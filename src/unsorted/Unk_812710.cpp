// Scope: common
// Battle server command wrappers (continuing Unk_8122b0.cpp): each acts on
// the server's state at +0x20, then queues the command with Unk_8150c0.
// Placeholder names: rename once they're known.
#include "unsorted/Unk_811d90.h"

struct Unk_8185d0;
struct Unk_8185e0;
struct Unk_8185f0;
struct Unk_818600;
struct Unk_818610;
struct Unk_818620;
struct Unk_818630;
struct Unk_818640;

void Unk_818590(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818650(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818690(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8186d0(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2);
void Unk_818720(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2);
void Unk_8185d0_call(const Unk_8185d0* self, u32 value, u32 arg2, u32 arg3, void* arg4, u64 arg5);
void Unk_8185e0_call(const Unk_8185e0* self, u32 value, u32 arg2);
void Unk_8185f0_call(const Unk_8185f0* self, u32 value, u32 arg2, void* arg3);
void Unk_818600_call(const Unk_818600* self, u32 value, u32 arg2);
// Declared void where they're defined, but they return the flag of the call
// they end with (the callers here return bit 0 of w0).
bool Unk_818610_call(const Unk_818610* self, u32 value, u32 arg2);
bool Unk_818620_call(const Unk_818620* self, u32 value, u32 arg2);
bool Unk_818630_call(const Unk_818630* self, u32 value, u64 arg2);
void Unk_818640_call(const Unk_818640* self, u32 value);
// Reads the two values of `self`: *out4 = +4, *out0 = +0.
void Unk_7f8ba0(const void* self, u32* out4, u32* out0);

// 0x7100812710
void Unk_812710(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818590(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x75, pokeId);
}

// NON_MATCHING: the original hands `arg5` on to Unk_8185d0_call as it got it
// (a 32-bit value), but the name callers use, _Z15Unk_8185d0_callPK10Unk_8185d0jjjPvm,
// makes that parameter a u64, which is zero-extended first (mov w5, w5).
// 0x7100812750
void Unk_812750(const Unk_811d90_Self* self, u32 arg1, u32 arg2, u32 arg3, u32* values, u32 arg5) {
    Unk_8185d0_call(reinterpret_cast<const Unk_8185d0*>(self->field_20), arg1, arg2, arg3, values,
                    arg5);
    Unk_8150c0(self->field_18, 0x76, arg1, arg2, static_cast<u8>(arg3), static_cast<u8>(arg5),
               values[0], values[1], values[2], values[3]);
}

// 0x71008127d0
void Unk_8127d0(const Unk_811d90_Self* self, u32 arg1, u32 arg2) {
    Unk_8185e0_call(reinterpret_cast<const Unk_8185e0*>(self->field_20), arg1, arg2);
    Unk_8150c0(self->field_18, 0x77, arg1, arg2);
}

// 0x7100812820
void Unk_812820(const Unk_811d90_Self* self, u32 pokeId, u32 arg2, void* arg3) {
    Unk_8185f0_call(reinterpret_cast<const Unk_8185f0*>(self->field_20), pokeId, arg2, arg3);
    u64 que = self->field_18;
    u32 value4 = 0;
    u32 value0 = 0;
    Unk_7f8ba0(arg3, &value4, &value0);
    Unk_8150c0(que, 0x78, static_cast<u8>(pokeId), arg2, value4, value0);
}

// 0x7100812890
void Unk_812890(const Unk_811d90_Self* self, u32 pokeId, u32 arg2) {
    Unk_818600_call(reinterpret_cast<const Unk_818600*>(self->field_20), pokeId, arg2);
    Unk_8150c0(self->field_18, 0x79, static_cast<u8>(pokeId), arg2);
}

// 0x71008128e0
bool Unk_8128e0(const Unk_811d90_Self* self, u32 pokeId, u32 arg2) {
    bool result =
        Unk_818610_call(reinterpret_cast<const Unk_818610*>(self->field_20), pokeId, arg2);
    Unk_8150c0(self->field_18, 0x7a, static_cast<u8>(pokeId), arg2);
    return result;
}

// 0x7100812930
bool Unk_812930(const Unk_811d90_Self* self, u32 pokeId, u32 arg2) {
    bool result =
        Unk_818620_call(reinterpret_cast<const Unk_818620*>(self->field_20), pokeId, arg2);
    Unk_8150c0(self->field_18, 0x7b, static_cast<u8>(pokeId), arg2);
    return result;
}

// NON_MATCHING: the original hands `arg2` on to Unk_818630_call as it got it
// (a 32-bit value), but the name callers use, _Z15Unk_818630_callPK10Unk_818630jm,
// makes that parameter a u64, which is zero-extended first (mov w2, w2).
// 0x7100812980
bool Unk_812980(const Unk_811d90_Self* self, u32 arg1, u32 arg2) {
    bool result = Unk_818630_call(reinterpret_cast<const Unk_818630*>(self->field_20), arg1, arg2);
    Unk_8150c0(self->field_18, 0x7c, arg1, static_cast<u8>(arg2));
    return result;
}

// 0x71008129d0
void Unk_8129d0(const Unk_811d90_Self* self, u32 value) {
    Unk_818640_call(reinterpret_cast<const Unk_818640*>(self->field_20), value);
    Unk_8150c0(self->field_18, 0x7d, value);
}

// 0x7100812a10
void Unk_812a10(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818650(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x7e, pokeId);
}

// 0x7100812a50
void Unk_812a50(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818690(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x7f, pokeId);
}

// 0x7100812a90
void Unk_812a90(const Unk_811d90_Self* self, u8 pokeId, u32 value) {
    Unk_8186d0(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x80, pokeId, value);
}

// 0x7100812ae0
void Unk_812ae0(const Unk_811d90_Self* self, u8 pokeId, u32 value) {
    Unk_818720(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x81, pokeId, value);
}
