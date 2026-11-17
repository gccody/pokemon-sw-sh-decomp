// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1048150 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1048150, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1048150, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1048150, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1048150, field_18, 0x18);

// 0x7101048150
void Unk_1048150_set(Unk_1048150* self) {
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}
