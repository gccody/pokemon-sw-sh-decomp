// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71016c1b80
void Unk_16c1b80_update() {
}

struct Unk_16c1b90 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16c1b90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_16c1b90, field_8, 0x8);

// 0x71016c1b90
void Unk_16c1b90_set(Unk_16c1b90* self) {
    self->field_0 = 0;
    self->field_8 = 0;
}

// 0x71016c1ba0
void Unk_16c1ba0_update() {
}

struct Unk_16c1c00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_16c1c00_arg1, field_0, 0x0);

struct Unk_16c1c00 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16c1c00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_16c1c00, field_8, 0x8);

// 0x71016c1c00
void Unk_16c1c00_set(Unk_16c1c00* self, const Unk_16c1c00_arg1* value) {
    self->field_0 = value->field_0;
    self->field_8 = 1;
}

struct Unk_16c1c20 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16c1c20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_16c1c20, field_8, 0x8);

// 0x71016c1c20
void Unk_16c1c20_set(Unk_16c1c20* self) {
    self->field_8 = 0;
    self->field_0 = 0;
}
