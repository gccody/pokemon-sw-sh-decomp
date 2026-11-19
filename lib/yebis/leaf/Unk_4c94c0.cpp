// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_4c94d0();

// 0x71004c94c0
void Unk_4c94c0_call() {
    Unk_4c94d0();
}

// 0x71004c9b90
u32 Unk_4c9b90_get() {
    return 1;
}

extern u8 Unk_24e8f60;

// 0x71004c9eb0
u8* Unk_4c9eb0_get() {
    return &Unk_24e8f60;
}
