// Copyright (c) 2021 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

import {
  GetPriceHistoryReturnObjectInfo,
  TokenInfo,
  AssetPriceInfo,
  AssetPriceTimeframe
} from '../../constants/types'

export interface CreateWalletPayloadType {
  password: string
}

export interface AddAccountPayloadType {
  accountName: string
}

export interface ImportAccountPayloadType {
  accountName: string
  privateKey: string
}

export interface ImportAccountFromJsonPayloadType {
  accountName: string
  password: string
  json: string
}

export interface RemoveImportedAccountPayloadType {
  address: string
}

export interface RemoveHardwareAccountPayloadType {
  address: string
}

export interface RestoreWalletPayloadType {
  mnemonic: string
  password: string
  isLegacy: boolean
}

export interface WalletCreatedPayloadType {
  mnemonic: string
}

export interface ViewPrivateKeyPayloadType {
  isDefault: boolean
  address: string
}

export interface RecoveryWordsAvailablePayloadType {
  mnemonic: string
}

export interface PrivateKeyAvailablePayloadType {
  privateKey: string
}

export interface UpdateSelectedAssetType {
  asset: TokenInfo
  timeFrame: AssetPriceTimeframe
}

export interface SelectAssetPayloadType {
  priceHistory: GetPriceHistoryReturnObjectInfo | undefined
  usdPriceInfo: AssetPriceInfo | undefined
  btcPriceInfo: AssetPriceInfo | undefined
  timeFrame: AssetPriceTimeframe
}

export interface ImportFromExternalWalletPayloadType {
  password: string
  newPassword: string
}

export interface ImportWalletErrorPayloadType {
  hasError: boolean
  errorMessage?: string
}
