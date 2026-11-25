// Scope: common
// A battle event handler that calls Unk_880b40 (in Unk_880840.cpp, a TU of
// its own so that the call isn't inlined). Placeholder names.
#include <types.h>

struct Unk_819600;
u32 Unk_819600_call(const Unk_819600* self, u32 value);
// Named (void*, u64, u32); it takes a u8.
void Unk_880b40(void* self, u64 pokeId, u32 index);

// NON_MATCHING: Unk_880b40 is named (void*, u64, u32), so the u8 is extended
// (and the registers swap). Matches with Unk_880b40(void*, u8, u32).
// 0x7100880ae0
void Unk_880ae0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_880b40(self, pokeId, 1);
}
