// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7e88d0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_7e88d0, field_10, 0x10);

// 0x71007e88d0
u64 Unk_7e88d0_getField10(const Unk_7e88d0* self) {
    return self->field_10;
}

struct Unk_7e88e0 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7e88e0, field_30, 0x30);

// 0x71007e88e0
u64 Unk_7e88e0_getField30(const Unk_7e88e0* self) {
    return self->field_30;
}

struct Unk_7e88f0 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_7e88f0, field_90, 0x90);

// 0x71007e88f0
u64 Unk_7e88f0_getField90(const Unk_7e88f0* self) {
    return self->field_90;
}

struct Unk_7e8900 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_7e8900, field_b0, 0xb0);

// 0x71007e8900
u64 Unk_7e8900_getFieldb0(const Unk_7e8900* self) {
    return self->field_b0;
}

struct Unk_7e8910 {
    u8 _0[0x130];
    u64 field_130;
};
PKMN_OFFSET_ASSERT(Unk_7e8910, field_130, 0x130);

// 0x71007e8910
u64 Unk_7e8910_getField130(const Unk_7e8910* self) {
    return self->field_130;
}

struct Unk_7e8920 {
    u8 _0[0x150];
    u64 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7e8920, field_150, 0x150);

// 0x71007e8920
u64 Unk_7e8920_getField150(const Unk_7e8920* self) {
    return self->field_150;
}

struct Unk_7e8930 {
    u8 _0[0x170];
    u64 field_170;
};
PKMN_OFFSET_ASSERT(Unk_7e8930, field_170, 0x170);

// 0x71007e8930
u64 Unk_7e8930_getField170(const Unk_7e8930* self) {
    return self->field_170;
}

struct Unk_27cec3c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cec3c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cec3c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cec3c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cec3c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cec3c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cec3c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cec3c_Data, field_18, 0x18);

extern Unk_27cec3c_Data Unk_27cec3c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71007e8940
void Unk_7e8940_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cec3c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cec3c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cec3c.field_18 = 0xffff;
    Unk_27cec3c.field_10 = 0;
    Unk_27cec3c.field_8 = r2;
    Unk_27cec3c.field_c = 0;
    Unk_27cec3c.field_14 = 0xffffffff;
}
