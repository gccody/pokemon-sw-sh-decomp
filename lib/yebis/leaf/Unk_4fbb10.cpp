// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_4fbb10 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_4fbb10, field_28, 0x28);

// 0x71004fbb10
u32 Unk_4fbb10_update(Unk_4fbb10* self, u64 value) {
    self->field_28 = value;
    return 1;
}
