// Scope: common
#include <types.h>

// A 400-entry ring buffer: `head` is the slot the next push writes. The
// scans walk back from the newest entry and stop at an empty one
// (field_4 == 0) or after a full lap.
struct Unk_803830_Entry {
    u32 field_0;
    u32 field_4;
    u8 field_8;
    u8 field_9;
};
PKMN_SIZE_ASSERT(Unk_803830_Entry, 0xc);
PKMN_OFFSET_ASSERT(Unk_803830_Entry, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_803830_Entry, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_803830_Entry, field_9, 0x9);

struct Unk_803830_Ring {
    static constexpr int kCount = 400;

    u32 head;
    Unk_803830_Entry entries[kCount];
};
PKMN_OFFSET_ASSERT(Unk_803830_Ring, entries, 0x4);
PKMN_SIZE_ASSERT(Unk_803830_Ring, 0x12c4);

static inline int Unk_803830_Prev(int index) {
    index--;
    if (index < 0)
        index = Unk_803830_Ring::kCount - 1;
    return index;
}

// 0x7100803830
void Unk_803830(Unk_803830_Ring* ring) {
    ring->head = 0;
    for (int i = 0; i < Unk_803830_Ring::kCount; i++)
        ring->entries[i].field_4 = 0;
}

// 0x7100803860
void Unk_803860(Unk_803830_Ring* ring, u32 field_4, u32 field_0, u8 field_8) {
    u32 head = ring->head;
    Unk_803830_Entry* entry = &ring->entries[head];
    entry->field_0 = field_0;
    entry->field_4 = field_4;
    entry->field_8 = field_8;
    entry->field_9 = 0;
    ring->head = head + 1 < Unk_803830_Ring::kCount ? head + 1 : 0;
}

// 0x7100803890
void Unk_803890(Unk_803830_Ring* ring) {
    int last = ring->head - 1;
    if (last < 0)
        last = Unk_803830_Ring::kCount - 1;
    ring->entries[last].field_9 = 1;
}

// 0x71008038c0
bool Unk_8038c0(const Unk_803830_Ring* ring, u32 field_4, u32 field_0) {
    for (int i = Unk_803830_Prev(ring->head); i != (int)ring->head; i = Unk_803830_Prev(i)) {
        if (ring->entries[i].field_4 == 0)
            return false;
        if (ring->entries[i].field_4 == field_4 && ring->entries[i].field_0 == field_0)
            return true;
    }
    return false;
}

// 0x7100803930
u32 Unk_803930(const Unk_803830_Ring* ring, u32 field_4, u32 field_0) {
    u32 count = 0;
    for (int i = Unk_803830_Prev(ring->head); i != (int)ring->head; i = Unk_803830_Prev(i)) {
        if (ring->entries[i].field_4 == 0)
            break;
        if (ring->entries[i].field_4 == field_4 && ring->entries[i].field_0 == field_0)
            count++;
    }
    return count;
}

// 0x71008039a0
u32 Unk_8039a0(const Unk_803830_Ring* ring, u32 field_0) {
    for (int i = Unk_803830_Prev(ring->head); i != (int)ring->head; i = Unk_803830_Prev(i)) {
        if (ring->entries[i].field_4 == 0)
            break;
        if (ring->entries[i].field_9 != 0 && ring->entries[i].field_0 == field_0)
            return ring->entries[i].field_4;
    }
    return 0;
}

// NON_MATCHING: the original masks the index to a u8 (`and w8, w1, #0xff`):
// it takes a u8, but its callers declare it with a u32
// 0x7100803a50
u16 Unk_803a50(void* self, u32 index) {
    if (index < 5)
        return static_cast<u16*>(self)[index];
    return 0;
}

// NON_MATCHING: the original masks the index to a u8 (`and w8, w1, #0xff`):
// it takes a u8, but its callers declare it with a u32
// 0x7100803a70
void Unk_803a70(void* self, u32 index, u16 value) {
    if (index < 5)
        static_cast<u16*>(self)[index] = value;
}

struct Unk_803a90_Entry {
    u32 kind;
    s16 field_4;
    s16 field_6;
};
PKMN_SIZE_ASSERT(Unk_803a90_Entry, 0x8);

static const Unk_803a90_Entry sUnk_803a90_Table[] = {
    {5, 336, 1244}, {4, 360, 1260}, {2, 424, 1252}, {3, 400, 1256}, {1, 380, 1248}, {23, 758, -1},
    {13, 806, -1},  {19, 984, -1},  {8, 508, 508},  {18, 508, 508}, {33, 1550, -1}, {11, 774, -1},
    {31, 892, -1},  {15, 1196, -1}, {12, 786, -1},  {6, 476, 1264}, {7, 460, 1268},
};

struct Unk_7ee6b0;
struct Unk_803d20;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
void Unk_803d20_set(Unk_803d20* self, u32 value, u16 arg2);
struct Unk_840b50_List;
void Unk_803d60(Unk_840b50_List* self, u32 value);
u16 Unk_7f89e0(const u64* self);

// The table is searched by kind; clang unrolls the loop into a switch and a
// lookup table of entry indices.
// NON_MATCHING: register allocation and one extra `and`: the original keeps
// arg3 unmasked in a callee-saved register and zero-extends it again for the
// second Unk_803d60 call, this build reuses one masked copy
// 0x7100803a90
bool Unk_803a90(u32 kind, const u64* arg1, const Unk_7ee6b0* arg2, u16 arg3, void* out) {
    int i;
    for (i = 0; i < 17; i++) {
        if (sUnk_803a90_Table[i].kind == kind)
            break;
    }
    if (i == 17)
        return false;

    const Unk_803a90_Entry* entry = &sUnk_803a90_Table[i];
    s16 id = arg3 != 0 ? entry->field_6 : entry->field_4;
    if (id < 0)
        id = entry->field_4;
    Unk_803d20_set(static_cast<Unk_803d20*>(out), 2, id);
    Unk_803d60(static_cast<Unk_840b50_List*>(out), Unk_7ee6b0_getField7d(arg2));
    if (arg3 != 0)
        Unk_803d60(static_cast<Unk_840b50_List*>(out), arg3);
    switch (kind) {
        case 8:
            Unk_803d60(static_cast<Unk_840b50_List*>(out), Unk_7f89e0(arg1));
            break;
        case 18:
            Unk_803d60(static_cast<Unk_840b50_List*>(out), 0x49);
            break;
    }
    return true;
}

bool Unk_7eb420(u32 value);
u32 Unk_7eef50(void* self, u32 index);

// 0x7100803b90
bool Unk_803b90(u32 kind, void* poke) {
    switch (kind) {
        case 6:
        case 10:
        case 15:
        case 18:
        case 19:
        case 20:
        case 21:
        case 30:
        case 31:
        case 33:
        case 36:
            return true;
        case 16:
            return !Unk_7eb420(Unk_7eef50(poke, 0x12));
        default:
            return false;
    }
}

// 0x7100803c00
u16 Unk_803c00(u32 kind) {
    switch (kind) {
        case 1:
            return 0x184;
        case 2:
            return 0x1b0;
        case 3:
            return 0x198;
        case 4:
            return 0x170;
        case 5:
            return 0x158;
        case 6:
            return 0x1e4;
        default:
            return 0xffff;
    }
}
