// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_16ce4f0 {
    u8 _0[0x6f8];
    u8 field_6f8;
};
PKMN_OFFSET_ASSERT(Unk_16ce4f0, field_6f8, 0x6f8);

// 0x71016ce4f0
const u8* Unk_16ce4f0_get(const Unk_16ce4f0* self) {
    return &self->field_6f8;
}

struct Unk_16ce500 {
    u8 _0[0x778];
    u8 field_778;
};
PKMN_OFFSET_ASSERT(Unk_16ce500, field_778, 0x778);

// 0x71016ce500
const u8* Unk_16ce500_get(const Unk_16ce500* self) {
    return &self->field_778;
}

struct Unk_16d24a0 {
    u8 _0[0x17b0];
    u64 field_17b0;
};
PKMN_OFFSET_ASSERT(Unk_16d24a0, field_17b0, 0x17b0);

// 0x71016d24a0
void Unk_16d24a0_set(Unk_16d24a0* self) {
    self->field_17b0 = 0;
}
