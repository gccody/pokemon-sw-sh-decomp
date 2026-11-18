// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern const u8 Unk_2433c50[] __attribute__((visibility("hidden")));

// 0x71013a3530
const u8* Unk_13a3530_get() {
    return Unk_2433c50;
}
