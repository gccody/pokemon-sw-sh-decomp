// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100b86230
void Unk_b86230_update() {}

struct Unk_b864c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_b864c0_arg1, field_0, 0x0);

struct Unk_b864c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_b864c0, field_0, 0x0);

// 0x7100b864c0
void Unk_b864c0_set(const Unk_b864c0* self, Unk_b864c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_b864d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_b864d0_arg1, field_0, 0x0);

struct Unk_b864d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_b864d0, field_0, 0x0);

// 0x7100b864d0
void Unk_b864d0_set(const Unk_b864d0* self, Unk_b864d0_arg1* value) {
    value->field_0 = self->field_0;
}
