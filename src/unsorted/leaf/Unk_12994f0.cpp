// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_1298270(void*, u32);
void Unk_12986e0();

// 0x71012994f0
void Unk_12994f0_call(void* self) {
    Unk_12986e0();
    Unk_1298270(self, 1);
}
