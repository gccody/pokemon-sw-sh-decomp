// Scope: common
// The walk of Unk_23bb228 (src/unsorted/unk_8bf520/Unk_8c6550.h) over the set
// bits of its mask, and the class on it with vtable 0x71023bb2b0
// (Unk_23bb2a0). Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_New.h"
#include "unsorted/unk_8bf520/Unk_8c6550.h"

// NON_MATCHING: the bit test's tst takes its operands the other way round
// 0x71008c6830
void Unk_23bb228::Unk_8c6830() {
    for (u32 i = field_54; i <= static_cast<u32>(field_58); i++) {
        if (field_60 & (1 << i)) {
            field_5c = i;
            return;
        }
    }
    field_5c = 14;
}

// NON_MATCHING: as Unk_8c6830
// 0x71008c6870
void Unk_23bb228::Unk_8c6870() {
    field_5c++;
    for (u32 i = field_5c; i <= static_cast<u32>(field_58); i++) {
        if (field_60 & (1 << i)) {
            field_5c = i;
            return;
        }
    }
    field_5c = 14;
}

// 0x71008c68b0
bool Unk_23bb228::Unk_8c68b0() const {
    return field_58 < field_5c;
}

// NON_MATCHING: clang inlines Create<Unk_23bab98>, which the original calls
// (0x71008c1770; so do its siblings' constructors, 0x71008c1040 and
// 0x71008c8380), and gives the fields' base another register; the rest
// matches
// 0x71008c68c0
Unk_23bb2a0::Unk_23bb2a0(Unk_239a418_Allocator* allocator,
                         const Unk_8c6550_Ref<Unk_239a4c0>& arg2,
                         Unk_7c2d80_Main* main,
                         Unk_7fe1d0* arg4,
                         void* arg5,
                         u64 seed,
                         u32 mask,
                         u8 arg8)
    : Unk_23bb228(arg8, 0, 9, mask), field_68(main), field_70(arg4), field_a8(arg2) {
    Unk_7f8c00(&field_88, seed);
    field_b0 = Unk_8c6550_Ref<Unk_23bab98>(Unk_New().Create<Unk_23bab98>(allocator));
    field_b8 = Unk_8c6550_Ref<Unk_23bac00>(
        Unk_New().Create<Unk_23bac00>(allocator, allocator, main, arg5, arg4, seed));
}

// 0x71008c6b20 (D1), 0x71008c6c90 (D0), its thunks for +0x48 (0x71008c6bd0
// D1, 0x71008c6d40 D0)
Unk_23bb2a0::~Unk_23bb2a0() {
    field_b0.Reset();
    field_b8.Reset();
}
