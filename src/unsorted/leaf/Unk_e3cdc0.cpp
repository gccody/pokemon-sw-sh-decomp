// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e3cdc0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e3cdc0, field_60, 0x60);

// 0x7100e3cdc0
void Unk_e3cdc0_clearField60(Unk_e3cdc0* self) {
    self->field_60 = 0;
}
