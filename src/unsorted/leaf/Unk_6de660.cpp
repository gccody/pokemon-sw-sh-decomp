// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6de660 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6de660, field_b0, 0xb0);

// 0x71006de660
u8* Unk_6de660_getFieldb0Ptr(Unk_6de660* self) {
    return &self->field_b0;
}
