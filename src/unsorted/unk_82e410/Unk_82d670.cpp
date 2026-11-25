// Scope: common
// A 0x60-byte record of a move in battle and the checks on it (the TU of
// 0x710082d680-0x710082d930). Its packed u32 at +0x54 and the move lookups
// are in Unk_82d930.cpp, which these call.
#include <string.h>
#include <types.h>

// What 0x7100803c60 clears: the record's second half.
struct Unk_803c60 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u32 field_20;
    u32 field_24;
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_803c60, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_803c60, field_24, 0x24);
PKMN_SIZE_ASSERT(Unk_803c60, 0x30);
void Unk_803c60_set(Unk_803c60* self);

struct Unk_82d680_Data {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    Unk_803c60 field_30;
};
PKMN_OFFSET_ASSERT(Unk_82d680_Data, field_30, 0x30);
PKMN_SIZE_ASSERT(Unk_82d680_Data, 0x60);

u32 Unk_82d930(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
u32 Unk_82d9a0(u32 move);

// 0x710082d680
void Unk_82d680(Unk_82d680_Data* self, const Unk_82d680_Data* other) {
    *self = *other;
}

// 0x710082d6c0
void Unk_82d6c0(Unk_82d680_Data* a, Unk_82d680_Data* b) {
    Unk_82d680_Data tmp;
    Unk_803c60_set(&tmp.field_30);
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// 0x710082d790
void Unk_82d790(Unk_82d680_Data* self) {
    memset(self, 0, sizeof(*self));
    self->field_30.field_24 = Unk_82d930(2, 5, 0, 0, 0);
}

struct Unk_7ee6b0;
struct Unk_7ee6c0;
struct Unk_7ee800;
bool Unk_7ee6c0_getField298(const Unk_7ee6c0* self);
bool Unk_7ee800_getField273(const Unk_7ee800* self);

// What Unk_82d7e0 takes: a Pokemon and a move.
struct Unk_82d7e0_Arg {
    const Unk_7ee6b0* field_0;
    u32 field_8;
    u32 _c;
    u32 field_10;
    bool field_14;
    bool field_15;
    bool field_16;
};
PKMN_OFFSET_ASSERT(Unk_82d7e0_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82d7e0_Arg, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_82d7e0_Arg, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_82d7e0_Arg, field_15, 0x15);
PKMN_OFFSET_ASSERT(Unk_82d7e0_Arg, field_16, 0x16);

// 0x710082d7e0
u32 Unk_82d7e0(const Unk_82d7e0_Arg* arg) {
    if (arg->field_8 != 1)
        return 0;
    u32 move = arg->field_10;
    if (!arg->field_15 &&
        (Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(arg->field_0)) ||
         arg->field_14 || arg->field_16))
        return Unk_82d9a0(move);
    return move;
}

// 0x710082d850
bool Unk_82d850(const Unk_82d7e0_Arg* arg) {
    if (arg->field_0 && Unk_7ee800_getField273(reinterpret_cast<const Unk_7ee800*>(arg->field_0)) &&
        arg->field_8 == 1)
        return true;
    return false;
}

// 0x710082d8a0
bool Unk_82d8a0(const Unk_82d7e0_Arg* arg) {
    if (Unk_82d850(arg) && !arg->field_15 &&
        (Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(arg->field_0)) ||
         arg->field_14 || arg->field_16))
        return true;
    return false;
}
