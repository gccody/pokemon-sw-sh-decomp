// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_829d30 {
    u8 _0[0x8];
    u32 field_8;
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_829d30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_829d30, field_c, 0xc);

// 0x7100829d30
void Unk_829d30_set(Unk_829d30* self) {
    self->field_c = 5;
    self->field_8 = 0x5050505;
}

struct Unk_27cf064_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cf064_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cf064_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cf064_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cf064_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cf064_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cf064_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cf064_Data, field_18, 0x18);

extern Unk_27cf064_Data Unk_27cf064 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710082a1f0
void Unk_82a1f0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cf064.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cf064.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cf064.field_18 = 0xffff;
    Unk_27cf064.field_10 = 0;
    Unk_27cf064.field_8 = r2;
    Unk_27cf064.field_c = 0;
    Unk_27cf064.field_14 = 0xffffffff;
}
