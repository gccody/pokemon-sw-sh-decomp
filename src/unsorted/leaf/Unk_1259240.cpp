// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1259240 {
    u8 _0[0xb80];
    u8 field_b80;
};
PKMN_OFFSET_ASSERT(Unk_1259240, field_b80, 0xb80);

// 0x7101259240
u8 Unk_1259240_getFieldb80(const Unk_1259240* self) {
    return self->field_b80;
}
