// SiSDK3::SiGfxShaderEffectKey (RTTI names the class; the file's name is a
// placeholder after it): some bytes that identify a shader program among an
// effect's. Its destructor is empty (0x7100535ff0; the deleting one is
// 0x7100536390). Placeholder members.
#pragma once

#include <stddef.h>
#include <string.h>
#include <types.h>

namespace SiSDK3 {

class SiGfxShaderEffectKey {
public:
    SiGfxShaderEffectKey() : field_8(0), field_c(0), field_10(nullptr) {}
    // a key whose bytes are the derived class's own (the ShowTexture keys)
    SiGfxShaderEffectKey(s32 size, u8* bytes) : field_8(0), field_c(size), field_10(bytes) {}
    virtual ~SiGfxShaderEffectKey() {}

    // sets the bytes (inline in its callers: placeholder name)
    void Unk_Set(s32 size, u8* bytes) {
        field_c = size;
        field_10 = bytes;
    }

    // clears the bytes and the number (inline in its callers: placeholder
    // name)
    void Unk_Clear() {
        if (field_c >= 1 && field_10 != nullptr) {
            memset(field_10, 0, field_c);
            field_8 = 0;
        }
    }

    // 0 if both have the same size, number and bytes, else which is greater
    // (inline in its callers: placeholder name; SiGfxShaderEffectVariationList's
    // slots 5 and 6 ask for equality)
    int Unk_Compare(const SiGfxShaderEffectKey& other) const {
        if (field_c < other.field_c) {
            return -1;
        }
        if (field_c > other.field_c) {
            return 1;
        }
        if (field_8 < other.field_8) {
            return -1;
        }
        if (field_8 > other.field_8) {
            return 1;
        }
        for (s32 i = 0; i < field_c; i++) {
            if (field_10[i] < other.field_10[i]) {
                return -1;
            }
            if (field_10[i] > other.field_10[i]) {
                return 1;
            }
        }
        return 0;
    }

    u32 field_8;
    s32 field_c;   // the number of bytes
    u8* field_10;  // the bytes
};
PKMN_SIZE_ASSERT(SiGfxShaderEffectKey, 0x18);

}  // namespace SiSDK3
