// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f9df80 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_f9df80, field_70, 0x70);

// 0x7100f9df80
u64 Unk_f9df80_getField70(const Unk_f9df80* self) {
    return self->field_70;
}
