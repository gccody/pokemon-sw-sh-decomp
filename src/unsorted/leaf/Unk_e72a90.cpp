// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e72a90
void Unk_e72a90_update() {}

struct Unk_e72aa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e72aa0_arg1, field_0, 0x0);

struct Unk_e72aa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e72aa0, field_0, 0x0);

// 0x7100e72aa0
void Unk_e72aa0_set(const Unk_e72aa0* self, Unk_e72aa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e72ab0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e72ab0_arg1, field_0, 0x0);

struct Unk_e72ab0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e72ab0, field_0, 0x0);

// 0x7100e72ab0
void Unk_e72ab0_set(const Unk_e72ab0* self, Unk_e72ab0_arg1* value) {
    value->field_0 = self->field_0;
}
