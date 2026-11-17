// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24ba170;
void Unk_6aed00(u64);

// 0x7101061760
void Unk_1061760_call() {
    if (Unk_24ba170 != 0) {
        Unk_6aed00(Unk_24ba170);
    }
}

void Unk_6ae9d0(u64);

// 0x7101061800
void Unk_1061800_call(void* /*unused*/, u64 value) {
    Unk_6ae9d0(value);
}

extern u64 Unk_24ba170;
void Unk_6ae840(u64);

// 0x71010619d0
void Unk_10619d0_call() {
    if (Unk_24ba170 != 0) {
        Unk_6ae840(Unk_24ba170);
    }
}
