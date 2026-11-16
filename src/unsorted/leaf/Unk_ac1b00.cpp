// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ac1b00 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_ac1b00, field_60, 0x60);

// 0x7100ac1b00
u32 Unk_ac1b00_getField60(const Unk_ac1b00* self) {
    return self->field_60;
}
