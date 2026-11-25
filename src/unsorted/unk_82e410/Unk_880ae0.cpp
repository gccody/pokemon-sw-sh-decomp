// Scope: common
// A battle event handler that calls Unk_880b40 (in Unk_880840.cpp, a TU of
// its own so that the call isn't inlined). Placeholder names.
#include "unsorted/unk_82e410/Unk_880840.h"

// 0x7100880ae0
void Unk_880ae0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_880b40(self, pokeId, 1);
}
