// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK324SiGfxShaderEffectPackageE
#include <types.h>

struct Unk_56d940 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_56d940, field_10, 0x10);

struct Unk_568550 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_568550, field_18, 0x18);

struct Unk_568560 {
    u8 _0[0x48];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_568560, field_48, 0x48);

struct Unk_569580 {
    u8 _0[0x2d0];
    u8 field_2d0;
};
PKMN_OFFSET_ASSERT(Unk_569580, field_2d0, 0x2d0);

struct Unk_569590 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_569590, field_78, 0x78);

struct Unk_56c860 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_56c860, field_150, 0x150);

struct Unk_56ce30 {
    u8 _0[0xe38];
    u8 field_e38;
};
PKMN_OFFSET_ASSERT(Unk_56ce30, field_e38, 0xe38);

struct Unk_56ce40 {
    u8 _0[0x13c];
    bool field_13c;
};
PKMN_OFFSET_ASSERT(Unk_56ce40, field_13c, 0x13c);

struct Unk_56ce50 {
    u8 _0[0x13c];
    u8 field_13c;
};
PKMN_OFFSET_ASSERT(Unk_56ce50, field_13c, 0x13c);

struct Unk_56d2a0 {
    u8 _0[0x13d];
    bool field_13d;
};
PKMN_OFFSET_ASSERT(Unk_56d2a0, field_13d, 0x13d);

struct Unk_56d2b0 {
    u8 _0[0x13d];
    u8 field_13d;
};
PKMN_OFFSET_ASSERT(Unk_56d2b0, field_13d, 0x13d);

namespace SiSDK3 {
class SiGfxShaderEffectPackage {
public:
    u32 vf4();
    const u8* vf6();
    const u8* vf7();
    const u8* vf17();
    const u8* vf18();
    u32 vf19();
    const u8* vf23();
    void vf24(bool value);
    u8 vf25();
    void vf26(bool value);
    u8 vf27();
};
}  // namespace SiSDK3

// 0x7100568550
const u8* SiSDK3::SiGfxShaderEffectPackage::vf6() {
    const Unk_568550* self = reinterpret_cast<const Unk_568550*>(this);
    return &self->field_18;
}

// 0x7100568560
const u8* SiSDK3::SiGfxShaderEffectPackage::vf7() {
    const Unk_568560* self = reinterpret_cast<const Unk_568560*>(this);
    return &self->field_48;
}

// 0x7100569580
const u8* SiSDK3::SiGfxShaderEffectPackage::vf17() {
    const Unk_569580* self = reinterpret_cast<const Unk_569580*>(this);
    return &self->field_2d0;
}

// 0x7100569590
const u8* SiSDK3::SiGfxShaderEffectPackage::vf18() {
    const Unk_569590* self = reinterpret_cast<const Unk_569590*>(this);
    return &self->field_78;
}

// 0x710056c860
u32 SiSDK3::SiGfxShaderEffectPackage::vf19() {
    const Unk_56c860* self = reinterpret_cast<const Unk_56c860*>(this);
    return self->field_150;
}

// 0x710056ce30
const u8* SiSDK3::SiGfxShaderEffectPackage::vf23() {
    const Unk_56ce30* self = reinterpret_cast<const Unk_56ce30*>(this);
    return &self->field_e38;
}

// 0x710056ce40
void SiSDK3::SiGfxShaderEffectPackage::vf24(bool value) {
    Unk_56ce40* self = reinterpret_cast<Unk_56ce40*>(this);
    self->field_13c = value;
}

// 0x710056ce50
u8 SiSDK3::SiGfxShaderEffectPackage::vf25() {
    const Unk_56ce50* self = reinterpret_cast<const Unk_56ce50*>(this);
    return self->field_13c;
}

// 0x710056d2a0
void SiSDK3::SiGfxShaderEffectPackage::vf26(bool value) {
    Unk_56d2a0* self = reinterpret_cast<Unk_56d2a0*>(this);
    self->field_13d = value;
}

// 0x710056d2b0
u8 SiSDK3::SiGfxShaderEffectPackage::vf27() {
    const Unk_56d2b0* self = reinterpret_cast<const Unk_56d2b0*>(this);
    return self->field_13d;
}

// 0x710056d940
u32 SiSDK3::SiGfxShaderEffectPackage::vf4() {
    const Unk_56d940* self = reinterpret_cast<const Unk_56d940*>(this);
    return self->field_10;
}
