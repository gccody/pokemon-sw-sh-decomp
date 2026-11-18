// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100a6e120
void Unk_a6e120_update() {}

struct Unk_a6e130 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6e130, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6e130, field_8, 0x8);

// 0x7100a6e130
void Unk_a6e130_set(const Unk_a6e130* self, Unk_a6e130* value) {
    *value = *self;
}

struct Unk_a6e140 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_a6e140, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a6e140, field_8, 0x8);

// 0x7100a6e140
void Unk_a6e140_set(const Unk_a6e140* self, Unk_a6e140* value) {
    *value = *self;
}
