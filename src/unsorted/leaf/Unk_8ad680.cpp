// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ad680 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_8ad680, field_80, 0x80);

void Unk_8ae890(u64);

// 0x71008ad680
void Unk_8ad680_call(const Unk_8ad680* self) {
    Unk_8ae890(self->field_80);
}

struct Unk_8ad690 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_8ad690, field_80, 0x80);

void Unk_8aea20(u64);

// 0x71008ad690
void Unk_8ad690_call(const Unk_8ad690* self) {
    Unk_8aea20(self->field_80);
}

struct Unk_8ad930 {
    u8 _0[0x2530];
    s32 field_2530;
};
PKMN_OFFSET_ASSERT(Unk_8ad930, field_2530, 0x2530);

// 0x71008ad930
bool Unk_8ad930_check(const Unk_8ad930* self) {
    return self->field_2530 > 2;
}

struct Unk_8ad940 {
    u8 _0[0x2530];
    u32 field_2530;
};
PKMN_OFFSET_ASSERT(Unk_8ad940, field_2530, 0x2530);

// 0x71008ad940
bool Unk_8ad940_check(const Unk_8ad940* self) {
    return self->field_2530 == 8;
}

struct Unk_8ada10 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_8ada10, field_80, 0x80);

void Unk_8b03c0(u64, u32, u32);

// 0x71008ada10
void Unk_8ada10_call(const Unk_8ada10* self, u32 value) {
    Unk_8b03c0(self->field_80, 2, value);
}

struct Unk_8ada20 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_8ada20, field_80, 0x80);

void Unk_8b03c0(u64, u32, u32);

// 0x71008ada20
void Unk_8ada20_call(const Unk_8ada20* self) {
    Unk_8b03c0(self->field_80, 1, 0);
}

struct Unk_8ada30 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_8ada30, field_80, 0x80);

void Unk_8b0650(u64);

// 0x71008ada30
void Unk_8ada30_call(const Unk_8ada30* self) {
    Unk_8b0650(self->field_80);
}

struct Unk_8ada40 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_8ada40, field_80, 0x80);

void Unk_8b09a0(u64);

// 0x71008ada40
void Unk_8ada40_call(const Unk_8ada40* self) {
    Unk_8b09a0(self->field_80);
}

struct Unk_8adaa0 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_8adaa0, field_80, 0x80);

void Unk_8b0c90(u64);

// 0x71008adaa0
void Unk_8adaa0_call(const Unk_8adaa0* self) {
    Unk_8b0c90(self->field_80);
}

struct Unk_27d13ec_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d13ec_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d13ec_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d13ec_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d13ec_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d13ec_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d13ec_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d13ec_Data, field_18, 0x18);

extern Unk_27d13ec_Data Unk_27d13ec __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008adab0
void Unk_8adab0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d13ec.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d13ec.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d13ec.field_18 = 0xffff;
    Unk_27d13ec.field_10 = 0;
    Unk_27d13ec.field_8 = r2;
    Unk_27d13ec.field_c = 0;
    Unk_27d13ec.field_14 = 0xffffffff;
}
