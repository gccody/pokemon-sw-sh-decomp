// Scope: common
// std::sort's libc++ instances for the ribbons of the summary app (game/status):
// 0x71012e3f60 lists the ribbons a Pokemon has and sorts them by the ribbon
// table's `showNum` (__sort, __sort3, __sort4, __sort5 and
// __insertion_sort_incomplete, 0x71012e5470-0x71012e7010).
// Placeholder names: rename once the classes are known.
#include <algorithm>

#include <types.h>

#include "unsorted/Unk_1106320.h"

class Unk_12e3f60 {
public:
    void Unk_12e3f60_Sort(s32 count);

    u8 _0[0x608];
    s32 field_608[98];
    u8 _790[0x8];
    Unk_1106320_Node field_798;
};
PKMN_OFFSET_ASSERT(Unk_12e3f60, field_608, 0x608);
PKMN_OFFSET_ASSERT(Unk_12e3f60, field_798, 0x798);

// 0x71012e3f60
// NON_MATCHING: a guess at the shape. The original (1,096 bytes) first lists
// the ribbons the Pokemon has; its only purpose here is the sort, whose
// instances are emitted with it.
void Unk_12e3f60::Unk_12e3f60_Sort(s32 count) {
    std::sort(field_608, field_608 + count, [this](const s32& a, const s32& b) {
        Unk_1106320_Node table = field_798.Unk_11063e0("ribbon_table");
        s32 a_num = table.Unk_1106320(a).Unk_11063e0("showNum").Unk_11065b0(0);
        s32 b_num = table.Unk_1106320(b).Unk_11063e0("showNum").Unk_11065b0(0);
        return a_num < b_num;
    });
}
