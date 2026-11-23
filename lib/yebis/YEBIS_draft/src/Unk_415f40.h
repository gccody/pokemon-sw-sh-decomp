// Scope: common
// What YEBIS's first translation unit (0x710040f610 to 0x7100417870, see
// Unk_415f40.cpp) gives the others.
#pragma once

#include <types.h>
#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>

namespace PPFX {

// 0x7100412cd0: five sample offsets for a `width` by `height` texture
void Unk_412cd0(f32 scale, u32 width, u32 height, Unk_Float4* out);

// 0x7100413160: the sample offsets and weights of a blur (one of two kinds);
// their count
s32 Unk_413160(u32 width, u32 height, u32 arg2, Unk_Float4* out, u32 mode, u32 second, f32 scale);

}  // namespace PPFX
