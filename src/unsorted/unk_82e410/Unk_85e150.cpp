// Scope: common
// Battle event handlers (0x710085e150-0x710085e8f4): they read the event's
// variables through the handler object's leaf accessors, set others, and pass
// parameter blocks to the battle state's handler objects (Unk_85e150.h).
// Placeholder names.
#include "unsorted/unk_82e410/Unk_85e150.h"

// 0x710085e150
void Unk_85e150(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 attacker = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (attacker != pokeId)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    s32 value = Unk_85c190_Value(flow, 6);
    Unk_84d950_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = pokeId;
    arg.field_2 = Unk_7f79e0(poke, value, true);
    arg.field_4 = 0x1f;
    arg.field_5 = pokeId;
    arg.field_9 = 1;
    arg.field_a = 4;
    arg.field_c = Unk_8198c0(flow, pokeId);
    arg.field_d = 5;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_10), 2, 0x57e);
    Unk_803d60(&arg.field_10, attacker);
    Unk_803d60(&arg.field_10, Unk_819690_call(static_cast<const Unk_819690*>(self)));
    Unk_819b80(flow, arg);
}

// 0x710085e280
void Unk_85e280(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x800);
}

// 0x710085e2d0
void Unk_85e2d0(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 9);
}

// 0x710085e380
void Unk_85e380(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 10);
}

// 0x710085e430
void Unk_85e430(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 12);
}

// 0x710085e4e0
void Unk_85e4e0(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 11);
}

// 0x710085e590
void Unk_85e590(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 14);
}

// 0x710085e640
void Unk_85e640(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 1);
}

// 0x710085e6f0
void Unk_85e6f0(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 3);
}

// 0x710085e7a0
void Unk_85e7a0(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 4);
}

// 0x710085e850
void Unk_85e850(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 2);
}
