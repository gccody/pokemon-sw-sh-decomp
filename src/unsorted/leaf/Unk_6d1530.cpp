// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6d1530 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_6d1530, field_a0, 0xa0);

// 0x71006d1530
void Unk_6d1530_setFielda0(Unk_6d1530* self, u64 value) {
    self->field_a0 = value;
}
