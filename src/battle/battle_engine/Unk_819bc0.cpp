// Scope: common
// Battle event handler helpers (0x7100819bc0-0x710081a024): each passes a
// parameter block to one of the battle state's handler objects, with a result
// on the stack, and returns the result's flag. Placeholder names.
#include "battle/battle_engine/Unk_81a030.h"

struct Unk_803c60;
void Unk_803c60_set(Unk_803c60* self);
bool Unk_82d990_call(u32 self);
u64 Unk_7f8820(u8 arg0, u16 arg1);

// The parameter block of Unk_23ad2b8 (Unk_7e0080::field_9a0), 0x7100836520.
struct Unk_836520_Arg {
    u8 field_0 = 0x1f;
    u8 field_1 = 0x1f;
    u32 field_4 = 0;
    u64 field_8 = 0;
    u8 field_10 = 0;
    u8 field_11 = 0;
    u16 field_12 = 0;
    u32 field_14 = 1;
    Unk_23acc98_Message field_18;

    Unk_836520_Arg() { Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_18)); }
};
PKMN_SIZE_ASSERT(Unk_836520_Arg, 0x40);
PKMN_OFFSET_ASSERT(Unk_836520_Arg, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_836520_Arg, field_18, 0x18);
void Unk_836520(Unk_23ad2b8* self, Unk_23acc98_Result& result, const Unk_836520_Arg& arg);

// The other handler objects' functions (game/unk_82e410).
struct Unk_8542e0_Arg;
void Unk_8542e0(Unk_23ae640* self, Unk_23acc98_Result& result, const Unk_8542e0_Arg& arg);
struct Unk_84a7a0_Arg;
void Unk_84a7a0(Unk_23ae080* self, Unk_23acc98_Result& result, const Unk_84a7a0_Arg& arg);
struct Unk_8561f0_Arg;
void Unk_8561f0(Unk_23ae860* self, Unk_23acc98_Result& result, const Unk_8561f0_Arg& arg);
struct Unk_84a910_Arg;
void Unk_84a910(Unk_23ae0a0* self, Unk_23acc98_Result& result, const Unk_84a910_Arg& arg);
struct Unk_854180_Arg;
void Unk_854180(Unk_23ae620* self, Unk_23acc98_Result& result, const Unk_854180_Arg& arg);
struct Unk_852610_Arg;
void Unk_852610(Unk_23ae4c0* self, Unk_23acc98_Result& result, const Unk_852610_Arg& arg);
struct Unk_8524e0_Arg;
void Unk_8524e0(Unk_23ae4a0* self, Unk_23acc98_Result& result, const Unk_8524e0_Arg& arg);
struct Unk_863ab0_Arg;
void Unk_863ab0(Unk_23b12c0* self, Unk_23acc98_Result& result, const Unk_863ab0_Arg& arg);
struct Unk_8549c0_Arg;
void Unk_8549c0(Unk_23ae6a0* self, Unk_23acc98_Result& result, const Unk_8549c0_Arg& arg);
struct Unk_84d780_Arg;
void Unk_84d780(Unk_23ae160* self, Unk_23acc98_Result& result, const Unk_84d780_Arg& arg);
struct Unk_862a90_Arg;
void Unk_862a90(Unk_23b11a0* self, Unk_23acc98_Result& result, const Unk_862a90_Arg& arg);
struct Unk_862cb0_Arg;
void Unk_862cb0(Unk_23b11c0* self, Unk_23acc98_Result& result, const Unk_862cb0_Arg& arg);

// 0x7100819bc0
bool Unk_819bc0(const Unk_819600_Self* self, const Unk_8542e0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8542e0(Unk_7e0080_Get10c0(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819c00
bool Unk_819c00(const Unk_819600_Self* self, const Unk_84a7a0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_84a7a0(Unk_7e0080_Getf00(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819c40
bool Unk_819c40(const Unk_819600_Self* self, const Unk_8561f0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8561f0(Unk_7e0080_Getba0(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819d00
bool Unk_819d00(const Unk_819600_Self* self, const Unk_836520_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_836520(Unk_7e0080_Get9a0(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819d40
bool Unk_819d40(const Unk_819600_Self* self, u8 pokeId, u32 id, u32 other) {
    Unk_23acc98_Result result;
    u32 move = Unk_82d990_call(id) ? id : other;
    Unk_836520_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = pokeId;
    arg.field_4 = 0x1c;
    arg.field_8 = Unk_7f8820(pokeId, move);
    arg.field_11 = 2;
    Unk_836520(Unk_7e0080_Get9a0(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819df0
bool Unk_819df0(const Unk_819600_Self* self, const Unk_84a910_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_84a910(Unk_7e0080_Gete60(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819e30
bool Unk_819e30(const Unk_819600_Self* self, const Unk_854180_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_854180(Unk_7e0080_Getee0(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819e70
bool Unk_819e70(const Unk_819600_Self* self, const Unk_852610_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_852610(Unk_7e0080_Getec0(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819eb0
bool Unk_819eb0(const Unk_819600_Self* self, const Unk_8524e0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8524e0(Unk_7e0080_Gete80(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819ef0
bool Unk_819ef0(const Unk_819600_Self* self, const Unk_863ab0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_863ab0(Unk_7e0080_Getea0(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819f30
bool Unk_819f30(const Unk_819600_Self* self, const Unk_8549c0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8549c0(Unk_7e0080_Get1020(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819f70
bool Unk_819f70(const Unk_819600_Self* self, const Unk_84d780_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_84d780(Unk_7e0080_Getd80(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819fb0
bool Unk_819fb0(const Unk_819600_Self* self, const Unk_862a90_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_862a90(Unk_7e0080_Geta60(self->field_20), result, arg);
    return result.field_0;
}

// 0x7100819ff0
bool Unk_819ff0(const Unk_819600_Self* self, const Unk_862cb0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_862cb0(Unk_7e0080_Getc00(self->field_20), result, arg);
    return result.field_0;
}
