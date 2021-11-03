// Copyright (c) 2020 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

import { createAction } from 'redux-act'

export const todayInit = createAction('todayInit')

export const interactionBegin = createAction('interactionStart')

export const ensureSettingsData = createAction('ensureSettingsData')

interface DataReceivedPayload {
  feed?: BraveToday.Feed
  publishers?: BraveToday.Publishers
}
export const dataReceived = createAction<DataReceivedPayload>('dataReceived')

export const optIn = createAction('optedIn')

/**
 * Scroll has reached a position so that another page of content is needed
 */
export const anotherPageNeeded = createAction('anotherPageNeeded')

interface BackgroundErrorPayload {
  error: Error
}
export const errorGettingDataFromBackground = createAction<BackgroundErrorPayload>('errorGettingDataFromBackground')

/**
 * User has requested to read an article
 */
export interface ReadFeedItemPayload {
  item: BraveToday.FeedItem
  isPromoted?: boolean
  promotedUUID?: string
  openInNewTab?: boolean
}
export const readFeedItem = createAction<ReadFeedItemPayload>('readFeedItem')

export const feedItemViewedCountChanged = createAction<number>('feedItemViewedCountChanged')

export interface PromotedItemViewedPayload {
  item: BraveToday.PromotedArticle
  uuid: string
}
export const promotedItemViewed = createAction<PromotedItemViewedPayload>('promotedItemViewed')

export interface VisitDisplayAdPayload {
  ad: BraveToday.DisplayAd
  openInNewTab?: boolean
}
export const visitDisplayAd = createAction<VisitDisplayAdPayload>('visitDisplayAd')

export interface DisplayAdViewedPayload {
  ad: BraveToday.DisplayAd
}
export const displayAdViewed = createAction<DisplayAdViewedPayload>('displayAdViewed')

export interface SetPublisherPrefPayload {
  publisherId: string
  enabled: boolean | null
}
export const setPublisherPref = createAction<SetPublisherPrefPayload>('setPublisherPref', (publisherId: string, enabled: boolean | null) => ({ publisherId, enabled }))

export const checkForUpdate = createAction('checkForUpdate')

export interface IsUpdateAvailablePayload {
  isUpdateAvailable: boolean
}
export const isUpdateAvailable = createAction<IsUpdateAvailablePayload>('isUpdateAvailable')

export const resetTodayPrefsToDefault = createAction('resetTodayPrefsToDefault')

export const refresh = createAction('refresh')
