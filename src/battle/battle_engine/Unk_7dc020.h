#pragma once
// The fields of the battle client (src/battle/battle_engine/Unk_7cdac0.cpp
// defines it in full) that its commands from 0x71007dc020 to 0x71007dc850 use:
// each reads the command's arguments (words) and calls a server command
// (src/battle/battle_engine/Unk_8139c0.cpp) or a member function of what the
// main module at +0x70 holds. Placeholder names: rename once the class is known.
#include <types.h>

#include "battle/battle_engine/Unk_8139c0.h"

struct Unk_7e88f0;

struct Unk_7cdac0_Self {
    u8 _0[0x70];
    const Unk_7fe1d0* field_70;
    u8 _78[0x1f0 - 0x78];
    const Unk_7e88f0* field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_1f0, 0x1f0);

// Its server (src/unsorted/leaf/Unk_7e88d0.cpp).
const Unk_8139c0_Self* Unk_7e88f0_getField90(const Unk_7e88f0* self);

static inline const Unk_8139c0_Self* Unk_7cdac0_Server(const Unk_7cdac0_Self* self) {
    return Unk_7e88f0_getField90(self->field_1f0);
}
