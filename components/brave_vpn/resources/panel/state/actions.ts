// Copyright (c) 2021 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

import { createAction } from 'redux-act'

import { ConnectionState, Region, ProductUrls } from '../api/panel_browser_api'

export interface ToggleRegionSelectorPayload {
  isSelectingRegion: boolean
}

export interface ConnectionStatePayload {
  connectionStatus: ConnectionState
}

export interface ConnectToNewRegionPayload {
  region: Region
}

export interface InitUIMainPayload {
  currentRegion: Region
  regions: Region[]
  connectionStatus: ConnectionState
  productUrls: ProductUrls
}

export const connect = createAction('connect')
export const disconnect = createAction('disconnect')
export const connectionFailed = createAction('connectionFailed')
export const retryConnect = createAction('retryConnect')
export const initialize = createAction('initialize')
export const purchaseConfirmed = createAction('purchaseConfirmed')

export const initUIMain = createAction<InitUIMainPayload>('initUIMain')
export const toggleRegionSelector = createAction<ToggleRegionSelectorPayload>('toggleRegionSelector', (isSelectingRegion) => ({ isSelectingRegion }))
export const connectionStateChanged = createAction<ConnectionStatePayload>('connectionStateChanged')
export const connectToNewRegion = createAction<ConnectToNewRegionPayload>('connectToNewRegion', (region) => ({ region }))
