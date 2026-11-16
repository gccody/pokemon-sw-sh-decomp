// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11802d0 {
    u8 _0[0x410];
    u8 field_410;
};
PKMN_OFFSET_ASSERT(Unk_11802d0, field_410, 0x410);

// 0x71011802d0
u8 Unk_11802d0_getField410(const Unk_11802d0* self) {
    return self->field_410;
}
