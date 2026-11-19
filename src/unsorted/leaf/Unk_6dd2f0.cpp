// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71006dd2f0
u64 Unk_6dd2f0() {
    return 0;
}

struct Unk_277950c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_277950c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_277950c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_277950c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_277950c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_277950c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_277950c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_277950c_Data, field_18, 0x18);

extern Unk_277950c_Data Unk_277950c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006dd300
void Unk_6dd300_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_277950c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_277950c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_277950c.field_10 = 0xffff;
    Unk_277950c.field_8 = r2;
    Unk_277950c.field_c = 0xffffffff;
    Unk_277950c.field_18 = 0;
    Unk_277950c.field_14 = 0;
}
