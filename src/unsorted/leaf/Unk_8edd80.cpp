// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern const u8 Unk_1f19ee8[] __attribute__((visibility("hidden")));

// 0x71008edd80
const u8* Unk_8edd80_get() {
    return Unk_1f19ee8;
}

// 0x71008edd90
u32 Unk_8edd90() {
    return 0x4b;
}
