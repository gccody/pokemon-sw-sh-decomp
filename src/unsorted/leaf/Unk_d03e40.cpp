// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100d03e40
void Unk_d03e40_update() {}

struct Unk_d03e50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d03e50_arg1, field_0, 0x0);

struct Unk_d03e50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d03e50, field_0, 0x0);

// 0x7100d03e50
void Unk_d03e50_set(const Unk_d03e50* self, Unk_d03e50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d03e60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d03e60_arg1, field_0, 0x0);

struct Unk_d03e60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d03e60, field_0, 0x0);

// 0x7100d03e60
void Unk_d03e60_set(const Unk_d03e60* self, Unk_d03e60_arg1* value) {
    value->field_0 = self->field_0;
}
