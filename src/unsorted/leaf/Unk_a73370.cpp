// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100a73370
void Unk_a73370_update() {}

struct Unk_a73380 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_a73380, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a73380, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a73380, field_10, 0x10);

// 0x7100a73380
void Unk_a73380_set(const Unk_a73380* self, Unk_a73380* value) {
    *value = *self;
}

struct Unk_a733a0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_a733a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a733a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a733a0, field_10, 0x10);

// 0x7100a733a0
void Unk_a733a0_set(const Unk_a733a0* self, Unk_a733a0* value) {
    *value = *self;
}

// 0x7100a73430
void Unk_a73430_update() {}

struct Unk_a73440_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a73440_arg1, field_0, 0x0);

struct Unk_a73440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a73440, field_0, 0x0);

// 0x7100a73440
void Unk_a73440_set(const Unk_a73440* self, Unk_a73440_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_a73450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a73450_arg1, field_0, 0x0);

struct Unk_a73450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_a73450, field_0, 0x0);

// 0x7100a73450
void Unk_a73450_set(const Unk_a73450* self, Unk_a73450_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100a75fe0
void Unk_a75fe0_update() {}

// 0x7100a75ff0
void Unk_a75ff0_update() {}

// 0x7100a76000
void Unk_a76000_update() {}

// 0x7100a76010
void Unk_a76010_update() {}
