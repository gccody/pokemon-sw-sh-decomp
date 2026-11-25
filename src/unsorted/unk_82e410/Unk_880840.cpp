// Scope: common
// Battle event handlers (0x7100880870-0x7100880c80): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp) and set others. Placeholder names.
#include "battle/battle_engine/Unk_81b200.h"

// The leaf accessors of the event variables, each with its own placeholder
// type for the handler object.
struct Unk_819600;
struct Unk_819640;
struct Unk_8196a0;
struct Unk_8196b0;
u32 Unk_819600_call(const Unk_819600* self, u32 value);
bool Unk_819640_call(const Unk_819640* self, u32 value, u32 arg2);
u32 Unk_8196a0_call(const Unk_8196a0* self, u32 value);
void Unk_8196b0_call(const Unk_8196b0* self, u32 value, u32 arg2);

bool Unk_81b7e0(const Unk_819600_Self* self, u8 pokeId, u32 value);
u8 Unk_81a350(const Unk_819600_Self* self, u8 arg);
Unk_7ee6b0* Unk_8196d0(const Unk_819600_Self* self, u8 pokeId);
u8 Unk_819a80(const Unk_819600_Self* self, u8 arg);
u8 Unk_819ac0(const Unk_819600_Self* self, u8 arg);
u8 Unk_819c80(const Unk_819600_Self* self, const void* arg);
bool Unk_7ef4c0(const Unk_7ee6b0* object, u32 index);
bool Unk_7f7db0(u8 value);
bool Unk_7f7c40(s32 condition);
u16 Unk_803c00(u32 kind);
struct Unk_803c60;
void Unk_803c60_set(Unk_803c60* self);
void Unk_8806b0(void* self, u8 pokeId, u8 arg2, u32 arg3);
// Named (void*, u64, u32); the code below gives it a u8 and a u16.
void Unk_8810e0(void* self, u64 pokeId, u32 value);

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

// NON_MATCHING: Unk_8810e0 is named (void*, u64, u32), so the u8 and the u16
// are extended (and the registers swap). Matches as (void*, u8, u16).
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

// What 0x7100880b40 gives Unk_819c80.
struct Unk_880b40_Arg {
    u8 field_0;
    u8 _1[3];
    u32 field_4;
    u8 field_8;
    u8 field_9[0x1d];
    u8 field_26;
    u8 _27;
    u32 field_28;
    Unk_23acc98_Message field_2c;

    Unk_880b40_Arg()
        : field_0(0x1f), field_4(0x2d), field_8(0), field_9(), field_26(0), field_28(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_2c));
    }
};
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_26, 0x26);
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_2c, 0x2c);
PKMN_SIZE_ASSERT(Unk_880b40_Arg, 0x50);

// NON_MATCHING: named (void*, u64, u32): the u64 is kept in x19 (mov x19, x1
// for mov w19, w1). Matches as (void*, u8, u32).
// 0x7100880b40
void Unk_880b40(void* self, u64 pokeId, u32 index) {
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
