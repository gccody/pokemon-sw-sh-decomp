// Scope: common
// YEBIS's first translation unit (0x710040f610 to 0x7100417870, before
// ppfx.cpp): matrix and filter kernel helpers and the SiReflection
// properties its static initialiser 0x7100415f40 registers. Its name isn't
// in the executable.
#include <yebis/YEBIS_draft/src/Unk_415f40.h>

namespace PPFX {

// 0x7100412cd0
void Unk_412cd0(f32 scale, u32 width, u32 height, Unk_Float4* out) {
    f32 dx = scale / static_cast<f32>(width);
    f32 dy = scale / static_cast<f32>(height);
    out[0] = Unk_Float4(dx * 0.0f, dy * 0.0f, 0.0f, 0.0f);
    out[1] = Unk_Float4(dx * -1.0f, dy * -1.0f, 0.0f, 0.0f);
    out[2] = Unk_Float4(dx * 1.0f, dy * 1.0f, 0.0f, 0.0f);
    out[3] = Unk_Float4(dx * -1.0f, dy * 1.0f, 0.0f, 0.0f);
    out[4] = Unk_Float4(dx * -1.0f, dy * -1.0f, 0.0f, 0.0f);
}

}  // namespace PPFX
