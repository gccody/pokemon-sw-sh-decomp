// Scope: common
// A static initialiser, as a function: the statics it sets are one placeholder struct
// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.
// Order: split
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

struct Unk_27dd4e0_Data {
    Unk_Init_Vec4 field_0;
};
PKMN_OFFSET_ASSERT(Unk_27dd4e0_Data, field_0, 0x0);

extern Unk_27dd4e0_Data Unk_27dd4e0;

struct Unk_27dd504_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dd504_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dd504_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dd504_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dd504_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dd504_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dd504_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dd504_Data, field_18, 0x18);

extern Unk_27dd504_Data Unk_27dd504 __attribute__((visibility("hidden")));

namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d712c0
void Unk_d712c0_init() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dd504.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dd504.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dd504.field_18 = 0xffff;
    Unk_27dd504.field_14 = 0xffffffff;
    Unk_27dd504.field_10 = 0;
    Unk_27dd504.field_8 = r2;
    Unk_27dd504.field_c = 0;
    Unk_27dd4e0.field_0.Set(2445.0f, 2.0f, 845.0f, 0);
}
