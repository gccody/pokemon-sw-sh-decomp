// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11e4c40 {
    u8 _0[0x114];
    f32 field_114;
};
PKMN_OFFSET_ASSERT(Unk_11e4c40, field_114, 0x114);

// 0x71011e4c40
void Unk_11e4c40_setField114(Unk_11e4c40* self, f32 value) {
    self->field_114 = value;
}
