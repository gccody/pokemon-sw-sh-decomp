// Scope: common
// Battle server command wrappers (continuing Unk_812040.cpp): each queues a
// command with Unk_8150c0, most after acting on the server's state at +0x20.
// Placeholder names: rename once they're known.
#include "unsorted/Unk_811d90.h"

void Unk_817270(const Unk_8139c0_Self* self, u8 pokeId, u32 value);
void Unk_818310(const Unk_8139c0_Self* self, u8 pokeId);
// Declared void where it's defined, but it returns the flag of the call it
// ends with (its callers here test bit 0 of w0).
bool Unk_818340(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, u32 arg3);
void Unk_818390(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2);
void Unk_8183e0(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2);
void Unk_818430(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818470(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8184b0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8184f0(const Unk_8139c0_Self* self, u8 pokeId, u8 otherId);
void Unk_818550(const Unk_8139c0_Self* self, u8 pokeId);
u16 Unk_816460(u64 que, u32 id);
// Variadic, like Unk_8150c0: it saves x3..x7 and q0..q7 into its va_list
// area. The name callers use gives it seven fixed u32 parameters.
void Unk_816500(void* que, u32 arg1, u32 id, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
bool Unk_786d90(u16 id);

// The values Unk_8123d0 reads from the queue and Unk_812420 writes back.
struct Unk_8123d0_Arg {
    u16 field_0;
    u16 field_2;
    u8 field_4;
    u16 field_6;
    u16 field_8;
    u16 field_a;
};
PKMN_OFFSET_ASSERT(Unk_8123d0_Arg, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_8123d0_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_8123d0_Arg, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_8123d0_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8123d0_Arg, field_a, 0xa);

// 0x71008122b0
void Unk_8122b0(const Unk_811d90_Self* self, u8 arg1, u16 arg2) {
    Unk_8150c0(self->field_18, 0x83, arg1, arg2);
}

// 0x71008122d0
void Unk_8122d0(const Unk_811d90_Self* self) {
    Unk_8150c0(self->field_18, 0x9a);
}

// 0x71008122e0
void Unk_8122e0(const Unk_811d90_Self* self,
                u8 arg1,
                u32 arg2,
                u32 arg3,
                u32 arg4,
                u32 arg5,
                u32 arg6,
                u32 arg7,
                u32 arg8) {
    Unk_8150c0(self->field_18, 0x9b, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

// 0x7100812330
void Unk_812330(const Unk_811d90_Self* self) {
    Unk_8150c0(self->field_18, 0x9c);
}

// 0x7100812340
void Unk_812340(const Unk_811d90_Self* self, u8 pokeId, u32 value) {
    Unk_817270(self->field_20, pokeId, value);
    Unk_8150c0(self->field_18, 0x6a, pokeId, value);
}

// 0x7100812390
void Unk_812390(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818310(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x50, pokeId);
}

// 0x71008123d0
void Unk_8123d0(const Unk_811d90_Self* self, Unk_8123d0_Arg* arg) {
    arg->field_6 = Unk_816460(self->field_18, 0xb6);
    arg->field_8 = Unk_816460(self->field_18, 0x96);
    arg->field_a = Unk_816460(self->field_18, 0xb7);
}

// NON_MATCHING: Unk_816500 is variadic, but the name callers use
// (_Z10Unk_816500Pvjjjjjjj) has seven fixed parameters, so every call passes
// all of them; the original passes only the ones it uses.
// 0x7100812420
void Unk_812420(const Unk_811d90_Self* self, const Unk_8123d0_Arg* arg) {
    if (arg->field_4) {
        Unk_816500(reinterpret_cast<void*>(self->field_18), arg->field_6, 0xb6, arg->field_0, 0, 0,
                   0, 0);
    }
    Unk_816500(reinterpret_cast<void*>(self->field_18), arg->field_8, 0x96, arg->field_0,
               Unk_786d90(arg->field_2), 0, 0, 0);
    if (arg->field_4) {
        Unk_816500(reinterpret_cast<void*>(self->field_18), arg->field_a, 0xb7, arg->field_0, 0, 0,
                   0, 0);
    }
}

// 0x71008124b0
bool Unk_8124b0(void* self, u8 pokeId, u32 arg2, int arg3) {
    const Unk_811d90_Self* server = static_cast<const Unk_811d90_Self*>(self);
    if (Unk_818340(server->field_20, pokeId, arg2, arg3)) {
        Unk_8150c0(server->field_18, 0x6d, pokeId, arg2, arg3);
        return true;
    }
    return false;
}

// 0x7100812520
void Unk_812520(void* self, u8 pokeId, u32 value) {
    const Unk_811d90_Self* server = static_cast<const Unk_811d90_Self*>(self);
    Unk_818390(server->field_20, pokeId, value);
    Unk_8150c0(server->field_18, 0x6e, pokeId, value);
}

// 0x7100812570
void Unk_812570(void* self, u8 pokeId, u32 value) {
    const Unk_811d90_Self* server = static_cast<const Unk_811d90_Self*>(self);
    Unk_8183e0(server->field_20, pokeId, value);
    Unk_8150c0(server->field_18, 0x6f, pokeId, value);
}

// 0x71008125c0
void Unk_8125c0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818430(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x70, pokeId);
}

// 0x7100812600
void Unk_812600(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818470(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x71, pokeId);
}

// 0x7100812640
void Unk_812640(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_8184b0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x72, pokeId);
}

// 0x7100812680
void Unk_812680(const Unk_811d90_Self* self, u8 pokeId, u8 otherId) {
    Unk_8184f0(self->field_20, pokeId, otherId);
    Unk_8150c0(self->field_18, 0x73, pokeId, otherId);
}

// 0x71008126d0
void Unk_8126d0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818550(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x74, pokeId);
}
