// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_NTP_TILES_SWITCHES_H_
#define COMPONENTS_NTP_TILES_SWITCHES_H_

namespace ntp_tiles {
namespace switches {

extern const char kEnableNTPSearchEngineCountryDetection[];

extern const char kEnableNTPPopularSites[];
extern const char kDisableNTPPopularSites[];

// These switches are only introduced to allow iOS to override a feature.
// TODO(jkrcal): Remove once crbug.com/718926 is fixed.
extern const char kEnableNtpMostLikelyFaviconsFromServer[];
extern const char kDisableNtpMostLikelyFaviconsFromServer[];

}  // namespace switches
}  // namespace ntp_tiles

#endif  // COMPONENTS_NTP_TILES_SWITCHES_H_
