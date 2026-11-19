// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1453cb0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1453cb0, field_0, 0x0);

// 0x7101453cb0
u32 Unk_1453cb0_get(const Unk_1453cb0* self) {
    return self->field_0 & 3;
}

struct Unk_1453cc0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1453cc0, field_0, 0x0);

// 0x7101453cc0
u32 Unk_1453cc0_get(const Unk_1453cc0* self) {
    return (self->field_0 >> 2) & 3;
}

struct Unk_1453cd0 {
    u8 _0[0x1];
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_1453cd0, field_1, 0x1);

// 0x7101453cd0
u8 Unk_1453cd0_getField1(const Unk_1453cd0* self) {
    return self->field_1;
}

struct Unk_1453ce0 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_1453ce0, field_2, 0x2);

// 0x7101453ce0
u8 Unk_1453ce0_getField2(const Unk_1453ce0* self) {
    return self->field_2;
}

struct Unk_1453e00 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1453e00, field_8, 0x8);

// 0x7101453e00
u64 Unk_1453e00_getField8(const Unk_1453e00* self) {
    return self->field_8;
}

struct Unk_1453e10 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1453e10, field_10, 0x10);

// 0x7101453e10
u64 Unk_1453e10_getField10(const Unk_1453e10* self) {
    return self->field_10;
}

struct Unk_1453e20 {
    u8 _0[0x3];
    u8 field_3;
};
PKMN_OFFSET_ASSERT(Unk_1453e20, field_3, 0x3);

// 0x7101453e20
bool Unk_1453e20_check(const Unk_1453e20* self) {
    return self->field_3 != 0;
}

struct Unk_27f0bec_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f0bec_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f0bec_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f0bec_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f0bec_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f0bec_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f0bec_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f0bec_Data, field_18, 0x18);

extern Unk_27f0bec_Data Unk_27f0bec __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71014554a0
void Unk_14554a0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f0bec.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f0bec.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f0bec.field_18 = 0xffff;
    Unk_27f0bec.field_10 = 0;
    Unk_27f0bec.field_8 = r2;
    Unk_27f0bec.field_c = 0;
    Unk_27f0bec.field_14 = 0xffffffff;
}
