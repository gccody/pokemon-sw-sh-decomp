// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82d670 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_82d670, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_82d670, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82d670, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_82d670, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_82d670, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_82d670, field_28, 0x28);

// 0x710082d670
void Unk_82d670_set(Unk_82d670* self) {
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

void Unk_7eb260(u32);

// 0x710082d990
void Unk_82d990_call(u32 self) {
    Unk_7eb260(self);
}

void Unk_780d70(u32);

// 0x710082da60
void Unk_82da60_call(u32 self) {
    Unk_780d70(self);
}

void Unk_7812a0(u32);

// 0x710082da70
void Unk_82da70_call(u32 self) {
    Unk_7812a0(self);
}

struct Unk_27cf224_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cf224_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cf224_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cf224_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cf224_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cf224_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cf224_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cf224_Data, field_18, 0x18);

extern Unk_27cf224_Data Unk_27cf224 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710082dc80
void Unk_82dc80_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cf224.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cf224.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cf224.field_18 = 0xffff;
    Unk_27cf224.field_10 = 0;
    Unk_27cf224.field_8 = r2;
    Unk_27cf224.field_c = 0;
    Unk_27cf224.field_14 = 0xffffffff;
}
