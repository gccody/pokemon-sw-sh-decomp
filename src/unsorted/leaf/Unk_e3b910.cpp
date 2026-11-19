// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u64 Unk_ead710(void*);

// 0x7100e3b910
bool Unk_e3b910_call(void* self) {
    u64 r0 = Unk_ead710(self);
    return r0 != 0;
}
