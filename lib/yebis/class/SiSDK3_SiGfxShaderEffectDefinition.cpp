// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_570790 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_570790, field_10, 0x10);

struct Unk_570010 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_570010, field_18, 0x18);

struct Unk_570020 {
    u8 _0[0x48];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_570020, field_48, 0x48);

struct Unk_570030 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_570030, field_78, 0x78);

struct Unk_570040 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_570040, field_a8, 0xa8);

struct Unk_570050 {
    u8 _0[0xac];
    u32 field_ac;
};
PKMN_OFFSET_ASSERT(Unk_570050, field_ac, 0xac);

struct Unk_5706d0 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_5706d0, field_c0, 0xc0);

struct Unk_5706e0 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_5706e0, field_c0, 0xc0);

namespace SiSDK3 {
class SiGfxShaderEffectDefinition {
public:
    u32 vf4();
    const u8* vf5();
    const u8* vf6();
    const u8* vf7();
    u32 vf8();
    u32 vf9();
    u64 vf17();
    u64 vf18();
};
}  // namespace SiSDK3

// 0x7100570010
const u8* SiSDK3::SiGfxShaderEffectDefinition::vf5() {
    const Unk_570010* self = reinterpret_cast<const Unk_570010*>(this);
    return &self->field_18;
}

// 0x7100570020
const u8* SiSDK3::SiGfxShaderEffectDefinition::vf6() {
    const Unk_570020* self = reinterpret_cast<const Unk_570020*>(this);
    return &self->field_48;
}

// 0x7100570030
const u8* SiSDK3::SiGfxShaderEffectDefinition::vf7() {
    const Unk_570030* self = reinterpret_cast<const Unk_570030*>(this);
    return &self->field_78;
}

// 0x7100570040
u32 SiSDK3::SiGfxShaderEffectDefinition::vf8() {
    const Unk_570040* self = reinterpret_cast<const Unk_570040*>(this);
    return self->field_a8;
}

// 0x7100570050
u32 SiSDK3::SiGfxShaderEffectDefinition::vf9() {
    const Unk_570050* self = reinterpret_cast<const Unk_570050*>(this);
    return self->field_ac;
}

// 0x71005706d0
u64 SiSDK3::SiGfxShaderEffectDefinition::vf17() {
    const Unk_5706d0* self = reinterpret_cast<const Unk_5706d0*>(this);
    return self->field_c0;
}

// 0x71005706e0
u64 SiSDK3::SiGfxShaderEffectDefinition::vf18() {
    const Unk_5706e0* self = reinterpret_cast<const Unk_5706e0*>(this);
    return self->field_c0;
}

// 0x7100570790
u32 SiSDK3::SiGfxShaderEffectDefinition::vf4() {
    const Unk_570790* self = reinterpret_cast<const Unk_570790*>(this);
    return self->field_10;
}
