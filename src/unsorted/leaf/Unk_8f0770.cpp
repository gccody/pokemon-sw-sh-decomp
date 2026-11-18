// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71008f0770
void Unk_8f0770_update() {}

struct Unk_8f0780_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8f0780_arg1, field_0, 0x0);

struct Unk_8f0780 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8f0780, field_0, 0x0);

// 0x71008f0780
void Unk_8f0780_set(const Unk_8f0780* self, Unk_8f0780_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8f0790_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8f0790_arg1, field_0, 0x0);

struct Unk_8f0790 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8f0790, field_0, 0x0);

// 0x71008f0790
void Unk_8f0790_set(const Unk_8f0790* self, Unk_8f0790_arg1* value) {
    value->field_0 = self->field_0;
}
