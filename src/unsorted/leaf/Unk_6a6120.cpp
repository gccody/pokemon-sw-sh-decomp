// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_15b87a0();

// 0x71006a6120
void Unk_6a6120_call() {
    Unk_15b87a0();
}

u32 Unk_15b78c0();
void Unk_15b8a20();

// 0x71006a6130
void Unk_6a6130_call() {
    u32 r0 = Unk_15b78c0();
    if (r0 != 0) {
        Unk_15b8a20();
    }
}
