// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710106fcf0
void Unk_106fcf0() {}

struct Unk_106fd00 {
    u8 _0[0x1c];
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_106fd00, field_1c, 0x1c);

// 0x710106fd00
u32 Unk_106fd00_getField1c(const Unk_106fd00* self) {
    return self->field_1c;
}

struct Unk_106fd30 {
    u8 _0[0x24];
    u8 field_24;
};
PKMN_OFFSET_ASSERT(Unk_106fd30, field_24, 0x24);

// 0x710106fd30
u8 Unk_106fd30_getField24(const Unk_106fd30* self) {
    return self->field_24;
}

struct Unk_106fd40 {
    u8 _0[0x25];
    u8 field_25;
};
PKMN_OFFSET_ASSERT(Unk_106fd40, field_25, 0x25);

// 0x710106fd40
u8 Unk_106fd40_getField25(const Unk_106fd40* self) {
    return self->field_25;
}

struct Unk_27e3cb4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3cb4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3cb4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3cb4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3cb4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3cb4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3cb4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3cb4_Data, field_18, 0x18);

extern Unk_27e3cb4_Data Unk_27e3cb4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710106ffd0
void Unk_106ffd0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3cb4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3cb4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3cb4.field_10 = 0xffff;
    Unk_27e3cb4.field_8 = r2;
    Unk_27e3cb4.field_c = 0xffffffff;
    Unk_27e3cb4.field_18 = 0;
    Unk_27e3cb4.field_14 = 0;
}
