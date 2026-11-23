// The version in SiSDK3's file headers (placeholder name, after the function
// of SiGfxShaderEffectPackage that first showed it): four numbers, which its
// constructor clears. A shader effect package's header and a binary archive's
// have one.
#pragma once

#include <types.h>

namespace SiSDK3 {

struct Unk_567750_Version {
    Unk_567750_Version() : field_0(0), field_4(0), field_8(0), field_c(0) {}
    Unk_567750_Version(s32 a, s32 b, s32 c, s32 d) : field_0(a), field_4(b), field_8(c), field_c(d) {}

    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
};

}  // namespace SiSDK3
