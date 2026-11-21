// SiSDK3::SiGfxShaderEffectKey (RTTI names the class; the file's name is a
// placeholder after it): some bytes that identify a shader program among an
// effect's. Its destructor is empty (0x7100535ff0; the deleting one is
// 0x7100536390). Placeholder members.
#pragma once

#include <stddef.h>
#include <types.h>

namespace SiSDK3 {

class SiGfxShaderEffectKey {
public:
    SiGfxShaderEffectKey() : field_8(0), field_c(0), field_10(nullptr) {}
    virtual ~SiGfxShaderEffectKey() {}

    // sets the bytes (inline in its callers: placeholder name)
    void Unk_Set(s32 size, u8* bytes) {
        field_c = size;
        field_10 = bytes;
    }

    u32 field_8;
    s32 field_c;   // the number of bytes
    u8* field_10;  // the bytes
};
PKMN_SIZE_ASSERT(SiGfxShaderEffectKey, 0x18);

}  // namespace SiSDK3
