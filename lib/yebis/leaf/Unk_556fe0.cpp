// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_556fe0 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_556fe0, field_20, 0x20);

// 0x7100556fe0
u32 Unk_556fe0_update(Unk_556fe0* self, u32 value) {
    self->field_20 = value;
    return 1;
}
