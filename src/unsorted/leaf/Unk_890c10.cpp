// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_890c10_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_890c10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_890c10_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_890c10_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_890c10_arg1, field_18, 0x18);

struct Unk_890c10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_890c10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_890c10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_890c10, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_890c10, field_18, 0x18);

// 0x7100890c10
void Unk_890c10_set(Unk_890c10* self, const Unk_890c10_arg1* value) {
    self->field_0 = value->field_0;
    self->field_8 = value->field_8;
    self->field_10 = value->field_10;
    self->field_18 = value->field_18;
}
