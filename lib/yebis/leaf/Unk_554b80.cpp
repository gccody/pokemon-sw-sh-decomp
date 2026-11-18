// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_554b80 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_554b80, field_28, 0x28);

// 0x7100554b80
u32 Unk_554b80_update(Unk_554b80* self, u64 value) {
    self->field_28 = value;
    return 1;
}
