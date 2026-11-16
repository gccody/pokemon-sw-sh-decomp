// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_13a7fd0 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13a7fd0, field_60, 0x60);

// 0x71013a7fd0
u8* Unk_13a7fd0_getField60Ptr(Unk_13a7fd0* self) {
    return &self->field_60;
}
