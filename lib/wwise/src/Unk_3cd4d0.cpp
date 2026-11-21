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
