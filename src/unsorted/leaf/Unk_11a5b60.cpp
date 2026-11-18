// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011a5b60
void Unk_11a5b60_update() {}

struct Unk_11a5b70 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a5b70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a5b70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a5b70, field_10, 0x10);

// 0x71011a5b70
void Unk_11a5b70_set(const Unk_11a5b70* self, Unk_11a5b70* value) {
    *value = *self;
}

struct Unk_11a5b90 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a5b90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a5b90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a5b90, field_10, 0x10);

// 0x71011a5b90
void Unk_11a5b90_set(const Unk_11a5b90* self, Unk_11a5b90* value) {
    *value = *self;
}
