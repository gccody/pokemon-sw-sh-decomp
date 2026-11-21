// Scope: common
// What the two filters at 0x10 of the class with the vtable 0x7102384248 do
// with their memory. Written from the executable. Placeholder names.
#include "Unk_2384190.h"

#include <string.h>

void Unk_3cd590(Unk_3cd530_Arg* arg, Unk_2384190_State* state, Unk_2384190_Filter* filter);
void Unk_3cdcc0(Unk_3cd530_Arg* arg, Unk_2384190_State* state, Unk_2384190_Filter* filter);

// 0x71003cd4d0: the memory of the filters is empty
void Unk_3cd4d0(Unk_2384190* self) {
    self->field_170.field_c = true;
    if (self->field_10.field_a0 != nullptr)
        memset(self->field_10.field_a0, 0, self->field_10.field_a8);
    self->field_180.field_c = true;
    if (self->field_c0.field_a0 != nullptr)
        memset(self->field_c0.field_a0, 0, self->field_c0.field_a8);
}

// 0x71003cd530
void Unk_3cd530(Unk_2384190* self, Unk_3cd530_Arg* arg) {
    if (self->field_10.field_a0 != nullptr)
        Unk_3cd590(arg, &self->field_170, &self->field_10);
    if (self->field_c0.field_a0 != nullptr)
        Unk_3cdcc0(arg, &self->field_180, &self->field_c0);
}

// What gives the filters their memory, called.
struct Unk_3cd470_Alloc {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(void* memory);
};
extern u8 Unk_2380d10;

static inline Unk_3cd470_Alloc* Unk_3cd470_GetAlloc() {
    return reinterpret_cast<Unk_3cd470_Alloc*>(&Unk_2380d10);
}

// 0x71003cd470: the memory of the filters is given back
void Unk_3cd470(void* object) {
    Unk_2384190* self = static_cast<Unk_2384190*>(object);
    if (self->field_10.field_a0 != nullptr) {
        Unk_3cd470_GetAlloc()->vf3(self->field_10.field_a0);
        self->field_10.field_a0 = nullptr;
    }
    if (self->field_c0.field_a0 != nullptr) {
        Unk_3cd470_GetAlloc()->vf3(self->field_c0.field_a0);
        self->field_c0.field_a0 = nullptr;
    }
}
