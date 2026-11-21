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

struct Unk_27ec7e4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
    u8 _1a[0x12];
    Unk_Init_Vec4 field_2c;
    Unk_Init_Vec4 field_3c;
    Unk_Init_Vec4 field_4c;
    Unk_Init_Vec4 field_5c;
    u8 _6c[0x20];
    Unk_Init_Vec4 field_8c;
    Unk_Init_Vec4 field_9c;
    Unk_Init_Vec4 field_ac;
};
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_3c, 0x3c);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_4c, 0x4c);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_8c, 0x8c);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_9c, 0x9c);
PKMN_OFFSET_ASSERT(Unk_27ec7e4_Data, field_ac, 0xac);

extern Unk_27ec7e4_Data Unk_27ec7e4 __attribute__((visibility("hidden")));

namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71011fdaf0
void Unk_11fdaf0_init() {
    Unk_27ec7e4.field_2c.Set(2e+04f, 0, 2e+04f, 0);
    Unk_27ec7e4.field_3c.Set(2e+03f, 0, 2e+03f, 0);
    Unk_27ec7e4.field_4c.Set(2e+04f, 0, 1.965e+04f, 0);
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ec7e4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ec7e4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ec7e4.field_5c.Set(0, 0, 7e+02f, 0);
    Unk_27ec7e4.field_18 = 0xffff;
    Unk_27ec7e4.field_8c.Set(0, 0, -1.1e+03f, 0);
    Unk_27ec7e4.field_14 = 0xffffffff;
    Unk_27ec7e4.field_9c.Set(-1.2e+03f, 0, -2.5e+02f, 0);
    Unk_27ec7e4.field_10 = 0;
    Unk_27ec7e4.field_ac.Set(1.2e+03f, 0, -2.5e+02f, 0);
    Unk_27ec7e4.field_8 = r2;
    Unk_27ec7e4.field_c = 0;
}
