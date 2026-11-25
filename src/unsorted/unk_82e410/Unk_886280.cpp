// Scope: common
// Battle event handlers (0x7100886280-0x7100886a4c): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_886280.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_886280.h"

// 0x7100886280
void Unk_886280(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_886420(self, pokeId);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x71008862e0
void Unk_8862e0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x10) ==
        Unk_819690_call(static_cast<const Unk_819690*>(self)))
        return;
    Unk_886520(self, pokeId);
}

// 0x7100886350
void Unk_886350(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_886520(self, pokeId);
}

// 0x71008863a0
void Unk_8863a0(void* self, u8 pokeId) {
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 0)
        Unk_886520(self, pokeId);
}

// 0x71008863e0
void Unk_8863e0(void* self, u8 pokeId) {
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 0)
        Unk_886420(self, pokeId);
}

// 0x71008865f0
void Unk_8865f0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) == pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16) != 10)
        return;
    u32 move = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12);
    if (Unk_7eb330(move))
        return;
    if (move == 0x1fb)
        return;
    Unk_81bd40(flow, pokeId, 1, 1);
}

// 0x7100886680
void Unk_886680(void* self, u8 pokeId) {
    u8 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    u8 kind = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x62);
    if (target == pokeId && kind == 1)
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x7100886700
void Unk_886700(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    if (Unk_81acc0(flow, pokeId)) {
        Unk_840b50_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x25e);
        Unk_803d60(&arg.field_4, pokeId);
        Unk_81a030(flow, arg);
    }
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
}

// 0x71008867b0
void Unk_8867b0(void* self, u8 pokeId) {
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (target != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) == target)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16) != 10)
        return;
    if (Unk_81bba0(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12)))
        return;
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x47, 1))
        return;
    Unk_884a50(self, pokeId, 3, 1);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x75, 1);
}

// 0x7100886890
void Unk_886890(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) == pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16) != 0xc)
        return;
    u32 move = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12);
    if (Unk_7eb330(move))
        return;
    if (move == 0x1fb)
        return;
    Unk_81bd40(flow, pokeId, 1, 2);
}

// 0x7100886920
void Unk_886920(void* self, u8 pokeId) {
    u8 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    u8 kind = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x62);
    if (target == pokeId && kind == 2)
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x71008869a0
void Unk_8869a0(void* self, u8 pokeId) {
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (target != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) == target)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16) != 0xc)
        return;
    if (Unk_81bba0(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12)))
        return;
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x47, 1))
        return;
    Unk_884a50(self, pokeId, 3, 1);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x75, 1);
}
