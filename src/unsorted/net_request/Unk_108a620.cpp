// Scope: common
// Leaf functions that call a stored callback on the object a handle points
// to, and a function that locks a weak handle and passes the object on to
// Unk_10f5bf0_call. Placeholder types: rename and move once the owning
// classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

class Unk_2417b28 : public Unk_239a418 {};

struct Unk_10f5bf0;
void Unk_10f5bf0_call(Unk_10f5bf0* self);

// src/gflib3/Unk_Lock.h, instantiated in src/unsorted/locks/Unk_f9cab0.cpp
template <class T>
Unk_239a418_Ref<T> Unk_Lock(Unk_239a418_Handle* handle);

struct Unk_108a9c0_Target {
    u8 field_0[0x60];
    void (*field_60)(void* arg);
    u8 field_68[0x18];
    u8 field_80[0x8];
};
PKMN_OFFSET_ASSERT(Unk_108a9c0_Target, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_108a9c0_Target, field_80, 0x80);

struct Unk_108a9c0 {
    Unk_108a9c0_Target* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108a9c0, field_0, 0x0);

// 0x710108a9c0
void Unk_108a9c0_call(Unk_108a9c0* self) {
    Unk_108a9c0_Target* target = self->field_0;
    target->field_60(target->field_80);
}

struct Unk_108aa40_Target {
    u8 field_0[0x60];
    void (*field_60)(void* arg, u32* value);
    u8 field_68[0x18];
    u8 field_80[0x8];
};
PKMN_OFFSET_ASSERT(Unk_108aa40_Target, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_108aa40_Target, field_80, 0x80);

struct Unk_108aa40 {
    Unk_108aa40_Target* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aa40, field_0, 0x0);

struct Unk_108aa40_arg1 {
    u32 field_0;
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_108aa40_arg1, field_4, 0x4);

// NON_MATCHING: instruction order and register allocation: the original
// loads self->field_0 into x9 before storing the copied value (w8), and the
// callback pointer goes in x8; this stores first and swaps x8/x9. Calling
// through an inline wrapper on either struct doesn't change it.
// 0x710108aa40
void Unk_108aa40_call(Unk_108aa40* self, Unk_108aa40_arg1* arg) {
    u32 value = arg->field_4;
    Unk_108aa40_Target* target = self->field_0;
    target->field_60(target->field_80, &value);
}

struct Unk_108aaf0 {
    Unk_239a418_Handle* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aaf0, field_0, 0x0);

// 0x710108aaf0
void Unk_108aaf0_call(Unk_108aaf0* self) {
    Unk_239a418_Ref<Unk_2417b28> object = self->field_0 != nullptr
                                              ? Unk_Lock<Unk_2417b28>(self->field_0)
                                              : Unk_239a418_Ref<Unk_2417b28>();
    Unk_10f5bf0_call(reinterpret_cast<Unk_10f5bf0*>(object.m_ptr));
}
