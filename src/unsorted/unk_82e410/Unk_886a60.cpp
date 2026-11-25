// Scope: common
// Battle event handlers (0x7100886a80-0x7100887240): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_886280.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_886280.h"

bool Unk_886f30(const Unk_886f30_Self* self);

// 0x7100886a80
void Unk_886a80(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (target != pokeId)
        return;
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1))
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x266);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x75, 1);
}

// 0x7100886b60
void Unk_886b60(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    u32 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x23);
    bool any = static_cast<u16>(value) != 0;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x23, 0);
    if (!any)
        return;
    u8 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    Unk_84d950_Arg arg;
    arg.field_4 = 0x1a;
    arg.field_0 = pokeId;
    arg.field_1 = other;
    arg.field_2 = value;
    arg.field_5 = pokeId;
    arg.field_7 = 1;
    arg.field_8 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_10), 2, 0x26a);
    Unk_803d60(&arg.field_10, other);
    Unk_819b80(flow, arg);
}

// 0x7100886c60
void Unk_886c60(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819a70_call(static_cast<const Unk_819a70*>(self));
}

// 0x7100886cc0
void Unk_886cc0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 0)
        return;
    // The predicate of 0x7100886f30, as a callback.
    Unk_819840(flow, reinterpret_cast<u64>(&Unk_886f30));
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x7100886d30
void Unk_886d30(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819850(flow);
}

// 0x7100886d70
void Unk_886d70(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_7f09c0_getField76(reinterpret_cast<const Unk_7f09c0*>(Unk_8196d0(flow, pokeId))) == 0)
        return;
    // field_1 first, as a constructor would set it (Handler.h's type has none).
    Unk_82c210_Arg arg;
    arg.field_1 = 0;
    arg.field_0 = pokeId;
    Unk_81a590(flow, arg);
}

// 0x7100886de0
void Unk_886de0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u32 move = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 2, 0);
    if (move != 0x16b)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 2,
                    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x25, 0x13));
}

// 0x7100886e60
void Unk_886e60(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (target != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 2) == 0)
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x4cc);
    Unk_803d60(&arg.field_4, target);
    Unk_803d60(&arg.field_4, Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12));
    Unk_81a030(flow, arg);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 2, 0);
}

// 0x7100886f30
bool Unk_886f30(const Unk_886f30_Self* self) {
    if (self->field_1a != 5)
        return false;
    u8 pokeId = self->field_1e;
    if (Unk_7ef4c0(Unk_7ecc90(Unk_7fe1d0_getField8(self->field_8), pokeId), 0x10))
        return false;
    if (Unk_7e9a60_getField3b(self->field_10) != pokeId)
        return false;
    u16 move = self->field_1c;
    switch (move) {
        case 0xd7:
        case 0xdf:
        case 0xe0:
        case 0xe5:
        case 0xe7:
        case 0x121:
        case 0x122:
        case 0x123:
        case 0x124:
        case 0x125:
        case 0x126:
        case 0x13f:
            return false;
    }
    if (move == 0)
        return false;
    if (self->field_18 == 0xc0 && (move == 0xdc || move == 0x11f || move == 0x129))
        return false;
    return true;
}

// 0x7100887040
void Unk_887040(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (target != pokeId)
        return;
    u32 move = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12);
    if (move != 0x19f && move != 0x10f)
        return;
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x47, 1))
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x120);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x75, 1);
}

// 0x7100887120
void Unk_887120(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x30) != 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0,
                    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1));
}

// 0x7100887190
void Unk_887190(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (target != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x29a);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
}
