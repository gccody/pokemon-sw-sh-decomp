// Scope: common
// Battle event handlers (0x710086e460-0x710086ec94): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_86dd10.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_86dd10.h"

// 0x710086e460
void Unk_86e460(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x14) !=
        Unk_819690_call(static_cast<const Unk_819690*>(self)))
        return;
    u8 type;
    switch (Unk_86dd10_Item(Unk_8196d0(flow, pokeId))) {
        case 0x390:
            type = 9;
            break;
        case 0x388:
            type = 1;
            break;
        case 0x389:
            type = 2;
            break;
        case 0x38a:
            type = 3;
            break;
        case 0x38b:
            type = 4;
            break;
        case 0x38c:
            type = 5;
            break;
        case 0x38d:
            type = 6;
            break;
        case 0x38e:
            type = 7;
            break;
        case 0x38f:
            type = 8;
            break;
        case 0x391:
            type = 0xa;
            break;
        case 0x392:
            type = 0xb;
            break;
        case 0x393:
            type = 0xc;
            break;
        case 0x394:
            type = 0xd;
            break;
        case 0x395:
            type = 0xe;
            break;
        case 0x396:
            type = 0xf;
            break;
        case 0x397:
            type = 0x10;
            break;
        case 0x398:
            type = 0x11;
            break;
        default:
            type = 0;
            break;
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x12, Unk_82da30(type));
}

// 0x710086e5a0
void Unk_86e5a0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (!Unk_81bfc0(flow, pokeId))
        return;
    u32 type = 0;
    u8 kind = 0;
    switch (Unk_86dd10_Item(Unk_8196d0(flow, pokeId))) {
        case 0x74:
            kind = 1;
            type = 0xa;
            break;
        case 0x75:
            kind = 2;
            type = 0xc;
            break;
        case 0x76:
            kind = 3;
            type = 9;
            break;
        case 0x77:
            kind = 4;
            type = 0xe;
            break;
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x16, type);
    Unk_8643c0_Arg arg;
    arg.field_0 = kind;
    Unk_81aab0(flow, arg);
}

// 0x710086e690
void Unk_86e690(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x14) !=
        Unk_819690_call(static_cast<const Unk_819690*>(self)))
        return;
    u8 type;
    switch (Unk_86dd10_Item(Unk_8196d0(flow, pokeId))) {
        case 0x74:
            type = 0xa;
            break;
        case 0x75:
            type = 0xc;
            break;
        case 0x76:
            type = 9;
            break;
        case 0x77:
            type = 0xe;
            break;
        default:
            type = 0;
            break;
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x12, Unk_82da30(type));
}

// 0x710086e740
void Unk_86e740(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x16, Unk_81b7a0(flow, pokeId));
}

// 0x710086e7a0
void Unk_86e7a0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u32 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (Unk_86dd10_Item(Unk_8196d0(flow, other)) == 0)
        return;
    if (Unk_81b100(flow, pokeId, other))
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, 0x1800);
}

// 0x710086e830
void Unk_86e830(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    if (target != pokeId)
        return;
    u8 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 6);
    if (Unk_81b100(flow, pokeId, other))
        return;
    u16 item = Unk_86dd10_Item(Unk_8196d0(flow, other));
    if (item == 0)
        return;
    Unk_838f90_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = other;
    arg.field_2 = 0;
    Unk_840b50_List* list = &arg.field_c;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(list), 2, 0x58e);
    Unk_803d60(list, target);
    Unk_803d60(list, other);
    Unk_803d60(list, item);
    Unk_81a510(flow, arg);
}

// 0x710086e930
void Unk_86e930(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (static_cast<u8>(target) == pokeId) {
        if (!Unk_81ae20(flow, pokeId))
            return;
        if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12) !=
            Unk_819690_call(static_cast<const Unk_819690*>(self)))
            return;
        Unk_819650_call(static_cast<const Unk_819650*>(self), 0x27);
    } else if (!Unk_8197f0_call(static_cast<const Unk_8197f0*>(self), pokeId, target)) {
        Unk_81b230(self, pokeId);
    }
}

// 0x710086e9d0
void Unk_86e9d0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    if (target != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 6) != 0)
        return;
    {
        Unk_840b50_Arg arg;
        arg.field_0 = pokeId;
        Unk_840b50_List* list = &arg.field_4;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(list), 2, 0x402);
        Unk_803d60(list, target);
        Unk_81a030(flow, arg);
    }
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 6, 1);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x78, 1);
}

// 0x710086eaa0
void Unk_86eaa0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 1))
        Unk_81b430(flow, pokeId);
}

// 0x710086eb00
void Unk_86eb00(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_8196c0_call(static_cast<const Unk_8196c0*>(self));
}

// 0x710086eb50
void Unk_86eb50(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    if (target != pokeId)
        return;
    if (!Unk_81b8d0(flow, pokeId))
        return;
    u8 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 6);
    if (other == 0x1f)
        return;
    const Unk_7ee6b0* poke = Unk_8196d0(flow, other);
    if (Unk_86dd10_Item(poke) == 0)
        return;
    if (Unk_81b100(flow, pokeId, other))
        return;
    {
        Unk_854b80_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = other;
        arg.field_2 = 1;
        Unk_840b50_List* list = &arg.field_4;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(list), 2, 0x598);
        Unk_803d60(list, target);
        Unk_803d60(list, other);
        Unk_803d60(list, Unk_86dd10_Item(poke));
        if (!Unk_81a550(flow, arg))
            return;
    }
    Unk_8643c0_Arg arg;
    arg.field_0 = 1;
    Unk_81aab0(flow, arg);
}
