// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d13290 {
    u8 _0[0xaa0];
    u64 field_aa0;
};
PKMN_OFFSET_ASSERT(Unk_d13290, field_aa0, 0xaa0);

void Unk_68d9b0(u64);

// 0x7100d13290
void Unk_d13290_call(const Unk_d13290* self) {
    Unk_68d9b0(self->field_aa0);
}
