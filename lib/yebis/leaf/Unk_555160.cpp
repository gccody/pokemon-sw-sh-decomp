// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_555160 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_555160, field_20, 0x20);

// 0x7100555160
u32 Unk_555160_update(Unk_555160* self, u32 value) {
    self->field_20 = value;
    return 1;
}
