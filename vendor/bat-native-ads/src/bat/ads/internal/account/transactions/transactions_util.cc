/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/account/transactions/transactions_util.h"

#include <algorithm>
#include <iterator>

#include "base/time/time.h"
#include "bat/ads/internal/time_util.h"

namespace ads {

namespace {

bool HasPendingTransactionsForDateRange(const TransactionList& transactions,
                                        const base::Time& from_time,
                                        const base::Time& to_time) {
  const double from_timestamp = from_time.ToDoubleT();
  const double to_timestamp = to_time.ToDoubleT();

  const int count = std::count_if(
      transactions.cbegin(), transactions.cend(),
      [from_timestamp, to_timestamp](const TransactionInfo& transaction) {
        return transaction.redeemed_at >= from_timestamp &&
               transaction.redeemed_at <= to_timestamp;
      });

  if (count == 0) {
    return false;
  }

  return true;
}

}  // namespace

TransactionList GetTransactionsForDateRange(const TransactionList& transactions,
                                            const base::Time& from_time,
                                            const base::Time& to_time) {
  const double now = base::Time::Now().ToDoubleT();
  const double from_timestamp = from_time.ToDoubleT();
  const double to_timestamp = to_time.ToDoubleT();

  TransactionList filtered_transactions;

  std::copy_if(
      transactions.cbegin(), transactions.cend(),
      std::back_inserter(filtered_transactions),
      [now, from_timestamp, to_timestamp](const TransactionInfo& transaction) {
        return now >= from_timestamp && now <= to_timestamp;
      });

  return filtered_transactions;
}

bool HasPendingTransactionsForPreviousMonth(
    const base::Time& time,
    const TransactionList& transactions) {
  const base::Time from_time = AdjustTimeToBeginningOfPreviousMonth(time);
  const base::Time to_time = AdjustTimeToEndOfPreviousMonth(time);
  return HasPendingTransactionsForDateRange(transactions, from_time, to_time);
}

bool HasPendingTransactionsForThisMonth(const base::Time& time,
                                        const TransactionList& transactions) {
  const base::Time from_time = AdjustTimeToBeginningOfMonth(time);
  const base::Time to_time = base::Time::Now();
  return HasPendingTransactionsForDateRange(transactions, from_time, to_time);
}

}  // namespace ads
