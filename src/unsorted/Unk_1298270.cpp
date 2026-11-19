// Scope: common
// The list of jobs, filled from a table of 0x30-byte entries and sorted by a
// priority computed from each entry's state. std::sort's libc++ instances for
// the comparator (__sort, __sort3, __sort4, __sort5 and
// __insertion_sort_incomplete, 0x7101299fb0-0x710129dfc0) are emitted here.
#include "unsorted/Unk_1298270.h"

#include <algorithm>

// 0x7101298270
// It matches, but its row keeps the name `_Z11Unk_1298270Pvj`
// (`Unk_1298270(void*, unsigned int)`): the generated
// src/unsorted/leaf/Unk_12994f0.cpp calls it by that name. The row can take
// this one when that file is regenerated.
void Unk_1298270_Jobs::Unk_1298270(bool sort) {
    Unk_239a418_Ref<Unk_13736e0_Owner> owner = Unk_24ba4e0->field_268;
    s32 count = 0;
    for (s32 id = 0; id < 167; id++) {
        const Unk_13736e0_Entry* entry = Unk_13736e0(owner.m_ptr, id);
        if (entry->field_0 != 0 && entry->field_0 != 4 && entry->field_0 != 5)
            field_140[count++] = id;
    }
    if (sort) {
        std::sort(field_140, field_140 + count, [this, owner](s32 a, s32 b) {
            u32 pa = Priority(a);
            u32 pb = Priority(b);
            if (pa == pb)
                return a < b;
            return pa > pb;
        });
    }
    field_3dc = count;
}
