#pragma once

#include <types.h>

// A grid of items laid out in lines of field_20 (field_28 == 0) or field_24
// (field_28 != 0) items, scrolled by whole lines.
struct Unk_14f5fb0 {
    u8 _0[0x8];
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
    s32 field_20;
    s32 field_24;
    s32 field_28;
    u8 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_14f5fb0, field_2c, 0x2c);

struct Unk_14f5fb0_Pair {
    s32 field_0;
    s32 field_4;
};
PKMN_SIZE_ASSERT(Unk_14f5fb0_Pair, 0x8);

// Items per line.
inline s32 Unk_14f5fb0_lineSize(const Unk_14f5fb0& self) {
    return self.field_28 == 0 ? self.field_20 : self.field_24;
}

// Number of lines.
inline s32 Unk_14f5fb0_lineCount(const Unk_14f5fb0& self) {
    return self.field_28 != 0 ? self.field_20 : self.field_24;
}

// The coordinate along the lines.
inline s32 Unk_14f5fb0_minor(const Unk_14f5fb0& self, const Unk_14f5fb0_Pair& pos) {
    return self.field_28 == 0 ? pos.field_0 : pos.field_4;
}

// The coordinate across the lines (the line number).
inline s32 Unk_14f5fb0_major(const Unk_14f5fb0& self, const Unk_14f5fb0_Pair& pos) {
    return self.field_28 == 0 ? pos.field_4 : pos.field_0;
}

inline s32 Unk_14f5fb0_index(const Unk_14f5fb0& self, const Unk_14f5fb0_Pair& pos) {
    if (self.field_28 != 0) {
        return pos.field_0 * self.field_24 + pos.field_4;
    }
    return pos.field_0 + pos.field_4 * self.field_20;
}

// The position of the item at `index`.
inline Unk_14f5fb0_Pair Unk_14f5fb0_position(const Unk_14f5fb0& self, s32 index) {
    Unk_14f5fb0_Pair pair;
    if (self.field_28 != 0) {
        pair.field_0 = index / self.field_24;
        pair.field_4 = index % self.field_24;
    } else {
        pair.field_0 = index % self.field_20;
        pair.field_4 = index / self.field_20;
    }
    return pair;
}
