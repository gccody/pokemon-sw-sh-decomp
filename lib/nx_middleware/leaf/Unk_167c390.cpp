// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_27fb0c8_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u8 _c[0x4];
    u32 field_10;
    u16 field_14;
    u8 _16[0x2];
    u32 field_18;
    u16 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_27fb0c8_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27fb0c8_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27fb0c8_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27fb0c8_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27fb0c8_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27fb0c8_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_27fb0c8_Data, field_1c, 0x1c);

extern Unk_27fb0c8_Data Unk_27fb0c8 __attribute__((visibility("hidden")));
namespace nn { namespace ldn { u64 MakeIpv4Address(u8, u8, u8, u8); } }

// 0x710167c390
void Unk_167c390_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27fb0c8.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27fb0c8.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27fb0c8.field_1c = 0xffff;
    Unk_27fb0c8.field_14 = 0;
    Unk_27fb0c8.field_8 = r2;
    Unk_27fb0c8.field_10 = 0;
    Unk_27fb0c8.field_18 = 0xffffffff;
}
