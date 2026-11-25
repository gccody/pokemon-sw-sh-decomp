// Scope: common
// Battle event handlers (0x7100880870-0x7100880c80): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp) and set others. Placeholder names.
#include "unsorted/unk_82e410/Unk_880840.h"

u8 Unk_81a350(const Unk_819600_Self* self, u8 arg);
Unk_7ee6b0* Unk_8196d0(const Unk_819600_Self* self, u8 pokeId);
u8 Unk_819a80(const Unk_819600_Self* self, u8 arg);
u8 Unk_819ac0(const Unk_819600_Self* self, u8 arg);
bool Unk_7ef4c0(const Unk_7ee6b0* object, u32 index);
bool Unk_7f7db0(u8 value);
bool Unk_7f7c40(s32 condition);
u16 Unk_803c00(u32 kind);
void Unk_8806b0(void* self, u8 pokeId, u8 arg2, u32 arg3);
// Named (void*, u64, u32); the code below gives it a u8 and a u16.
void Unk_8810e0(void* self, u8 pokeId, u16 value);

// 0x7100880870
void Unk_880870(void* self, u8 pokeId) {
    Unk_8806b0(self, pokeId, pokeId, 0x110);
}

// 0x71008808a0
void Unk_8808a0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x22) == 9)
        return;
    u32 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x23);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x23, value * 2);
}

// 0x7100880930
void Unk_880930(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    if (!Unk_7f7db0(Unk_81a350(flow, pokeId)))
        return;
    u32 condition = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x1e);
    bool match = Unk_7f7c40(condition);
    if (condition == 0xe || match) {
        bool set = Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1);
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, set);
    }
}

// 0x71008809c0
void Unk_8809c0(void* self, u8 pokeId) {
    u16 value = 0x120;
    if (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x6b)) == 5) {
        s16 kind = Unk_803c00(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x1e));
        if (kind >= 0)
            value = kind;
    }
    Unk_8810e0(self, pokeId, value);
}

// 0x7100880a30
void Unk_880a30(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_7f7db0(Unk_81a350(flow, pokeId)))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1);
}

// 0x7100880ab0
void Unk_880ab0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, Unk_81b7e0(flow, pokeId, 1));
}

// 0x7100880b40
void Unk_880b40(void* self, u8 pokeId, u32 index) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (!Unk_7ef4c0(Unk_8196d0(flow, pokeId), index))
        return;
    Unk_819a80(flow, pokeId);
    Unk_880b40_Arg arg;
    arg.field_0 = pokeId;
    arg.field_8 = pokeId;
    arg.field_26 = 1;
    arg.field_4 = index;
    Unk_819c80(flow, &arg);
    Unk_819ac0(flow, pokeId);
}

// 0x7100880c10
void Unk_880c10(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, Unk_81b7e0(flow, pokeId, 2));
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, Unk_81b7e0(flow, pokeId, 0xe));
}
