// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_1453510(u32, u32, void*);

// 0x71008ac820
void Unk_8ac820_call(void* self, u32 value, u32 arg2) {
    Unk_1453510(value, arg2 < 3 ? (arg2 + 0xd) : 0x1b, self);
}

struct Unk_8ac9e0 {
    u8 _0[0x20];
    u32 field_20;
    u8 field_24;
    u8 field_25;
    u8 _26[0x2];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_8ac9e0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ac9e0, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_8ac9e0, field_25, 0x25);
PKMN_OFFSET_ASSERT(Unk_8ac9e0, field_28, 0x28);

// 0x71008ac9e0
void Unk_8ac9e0_set(Unk_8ac9e0* self, u8 value, u32 arg2) {
    self->field_20 = 0;
    self->field_24 = 0;
    self->field_25 = value;
    self->field_28 = arg2;
}

struct Unk_8acb50 {
    u8 _0[0x24];
    u8 field_24;
};
PKMN_OFFSET_ASSERT(Unk_8acb50, field_24, 0x24);

// 0x71008acb50
u8 Unk_8acb50_getField24(const Unk_8acb50* self) {
    return self->field_24;
}

struct Unk_27d13ac_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d13ac_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d13ac_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d13ac_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d13ac_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d13ac_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d13ac_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d13ac_Data, field_18, 0x18);

extern Unk_27d13ac_Data Unk_27d13ac __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008acb60
void Unk_8acb60_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d13ac.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d13ac.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d13ac.field_18 = 0xffff;
    Unk_27d13ac.field_10 = 0;
    Unk_27d13ac.field_8 = r2;
    Unk_27d13ac.field_c = 0;
    Unk_27d13ac.field_14 = 0xffffffff;
}
