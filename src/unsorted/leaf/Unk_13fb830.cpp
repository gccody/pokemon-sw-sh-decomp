// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_13fb830 {
    u8 _0[0x60];
    u64 field_60;
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_13fb830, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_13fb830, field_68, 0x68);

// 0x71013fb830
void Unk_13fb830_set(Unk_13fb830* self) {
    self->field_68 = self->field_60;
}
