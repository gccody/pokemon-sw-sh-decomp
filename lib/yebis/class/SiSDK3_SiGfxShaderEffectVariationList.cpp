// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_573770 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_573770, field_10, 0x10);

struct Unk_5725b0 {
    u8 _0[0xb8];
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_5725b0, field_b8, 0xb8);

struct Unk_573260 {
    u8 _0[0x108];
    u32 field_108;
};
PKMN_OFFSET_ASSERT(Unk_573260, field_108, 0x108);

struct Unk_573360 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_573360, field_170, 0x170);

struct Unk_573460 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_573460, field_50, 0x50);

struct Unk_573470 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_573470, field_48, 0x48);

namespace SiSDK3 {
class SiGfxShaderEffectVariationList {
public:
    u32 vf4();
    u32 vf11();
    u32 vf13();
    u8 vf16();
    const u8* vf20();
    u64 vf21();
};
}  // namespace SiSDK3

// 0x71005725b0
u32 SiSDK3::SiGfxShaderEffectVariationList::vf11() {
    const Unk_5725b0* self = reinterpret_cast<const Unk_5725b0*>(this);
    return self->field_b8;
}

// 0x7100573260
u32 SiSDK3::SiGfxShaderEffectVariationList::vf13() {
    const Unk_573260* self = reinterpret_cast<const Unk_573260*>(this);
    return self->field_108;
}

// 0x7100573360
u8 SiSDK3::SiGfxShaderEffectVariationList::vf16() {
    const Unk_573360* self = reinterpret_cast<const Unk_573360*>(this);
    return self->field_170;
}

// 0x7100573460
const u8* SiSDK3::SiGfxShaderEffectVariationList::vf20() {
    const Unk_573460* self = reinterpret_cast<const Unk_573460*>(this);
    return &self->field_50;
}

// 0x7100573470
u64 SiSDK3::SiGfxShaderEffectVariationList::vf21() {
    const Unk_573470* self = reinterpret_cast<const Unk_573470*>(this);
    return self->field_48;
}

// 0x7100573770
u32 SiSDK3::SiGfxShaderEffectVariationList::vf4() {
    const Unk_573770* self = reinterpret_cast<const Unk_573770*>(this);
    return self->field_10;
}
