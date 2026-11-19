// Scope: common
// A table of 36 unordered pairs of objects, each kept with the lower address
// first, and a flag per pair.
#include <types.h>

struct Unk_1166030_Pair {
    void* field_0;
    void* field_8;
    bool field_10;
};
PKMN_SIZE_ASSERT(Unk_1166030_Pair, 0x18);

struct Unk_1166030 {
    u8 field_0[0x80];
    Unk_1166030_Pair field_80[36];
};
PKMN_OFFSET_ASSERT(Unk_1166030, field_80, 0x80);
PKMN_SIZE_ASSERT(Unk_1166030, 0x3e0);

// 0x7101166930
bool Unk_1166930(Unk_1166030* self, void* a, void* b) {
    if (a == nullptr || b == nullptr)
        return false;
    void* hi = b;
    void* lo = a;
    if (a != b) {
        lo = a < b ? a : b;
        hi = a > b ? a : b;
    }
    for (Unk_1166030_Pair& pair : self->field_80) {
        if (pair.field_0 == lo && pair.field_8 == hi)
            return true;
    }
    return false;
}

// 0x7101166ce0
// NON_MATCHING: register allocation. The values of the first entries' first
// fields, which the second loop reuses, swap registers (x13/x14, x15/x16,
// x5/x6) in 29 instructions; the code is otherwise the same.
void Unk_1166ce0(Unk_1166030* self, void* a, void* b) {
    if (a == nullptr || b == nullptr)
        return;
    void* hi = b;
    void* lo = a;
    if (a != b) {
        lo = a < b ? a : b;
        hi = a > b ? a : b;
    }
    for (Unk_1166030_Pair& pair : self->field_80) {
        if (pair.field_0 == lo && pair.field_8 == hi) {
            pair.field_10 = true;
            return;
        }
    }
    for (Unk_1166030_Pair& pair : self->field_80) {
        if (pair.field_0 == nullptr && pair.field_8 == nullptr) {
            pair.field_0 = lo;
            pair.field_8 = hi;
            return;
        }
    }
}
