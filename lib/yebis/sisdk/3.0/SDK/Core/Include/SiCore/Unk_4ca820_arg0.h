// Eight bytes that name a language: two numbers, both 0 for no language
// (leafgen-style placeholder name: 0x71004ca820 takes one). The kernel keeps
// two, and every string table one; a string table's entry has a text for each.
#pragma once

#include <types.h>

struct Unk_4ca820_arg0 {
    Unk_4ca820_arg0() : field_0(0), field_4(0) {}
    Unk_4ca820_arg0(u32 a, u32 b) : field_0(a), field_4(b) {}

    bool operator==(const Unk_4ca820_arg0& other) const { return field_0 == other.field_0 && field_4 == other.field_4; }

    u32 field_0;
    u32 field_4;
};
PKMN_SIZE_ASSERT(Unk_4ca820_arg0, 8);
