// Scope: common
// A battle event handler helper, in its own TU: 0x710087a1c0 calls it.
// Placeholder names.
#include "unsorted/unk_82e410/Unk_8798c0.h"

// 0x710087a210
void Unk_87a210(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x63) == 0)
        return;
    u8 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    Unk_7ee6b0* poke = Unk_8196d0(flow, target);
    Unk_84d950_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = target;
    arg.field_2 = Unk_7f79e0(poke, 8, true);
    arg.field_4 = 6;
    arg.field_5 = pokeId;
    arg.field_6 = 0;
    arg.field_7 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_10), 2, 0x668);
    Unk_803d60(&arg.field_10, target);
    Unk_819b80(flow, arg);
}
