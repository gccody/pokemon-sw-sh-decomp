// Scope: common
// A static initialiser, as a function: the statics it sets are one placeholder struct
// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.
// Order: delay
#include <arm_neon.h>

#include <types.h>

// Four floats stored together.
struct Unk_Init_Vec4 {
    void Set(f32 x, f32 y, f32 z, f32 w) {
        float32x4_t value = {x, y, z, w};
        vst1q_f32(v, value);
    }

    f32 v[4];
};

struct Unk_27ee5f4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
    u8 _1a[0x62];
    Unk_Init_Vec4 field_7c;
    Unk_Init_Vec4 field_8c;
    Unk_Init_Vec4 field_9c;
    Unk_Init_Vec4 field_ac;
    Unk_Init_Vec4 field_bc;
    Unk_Init_Vec4 field_cc;
    Unk_Init_Vec4 field_dc;
};
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_7c, 0x7c);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_8c, 0x8c);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_9c, 0x9c);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_ac, 0xac);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_bc, 0xbc);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_27ee5f4_Data, field_dc, 0xdc);

extern Unk_27ee5f4_Data Unk_27ee5f4 __attribute__((visibility("hidden")));

namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71012937e0
void Unk_12937e0_init() {
    Unk_27ee5f4.field_7c.Set(2e+04f, 0, 2e+04f, 0);
    Unk_27ee5f4.field_8c.Set(2e+03f, 0, 2e+03f, 0);
    Unk_27ee5f4.field_9c.Set(2e+04f, 0, 1.965e+04f, 0);
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ee5f4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ee5f4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ee5f4.field_ac.Set(0, 0, 7e+02f, 0);
    Unk_27ee5f4.field_18 = 0xffff;
    Unk_27ee5f4.field_bc.Set(0, 0, -1.1e+03f, 0);
    Unk_27ee5f4.field_14 = 0xffffffff;
    Unk_27ee5f4.field_cc.Set(-1.2e+03f, 0, -2.5e+02f, 0);
    Unk_27ee5f4.field_10 = 0;
    Unk_27ee5f4.field_dc.Set(1.2e+03f, 0, -2.5e+02f, 0);
    Unk_27ee5f4.field_8 = r2;
    Unk_27ee5f4.field_c = 0;
}
