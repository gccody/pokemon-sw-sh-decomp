// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_153bdb0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_153bdb0, field_60, 0x60);

// 0x710153bdb0
u64 Unk_153bdb0_getField60(const Unk_153bdb0* self) {
    return self->field_60;
}

struct Unk_153bdc0 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_153bdc0, field_88, 0x88);

// 0x710153bdc0
u8* Unk_153bdc0_getField88Ptr(Unk_153bdc0* self) {
    return &self->field_88;
}

struct Unk_153bdd0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_153bdd0, field_6c, 0x6c);

// 0x710153bdd0
void Unk_153bdd0_setField6c(Unk_153bdd0* self, u32 value) {
    self->field_6c = value;
}

struct Unk_153c410 {
    u8 _0[0x780];
    u64 field_780;
};
PKMN_OFFSET_ASSERT(Unk_153c410, field_780, 0x780);

// 0x710153c410
void Unk_153c410_setField780(Unk_153c410* self, u64 value) {
    self->field_780 = value;
}

struct Unk_15407f0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_15407f0, field_5cc, 0x5cc);

// 0x71015407f0
u32 Unk_15407f0_getField5cc(const Unk_15407f0* self) {
    return self->field_5cc;
}

struct Unk_1540800 {
    u8 _0[0x5d8];
    u64 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_1540800, field_5d8, 0x5d8);

// 0x7101540800
void Unk_1540800_setField5d8(Unk_1540800* self, u64 value) {
    self->field_5d8 = value;
}
