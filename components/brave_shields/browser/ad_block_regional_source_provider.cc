/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_shields/browser/ad_block_regional_source_provider.h"

#include <memory>

#include "base/files/file_path.h"
#include "base/logging.h"
#include "base/task/thread_pool.h"
#include "brave/components/brave_shields/browser/ad_block_component_installer.h"
#include "content/public/browser/browser_task_traits.h"

// TODO this should be unused
#define DAT_FILE "rs-ABPFilterParserData.dat"

namespace brave_shields {

AdBlockRegionalSourceProvider::AdBlockRegionalSourceProvider(component_updater::ComponentUpdateService* cus, const adblock::FilterList& catalog_entry) {
  // TODO save catalog_entry.uuid as well
  RegisterAdBlockRegionalComponent(cus, catalog_entry.base64_public_key, catalog_entry.component_id, catalog_entry.title, base::BindRepeating(&AdBlockRegionalSourceProvider::OnComponentReady, base::Unretained(this)));
}

AdBlockRegionalSourceProvider::~AdBlockRegionalSourceProvider() {}

void AdBlockRegionalSourceProvider::OnComponentReady(const base::FilePath& path) {
  component_path_ = path;

  base::ThreadPool::PostTaskAndReplyWithResult(
      FROM_HERE, {base::MayBlock()},
      base::BindOnce(&brave_component_updater::ReadDATFileData, component_path_.AppendASCII(DAT_FILE)),
      base::BindOnce(&AdBlockRegionalSourceProvider::ProvideNewDAT,
                     base::Unretained(this)));
}

void AdBlockRegionalSourceProvider::Load(base::OnceCallback<void(bool deserialize, const DATFileDataBuffer& dat_buf)> cb) {
  if (component_path_.empty()) {
    // If the path is not ready yet, just provide an empty buffer. An update
    // should be pushed soon.
    return;
  }

  base::ThreadPool::PostTaskAndReplyWithResult(
      FROM_HERE, {base::MayBlock()},
      base::BindOnce(&brave_component_updater::ReadDATFileData, component_path_.AppendASCII(DAT_FILE)),
      base::BindOnce(std::move(cb), true));
}

}  // namespace brave_shields
