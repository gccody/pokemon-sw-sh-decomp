// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14b9630 {
    u8 _0[0x348];
    u32 field_348;
};
PKMN_OFFSET_ASSERT(Unk_14b9630, field_348, 0x348);

// 0x71014b9630
u32 Unk_14b9630_get(const Unk_14b9630* self) {
    return self->field_348 >> 1;
}

// 0x71014ba810
u32 Unk_14ba810_get(u64 /*unused*/) {
    return 1;
}
