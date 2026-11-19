// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82cca0 {
    u8 _0[0xb48];
    u8 field_b48;
};
PKMN_OFFSET_ASSERT(Unk_82cca0, field_b48, 0xb48);

// 0x710082cca0
void Unk_82cca0_clearFieldb48(Unk_82cca0* self) {
    self->field_b48 = 0;
}

struct Unk_82ccb0 {
    u8 _0[0xb48];
    u8 field_b48;
};
PKMN_OFFSET_ASSERT(Unk_82ccb0, field_b48, 0xb48);

// 0x710082ccb0
u8 Unk_82ccb0_getFieldb48(const Unk_82ccb0* self) {
    return self->field_b48;
}

struct Unk_27cf204_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cf204_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cf204_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cf204_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cf204_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cf204_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cf204_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cf204_Data, field_18, 0x18);

extern Unk_27cf204_Data Unk_27cf204 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710082d5f0
void Unk_82d5f0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cf204.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cf204.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cf204.field_18 = 0xffff;
    Unk_27cf204.field_10 = 0;
    Unk_27cf204.field_8 = r2;
    Unk_27cf204.field_c = 0;
    Unk_27cf204.field_14 = 0xffffffff;
}
