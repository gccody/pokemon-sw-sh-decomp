// Scope: common
// Battle event handlers (0x7100885530-0x7100885b14): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_886280.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_886280.h"

struct Unk_819680;
bool Unk_780ec0(u32 move);

// Declared void in src/unsorted/leaf: it returns what 0x71007e9910 returns,
// a message list.
Unk_840b50_List* Unk_819680_call(const Unk_819680* self, u32 value);

bool Unk_885af0(const Unk_886f30_Self* self);

// 0x7100885530
void Unk_885530(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
}

// 0x71008855a0
void Unk_8855a0(void* self, u8 pokeId) {
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (target != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) == target)
        return;
    u32 move = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12);
    bool ok = Unk_780ec0(move);
    if (move == 0xa5 || !ok)
        return;
    if (static_cast<s32>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x3d)) > 7)
        return;
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x47, 1))
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x76, 1);
    Unk_840b50_List* list = Unk_819680_call(static_cast<const Unk_819680*>(self), 0x44);
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(list), 2, 0x120);
    Unk_803d60(list, target);
}

// 0x71008856a0
void Unk_8856a0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 0) {
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1,
                        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x25, 0x13));
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    } else {
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
    }
}

// 0x7100885730
void Unk_885730(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_7f0aa0(Unk_8196d0(flow, pokeId), 0))
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x7100885790
void Unk_885790(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (target != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 1) == 0)
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x25a);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, 0);
}

// 0x7100885850
void Unk_885850(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0xc) == 5)
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
}

// 0x71008858b0
void Unk_8858b0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, 0);
}

// 0x7100885930
void Unk_885930(void* self, u8 pokeId) {
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    u32 move = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12);
    if (move != 0x78 && move != 0x2d0 && move != 0x99)
        return;
    if (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x25)) == 0) {
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0,
                        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x25, 0x13));
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, move);
    }
}

// 0x71008859d0
void Unk_8859d0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    u8 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x4cc);
    Unk_803d60(&arg.field_4, target);
    Unk_803d60(&arg.field_4, Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 1));
    Unk_81a030(flow, arg);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
}

// 0x7100885a90
void Unk_885a90(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    // The predicate of 0x7100885af0, as a callback.
    Unk_819840(flow, reinterpret_cast<u64>(&Unk_885af0));
}

// 0x7100885aa0
void Unk_885aa0(void* self, u8 pokeId) {
    Unk_819850(static_cast<const Unk_819600_Self*>(self));
}

// 0x7100885ab0
void Unk_885ab0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819850(flow);
}

// NON_MATCHING: the original branches to a `mov w0, #1` for the second test;
// clang gives a cset (also tried early returns and a one-case switch).
// 0x7100885af0
bool Unk_885af0(const Unk_886f30_Self* self) {
    return self->field_1a == 4 && self->field_1c == 0x6a;
}
