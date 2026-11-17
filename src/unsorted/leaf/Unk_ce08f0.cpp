// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ce08f0 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_ce08f0, field_68, 0x68);

// 0x7100ce08f0
bool Unk_ce08f0_check(const Unk_ce08f0* self) {
    return self->field_68 != 0;
}
