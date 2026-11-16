// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_983f60 {
    u8 _0[0x4b1];
    u8 field_4b1;
};
PKMN_OFFSET_ASSERT(Unk_983f60, field_4b1, 0x4b1);

// 0x7100983f60
u8 Unk_983f60_getField4b1(const Unk_983f60* self) {
    return self->field_4b1;
}
