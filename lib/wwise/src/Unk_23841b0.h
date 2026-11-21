#pragma once
// The class under a bus (vtable 0x71023841b0): what it mixes into (a sorted
// array), what plays into it (a list) and two arrays. Written from the
// executable. Placeholder names.
#include "Unk_24df148.h"
#include "sorted_array.h"

struct Unk_23841b0_T;
typedef Unk_ListLight<Unk_369930> Unk_23841b0_List;
typedef Unk_SortedKeyArray<Unk_23841b0_T*, Unk_23841b0_T*, Unk_KeyIsItem<Unk_23841b0_T*>,
                           Unk_Pool2381488>
    Unk_23841b0_Set;

struct Unk_23841b0_T {
    void** field_0;  // vptr
    u8 _8[8];
    Unk_23841b0_Set field_10;  // what it plays into
    Unk_24df148_Mix* field_20;
    Unk_Array<u64> field_28;
    u8 _38[8];
    Unk_23841b0_List field_40;  // what plays into it
    Unk_Array<u64> field_50;
    u8 field_60_0 : 1;
    u8 field_60_1 : 1;
};
PKMN_OFFSET_ASSERT(Unk_23841b0_T, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_23841b0_T, field_50, 0x50);

u64 Unk_369930_get(const Unk_369930* self);
Unk_23841b0_List::IteratorEx Unk_3cf8e0(Unk_23841b0_T* self, Unk_23841b0_List::IteratorEx& it);
void Unk_3cf7b0(void* self);
void Unk_3cfa80(Unk_24df148_Bus* self);
