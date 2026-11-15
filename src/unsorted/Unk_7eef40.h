#pragma once
// Placeholder type: rename once the owning class is identified.
#include <types.h>

struct Unk_7eef40 {
    u8 _0[0x70];
    u16 field_70;
};
PKMN_OFFSET_ASSERT(Unk_7eef40, field_70, 0x70);

u16 Unk_7eef40_getField70(const Unk_7eef40* self);
