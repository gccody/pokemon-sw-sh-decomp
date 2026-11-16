// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e9ddc0 {
    u8 _0[0x89];
    u8 field_89;
};
PKMN_OFFSET_ASSERT(Unk_e9ddc0, field_89, 0x89);

// 0x7100e9ddc0
u8 Unk_e9ddc0_getField89(const Unk_e9ddc0* self) {
    return self->field_89;
}
