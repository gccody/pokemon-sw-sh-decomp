// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71012a61d0
void Unk_12a61d0_update() {}

struct Unk_12a61e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12a61e0_arg1, field_0, 0x0);

struct Unk_12a61e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12a61e0, field_0, 0x0);

// 0x71012a61e0
void Unk_12a61e0_set(const Unk_12a61e0* self, Unk_12a61e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12a61f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12a61f0_arg1, field_0, 0x0);

struct Unk_12a61f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12a61f0, field_0, 0x0);

// 0x71012a61f0
void Unk_12a61f0_set(const Unk_12a61f0* self, Unk_12a61f0_arg1* value) {
    value->field_0 = self->field_0;
}
