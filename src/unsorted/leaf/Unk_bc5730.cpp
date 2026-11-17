// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_bc5730 {
    u8 _0[0x2c0];
    u32 field_2c0;
    u32 field_2c4;
    u8 _2c8[0x58];
    u32 field_320;
};
PKMN_OFFSET_ASSERT(Unk_bc5730, field_2c0, 0x2c0);
PKMN_OFFSET_ASSERT(Unk_bc5730, field_2c4, 0x2c4);
PKMN_OFFSET_ASSERT(Unk_bc5730, field_320, 0x320);

// 0x7100bc5730
void Unk_bc5730_set(Unk_bc5730* self) {
    self->field_2c0 = 5;
    self->field_2c4 = self->field_320 == 2;
}
