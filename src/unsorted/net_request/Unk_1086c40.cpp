// Scope: common
// A stored callback called with a copied value, and a function that locks a
// weak handle and passes the object on to Unk_10f5bf0_call. Placeholder
// types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

class Unk_2417b28 : public Unk_239a418 {};

struct Unk_10f5bf0;
void Unk_10f5bf0_call(Unk_10f5bf0* self);

// src/gflib3/Unk_Lock.h, instantiated in src/unsorted/locks/Unk_f9cab0.cpp
template <class T>
Unk_239a418_Ref<T> Unk_Lock(Unk_239a418_Handle* handle);

// A stored callback: called with its storage and the address of its argument.
struct Unk_1086c40_Callback {
    void operator()(u32 value) { field_0(field_20, &value); }

    void (*field_0)(void* arg, u32* value);
    u8 field_8[0x18];
    u8 field_20[0x8];
};
PKMN_OFFSET_ASSERT(Unk_1086c40_Callback, field_20, 0x20);

struct Unk_1086c40_Target {
    u8 field_0[0x60];
    Unk_1086c40_Callback field_60;
};
PKMN_OFFSET_ASSERT(Unk_1086c40_Target, field_60, 0x60);

struct Unk_1086c40 {
    Unk_1086c40_Target* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086c40, field_0, 0x0);

struct Unk_1086c40_arg1 {
    u32 field_0;
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_1086c40_arg1, field_4, 0x4);

// 0x7101086c40
void Unk_1086c40_call(Unk_1086c40* self, Unk_1086c40_arg1* arg) {
    u32 value = arg->field_4;
    self->field_0->field_60(value);
}

struct Unk_1086cf0 {
    Unk_239a418_Handle* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086cf0, field_0, 0x0);

// 0x7101086cf0
void Unk_1086cf0_call(Unk_1086cf0* self) {
    Unk_239a418_Ref<Unk_2417b28> object = self->field_0 != nullptr
                                              ? Unk_Lock<Unk_2417b28>(self->field_0)
                                              : Unk_239a418_Ref<Unk_2417b28>();
    Unk_10f5bf0_call(reinterpret_cast<Unk_10f5bf0*>(object.m_ptr));
}
