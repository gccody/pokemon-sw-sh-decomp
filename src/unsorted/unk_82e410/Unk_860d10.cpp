// Scope: common
// A battle event handler with a TU of its own: 0x7100860dd0 calls it
// (Unk_8608d0.cpp). Placeholder names.
#include "unsorted/unk_82e410/Unk_860110.h"

// 0x7100860d10
void Unk_860d10(void* self, u8 pokeId) {
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    if (!Unk_860b00_CanShow(self, pokeId))
        return;
    Unk_860370_Show(self, pokeId);
}
