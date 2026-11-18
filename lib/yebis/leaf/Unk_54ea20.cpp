// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_54ea20 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_54ea20, field_20, 0x20);

// 0x710054ea20
u32 Unk_54ea20_update(Unk_54ea20* self, u32 value) {
    self->field_20 = value;
    return 1;
}
