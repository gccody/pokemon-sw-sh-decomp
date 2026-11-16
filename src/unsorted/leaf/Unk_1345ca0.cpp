// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1345ca0 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1345ca0, field_60, 0x60);

// 0x7101345ca0
u8* Unk_1345ca0_getField60Ptr(Unk_1345ca0* self) {
    return &self->field_60;
}

struct Unk_1345d00 {
    u8 _0[0x228];
    u64 field_228;
};
PKMN_OFFSET_ASSERT(Unk_1345d00, field_228, 0x228);

// 0x7101345d00
void Unk_1345d00_setField228(Unk_1345d00* self, u64 value) {
    self->field_228 = value;
}

struct Unk_1345d10 {
    u8 _0[0x230];
    u8 field_230;
};
PKMN_OFFSET_ASSERT(Unk_1345d10, field_230, 0x230);

// 0x7101345d10
u8* Unk_1345d10_getField230Ptr(Unk_1345d10* self) {
    return &self->field_230;
}

struct Unk_1354890 {
    u8 _0[0x56e];
    u8 field_56e;
};
PKMN_OFFSET_ASSERT(Unk_1354890, field_56e, 0x56e);

// 0x7101354890
u8 Unk_1354890_getField56e(const Unk_1354890* self) {
    return self->field_56e;
}

struct Unk_13548a0 {
    u8 _0[0x590];
    u16 field_590;
};
PKMN_OFFSET_ASSERT(Unk_13548a0, field_590, 0x590);

// 0x71013548a0
void Unk_13548a0_setField590(Unk_13548a0* self, u16 value) {
    self->field_590 = value;
}

struct Unk_13548b0 {
    u8 _0[0x590];
    u16 field_590;
};
PKMN_OFFSET_ASSERT(Unk_13548b0, field_590, 0x590);

// 0x71013548b0
u16 Unk_13548b0_getField590(const Unk_13548b0* self) {
    return self->field_590;
}

struct Unk_1357f20 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_1357f20, field_150, 0x150);

// 0x7101357f20
u32 Unk_1357f20_getField150(const Unk_1357f20* self) {
    return self->field_150;
}
