// Scope: common
// Battle server command wrappers that only queue the command for the
// clients. Placeholder names: rename once they're known.
#include "unsorted/Unk_811d90.h"

void Unk_817540(const Unk_8139c0_Self* self, u8 pokeId, u8 value);

// The two bytes Unk_812260 passes on.
struct Unk_812260_Arg {
    u8 field_0;
    u8 _1;
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_812260_Arg, field_2, 0x2);

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100812040
void Unk_812040(const Unk_811d90_Self* self,
                u8 arg1,
                u32 arg2,
                u8 arg3,
                u16 arg4,
                u16 arg5,
                u16 arg6) {
    Unk_8150c0(self->field_18, 0xaf, arg1, arg2, arg3, arg4, arg5, arg6);
}

// 0x7100812080
void Unk_812080(const Unk_811d90_Self* self, u8 value) {
    Unk_8150c0(self->field_18, 0xa5, value);
}

// 0x7100812090
void Unk_812090(void* self, u8 value) {
    Unk_8150c0(static_cast<const Unk_811d90_Self*>(self)->field_18, 0x8a, value);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x71008120a0
void Unk_8120a0(void* self, u8 arg1, u32 arg2, u32 arg3) {
    Unk_8150c0(static_cast<const Unk_811d90_Self*>(self)->field_18, 0x88, arg1, arg2,
               static_cast<u16>(arg3));
}

// 0x71008120c0
void Unk_8120c0(const Unk_811d90_Self* self, u16 value) {
    Unk_8150c0(self->field_18, 0xa1, value);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x71008120d0
void Unk_8120d0(const Unk_811d90_Self* self, u32 arg1, u32 arg2, u16 arg3) {
    Unk_8150c0(self->field_18, 0xa3, arg1, arg2, arg3);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x71008120f0
void Unk_8120f0(const Unk_811d90_Self* self, u8 arg1, u8 arg2) {
    Unk_8150c0(self->field_18, 0xaa, arg1, arg2);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100812110
void Unk_812110(const Unk_811d90_Self* self, u8 pokeId, u8 value) {
    Unk_817540(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x6c, pokeId, value);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100812160
void Unk_812160(const Unk_811d90_Self* self, u8 arg1, u8 arg2, u8 arg3, bool flag) {
    Unk_8150c0(self->field_18, 0x93, arg1, arg2, arg3, flag);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100812190
void Unk_812190(const Unk_811d90_Self* self, u32 arg1, u16 arg2) {
    Unk_8150c0(self->field_18, 0x92, arg1, arg2);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x71008121b0
void Unk_8121b0(const Unk_811d90_Self* self, u8 arg1, u32 arg2, u32 arg3) {
    Unk_8150c0(self->field_18, 0xab, arg1, arg2, arg3);
}

// NON_MATCHING: the original passes `value` on as it got it (a u32), but the
// name callers use, _Z10Unk_8121d0Pvh, makes it a u8, which is zero-extended.
// 0x71008121d0
void Unk_8121d0(void* self, u8 value) {
    Unk_8150c0(static_cast<const Unk_811d90_Self*>(self)->field_18, 0xa9, value);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x71008121e0
void Unk_8121e0(const Unk_811d90_Self* self,
                u32 arg1,
                u32 arg2,
                u8 arg3,
                u8 arg4,
                u8 arg5,
                u8 arg6,
                u16 arg7) {
    Unk_8150c0(self->field_18, 0x9d, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100812240
void Unk_812240(const Unk_811d90_Self* self, u8 arg1, u16 arg2, u8 arg3) {
    Unk_8150c0(self->field_18, 0x9f, arg1, arg3, arg2);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100812260
void Unk_812260(const Unk_811d90_Self* self, const Unk_812260_Arg* arg) {
    u64 que = self->field_18;
    u8 second = arg->field_2;
    u8 first = arg->field_0;
    Unk_8150c0(que, 0x9e, first, second);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100812280
void Unk_812280(const Unk_811d90_Self* self, u8 arg1, u8 arg2, u16 arg3, u16 arg4) {
    Unk_8150c0(self->field_18, 0x84, arg1, arg2, arg3, arg4);
}
