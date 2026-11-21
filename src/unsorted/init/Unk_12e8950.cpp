// Scope: common
// A static initialiser, as a function: the statics it sets are one placeholder struct
// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.
// Order: split
#include <types.h>

struct Unk_27eefa8_Data {
    u8 _0[0x4];
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u16 field_14;
    u8 _16[0x2];
    u32 field_18;
    u16 field_1c;
    u8 _1e[0x2];
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_27eefa8_Data, field_48, 0x48);

extern Unk_27eefa8_Data Unk_27eefa8 __attribute__((visibility("hidden")));

namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71012e8950
void Unk_12e8950_init() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27eefa8.field_4 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27eefa8.field_8 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27eefa8.field_14 = 0xffff;
    Unk_27eefa8.field_c = r2;
    Unk_27eefa8.field_10 = 0xffffffff;
    Unk_27eefa8.field_1c = 0;
    Unk_27eefa8.field_18 = 0;
    Unk_27eefa8.field_20 = 0x927c0;
    Unk_27eefa8.field_28 = 0x1b58;
    Unk_27eefa8.field_30 = 0x927c0;
    Unk_27eefa8.field_38 = 0x1b58;
    Unk_27eefa8.field_40 = 0x927c0;
    Unk_27eefa8.field_48 = 0x1b58;
}
