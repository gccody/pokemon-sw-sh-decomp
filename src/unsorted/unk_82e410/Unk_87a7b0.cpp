// Scope: common
// A battle event handler helper, in its own TU: 0x710087a760 calls it.
// Placeholder names.
#include "unsorted/unk_82e410/Unk_8798c0.h"

// 0x710087a7b0
// NON_MATCHING: named (void*, u32); the original compares the value as a byte
// (cmp w0, w20, uxtb), as a u8 parameter gives. Unk_7f78c0 is named with one
// parameter and takes two.
void Unk_87a7b0(void* self, u32 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x63) == 0)
        return;
    Unk_836520_Arg arg;
    arg.field_4 = 5;
    arg.field_8 = Unk_7f78c0(arg.field_4, pokeId);
    arg.field_10 = 2;
    arg.field_0 = pokeId;
    arg.field_1 = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    Unk_819d00(flow, arg);
}
