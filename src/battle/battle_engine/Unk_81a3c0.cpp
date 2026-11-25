// Scope: common
// Battle event handler helpers (0x710081a3c0-0x710081a714): each passes its
// parameter block to one of the battle state's handler objects, with a result
// on the stack, and returns the result's flag (or nothing). Placeholder names.
#include "battle/battle_engine/Unk_81a030.h"

// The handler objects' functions (game/unk_82e410), declared as Handler.h
// declares them.
struct Unk_857340_Arg;
void Unk_857340(Unk_23ae980* self, Unk_23acc98_Result& result, const Unk_857340_Arg& arg);
struct Unk_863bd0_Arg;
void Unk_863bd0(Unk_23b12e0* self, Unk_23acc98_Result& result, const Unk_863bd0_Arg& arg);
struct Unk_864790_Arg;
void Unk_864790(Unk_23b1420* self, Unk_23acc98_Result& result, const Unk_864790_Arg& arg);
struct Unk_856ad0_Arg;
void Unk_856ad0(Unk_23ae920* self, Unk_23acc98_Result& result, const Unk_856ad0_Arg& arg);
struct Unk_83ddc0_Arg;
void Unk_83ddc0(Unk_23ad898* self, Unk_23acc98_Result& result, const Unk_83ddc0_Arg& arg);
struct Unk_838f90_Arg;
void Unk_838f90(Unk_23ad478* self, Unk_23acc98_Result& result, const Unk_838f90_Arg& arg);
struct Unk_854b80_Arg;
void Unk_854b80(Unk_23ae6c0* self, Unk_23acc98_Result& result, const Unk_854b80_Arg& arg);
struct Unk_850fb0_Arg;
void Unk_850fb0(Unk_23ae3c0* self, Unk_23acc98_Result& result, const Unk_850fb0_Arg& arg);
struct Unk_857770_Arg;
void Unk_857770(Unk_23ae9e0* self, Unk_23acc98_Result& result, const Unk_857770_Arg& arg);
struct Unk_856020_Arg;
void Unk_856020(Unk_23ae840* self, Unk_23acc98_Result& result, const Unk_856020_Arg& arg);
struct Unk_855cb0_Arg;
void Unk_855cb0(Unk_23ae7e0* self, Unk_23acc98_Result& result, const Unk_855cb0_Arg& arg);
struct Unk_855ba0_Arg;
void Unk_855ba0(Unk_23ae7c0* self, Unk_23acc98_Result& result, const Unk_855ba0_Arg& arg);
struct Unk_8636a0_Arg;
void Unk_8636a0(Unk_23b1280* self, Unk_23acc98_Result& result, const Unk_8636a0_Arg& arg);

// A leaf function with its own placeholder types (src/unsorted/leaf).
struct Unk_856d80_arg1 {
    u8 field_0;
};
struct Unk_856d80_arg2;
void Unk_856d80_call(void* self, Unk_856d80_arg1* value, Unk_856d80_arg2* arg2);

// 0x710081a3c0
u8 Unk_81a3c0(const Unk_819600_Self* self, Unk_856d80_arg2* arg) {
    Unk_856d80_arg1 result;
    Unk_856d80_call(Unk_7e0080_Getaa0(self->field_20), &result, arg);
    return result.field_0;
}

// 0x710081a400
bool Unk_81a400(const Unk_819600_Self* self, const Unk_857340_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_857340(Unk_7e0080_Gete00(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a440
void Unk_81a440(const Unk_819600_Self* self, const Unk_863bd0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_863bd0(Unk_7e0080_Getf40(self->field_20), result, arg);
}

// 0x710081a470
void Unk_81a470(const Unk_819600_Self* self, const Unk_864790_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_864790(Unk_7e0080_Get1220(self->field_20), result, arg);
}

// 0x710081a4a0
bool Unk_81a4a0(const Unk_819600_Self* self, const Unk_856ad0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_856ad0(Unk_7e0080_Geta80(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a4e0
void Unk_81a4e0(const Unk_819600_Self* self, const Unk_83ddc0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_83ddc0(Unk_7e0080_Get800(self->field_20), result, arg);
}

// 0x710081a510
bool Unk_81a510(const Unk_819600_Self* self, const Unk_838f90_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_838f90(Unk_7e0080_Getfe0(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a550
bool Unk_81a550(const Unk_819600_Self* self, const Unk_854b80_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_854b80(Unk_7e0080_Get1180(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a590
void Unk_81a590(const Unk_819600_Self* self, const Unk_82c210_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_82c210(Unk_7e0080_Get2c0(self->field_20), result, arg);
}

// 0x710081a5c0
bool Unk_81a5c0(const Unk_819600_Self* self, const Unk_850fb0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_850fb0(Unk_7e0080_Get1aa0(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a600
bool Unk_81a600(const Unk_819600_Self* self, const Unk_857770_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_857770(Unk_7e0080_Get1260(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081a640
void Unk_81a640(const Unk_819600_Self* self, const Unk_856020_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_856020(Unk_7e0080_Getb00(self->field_20), result, arg);
}

// 0x710081a680
void Unk_81a680(const Unk_819600_Self* self, const Unk_855cb0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_855cb0(Unk_7e0080_Get1240(self->field_20), result, arg);
}

// 0x710081a6b0
void Unk_81a6b0(const Unk_819600_Self* self, const Unk_855ba0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_855ba0(Unk_7e0080_Getfc0(self->field_20), result, arg);
}

// 0x710081a6e0
bool Unk_81a6e0(const Unk_819600_Self* self, const Unk_8636a0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8636a0(Unk_7e0080_Getbc0(self->field_20), result, arg);
    return result.field_0;
}
