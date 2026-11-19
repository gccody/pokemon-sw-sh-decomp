// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u32 Unk_e59010(void*);

// 0x7100e59180
bool Unk_e59180_call(void* self) {
    u32 r0 = Unk_e59010(self);
    return r0 != 0;
}
