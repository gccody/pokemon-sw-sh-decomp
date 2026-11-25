// Scope: common
// Functions that move a nest hole object's state on (the value at +0x7c),
// clearing its two flags at +0x385, once a weak handle's object still has
// references. Placeholder types: rename and move once the owning classes are
// known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

class Unk_2401e68 : public Unk_239a418 {
public:
    u32 field_60;
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_2401e68, field_64, 0x64);

// src/gflib3/Unk_Lock.h, instantiated in src/unsorted/locks/Unk_f9d830.cpp
template <class T>
Unk_239a418_Ref<T> Unk_Lock(Unk_239a418_Handle* handle);

struct Unk_fa8540_0 {
    u8 _0[0x7c];
    u32 field_7c;
    Unk_239a418_Handle* field_80;
    u8 _88[0x340 - 0x88];
    void* field_340;
    u64 field_348;
    u8 _350[0x385 - 0x350];
    bool field_385;
    bool field_386;
};
PKMN_OFFSET_ASSERT(Unk_fa8540_0, field_7c, 0x7c);
PKMN_OFFSET_ASSERT(Unk_fa8540_0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_fa8540_0, field_340, 0x340);
PKMN_OFFSET_ASSERT(Unk_fa8540_0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_fa8540_0, field_385, 0x385);
PKMN_OFFSET_ASSERT(Unk_fa8540_0, field_386, 0x386);

struct Unk_fa8540 {
    Unk_fa8540_0* field_0;
    Unk_239a418_Handle* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa8540, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fa8540, field_8, 0x8);

void Unk_eb6230(void*, u32);
void Unk_eb77f0(u64);

// 0x7100fa8540
void Unk_fa8540_reset(const Unk_fa8540* self) {
    Unk_fa8540_0* obj = self->field_0;
    obj->field_385 = false;
    obj->field_386 = false;
    obj->field_7c = 1;
}

// 0x7100fa85d0
void Unk_fa85d0_reset(const Unk_fa8540* self) {
    Unk_239a418_Handle* handle = self->field_8;
    if (handle == nullptr)
        return;
    Unk_fa8540_0* obj = self->field_0;
    if (handle->field_54.load(std::memory_order_acquire) == 0)
        return;
    obj->field_385 = false;
    obj->field_386 = false;
    obj->field_7c = 9;
}

// 0x7100fa86a0
void Unk_fa86a0_reset(const Unk_fa8540* self) {
    Unk_239a418_Handle* handle = self->field_8;
    if (handle == nullptr)
        return;
    Unk_fa8540_0* obj = self->field_0;
    if (handle->field_54.load(std::memory_order_acquire) == 0)
        return;
    {
        Unk_239a418_Ref<Unk_2401e68> object = obj->field_80 != nullptr
                                                  ? Unk_Lock<Unk_2401e68>(obj->field_80)
                                                  : Unk_239a418_Ref<Unk_2401e68>();
        object.m_ptr->field_64 = 1;
    }
    Unk_eb6230(obj->field_340, 1);
    Unk_eb77f0(obj->field_348);
    obj->field_385 = false;
    obj->field_386 = false;
    obj->field_7c = 0x11;
}
