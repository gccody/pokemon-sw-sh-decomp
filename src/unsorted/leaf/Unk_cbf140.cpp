// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_27e06a0;
void Unk_c50830(u64, u32);

// 0x7100cbf140
void Unk_cbf140_call() {
    Unk_c50830(Unk_27e06a0, 9);
}

extern u64 Unk_27e06a0;
void Unk_c50830(u64, u32);

// 0x7100cbf990
void Unk_cbf990_call() {
    Unk_c50830(Unk_27e06a0, 0xa);
}
