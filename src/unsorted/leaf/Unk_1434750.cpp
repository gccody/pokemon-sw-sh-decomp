// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1434750 {
    u8 _0[0x50];
    u32 field_50;
    u16 field_54;
};
PKMN_OFFSET_ASSERT(Unk_1434750, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_1434750, field_54, 0x54);

// 0x7101434750
void Unk_1434750_set(Unk_1434750* self) {
    self->field_54 = 0;
    self->field_50 = 0;
}
