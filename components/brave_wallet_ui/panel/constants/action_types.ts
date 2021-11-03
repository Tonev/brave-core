// Copyright (c) 2021 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

import { WalletAccountType, EthereumChain } from '../../constants/types'

export interface AccountPayloadType {
  selectedAccounts: WalletAccountType[]
  siteToConnectTo: string
}

export interface ShowConnectToSitePayload {
  tabId: number
  accounts: string[]
  origin: string
}

export interface EthereumChainRequestPayload {
  chainId: string
  approved: boolean
}

export interface EthereumChainPayload {
  chain: EthereumChain
}

export interface SignMessagePayload {
  id: number
  address: string
  message: string
}

export interface SignMessageProcessedPayload {
  approved: boolean
  id: number
}

export interface SignMessageHardwareProcessedPayload {
  success: boolean
  id: number
  signature: string
  error: string
}
