// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24e8f28 __attribute__((visibility("hidden")));

// 0x71004bf7b0
u64 Unk_4bf7b0_get() {
    return Unk_24e8f28;
}
