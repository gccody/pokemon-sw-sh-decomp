// Scope: common
// Functions that size an array of pointers (Unk_Array) and clear it: one per
// class, with the same code. Placeholder names.
#include "containers.h"

struct Unk_3352d0_T {
    Unk_Array<void*> field_0;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_3352d0_T, field_10, 0x10);

static inline bool Unk_3352d0_Init(Unk_3352d0_T* self, u32 size) {
    self->field_10 = 0;
    if (!self->field_0.Resize(size))
        return false;
    for (u32 i = 0; i < self->field_0.Length(); i++)
        self->field_0.field_0[i] = nullptr;
    return true;
}

// 0x71003352d0
bool Unk_3352d0(Unk_3352d0_T* self, u32 size) {
    return Unk_3352d0_Init(self, size);
}

// 0x710034a670
bool Unk_34a670(void* self, u32 size) {
    return Unk_3352d0_Init(static_cast<Unk_3352d0_T*>(self), size);
}

// 0x710038ea80
bool Unk_38ea80(Unk_3352d0_T* self, u32 size) {
    return Unk_3352d0_Init(self, size);
}

// 0x710039a990
bool Unk_39a990(Unk_3352d0_T* self, u32 size) {
    return Unk_3352d0_Init(self, size);
}

// 0x710039aae0
bool Unk_39aae0(Unk_3352d0_T* self, u32 size) {
    return Unk_3352d0_Init(self, size);
}

// 0x71003bac50
bool Unk_3bac50(Unk_3352d0_T* self, u32 size) {
    return Unk_3352d0_Init(self, size);
}

// 0x71003bada0
bool Unk_3bada0(Unk_3352d0_T* self, u32 size) {
    return Unk_3352d0_Init(self, size);
}
