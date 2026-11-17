// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1434750 {
    u8 _0[0x50];
    u32 field_50;
    u16 field_54;
};
PKMN_OFFSET_ASSERT(Unk_1434750, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_1434750, field_54, 0x54);

// 0x7101434750
void Unk_1434750_set(Unk_1434750* self) {
    self->field_54 = 0;
    self->field_50 = 0;
}

// 0x71014357f0
u64 Unk_14357f0_get() {
    return 0xfc06cb2c3f628f41;
}

// 0x7101435810
u64 Unk_1435810_get() {
    return 0xfc03492c3f5f7c84;
}

struct Unk_1435ec0 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_1435ec0, field_88, 0x88);

void Unk_eb8a30(u64, u32);

// 0x7101435ec0
void Unk_1435ec0_call(const Unk_1435ec0* self) {
    Unk_eb8a30(self->field_88, 1);
}
