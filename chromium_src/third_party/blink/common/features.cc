/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "../../../../../third_party/blink/common/features.cc"

#include "base/feature_override.h"

// Upgrade all mixed content
ENABLE_FEATURE_BY_DEFAULT(blink::features::kMixedContentAutoupgrade);

ENABLE_FEATURE_BY_DEFAULT(blink::features::kPrefetchPrivacyChanges);
ENABLE_FEATURE_BY_DEFAULT(blink::features::kReducedReferrerGranularity);

DISABLE_FEATURE_BY_DEFAULT(blink::features::kComputePressure);
DISABLE_FEATURE_BY_DEFAULT(blink::features::kConversionMeasurement);
DISABLE_FEATURE_BY_DEFAULT(blink::features::kFledgeInterestGroupAPI);
DISABLE_FEATURE_BY_DEFAULT(blink::features::kFledgeInterestGroups);
DISABLE_FEATURE_BY_DEFAULT(
    blink::features::kHandwritingRecognitionWebPlatformApiFinch);
DISABLE_FEATURE_BY_DEFAULT(blink::features::kInterestCohortAPIOriginTrial);
DISABLE_FEATURE_BY_DEFAULT(blink::features::kInterestCohortFeaturePolicy);
DISABLE_FEATURE_BY_DEFAULT(blink::features::kNavigatorPluginsFixed);
DISABLE_FEATURE_BY_DEFAULT(blink::features::kTextFragmentAnchor);

namespace blink {
namespace features {

const base::Feature kFileSystemAccessAPI{"FileSystemAccessAPI",
                                         base::FEATURE_DISABLED_BY_DEFAULT};

}  // namespace features
}  // namespace blink
