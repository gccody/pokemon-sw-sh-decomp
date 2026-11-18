// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_238d5f8;
void Unk_4b9a60(u64);

// 0x710045fe80
void Unk_45fe80_call() {
    Unk_4b9a60(Unk_238d5f8);
}

void Unk_46e270(void*, u32);

// 0x710046e350
void Unk_46e350_call(void* self) {
    Unk_46e270(self, 1);
}

// 0x7100471460
void Unk_471460_update() {
}
