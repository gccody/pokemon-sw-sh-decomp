#pragma once
// The battle server's command wrappers' object as Unk_811d90_Self has it,
// with the main module at +0x10 too. Placeholder names: rename once the class
// is known.
#include "unsorted/Unk_811d90.h"

struct Unk_80fb90_Self {
    u8 _0[0x10];
    const Unk_7fe250* field_10;
    u64 field_18;
    const Unk_8139c0_Self* field_20;
};
PKMN_OFFSET_ASSERT(Unk_80fb90_Self, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_80fb90_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_80fb90_Self, field_20, 0x20);
