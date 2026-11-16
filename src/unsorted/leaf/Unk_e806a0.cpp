// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e806a0 {
    u8 _0[0x5a0];
    u64 field_5a0;
};
PKMN_OFFSET_ASSERT(Unk_e806a0, field_5a0, 0x5a0);

// 0x7100e806a0
u64 Unk_e806a0_getField5a0(const Unk_e806a0* self) {
    return self->field_5a0;
}

// 0x7100e87c40
void Unk_e87c40() {}

// 0x7100e88350
void Unk_e88350() {}
