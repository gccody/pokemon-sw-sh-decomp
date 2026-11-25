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
    if (flag && poke != nullptr) {
        u8 id = Unk_7ee6b0_getField7d(poke);
        if (id != 0x1f)
            Unk_8150c0(self->field_18, 0xb6, id);
        Unk_80dd60(self, message);
        id = Unk_7ee6b0_getField7d(poke);
        if (id != 0x1f)
            Unk_8150c0(self->field_18, 0xb7, id);
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
