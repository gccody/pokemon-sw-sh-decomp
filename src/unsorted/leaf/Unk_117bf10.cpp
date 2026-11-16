// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_117bf10 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_117bf10, field_a0, 0xa0);

// 0x710117bf10
u64 Unk_117bf10_getFielda0(const Unk_117bf10* self) {
    return self->field_a0;
}
