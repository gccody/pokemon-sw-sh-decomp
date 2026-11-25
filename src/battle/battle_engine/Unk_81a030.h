#pragma once
// Scope: common
// What the battle's event handlers are given (as in Unk_819600.cpp): the main
// module (+0, +8), the Pokemon (+0x10), the battle's state (+0x20, the
// Unk_7e0080 that holds the handler objects), the event system (+0x30) and
// the handler (+0x40). Placeholder names: rename once the functions are known.
#include "unsorted/unk_82e410/Handler.h"

struct Unk_819600_Self {
    const void* field_0;
    const void* field_8;
    const void* field_10;
    const void* field_18;
    const Unk_7e0080* field_20;
    u8 _28[0x30 - 0x28];
    void* field_30;
    u8 _38[0x40 - 0x38];
    void* field_40;
};
PKMN_OFFSET_ASSERT(Unk_819600_Self, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_819600_Self, field_40, 0x40);
