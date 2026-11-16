// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a89c0 {
    u8 _0[0x2c];
    u8 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_8a89c0, field_2c, 0x2c);

// 0x71008a89c0
u8 Unk_8a89c0_getField2c(const Unk_8a89c0* self) {
    return self->field_2c;
}
