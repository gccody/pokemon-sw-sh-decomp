// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_55b100 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_55b100, field_28, 0x28);

// 0x710055b100
u32 Unk_55b100_update(Unk_55b100* self, u64 value) {
    self->field_28 = value;
    return 1;
}
