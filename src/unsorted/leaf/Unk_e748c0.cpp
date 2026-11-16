// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e748c0 {
    u8 _0[0x700];
    u64 field_700;
};
PKMN_OFFSET_ASSERT(Unk_e748c0, field_700, 0x700);

// 0x7100e748c0
void Unk_e748c0_setField700(Unk_e748c0* self, u64 value) {
    self->field_700 = value;
}

// 0x7100e76a20
u64 Unk_e76a20() {
    return 0;
}
