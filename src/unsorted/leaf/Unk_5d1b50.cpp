// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5d1b50 {
    u8 _0[0x130];
    u64 field_130;
};
PKMN_OFFSET_ASSERT(Unk_5d1b50, field_130, 0x130);

// 0x71005d1b50
void Unk_5d1b50_set(Unk_5d1b50* self) {
    self->field_130 = self->field_130 | 0x10;
}
