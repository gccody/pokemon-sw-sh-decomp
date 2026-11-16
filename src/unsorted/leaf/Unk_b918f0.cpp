// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_b918f0 {
    u8 _0[0x1d8];
    u8 field_1d8;
};
PKMN_OFFSET_ASSERT(Unk_b918f0, field_1d8, 0x1d8);

// 0x7100b918f0
u8* Unk_b918f0_getField1d8Ptr(Unk_b918f0* self) {
    return &self->field_1d8;
}
