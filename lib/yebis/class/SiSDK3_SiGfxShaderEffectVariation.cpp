// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_575d50 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_575d50, field_10, 0x10);

struct Unk_574c60 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_574c60, field_18, 0x18);

struct Unk_574c70 {
    u8 _0[0xc8];
    u32 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_574c70, field_c8, 0xc8);

struct Unk_574c80 {
    u8 _0[0xcc];
    u32 field_cc;
};
PKMN_OFFSET_ASSERT(Unk_574c80, field_cc, 0xcc);

struct Unk_575370 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_575370, field_150, 0x150);

struct Unk_575380 {
    u8 _0[0x154];
    u32 field_154;
};
PKMN_OFFSET_ASSERT(Unk_575380, field_154, 0x154);

namespace SiSDK3 {
class SiGfxShaderEffectVariation {
public:
    u32 vf4();
    const u8* vf5();
    u32 vf6();
    u32 vf7();
    u32 vf10();
    u32 vf11();
};
}  // namespace SiSDK3

// 0x7100574c60
const u8* SiSDK3::SiGfxShaderEffectVariation::vf5() {
    const Unk_574c60* self = reinterpret_cast<const Unk_574c60*>(this);
    return &self->field_18;
}

// 0x7100574c70
u32 SiSDK3::SiGfxShaderEffectVariation::vf6() {
    const Unk_574c70* self = reinterpret_cast<const Unk_574c70*>(this);
    return self->field_c8;
}

// 0x7100574c80
u32 SiSDK3::SiGfxShaderEffectVariation::vf7() {
    const Unk_574c80* self = reinterpret_cast<const Unk_574c80*>(this);
    return self->field_cc;
}

// 0x7100575370
u32 SiSDK3::SiGfxShaderEffectVariation::vf10() {
    const Unk_575370* self = reinterpret_cast<const Unk_575370*>(this);
    return self->field_150;
}

// 0x7100575380
u32 SiSDK3::SiGfxShaderEffectVariation::vf11() {
    const Unk_575380* self = reinterpret_cast<const Unk_575380*>(this);
    return self->field_154;
}

// 0x7100575d50
u32 SiSDK3::SiGfxShaderEffectVariation::vf4() {
    const Unk_575d50* self = reinterpret_cast<const Unk_575d50*>(this);
    return self->field_10;
}
