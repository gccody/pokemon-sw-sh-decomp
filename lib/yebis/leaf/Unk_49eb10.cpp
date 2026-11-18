// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u32 Unk_24e55a8;

// 0x710049eb10
u32 Unk_49eb10_get() {
    return Unk_24e55a8;
}

extern u32 Unk_24e55a8;

// 0x710049eb20
u32 Unk_49eb20_get() {
    return Unk_24e55a8;
}
