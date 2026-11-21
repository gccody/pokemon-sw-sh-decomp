// Scope: common
// Three indexed classes of one shape (Unk_360c20_T): their creation
// functions, which construct the object and add it to its index, and their
// destructor. Placeholder names.
#include "Unk_360c20.h"

extern void* Unk_2380888[];
extern void* Unk_2380a38[];
extern void* Unk_2380960[];
extern void* Unk_2380b10[];

template <void** Vtable, u32 Offset>
static inline Unk_360c20_T* Unk_360c20_Create(u32 id) {
    Unk_360c20_T* self = static_cast<Unk_360c20_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_360c20_T)));
    if (self != nullptr) {
        Unk_363510(self, id);
        new (&self->field_18) Unk_2380c68;
        self->field_30 = 0xffffffff;
        for (int i = 0; i < 8; i++)
            (&self->field_38)[i] = nullptr;
        Unk_SetVtable(self, Vtable);
        Unk_SetVtable(&self->field_18, Vtable + 8);
        Unk_IndexedAdd<Offset>(self);
    }
    return self;
}

// 0x7100360c20
Unk_360c20_T* Unk_360c20(u32 id) {
    return Unk_360c20_Create<Unk_2380a38, 0x230>(id);
}

// 0x7100360ec0
Unk_360c20_T* Unk_360ec0(u32 id) {
    return Unk_360c20_Create<Unk_2380960, 0x2a0>(id);
}

// 0x7100361160
Unk_360c20_T* Unk_361160(u32 id) {
    return Unk_360c20_Create<Unk_2380b10, 0x268>(id);
}

// 0x71003627c0
// NON_MATCHING: the loads of field_50's items and length before the loop are
// in the other order.
void Unk_3627c0(void* self_) {
    Unk_360c20_T* self = static_cast<Unk_360c20_T*>(self_);
    Unk_SetVtable(self, Unk_2380888);
    Unk_SetVtable(&self->field_18, Unk_2380888 + 8);
    for (auto it = self->field_50.Begin(); it != self->field_50.End(); ++it)
        (*it).field_10.Unset();
    self->field_50.Term();
    self->field_60.Term();
    self->field_40.Term();
    if (self->field_38 != nullptr)
        self->field_38->vf5(&Unk_2380d00);
    Unk_362a20(&self->field_18);
    Unk_IndexedDtor(self);
}
