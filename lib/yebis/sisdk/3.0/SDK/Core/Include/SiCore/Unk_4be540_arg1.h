// What an allocator's slot 11 fills in (leafgen's name, after the first
// function that takes one; lib/yebis/class has the same layout): sizes and
// counts of the allocator's memory. Placeholder members.
#pragma once

#include <types.h>

struct Unk_4be540_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
};
PKMN_SIZE_ASSERT(Unk_4be540_arg1, 0x38);
