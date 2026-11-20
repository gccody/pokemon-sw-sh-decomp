// Scope: common
// Whether two clients are on different sides (calls Unk_7fa500 out of line,
// src/battle/battle_engine/Unk_7f9a10.cpp). Placeholder names: rename once the
// functions are known.
#include <types.h>

u8 Unk_7fa500(u32 rule, u32 client);

// 0x71007fb6f0
bool Unk_7fb6f0(u32 rule, u32 client, u32 other) {
    return Unk_7fa500(rule, client) != Unk_7fa500(rule, other);
}
