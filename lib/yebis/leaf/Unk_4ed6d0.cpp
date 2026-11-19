// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71004ed6d0
u32 Unk_4ed6d0_get() {
    return 0x60;
}

extern u64 Unk_276e2d0 __attribute__((visibility("hidden")));

// 0x71004ee850
u64 Unk_4ee850_get() {
    return Unk_276e2d0;
}

extern u32 Unk_2391350 __attribute__((visibility("hidden")));

// 0x71004ee860
u32 Unk_4ee860_get() {
    return Unk_2391350;
}
