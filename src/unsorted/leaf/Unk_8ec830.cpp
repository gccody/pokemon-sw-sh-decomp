// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ec830 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_8ec830, field_50, 0x50);

// 0x71008ec830
u32 Unk_8ec830_getField50(const Unk_8ec830* self) {
    return self->field_50;
}

struct Unk_8ec840_10 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8ec840_10, field_60, 0x60);

struct Unk_8ec840 {
    u8 _0[0x10];
    Unk_8ec840_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_8ec840, field_10, 0x10);

// 0x71008ec840
void Unk_8ec840_set(const Unk_8ec840* self) {
    self->field_10->field_60 = 1;
}

struct Unk_8ec890 {
    u8 _0[0x28];
    u8 field_28;
    u8 _29[0xf];
    u16 field_38;
};
PKMN_OFFSET_ASSERT(Unk_8ec890, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8ec890, field_38, 0x38);

// 0x71008ec890
void Unk_8ec890_set(Unk_8ec890* self, u8 value) {
    self->field_28 = value;
    self->field_38 = 1;
}

struct Unk_8ec8a0 {
    u8 _0[0x39];
    u8 field_39;
};
PKMN_OFFSET_ASSERT(Unk_8ec8a0, field_39, 0x39);

// 0x71008ec8a0
u8 Unk_8ec8a0_getField39(const Unk_8ec8a0* self) {
    return self->field_39;
}

struct Unk_8ec8b0_10 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8ec8b0_10, field_60, 0x60);

struct Unk_8ec8b0 {
    u8 _0[0x10];
    Unk_8ec8b0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_8ec8b0, field_10, 0x10);

// 0x71008ec8b0
void Unk_8ec8b0_set(const Unk_8ec8b0* self) {
    self->field_10->field_60 = 1;
}

struct Unk_8ec900_10 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8ec900_10, field_60, 0x60);

struct Unk_8ec900 {
    u8 _0[0x10];
    Unk_8ec900_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_8ec900, field_10, 0x10);

// 0x71008ec900
void Unk_8ec900_set(const Unk_8ec900* self) {
    self->field_10->field_60 = 1;
}

struct Unk_8ec930 {
    u8 _0[0x2d];
    u8 field_2d;
};
PKMN_OFFSET_ASSERT(Unk_8ec930, field_2d, 0x2d);

// 0x71008ec930
u8 Unk_8ec930_getField2d(const Unk_8ec930* self) {
    return self->field_2d;
}

struct Unk_8ec940 {
    u8 _0[0x26];
    u16 field_26;
};
PKMN_OFFSET_ASSERT(Unk_8ec940, field_26, 0x26);

// 0x71008ec940
u16 Unk_8ec940_getField26(const Unk_8ec940* self) {
    return self->field_26;
}

struct Unk_8ec950 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_8ec950, field_28, 0x28);

// 0x71008ec950
u8 Unk_8ec950_getField28(const Unk_8ec950* self) {
    return self->field_28;
}

struct Unk_8ec960 {
    u8 _0[0x29];
    u8 field_29;
};
PKMN_OFFSET_ASSERT(Unk_8ec960, field_29, 0x29);

// 0x71008ec960
u8 Unk_8ec960_getField29(const Unk_8ec960* self) {
    return self->field_29;
}

// 0x71008ec970
void Unk_8ec970() {}

struct Unk_8ec980_10 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8ec980_10, field_60, 0x60);

struct Unk_8ec980 {
    u8 _0[0x10];
    Unk_8ec980_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_8ec980, field_10, 0x10);

// 0x71008ec980
void Unk_8ec980_set(const Unk_8ec980* self) {
    self->field_10->field_60 = 1;
}

struct Unk_8ec9e0 {
    u8 _0[0x1b0];
    u8 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_8ec9e0, field_1b0, 0x1b0);

// 0x71008ec9e0
u8 Unk_8ec9e0_getField1b0(const Unk_8ec9e0* self) {
    return self->field_1b0;
}
