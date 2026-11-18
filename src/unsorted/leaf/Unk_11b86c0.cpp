// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011b86c0
void Unk_11b86c0_update() {}

struct Unk_11b86d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11b86d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11b86d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11b86d0, field_10, 0x10);

// 0x71011b86d0
void Unk_11b86d0_set(const Unk_11b86d0* self, Unk_11b86d0* value) {
    *value = *self;
}

struct Unk_11b86f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11b86f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11b86f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11b86f0, field_10, 0x10);

// 0x71011b86f0
void Unk_11b86f0_set(const Unk_11b86f0* self, Unk_11b86f0* value) {
    *value = *self;
}
