// Scope: common
// Battle server command wrappers (continuing Unk_810750.cpp): act on the
// server's state, then queue the command for the clients. Placeholder names:
// rename once they're known.
#include "unsorted/Unk_811d90.h"

struct Unk_7c2d80_Main;
struct Unk_23acc98_Message;
struct Unk_812cf0;
struct Unk_812dd0;
struct Unk_812e90;
struct Unk_831030;

u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u8 Unk_780d40(u32 move);
u8 Unk_7cb420(const Unk_7c2d80_Main* self, Unk_7ecc90_Con* con, u8 pokeId);
u32 Unk_812dd0_getField0(const Unk_812dd0* self);
bool Unk_812e90_check(const Unk_812e90* self);
void Unk_812cf0_clearField10(Unk_812cf0* self);
bool Unk_831030_check(const Unk_831030* self);
// Variadic, like Unk_8150c0.
void Unk_816500(void* que, u32 arg1, u16 id, ...);
void Unk_80dd60(void* self, const Unk_23acc98_Message* message);

// Appends 0, 0xbf and `value` to the byte list.
void Unk_8168e0(Unk_816910_List* list, u8 value);
void Unk_816910(Unk_816910_List* list, u8 value);
void Unk_816c00(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, u32 arg3, u8 arg4);
void Unk_816f60(const Unk_8139c0_Self* self, u32 arg1, u32 arg2);
void Unk_8172b0(const Unk_8139c0_Self* self,
                u8 pokeId,
                u32 value0,
                u32 value1,
                u32 value2,
                u32 value3,
                u32 value4,
                u32 value5);
void Unk_817370(const Unk_8139c0_Self* self, u8 arg1, u8 arg2);
bool Unk_8179f0(const Unk_8139c0_Self* self, u8 pokeId);
bool Unk_817a20(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817a50(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817c80(const Unk_8139c0_Self* self, u16 index);
void Unk_817ce0(const Unk_8139c0_Self* self, u8 index);
void Unk_817d10(const Unk_8139c0_Self* self, u32 arg1, u32 arg2);
void Unk_817d40(const Unk_8139c0_Self* self, u32 arg1, u32 arg2);

// The server, for the wrappers that also read the main module at +0x10.
struct Unk_810be0_Self {
    u8 _0[0x8];
    const Unk_7c2d80_Main* field_8;
    const Unk_7fe1d0* field_10;
    u64 field_18;
    const Unk_8139c0_Self* field_20;
};
PKMN_OFFSET_ASSERT(Unk_810be0_Self, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_810be0_Self, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_810be0_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_810be0_Self, field_20, 0x20);

// 0x7100810d10
void Unk_810d10(const Unk_811d90_Self* self,
                u8 arg1,
                u8 arg2,
                u16 arg3,
                u8 arg4,
                u8 arg5,
                u8 arg6,
                bool arg7,
                bool arg8) {
    Unk_8150c0(self->field_18, 0x86, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

// What Unk_810be0 queues: a command's values, and the six 5-bit values of
// the command it queues first, which it then clears.
struct Unk_810be0_Arg1 {
    u32 field_0;
    u8 _4[0xe - 0x4];
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_810be0_Arg1, field_e, 0xe);

struct Unk_810be0_Arg2 {
    u32 field_0;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    bool field_8;
    u8 _9;
    bool field_a;
    u8 _b[0xe - 0xb];
    bool field_e;
    u8 _f;
    u32 field_10_0 : 5;
    u32 field_10_1 : 5;
    u32 field_10_2 : 5;
    u32 field_10_3 : 5;
    u32 field_10_4 : 5;
    u32 field_10_5 : 5;
};
PKMN_OFFSET_ASSERT(Unk_810be0_Arg2, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_810be0_Arg2, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_810be0_Arg2, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_810be0_Arg2, field_e, 0xe);

struct Unk_810be0_Arg3 {
    u16 field_0;
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_810be0_Arg3, field_2, 0x2);

// NON_MATCHING: register allocation (self, arg1 and arg3 take x21..x23 in
// another order) and the order of the loads for the 0x86 command.
// 0x7100810be0
void Unk_810be0(const Unk_811d90_Self* self,
                const Unk_810be0_Arg1& arg1,
                Unk_810be0_Arg2* arg2,
                const Unk_810be0_Arg3* arg3) {
    // arg1 is a reference: the original loads its field_0 before testing
    // the value, which clang only does for a pointer it knows is valid.
    u32 value = Unk_812dd0_getField0(reinterpret_cast<const Unk_812dd0*>(arg2));
    if (value == 0)
        value = arg1.field_0;
    if (Unk_812e90_check(reinterpret_cast<const Unk_812e90*>(arg2))) {
        Unk_816500(reinterpret_cast<void*>(self->field_18), arg3->field_0, 0x97, arg2->field_10_0,
                   arg2->field_10_1, arg2->field_10_2, arg2->field_10_3, arg2->field_10_4,
                   arg2->field_10_5);
        Unk_812cf0_clearField10(reinterpret_cast<Unk_812cf0*>(arg2));
    }
    if (Unk_831030_check(reinterpret_cast<const Unk_831030*>(arg3))) {
        Unk_816500(reinterpret_cast<void*>(self->field_18), arg3->field_2, 0x86, arg2->field_4,
                   arg2->field_5, value, arg1.field_e, arg2->field_6, arg2->field_7, arg2->field_e,
                   arg2->field_8);
    } else {
        Unk_810d10(self, arg2->field_4, arg2->field_5, value, arg1.field_e, arg2->field_6,
                   arg2->field_7, arg2->field_e, arg2->field_8);
    }
    arg2->field_6 = 0;
    arg2->field_a = true;
}

// 0x7100810d80
// The move goes to Unk_780d40 as a u32, and into the command as a u16.
void Unk_810d80(const Unk_810be0_Self* self, const Unk_7ee6b0* poke, u32 move, u8 arg3) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    u8 value = Unk_780d40(move);
    u8 pos = Unk_7cb420(self->field_8, Unk_7fe1d0_getField8(self->field_10), pokeId);
    Unk_8150c0(self->field_18, 0x86, pos, arg3, static_cast<u16>(move), value, 0, 0, 0, 0);
}

// 0x7100810fb0
void Unk_810fb0(Unk_810be0_Self* self, u8 pokeId, bool flag, const Unk_23acc98_Message* message) {
    Unk_7ee6b0* poke = Unk_7ecc90(Unk_7fe1d0_getField8(self->field_10), pokeId);
    if (flag) {
        if (poke != nullptr) {
            u8 id = Unk_7ee6b0_getField7d(poke);
            if (id != 0x1f)
                Unk_8150c0(self->field_18, 0xb6, id);
        }
        Unk_80dd60(self, message);
        if (poke != nullptr) {
            u8 id = Unk_7ee6b0_getField7d(poke);
            if (id != 0x1f)
                Unk_8150c0(self->field_18, 0xb7, id);
        }
    } else {
        Unk_80dd60(self, message);
    }
}

// 0x7100811070
void Unk_811070(const Unk_811d90_Self* self, u16 index) {
    Unk_817c80(self->field_20, index);
    Unk_8150c0(self->field_18, 0x29, index);
}

// 0x71008110b0
void Unk_8110b0(const Unk_811d90_Self* self, u8 index) {
    Unk_817ce0(self->field_20, index);
    Unk_8150c0(self->field_18, 0x2b, index);
}

// 0x71008110f0
void Unk_8110f0(const Unk_811d90_Self* self, u32 arg1, u32 arg2) {
    Unk_817d10(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x2c, static_cast<u8>(arg1), static_cast<u8>(arg2));
}

// 0x7100811140
void Unk_811140(const Unk_811d90_Self* self, u32 arg1, u32 arg2) {
    Unk_817d40(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x2d, static_cast<u8>(arg1), static_cast<u8>(arg2));
}

// 0x7100811190
void Unk_811190(const Unk_811d90_Self* self, u32 arg1, u32 arg2) {
    Unk_816f60(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x4f, static_cast<u8>(arg1), static_cast<u8>(arg2));
}

// A Pokemon and a value that go with a command.
struct Unk_8111e0_Arg {
    const Unk_7ee6b0* field_0;
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8111e0_Arg, field_8, 0x8);

// 0x71008111e0
void Unk_8111e0(const Unk_811d90_Self* self, const Unk_7ee6b0* poke, const Unk_8111e0_Arg* arg) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    u8 otherId;
    u16 value;
    if (arg != nullptr) {
        otherId = Unk_7ee6b0_getField7d(arg->field_0);
        value = arg->field_8;
    } else {
        otherId = 0x1f;
        value = 0;
    }
    Unk_8150c0(self->field_18, 0x46, pokeId, otherId, value);
}

// 0x7100811240
void Unk_811240(const Unk_811d90_Self* self,
                u8 pokeId,
                u32 value0,
                u32 value1,
                u32 value2,
                u32 value3,
                u32 value4,
                u32 value5) {
    Unk_8172b0(self->field_20, pokeId, value0, value1, value2, value3, value4, value5);
    Unk_8150c0(self->field_18, 0x41, pokeId, static_cast<u8>(value0), static_cast<u8>(value1),
               static_cast<u8>(value2), static_cast<u8>(value3), static_cast<u8>(value4),
               static_cast<u8>(value5));
}

// 0x71008112d0
void Unk_8112d0(const Unk_811d90_Self* self, u8 arg1, u8 arg2) {
    Unk_817370(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x42, arg1, arg2);
}

// 0x7100811320
bool Unk_811320(const Unk_811d90_Self* self, u8 pokeId) {
    bool result = Unk_8179f0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0xf, pokeId);
    return result;
}

// 0x7100811370
bool Unk_811370(const Unk_811d90_Self* self, u8 pokeId) {
    bool result = Unk_817a20(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x10, pokeId);
    return result;
}

// 0x71008113c0
void Unk_8113c0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817a50(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x11, pokeId);
}
