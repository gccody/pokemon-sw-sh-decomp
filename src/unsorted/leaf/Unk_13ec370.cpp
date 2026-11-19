// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_27d6178;
u64 Unk_cab0c0(u64);

// 0x71013ec370
u64 Unk_13ec370_call() {
    u64 r0 = Unk_cab0c0(Unk_27d6178);
    return r0 & 1;
}
