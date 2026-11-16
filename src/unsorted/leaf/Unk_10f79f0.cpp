// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10f79f0 {
    u8 _0[0x1c8];
    u8 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_10f79f0, field_1c8, 0x1c8);

// 0x71010f79f0
void Unk_10f79f0_clearField1c8(Unk_10f79f0* self) {
    self->field_1c8 = 0;
}
