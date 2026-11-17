// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_69fb90 {
    u8 _0[0x378];
    u8 field_378;
};
PKMN_OFFSET_ASSERT(Unk_69fb90, field_378, 0x378);

// 0x710069fb90
void Unk_69fb90_set(Unk_69fb90* self) {
    self->field_378 = 1;
}
