// Scope: common
#include <types.h>

struct Unk_14e6d50_Grid {
    u8 _0[0x8];
    s32 field_8;
    s32 field_c;
    s32 field_10;
    u8 _14[0x1c - 0x14];
    s32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_14e6d50_Grid, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14e6d50_Grid, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_14e6d50_Grid, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_14e6d50_Grid, field_1c, 0x1c);

struct Unk_14e6d50 {
    u8 _0[0x408];
    Unk_14e6d50_Grid* field_408;
};
PKMN_OFFSET_ASSERT(Unk_14e6d50, field_408, 0x408);

struct Unk_14e6d50_Pair {
    s32 field_0;
    s32 field_4;
};
PKMN_SIZE_ASSERT(Unk_14e6d50_Pair, 0x8);

// 0x71014e6d50 (Shield 0x71014e6df0)
// Same split as 0x71014f5fb0, on another layout. -O3 only: the `mov; bfi; ret`
// tail is duplicated.
Unk_14e6d50_Pair Unk_14e6d50_split(const Unk_14e6d50* self) {
    const Unk_14e6d50_Grid* grid = self->field_408;
    s32 index = grid->field_8;
    Unk_14e6d50_Pair pair;
    if (grid->field_1c != 0) {
        pair.field_0 = index / grid->field_10;
        pair.field_4 = index % grid->field_10;
    } else {
        pair.field_0 = index % grid->field_c;
        pair.field_4 = index / grid->field_c;
    }
    return pair;
}
