// Scope: common
// The per-kind limits of the entries of src/unsorted/unk_82e410/Unk_801e30.h,
// a counter handing out the blocks' ids, and accessors of a condition at
// +0x10. Placeholder names: rename once the classes are known.
#include "unsorted/unk_82e410/Handler.h"

// As src/unsorted/leaf/Unk_7f8780.cpp declares it.
struct Unk_7f8b70 {
    u32 field_0;
};
u32 Unk_7f8b70_get(const Unk_7f8b70* self);

struct Unk_8024f0 {
    u8 _0[0x10];
    Unk_7f8b70 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8024f0, field_10, 0x10);

// 0x71008024f0
u32 Unk_8024f0_get(const Unk_8024f0* self) {
    return Unk_7f8b70_get(&self->field_10);
}

struct Unk_802510 {
    u8 _0[0x10];
    u32 field_10;
    u8 _14[0x4];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_802510, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_802510, field_18, 0x18);

// 0x7100802510
bool Unk_802510_check(const Unk_802510* self) {
    return ((self->field_10 >> 8) & 0x3f) <= self->field_18;
}

// How often an entry of each kind can be set (0x7100802530 searches it by kind).
struct Unk_802530_Entry {
    u32 kind;
    u32 max;
};
PKMN_SIZE_ASSERT(Unk_802530_Entry, 0x8);

static const Unk_802530_Entry sUnk_802530_Table[] = {
    {0, 1},  {1, 1},  {17, 1}, {2, 1},  {3, 1},  {4, 1},  {5, 1},  {6, 3},
    {7, 2},  {8, 1},  {9, 1},  {10, 1}, {11, 1}, {12, 1}, {13, 1}, {14, 1},
    {15, 3}, {16, 1}, {18, 1}, {19, 1}, {20, 1}, {21, 1},
};

// The table is searched by kind; clang unrolls the loop into a switch and a
// lookup table of entry indices.
// 0x7100802530
u32 Unk_802530(s32 kind) {
    for (s32 i = 0; i < 22; i++) {
        if (sUnk_802530_Table[i].kind == static_cast<u32>(kind))
            return sUnk_802530_Table[i].max;
    }
    return 0;
}

struct Unk_8025a0_Counter {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8025a0_Counter, field_8, 0x8);

// 0x71008025a0
void Unk_8025a0(void* self, Unk_8306f0_Block* block) {
    Unk_8025a0_Counter* counter = static_cast<Unk_8025a0_Counter*>(self);
    if (counter->field_8 == 0)
        counter->field_8 = 1;
    block->field_0 = counter->field_8;
    ++counter->field_8;
}
