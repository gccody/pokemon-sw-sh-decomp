// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1047a00 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1047a00, field_68, 0x68);

// 0x7101047a00
void Unk_1047a00_clearField68(Unk_1047a00* self) {
    self->field_68 = 0;
}
