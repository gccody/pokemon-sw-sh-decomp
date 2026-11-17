// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_13e4b60(void*, u64, u64, u32, u32);

// 0x71013e4b50
void Unk_13e4b50_call(void* self, u64 value, u64 arg2, bool arg3) {
    Unk_13e4b60(self, value, arg2, arg3, 0);
}
