// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6aede0 {
    u8 _0[0x219];
    u8 field_219;
};
PKMN_OFFSET_ASSERT(Unk_6aede0, field_219, 0x219);

// 0x71006aede0
u8 Unk_6aede0_getField219(const Unk_6aede0* self) {
    return self->field_219;
}
