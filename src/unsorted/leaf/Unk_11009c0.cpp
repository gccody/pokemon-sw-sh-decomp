// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11009c0 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_11009c0, field_78, 0x78);

// 0x71011009c0
void Unk_11009c0_clearField78(Unk_11009c0* self) {
    self->field_78 = 0;
}
