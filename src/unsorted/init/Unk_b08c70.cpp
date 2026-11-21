// Scope: common
// A static initialiser, as a function: the statics it sets are one placeholder struct
// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.
// Order: split
#include <types.h>

struct Unk_27d7bb0_Data {
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
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_27d7bb0_Data, field_48, 0x48);

extern Unk_27d7bb0_Data Unk_27d7bb0 __attribute__((visibility("hidden")));

namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100b08c70
void Unk_b08c70_init() {
    Unk_27d7bb0.field_20 = 0x927c0;
    Unk_27d7bb0.field_28 = 0x1b58;
    Unk_27d7bb0.field_30 = 0x927c0;
    Unk_27d7bb0.field_38 = 0x1b58;
    Unk_27d7bb0.field_40 = 0x927c0;
    Unk_27d7bb0.field_48 = 0x1b58;
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d7bb0.field_4 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d7bb0.field_8 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d7bb0.field_1c = 0xffff;
    Unk_27d7bb0.field_14 = 0;
    Unk_27d7bb0.field_c = r2;
    Unk_27d7bb0.field_10 = 0;
    Unk_27d7bb0.field_18 = 0xffffffff;
}
