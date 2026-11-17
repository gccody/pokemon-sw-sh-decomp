// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_906480(void*, u32);

// 0x7100906540
void Unk_906540_call(void* self) {
    Unk_906480(self, 0xff);
}
