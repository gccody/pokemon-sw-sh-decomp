// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e41310 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e41310, field_60, 0x60);

// 0x7100e41310
void Unk_e41310_setField60(Unk_e41310* self, u64 value) {
    self->field_60 = value;
}

// 0x7100e420a0
void Unk_e420a0() {}

struct Unk_e420b0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e420b0, field_78, 0x78);

// 0x7100e420b0
void Unk_e420b0_set(Unk_e420b0* self) {
    self->field_78 = 1;
}

// 0x7100e420c0
void Unk_e420c0() {}

struct Unk_e42280 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_e42280, field_80, 0x80);

// 0x7100e42280
bool Unk_e42280_check(const Unk_e42280* self) {
    return self->field_80 == 0;
}

struct Unk_27e0164_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e0164_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e0164_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e0164_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e0164_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e0164_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e0164_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e0164_Data, field_18, 0x18);

extern Unk_27e0164_Data Unk_27e0164 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100e427d0
void Unk_e427d0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e0164.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e0164.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e0164.field_18 = 0xffff;
    Unk_27e0164.field_10 = 0;
    Unk_27e0164.field_8 = r2;
    Unk_27e0164.field_c = 0;
    Unk_27e0164.field_14 = 0xffffffff;
}
