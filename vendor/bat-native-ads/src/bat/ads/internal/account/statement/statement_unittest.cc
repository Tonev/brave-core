/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/account/statement/statement.h"

#include "bat/ads/internal/account/transactions/transactions.h"
#include "bat/ads/internal/unittest_base.h"
#include "bat/ads/internal/unittest_time_util.h"
#include "bat/ads/internal/unittest_util.h"
#include "bat/ads/statement_info.h"
#include "net/http/http_status_code.h"

// npm run test -- brave_unit_tests --filter=BatAds*

using ::testing::NiceMock;

namespace ads {

class BatAdsStatementTest : public UnitTestBase {
 protected:
  BatAdsStatementTest() = default;

  ~BatAdsStatementTest() override = default;

  void AddTransactions(const int count) {
    for (int i = 0; i < count; i++) {
      transactions::Add(0.01, ConfirmationType::kViewed,
                        [](const bool success, const std::string& id) {
                          ASSERT_TRUE(success);
                        });
    }
  }
};

TEST_F(BatAdsStatementTest, GetForTransactionsThisMonth) {
  // Arrange
  AdvanceClock(TimeFromString("18 November 2020", /* is_local */ true));
  AddTransactions(7);

  // Act
  Statement statement;
  statement.Get([](const bool success, const StatementInfo& statement) {
    ASSERT_TRUE(success);

    StatementInfo expected_statement;
    EXPECT_EQ(expected_statement, statement);
  });

  // Assert
}

TEST_F(BatAdsStatementTest, GetForTransactionsSplitOverTwoConsecutiveMonths) {
  // Arrange
  AdvanceClock(TimeFromString("18 November 2020", /* is_local */ true));
  AddTransactions(7);

  AdvanceClock(TimeFromString("25 December 2020", /* is_local */ true));
  AddTransactions(7);

  // Act
  Statement statement;
  statement.Get([](const bool success, const StatementInfo& statement) {
    ASSERT_TRUE(success);

    StatementInfo expected_statement;
    EXPECT_EQ(expected_statement, statement);
  });

  // Assert
}

TEST_F(BatAdsStatementTest, GetForTransactionsSplitOverTwoYears) {
  // Arrange
  AdvanceClock(TimeFromString("25 December 2020", /* is_local */ true));
  AddTransactions(7);

  AdvanceClock(TimeFromString("4 January 2021", /* is_local */ true));
  AddTransactions(7);

  // Act
  Statement statement;
  statement.Get([](const bool success, const StatementInfo& statement) {
    ASSERT_TRUE(success);

    StatementInfo expected_statement;
    EXPECT_EQ(expected_statement, statement);
  });

  // Assert
}

TEST_F(BatAdsStatementTest, GetForTransactionsOnTheCusp) {
  // Arrange
  AdvanceClock(TimeFromString("18 November 2020", /* is_local */ true));
  AddTransactions(7);

  // Act
  Statement statement;
  statement.Get([](const bool success, const StatementInfo& statement) {
    ASSERT_TRUE(success);

    StatementInfo expected_statement;
    EXPECT_EQ(expected_statement, statement);
  });

  // Assert
}

TEST_F(BatAdsStatementTest, GetForNoTransactions) {
  // Arrange
  AdvanceClock(TimeFromString("18 November 2020", /* is_local */ true));

  // Act
  Statement statement;
  statement.Get([](const bool success, const StatementInfo& statement) {
    ASSERT_TRUE(success);

    StatementInfo expected_statement;
    EXPECT_EQ(expected_statement, statement);
  });

  // Assert
}

}  // namespace ads
