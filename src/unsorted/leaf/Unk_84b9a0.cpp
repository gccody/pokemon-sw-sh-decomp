// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_1367890(void*, u64, u32);

// 0x710084b9a0
void Unk_84b9a0_call(void* self, u64 value) {
    Unk_1367890(self, value, 1);
}
