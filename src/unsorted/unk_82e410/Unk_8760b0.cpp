// Scope: common
// Battle event handlers (0x71008760b0-0x71008768a8): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_8758d0.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_8758d0.h"

// Defined as void; they return what their tail calls give.
Unk_840b50_List* Unk_819680_call(const Unk_819680* self, u32 value);
struct Unk_819830;
struct Unk_819830_Value {
    u16 field_0;
    u16 field_2;
};
const Unk_819830_Value* Unk_819830_call(const Unk_819830* self);

u8 Unk_819810(const Unk_819600_Self* self);
u8 Unk_8198c0(const Unk_819600_Self* self, u8 pokeId);
u8 Unk_81ab90(const Unk_819600_Self* self, u8 pokeId, u32 move);
struct Unk_7f0b70;
bool Unk_7f0b70_check(const Unk_7f0b70* self);
bool Unk_7ef5d0(Unk_7ee6b0* self, u32 flag);
struct Unk_7efe00;
u8 Unk_7efe00_getField33c(const Unk_7efe00* self);
// Named (void*, u32); it takes a u8 (0x71007efef0 masks w1), and
// 0x71008765e0 passes it unextended.
u32 Unk_7efef0(void* object, u8 index);
bool Unk_7eb780(u16 move);
bool Unk_7eb890(u16 move);
bool Unk_780c30(u32 move);
bool Unk_780c60(u32 move, u32 kind);
u32 Unk_7f7690(u32 count);
struct Unk_7eba90;
const u32* Unk_7eba90_update(Unk_7eba90* self);
bool Unk_82d990_call(u32 self);
u64 Unk_7f87c0(u8 index, u8 b, u16 c);
void Unk_7f8a20(u64* self, bool value);

// The moves 0x7100876720 reads from the battle state (+0x8).
struct Unk_7fe370;
struct Unk_876720_Moves {
    u32 field_0;
    u32 _4;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_876720_Moves, field_8, 0x8);
// Defined as returning a pointer.
const Unk_876720_Moves& Unk_7fe370_getField2e8Ptr(Unk_7fe370* self);

// What 0x7100876270 gives Unk_81a060: a Pokemon and a value.
struct Unk_8565c0_arg2 {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_8565c0_arg2, field_4, 0x4);
PKMN_SIZE_ASSERT(Unk_8565c0_arg2, 0x8);
u8 Unk_81a060(const Unk_819600_Self* self, const Unk_8565c0_arg2* arg);

// What 0x7100876270 gives Unk_81aa40, with a message list at +0x8.
struct Unk_856990_Arg {
    u16 field_0;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    Unk_840b50_List field_8;

    Unk_856990_Arg()
        : field_0(0), field_2(5), field_3(5), field_4(0), field_5(0), field_6(0), field_7(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_8));
    }
};
PKMN_OFFSET_ASSERT(Unk_856990_Arg, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_856990_Arg, field_7, 0x7);
PKMN_OFFSET_ASSERT(Unk_856990_Arg, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_856990_Arg, 0x2c);
void Unk_81aa40(const Unk_819600_Self* self, const Unk_856990_Arg& arg);

// As in Unk_8798c0.h: the parameter block of 0x7100836520 (through
// Unk_819d00), with +0x14 split into bytes (0x71008761c0 sets +0x15 as a
// byte) and a message list at +0x18.
struct Unk_836520_Arg {
    u8 field_0 = 0x1f;
    u8 field_1 = 0x1f;
    u32 field_4 = 0;
    u64 field_8 = 0;
    u8 field_10 = 0;
    u8 field_11 = 0;
    u16 field_12 = 0;
    u8 field_14 = 1;
    u8 field_15 = 0;
    u16 field_16 = 0;
    Unk_840b50_List field_18;

    Unk_836520_Arg() { Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_18)); }
};
PKMN_SIZE_ASSERT(Unk_836520_Arg, 0x40);
PKMN_OFFSET_ASSERT(Unk_836520_Arg, field_15, 0x15);
PKMN_OFFSET_ASSERT(Unk_836520_Arg, field_18, 0x18);
bool Unk_819d00(const Unk_819600_Self* self, const Unk_836520_Arg& arg);

// 0x71008760b0
void Unk_8760b0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0xc) == 6)
        return;
    Unk_857530_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 0x12;
    Unk_81a120(flow, arg);
    Unk_8196c0_call(static_cast<const Unk_8196c0*>(self));
}

// 0x7100876120
void Unk_876120(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_856390_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 8;
    Unk_81a0e0(flow, arg);
}

// 0x7100876170
void Unk_876170(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_856390_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 7;
    Unk_81a0e0(flow, arg);
}

// 0x71008761c0
void Unk_8761c0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_836520_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = pokeId;
    arg.field_15 = 1;
    arg.field_4 = 0x19;
    arg.field_8 = Unk_7f87c0(pokeId, 1, 2);
    Unk_7f8a20(&arg.field_8, true);
    Unk_819d00(flow, arg);
}

// 0x7100876270
void Unk_876270(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (target != pokeId)
        return;
    {
        Unk_8565c0_arg2 arg;
        arg.field_0 = pokeId;
        arg.field_4 = 5;
        Unk_81a060(flow, &arg);
    }
    if (!Unk_7f0b70_check(reinterpret_cast<const Unk_7f0b70*>(Unk_8196d0(flow, pokeId)))) {
        Unk_856990_Arg arg;
        arg.field_0 = 0x42;
        arg.field_2 = Unk_8198c0(flow, pokeId);
        arg.field_3 = 5;
        arg.field_7 = 1;
        Unk_81aa40(flow, arg);
    }
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x33e);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
}

// 0x7100876370
void Unk_876370(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u32 count = 0;
    const u32* moves = Unk_7eba90_update(reinterpret_cast<Unk_7eba90*>(&count));
    u32 move = moves[Unk_7f7690(count)];
    u8 result = Unk_81ab90(flow, pokeId, move);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x12, move);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0xd, result);
}

// 0x7100876400
void Unk_876400(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u32 move = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12);
    Unk_840b50_List* list = Unk_819680_call(static_cast<const Unk_819680*>(self), 0x44);
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(list), 1, 0x89);
    Unk_803d60(list, move);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 1);
}

// 0x7100876490
void Unk_876490(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u32 move;
    switch (Unk_819810(flow)) {
        case 1:
            move = 0x19c;
            break;
        case 2:
            move = 0x249;
            break;
        case 3:
            move = 0x55;
            break;
        case 4:
            move = 0x5e;
            break;
        default:
            move = Unk_819830_call(static_cast<const Unk_819830*>(self))->field_2;
            break;
    }
    u8 result = Unk_819600_call(static_cast<const Unk_819600*>(self), 0xe);
    if (result == 5)
        result = Unk_81ab90(flow, pokeId, move);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x12, move);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0xd, result);
}

// 0x7100876560
void Unk_876560(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_840b50_List* list = Unk_819680_call(static_cast<const Unk_819680*>(self), 0x44);
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(list), 1, 0x8a);
    Unk_803d60(list, Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12));
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 1);
}

// 0x71008765e0
void Unk_8765e0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (!Unk_7ef5d0(poke, 1))
        return;
    u8 n = Unk_7efe00_getField33c(reinterpret_cast<const Unk_7efe00*>(poke));
    u32 moves[4];
    u8 count = 0;
    for (u8 i = 0; i < n; i++) {
        u32 move = Unk_7efef0(poke, i);
        if (Unk_7eb780(move))
            continue;
        if (!Unk_780c30(move))
            continue;
        if (Unk_780c60(move, 1))
            continue;
        moves[count++] = move;
    }
    if (count == 0) {
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1);
        return;
    }
    u32 move = moves[static_cast<u8>(Unk_7f7690(count))];
    u8 result = Unk_81ab90(flow, pokeId, move);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x12, move);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0xd, result);
}

// 0x7100876720
void Unk_876720(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    const Unk_876720_Moves& moves = Unk_7fe370_getField2e8Ptr(
        reinterpret_cast<Unk_7fe370*>(const_cast<Unk_7fe1d0*>(flow->field_8)));
    u32 first = moves.field_0;
    u32 move = Unk_82d990_call(first) ? moves.field_8 : first;
    if (move == 0)
        return;
    if (Unk_7eb890(move))
        return;
    u8 result = Unk_81ab90(flow, pokeId, move);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x12, move);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0xd, result);
}

// 0x71008767d0
void Unk_8767d0(void* self, u8 pokeId) {
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (target != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != target)
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x22, 0xa);
}

// 0x7100876840
void Unk_876840(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_7ef4c0(Unk_8196d0(flow, Unk_819600_call(static_cast<const Unk_819600*>(self), 4)), 5))
        Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, 0x2000);
}
