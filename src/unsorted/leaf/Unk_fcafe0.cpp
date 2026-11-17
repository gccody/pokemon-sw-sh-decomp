// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fcafe0 {
    u8 _0[0xe0];
    u32 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_fcafe0, field_e0, 0xe0);

// 0x7100fcafe0
bool Unk_fcafe0_check(const Unk_fcafe0* self) {
    return self->field_e0 == 5;
}
