// Scope: common
// The object built at 0x7100fd7eb0: its references, its count and its name.
// Placeholder names: rename once the class is known.
#include "unsorted/unk_fd7eb0/Unk_fd7eb0.h"

#include <utility>

#include "gflib3/Unk_239a418_Make.h"
#include "unsorted/Unk_112dd40.h"

// 0x7100fd7f40
void Unk_fd7f40_setRef(Unk_fd7eb0* self, const Unk_fd7eb0_Ref& ref) {
    Unk_fd7eb0_Assign(self->field_70, ref);
}

// 0x7100fd7fb0
Unk_fd7eb0_Ref Unk_fd7fb0_getRef(const Unk_fd7eb0* self) {
    return self->field_70;
}

// 0x7100fd7fd0
// The copy is moved out (no copy elision): the pointer is stored after the
// reference is added.
Unk_fd7eb0_Ref Unk_fd7fd0_getRef(const Unk_fd7eb0* self) {
    Unk_fd7eb0_Ref ref(self->field_68->field_d80->field_58);
    return std::move(ref);
}

// 0x7100fd8010
Unk_fd7eb0_Ref Unk_fd8010_getRef(const Unk_fd7eb0* self) {
    Unk_fd7eb0_Ref ref;
    Unk_fd7eb0_ef0* source = self->field_68->field_ef0;
    if (source == nullptr)
        return Unk_fd7eb0_Ref();
    Unk_Assign(ref, source->vf2());
    return ref;
}

// 0x7100fd8060
void Unk_fd8060_setName(Unk_fd7eb0* self, const char* name) {
    self->field_78 = Unk_112dd40_Hash(name);
}

static s32 Unk_fd7eb0_GetCount(const Unk_fd7eb0* self) {
    s32 count = self->field_68->field_8c - 1;
    return count < 0 ? 0 : count;
}

// 0x7100fd80e0
s32 Unk_fd80e0_addCount(Unk_fd7eb0* self) {
    self->field_68->field_8c++;
    return Unk_fd7eb0_GetCount(self);
}

// 0x7100fd8110
s32 Unk_fd8110_getCount(const Unk_fd7eb0* self) {
    return Unk_fd7eb0_GetCount(self);
}
