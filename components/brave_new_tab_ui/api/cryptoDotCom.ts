// Copyright (c) 2020 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

async function getCryptoDotComTickerInfo (asset: string) {
  return await new Promise((resolve: Function) => {
    chrome.cryptoDotCom.getTickerInfo(`${asset}_USDT`, (resp: any) => {
      resolve({ [asset]: resp })
    })
  })
}

async function getCryptoDotComAssetRankings () {
  return await new Promise((resolve: Function) => {
    chrome.cryptoDotCom.getAssetRankings((resp: any) => {
      resolve(resp)
    })
  })
}

async function getCryptoDotComChartData (asset: string) {
  return await new Promise((resolve: Function) => {
    chrome.cryptoDotCom.getChartData(`${asset}_USDT`, (resp: any) => {
      resolve({ [asset]: resp })
    })
  })
}

async function getCryptoDotComSupportedPairs () {
  return await new Promise((resolve: Function) => {
    chrome.cryptoDotCom.getSupportedPairs((resp: any) => {
      resolve(resp)
    })
  })
}

export async function fetchCryptoDotComTickerPrices (assets: string[]) {
  const assetReqs = assets.map(async asset => await getCryptoDotComTickerInfo(asset))
  const assetResps = await Promise.all(assetReqs).then((resps: object[]) => resps)
  return assetResps.reduce((all, current) => ({ ...current, ...all }), {})
}

export async function fetchCryptoDotComLosersGainers () {
  return await getCryptoDotComAssetRankings().then((resp: any) => resp)
}

export async function fetchCryptoDotComCharts (assets: string[]) {
  const chartReqs = assets.map(async asset => await getCryptoDotComChartData(asset))
  const chartResps = await Promise.all(chartReqs).then((resps: object[]) => resps)
  return chartResps.reduce((all, current) => ({ ...current, ...all }), {})
}

export async function fetchCryptoDotComSupportedPairs () {
  return await getCryptoDotComSupportedPairs().then((resp: any) => resp)
}
