// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d69a10 {
    u8 _0[0x721];
    u8 field_721;
};
PKMN_OFFSET_ASSERT(Unk_d69a10, field_721, 0x721);

// 0x7100d69a10
u8 Unk_d69a10_getField721(const Unk_d69a10* self) {
    return self->field_721;
}
