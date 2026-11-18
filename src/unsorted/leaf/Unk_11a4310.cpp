// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011a4310
void Unk_11a4310_update() {}

struct Unk_11a4320 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a4320, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a4320, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a4320, field_10, 0x10);

// 0x71011a4320
void Unk_11a4320_set(const Unk_11a4320* self, Unk_11a4320* value) {
    *value = *self;
}

struct Unk_11a4340 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a4340, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a4340, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a4340, field_10, 0x10);

// 0x71011a4340
void Unk_11a4340_set(const Unk_11a4340* self, Unk_11a4340* value) {
    *value = *self;
}

// 0x71011a50c0
void Unk_11a50c0_update() {}

struct Unk_11a50d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a50d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a50d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a50d0, field_10, 0x10);

// 0x71011a50d0
void Unk_11a50d0_set(const Unk_11a50d0* self, Unk_11a50d0* value) {
    *value = *self;
}

struct Unk_11a50f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a50f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a50f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a50f0, field_10, 0x10);

// 0x71011a50f0
void Unk_11a50f0_set(const Unk_11a50f0* self, Unk_11a50f0* value) {
    *value = *self;
}

// 0x71011a5180
void Unk_11a5180_update() {}

struct Unk_11a5190_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a5190_arg1, field_0, 0x0);

struct Unk_11a5190 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a5190, field_0, 0x0);

// 0x71011a5190
void Unk_11a5190_set(const Unk_11a5190* self, Unk_11a5190_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11a51a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a51a0_arg1, field_0, 0x0);

struct Unk_11a51a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a51a0, field_0, 0x0);

// 0x71011a51a0
void Unk_11a51a0_set(const Unk_11a51a0* self, Unk_11a51a0_arg1* value) {
    value->field_0 = self->field_0;
}
