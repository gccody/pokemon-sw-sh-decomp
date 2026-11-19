// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e71990
u32 Unk_e71990_get() {
    return 1;
}

struct Unk_e719a0 {
    u8 _0[0x1c];
    u8 field_1c;
    u8 _1d[0x3];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_e719a0, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_e719a0, field_20, 0x20);

void Unk_e725a0(u64, u32);

// 0x7100e719a0
void Unk_e719a0_call(Unk_e719a0* self) {
    self->field_1c = 1;
    Unk_e725a0(self->field_20, 1);
}

struct Unk_e719c0 {
    u8 _0[0x1c];
    u8 field_1c;
    u8 _1d[0x3];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_e719c0, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_e719c0, field_20, 0x20);

void Unk_e725a0(u64, u32);

// 0x7100e719c0
void Unk_e719c0_call(Unk_e719c0* self) {
    self->field_1c = 0;
    Unk_e725a0(self->field_20, 0);
}

struct Unk_27e048c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e048c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e048c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e048c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e048c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e048c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e048c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e048c_Data, field_18, 0x18);

extern Unk_27e048c_Data Unk_27e048c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100e71d00
void Unk_e71d00_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e048c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e048c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e048c.field_18 = 0xffff;
    Unk_27e048c.field_10 = 0;
    Unk_27e048c.field_8 = r2;
    Unk_27e048c.field_c = 0;
    Unk_27e048c.field_14 = 0xffffffff;
}
