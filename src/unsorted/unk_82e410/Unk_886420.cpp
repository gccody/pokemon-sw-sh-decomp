// Scope: common
// The two helpers of the handlers of 0x7100886280-0x71008863e0 (Unk_886280.cpp
// calls them, so they have a TU of their own): they set the form of species
// 0x15f from what Unk_81a350 gives, and reset it. Placeholder names.
#include "unsorted/unk_82e410/Unk_886280.h"

// 0x7100886420
void Unk_886420(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_85c190_Species(poke) != 0x15f)
        return;
    if (Unk_7ef220_get(reinterpret_cast<const Unk_7ef220*>(poke)))
        return;
    u8 current = poke->field_33d;
    u8 form;
    switch (Unk_81a350(flow, pokeId)) {
        case 1:
            form = 1;
            break;
        case 2:
            form = 2;
            break;
        case 3:
            form = 3;
            break;
        case 5:
            form = 2;
            break;
        case 6:
            form = 1;
            break;
        default:
            form = 0;
            break;
    }
    if (form == current)
        return;
    Unk_8557b0_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = form;
    arg.field_4 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_8), 2, 0x130);
    Unk_803d60(&arg.field_8, pokeId);
    Unk_81aa70(flow, arg);
}

// 0x7100886520
void Unk_886520(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_85c190_Species(poke) != 0x15f)
        return;
    if (poke->field_33d == 0)
        return;
    if (Unk_7ef220_get(reinterpret_cast<const Unk_7ef220*>(poke)))
        return;
    Unk_8557b0_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 0;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_8), 2, 0x130);
    Unk_803d60(&arg.field_8, pokeId);
    Unk_81aa70(flow, arg);
}
