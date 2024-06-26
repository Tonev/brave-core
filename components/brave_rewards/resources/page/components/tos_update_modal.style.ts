/* Copyright (c) 2023 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

import styled from 'styled-components'

import * as leo from '@brave/leo/tokens/css'

export const root = styled.div.attrs({
  'data-theme': 'light'
})`
  --tos-update-notice-padding: 40px 40px 32px;
  --tos-update-notice-heading-font: ${leo.font.heading.h2};
`
