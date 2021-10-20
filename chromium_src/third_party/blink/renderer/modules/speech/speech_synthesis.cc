/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * you can obtain one at http://mozilla.org/MPL/2.0/. */

#include "third_party/blink/renderer/modules/speech/speech_synthesis.h"
#include "brave/third_party/blink/renderer/brave_farbling_constants.h"
#include "third_party/blink/public/platform/web_content_settings_client.h"

#define OnSetVoiceList OnSetVoiceList_ChromiumImpl
#include "../../../../../../../third_party/blink/renderer/modules/speech/speech_synthesis.cc"
#undef OnSetVoiceList

namespace blink {

void SpeechSynthesis::OnSetVoiceList(
    Vector<mojom::blink::SpeechSynthesisVoicePtr> mojom_voices) {
  voice_list_.clear();
  BraveFarblingLevel farbling_level = BraveFarblingLevel::OFF;
  if (ExecutionContext* context = GetExecutionContext()) {
    if (blink::WebContentSettingsClient* settings =
            brave::GetContentSettingsClientFor(context)) {
      farbling_level = settings->GetBraveFarblingLevel();
    }
  }
  if (farbling_level == BraveFarblingLevel::MAXIMUM) {
    // maximum farbling -> return empty voice list
    VoicesDidChange();
    return;
  }
  mojom::blink::SpeechSynthesisVoicePtr fake_voice = nullptr;
  for (auto& mojom_voice : mojom_voices) {
    if (!fake_voice && mojom_voice->is_default &&
        (farbling_level == BraveFarblingLevel::BALANCED)) {
      // balanced farbling -> return real voices + one fake voice
      if (ExecutionContext* context = GetExecutionContext()) {
        fake_voice = mojom_voice.Clone();
        fake_voice->is_default = false;
        std::mt19937_64 prng = brave::BraveSessionCache::From(*context)
                                   .MakePseudoRandomGenerator();
        std::vector<WTF::String> fake_names = {
            "Hubert", "Vernon", "Rudolph",   "Clayton",    "Irving",
            "Wilson", "Alva",   "Harley",    "Beauregard", "Cleveland",
            "Cecil",  "Reuben", "Sylvester", "Jasper"};
        fake_voice->name = fake_names[(prng() % fake_names.size())];
      }
    }
    voice_list_.push_back(
        MakeGarbageCollected<SpeechSynthesisVoice>(std::move(mojom_voice)));
  }
  if (fake_voice) {
    voice_list_.push_back(
        MakeGarbageCollected<SpeechSynthesisVoice>(std::move(fake_voice)));
  }
  VoicesDidChange();
}

}  // namespace blink
