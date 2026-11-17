// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1509aa0_5f8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1509aa0_5f8, field_58, 0x58);

struct Unk_1509aa0 {
    u8 _0[0x5f8];
    Unk_1509aa0_5f8* field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_1509aa0, field_5f8, 0x5f8);

// 0x7101509aa0
void Unk_1509aa0_set(const Unk_1509aa0* self) {
    self->field_5f8->field_58 = self->field_5f8->field_58 | 1;
}
