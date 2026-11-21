// Scope: common
// Wwise's object index (Unk_334be0.h). Placeholder names.
#include "Unk_334be0.h"

struct Unk_3352d0_T;
bool Unk_3352d0(Unk_3352d0_T* self, u32 size);
void Unk_38fcb0(void* self, u32 id);
extern void* Unk_24bbc08;

template <class T>
static inline bool Unk_334be0_Init(Unk_334be0_Index<T>& index) {
    return Unk_3352d0(reinterpret_cast<Unk_3352d0_T*>(&index.field_20), 11);
}

// 0x7100334be0
bool Unk_334be0_T::Unk_334be0() {
    return Unk_334be0_Init(field_0) && Unk_334be0_Init(field_38) && Unk_334be0_Init(field_70) &&
           Unk_334be0_Init(field_a8) && Unk_334be0_Init(field_e0) && Unk_334be0_Init(field_118) &&
           Unk_334be0_Init(field_150) && Unk_334be0_Init(field_188) &&
           Unk_334be0_Init(field_1c0) && Unk_334be0_Init(field_1f8) &&
           Unk_334be0_Init(field_230) && Unk_334be0_Init(field_268) &&
           Unk_334be0_Init(field_2a0) && Unk_334be0_Init(field_2d8);
}

// NON_MATCHING: the original keeps the last table's address in a register for its loads
// 0x7100334cf0
void Unk_334be0_T::Unk_334cf0() {
    field_0.field_20.field_0.Term();
    field_38.field_20.field_0.Term();
    field_70.field_20.field_0.Term();
    field_a8.field_20.field_0.Term();
    field_e0.field_20.field_0.Term();
    field_118.field_20.field_0.Term();
    field_150.field_20.field_0.Term();
    field_188.field_20.field_0.Term();
    field_1c0.field_20.field_0.Term();
    field_1f8.field_20.field_0.Term();
    field_230.field_20.field_0.Term();
    field_268.field_20.field_0.Term();
    field_2a0.field_20.field_0.Term();
    while (field_2d8.field_20.Length() != 0)
        (*field_2d8.field_20.Begin())->vf3();
    field_2d8.field_20.field_0.Term();
}

// Releases the objects of a table whose IDs have the top bit set.
template <class T>
static inline void Unk_334f70_Release(Unk_334be0_Table<T>& table) {
    auto it = table.Begin();
    while (it != table.End()) {
        T* p = *it;
        ++it;
        if (static_cast<s32>(p->field_10) < 0)
            p->vf3();
    }
}

// NON_MATCHING: the original reloads the bucket array inside the iterator's loop (2 x 5
// instructions)
// 0x7100334f70
void Unk_334be0_T::Unk_334f70() {
    nn::os::LockMutex(&field_0.field_0);
    Unk_334f70_Release(field_0.field_20);
    nn::os::UnlockMutex(&field_0.field_0);
    Unk_334f70_Release(field_268.field_20);
}

// 0x71003350e0
void Unk_334be0_T::Unk_3350e0() {
    nn::os::LockMutex(&field_1c0.field_0);
    auto it = field_1c0.field_20.Begin();
    while (it != field_1c0.field_20.End()) {
        Unk_3350e0_Obj* p = *it;
        ++it;
        Unk_38fcb0(Unk_24bbc08, p->field_6c);
        p->vf3();
    }
    nn::os::UnlockMutex(&field_1c0.field_0);
}

// NON_MATCHING: the original shares one more instruction between the two lookups' exits
// 0x71003351b0
Unk_3476d0_Obj* Unk_3351b0(void* self, u32 id, u32 type) {
    Unk_334be0_T* index = static_cast<Unk_334be0_T*>(self);
    if (type != 0)
        return index->field_38.GetAndAddRef(id);
    return index->field_0.GetAndAddRef(id);
}
