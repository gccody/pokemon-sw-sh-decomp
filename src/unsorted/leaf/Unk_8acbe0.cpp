// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8acbe0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8acbe0, field_30, 0x30);

// 0x71008acbe0
u8 Unk_8acbe0_getField30(const Unk_8acbe0* self) {
    return self->field_30;
}
