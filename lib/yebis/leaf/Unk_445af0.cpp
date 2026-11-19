// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_445620(void*, void*, u32, u32, u32, u32, u32);

// 0x7100445af0
void Unk_445af0_call(void* self, void* value, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6) {
    Unk_445620(self, value, arg2, arg3, arg4, arg5, arg6);
}
