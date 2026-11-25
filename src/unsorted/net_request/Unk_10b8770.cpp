// Scope: common
// Leaf functions that call a stored callback on the object a handle points
// to, and functions that lock a weak handle and pass the object on to
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

struct Unk_10b8780_Target {
    u8 field_0[0x60];
    void (*field_60)(void* arg);
    u8 field_68[0x18];
    u8 field_80[0x8];
};
PKMN_OFFSET_ASSERT(Unk_10b8780_Target, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_10b8780_Target, field_80, 0x80);

struct Unk_10b8780 {
    Unk_10b8780_Target* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8780, field_0, 0x0);

// 0x71010b8780
void Unk_10b8780_call(Unk_10b8780* self) {
    Unk_10b8780_Target* target = self->field_0;
    target->field_60(target->field_80);
}

struct Unk_10b8800_Target {
    u8 field_0[0x60];
    void (*field_60)(void* arg);
    u8 field_68[0x18];
    u8 field_80[0x8];
};
PKMN_OFFSET_ASSERT(Unk_10b8800_Target, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_10b8800_Target, field_80, 0x80);

struct Unk_10b8800 {
    Unk_10b8800_Target* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8800, field_0, 0x0);

// 0x71010b8800
void Unk_10b8800_call(Unk_10b8800* self) {
    Unk_10b8800_Target* target = self->field_0;
    target->field_60(target->field_80);
}

struct Unk_10b8880 {
    Unk_239a418_Handle* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8880, field_0, 0x0);

// 0x71010b8880
void Unk_10b8880_call(Unk_10b8880* self) {
    Unk_239a418_Ref<Unk_2417b28> object = self->field_0 != nullptr
                                              ? Unk_Lock<Unk_2417b28>(self->field_0)
                                              : Unk_239a418_Ref<Unk_2417b28>();
    Unk_10f5bf0_call(reinterpret_cast<Unk_10f5bf0*>(object.m_ptr));
}
