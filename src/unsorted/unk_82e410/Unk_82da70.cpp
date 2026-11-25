// Scope: common
// Unk_23ace38's functions (the TU of 0x710082da70-0x710082dd00), see
// Handler.h.
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7ee6b0;
struct Unk_811d90_Self;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u8 Unk_7f0ba0(const Unk_7ee6b0* self, u32 index);
bool Unk_7ef4c0(const Unk_7ee6b0* self, u32 condition);
bool Unk_7ef2b0_call(void* self);
void Unk_80f880(void* self, const Unk_7ee6b0* poke, u8 arg2, u8 arg3);
void Unk_80f7a0(void* self, const Unk_7ee6b0* poke, u32 arg2);
void Unk_811fe0(const Unk_811d90_Self* self, u8 pokeId, bool flag);
struct Unk_803c60;
void Unk_803c60_set(Unk_803c60* self);

// What Unk_82c6b0 gets back.
struct Unk_819c80_Out {
    u8 field_0;
    u8 _1[0xf];
};
PKMN_SIZE_ASSERT(Unk_819c80_Out, 0x10);

// What Unk_82db80 passes to Unk_82c6b0.
struct Unk_82db80_Param {
    u8 field_0;
    u32 field_4;
    u8 field_8;
    u8 field_9;
    u16 field_a;
    u32 field_c;
    u64 field_10;
    u64 field_18;
    u32 field_20;
    u16 field_24;
    u8 field_26;
    u8 _27;
    u8 field_28[4];
    Unk_23acc98_Message field_2c;

    Unk_82db80_Param()
        : field_0(0x1f),
          field_4(0x2d),
          field_8(0),
          field_9(0),
          field_a(0),
          field_c(0),
          field_10(0),
          field_18(0),
          field_20(0),
          field_24(0),
          field_26(0),
          field_28() {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_2c));
    }
};
PKMN_OFFSET_ASSERT(Unk_82db80_Param, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82db80_Param, field_26, 0x26);
PKMN_OFFSET_ASSERT(Unk_82db80_Param, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_82db80_Param, field_2c, 0x2c);
PKMN_SIZE_ASSERT(Unk_82db80_Param, 0x50);
void Unk_82c6b0(void* self, Unk_819c80_Out* out, const void* in);

// What Unk_82dd30 (Unk_23ace58's) takes.
struct Unk_82dd30_Arg {
    u8 field_0;
};
void Unk_82dd30(Unk_23ace58* self, Unk_23acc98_Result& result, const Unk_82dd30_Arg& arg);

// What Unk_82dab0 takes.
struct Unk_82dab0_Arg {
    const Unk_7ee6b0* field_0;
    bool field_8;
    bool field_9;
};
PKMN_OFFSET_ASSERT(Unk_82dab0_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82dab0_Arg, field_9, 0x9);

void Unk_82db80(Unk_23ace38* self, const Unk_7ee6b0* poke, bool flag);

// 0x710082dab0
void Unk_82dab0(Unk_23ace38* self, Unk_23acc98_Result& /*result*/, const Unk_82dab0_Arg& arg) {
    u8 value = Unk_7f0ba0(arg.field_0, 4);
    if (value == 0)
        return;
    u8 pokeId = value - 1;
    if (pokeId >= 0x1e)
        return;
    void* other = Unk_23acc98_Object(self, pokeId);
    if (other == nullptr)
        return;
    Unk_82db80(self, static_cast<const Unk_7ee6b0*>(other), arg.field_9);
    const Unk_7ee6b0* poke = arg.field_0;
    bool flag = arg.field_8;
    Unk_80f880(Unk_23acc98_Field20(self), poke, 4, 0);
    if (flag && !Unk_7ef2b0_call(const_cast<Unk_7ee6b0*>(poke)))
        Unk_811fe0(static_cast<const Unk_811d90_Self*>(Unk_23acc98_Field20(self)),
                   Unk_7ee6b0_getField7d(poke), false);
}

// 0x710082db80
void Unk_82db80(Unk_23ace38* self, const Unk_7ee6b0* poke, bool flag) {
    if (!Unk_7ef4c0(poke, 0x22))
        return;
    {
        Unk_82db80_Param param;
        param.field_0 = Unk_7ee6b0_getField7d(poke);
        param.field_4 = 0x22;
        param.field_8 = Unk_7ee6b0_getField7d(poke);
        param.field_26 = 1;
        param.field_28[3] = 1;
        Unk_819c80_Out out;
        Unk_82c6b0(Unk_7e0080_Getb20(Unk_23acc98_Holder(self)), &out, &param);
    }
    Unk_80f7a0(Unk_23acc98_Field20(self), poke, 3);
    if (flag) {
        Unk_82dd30_Arg arg;
        arg.field_0 = Unk_7ee6b0_getField7d(poke);
        Unk_23acc98_Result result;
        Unk_82dd30(Unk_7e0080_Gete0(Unk_23acc98_Holder(self)), result, arg);
    }
}
