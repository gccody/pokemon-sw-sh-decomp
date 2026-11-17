// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x710091ced0
void Unk_91ced0_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x710091cee0
void Unk_91cee0_call(void* self) {
    Unk_eb6230(self, 3);
}
