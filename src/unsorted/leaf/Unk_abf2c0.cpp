// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_abf2c0 {
    u8 _0[0x92];
    u8 field_92;
};
PKMN_OFFSET_ASSERT(Unk_abf2c0, field_92, 0x92);

// 0x7100abf2c0
u8 Unk_abf2c0_getField92(const Unk_abf2c0* self) {
    return self->field_92;
}
