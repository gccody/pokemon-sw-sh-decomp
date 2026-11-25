// Scope: common
// Accessors of an object of game/unk_133d350 (the one the accessors of
// src/unsorted/leaf/Unk_1361f80.cpp around 0x710137bba0 read): a counter at
// +0x280 and flags at +0x68 and +0x198. Placeholder names: rename once the
// class is known.
#include <types.h>

struct Unk_137bbf0 {
    u8 _0[0x280];
    s8 field_280;
};
PKMN_OFFSET_ASSERT(Unk_137bbf0, field_280, 0x280);

// 0x710137bbf0: count up, unless the counter is negative.
s8 Unk_137bbf0_update(Unk_137bbf0* self) {
    if (self->field_280 >= 0)
        self->field_280++;
    return self->field_280;
}

// The flags at +0x68: bits 5 and 6 are set when a flag is off (0x710137bc60
// and 0x710137bc90 test them).
struct Unk_137bc70_Flags {
    u32 _0 : 5;
    u32 field_5 : 1;
    u32 field_6 : 1;
    u32 _7 : 25;
};
PKMN_SIZE_ASSERT(Unk_137bc70_Flags, 0x4);

struct Unk_137bc70 {
    u8 _0[0x68];
    Unk_137bc70_Flags field_68;
};
PKMN_OFFSET_ASSERT(Unk_137bc70, field_68, 0x68);

// 0x710137bc70
void Unk_137bc70_set(Unk_137bc70* self, bool value) {
    self->field_68.field_5 = !value;
}

struct Unk_137bca0 {
    u8 _0[0x68];
    Unk_137bc70_Flags field_68;
};
PKMN_OFFSET_ASSERT(Unk_137bca0, field_68, 0x68);

// 0x710137bca0
void Unk_137bca0_set(Unk_137bca0* self, bool value) {
    self->field_68.field_6 = !value;
}

struct Unk_137bcc0 {
    u8 _0[0x198];
    u32 field_198;
};
PKMN_OFFSET_ASSERT(Unk_137bcc0, field_198, 0x198);

// 0x710137bcc0: a bit of field_198.
bool Unk_137bcc0_check(const Unk_137bcc0* self, u32 bit) {
    if (bit < 32)
        return (self->field_198 & (1u << bit)) != 0;
    return false;
}

struct Unk_137bcf0 {
    u8 _0[0x198];
    u32 field_198;
};
PKMN_OFFSET_ASSERT(Unk_137bcf0, field_198, 0x198);

// 0x710137bcf0
void Unk_137bcf0_set(Unk_137bcf0* self, u32 bit, bool value) {
    if (bit >= 32)
        return;
    if (value)
        self->field_198 |= 1u << bit;
    else
        self->field_198 &= ~(1u << bit);
}
