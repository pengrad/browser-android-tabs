// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_VR_ELEMENTS_VECTOR_ICON_H_
#define CHROME_BROWSER_VR_ELEMENTS_VECTOR_ICON_H_

#include "third_party/skia/include/core/SkColor.h"

namespace gfx {
class Canvas;
class PointF;
struct VectorIcon;
}  // namespace gfx

namespace vr {

void DrawVectorIcon(gfx::Canvas* canvas,
                    const gfx::VectorIcon& icon,
                    float size_px,
                    const gfx::PointF& corner,
                    SkColor color);

}  // namespace vr

#endif  // CHROME_BROWSER_VR_ELEMENTS_VECTOR_ICON_H_
