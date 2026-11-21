// Scope: common
// The class with the vtable 0x7102384248: an object and, at 0x10, two
// filters. Written from the executable. Placeholder names.
#include "Unk_2384190.h"
#include "Unk_PlacementNew.h"

// What the object at 8 is.
struct Unk_2384248_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u32 arg1);
    virtual u32 vf6(u64 arg1, bool arg2);
    virtual u32 vf7();
    virtual f32 vf8();
};

struct Unk_2384248_T {
    void** field_0;  // vptr
    Unk_2384248_Obj* field_8;
    Unk_2384190 field_10;
};

extern void* Unk_2384248[];

// 0x71003d1330
void Unk_3d1330(Unk_2384248_T* self, Unk_3cd530_Arg* arg) {
    if (arg->field_0 != nullptr)
        Unk_3cd530(&self->field_10, arg);
}

// 0x71003d13b0
void Unk_3d13b0(Unk_2384248_T* self, u32 arg1) {
    Unk_3cd4d0(&self->field_10);
    if (self->field_8 != nullptr)
        self->field_8->vf5(arg1);
}

// 0x71003d1400: the destructor
void Unk_3d1400(Unk_2384248_T* self) {
    self->field_0 = Unk_2384248 + 2;
    new (&self->field_10) Unk_2384190;
}

// 0x71003d1420: the deleting destructor
void Unk_3d1420(Unk_2384248_T* self) {
    self->field_0 = Unk_2384248 + 2;
    new (&self->field_10) Unk_2384190;
    operator delete(self);
}

// 0x71003d1460
u32 Unk_3d1460(Unk_2384248_T* self, u64 arg1, bool arg2) {
    if (self->field_8 != nullptr)
        return self->field_8->vf6(arg1, arg2);
    return 1;
}

// 0x71003d1480
u32 Unk_3d1480(Unk_2384248_T* self) {
    if (self->field_8 != nullptr)
        return self->field_8->vf7();
    return 2;
}

// 0x71003d14a0
f32 Unk_3d14a0(Unk_2384248_T* self) {
    if (self->field_8 != nullptr)
        return self->field_8->vf8();
    return 0.0f;
}
