// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e66dd0 {
    u8 _0[0x85];
    u8 field_85;
};
PKMN_OFFSET_ASSERT(Unk_e66dd0, field_85, 0x85);

// 0x7100e66dd0
u8 Unk_e66dd0_getField85(const Unk_e66dd0* self) {
    return self->field_85;
}
