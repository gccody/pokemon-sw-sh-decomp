// Scope: common
// Battle event handlers (0x710085e900-0x710085f0fc): as in Unk_85e150.cpp.
// Placeholder names.
#include "unsorted/unk_82e410/Unk_85e150.h"

// 0x710085e900
void Unk_85e900(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 13);
}

// 0x710085e9b0
void Unk_85e9b0(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 6);
}

// 0x710085ea60
void Unk_85ea60(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 5);
}

// 0x710085eb10
void Unk_85eb10(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 7);
}

// 0x710085ebc0
void Unk_85ebc0(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 15);
}

// 0x710085ec70
void Unk_85ec70(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 16);
}

// 0x710085ed20
void Unk_85ed20(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 8);
}

// 0x710085edd0
void Unk_85edd0(void* self, u8 pokeId) {
    Unk_85e150_ScaleIfKind(self, pokeId, 17);
}

// 0x710085ee80
void Unk_85ee80(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085ef20
void Unk_85ef20(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (!Unk_81b5b0(flow, pokeId))
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x550);
    Unk_803d60(&arg.field_4, pokeId);
    Unk_803d60(&arg.field_4, Unk_819690_call(static_cast<const Unk_819690*>(self)));
    Unk_803dd0_update(reinterpret_cast<Unk_803dd0*>(&arg.field_4), 0);
    Unk_81a030(flow, arg);
}

// 0x710085efc0
void Unk_85efc0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_81c300(flow, pokeId, 0);
}

// 0x710085f010
void Unk_85f010(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_85c190_Species(Unk_8196d0(flow, pokeId)) != 0x1e7)
        return;
    u8 kind = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16);
    if (kind != 7 && kind != 0xf)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, 0x1333);
}

// 0x710085f090
void Unk_85f090(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x3e) != 3)
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x27, Unk_85c190_Value(flow, 6));
}
