// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71005393f0
u32 Unk_5393f0_get() {
    return 1;
}

struct Unk_539700 {
    u8 _0[0x50];
    u64 field_50;
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_539700, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_539700, field_58, 0x58);

// 0x7100539700
void Unk_539700_set(Unk_539700* self) {
    self->field_50 = 0;
    self->field_58 = 0;
}
