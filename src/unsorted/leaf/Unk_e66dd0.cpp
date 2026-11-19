// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e66dd0 {
    u8 _0[0x85];
    u8 field_85;
};
PKMN_OFFSET_ASSERT(Unk_e66dd0, field_85, 0x85);

// 0x7100e66dd0
u8 Unk_e66dd0_getField85(const Unk_e66dd0* self) {
    return self->field_85;
}

struct Unk_27e039c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e039c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e039c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e039c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e039c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e039c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e039c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e039c_Data, field_18, 0x18);

extern Unk_27e039c_Data Unk_27e039c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100e67670
void Unk_e67670_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e039c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e039c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e039c.field_18 = 0xffff;
    Unk_27e039c.field_10 = 0;
    Unk_27e039c.field_8 = r2;
    Unk_27e039c.field_c = 0;
    Unk_27e039c.field_14 = 0xffffffff;
}
