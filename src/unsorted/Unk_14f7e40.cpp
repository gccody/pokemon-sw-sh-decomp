// Scope: common
#include <types.h>

struct Unk_14f7e40 {
    u8 _0[0x1b8];
    s32 field_1b8;
    u8 _1bc[0x1d4 - 0x1bc];
    f32 field_1d4;
    f32 field_1d8;
    bool field_1dc;
    f32 field_1e0;
};
PKMN_OFFSET_ASSERT(Unk_14f7e40, field_1b8, 0x1b8);
PKMN_OFFSET_ASSERT(Unk_14f7e40, field_1d4, 0x1d4);
PKMN_OFFSET_ASSERT(Unk_14f7e40, field_1d8, 0x1d8);
PKMN_OFFSET_ASSERT(Unk_14f7e40, field_1dc, 0x1dc);
PKMN_OFFSET_ASSERT(Unk_14f7e40, field_1e0, 0x1e0);

// 0x71014f7e40
bool Unk_14f7e40_hasField1b8(const Unk_14f7e40* self) {
    return self->field_1b8 != 0;
}

// 0x71014f7fe0
// NON_MATCHING: register allocation only. The original keeps the quotient in s2
// and field_1d8 in s1 (`fcsel s1, s2, s3, lt`); this swaps them. Same result with
// -O2, -g0 and -std=c++14.
void Unk_14f7e40_snap(Unk_14f7e40* self, f32 step) {
    if (self->field_1b8 == 4) {
        f32 q = self->field_1d4 / step;
        if (self->field_1d8 >= 0.0f)
            q += 1.0f;
        s32 n = q;
        self->field_1e0 = n * step;
        self->field_1dc = true;
    }
}
