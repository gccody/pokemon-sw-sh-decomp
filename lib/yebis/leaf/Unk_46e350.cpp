// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_46e270(void*, u32);

// 0x710046e350
void Unk_46e350_call(void* self) {
    Unk_46e270(self, 1);
}

// 0x7100471460
void Unk_471460_update() {
}

extern const u8 Unk_24e4c18[] __attribute__((visibility("hidden")));

// 0x71004738c0
const u8* Unk_4738c0_get() {
    return Unk_24e4c18;
}

extern const u8 Unk_24e4a18[] __attribute__((visibility("hidden")));

// 0x71004738d0
const u8* Unk_4738d0_get() {
    return Unk_24e4a18;
}
