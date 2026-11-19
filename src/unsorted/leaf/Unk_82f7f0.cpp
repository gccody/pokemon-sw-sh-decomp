// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82f7f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_82f7f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_82f7f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82f7f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_82f7f0, field_18, 0x18);

// 0x710082f7f0
void Unk_82f7f0_set(Unk_82f7f0* self) {
    self->field_18 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_0 = 0;
}

// 0x710082f800
void Unk_82f800() {}

struct Unk_82f810 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_82f810, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_82f810, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82f810, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_82f810, field_18, 0x18);

// 0x710082f810
void Unk_82f810_set(Unk_82f810* self) {
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_0 = 0;
    self->field_18 = 1;
}

struct Unk_82f830 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_82f830, field_18, 0x18);

// 0x710082f830
void Unk_82f830_clearField18(Unk_82f830* self) {
    self->field_18 = 0;
}

struct Unk_27cf384_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cf384_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cf384_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cf384_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cf384_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cf384_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cf384_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cf384_Data, field_18, 0x18);

extern Unk_27cf384_Data Unk_27cf384 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710082f960
void Unk_82f960_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cf384.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cf384.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cf384.field_18 = 0xffff;
    Unk_27cf384.field_10 = 0;
    Unk_27cf384.field_8 = r2;
    Unk_27cf384.field_c = 0;
    Unk_27cf384.field_14 = 0xffffffff;
}
