// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_865240(void*, u64, u32);

// 0x7100865230
void Unk_865230_call(void* self, u64 value) {
    Unk_865240(self, value, 1);
}

void Unk_865240(void*, u64, u32);

// 0x7100865300
void Unk_865300_call(void* self, u64 value) {
    Unk_865240(self, value, 2);
}

// 0x7100865680
void Unk_865680_update() {}

// 0x7100866300
void Unk_866300_update() {}
