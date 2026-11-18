// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101266440
void Unk_1266440_update() {}

struct Unk_1266450 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1266450, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1266450, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1266450, field_10, 0x10);

// 0x7101266450
void Unk_1266450_set(const Unk_1266450* self, Unk_1266450* value) {
    *value = *self;
}

struct Unk_1266470 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1266470, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1266470, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1266470, field_10, 0x10);

// 0x7101266470
void Unk_1266470_set(const Unk_1266470* self, Unk_1266470* value) {
    *value = *self;
}
