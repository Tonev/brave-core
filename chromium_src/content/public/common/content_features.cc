/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "../../../../../content/public/common/content_features.cc"

#include "base/feature_override.h"

DISABLE_FEATURE_BY_DEFAULT(features::kDirectSockets);
DISABLE_FEATURE_BY_DEFAULT(features::kIdleDetection);
DISABLE_FEATURE_BY_DEFAULT(features::kNotificationTriggers);
DISABLE_FEATURE_BY_DEFAULT(
    features::kSignedExchangePrefetchCacheForNavigations);
DISABLE_FEATURE_BY_DEFAULT(features::kSignedExchangeSubresourcePrefetch);
DISABLE_FEATURE_BY_DEFAULT(features::kSubresourceWebBundles);
#if defined(OS_ANDROID)
DISABLE_FEATURE_BY_DEFAULT(features::kWebNfc);
#endif
DISABLE_FEATURE_BY_DEFAULT(features::kWebOTP);
