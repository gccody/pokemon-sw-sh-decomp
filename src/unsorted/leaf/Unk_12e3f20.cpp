// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12e3f20_5e0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_12e3f20_5e0, field_58, 0x58);

struct Unk_12e3f20 {
    u8 _0[0x5e0];
    Unk_12e3f20_5e0* field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_12e3f20, field_5e0, 0x5e0);

// 0x71012e3f20
void Unk_12e3f20_set(const Unk_12e3f20* self, bool value) {
    self->field_5e0->field_58 = (self->field_5e0->field_58 & 0xfffffffe) | (value);
}
