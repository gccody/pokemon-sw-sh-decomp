// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4e2e30 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4e2e30, field_10, 0x10);

struct Unk_4e2e40 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4e2e40, field_18, 0x18);

struct Unk_4e2e50 {
    u8 _0[0x34];
    f32 field_34;
};
PKMN_OFFSET_ASSERT(Unk_4e2e50, field_34, 0x34);

struct Unk_4e2d20 {
    u8 _0[0x34];
    f32 field_34;
};
PKMN_OFFSET_ASSERT(Unk_4e2d20, field_34, 0x34);

struct Unk_4e2e60 {
    u8 _0[0x38];
    f32 field_38;
};
PKMN_OFFSET_ASSERT(Unk_4e2e60, field_38, 0x38);

struct Unk_4e2d30 {
    u8 _0[0x38];
    f32 field_38;
};
PKMN_OFFSET_ASSERT(Unk_4e2d30, field_38, 0x38);

struct Unk_4e2e70 {
    u8 _0[0x3c];
    f32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_4e2e70, field_3c, 0x3c);

struct Unk_4e2d40 {
    u8 _0[0x3c];
    f32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_4e2d40, field_3c, 0x3c);

struct Unk_4e2e80 {
    u8 _0[0x40];
    f32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_4e2e80, field_40, 0x40);

struct Unk_4e2d50 {
    u8 _0[0x40];
    f32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_4e2d50, field_40, 0x40);

struct Unk_4e2e90 {
    u8 _0[0x44];
    f32 field_44;
};
PKMN_OFFSET_ASSERT(Unk_4e2e90, field_44, 0x44);

struct Unk_4e2d60 {
    u8 _0[0x44];
    f32 field_44;
};
PKMN_OFFSET_ASSERT(Unk_4e2d60, field_44, 0x44);

struct Unk_4e2d70 {
    u8 _0[0x48];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_4e2d70, field_48, 0x48);

struct Unk_4e2d80 {
    u8 _0[0x4c];
    u32 field_4c;
};
PKMN_OFFSET_ASSERT(Unk_4e2d80, field_4c, 0x4c);

struct Unk_4e2ea0 {
    u8 _0[0x1c];
    u8 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_4e2ea0, field_1c, 0x1c);

namespace SiSDK3 {
class SiGfxPerformanceUtility {
public:
    u32 vf4();
    u32 vf7();
    f32 vf9();
    u32 vf10(f32 fvalue);
    f32 vf11();
    u32 vf12(f32 fvalue);
    f32 vf13();
    u32 vf14(f32 fvalue);
    f32 vf15();
    u32 vf16(f32 fvalue);
    f32 vf17();
    u32 vf18(f32 fvalue);
    u32 vf19(u32 value);
    u32 vf20(u32 value);
    const u8* vf21();
};
}  // namespace SiSDK3

// 0x71004e2d20
u32 SiSDK3::SiGfxPerformanceUtility::vf10(f32 fvalue) {
    Unk_4e2d20* self = reinterpret_cast<Unk_4e2d20*>(this);
    self->field_34 = fvalue;
    return 1;
}

// 0x71004e2d30
u32 SiSDK3::SiGfxPerformanceUtility::vf12(f32 fvalue) {
    Unk_4e2d30* self = reinterpret_cast<Unk_4e2d30*>(this);
    self->field_38 = fvalue;
    return 1;
}

// 0x71004e2d40
u32 SiSDK3::SiGfxPerformanceUtility::vf14(f32 fvalue) {
    Unk_4e2d40* self = reinterpret_cast<Unk_4e2d40*>(this);
    self->field_3c = fvalue;
    return 1;
}

// 0x71004e2d50
u32 SiSDK3::SiGfxPerformanceUtility::vf16(f32 fvalue) {
    Unk_4e2d50* self = reinterpret_cast<Unk_4e2d50*>(this);
    self->field_40 = fvalue;
    return 1;
}

// 0x71004e2d60
u32 SiSDK3::SiGfxPerformanceUtility::vf18(f32 fvalue) {
    Unk_4e2d60* self = reinterpret_cast<Unk_4e2d60*>(this);
    self->field_44 = fvalue;
    return 1;
}

// 0x71004e2d70
u32 SiSDK3::SiGfxPerformanceUtility::vf19(u32 value) {
    Unk_4e2d70* self = reinterpret_cast<Unk_4e2d70*>(this);
    self->field_48 = value;
    return 1;
}

// 0x71004e2d80
u32 SiSDK3::SiGfxPerformanceUtility::vf20(u32 value) {
    Unk_4e2d80* self = reinterpret_cast<Unk_4e2d80*>(this);
    self->field_4c = value;
    return 1;
}

// 0x71004e2e30
u32 SiSDK3::SiGfxPerformanceUtility::vf4() {
    const Unk_4e2e30* self = reinterpret_cast<const Unk_4e2e30*>(this);
    return self->field_10;
}

// 0x71004e2e40
u32 SiSDK3::SiGfxPerformanceUtility::vf7() {
    const Unk_4e2e40* self = reinterpret_cast<const Unk_4e2e40*>(this);
    return self->field_18;
}

// 0x71004e2e50
f32 SiSDK3::SiGfxPerformanceUtility::vf9() {
    const Unk_4e2e50* self = reinterpret_cast<const Unk_4e2e50*>(this);
    return self->field_34;
}

// 0x71004e2e60
f32 SiSDK3::SiGfxPerformanceUtility::vf11() {
    const Unk_4e2e60* self = reinterpret_cast<const Unk_4e2e60*>(this);
    return self->field_38;
}

// 0x71004e2e70
f32 SiSDK3::SiGfxPerformanceUtility::vf13() {
    const Unk_4e2e70* self = reinterpret_cast<const Unk_4e2e70*>(this);
    return self->field_3c;
}

// 0x71004e2e80
f32 SiSDK3::SiGfxPerformanceUtility::vf15() {
    const Unk_4e2e80* self = reinterpret_cast<const Unk_4e2e80*>(this);
    return self->field_40;
}

// 0x71004e2e90
f32 SiSDK3::SiGfxPerformanceUtility::vf17() {
    const Unk_4e2e90* self = reinterpret_cast<const Unk_4e2e90*>(this);
    return self->field_44;
}

// 0x71004e2ea0
const u8* SiSDK3::SiGfxPerformanceUtility::vf21() {
    const Unk_4e2ea0* self = reinterpret_cast<const Unk_4e2ea0*>(this);
    return &self->field_1c;
}
