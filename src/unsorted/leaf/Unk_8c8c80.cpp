// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8c8c80 {
    u8 _0[0xf8];
    u8 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_8c8c80, field_f8, 0xf8);

// 0x71008c8c80
u8* Unk_8c8c80_getFieldf8Ptr(Unk_8c8c80* self) {
    return &self->field_f8;
}
