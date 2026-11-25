// Scope: common
// Battle event handlers (0x710085f100-0x710085f940): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_85c190.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_85c190.h"

// 0x7100819d00's parameter block (as in battle/battle_engine/Unk_819bc0.cpp,
// whose u16 at +0x12 is two bytes here: these handlers set the one at +0x13).
struct Unk_836520_Arg {
    u8 field_0 = 0x1f;
    u8 field_1 = 0x1f;
    u32 field_4 = 0;
    u64 field_8 = 0;
    u8 field_10 = 0;
    u8 field_11 = 0;
    u8 field_12 = 0;
    u8 field_13 = 0;
    u32 field_14 = 1;
    Unk_23acc98_Message field_18;

    Unk_836520_Arg() { Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_18)); }
};
PKMN_SIZE_ASSERT(Unk_836520_Arg, 0x40);
PKMN_OFFSET_ASSERT(Unk_836520_Arg, field_13, 0x13);
PKMN_OFFSET_ASSERT(Unk_836520_Arg, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_836520_Arg, field_18, 0x18);
bool Unk_819d00(const Unk_819600_Self* self, const Unk_836520_Arg& arg);

u64 Unk_7f88a0(u8 index);
// Named with one parameter (_Z10Unk_7f78c0j), but 0x71007f78c0 takes a kind
// (w0) and a Pokemon (w1, as 0x71007f88a0's).
u64 Unk_7f78c0(u32 kind, u8 index);

// Sets variable 0x27 to 0x7100819690's value 6, when the event's variable
// 0x3e is `kind`.
static inline void Unk_85f100_Set(void* self, u8 pokeId, u32 kind) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x3e) != kind)
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x27, Unk_85c190_Value(flow, 6));
}

// 0x710085f100
void Unk_85f100(void* self, u8 pokeId) {
    Unk_85f100_Set(self, pokeId, 4);
}

// 0x710085f170
void Unk_85f170(void* self, u8 pokeId) {
    Unk_85f100_Set(self, pokeId, 1);
}

// 0x710085f1e0
void Unk_85f1e0(void* self, u8 pokeId) {
    Unk_85f100_Set(self, pokeId, 2);
}

// 0x710085f250
void Unk_85f250(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_85c190_Species(Unk_8196d0(flow, pokeId)) == 0x19)
        Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x2000);
}

// NON_MATCHING: calls Unk_7f78c0 with its two parameters; its name
// (_Z10Unk_7f78c0j) has one.
// 0x710085f2c0
void Unk_85f2c0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u8 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    Unk_836520_Arg arg;
    arg.field_0 = other;
    arg.field_1 = pokeId;
    arg.field_4 = 1;
    arg.field_8 = Unk_7f78c0(1, other);
    if (Unk_819d00(flow, arg))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// 0x710085f370
void Unk_85f370(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (target != pokeId)
        return;
    Unk_836520_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = pokeId;
    arg.field_4 = 5;
    arg.field_8 = Unk_7f88a0(pokeId);
    arg.field_13 = 0;
    Unk_840b50_List* list = reinterpret_cast<Unk_840b50_List*>(&arg.field_18);
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(list), 2, 0x148);
    Unk_803d60(list, target);
    Unk_803d60(list, Unk_819690_call(static_cast<const Unk_819690*>(self)));
    Unk_819d00(flow, arg);
}

// 0x710085f440
void Unk_85f440(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u8 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    Unk_836520_Arg arg;
    arg.field_0 = other;
    arg.field_1 = pokeId;
    arg.field_4 = 5;
    arg.field_8 = Unk_7f88a0(other);
    if (Unk_819d00(flow, arg))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// NON_MATCHING: calls Unk_7f78c0 with its two parameters; its name
// (_Z10Unk_7f78c0j) has one.
// 0x710085f4f0
void Unk_85f4f0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (target != pokeId)
        return;
    Unk_836520_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = pokeId;
    arg.field_4 = 4;
    arg.field_8 = Unk_7f78c0(4, pokeId);
    arg.field_13 = 0;
    Unk_840b50_List* list = reinterpret_cast<Unk_840b50_List*>(&arg.field_18);
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(list), 2, 0x160);
    Unk_803d60(list, target);
    Unk_803d60(list, Unk_819690_call(static_cast<const Unk_819690*>(self)));
    Unk_819d00(flow, arg);
}

// NON_MATCHING: calls Unk_7f78c0 with its two parameters; its name
// (_Z10Unk_7f78c0j) has one.
// 0x710085f5c0
void Unk_85f5c0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u8 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    Unk_836520_Arg arg;
    arg.field_0 = other;
    arg.field_1 = pokeId;
    arg.field_4 = 4;
    arg.field_8 = Unk_7f78c0(4, other);
    if (Unk_819d00(flow, arg))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// NON_MATCHING: calls Unk_7f78c0 with its two parameters; its name
// (_Z10Unk_7f78c0j) has one.
// 0x710085f680
void Unk_85f680(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u8 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    Unk_836520_Arg arg;
    arg.field_0 = other;
    arg.field_1 = pokeId;
    arg.field_4 = 5;
    arg.field_8 = Unk_7f78c0(5, other);
    if (Unk_819d00(flow, arg))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// Raises variable 0x34 by the percentage of 0x7100819690's value 6, when the
// event's variable 0x16 is `type`.
static inline void Unk_85f100_Boost(void* self, u8 pokeId, u8 type) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16)) != type)
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085f730
void Unk_85f730(void* self, u8 pokeId) {
    Unk_85f100_Boost(self, pokeId, 0);
}

// 0x710085f7e0
void Unk_85f7e0(void* self, u8 pokeId) {
    Unk_85f100_Boost(self, pokeId, 0xd);
}

// 0x710085f890
void Unk_85f890(void* self, u8 pokeId) {
    Unk_85f100_Boost(self, pokeId, 5);
}
