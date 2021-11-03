// Copyright (c) 2021 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

import {
  AppObjectType,
  AccountInfo,
  DefaultWallet,
  TransactionInfo,
  TokenInfo,
  AccountAssetOptionType,
  SlippagePresetObjectType,
  WalletAccountType
} from '../../constants/types'

export interface InitializedPayloadType {
  isWalletCreated: boolean
  isWalletLocked: boolean
  favoriteApps: AppObjectType[]
  isWalletBackedUp: boolean
  visibleTokens: string[]
  accountInfos: AccountInfo[]
  selectedAccount: string
}

export interface UnlockWalletPayloadType {
  password: string
}

export interface ChainChangedEventPayloadType {
  chainId: string
}

export interface IsEip1559Changed {
  chainId: string
  isEip1559: boolean
}

export interface NewUnapprovedTxAdded {
  txInfo: TransactionInfo
}

export interface UnapprovedTxUpdated {
  txInfo: TransactionInfo
}

export interface TransactionStatusChanged {
  txInfo: TransactionInfo
}

export interface AddUserAssetPayloadType {
  token: TokenInfo
  chainId: string
}

export interface RemoveUserAssetPayloadType {
  token: TokenInfo
  chainId: string
}

export interface SetUserAssetVisiblePayloadType {
  token: TokenInfo
  chainId: string
  isVisible: boolean
}

export interface SwapParamsPayloadType {
  fromAsset: AccountAssetOptionType
  toAsset: AccountAssetOptionType
  fromAssetAmount?: string
  toAssetAmount?: string
  slippageTolerance: SlippagePresetObjectType
  accountAddress: string
  networkChainId: string
  full: boolean
}

export interface ActiveOriginChanged {
  origin: string
}

export interface UpdateUnapprovedTransactionGasFieldsType {
  txMetaId: string
  gasLimit: string
  gasPrice?: string
  maxPriorityFeePerGas?: string
  maxFeePerGas?: string
}

export interface UpdateUnapprovedTransactionSpendAllowanceType {
  txMetaId: string
  spenderAddress: string
  allowance: string
}

export interface DefaultWalletChanged {
  defaultWallet: DefaultWallet
}

export interface SitePermissionsPayloadType {
  accounts: Array<WalletAccountType | undefined>
}

export interface RemoveSitePermissionPayloadType {
  origin: string
  account: string
}
