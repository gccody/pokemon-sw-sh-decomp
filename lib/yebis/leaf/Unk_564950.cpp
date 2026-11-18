// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_564950 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_564950, field_28, 0x28);

// 0x7100564950
u32 Unk_564950_update(Unk_564950* self, u64 value) {
    self->field_28 = value;
    return 1;
}
