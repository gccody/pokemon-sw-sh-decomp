// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_55f1c0 {
    u8 _0[0x30];
    u64 field_30;
    u8 _38[0x2e8];
    u32 field_320;
};
PKMN_OFFSET_ASSERT(Unk_55f1c0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_55f1c0, field_320, 0x320);

// 0x710055f1c0
u32 Unk_55f1c0_update(Unk_55f1c0* self, u64 value) {
    self->field_30 = value;
    self->field_320 = 0x2b0e;
    return 1;
}
