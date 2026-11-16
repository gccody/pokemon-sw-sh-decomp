// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11492a0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_11492a0, field_70, 0x70);

// 0x71011492a0
void Unk_11492a0_setField70(Unk_11492a0* self, u64 value) {
    self->field_70 = value;
}
