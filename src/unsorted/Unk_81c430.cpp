// Scope: common
// Unk_23acbb8's function (the TU of 0x710081c430-0x710081c630; its
// constructor is src/unsorted/ctor/Unk_81c430.cpp). Placeholder names.
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7c2d80_Main;
struct Unk_7ecc90_Con;
struct Unk_7fe1d0;
struct Unk_7fe260;
struct Unk_803d10;
struct Unk_811d90_Self;
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
u64 Unk_7fe260_getFieldc8(const Unk_7fe260* self);
u8 Unk_7cb420(const Unk_7c2d80_Main* self, Unk_7ecc90_Con* con, u8 pokeId);
u8 Unk_7cb490(u8 pokeId);
u8 Unk_7cb690(const Unk_7c2d80_Main* self, u8 position);
void Unk_8028d0(void* self, u8 pokeId);
bool Unk_803d10_check(const Unk_803d10* self);
void Unk_80dd60(void* self, const Unk_23acc98_Message* message);
void Unk_810900(const Unk_811d90_Self* self, u8 pokeId, u16 value);

// A set of up to 30 byte ids (src/unsorted/Unk_812bd0.cpp), which 0x7100812bd0
// starts empty (it sets the vptr at +0 and clears the rest).
struct Unk_812bf0 {
    u8 _0[0x8];
    u8 count;
    u8 items[30];
};
PKMN_OFFSET_ASSERT(Unk_812bf0, count, 0x8);
PKMN_OFFSET_ASSERT(Unk_812bf0, items, 0x9);
void Unk_812bd0(Unk_812bf0* self);
void Unk_812c50_add(Unk_812bf0* self, u8 id);

// The handler objects' functions (game/unk_82e410).
// --- Unk_23ad7b8 (Unk_7e0080::field_1400), 0x710083ce50
struct Unk_83ce50_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
};
PKMN_SIZE_ASSERT(Unk_83ce50_Arg, 0x4);
struct Unk_83ce50_Result {
    u8 field_0;
};
void Unk_83ce50(Unk_23ad7b8* self, Unk_83ce50_Result& result, const Unk_83ce50_Arg& arg);
// --- Unk_23ad7f8 (Unk_7e0080::field_80), 0x710083d280
struct Unk_83d280_Arg {
    Unk_812bf0* field_0;
};
void Unk_83d280(Unk_23ad7f8* self, Unk_23acc98_Result& result, const Unk_83d280_Arg& arg);

struct Unk_81c460_Arg {
    u8 field_0;
    u16 field_2;
    Unk_23acc98_Message field_4;
};
PKMN_OFFSET_ASSERT(Unk_81c460_Arg, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_81c460_Arg, field_4, 0x4);

// 0x710081c460
void Unk_81c460(Unk_23acbb8* self, Unk_23acc98_Result& /*result*/, const Unk_81c460_Arg& arg) {
    Unk_810900(static_cast<const Unk_811d90_Self*>(Unk_23acc98_Field20(self)), arg.field_0,
               arg.field_2);
    Unk_8028d0(reinterpret_cast<void*>(Unk_7fe260_getFieldc8(
                   static_cast<const Unk_7fe260*>(Unk_23acc98_Field10(self)))),
               arg.field_0);
    if (Unk_803d10_check(reinterpret_cast<const Unk_803d10*>(&arg.field_4)))
        Unk_80dd60(Unk_23acc98_Field20(self), &arg.field_4);

    u8 position =
        Unk_7cb420(static_cast<const Unk_7c2d80_Main*>(Unk_23acc98_Field8(self)),
                   Unk_7fe1d0_getField8(static_cast<const Unk_7fe1d0*>(Unk_23acc98_Field10(self))),
                   arg.field_0);
    if (position == 5)
        return;

    u8 side = Unk_7cb490(arg.field_0);
    u8 value = Unk_7cb690(static_cast<const Unk_7c2d80_Main*>(Unk_23acc98_Field8(self)), position);
    u8 id;
    {
        Unk_83ce50_Arg query{side, value, value, 1};
        Unk_83ce50_Result found;
        Unk_83ce50(Unk_7e0080_Get1400(Unk_23acc98_Holder(self)), found, query);
        id = found.field_0;
    }
    Unk_812bf0 ids;
    Unk_812bd0(&ids);
    Unk_812c50_add(&ids, id);
    Unk_83d280_Arg notice{&ids};
    Unk_23acc98_Result done;
    Unk_83d280(Unk_7e0080_Get80(Unk_23acc98_Holder(self)), done, notice);
}
