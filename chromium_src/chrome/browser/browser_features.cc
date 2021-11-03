/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "../../../../chrome/browser/browser_features.cc"

#include "base/feature_override.h"

#if !defined(OS_ANDROID)
DISABLE_FEATURE_BY_DEFAULT(features::kCopyLinkToText);
#endif
