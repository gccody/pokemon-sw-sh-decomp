// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710076bef0
u32 Unk_76bef0_get() {
    return 8;
}

struct Unk_76c490 {
    u8 _0[0x31];
    u8 field_31;
};
PKMN_OFFSET_ASSERT(Unk_76c490, field_31, 0x31);

// 0x710076c490
u32 Unk_76c490_get(const Unk_76c490* self) {
    return (self->field_31 >> 6) & 1;
}
