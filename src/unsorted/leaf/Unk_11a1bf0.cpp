// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011a1bf0
void Unk_11a1bf0_update() {}

struct Unk_11a1c00 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a1c00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a1c00, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a1c00, field_10, 0x10);

// 0x71011a1c00
void Unk_11a1c00_set(const Unk_11a1c00* self, Unk_11a1c00* value) {
    *value = *self;
}

struct Unk_11a1c20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a1c20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a1c20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a1c20, field_10, 0x10);

// 0x71011a1c20
void Unk_11a1c20_set(const Unk_11a1c20* self, Unk_11a1c20* value) {
    *value = *self;
}

// 0x71011a2c80
void Unk_11a2c80_update() {}

struct Unk_11a2c90 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a2c90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a2c90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a2c90, field_10, 0x10);

// 0x71011a2c90
void Unk_11a2c90_set(const Unk_11a2c90* self, Unk_11a2c90* value) {
    *value = *self;
}

struct Unk_11a2cb0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a2cb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a2cb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a2cb0, field_10, 0x10);

// 0x71011a2cb0
void Unk_11a2cb0_set(const Unk_11a2cb0* self, Unk_11a2cb0* value) {
    *value = *self;
}

// 0x71011a2d00
void Unk_11a2d00_update() {}

struct Unk_11a2d10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a2d10_arg1, field_0, 0x0);

struct Unk_11a2d10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a2d10, field_0, 0x0);

// 0x71011a2d10
void Unk_11a2d10_set(const Unk_11a2d10* self, Unk_11a2d10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11a2d20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a2d20_arg1, field_0, 0x0);

struct Unk_11a2d20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a2d20, field_0, 0x0);

// 0x71011a2d20
void Unk_11a2d20_set(const Unk_11a2d20* self, Unk_11a2d20_arg1* value) {
    value->field_0 = self->field_0;
}
