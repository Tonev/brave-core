/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_ads/core/internal/account/utility/redeem_unblinded_token/create_confirmation_url_request_builder.h"

#include <utility>
#include <vector>

#include "base/check.h"
#include "base/strings/strcat.h"
#include "base/strings/stringprintf.h"
#include "brave/components/brave_ads/common/interfaces/ads.mojom.h"
#include "brave/components/brave_ads/core/internal/account/confirmations/confirmation_payload_json_writer.h"
#include "brave/components/brave_ads/core/internal/account/confirmations/confirmation_util.h"
#include "brave/components/brave_ads/core/internal/common/url/request_builder/host/url_host_util.h"
#include "url/gurl.h"

namespace brave_ads {

namespace {

std::vector<std::string> BuildHeaders() {
  std::vector<std::string> headers;

  const std::string accept_header = "accept: application/json";
  headers.push_back(accept_header);

  return headers;
}

}  // namespace

CreateConfirmationUrlRequestBuilder::CreateConfirmationUrlRequestBuilder(
    ConfirmationInfo confirmation)
    : confirmation_(std::move(confirmation)) {
  DCHECK(IsValid(confirmation_));
}

// POST /v3/confirmation/{transactionId}/{credential}

mojom::UrlRequestInfoPtr CreateConfirmationUrlRequestBuilder::Build() {
  mojom::UrlRequestInfoPtr url_request = mojom::UrlRequestInfo::New();
  url_request->url = BuildUrl();
  url_request->headers = BuildHeaders();
  url_request->content = BuildBody();
  url_request->content_type = "application/json";
  url_request->method = mojom::UrlRequestMethodType::kPost;

  return url_request;
}

///////////////////////////////////////////////////////////////////////////////

GURL CreateConfirmationUrlRequestBuilder::BuildUrl() const {
  const std::string url_host = confirmation_.ad_type == AdType::kSearchResultAd
                                   ? GetAnonymousSearchUrlHost()
                                   : GetAnonymousUrlHost();

  std::string credential_base64_url;
  if (confirmation_.opted_in && confirmation_.opted_in->credential_base64url) {
    credential_base64_url =
        base::StrCat({"/", *confirmation_.opted_in->credential_base64url});
  }

  const std::string spec = base::StringPrintf(
      "%s/v3/confirmation/%s%s", url_host.c_str(),
      confirmation_.transaction_id.c_str(), credential_base64_url.c_str());

  return GURL(spec);
}

std::string CreateConfirmationUrlRequestBuilder::BuildBody() const {
  return json::writer::WriteConfirmationPayload(confirmation_);
}

}  // namespace brave_ads
