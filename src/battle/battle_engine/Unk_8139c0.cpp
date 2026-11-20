// Scope: common
// The battle server's commands: each looks up what it acts on through the
// main module and calls one of its member functions (0x71008139c0 to
// 0x7100818810). Placeholder names: rename once the functions are known.
#include "battle/battle_engine/Unk_8139c0.h"

// 0x7100816910
void Unk_816910(Unk_816910_List* self, u8 value) {
    self->field_8[self->field_0++] = value;
}

// 0x7100816aa0
void Unk_816aa0(const Unk_8139c0_Self* self, u8 pokeId, u32 index, u8 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f26d0(poke, index, value);
}

// 0x7100816af0
void Unk_816af0(const Unk_8139c0_Self* self, u8 pokeId, u8 index, u32 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2700(poke, index, value);
}

// 0x7100816b40
void Unk_816b40(const Unk_8139c0_Self* self, u8 pokeId, u8 index, u32 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2720(poke, index, value);
}

// 0x7100816bc0
void Unk_816bc0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    if (poke != nullptr)
        Unk_7ef2e0_set(reinterpret_cast<Unk_7ef2e0*>(poke));
}

// 0x7100816c80
void Unk_816c80(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f13d0_clearField74(reinterpret_cast<Unk_7f13d0*>(Unk_8139c0_Poke(self, pokeId)));
}

// 0x7100816cb0
void Unk_816cb0(const Unk_8139c0_Self* self, u8 pokeId, u8 slot, u8 count) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f0250(poke, slot, count);
}

// 0x7100816d00
void Unk_816d00(const Unk_8139c0_Self* self, u8 pokeId, u8 slot) {
    Unk_7f0370(Unk_8139c0_Poke(self, pokeId), slot);
}

// 0x7100816d40
void Unk_816d40(const Unk_8139c0_Self* self, u8 pokeId, u8 slot) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    u8 value = Unk_7f0010(poke, slot);
    if (value != 0xff)
        value++;
    Unk_7f0040(poke, slot, value);
}

// 0x7100816da0
void Unk_816da0(const Unk_8139c0_Self* self, u8 pokeId, u8 slot) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    u8 value = Unk_7f0080(poke, slot);
    if (value != 0xff)
        value++;
    Unk_7f00b0(poke, slot, value);
}

// 0x7100816f60
void Unk_816f60(const Unk_8139c0_Self* self, u32 arg1, u32 arg2) {
    Unk_8006e0(Unk_7fe290_getField128(reinterpret_cast<const Unk_7fe290*>(self->field_10)), arg1,
               arg2);
}

// 0x7100816f90
void Unk_816f90(const Unk_8139c0_Self* self,
                u8 pokeId,
                u8 arg2,
                u8 arg3,
                u8 arg4,
                u32 arg5,
                u16 arg6,
                u16 arg7) {
    Unk_7ee6b0_Action arg;
    arg.field_0 = arg6;
    arg.field_2 = arg7;
    arg.field_4 = arg5;
    arg.field_8 = arg4;
    arg.field_9 = arg2;
    arg.field_a = arg3;
    Unk_7f2590(Unk_8139c0_Poke(self, pokeId), &arg);
}

// 0x71008170d0
void Unk_8170d0(const Unk_8139c0_Self* self, u32 arg1, const u64* arg2) {
    Unk_8002a0(Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_10)), arg1,
               *arg2);
}

// 0x7100817100
void Unk_817100(const Unk_8139c0_Self* self, u32 arg1, void* arg2) {
    Unk_7ffbd0(Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_10)), arg1,
               arg2);
}

// 0x7100817190
void Unk_817190(const Unk_8139c0_Self* self, u32 arg1, u32 arg2) {
    Unk_7ffce0(Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_10)), arg1,
               arg2);
}

// 0x71008171c0
void Unk_8171c0(const Unk_8139c0_Self* self, u32 arg1, u32 arg2) {
    Unk_7ffe50(Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_10)), arg2,
               arg1);
}

// 0x71008171f0
bool Unk_8171f0(const Unk_8139c0_Self* self, u32 arg1, u32 arg2, u32 arg3) {
    if (Unk_8021d0(Unk_7fe200_getField48(reinterpret_cast<const Unk_7fe200*>(self->field_10)), arg1,
                   arg2, arg3)) {
        Unk_7eb130(Unk_7fe240_getField88(reinterpret_cast<const Unk_7fe240*>(self->field_10)), arg1,
                   arg2, arg3);
        return true;
    }
    return false;
}

// 0x71008172b0
void Unk_8172b0(const Unk_8139c0_Self* self,
                u8 pokeId,
                u32 value0,
                u32 value1,
                u32 value2,
                u32 value3,
                u32 value4,
                u32 value5) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2fe0(poke, 0, value0);
    Unk_7f2fe0(poke, 1, value1);
    Unk_7f2fe0(poke, 2, value2);
    Unk_7f2fe0(poke, 3, value3);
    Unk_7f2fe0(poke, 4, value4);
    Unk_7f2fe0(poke, 5, value5);
}

// 0x71008173b0
void Unk_8173b0(const Unk_8139c0_Self* self, u8 pokeId, u8 otherId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7ee6b0* other = Unk_8139c0_Poke(self, otherId);
    Unk_7f2150(other, poke);
}

// 0x7100817410
void Unk_817410(const Unk_8139c0_Self* self, u8 pokeId, u16 types, u32 arg3) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f22a0(poke, types, arg3);
}

// 0x7100817460
void Unk_817460(const Unk_8139c0_Self* self, u8 pokeId, u8 value, u32 arg3) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2310_set(reinterpret_cast<Unk_7f2310*>(poke), value, arg3);
}

// 0x71008174f0
void Unk_8174f0(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, bool arg3) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2380(poke, arg2, arg3);
}

// 0x7100817540
void Unk_817540(const Unk_8139c0_Self* self, u8 pokeId, u8 otherId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7ee6b0* other = Unk_8139c0_Poke(self, otherId);
    Unk_7f2a10(poke, other);
}

// 0x71008175a0
void Unk_8175a0(const Unk_8139c0_Self* self, u8 pokeId, u32 stat, u16 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f0750(poke, stat, value);
}

// 0x7100817710
void Unk_817710(const Unk_8139c0_Self* self, u8 pokeId, u8 slot, u32 move, u8 maxPP, u8 original) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f03e0(poke, slot, move, maxPP, original != 0);
}

// 0x7100817770
void Unk_817770(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f1e00(Unk_8139c0_Poke(self, pokeId));
    Unk_802ff0(Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_10)), pokeId);
}

// 0x71008177b0
void Unk_8177b0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f1a50(Unk_8139c0_Poke(self, pokeId));
    Unk_802ff0(Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_10)), pokeId);
}

// 0x7100817860
void Unk_817860(const Unk_8139c0_Self* self, u8 pokeId, u16 amount) {
    Unk_7f13e0(Unk_8139c0_Poke(self, pokeId), amount);
    Unk_7ee040_set(reinterpret_cast<Unk_7ee040*>(Unk_8139c0_Poke(self, pokeId)));
}

// 0x71008178c0
void Unk_8178c0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f19d0(Unk_8139c0_Poke(self, pokeId));
    Unk_7f1cd0_set(reinterpret_cast<Unk_7f1cd0*>(Unk_8139c0_Poke(self, pokeId)));
}

// 0x7100817910
void Unk_817910(const Unk_8139c0_Self* self,
                u8 pokeId,
                u32 condition,
                bool* out,
                const u64* value,
                bool* changed) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    bool result = Unk_7f15a0(poke, condition, value, changed);
    if (out != nullptr)
        *out = result;
}

// 0x7100817980
void Unk_817980(const Unk_8139c0_Self* self,
                u8 pokeId,
                u8 arg2,
                u8 arg3,
                bool same,
                u32 arg5,
                u32 arg6) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f24c0(poke, arg2, arg3, same, arg5, arg6);
}

// 0x7100817a80
void Unk_817a80(const Unk_8139c0_Self* self,
                u8 pokeId,
                u8 stage1,
                u8 stage2,
                u8 stage3,
                u8 stage4,
                u8 stage5,
                u8 stage6,
                u8 stage7,
                u8 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f1000(poke, 1, stage1);
    Unk_7f1000(poke, 2, stage2);
    Unk_7f1000(poke, 3, stage3);
    Unk_7f1000(poke, 4, stage4);
    Unk_7f1000(poke, 5, stage5);
    Unk_7f1000(poke, 6, stage6);
    Unk_7f1000(poke, 7, stage7);
    Unk_7f1390(poke, value);
}

// 0x7100817b70
void Unk_817b70(const Unk_8139c0_Self* self, u8 pokeId, u8 count) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f1320(poke, count);
}

// 0x7100817bf0
void Unk_817bf0(const Unk_8139c0_Self* self, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    Unk_7ffb40_set(static_cast<Unk_7ffb40*>(
                       Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_10))),
                   arg1, arg2, arg3, arg4);
}

// 0x7100817d10
void Unk_817d10(const Unk_8139c0_Self* self, u32 arg1, u32 arg2) {
    Unk_7ff4f0(Unk_7fe350_getField2a8(reinterpret_cast<const Unk_7fe350*>(self->field_10)), arg1,
               arg2);
}

// 0x7100817d40
void Unk_817d40(const Unk_8139c0_Self* self, u32 arg1, u32 arg2) {
    Unk_7ff570(Unk_7fe350_getField2a8(reinterpret_cast<const Unk_7fe350*>(self->field_10)), arg1,
               arg2);
}

// 0x7100817d70
void Unk_817d70(const Unk_8139c0_Self* self, u32 client) {
    void* party = Unk_7ed1a0(Unk_7fe1d0_getField8(self->field_10), client);
    Unk_7cc080(self->field_8, party, client);
}

static inline Unk_7f3610_Self* Unk_8139c0_Data(const Unk_8139c0_Self* self, u8 pokeId) {
    return Unk_7ee810_getField278(
        reinterpret_cast<const Unk_7ee810*>(Unk_8139c0_Poke(self, pokeId)));
}

// 0x7100817e60
void Unk_817e60(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f3740_set(reinterpret_cast<Unk_7f3740*>(Unk_8139c0_Data(self, pokeId)));
}

// 0x7100817e90
void Unk_817e90(const Unk_8139c0_Self* self, u8 pokeId, u8 value) {
    Unk_7f3730_setField3d(reinterpret_cast<Unk_7f3730*>(Unk_8139c0_Data(self, pokeId)), value);
}

// 0x7100817ed0
void Unk_817ed0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f3800(Unk_8139c0_Data(self, pokeId));
}

// 0x7100817f00
void Unk_817f00(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f37b0_set(reinterpret_cast<Unk_7f37b0*>(Unk_8139c0_Data(self, pokeId)));
}

// 0x7100817f30
void Unk_817f30(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f37d0_set(reinterpret_cast<Unk_7f37d0*>(Unk_8139c0_Data(self, pokeId)));
}

// 0x7100817f60
void Unk_817f60(const Unk_8139c0_Self* self, u8 pokeId, u8 value) {
    Unk_7f37e0_set(reinterpret_cast<Unk_7f37e0*>(Unk_8139c0_Data(self, pokeId)), value);
}

static inline void* Unk_8139c0_Max(Unk_7f3610_Self* data) {
    return Unk_7f3700_getField0(reinterpret_cast<const Unk_7f3700*>(data));
}

// 0x7100817fa0
void Unk_817fa0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    void* max = Unk_8139c0_Max(Unk_7ee810_getField278(reinterpret_cast<const Unk_7ee810*>(poke)));
    Unk_7fc870_set(static_cast<Unk_7fc870*>(max), 0);
    Unk_7fc7d0_set(static_cast<Unk_7fc7d0*>(max));
    Unk_7f26d0(poke, 5, 0);
}

// 0x7100818000
void Unk_818000(const Unk_8139c0_Self* self, u8 pokeId, u32 value) {
    Unk_7fc890(Unk_8139c0_Max(Unk_8139c0_Data(self, pokeId)), value);
}

// 0x7100818040
void Unk_818040(const Unk_8139c0_Self* self, u8 pokeId, u8 value) {
    Unk_7fc8b0_set(static_cast<Unk_7fc8b0*>(Unk_8139c0_Max(Unk_8139c0_Data(self, pokeId))), value);
}

// 0x7100818080
void Unk_818080(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7fc7b0(Unk_8139c0_Max(Unk_8139c0_Data(self, pokeId)));
}

// 0x71008180c0
void Unk_8180c0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7fc900_set(static_cast<Unk_7fc900*>(Unk_8139c0_Max(Unk_8139c0_Data(self, pokeId))));
}

// 0x7100818100
void Unk_818100(const Unk_8139c0_Self* self, u8 pokeId) {
    void* max = Unk_8139c0_Max(Unk_8139c0_Data(self, pokeId));
    Unk_7fc7e0_set(static_cast<Unk_7fc7e0*>(max));
    Unk_7fc7b0(max);
}

// 0x7100818270
void Unk_818270(const Unk_8139c0_Self* self, u32 value) {
    u8 index = Unk_7cac80_call(static_cast<const Unk_7cac80*>(self->field_8), value);
    if (index <= 1)
        Unk_800b60(
            Unk_800990(Unk_7fe2d0_getField188(reinterpret_cast<const Unk_7fe2d0*>(self->field_10)),
                       index),
            value);
}

// 0x7100818340
void Unk_818340(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, u32 arg3) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_868a00(self->field_18, poke, arg2, arg3);
}

// 0x7100818390
void Unk_818390(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_868b40(self->field_18, poke, arg2);
}

// 0x71008183e0
void Unk_8183e0(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_868bf0(self->field_18, poke, arg2);
}

// 0x7100818430
void Unk_818430(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_868ca0(self->field_18, poke);
}

// 0x7100818470
void Unk_818470(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_87e3b0(self->field_18, poke);
}

// 0x71008184b0
void Unk_8184b0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_87e4b0(self->field_18, poke);
}

// 0x71008184f0
void Unk_8184f0(const Unk_8139c0_Self* self, u8 pokeId, u8 otherId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7ee6b0* other = Unk_8139c0_Poke(self, otherId);
    Unk_87e540(self->field_18, poke, other);
}

// 0x7100818550
void Unk_818550(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_859180(self->field_18, poke);
}

// 0x7100818590
void Unk_818590(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_859280(self->field_18, poke);
}

// 0x7100818650
void Unk_818650(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_818830(self->field_18, poke);
}

// 0x7100818690
void Unk_818690(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_8188f0(self->field_18, poke);
}

// 0x71008186d0
void Unk_8186d0(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_890950(self->field_18, poke, arg2);
}

// 0x7100818720
void Unk_818720(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_890a20(self->field_18, poke, arg2);
}
