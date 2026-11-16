// Scope: common
#include <types.h>

struct Unk_14f5fb0 {
    u8 _0[0x20];
    s32 field_20;
    s32 field_24;
    s32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_28, 0x28);

struct Unk_14f5fb0_Pair {
    s32 field_0;
    s32 field_4;
};
PKMN_SIZE_ASSERT(Unk_14f5fb0_Pair, 0x8);

// 0x71014f5fb0 (Shield 0x71014f6050)
// Splits an index into quotient and remainder, in an order chosen by field_28.
// -O3 only: the 3-instruction `mov; bfi; ret` tail is duplicated.
Unk_14f5fb0_Pair Unk_14f5fb0_split(const Unk_14f5fb0* self, s32 index) {
    Unk_14f5fb0_Pair pair;
    if (self->field_28 != 0) {
        pair.field_0 = index / self->field_24;
        pair.field_4 = index % self->field_24;
    } else {
        pair.field_0 = index % self->field_20;
        pair.field_4 = index / self->field_20;
    }
    return pair;
}
