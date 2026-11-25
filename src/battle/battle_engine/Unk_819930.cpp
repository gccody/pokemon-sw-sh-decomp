// Scope: common
// Battle event handler helpers (0x7100819930-0x7100819bc0): the main module's
// party lookup, and wrappers that pass a parameter block to one of the battle
// state's handler objects with a result on the stack and return its flag.
// Placeholder names.
#include "battle/battle_engine/Unk_81a030.h"

struct Unk_7fe1d0;
struct Unk_7ecc90_Con;
struct Unk_7fc430_Party;
struct Unk_7cb2c0;
u8 Unk_7cb490(u8 pokeId);
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
const Unk_7fc430_Party* Unk_7ed1b0(const Unk_7ecc90_Con* self, u32 client);
u8 Unk_7cb2c0_call(const Unk_7cb2c0* self, u8 value);
u8 Unk_7fc350(const Unk_7fc430_Party* self, u8 start);

// The handler objects' functions (game/unk_82e410).
struct Unk_84dde0_Arg;
void Unk_84dde0(Unk_23ae1c0* self, Unk_23acc98_Result& result, const Unk_84dde0_Arg& arg);
struct Unk_84d950_Arg;
void Unk_84d950(Unk_23ae180* self, Unk_23acc98_Result& result, const Unk_84d950_Arg& arg);

// 0x71008199a0
// NON_MATCHING: the load of the handler object is hoisted above the call to
// Unk_7cb490 (the original loads it after).
bool Unk_8199a0(const Unk_819600_Self* self, u8 pokeId) {
    u32 client = Unk_7cb490(pokeId);
    const Unk_7fc430_Party* party =
        Unk_7ed1b0(Unk_7fe1d0_getField8(static_cast<const Unk_7fe1d0*>(self->field_8)), client);
    u8 start = Unk_7cb2c0_call(static_cast<const Unk_7cb2c0*>(self->field_0), Unk_7cb490(pokeId));
    return Unk_7fc350(party, start);
}

// 0x7100819b00
bool Unk_819b00(const Unk_819600_Self* self, const Unk_82ec20_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_82ec20(Unk_7e0080_Get16e0(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819b40
bool Unk_819b40(const Unk_819600_Self* self, const Unk_84dde0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_84dde0(Unk_7e0080_Getbe0(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819b80
bool Unk_819b80(const Unk_819600_Self* self, const Unk_84d950_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_84d950(Unk_7e0080_Getb40(self->field_20), result, arg);
    return result.field_0;
}
