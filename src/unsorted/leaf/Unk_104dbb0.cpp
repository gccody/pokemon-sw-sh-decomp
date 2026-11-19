// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_104dbb0 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_104dbb0, field_50, 0x50);

// 0x710104dbb0
bool Unk_104dbb0_check(const Unk_104dbb0* self) {
    return self->field_50 >= 1 && self->field_50 <= 2;
}

struct Unk_104dbd0 {
    u8 _0[0x58];
    u32 field_58;
};
PKMN_OFFSET_ASSERT(Unk_104dbd0, field_58, 0x58);

// 0x710104dbd0
u32 Unk_104dbd0_getField58(const Unk_104dbd0* self) {
    return self->field_58;
}

struct Unk_104e020 {
    u8 _0[0x169];
    u8 field_169;
};
PKMN_OFFSET_ASSERT(Unk_104e020, field_169, 0x169);

// 0x710104e020
void Unk_104e020_set(Unk_104e020* self) {
    self->field_169 = 1;
}

struct Unk_104e030 {
    u8 _0[0x169];
    u8 field_169;
};
PKMN_OFFSET_ASSERT(Unk_104e030, field_169, 0x169);

// 0x710104e030
void Unk_104e030_clearField169(Unk_104e030* self) {
    self->field_169 = 0;
}

struct Unk_104e040 {
    u8 _0[0x168];
    u8 field_168;
};
PKMN_OFFSET_ASSERT(Unk_104e040, field_168, 0x168);

// 0x710104e040
void Unk_104e040_set(Unk_104e040* self) {
    self->field_168 = self->field_168 | 1;
}

struct Unk_104e080 {
    u8 _0[0x168];
    u8 field_168;
};
PKMN_OFFSET_ASSERT(Unk_104e080, field_168, 0x168);

// 0x710104e080
void Unk_104e080_set(Unk_104e080* self) {
    self->field_168 = self->field_168 | 2;
}

struct Unk_104e0c0 {
    u8 _0[0x16a];
    u8 field_16a;
};
PKMN_OFFSET_ASSERT(Unk_104e0c0, field_16a, 0x16a);

// 0x710104e0c0
void Unk_104e0c0_set(Unk_104e0c0* self) {
    self->field_16a = 1;
}

struct Unk_104e0d0 {
    u8 _0[0x16a];
    u8 field_16a;
};
PKMN_OFFSET_ASSERT(Unk_104e0d0, field_16a, 0x16a);

// 0x710104e0d0
void Unk_104e0d0_clearField16a(Unk_104e0d0* self) {
    self->field_16a = 0;
}

struct Unk_27e38cc_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e38cc_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e38cc_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e38cc_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e38cc_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e38cc_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e38cc_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e38cc_Data, field_18, 0x18);

extern Unk_27e38cc_Data Unk_27e38cc __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710104e950
void Unk_104e950_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e38cc.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e38cc.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e38cc.field_10 = 0xffff;
    Unk_27e38cc.field_8 = r2;
    Unk_27e38cc.field_c = 0xffffffff;
    Unk_27e38cc.field_18 = 0;
    Unk_27e38cc.field_14 = 0;
}
