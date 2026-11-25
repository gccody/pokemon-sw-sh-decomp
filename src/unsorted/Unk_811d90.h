#pragma once
// The object behind the battle server's command wrappers (0x7100811d90 to
// 0x71008122a8): each one queues a command (an id and its arguments) with
// Unk_8150c0, some after acting on the server's state at +0x20 first.
// Placeholder names: rename once the classes are known.
#include <types.h>

#include "battle/battle_engine/Unk_8139c0.h"

struct Unk_811d90_Self {
    u8 _0[0x18];
    u64 field_18;
    const Unk_8139c0_Self* field_20;
};
PKMN_OFFSET_ASSERT(Unk_811d90_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_811d90_Self, field_20, 0x20);

// Queues command `cmd` with its arguments: it's variadic (it saves x2..x7 and
// q0..q7 into its va_list area, and its callers pass 1 to 7 arguments).
void Unk_8150c0(u64 que, u32 cmd, ...);
