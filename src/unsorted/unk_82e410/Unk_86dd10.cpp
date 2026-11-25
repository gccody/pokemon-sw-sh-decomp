// Scope: common
// Battle event handlers (0x710086dd10-0x710086e440): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_86dd10.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_86dd10.h"

// 0x710086dd10
void Unk_86dd10(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u8 kind;
    u8 weather = Unk_81a350(flow, pokeId);
    u32 type = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16);
    switch (weather) {
        case 1:
        case 6:
            kind = 1;
            type = 9;
            break;
        case 2:
        case 5:
            kind = 4;
            type = 0xa;
            break;
        case 3:
            kind = 2;
            type = 0xe;
            break;
        case 4:
            kind = 3;
            type = 5;
            break;
        default:
            kind = 0;
            type = 0;
            break;
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x16, type);
    Unk_8643c0_Arg arg;
    arg.field_0 = kind;
    Unk_81aab0(flow, arg);
}

// 0x710086dde0
void Unk_86dde0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_81a350(flow, pokeId) == 0)
        return;
    if (Unk_81a350(flow, pokeId) == 7)
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x33,
                    Unk_819600_call(static_cast<const Unk_819600*>(self), 0x33) * 2);
}

// 0x710086de70
void Unk_86de70(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x14) !=
        Unk_819690_call(static_cast<const Unk_819690*>(self)))
        return;
    u8 type;
    switch (Unk_81a350(flow, pokeId)) {
        case 1:
            type = 9;
            break;
        case 2:
            type = 0xa;
            break;
        case 3:
            type = 0xe;
            break;
        case 4:
            type = 5;
            break;
        case 5:
            type = 0xa;
            break;
        case 6:
            type = 9;
            break;
        default:
            type = 0;
            break;
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x12, Unk_82da30(type));
}

// 0x710086df20
void Unk_86df20(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x24) == 3)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x49, 0);
}

// 0x710086df80
void Unk_86df80(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_7f05a0(Unk_8196d0(flow, Unk_819600_call(static_cast<const Unk_819600*>(self), 4)), 3))
        Unk_81b500(flow, 2);
}

// 0x710086dff0
void Unk_86dff0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x24) == 3)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x49, 0);
}

// 0x710086e050
void Unk_86e050(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_7f7dd0(Unk_81a350(flow, Unk_819600_call(static_cast<const Unk_819600*>(self), 4))))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 1);
}

// 0x710086e0c0
void Unk_86e0c0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_7f7db0(Unk_81a350(flow, pokeId)))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x2e, 0x32);
}

// 0x710086e120
void Unk_86e120(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_81a310(flow) == 3)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 1);
}

// 0x710086e180
void Unk_86e180(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 3)) != pokeId)
        return;
    if (!Unk_7f0670(Unk_8196d0(flow, pokeId), 0xe))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x2e, 0x14);
}

// 0x710086e1f0
void Unk_86e1f0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x24) == 5)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x49, 0);
}

// 0x710086e250
void Unk_86e250(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_7f05a0(Unk_8196d0(flow, Unk_819600_call(static_cast<const Unk_819600*>(self), 4)), 5))
        Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x2000);
}

// 0x710086e2c0
void Unk_86e2c0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (!Unk_81bfc0(flow, pokeId))
        return;
    u32 type = 0;
    switch (Unk_86dd10_Item(Unk_8196d0(flow, pokeId))) {
        case 0x12a:
            type = 9;
            break;
        case 0x12b:
            type = 0xa;
            break;
        case 0x12c:
            type = 0xc;
            break;
        case 0x12d:
            type = 0xb;
            break;
        case 0x12e:
            type = 0xe;
            break;
        case 0x12f:
            type = 1;
            break;
        case 0x130:
            type = 3;
            break;
        case 0x131:
            type = 4;
            break;
        case 0x132:
            type = 2;
            break;
        case 0x133:
            type = 0xd;
            break;
        case 0x134:
            type = 6;
            break;
        case 0x135:
            type = 5;
            break;
        case 0x136:
            type = 7;
            break;
        case 0x137:
            type = 0xf;
            break;
        case 0x138:
            type = 0x10;
            break;
        case 0x139:
            type = 8;
            break;
        case 0x284:
            type = 0x11;
            break;
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x16, type);
}

// 0x710086e3e0
void Unk_86e3e0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (!Unk_81bfc0(flow, pokeId))
        return;
    u32 value;
    switch (Unk_86dd10_Item(Unk_8196d0(flow, pokeId))) {
        case 0x388:
            value = 1;
            break;
        case 0x389:
            value = 2;
            break;
        case 0x38a:
            value = 3;
            break;
        case 0x38b:
            value = 4;
            break;
        case 0x38c:
            value = 5;
            break;
        case 0x38d:
            value = 6;
            break;
        case 0x38e:
            value = 7;
            break;
        case 0x38f:
            value = 8;
            break;
        case 0x390:
            value = 9;
            break;
        case 0x391:
            value = 0xa;
            break;
        case 0x392:
            value = 0xb;
            break;
        case 0x393:
            value = 0xc;
            break;
        case 0x394:
            value = 0xd;
            break;
        case 0x395:
            value = 0xe;
            break;
        case 0x396:
            value = 0xf;
            break;
        case 0x397:
            value = 0x10;
            break;
        case 0x398:
            value = 0x11;
            break;
        default:
            value = 0;
            break;
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x16, value);
}
