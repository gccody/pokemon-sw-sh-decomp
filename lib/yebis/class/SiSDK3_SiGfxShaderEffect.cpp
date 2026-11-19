// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_5792c0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5792c0, field_10, 0x10);

struct Unk_576b90 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_576b90, field_18, 0x18);

struct Unk_576ba0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_576ba0, field_18, 0x18);

struct Unk_576bf0 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_576bf0, field_20, 0x20);

struct Unk_576c00 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_576c00, field_90, 0x90);

struct Unk_576c10 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_576c10, field_a8, 0xa8);

struct Unk_576c20 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_576c20, field_a8, 0xa8);

struct Unk_578af0 {
    u8 _0[0x58];
    bool field_58;
};
PKMN_OFFSET_ASSERT(Unk_578af0, field_58, 0x58);

struct Unk_578b00 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_578b00, field_58, 0x58);

namespace SiSDK3 {
class SiGfxShaderEffect {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    const u8* vf8();
    const u8* vf9();
    u64 vf10();
    u64 vf11();
    void vf18(bool value);
    u8 vf19();
};
}  // namespace SiSDK3

// 0x7100576b90
u64 SiSDK3::SiGfxShaderEffect::vf5() {
    const Unk_576b90* self = reinterpret_cast<const Unk_576b90*>(this);
    return self->field_18;
}

// 0x7100576ba0
u64 SiSDK3::SiGfxShaderEffect::vf6() {
    const Unk_576ba0* self = reinterpret_cast<const Unk_576ba0*>(this);
    return self->field_18;
}

// 0x7100576bf0
const u8* SiSDK3::SiGfxShaderEffect::vf8() {
    const Unk_576bf0* self = reinterpret_cast<const Unk_576bf0*>(this);
    return &self->field_20;
}

// 0x7100576c00
const u8* SiSDK3::SiGfxShaderEffect::vf9() {
    const Unk_576c00* self = reinterpret_cast<const Unk_576c00*>(this);
    return &self->field_90;
}

// 0x7100576c10
u64 SiSDK3::SiGfxShaderEffect::vf10() {
    const Unk_576c10* self = reinterpret_cast<const Unk_576c10*>(this);
    return self->field_a8;
}

// 0x7100576c20
u64 SiSDK3::SiGfxShaderEffect::vf11() {
    const Unk_576c20* self = reinterpret_cast<const Unk_576c20*>(this);
    return self->field_a8;
}

// 0x7100578af0
void SiSDK3::SiGfxShaderEffect::vf18(bool value) {
    Unk_578af0* self = reinterpret_cast<Unk_578af0*>(this);
    self->field_58 = value;
}

// 0x7100578b00
u8 SiSDK3::SiGfxShaderEffect::vf19() {
    const Unk_578b00* self = reinterpret_cast<const Unk_578b00*>(this);
    return self->field_58;
}

// 0x71005792c0
u32 SiSDK3::SiGfxShaderEffect::vf4() {
    const Unk_5792c0* self = reinterpret_cast<const Unk_5792c0*>(this);
    return self->field_10;
}
