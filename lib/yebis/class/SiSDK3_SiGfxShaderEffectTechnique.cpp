// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_570c20 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_570c20, field_10, 0x10);

struct Unk_5709c0 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_5709c0, field_18, 0x18);

struct Unk_5709d0 {
    u8 _0[0x4c];
    u32 field_4c;
};
PKMN_OFFSET_ASSERT(Unk_5709d0, field_4c, 0x4c);

namespace SiSDK3 {
class SiGfxShaderEffectTechnique {
public:
    u32 vf4();
    const u8* vf5();
    u32 vf6();
};
}  // namespace SiSDK3

// 0x71005709c0
const u8* SiSDK3::SiGfxShaderEffectTechnique::vf5() {
    const Unk_5709c0* self = reinterpret_cast<const Unk_5709c0*>(this);
    return &self->field_18;
}

// 0x71005709d0
u32 SiSDK3::SiGfxShaderEffectTechnique::vf6() {
    const Unk_5709d0* self = reinterpret_cast<const Unk_5709d0*>(this);
    return self->field_4c;
}

// 0x7100570c20
u32 SiSDK3::SiGfxShaderEffectTechnique::vf4() {
    const Unk_570c20* self = reinterpret_cast<const Unk_570c20*>(this);
    return self->field_10;
}
