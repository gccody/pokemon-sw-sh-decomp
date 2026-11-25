// Scope: common
// Battle event handler helpers (0x710081a030-0x710081a350): each passes its
// parameter block to one of the battle state's handler objects, with a result
// on the stack, and returns the result's flag (or nothing). Placeholder names.
#include "battle/battle_engine/Unk_81a030.h"

// The handler objects' functions (game/unk_82e410), declared as Handler.h
// declares them.
struct Unk_840b50_Arg;
void Unk_840b50(Unk_23adad8* self, Unk_23acc98_Result& result, const Unk_840b50_Arg& arg);
struct Unk_856390_Arg;
void Unk_856390(Unk_23ae880* self, Unk_23acc98_Result& result, const Unk_856390_Arg& arg);
struct Unk_857530_Arg;
void Unk_857530(Unk_23ae9a0* self, Unk_23acc98_Result& result, const Unk_857530_Arg& arg);
struct Unk_8564b0_Arg;
void Unk_8564b0(Unk_23ae8a0* self, Unk_23acc98_Result& result, const Unk_8564b0_Arg& arg);
struct Unk_82fa10_Arg;
void Unk_82fa10(Unk_23acf78* self, Unk_23acc98_Result& result, const Unk_82fa10_Arg& arg);
struct Unk_839560_Arg;
void Unk_839560(Unk_23ad4b8* self, Unk_23acc98_Result& result, const Unk_839560_Arg& arg);
struct Unk_853f20_Arg;
void Unk_853f20(Unk_23ae600* self, Unk_23acc98_Result& result, const Unk_853f20_Arg& arg);
struct Unk_82b8b0_Arg;
void Unk_82b8b0(Unk_23acd18* self, Unk_23acc98_Result& result, const Unk_82b8b0_Arg& arg);
struct Unk_8642b0_Arg;
void Unk_8642b0(Unk_23b1380* self, Unk_23acc98_Result& result, const Unk_8642b0_Arg& arg);

// Leaf functions with their own placeholder types (src/unsorted/leaf).
struct Unk_8565c0_arg1 {
    u8 field_0;
};
struct Unk_8565c0_arg2;
void Unk_8565c0_call(void* self, Unk_8565c0_arg1* value, const Unk_8565c0_arg2* arg2);
struct Unk_857650_arg1 {
    u8 field_0;
};
struct Unk_857650_arg2;
void Unk_857650_call(void* self, Unk_857650_arg1* value, const Unk_857650_arg2* arg2);

// 0x710081a030
void Unk_81a030(const Unk_819600_Self* self, const Unk_840b50_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_840b50(Unk_7e0080_Getdc0(self->field_20), result, arg);
}

// 0x710081a060
u8 Unk_81a060(const Unk_819600_Self* self, const Unk_8565c0_arg2* arg) {
    Unk_8565c0_arg1 result;
    Unk_8565c0_call(Unk_7e0080_Get1040(self->field_20), &result, arg);
    return result.field_0;
}

// 0x710081a0a0
u8 Unk_81a0a0(const Unk_819600_Self* self, const Unk_857650_arg2* arg) {
    Unk_857650_arg1 result;
    Unk_857650_call(Unk_7e0080_Getf80(self->field_20), &result, arg);
    return result.field_0;
}

// 0x710081a0e0
bool Unk_81a0e0(const Unk_819600_Self* self, const Unk_856390_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_856390(Unk_7e0080_Getfa0(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a120
bool Unk_81a120(const Unk_819600_Self* self, const Unk_857530_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_857530(Unk_7e0080_Getf60(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a160
void Unk_81a160(const Unk_819600_Self* self, const Unk_8564b0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8564b0(Unk_7e0080_Get1000(self->field_20), result, arg);
}

// 0x710081a190
bool Unk_81a190(const Unk_819600_Self* self, const Unk_82fa10_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_82fa10(Unk_7e0080_Get1100(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a1d0
bool Unk_81a1d0(const Unk_819600_Self* self, const Unk_839560_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_839560(Unk_7e0080_Get1120(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a210
bool Unk_81a210(const Unk_819600_Self* self, const Unk_853f20_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_853f20(Unk_7e0080_Get1140(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a290
bool Unk_81a290(const Unk_819600_Self* self, const Unk_82b8b0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_82b8b0(Unk_7e0080_Getc20(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a2d0
bool Unk_81a2d0(const Unk_819600_Self* self, const Unk_8642b0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8642b0(Unk_7e0080_Getc40(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a310
// NON_MATCHING: the code matches, but under its own signature: the existing
// name _Z10Unk_81a310v takes no parameters, and the original reads
// self->field_20 from x0 (rename to _Z10Unk_81a310PK15Unk_819600_Self).
u8 Unk_81a310(const Unk_819600_Self* self) {
    Unk_8341a0_Result result;
    Unk_8341a0_Arg arg{0x1f};
    Unk_8341a0(Unk_7e0080_Getcc0(self->field_20), result, arg);
    return result.field_0;
}
