// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011967f0
void Unk_11967f0_update() {}

struct Unk_1196800 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1196800, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1196800, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1196800, field_10, 0x10);

// 0x7101196800
void Unk_1196800_set(const Unk_1196800* self, Unk_1196800* value) {
    *value = *self;
}

struct Unk_1196820 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1196820, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1196820, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1196820, field_10, 0x10);

// 0x7101196820
void Unk_1196820_set(const Unk_1196820* self, Unk_1196820* value) {
    *value = *self;
}

// 0x7101196980
void Unk_1196980_update() {}

struct Unk_1196990 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1196990, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1196990, field_8, 0x8);

// 0x7101196990
void Unk_1196990_set(const Unk_1196990* self, Unk_1196990* value) {
    *value = *self;
}

struct Unk_11969a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11969a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11969a0, field_8, 0x8);

// 0x71011969a0
void Unk_11969a0_set(const Unk_11969a0* self, Unk_11969a0* value) {
    *value = *self;
}

void Unk_11969d0();

// 0x71011969b0
void Unk_11969b0_call() {
    Unk_11969d0();
}

// 0x71011969c0
void Unk_11969c0_update() {}
