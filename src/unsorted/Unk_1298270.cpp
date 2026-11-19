// Scope: common
// A list of up to 167 ids (Poke Jobs, judging by the accessor it calls, which
// sits in the job app's code), filled from a table of 0x30-byte entries and
// sorted by a priority computed from each entry's state. std::sort's libc++
// instances for the comparator (__sort, __sort3, __sort4, __sort5 and
// __insertion_sort_incomplete, 0x7101299fb0-0x710129dfc0) are emitted here.
// Placeholder names: rename once the classes are known.
#include <algorithm>

#include <types.h>

#include "gflib3/Unk_239a418.h"

// An entry of the table: its state and a flag.
struct Unk_13736e0_Entry {
    u8 field_0;
    u8 _1[0x18];
    bool field_19;
    u8 _1a[0x16];
};
PKMN_OFFSET_ASSERT(Unk_13736e0_Entry, field_19, 0x19);
PKMN_SIZE_ASSERT(Unk_13736e0_Entry, 0x30);

// The table's owner (its entries start at +0x60).
class Unk_13736e0_Owner : public Unk_239a418 {};

// 0x71013736e0: the entry of an id.
const Unk_13736e0_Entry* Unk_13736e0(Unk_13736e0_Owner* self, s32 id);

struct Unk_24ba4e0_Type {
    u8 _0[0x268];
    Unk_239a418_Ref<Unk_13736e0_Owner> field_268;
};
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_268, 0x268);

extern Unk_24ba4e0_Type* Unk_24ba4e0;

class Unk_1298270_Jobs {
public:
    void Unk_1298270(bool sort);
    // 0x710129e870
    u32 Unk_129e870(s32 id);

    // The order of the list: higher priorities first, ids of the same
    // priority in increasing order.
    u32 Priority(s32 id) {
        Unk_239a418_Ref<Unk_13736e0_Owner> owner = Unk_24ba4e0->field_268;
        const Unk_13736e0_Entry* entry = Unk_13736e0(owner.m_ptr, id);
        u32 priority;
        if (Unk_129e870(id)) {
            if (entry->field_0 == 3)
                priority = entry->field_19 ? 8 : 10;
            else if (entry->field_0 == 1)
                priority = entry->field_19 ? 6 : 2;
            else
                priority = entry->field_19 ? 4 : 0;
        } else {
            if (entry->field_0 == 3)
                priority = entry->field_19 ? 9 : 11;
            else if (entry->field_0 == 1)
                priority = entry->field_19 ? 7 : 3;
            else
                priority = entry->field_19 ? 5 : 1;
        }
        return priority;
    }

    u8 _0[0x140];
    s32 field_140[167];
    s32 field_3dc;
};
PKMN_OFFSET_ASSERT(Unk_1298270_Jobs, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_1298270_Jobs, field_3dc, 0x3dc);

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
