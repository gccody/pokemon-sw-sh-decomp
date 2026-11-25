#pragma once
// A tick and whether it's set (0x71016c1b90-0x71016c1c20). Placeholder names.
#include <types.h>

struct Unk_16c1b90 {
    Unk_16c1b90();
    ~Unk_16c1b90();

    u64 field_0;
    bool field_8;
};
PKMN_OFFSET_ASSERT(Unk_16c1b90, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_16c1b90, 0x10);
