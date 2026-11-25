// Scope: common
// Battle event handlers (0x7100861b20-0x71008620f4): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_85c190.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_85c190.h"

u8 Unk_819810(const Unk_819600_Self* self);

// Sets variable 0x34 to 0x14cd when the event's variable 3 is `pokeId`, its
// variable 0x16 is `kind` and its value 0 is 1.
static inline void Unk_861b20_Set(void* self, u8 pokeId, u8 kind) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u8 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16);
    if (value != kind)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 1)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, 0x14cd);
}

// 0x7100861b20
void Unk_861b20(void* self, u8 pokeId) {
    Unk_861b20_Set(self, pokeId, 0);
}

// 0x7100861ba0
void Unk_861ba0(void* self, u8 pokeId) {
    Unk_861b20_Set(self, pokeId, 0x11);
}

// 0x7100861c40
void Unk_861c40(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u8 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x27) + 3;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x27, value);
}

// 0x7100861ca0
void Unk_861ca0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x68) != 1)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// Shows the effect of `pokeId` (0x7100819a10, then 0x710081a5c0).
static inline void Unk_861d10_Show(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_819a10_call(static_cast<const Unk_819a10*>(self));
    Unk_850fb0_Arg arg;
    arg.field_0 = pokeId;
    Unk_81a5c0(flow, arg);
}

// 0x7100861d10
void Unk_861d10(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 1)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 2);
    Unk_861d10_Show(self, pokeId);
}

// 0x7100861d90
void Unk_861d90(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_84a910_Arg arg;
    arg.field_0 = pokeId;
    arg.field_2 = pokeId;
    arg.field_1 = 1;
    arg.field_8 = 5;
    arg.field_c = 1;
    arg.field_e = Unk_819690_call(static_cast<const Unk_819690*>(self));
    if (!Unk_819df0(flow, arg))
        return;
    Unk_856020_Arg message;
    message.field_0 = pokeId;
    message.field_1 = 1;
    message.field_3 = 1;
    Unk_81a640(flow, message);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// Shows the effect of `pokeId` when the event's variable 2 is `pokeId` and
// 0x7100819810 gives `kind`.
static inline void Unk_861e70_Show(void* self, u8 pokeId, u8 kind) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819810(flow) != kind)
        return;
    Unk_861d10_Show(self, pokeId);
}

// Shows the effect of `pokeId` when the event's variable 0x66 is `kind`.
static inline void Unk_861ee0_Show(void* self, u8 pokeId, u32 kind) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x66) != kind)
        return;
    Unk_861d10_Show(self, pokeId);
}

// 0x7100861e70
void Unk_861e70(void* self, u8 pokeId) {
    Unk_861e70_Show(self, pokeId, 3);
}

// 0x7100861ee0
void Unk_861ee0(void* self, u8 pokeId) {
    Unk_861ee0_Show(self, pokeId, 3);
}

// 0x7100861f50
// NON_MATCHING: the original takes a u8 (it keeps w1, `mov w20, w1`); the
// placeholder name's u64 keeps x1.
void Unk_861f50(void* self, u64 value, u32 kind) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u8 pokeId = value;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    {
        Unk_84a910_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        arg.field_2 = pokeId;
        arg.field_8 = kind;
        arg.field_c = 1;
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

// 0x7100862030
void Unk_862030(void* self, u8 pokeId) {
    Unk_861e70_Show(self, pokeId, 4);
}

// 0x71008620a0
void Unk_8620a0(void* self, u8 pokeId) {
    Unk_861ee0_Show(self, pokeId, 4);
}
