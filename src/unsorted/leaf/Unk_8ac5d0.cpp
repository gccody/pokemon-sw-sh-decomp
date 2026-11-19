// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ac5d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u16 field_18;
    u8 field_1a;
    u8 _1b[0x5];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_1a, 0x1a);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_20, 0x20);

// 0x71008ac5d0
void Unk_8ac5d0_set(Unk_8ac5d0* self) {
    self->field_20 = 0;
    self->field_1a = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
}

struct Unk_27d138c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d138c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d138c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d138c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d138c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d138c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d138c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d138c_Data, field_18, 0x18);

extern Unk_27d138c_Data Unk_27d138c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008ac780
void Unk_8ac780_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d138c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d138c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d138c.field_18 = 0xffff;
    Unk_27d138c.field_10 = 0;
    Unk_27d138c.field_8 = r2;
    Unk_27d138c.field_c = 0;
    Unk_27d138c.field_14 = 0xffffffff;
}
