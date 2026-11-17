// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f248d0_5d8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_f248d0_5d8, field_58, 0x58);

struct Unk_f248d0 {
    u8 _0[0x5d8];
    Unk_f248d0_5d8* field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_f248d0, field_5d8, 0x5d8);

// 0x7100f248d0
void Unk_f248d0_set(const Unk_f248d0* self, bool value) {
    self->field_5d8->field_58 = (self->field_5d8->field_58 & 0xfffffffe) | (value);
}
