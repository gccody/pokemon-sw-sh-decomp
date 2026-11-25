// Scope: common
// Battle event handler helpers (0x710081a720-0x710081aad0): each passes its
// parameter block to one of the battle state's handler objects, with a result
// on the stack, and returns the result's flag (or nothing). Placeholder names.
#include "battle/battle_engine/Unk_81a030.h"

// The handler objects' functions (game/unk_82e410), declared as Handler.h
// declares them.
struct Unk_855db0_Arg;
void Unk_855db0(Unk_23ae800* self, Unk_23acc98_Result& result, const Unk_855db0_Arg& arg);
struct Unk_8551b0_Arg;
void Unk_8551b0(Unk_23ae720* self, Unk_23acc98_Result& result, const Unk_8551b0_Arg& arg);
struct Unk_856990_Arg;
void Unk_856990(Unk_23ae900* self, Unk_23acc98_Result& result, const Unk_856990_Arg& arg);
struct Unk_8643c0_Arg;
void Unk_8643c0(Unk_23b13a0* self, Unk_23acc98_Result& result, const Unk_8643c0_Arg& arg);
struct Unk_8559c0_Arg;
void Unk_8559c0(Unk_23ae7a0* self, Unk_23acc98_Result& result, const Unk_8559c0_Arg& arg);
struct Unk_8566e0_Arg;
void Unk_8566e0(Unk_23ae8e0* self, Unk_23acc98_Result& result, const Unk_8566e0_Arg& arg);
struct Unk_853920_Arg;
void Unk_853920(Unk_23ae5a0* self, Unk_23acc98_Result& result, const Unk_853920_Arg& arg);
struct Unk_83c7b0_Arg;
void Unk_83c7b0(Unk_23ad798* self, Unk_23acc98_Result& result, const Unk_83c7b0_Arg& arg);
struct Unk_863990_Arg;
void Unk_863990(Unk_23b12a0* self, Unk_23acc98_Result& result, const Unk_863990_Arg& arg);
struct Unk_864a80_Arg;
void Unk_864a80(Unk_23b1460* self, Unk_23acc98_Result& result, const Unk_864a80_Arg& arg);
struct Unk_862f30_Arg;
void Unk_862f30(Unk_23b1200* self, Unk_23acc98_Result& result, const Unk_862f30_Arg& arg);
struct Unk_854e40_Arg;
void Unk_854e40(Unk_23ae6e0* self, Unk_23acc98_Result& result, const Unk_854e40_Arg& arg);
struct Unk_853660_Arg;
void Unk_853660(Unk_23ae580* self, Unk_23acc98_Result& result, const Unk_853660_Arg& arg);
struct Unk_847520_Arg;
void Unk_847520(Unk_23ade38* self, Unk_23acc98_Result& result, const Unk_847520_Arg& arg);
struct Unk_863050_Arg;
void Unk_863050(Unk_23b1220* self, Unk_23acc98_Result& result, const Unk_863050_Arg& arg);
struct Unk_8557b0_Arg;
void Unk_8557b0(Unk_23ae780* self, Unk_23acc98_Result& result, const Unk_8557b0_Arg& arg);

// 0x710081a720
bool Unk_81a720(const Unk_819600_Self* self, const Unk_8559c0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8559c0(Unk_7e0080_Gete40(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a760
bool Unk_81a760(const Unk_819600_Self* self, const Unk_8566e0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8566e0(Unk_7e0080_Getda0(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a7a0
void Unk_81a7a0(const Unk_819600_Self* self, const Unk_855db0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_855db0(Unk_7e0080_Get9e0(self->field_20), result, arg);
}

// 0x710081a7d0
bool Unk_81a7d0(const Unk_819600_Self* self, const Unk_853920_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_853920(Unk_7e0080_Get10e0(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a810
void Unk_81a810(const Unk_819600_Self* self, const Unk_8551b0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8551b0(Unk_7e0080_Get10a0(self->field_20), result, arg);
}

// 0x710081a840
bool Unk_81a840(const Unk_819600_Self* self, const Unk_83c7b0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_83c7b0(Unk_7e0080_Get740(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a880
bool Unk_81a880(const Unk_819600_Self* self, const Unk_863990_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_863990(Unk_7e0080_Getd40(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a8c0
bool Unk_81a8c0(const Unk_819600_Self* self, const Unk_864a80_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_864a80(Unk_7e0080_Getd60(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a900
bool Unk_81a900(const Unk_819600_Self* self, const Unk_862f30_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_862f30(Unk_7e0080_Gete20(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a940
bool Unk_81a940(const Unk_819600_Self* self, const Unk_854e40_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_854e40(Unk_7e0080_Get11a0(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a980
bool Unk_81a980(const Unk_819600_Self* self, const Unk_853660_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_853660(Unk_7e0080_Getd00(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a9c0
bool Unk_81a9c0(const Unk_819600_Self* self, const Unk_847520_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_847520(Unk_7e0080_Geta00(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081aa00
bool Unk_81aa00(const Unk_819600_Self* self, const Unk_863050_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_863050(Unk_7e0080_Get11c0(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081aa40
void Unk_81aa40(const Unk_819600_Self* self, const Unk_856990_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_856990(Unk_7e0080_Get9c0(self->field_20), result, arg);
}

// 0x710081aa70
bool Unk_81aa70(const Unk_819600_Self* self, const Unk_8557b0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8557b0(Unk_7e0080_Getc60(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081aab0
void Unk_81aab0(const Unk_819600_Self* self, const Unk_8643c0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8643c0(Unk_7e0080_Get1080(self->field_20), result, arg);
}
