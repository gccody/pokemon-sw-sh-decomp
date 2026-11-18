// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011f7970
void Unk_11f7970_update() {}

struct Unk_11f7980_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f7980_arg1, field_0, 0x0);

struct Unk_11f7980 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f7980, field_0, 0x0);

// 0x71011f7980
void Unk_11f7980_set(const Unk_11f7980* self, Unk_11f7980_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f7990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f7990_arg1, field_0, 0x0);

struct Unk_11f7990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f7990, field_0, 0x0);

// 0x71011f7990
void Unk_11f7990_set(const Unk_11f7990* self, Unk_11f7990_arg1* value) {
    value->field_0 = self->field_0;
}
