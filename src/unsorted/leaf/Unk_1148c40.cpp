// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1148c40 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1148c40, field_60, 0x60);

// 0x7101148c40
u32 Unk_1148c40_getField60(const Unk_1148c40* self) {
    return self->field_60;
}
