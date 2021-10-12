/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_WALLET_BROWSER_BRAVE_WALLET_CONSTANTS_H_
#define BRAVE_COMPONENTS_BRAVE_WALLET_BROWSER_BRAVE_WALLET_CONSTANTS_H_

#include <vector>

#include "base/no_destructor.h"
#include "brave/components/brave_wallet/browser/brave_wallet_types.h"
#include "brave/components/brave_wallet/common/brave_wallet.mojom.h"
#include "components/grit/brave_components_strings.h"
#include "ui/base/webui/web_ui_util.h"

namespace brave_wallet {

extern const char kAssetRatioBaseURL[];

constexpr uint256_t kDefaultSendEthGasLimit = 21000;
constexpr uint256_t kDefaultSendEthGasPrice = 150000000000ULL;  // 150 Gwei

constexpr int32_t kAutoLockMinutesMin = 1;
constexpr int32_t kAutoLockMinutesMax = 10080;

// List of assets from Wyre, available to buy
static base::NoDestructor<std::vector<mojom::ERCToken>> kBuyTokens(
    {{"0x0D8775F648430679A709E98d2b0Cb6250d2887EF", "Basic Attention Token",
      "bat.png", true, false, "BAT", 18, true, ""},
     {"", "Ethereum", "", false, false, "ETH", 18, true, ""},
     {"0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48", "USD Coin", "usdc.png",
      true, false, "USDC", 6, true, ""},
     {"0x6B175474E89094C44Da98b954EedeAC495271d0F", "DAI", "dai.png", true,
      false, "DAI", 18, true, ""},
     {"0x7Fc66500c84A76Ad7e9c93437bFc5Ac33E2DDaE9", "AAVE", "AAVE.png", true,
      false, "AAVE", 18, true, ""},
     {"0x4Fabb145d64652a948d72533023f6E7A623C7C53", "Binance USD", "busd.png",
      true, false, "BUSD", 18, true, ""},
     {"0xc00e94Cb662C3520282E6f5717214004A7f26888", "Compound", "comp.png",
      true, false, "Comp", 18, true, ""},
     {"0xD533a949740bb3306d119CC777fa900bA034cd52", "Curve", "curve.png", true,
      false, "CRV", 18, true, ""},
     {"0xc00e94Cb662C3520282E6f5717214004A7f26888", "Gemini Dollar", "gusd.png",
      true, false, "GUSD", 2, true, ""},
     {"0x514910771AF9Ca656af840dff83E8264EcF986CA", "Chainlink",
      "chainlink.png", true, false, "LINK", 18, true, ""},
     {"0x9f8F72aA9304c8B593d555F12eF6589cC3A579A2", "Maker", "mkr.png", true,
      false, "MKR", 18, true, ""},
     {"0xC011a73ee8576Fb46F5E1c5751cA3B9Fe0af2a6F", "Synthetix",
      "synthetix.png", true, false, "SNX", 18, true, ""},
     {"0x04Fa0d235C4abf4BcF4787aF4CF447DE572eF828", "UMA", "UMA.png", true,
      false, "UMA", 18, true, ""},
     {"0x1f9840a85d5aF5bf1D1762F925BDADdC4201F984", "Uniswap", "uni.png", true,
      false, "UNI", 18, true, ""},
     {"0xA4Bdb11dc0a2bEC88d24A3aa1E6Bb17201112eBe", "Stably Dollar", "usds.png",
      true, false, "USDS", 6, true, ""},
     {"0xdAC17F958D2ee523a2206206994597C13D831ec7", "Tether", "usdt.png", true,
      false, "USDT", 6, true, ""},
     {"0x2260FAC5E5542a773Aa44fBCfeDf7C193bc2C599", "Wrapped Bitcoin",
      "wbtc.png", true, false, "WBTC", 8, true, ""},
     {"0x0bc529c00C6401aEF6D220BE8C6Ea1667F6Ad93e", "Year.Finance", "yfi.png",
      true, false, "YFI", 18, true, ""},
     {"0x9043d4d51C9d2e31e3F169de4551E416970c27Ef", "Palm DAI", "pdai.png",
      true, false, "PDAI", 18, true, ""}});

const char kWalletBaseDirectory[] = "BraveWallet";
const char kImageSourceHost[] = "erc-token-images";
const char kWyreID[] = "AC_MGNVBGHPA9T";
const char kBuyUrl[] =
    "https://pay.sendwyre.com/?dest=ethereum:%s"
    "&destCurrency=%s&amount=%s&accountId=%s&paymentMethod=debit-card";

constexpr webui::LocalizedString kLocalizedStrings[] = {
    {"braveWallet", IDS_BRAVE_WALLET},
    {"braveWalletDefiCategory", IDS_BRAVE_WALLET_DEFI_CATEGORY},
    {"braveWalletNftCategory", IDS_BRAVE_WALLET_NFT_CATEGORY},
    {"braveWalletSearchCategory", IDS_BRAVE_WALLET_SEARCH_CATEGORY},
    {"braveWalletDefiButtonText", IDS_BRAVE_WALLET_DEFI_BUTTON_TEXT},
    {"braveWalletNftButtonText", IDS_BRAVE_WALLET_NFT_BUTTON_TEXT},
    {"braveWalletCompoundName", IDS_BRAVE_WALLET_COMPOUND_NAME},
    {"braveWalletCompoundDescription", IDS_BRAVE_WALLET_COMPOUND_DESCRIPTION},
    {"braveWalletMakerName", IDS_BRAVE_WALLET_MAKER_NAME},
    {"braveWalletMakerDescription", IDS_BRAVE_WALLET_MAKER_DESCRIPTION},
    {"braveWalletAaveName", IDS_BRAVE_WALLET_AAVE_NAME},
    {"braveWalletAaveDescription", IDS_BRAVE_WALLET_AAVE_DESCRIPTION},
    {"braveWalletOpenSeaName", IDS_BRAVE_WALLET_OPEN_SEA_NAME},
    {"braveWalletOpenSeaDescription", IDS_BRAVE_WALLET_OPEN_SEA_DESCRIPTION},
    {"braveWalletRaribleName", IDS_BRAVE_WALLET_RARIBLE_NAME},
    {"braveWalletRaribleDescription", IDS_BRAVE_WALLET_RARIBLE_DESCRIPTION},
    {"braveWalletSearchText", IDS_BRAVE_WALLET_SEARCH_TEXT},
    {"braveWalletSideNavCrypto", IDS_BRAVE_WALLET_SIDE_NAV_CRYPTO},
    {"braveWalletSideNavRewards", IDS_BRAVE_WALLET_SIDE_NAV_REWARDS},
    {"braveWalletSideNavCards", IDS_BRAVE_WALLET_SIDE_NAV_CARDS},
    {"braveWalletTopNavPortfolio", IDS_BRAVE_WALLET_TOP_NAV_PORTFOLIO},
    {"braveWalletTopTabPrices", IDS_BRAVE_WALLET_TOP_TAB_PRICES},
    {"braveWalletTopTabApps", IDS_BRAVE_WALLET_TOP_TAB_APPS},
    {"braveWalletTopNavNFTS", IDS_BRAVE_WALLET_TOP_NAV_N_F_T_S},
    {"braveWalletTopNavAccounts", IDS_BRAVE_WALLET_TOP_NAV_ACCOUNTS},
    {"braveWalletChartLive", IDS_BRAVE_WALLET_CHART_LIVE},
    {"braveWalletChartOneDay", IDS_BRAVE_WALLET_CHART_ONE_DAY},
    {"braveWalletChartOneWeek", IDS_BRAVE_WALLET_CHART_ONE_WEEK},
    {"braveWalletChartOneMonth", IDS_BRAVE_WALLET_CHART_ONE_MONTH},
    {"braveWalletChartThreeMonths", IDS_BRAVE_WALLET_CHART_THREE_MONTHS},
    {"braveWalletChartOneYear", IDS_BRAVE_WALLET_CHART_ONE_YEAR},
    {"braveWalletChartAllTime", IDS_BRAVE_WALLET_CHART_ALL_TIME},
    {"braveWalletAddCoin", IDS_BRAVE_WALLET_ADD_COIN},
    {"braveWalletBalance", IDS_BRAVE_WALLET_BALANCE},
    {"braveWalletAccounts", IDS_BRAVE_WALLET_ACCOUNTS},
    {"braveWalletAccount", IDS_BRAVE_WALLET_ACCOUNT},
    {"braveWalletTransactions", IDS_BRAVE_WALLET_TRANSACTIONS},
    {"braveWalletPrice", IDS_BRAVE_WALLET_PRICE},
    {"braveWalletBack", IDS_BRAVE_WALLET_BACK},
    {"braveWalletAddAccount", IDS_BRAVE_WALLET_ADD_ACCOUNT},
    {"braveWalletBuy", IDS_BRAVE_WALLET_BUY},
    {"braveWalletSend", IDS_BRAVE_WALLET_SEND},
    {"braveWalletSwap", IDS_BRAVE_WALLET_SWAP},
    {"braveWalletBssToolTip", IDS_BRAVE_WALLET_BSS_TOOL_TIP},
    {"braveWalletSlippageToleranceWarning",
     IDS_BRAVE_WALLET_SLIPPAGE_TOLERANCE_WARNING},
    {"braveWalletSlippageToleranceTitle",
     IDS_BRAVE_WALLET_SLIPPAGE_TOLERANCE_TITLE},
    {"braveWalletExpiresInTitle", IDS_BRAVE_WALLET_EXPIRES_IN_TITLE},
    {"braveWalletSendPlaceholder", IDS_BRAVE_WALLET_SEND_PLACEHOLDER},
    {"braveWalletButtonContinue", IDS_BRAVE_WALLET_BUTTON_CONTINUE},
    {"braveWalletButtonCopy", IDS_BRAVE_WALLET_BUTTON_COPY},
    {"braveWalletButtonVerify", IDS_BRAVE_WALLET_BUTTON_VERIFY},
    {"braveWalletWelcomeTitle", IDS_BRAVE_WALLET_WELCOME_TITLE},
    {"braveWalletWelcomeDescription", IDS_BRAVE_WALLET_WELCOME_DESCRIPTION},
    {"braveWalletWelcomeButton", IDS_BRAVE_WALLET_WELCOME_BUTTON},
    {"braveWalletWelcomeRestoreButton",
     IDS_BRAVE_WALLET_WELCOME_RESTORE_BUTTON},
    {"braveWalletBackupIntroTitle", IDS_BRAVE_WALLET_BACKUP_INTRO_TITLE},
    {"braveWalletBackupIntroDescription",
     IDS_BRAVE_WALLET_BACKUP_INTRO_DESCRIPTION},
    {"braveWalletBackupIntroTerms", IDS_BRAVE_WALLET_BACKUP_INTRO_TERMS},
    {"braveWalletBackupButtonSkip", IDS_BRAVE_WALLET_BACKUP_BUTTON_SKIP},
    {"braveWalletBackupButtonCancel", IDS_BRAVE_WALLET_BACKUP_BUTTON_CANCEL},
    {"braveWalletRecoveryTitle", IDS_BRAVE_WALLET_RECOVERY_TITLE},
    {"braveWalletRecoveryDescription", IDS_BRAVE_WALLET_RECOVERY_DESCRIPTION},
    {"braveWalletRecoveryWarning1", IDS_BRAVE_WALLET_RECOVERY_WARNING1},
    {"braveWalletRecoveryWarning2", IDS_BRAVE_WALLET_RECOVERY_WARNING2},
    {"braveWalletRecoveryWarning3", IDS_BRAVE_WALLET_RECOVERY_WARNING3},
    {"braveWalletRecoveryTerms", IDS_BRAVE_WALLET_RECOVERY_TERMS},
    {"braveWalletVerifyRecoveryTitle", IDS_BRAVE_WALLET_VERIFY_RECOVERY_TITLE},
    {"braveWalletVerifyRecoveryDescription",
     IDS_BRAVE_WALLET_VERIFY_RECOVERY_DESCRIPTION},
    {"braveWalletVerifyError", IDS_BRAVE_WALLET_VERIFY_ERROR},
    {"braveWalletCreatePasswordTitle", IDS_BRAVE_WALLET_CREATE_PASSWORD_TITLE},
    {"braveWalletCreatePasswordDescription",
     IDS_BRAVE_WALLET_CREATE_PASSWORD_DESCRIPTION},
    {"braveWalletCreatePasswordInput", IDS_BRAVE_WALLET_CREATE_PASSWORD_INPUT},
    {"braveWalletConfirmPasswordInput",
     IDS_BRAVE_WALLET_CONFIRM_PASSWORD_INPUT},
    {"braveWalletCreatePasswordError", IDS_BRAVE_WALLET_CREATE_PASSWORD_ERROR},
    {"braveWalletConfirmPasswordError",
     IDS_BRAVE_WALLET_CONFIRM_PASSWORD_ERROR},
    {"braveWalletLockScreenTitle", IDS_BRAVE_WALLET_LOCK_SCREEN_TITLE},
    {"braveWalletLockScreenButton", IDS_BRAVE_WALLET_LOCK_SCREEN_BUTTON},
    {"braveWalletLockScreenError", IDS_BRAVE_WALLET_LOCK_SCREEN_ERROR},
    {"braveWalletWalletPopupSettings", IDS_BRAVE_WALLET_WALLET_POPUP_SETTINGS},
    {"braveWalletWalletPopupLock", IDS_BRAVE_WALLET_WALLET_POPUP_LOCK},
    {"braveWalletWalletPopupBackup", IDS_BRAVE_WALLET_WALLET_POPUP_BACKUP},
    {"braveWalletBackupWarningText", IDS_BRAVE_WALLET_BACKUP_WARNING_TEXT},
    {"braveWalletBackupButton", IDS_BRAVE_WALLET_BACKUP_BUTTON},
    {"braveWalletDismissButton", IDS_BRAVE_WALLET_DISMISS_BUTTON},
    {"braveWalletDefaultWalletBanner", IDS_BRAVE_WALLET_DEFAULT_WALLET_BANNER},
    {"braveWalletRestoreTite", IDS_BRAVE_WALLET_RESTORE_TITE},
    {"braveWalletRestoreDescription", IDS_BRAVE_WALLET_RESTORE_DESCRIPTION},
    {"braveWalletRestoreError", IDS_BRAVE_WALLET_RESTORE_ERROR},
    {"braveWalletRestorePlaceholder", IDS_BRAVE_WALLET_RESTORE_PLACEHOLDER},
    {"braveWalletRestoreShowPhrase", IDS_BRAVE_WALLET_RESTORE_SHOW_PHRASE},
    {"braveWalletRestoreLegacyCheckBox",
     IDS_BRAVE_WALLET_RESTORE_LEGACY_CHECK_BOX},
    {"braveWalletRestoreFormText", IDS_BRAVE_WALLET_RESTORE_FORM_TEXT},
    {"braveWalletToolTipCopyToClipboard",
     IDS_BRAVE_WALLET_TOOL_TIP_COPY_TO_CLIPBOARD},
    {"braveWalletAccountsPrimary", IDS_BRAVE_WALLET_ACCOUNTS_PRIMARY},
    {"braveWalletAccountsSecondary", IDS_BRAVE_WALLET_ACCOUNTS_SECONDARY},
    {"braveWalletAccountsSecondaryDisclaimer",
     IDS_BRAVE_WALLET_ACCOUNTS_SECONDARY_DISCLAIMER},
    {"braveWalletAccountsAssets", IDS_BRAVE_WALLET_ACCOUNTS_ASSETS},
    {"braveWalletAccountsEditVisibleAssets",
     IDS_BRAVE_WALLET_ACCOUNTS_EDIT_VISIBLE_ASSETS},
    {"braveWalletAddAccountCreate", IDS_BRAVE_WALLET_ADD_ACCOUNT_CREATE},
    {"braveWalletAddAccountImport", IDS_BRAVE_WALLET_ADD_ACCOUNT_IMPORT},
    {"braveWalletAddAccountHardware", IDS_BRAVE_WALLET_ADD_ACCOUNT_HARDWARE},
    {"braveWalletAddAccountConnect", IDS_BRAVE_WALLET_ADD_ACCOUNT_CONNECT},
    {"braveWalletAddAccountPlaceholder",
     IDS_BRAVE_WALLET_ADD_ACCOUNT_PLACEHOLDER},
    {"braveWalletImportAccountDisclaimer",
     IDS_BRAVE_WALLET_IMPORT_ACCOUNT_DISCLAIMER},
    {"braveWalletImportAccountPlaceholder",
     IDS_BRAVE_WALLET_IMPORT_ACCOUNT_PLACEHOLDER},
    {"braveWalletImportAccountKey", IDS_BRAVE_WALLET_IMPORT_ACCOUNT_KEY},
    {"braveWalletImportAccountFile", IDS_BRAVE_WALLET_IMPORT_ACCOUNT_FILE},
    {"braveWalletImportAccountUploadButton",
     IDS_BRAVE_WALLET_IMPORT_ACCOUNT_UPLOAD_BUTTON},
    {"braveWalletImportAccountUploadPlaceholder",
     IDS_BRAVE_WALLET_IMPORT_ACCOUNT_UPLOAD_PLACEHOLDER},
    {"braveWalletImportAccountError", IDS_BRAVE_WALLET_IMPORT_ACCOUNT_ERROR},
    {"braveWalletConnectHardwareTitle",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_TITLE},
    {"braveWalletConnectHardwareInfo1",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_INFO1},
    {"braveWalletConnectHardwareInfo2",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_INFO2},
    {"braveWalletConnectHardwareInfo3",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_INFO3},
    {"braveWalletConnectHardwareTrezor",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_TREZOR},
    {"braveWalletConnectHardwareLedger",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_LEDGER},
    {"braveWalletConnectingHardwareWallet",
     IDS_BRAVE_WALLET_CONNECTING_HARDWARE_WALLET},
    {"braveWalletAddCheckedAccountsHardwareWallet",
     IDS_BRAVE_WALLET_ADD_CHECKED_ACCOUNTS_HARDWARE_WALLET},
    {"braveWalletLoadMoreAccountsHardwareWallet",
     IDS_BRAVE_WALLET_LOAD_MORE_ACCOUNTS_HARDWARE_WALLET},
    {"braveWalletLoadingMoreAccountsHardwareWallet",
     IDS_BRAVE_WALLET_LOADING_MORE_ACCOUNTS_HARDWARE_WALLET},
    {"braveWalletSearchScannedAccounts",
     IDS_BRAVE_WALLET_SEARCH_SCANNED_ACCOUNTS},
    {"braveWalletSwitchHDPathTextHardwareWallet",
     IDS_BRAVE_WALLET_SWITCH_H_D_PATH_TEXT_HARDWARE_WALLET},
    {"braveWalletLedgerLiveDerivationPath",
     IDS_BRAVE_WALLET_LEDGER_LIVE_DERIVATION_PATH},
    {"braveWalletLedgerLegacyDerivationPath",
     IDS_BRAVE_WALLET_LEDGER_LEGACY_DERIVATION_PATH},
    {"braveWalletUnknownInternalError",
     IDS_BRAVE_WALLET_UNKNOWN_INTERNAL_ERROR},
    {"braveWalletAccountSettingsDetails",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_DETAILS},
    {"braveWalletAccountSettingsWatchlist",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_WATCHLIST},
    {"braveWalletAccountSettingsPrivateKey",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_PRIVATE_KEY},
    {"braveWalletAccountSettingsSave", IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_SAVE},
    {"braveWalletAccountSettingsRemove",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_REMOVE},
    {"braveWalletWatchlistAddCustomAsset",
     IDS_BRAVE_WALLET_WATCHLIST_ADD_CUSTOM_ASSET},
    {"braveWalletWatchListTokenName", IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_NAME},
    {"braveWalletWatchListTokenAddress",
     IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_ADDRESS},
    {"braveWalletWatchListTokenSymbol",
     IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_SYMBOL},
    {"braveWalletWatchListTokenDecimals",
     IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_DECIMALS},
    {"braveWalletWatchListAdd", IDS_BRAVE_WALLET_WATCH_LIST_ADD},
    {"braveWalletWatchListDoneButton", IDS_BRAVE_WALLET_WATCH_LIST_DONE_BUTTON},
    {"braveWalletWatchListSuggestion", IDS_BRAVE_WALLET_WATCH_LIST_SUGGESTION},
    {"braveWalletWatchListNoAsset", IDS_BRAVE_WALLET_WATCH_LIST_NO_ASSET},
    {"braveWalletWatchListSearchPlaceholder",
     IDS_BRAVE_WALLET_WATCH_LIST_SEARCH_PLACEHOLDER},
    {"braveWalletWatchListError", IDS_BRAVE_WALLET_WATCH_LIST_ERROR},
    {"braveWalletWatchListTokenId", IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_ID},
    {"braveWalletWatchListTokenIdError",
     IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_ID_ERROR},
    {"braveWalletAccountSettingsDisclaimer",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_DISCLAIMER},
    {"braveWalletAccountSettingsShowKey",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_SHOW_KEY},
    {"braveWalletAccountSettingsHideKey",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_HIDE_KEY},
    {"braveWalletAccountSettingsUpdateError",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_UPDATE_ERROR},
    {"braveWalletPreset25", IDS_BRAVE_WALLET_PRESET25},
    {"braveWalletPreset50", IDS_BRAVE_WALLET_PRESET50},
    {"braveWalletPreset75", IDS_BRAVE_WALLET_PRESET75},
    {"braveWalletPreset100", IDS_BRAVE_WALLET_PRESET100},
    {"braveWalletNetworkETH", IDS_BRAVE_WALLET_NETWORK_E_T_H},
    {"braveWalletNetworkMain", IDS_BRAVE_WALLET_NETWORK_MAIN},
    {"braveWalletNetworkTest", IDS_BRAVE_WALLET_NETWORK_TEST},
    {"braveWalletNetworkRopsten", IDS_BRAVE_WALLET_NETWORK_ROPSTEN},
    {"braveWalletNetworkKovan", IDS_BRAVE_WALLET_NETWORK_KOVAN},
    {"braveWalletNetworkRinkeby", IDS_BRAVE_WALLET_NETWORK_RINKEBY},
    {"braveWalletNetworkGoerli", IDS_BRAVE_WALLET_NETWORK_GOERLI},
    {"braveWalletNetworkBinance", IDS_BRAVE_WALLET_NETWORK_BINANCE},
    {"braveWalletNetworkBinanceAbbr", IDS_BRAVE_WALLET_NETWORK_BINANCE_ABBR},
    {"braveWalletNetworkLocalhost", IDS_BRAVE_WALLET_NETWORK_LOCALHOST},
    {"braveWalletSelectAccount", IDS_BRAVE_WALLET_SELECT_ACCOUNT},
    {"braveWalletSearchAccount", IDS_BRAVE_WALLET_SEARCH_ACCOUNT},
    {"braveWalletSelectNetwork", IDS_BRAVE_WALLET_SELECT_NETWORK},
    {"braveWalletSelectAsset", IDS_BRAVE_WALLET_SELECT_ASSET},
    {"braveWalletSearchAsset", IDS_BRAVE_WALLET_SEARCH_ASSET},
    {"braveWalletSwapFrom", IDS_BRAVE_WALLET_SWAP_FROM},
    {"braveWalletSwapTo", IDS_BRAVE_WALLET_SWAP_TO},
    {"braveWalletSwapEstimate", IDS_BRAVE_WALLET_SWAP_ESTIMATE},
    {"braveWalletSwapMarket", IDS_BRAVE_WALLET_SWAP_MARKET},
    {"braveWalletSwapLimit", IDS_BRAVE_WALLET_SWAP_LIMIT},
    {"braveWalletSwapPriceIn", IDS_BRAVE_WALLET_SWAP_PRICE_IN},
    {"braveWalletBuyTitle", IDS_BRAVE_WALLET_BUY_TITLE},
    {"braveWalletBuyDescription", IDS_BRAVE_WALLET_BUY_DESCRIPTION},
    {"braveWalletBuyWyreButton", IDS_BRAVE_WALLET_BUY_WYRE_BUTTON},
    {"braveWalletBuyFaucetButton", IDS_BRAVE_WALLET_BUY_FAUCET_BUTTON},
    {"braveWalletSignTransactionTitle",
     IDS_BRAVE_WALLET_SIGN_TRANSACTION_TITLE},
    {"braveWalletSignWarning", IDS_BRAVE_WALLET_SIGN_WARNING},
    {"braveWalletSignWarningTitle", IDS_BRAVE_WALLET_SIGN_WARNING_TITLE},
    {"braveWalletSignTransactionMessageTitle",
     IDS_BRAVE_WALLET_SIGN_TRANSACTION_MESSAGE_TITLE},
    {"braveWalletSignTransactionButton",
     IDS_BRAVE_WALLET_SIGN_TRANSACTION_BUTTON},
    {"braveWalletAllowSpendTitle", IDS_BRAVE_WALLET_ALLOW_SPEND_TITLE},
    {"braveWalletAllowSpendDescription",
     IDS_BRAVE_WALLET_ALLOW_SPEND_DESCRIPTION},
    {"braveWalletAllowSpendBoxTitle", IDS_BRAVE_WALLET_ALLOW_SPEND_BOX_TITLE},
    {"braveWalletAllowSpendTransactionFee",
     IDS_BRAVE_WALLET_ALLOW_SPEND_TRANSACTION_FEE},
    {"braveWalletAllowSpendEditButton",
     IDS_BRAVE_WALLET_ALLOW_SPEND_EDIT_BUTTON},
    {"braveWalletAllowSpendDetailsButton",
     IDS_BRAVE_WALLET_ALLOW_SPEND_DETAILS_BUTTON},
    {"braveWalletAllowSpendRejectButton",
     IDS_BRAVE_WALLET_ALLOW_SPEND_REJECT_BUTTON},
    {"braveWalletAllowSpendConfirmButton",
     IDS_BRAVE_WALLET_ALLOW_SPEND_CONFIRM_BUTTON},
    {"braveWalletAllowSpendCurrentAllowance",
     IDS_BRAVE_WALLET_ALLOW_SPEND_CURRENT_ALLOWANCE},
    {"braveWalletAllowSpendProposedAllowance",
     IDS_BRAVE_WALLET_ALLOW_SPEND_PROPOSED_ALLOWANCE},
    {"braveWalletAllowAddNetworkTitle",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_TITLE},
    {"braveWalletAllowAddNetworkDescription",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_DESCRIPTION},
    {"braveWalletAllowAddNetworkLearnMoreButton",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_LEARN_MORE_BUTTON},
    {"braveWalletAllowAddNetworkName", IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_NAME},
    {"braveWalletAllowAddNetworkUrl", IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_URL},
    {"braveWalletAllowAddNetworkDetailsButton",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_DETAILS_BUTTON},
    {"braveWalletAllowAddNetworkApproveButton",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_APPROVE_BUTTON},
    {"braveWalletAllowAddNetworkChainID",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_CHAIN_I_D},
    {"braveWalletAllowAddNetworkCurrencySymbol",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_CURRENCY_SYMBOL},
    {"braveWalletAllowAddNetworkExplorer",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_EXPLORER},
    {"braveWalletConfirmTransactionTotal",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_TOTAL},
    {"braveWalletConfirmTransactionGasFee",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_GAS_FEE},
    {"braveWalletConfirmTransactionBid",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_BID},
    {"braveWalletConfirmTransactionAmountGas",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_AMOUNT_GAS},
    {"braveWalletConfirmTransactionNoData",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_NO_DATA},
    {"braveWalletConfirmTransactionNext",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_NEXT},
    {"braveWalletConfirmTransactionFrist",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_FRIST},
    {"braveWalletConfirmTransactions", IDS_BRAVE_WALLET_CONFIRM_TRANSACTIONS},
    {"braveWalletPanelTitle", IDS_BRAVE_WALLET_PANEL_TITLE},
    {"braveWalletPanelConnected", IDS_BRAVE_WALLET_PANEL_CONNECTED},
    {"braveWalletSitePermissionsAccounts",
     IDS_BRAVE_WALLET_SITE_PERMISSIONS_ACCOUNTS},
    {"braveWalletSitePermissionsTitle",
     IDS_BRAVE_WALLET_SITE_PERMISSIONS_TITLE},
    {"braveWalletSitePermissionsDisconnect",
     IDS_BRAVE_WALLET_SITE_PERMISSIONS_DISCONNECT},
    {"braveWalletPanelNotConnected", IDS_BRAVE_WALLET_PANEL_NOT_CONNECTED},
    {"braveWalletTransactionDetailBoxFunction",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_BOX_FUNCTION},
    {"braveWalletTransactionDetailBoxHex",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_BOX_HEX},
    {"braveWalletTransactionDetailBoxBytes",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_BOX_BYTES},
    {"braveWalletConnectWithSiteTitle",
     IDS_BRAVE_WALLET_CONNECT_WITH_SITE_TITLE},
    {"braveWalletConnectWithSiteDescription1",
     IDS_BRAVE_WALLET_CONNECT_WITH_SITE_DESCRIPTION1},
    {"braveWalletConnectWithSiteDescription2",
     IDS_BRAVE_WALLET_CONNECT_WITH_SITE_DESCRIPTION2},
    {"braveWalletConnectWithSiteNext", IDS_BRAVE_WALLET_CONNECT_WITH_SITE_NEXT},
    {"braveWalletConnectWithSiteHeaderTitle",
     IDS_BRAVE_WALLET_CONNECT_WITH_SITE_HEADER_TITLE},
    {"braveWalletImportFromExternalNewPassword",
     IDS_BRAVE_WALLET_IMPORT_FROM_EXTERNAL_NEW_PASSWORD},
    {"braveWalletImportFromExternalCreatePassword",
     IDS_BRAVE_WALLET_IMPORT_FROM_EXTERNAL_CREATE_PASSWORD},
    {"braveWalletImportFromExternalPasswordCheck",
     IDS_BRAVE_WALLET_IMPORT_FROM_EXTERNAL_PASSWORD_CHECK},
    {"braveWalletImportMetaMaskTitle", IDS_BRAVE_WALLET_IMPORT_META_MASK_TITLE},
    {"braveWalletImportTitle", IDS_BRAVE_WALLET_IMPORT_TITLE},
    {"braveWalletImportDescriptionOne",
     IDS_BRAVE_WALLET_IMPORT_DESCRIPTION_ONE},
    {"braveWalletImportDescriptionTwo",
     IDS_BRAVE_WALLET_IMPORT_DESCRIPTION_TWO},
    {"braveWalletImportMetaMaskInput", IDS_BRAVE_WALLET_IMPORT_META_MASK_INPUT},
    {"braveWalletImportBraveLegacyTitle",
     IDS_BRAVE_WALLET_IMPORT_BRAVE_LEGACY_TITLE},
    {"braveWalletCryptoWalletsDetected",
     IDS_BRAVE_WALLET_CRYPTO_WALLETS_DETECTED},
    {"braveWalletCryptoWalletsDescriptionOne",
     IDS_BRAVE_WALLET_CRYPTO_WALLETS_DESCRIPTION_ONE},
    {"braveWalletCryptoWalletsDescriptionTwoFirst",
     IDS_BRAVE_WALLET_CRYPTO_WALLETS_DESCRIPTION_TWO_FIRST},
    {"braveWalletCryptoWalletsDescriptionTwoSecond",
     IDS_BRAVE_WALLET_CRYPTO_WALLETS_DESCRIPTION_TWO_SECOND},
    {"braveWalletImportBraveLegacyDescription",
     IDS_BRAVE_WALLET_IMPORT_BRAVE_LEGACY_DESCRIPTION},
    {"braveWalletImportBraveLegacyInput",
     IDS_BRAVE_WALLET_IMPORT_BRAVE_LEGACY_INPUT},
    {"braveWalletImportBraveLegacyAltButton",
     IDS_BRAVE_WALLET_IMPORT_BRAVE_LEGACY_ALT_BUTTON},
    {"braveWalletConnectHardwarePanelConnected",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_CONNECTED},
    {"braveWalletConnectHardwarePanelDisconnected",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_DISCONNECTED},
    {"braveWalletConnectHardwarePanelInstructions",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_INSTRUCTIONS},
    {"braveWalletConnectHardwarePanelConnect",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_CONNECT},
    {"braveWalletConnectHardwarePanelConfirmation",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_CONFIRMATION},
    {"braveWalletTransactionSent", IDS_BRAVE_WALLET_TRANSACTION_SENT},
    {"braveWalletTransactionReceived", IDS_BRAVE_WALLET_TRANSACTION_RECEIVED},
    {"braveWalletTransactionExplorerMissing",
     IDS_BRAVE_WALLET_TRANSACTION_EXPLORER_MISSING},
    {"braveWalletTransactionExplorer", IDS_BRAVE_WALLET_TRANSACTION_EXPLORER},
    {"braveWalletTransactionPlaceholder",
     IDS_BRAVE_WALLET_TRANSACTION_PLACEHOLDER},
    {"braveWalletEditGasTitle1", IDS_BRAVE_WALLET_EDIT_GAS_TITLE1},
    {"braveWalletEditGasTitle2", IDS_BRAVE_WALLET_EDIT_GAS_TITLE2},
    {"braveWalletEditGasDescription", IDS_BRAVE_WALLET_EDIT_GAS_DESCRIPTION},
    {"braveWalletEditGasLow", IDS_BRAVE_WALLET_EDIT_GAS_LOW},
    {"braveWalletEditGasOptimal", IDS_BRAVE_WALLET_EDIT_GAS_OPTIMAL},
    {"braveWalletEditGasHigh", IDS_BRAVE_WALLET_EDIT_GAS_HIGH},
    {"braveWalletEditGasLimit", IDS_BRAVE_WALLET_EDIT_GAS_LIMIT},
    {"braveWalletEditGasPerGasPrice", IDS_BRAVE_WALLET_EDIT_GAS_PER_GAS_PRICE},
    {"braveWalletEditGasPerTipLimit", IDS_BRAVE_WALLET_EDIT_GAS_PER_TIP_LIMIT},
    {"braveWalletEditGasPerPriceLimit",
     IDS_BRAVE_WALLET_EDIT_GAS_PER_PRICE_LIMIT},
    {"braveWalletEditGasMaxFee", IDS_BRAVE_WALLET_EDIT_GAS_MAX_FEE},
    {"braveWalletEditGasMaximumFee", IDS_BRAVE_WALLET_EDIT_GAS_MAXIMUM_FEE},
    {"braveWalletEditGasBaseFee", IDS_BRAVE_WALLET_EDIT_GAS_BASE_FEE},
    {"braveWalletEditGasGwei", IDS_BRAVE_WALLET_EDIT_GAS_GWEI},
    {"braveWalletEditGasSetCustom", IDS_BRAVE_WALLET_EDIT_GAS_SET_CUSTOM},
    {"braveWalletEditGasSetSuggested", IDS_BRAVE_WALLET_EDIT_GAS_SET_SUGGESTED},
    {"braveWalletEditPermissionsTitle",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_TITLE},
    {"braveWalletEditPermissionsDescription",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_DESCRIPTION},
    {"braveWalletEditPermissionsButton",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_BUTTON},
    {"braveWalletEditPermissionsProposedAllowance",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_PROPOSED_ALLOWANCE},
    {"braveWalletEditPermissionsCustomAllowance",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_CUSTOM_ALLOWANCE},
    {"braveWalletNotValidEthAddress", IDS_BRAVE_WALLET_NOT_VALID_ETH_ADDRESS},
    {"braveWalletNotValidAddress", IDS_BRAVE_WALLET_NOT_VALID_ADDRESS},
    {"braveWalletNotDomain", IDS_BRAVE_WALLET_NOT_DOMAIN},
    {"braveWalletQueueOf", IDS_BRAVE_WALLET_QUEUE_OF},
    {"braveWalletQueueNext", IDS_BRAVE_WALLET_QUEUE_NEXT},
    {"braveWalletQueueFirst", IDS_BRAVE_WALLET_QUEUE_FIRST},
    {"braveWalletQueueRejectAll", IDS_BRAVE_WALLET_QUEUE_REJECT_ALL},
    {"braveWalletSwapInsufficientBalance",
     IDS_BRAVE_WALLET_SWAP_INSUFFICIENT_BALANCE},
    {"braveWalletSwapInsufficientEthBalance",
     IDS_BRAVE_WALLET_SWAP_INSUFFICIENT_ETH_BALANCE},
    {"braveWalletSwapInsufficientLiquidity",
     IDS_BRAVE_WALLET_SWAP_INSUFFICIENT_LIQUIDITY},
    {"braveWalletSwapInsufficientAllowance",
     IDS_BRAVE_WALLET_SWAP_INSUFFICIENT_ALLOWANCE},
    {"braveWalletSwapUnknownError", IDS_BRAVE_WALLET_SWAP_UNKNOWN_ERROR},
    {"braveWalletUnlockError", IDS_BRAVE_WALLET_UNLOCK_ERROR},
    {"braveWalletDeviceUnknownScheme", IDS_BRAVE_WALLET_UNKNOWN_SCHEME_ERROR},
    {"braveWalletApprovalTransactionIntent",
     IDS_BRAVE_WALLET_APPROVAL_TRANSACTION_INTENT},
    {"braveWalletLedgerValidationError",
     IDS_BRAVE_WALLET_LEDGER_VALIDATION_ERROR},
    {"braveWalletHardwareAccountNotFound",
     IDS_BRAVE_WALLET_HARDWARE_ACCOUNT_NOT_FOUND_ERROR},
    {"braveWalletCreateBridgeError",
     IDS_BRAVE_WALLET_HARDWARE_CREATE_BRIDGE_ERROR},
    {"braveWalletImportingAccountsError",
     IDS_BRAVE_WALLET_HARDWARE_ACCOUNTS_IMPORT_ERROR}};

const char kRopstenSwapBaseAPIURL[] = "https://ropsten.api.0x.org/";
const char kRopstenBuyTokenPercentageFee[] = "0.00875";
const char kRopstenFeeRecipient[] =
    "0xa92D461a9a988A7f11ec285d39783A637Fdd6ba4";

const char kSwapBaseAPIURL[] = "https://api.0x.org/";
const char kBuyTokenPercentageFee[] = "0.00875";
const char kFeeRecipient[] = "0xbd9420A98a7Bd6B89765e5715e169481602D9c3d";
const int64_t kBlockTrackerDefaultTimeInSeconds = 20;

// Unstoppable domains record key for ethereum address.
constexpr char kCryptoEthAddressKey[] = "crypto.ETH.address";

}  // namespace brave_wallet

#endif  // BRAVE_COMPONENTS_BRAVE_WALLET_BROWSER_BRAVE_WALLET_CONSTANTS_H_
