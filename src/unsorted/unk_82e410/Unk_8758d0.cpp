// Scope: common
// Battle event handlers (0x71008758d0-0x71008760a4): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_8758d0.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_8758d0.h"

struct Unk_7f09c0;
struct Unk_7f2510;
struct Unk_7f2520;
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self);
// Defined as u16; 0x7100875ac0 tests the whole register (cbz).
u32 Unk_7f2510_getField348(const Unk_7f2510* self);
u32 Unk_7f2520_getField34c(const Unk_7f2520* self);
u8 Unk_7f0540(const Unk_7ee6b0* poke, u32 stat);
s32 Unk_7f0130(const Unk_7ee6b0* poke, u8 value);

// What 0x71008758d0 gives Unk_81a510 (field_0 and field_1 two Pokemon), with
// a message list at +0xc. As in Unk_86dd10.h, with +0x8 split into bytes
// (0x71008758d0 sets +0x9 as a byte).
struct Unk_838f90_Arg {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u8 _a[2];
    Unk_840b50_List field_c;

    Unk_838f90_Arg()
        : field_0(0x1f),
          field_1(0x1f),
          field_2(0),
          field_4(0),
          field_5(0),
          field_6(0x1f),
          field_7(0),
          field_8(0),
          field_9(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_c));
    }
};
PKMN_OFFSET_ASSERT(Unk_838f90_Arg, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_838f90_Arg, field_9, 0x9);
PKMN_OFFSET_ASSERT(Unk_838f90_Arg, field_c, 0xc);
PKMN_SIZE_ASSERT(Unk_838f90_Arg, 0x30);
bool Unk_81a510(const Unk_819600_Self* self, const Unk_838f90_Arg& arg);

// What 0x71008758d0 gives Unk_81a600: two Pokemon, an item and two values.
struct Unk_857770_Arg {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u8 field_4;
    u8 _5[3];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_857770_Arg, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_857770_Arg, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_857770_Arg, 0xc);
bool Unk_81a600(const Unk_819600_Self* self, const Unk_857770_Arg& arg);

// What 0x7100875cb0 gives Unk_819f70 (field_0 and field_1 two Pokemon), with
// a message list at +0xc.
struct Unk_84d780_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u32 field_4;
    u8 field_8;
    u8 _9[3];
    Unk_840b50_List field_c;

    Unk_84d780_Arg()
        : field_0(0x1f), field_1(0x1f), field_2(0), field_3(0), field_4(0), field_8(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_c));
    }
};
PKMN_OFFSET_ASSERT(Unk_84d780_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_84d780_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_84d780_Arg, field_c, 0xc);
PKMN_SIZE_ASSERT(Unk_84d780_Arg, 0x30);
bool Unk_819f70(const Unk_819600_Self* self, const Unk_84d780_Arg& arg);

// What 0x7100875f50 gives Unk_819c40 (field_0 a Pokemon), with a message
// list at +0x8.
struct Unk_8561f0_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 _5[3];
    Unk_840b50_List field_8;

    Unk_8561f0_Arg() : field_0(0x1f), field_1(0), field_2(0), field_3(0), field_4(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_8));
    }
};
PKMN_OFFSET_ASSERT(Unk_8561f0_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_8561f0_Arg, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_8561f0_Arg, 0x2c);
bool Unk_819c40(const Unk_819600_Self* self, const Unk_8561f0_Arg& arg);

// 0x71008758d0
void Unk_8758d0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u16 item = Unk_7f09c0_getField76(reinterpret_cast<const Unk_7f09c0*>(Unk_8196d0(flow, pokeId)));
    {
        Unk_838f90_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = pokeId;
        arg.field_2 = 0;
        arg.field_9 = 1;
        Unk_81a510(flow, arg);
    }
    Unk_857770_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = pokeId;
    arg.field_2 = item;
    arg.field_4 = 1;
    arg.field_8 = 2;
    Unk_81a600(flow, arg);
}

// 0x7100875990
void Unk_875990(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    if (target != pokeId)
        return;
    Unk_840b50_Arg arg;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x46c);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
}

// 0x7100875a20
void Unk_875a20(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x52, 1);
}

// 0x7100875a70
void Unk_875a70(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) == pokeId)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 1);
}

// 0x7100875ac0
void Unk_875ac0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_7e9830(flow->field_30, 2) != pokeId)
        return;
    if (Unk_7e9830(flow->field_30, 0x12) !=
        Unk_7e9ba0_getField38(static_cast<const Unk_7e9ba0*>(flow->field_40)))
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_7f2520_getField34c(reinterpret_cast<const Unk_7f2520*>(poke)) != 0xc2)
        return;
    if (Unk_7f2510_getField348(reinterpret_cast<const Unk_7f2510*>(poke)) == 0)
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x25, 0x27);
}

// 0x7100875b60
void Unk_875b60(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_7e9830(flow->field_30, 3);
    if (target != pokeId)
        return;
    if (Unk_7e9830(flow->field_30, 0x12) !=
        Unk_7e9ba0_getField38(static_cast<const Unk_7e9ba0*>(flow->field_40)))
        return;
    {
        Unk_840b50_Arg arg;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x34c);
        Unk_803d60(&arg.field_4, target);
        Unk_81a030(flow, arg);
    }
    Unk_856390_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 0x13;
    Unk_81a0e0(flow, arg);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 6, 1);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x78, 1);
}

// 0x7100875c40
void Unk_875c40(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0xc) == 6)
        return;
    Unk_857530_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 0x13;
    Unk_81a120(flow, arg);
    Unk_8196c0_call(static_cast<const Unk_8196c0*>(self));
}

// 0x7100875cb0
void Unk_875cb0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (target != pokeId)
        return;
    if (!Unk_7ef2b0_call(Unk_8196d0(flow, pokeId)))
        return;
    if (!Unk_7eb230(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12))) {
        u32 attacker = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
        Unk_7ee6b0* poke = Unk_8196d0(flow, attacker);
        if (!Unk_8197f0_call(static_cast<const Unk_8197f0*>(self), pokeId, attacker) &&
            !Unk_7ef2b0_call(poke) &&
            !Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(poke))) {
            Unk_819a70_call(static_cast<const Unk_819a70*>(self));
            {
                Unk_84d780_Arg arg;
                arg.field_0 = attacker;
                arg.field_1 = pokeId;
                arg.field_8 = 3;
                arg.field_4 = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x14);
                arg.field_2 = 1;
                Unk_819f70(flow, arg);
            }
            Unk_84d780_Arg arg;
            arg.field_0 = pokeId;
            arg.field_1 = attacker;
            arg.field_8 = 0xc;
            arg.field_4 = Unk_819690_call(static_cast<const Unk_819690*>(self));
            arg.field_3 = 1;
            Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_c), 2, 0x350);
            Unk_803d60(&arg.field_c, target);
            Unk_819f70(flow, arg);
        }
    }
    Unk_857530_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 0x13;
    Unk_81a120(flow, arg);
    Unk_8196c0_call(static_cast<const Unk_8196c0*>(self));
}

// 0x7100875e60
void Unk_875e60(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_7e9830(flow->field_30, 3);
    if (target != pokeId)
        return;
    if (Unk_7e9830(flow->field_30, 0x12) !=
        Unk_7e9ba0_getField38(static_cast<const Unk_7e9ba0*>(flow->field_40)))
        return;
    Unk_840b50_Arg message;
    message.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&message.field_4), 2, 0x354);
    Unk_803d60(&message.field_4, target);
    Unk_81a030(flow, message);
    Unk_856390_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 0x12;
    Unk_81a0e0(flow, arg);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 6, 1);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x78, 1);
}

// 0x7100875f50
void Unk_875f50(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    if (Unk_7eb230(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12)))
        return;
    if (!Unk_7ef2b0_call(Unk_8196d0(flow, pokeId)))
        return;
    u8 attacker = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    Unk_7ee6b0* poke = Unk_8196d0(flow, attacker);
    u32 stat = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x14);
    u8 value = Unk_7f0540(poke, stat);
    if (value != 4) {
        Unk_8561f0_Arg arg;
        arg.field_0 = attacker;
        arg.field_1 = value;
        arg.field_2 = -Unk_7f0130(poke, value);
        arg.field_4 = 1;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_8), 2, 0x358);
        Unk_803d60(&arg.field_8, attacker);
        Unk_803d60(&arg.field_8, stat);
        Unk_819c40(flow, arg);
    }
    Unk_857530_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 0x12;
    Unk_81a120(flow, arg);
    Unk_8196c0_call(static_cast<const Unk_8196c0*>(self));
}
