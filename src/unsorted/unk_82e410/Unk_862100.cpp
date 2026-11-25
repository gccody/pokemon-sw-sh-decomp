// Scope: common
// Battle event handlers (0x7100862110-0x7100862794): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_85c190.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_85c190.h"

u8 Unk_819810(const Unk_819600_Self* self);
bool Unk_819970(const Unk_819600_Self* self, u32 effect);
void Unk_8627f0(void* self, u8 pokeId);

// Shows the effect of `pokeId` (0x7100819a10, then 0x710081a5c0).
static inline void Unk_862110_Show(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_819a10_call(static_cast<const Unk_819a10*>(self));
    Unk_850fb0_Arg arg;
    arg.field_0 = pokeId;
    Unk_81a5c0(flow, arg);
}

// Shows the effect of `pokeId` when the event's variable 2 is `pokeId` and
// 0x7100819810 gives `kind`.
static inline void Unk_862110_ShowKind(void* self, u8 pokeId, u8 kind) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819810(flow) != kind)
        return;
    Unk_862110_Show(self, pokeId);
}

// Shows the effect of `pokeId` when the event's variable 0x66 is `kind`.
static inline void Unk_862180_Show(void* self, u8 pokeId, u32 kind) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x66) != kind)
        return;
    Unk_862110_Show(self, pokeId);
}

// 0x7100862110
void Unk_862110(void* self, u8 pokeId) {
    Unk_862110_ShowKind(self, pokeId, 2);
}

// 0x7100862180
void Unk_862180(void* self, u8 pokeId) {
    Unk_862180_Show(self, pokeId, 2);
}

// 0x71008621f0
void Unk_8621f0(void* self, u8 pokeId) {
    Unk_862110_ShowKind(self, pokeId, 1);
}

// 0x7100862260
void Unk_862260(void* self, u8 pokeId) {
    Unk_862180_Show(self, pokeId, 1);
}

// 0x71008622d0
void Unk_8622d0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819970(flow, 1))
        Unk_862110_Show(self, pokeId);
}

// 0x7100862340
void Unk_862340(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819970(flow, 1))
        Unk_862110_Show(self, pokeId);
}

// 0x7100862390
void Unk_862390(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    {
        Unk_84a910_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        arg.field_2 = pokeId;
        arg.field_8 = 5;
        arg.field_c = 0xff;
        arg.field_e = Unk_819690_call(static_cast<const Unk_819690*>(self));
        if (!Unk_819df0(flow, arg))
            return;
    }
    Unk_856020_Arg message;
    message.field_0 = pokeId;
    message.field_1 = 1;
    message.field_3 = 1;
    Unk_81a640(flow, message);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// 0x7100862540
void Unk_862540(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) == pokeId)
        Unk_8627f0(self, pokeId);
}

// 0x7100862590
void Unk_862590(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    u8 attacker = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    u8 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (attacker == target)
        return;
    u8 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x6b);
    if (static_cast<u8>(value - 1) < 3)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1);
}

// 0x7100862620
void Unk_862620(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    bool flag;
    switch (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x68))) {
        case 2:
            flag = true;
            break;
        case 3:
            flag = false;
            break;
        default:
            return;
    }
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1))
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, flag);
}

// 0x71008626c0
void Unk_8626c0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_8627f0(self, pokeId);
}

// The event's variable 0x6c, a byte.
enum class Unk_862710_Kind : u8 {};

// 0x7100862710
void Unk_862710(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    switch (
        static_cast<Unk_862710_Kind>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x6c))) {
        case Unk_862710_Kind(1):
        case Unk_862710_Kind(2):
            break;
        default:
            return;
    }
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1))
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, 1);
}

// 0x7100862470
// NON_MATCHING: clang folds `stage < 0` into the switch's cases (a 0/1 per
// case); the original keeps the -3..1 value and compares it (`cmp x20, #1`,
// `cset hi`) after 0x7100819640.
void Unk_862470(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    s64 stage;
    switch (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x69))) {
        case 6:
            stage = 0;
            break;
        case 0x14:
            stage = -3;
            break;
        case 0x15:
            stage = -2;
            break;
        case 0x16:
            stage = -1;
            break;
        case 0x20:
            stage = 1;
            break;
        default:
            return;
    }
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 0))
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, stage < 0);
}
