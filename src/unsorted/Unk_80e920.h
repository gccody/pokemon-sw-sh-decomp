#pragma once
// The battle server's command wrappers' object (0x710080e920 to
// 0x710080f794), as these functions use it: the client at +8, the main module
// at +0x10, the command queue at +0x18 and the server's state at +0x20.
// Placeholder names: rename once the class is known.
#include <types.h>

#include "battle/battle_engine/Unk_8139c0.h"

struct Unk_80e920_Self {
    u8 _0[0x8];
    void* field_8;
    const void* field_10;
    u64 field_18;
    const Unk_8139c0_Self* field_20;
};
PKMN_OFFSET_ASSERT(Unk_80e920_Self, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_80e920_Self, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_80e920_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_80e920_Self, field_20, 0x20);

u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);

// Queues command `cmd` with its arguments (variadic).
void Unk_8150c0(u64 que, u32 cmd, ...);
// Queues message `id` with its arguments, ended by 0xffff0000 (variadic).
void Unk_816320(u64 que, u16 id, ...);
