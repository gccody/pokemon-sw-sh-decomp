// Scope: common
// The walk of Unk_23bb228 (src/unsorted/unk_8bf520/Unk_8c6550.h) over the set
// bits of its mask, and the class on it with vtable 0x71023bb2b0
// (Unk_23bb2a0). Placeholder names: rename once the classes are known.
#include <types.h>

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
