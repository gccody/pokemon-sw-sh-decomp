// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7ce130 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_7ce130, field_a8, 0xa8);

// 0x71007ce130
u64 Unk_7ce130_getFielda8(const Unk_7ce130* self) {
    return self->field_a8;
}

struct Unk_7ce140 {
    u8 _0[0x6f];
    u8 field_6f;
};
PKMN_OFFSET_ASSERT(Unk_7ce140, field_6f, 0x6f);

// 0x71007ce140
u32 Unk_7ce140_get(const Unk_7ce140* self) {
    return (self->field_6f >> 6) & 1;
}

struct Unk_7cfdd0 {
    u8 _0[0x2b6];
    u8 field_2b6;
};
PKMN_OFFSET_ASSERT(Unk_7cfdd0, field_2b6, 0x2b6);

// 0x71007cfdd0
u8 Unk_7cfdd0_getField2b6(const Unk_7cfdd0* self) {
    return self->field_2b6;
}

struct Unk_7d0ac0 {
    u8 _0[0x2b5];
    u8 field_2b5;
};
PKMN_OFFSET_ASSERT(Unk_7d0ac0, field_2b5, 0x2b5);

// 0x71007d0ac0
void Unk_7d0ac0_set(Unk_7d0ac0* self) {
    self->field_2b5 = self->field_2b5 | 2;
}

struct Unk_7d0b40 {
    u8 _0[0x2b5];
    u8 field_2b5;
    u8 _2b6[0x9a];
    u64 field_350;
};
PKMN_OFFSET_ASSERT(Unk_7d0b40, field_2b5, 0x2b5);
PKMN_OFFSET_ASSERT(Unk_7d0b40, field_350, 0x350);

// 0x71007d0b40
void Unk_7d0b40_set(Unk_7d0b40* self, u64 value) {
    self->field_350 = value;
    self->field_2b5 = self->field_2b5 | 8;
}

struct Unk_7d0b60 {
    u8 _0[0x2b5];
    u8 field_2b5;
    u8 _2b6[0x9a];
    u64 field_350;
};
PKMN_OFFSET_ASSERT(Unk_7d0b60, field_2b5, 0x2b5);
PKMN_OFFSET_ASSERT(Unk_7d0b60, field_350, 0x350);

// 0x71007d0b60
void Unk_7d0b60_set(Unk_7d0b60* self) {
    self->field_350 = 0;
    self->field_2b5 = self->field_2b5 & 0xfffffff7;
}

struct Unk_7d0b80 {
    u8 _0[0xf0];
    u64 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_7d0b80, field_f0, 0xf0);

// 0x71007d0b80
u64 Unk_7d0b80_getFieldf0(const Unk_7d0b80* self) {
    return self->field_f0;
}

struct Unk_7d0b90 {
    u8 _0[0xf0];
    u64 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_7d0b90, field_f0, 0xf0);

// 0x71007d0b90
u64 Unk_7d0b90_getFieldf0(const Unk_7d0b90* self) {
    return self->field_f0;
}

struct Unk_7d0ba0 {
    u8 _0[0x250];
    u64 field_250;
};
PKMN_OFFSET_ASSERT(Unk_7d0ba0, field_250, 0x250);

// 0x71007d0ba0
u64 Unk_7d0ba0_getField250(const Unk_7d0ba0* self) {
    return self->field_250;
}

struct Unk_7d0bb0 {
    u8 _0[0x250];
    u64 field_250;
};
PKMN_OFFSET_ASSERT(Unk_7d0bb0, field_250, 0x250);

// 0x71007d0bb0
u64 Unk_7d0bb0_getField250(const Unk_7d0bb0* self) {
    return self->field_250;
}

struct Unk_7d0c10 {
    u8 _0[0x2b5];
    u8 field_2b5;
};
PKMN_OFFSET_ASSERT(Unk_7d0c10, field_2b5, 0x2b5);

// 0x71007d0c10
void Unk_7d0c10_set(Unk_7d0c10* self) {
    self->field_2b5 = self->field_2b5 | 0x40;
}

struct Unk_7d3a50 {
    u8 _0[0x2b5];
    u8 field_2b5;
};
PKMN_OFFSET_ASSERT(Unk_7d3a50, field_2b5, 0x2b5);

// 0x71007d3a50
u32 Unk_7d3a50_get(const Unk_7d3a50* self) {
    return (self->field_2b5 >> 5) & 1;
}

struct Unk_7d72b0 {
    u8 _0[0x340];
    u64 field_340;
};
PKMN_OFFSET_ASSERT(Unk_7d72b0, field_340, 0x340);

// 0x71007d72b0
u64 Unk_7d72b0_getField340(const Unk_7d72b0* self) {
    return self->field_340;
}

// 0x71007dfda0
u32 Unk_7dfda0_get() {
    return 1;
}

struct Unk_7dfdb0 {
    u8 _0[0x2a6];
    u8 field_2a6;
};
PKMN_OFFSET_ASSERT(Unk_7dfdb0, field_2a6, 0x2a6);

// 0x71007dfdb0
u8 Unk_7dfdb0_getField2a6(const Unk_7dfdb0* self) {
    return self->field_2a6;
}

struct Unk_7dfdc0 {
    u8 _0[0x230];
    u64 field_230;
};
PKMN_OFFSET_ASSERT(Unk_7dfdc0, field_230, 0x230);

// 0x71007dfdc0
u64 Unk_7dfdc0_getField230(const Unk_7dfdc0* self) {
    return self->field_230;
}
