// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_8ecf40(void*, void*, u32);

// 0x71008ed2e0
void Unk_8ed2e0_call(void* self, void* value) {
    Unk_8ecf40(self, value, 0);
    Unk_8ecf40(self, value, 1);
    Unk_8ecf40(self, value, 2);
    Unk_8ecf40(self, value, 3);
    Unk_8ecf40(self, value, 4);
    Unk_8ecf40(self, value, 5);
    Unk_8ecf40(self, value, 6);
}
