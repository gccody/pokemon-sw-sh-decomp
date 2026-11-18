// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710126dfa0
void Unk_126dfa0_update() {}

struct Unk_126dfb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126dfb0_arg1, field_0, 0x0);

struct Unk_126dfb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126dfb0, field_0, 0x0);

// 0x710126dfb0
void Unk_126dfb0_set(const Unk_126dfb0* self, Unk_126dfb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_126dfc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126dfc0_arg1, field_0, 0x0);

struct Unk_126dfc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126dfc0, field_0, 0x0);

// 0x710126dfc0
void Unk_126dfc0_set(const Unk_126dfc0* self, Unk_126dfc0_arg1* value) {
    value->field_0 = self->field_0;
}
