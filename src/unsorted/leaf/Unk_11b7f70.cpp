// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011b7f70
void Unk_11b7f70_update() {}

struct Unk_11b7f80 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11b7f80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11b7f80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11b7f80, field_10, 0x10);

// 0x71011b7f80
void Unk_11b7f80_set(const Unk_11b7f80* self, Unk_11b7f80* value) {
    *value = *self;
}

struct Unk_11b7fa0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11b7fa0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11b7fa0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11b7fa0, field_10, 0x10);

// 0x71011b7fa0
void Unk_11b7fa0_set(const Unk_11b7fa0* self, Unk_11b7fa0* value) {
    *value = *self;
}
