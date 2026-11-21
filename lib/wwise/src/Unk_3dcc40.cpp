// Scope: common
// An effect between a source and what plays it (vtable 0x7102384c90).
// Written from the executable. Placeholder names.
#include "Unk_2384c90.h"

// 0x71003dcc40: the destructor
void Unk_3dcc40(Unk_2384c90_T* self) {
    *reinterpret_cast<void***>(self) = Unk_2384c90_Vtable + 2;
    Unk_2380be8_Dtor(&self->field_20);
}

// 0x71003dcc70: the deleting destructor
void Unk_3dcc70(Unk_2384c90_T* self) {
    *reinterpret_cast<void***>(self) = Unk_2384c90_Vtable + 2;
    Unk_2380be8_Dtor(&self->field_20);
    operator delete(self);
}

// 0x71003dcd10
u32 Unk_3dcd10(Unk_2384c90_T* self, u64 arg1, bool arg2) {
    if (self->field_88)
        return 1;
    return self->field_8->vf6(arg1, arg2);
}

// 0x71003dce10
void Unk_3dce10(Unk_2384c90_T* self) {
    Unk_362360(reinterpret_cast<Unk_362360_T*>(&self->field_20));
    Unk_24df148_Object* object = self->field_18;
    if (object != nullptr) {
        int pool = Unk_2381488;
        object->vf0();
        Unk_3047c0(pool, object);
        self->field_18 = nullptr;
    }
}
