/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_LEGACY_MIGRATION_REWARDS_LEGACY_REWARDS_MIGRATION_TRANSACTION_HISTORY_JSON_READER_
#define BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_LEGACY_MIGRATION_REWARDS_LEGACY_REWARDS_MIGRATION_TRANSACTION_HISTORY_JSON_READER_

#include <string>

#include "bat/ads/transaction_info_aliases.h"

namespace absl {
template <typename T>
class optional;
}  // namespace absl

namespace ads {
namespace rewards {
namespace JSONReader {

absl::optional<TransactionList> ReadTransactionHistory(const std::string& json);

}  // namespace JSONReader
}  // namespace rewards
}  // namespace ads

#endif  // BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_LEGACY_MIGRATION_REWARDS_LEGACY_REWARDS_MIGRATION_TRANSACTION_HISTORY_JSON_READER_
