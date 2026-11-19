// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6b7650 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_6b7650, field_78, 0x78);

// 0x71006b7650
u32 Unk_6b7650_getField78(const Unk_6b7650* self) {
    return self->field_78;
}

struct Unk_6b7660 {
    u8 _0[0x160];
    u32 field_160;
};
PKMN_OFFSET_ASSERT(Unk_6b7660, field_160, 0x160);

// 0x71006b7660
u32 Unk_6b7660_getField160(const Unk_6b7660* self) {
    return self->field_160;
}

struct Unk_2778eec_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2778eec_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2778eec_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2778eec_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2778eec_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2778eec_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2778eec_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2778eec_Data, field_18, 0x18);

extern Unk_2778eec_Data Unk_2778eec __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006b8fb0
void Unk_6b8fb0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2778eec.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2778eec.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2778eec.field_10 = 0xffff;
    Unk_2778eec.field_8 = r2;
    Unk_2778eec.field_c = 0xffffffff;
    Unk_2778eec.field_18 = 0;
    Unk_2778eec.field_14 = 0;
}
