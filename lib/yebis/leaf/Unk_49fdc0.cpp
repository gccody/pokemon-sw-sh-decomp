// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

namespace PPFX {
class CRenderTexturePool;
}
s32 Unk_49fc60(PPFX::CRenderTexturePool*, u32, void*);

// 0x710049fdc0
void Unk_49fdc0_call(void* self, u64 value) {
    u64 l8;
    l8 = value;
    Unk_49fc60(static_cast<PPFX::CRenderTexturePool*>(self), 1, &l8);
}
