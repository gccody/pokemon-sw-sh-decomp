// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_3291d0(void*, u64, u32, u64);

// 0x71003291c0
void Unk_3291c0_call(void* self, u64 value, u64 arg2, u32 arg3) {
    Unk_3291d0(self, value, arg3, arg2);
}

void Unk_3296c0(void*, u64, u32, u64, u64);

// 0x71003296a0
void Unk_3296a0_call(void* self, u64 value, u64 arg2, u64 arg3, u32 arg4) {
    Unk_3296c0(self, value, arg4, arg2, arg3);
}
