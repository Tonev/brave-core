/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */
/* global window */

const { EventEmitter } = require('events')
import { publicToAddress, toChecksumAddress, bufferToHex } from 'ethereumjs-util'
import { Transaction } from 'ethereumjs-tx'
import {
  TrezorDerivationPaths, TrezorBridgeAccountsPayload
} from '../../components/desktop/popup-modals/add-account-modal/hardware-wallet-connect/types'
import {
  kTrezorHardwareVendor,
  TransactionInfo
} from '../../constants/types'
import {
  TrezorCommand,
  UnlockCommand,
  GetAccountsCommand,
  UnlockResponse,
  GetAccountsResponsePayload,
  TrezorAccount,
  TrezorError,
  sendTrezorCommand,
  TrezorFrameCommand,
  SignTransactionCommand,
  SignTransactionCommandPayload
} from '../../common/trezor/trezor-messages'
import { getLocale } from '../../../common/locale'
import { hardwareDeviceIdFromAddress } from '../async/lib'

export default class TrezorBridgeKeyring extends EventEmitter {
  constructor () {
    super()
    this.unlocked_ = false
  }

  type = () => {
    return kTrezorHardwareVendor
  }

  getAccounts = async (from: number, to: number, scheme: string) => {
    if (from < 0) {
      from = 0
    }
    if (!this.isUnlocked() && !(await this.unlock())) {
      return new Error(getLocale('braveWalletUnlockError'))
    }
    const paths = []

    const addZeroPath = (from > 0 || to < 0)
    if (addZeroPath) {
      // Add zero address to calculate device id.
      paths.push(this.getPathForIndex(0, TrezorDerivationPaths.Default))
    }
    for (let i = from; i <= to; i++) {
      paths.push(this.getPathForIndex(i, scheme))
    }
    const accounts = await this.getAccountsFromDevice(paths, addZeroPath)
    if (!accounts.success) {
      throw Error(accounts.error)
    }
    return accounts.accounts
  }

  signTransaction = async (path: string, txInfo: TransactionInfo, chainId: string) => {
    return new Promise(async (resolve, reject) => {
      if (!this.isUnlocked() && !(await this.unlock())) {
        return reject(new Error(getLocale('braveWalletUnlockError')))
      }
      const message: SignTransactionCommand = {
        command: TrezorCommand.SignTransaction,
        // @ts-ignore
        id: crypto.randomUUID(),
        payload: this.prepareTransactionPayload(path, txInfo, chainId),
        origin: window.origin
      }
      const result = await this.sendTrezorCommand(message, async (data: SignTransactionCommandPayload) => {
        if (data.payload.success) {
          resolve(data.payload.payload)
        } else {
          reject(data.payload.payload)
        }
      })
      if (!result) {
        reject(false)
      }
    })
  }

  isUnlocked = () => {
    return this.unlocked_
  }

  unlock = () => {
    return new Promise(async (resolve, reject) => {
      const message: UnlockCommand = {
        // @ts-ignore
        id: crypto.randomUUID(),
        origin: window.origin,
        command: TrezorCommand.Unlock }
      const result = await this.sendTrezorCommand(message, (data: UnlockResponse) => {
        this.unlocked_ = data.result
        if (data.result) {
          resolve(true)
        } else {
          reject(false)
        }
      })
      if (!result) {
        reject(false)
      }
    })
  }

  private sendTrezorCommand = async (command: TrezorFrameCommand, listener: Function) => {
    return sendTrezorCommand(command, listener)
  }

  private getHashFromAddress = async (address: string) => {
    return hardwareDeviceIdFromAddress(address)
  }

  private getDeviceIdFromAccountsList = async (accountsList: TrezorAccount[]) => {
    const zeroPath = this.getPathForIndex(0, TrezorDerivationPaths.Default)
    for (const value of accountsList) {
      if (value.serializedPath !== zeroPath) {
        continue
      }
      const address = this.publicKeyToAddress(value.publicKey)
      return this.getHashFromAddress(address)
    }
    return ''
  }

  private normalize (buf: any) {
    return bufferToHex(buf).toString()
  }

  private prepareTransactionPayload = (path: string, txInfo: TransactionInfo, chainId: string): SignTransactionCommandPayload => {
    const txParams = {
      nonce: txInfo.txData.baseData.nonce,
      gasPrice: txInfo.txData.baseData.gasPrice,
      gasLimit: txInfo.txData.baseData.gasLimit,
      to: txInfo.txData.baseData.to,
      value: txInfo.txData.baseData.value,
      data: Buffer.from(txInfo.txData.baseData.data)
    }
    const tx = new Transaction(txParams)
    return {
      path: path,
      transaction: {
        to: this.normalize(tx.to),
        value: this.normalize(tx.value),
        data: this.normalize(tx.data).replace('0x', ''),
        chainId: parseInt(chainId, 16),
        nonce: this.normalize(tx.nonce),
        gasLimit: this.normalize(tx.gasLimit),
        gasPrice: this.normalize(tx.gasPrice)
      }
    }
  }

  private publicKeyToAddress = (key: string) => {
    const buffer = Buffer.from(key, 'hex')
    const address = publicToAddress(buffer, true).toString('hex')
    return toChecksumAddress(`0x${address}`)
  }

  private getAccountsFromDevice = async (paths: string[], skipZeroPath: Boolean): Promise<TrezorBridgeAccountsPayload> => {
    return new Promise(async (resolve, reject) => {
      const requestedPaths = []
      for (const path of paths) {
        requestedPaths.push({ path: path })
      }
      const message: GetAccountsCommand = {
        command: TrezorCommand.GetAccounts,
        // @ts-ignore
        id: crypto.randomUUID(),
        paths: requestedPaths,
        origin: window.origin }
      const result = await this.sendTrezorCommand(message, async (data: GetAccountsResponsePayload) => {
        if (data.payload.success) {
          let accounts = []
          const accountsList = data.payload.payload as TrezorAccount[]
          this.deviceId_ = await this.getDeviceIdFromAccountsList(accountsList)
          const zeroPath = this.getPathForIndex(0, TrezorDerivationPaths.Default)
          for (const value of accountsList) {
            // If requested addresses do not have zero indexed adress we add it
            // intentionally to calculate device id and should not add it to
            // returned accounts
            if (skipZeroPath && (value.serializedPath === zeroPath)) {
              continue
            }
            accounts.push({
              address: this.publicKeyToAddress(value.publicKey),
              derivationPath: value.serializedPath,
              name: this.type(),
              hardwareVendor: this.type(),
              deviceId: this.deviceId_
            })
          }
          resolve({ success: true, accounts: [...accounts] })
        } else {
          const error = data.payload.payload as TrezorError
          reject({ success: false, error: error.error, accounts: [] })
        }
      })
      if (!result) {
        reject({ success: false, error: getLocale('braveWalletCreateBridgeError'), accounts: [] })
      }
    })
  }

  private getPathForIndex = (index: number, scheme: string) => {
    if (scheme === TrezorDerivationPaths.Default) {
      return `m/44'/60'/0'/${index}`
    } else {
      throw Error(getLocale('braveWalletDeviceUnknownScheme'))
    }
  }
}
