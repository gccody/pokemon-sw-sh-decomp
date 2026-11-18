// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_158c0f0_arg1 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x1];
    u16 field_a;
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_158c0f0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_158c0f0_arg1, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_158c0f0_arg1, field_c, 0xc);

struct Unk_158c0f0 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x1];
    u16 field_a;
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_158c0f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_158c0f0, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_158c0f0, field_c, 0xc);

// 0x710158c0f0
void Unk_158c0f0_set(Unk_158c0f0* self, const Unk_158c0f0_arg1* value) {
    self->field_8 = value->field_8;
    self->field_a = value->field_a;
    self->field_c = value->field_c;
}

struct Unk_158c1f0_arg1 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x7];
    u64 field_10;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_158c1f0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_158c1f0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158c1f0_arg1, field_18, 0x18);

struct Unk_158c1f0 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x7];
    u64 field_10;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_158c1f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_158c1f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158c1f0, field_18, 0x18);

// 0x710158c1f0
void Unk_158c1f0_set(Unk_158c1f0* self, const Unk_158c1f0_arg1* value) {
    self->field_8 = value->field_8;
    self->field_10 = value->field_10;
    self->field_18 = value->field_18;
}

// 0x710158cf90
void Unk_158cf90_update() {
}

// 0x710158cfa0
void Unk_158cfa0_update() {
}

// 0x710158d020
void Unk_158d020_update() {
}

// 0x710158d3b0
void Unk_158d3b0_update() {
}

// 0x710158d8a0
void Unk_158d8a0_update() {
}

// 0x710158da60
void Unk_158da60_update() {
}

// 0x710158dd30
void Unk_158dd30_update() {
}

// 0x710158e030
void Unk_158e030_update() {
}

// 0x710158e040
void Unk_158e040_update() {
}

// 0x710158e480
void Unk_158e480_update() {
}

// 0x710158e490
void Unk_158e490_update() {
}

// 0x710158e610
void Unk_158e610_update() {
}

// 0x710158e9d0
void Unk_158e9d0_update() {
}

// 0x710158e9e0
void Unk_158e9e0_update() {
}

// 0x710158e9f0
void Unk_158e9f0_update() {
}

// 0x710158ea00
void Unk_158ea00_update() {
}
