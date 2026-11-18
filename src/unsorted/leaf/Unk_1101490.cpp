// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101101490
void Unk_1101490_update() {}

struct Unk_11014a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11014a0_arg1, field_0, 0x0);

struct Unk_11014a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11014a0, field_0, 0x0);

// 0x71011014a0
void Unk_11014a0_set(const Unk_11014a0* self, Unk_11014a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11014b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11014b0_arg1, field_0, 0x0);

struct Unk_11014b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11014b0, field_0, 0x0);

// 0x71011014b0
void Unk_11014b0_set(const Unk_11014b0* self, Unk_11014b0_arg1* value) {
    value->field_0 = self->field_0;
}
