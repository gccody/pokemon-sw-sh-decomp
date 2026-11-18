// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_4a0530 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_4a0530, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_4a0530, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_4a0530, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_4a0530, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_4a0530, field_20, 0x20);

// 0x71004a0530
void Unk_4a0530_set(Unk_4a0530* self) {
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
}
