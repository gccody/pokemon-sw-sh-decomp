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
