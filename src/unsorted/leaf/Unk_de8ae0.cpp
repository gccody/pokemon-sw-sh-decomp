// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_de8af0(void*, void*, u32, u64);

// 0x7100de8ae0
void Unk_de8ae0_call(void* self, void* value, u64 arg2) {
    Unk_de8af0(self, value, 0, arg2);
}
