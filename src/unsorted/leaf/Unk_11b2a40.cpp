// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11b2a40 {
    u8 _0[0x80];
    u64 field_80;
    u8 _88[0x58];
    u8 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_11b2a40, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_11b2a40, field_e0, 0xe0);

// 0x71011b2a40
bool Unk_11b2a40_check(const Unk_11b2a40* self) {
    if (self->field_e0 == 0) {
        return false;
    }
    return self->field_80 != 0;
}

// 0x71011b3bb0
void Unk_11b3bb0_update() {}

struct Unk_11b3bc0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11b3bc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11b3bc0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11b3bc0, field_10, 0x10);

// 0x71011b3bc0
void Unk_11b3bc0_set(const Unk_11b3bc0* self, Unk_11b3bc0* value) {
    *value = *self;
}

struct Unk_11b3be0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11b3be0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11b3be0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11b3be0, field_10, 0x10);

// 0x71011b3be0
void Unk_11b3be0_set(const Unk_11b3be0* self, Unk_11b3be0* value) {
    *value = *self;
}

// 0x71011b4f00
void Unk_11b4f00_update() {}

struct Unk_11b4f10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11b4f10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11b4f10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11b4f10, field_10, 0x10);

// 0x71011b4f10
void Unk_11b4f10_set(const Unk_11b4f10* self, Unk_11b4f10* value) {
    *value = *self;
}

struct Unk_11b4f30 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11b4f30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11b4f30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11b4f30, field_10, 0x10);

// 0x71011b4f30
void Unk_11b4f30_set(const Unk_11b4f30* self, Unk_11b4f30* value) {
    *value = *self;
}
