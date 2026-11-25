// Scope: common
//
// Virtual functions of the battle scene classes on Unk_23dc940 and of
// Unk_23c1b18 (an abstract class on Unk_239a418, vtable 0x71023c1b28).
// Placeholder names: rename once the classes are known.
#include "gflib3/Unk_239a418.h"

// What slot 68 of the 70-slot vtables on Unk_23dc940 (0x71023c1698 and four
// more) returns.
struct Unk_9782c0_Result {
    u32 field_0;
    u16 field_4;
    u32 field_8;
    u16 field_c;
    u64 field_10;
    s32 field_18;
};
static_assert(sizeof(Unk_9782c0_Result) == 0x20, "Unk_9782c0_Result");

// 0x71009782c0
Unk_9782c0_Result Unk_9782c0(const void* self) {
    Unk_9782c0_Result result;
    result.field_18 = -1;
    result.field_0 = 0;
    result.field_4 = 0;
    result.field_8 = 0;
    result.field_c = 0;
    result.field_10 = 0;
    return result;
}

// Unk_23c1b18's slots 2, 4 and 5: the same as Unk_239a418's own (the handle,
// add a reference, drop one), emitted again for it.

// 0x7100978790
Unk_239a418_Ref<Unk_239a418_Handle> Unk_978790(const Unk_239a418* self) {
    return self->m_handle;
}

// 0x7100978800
void Unk_978800(Unk_239a418* self) {
    Unk_239a418_Handle* handle = self->m_handle.m_ptr;
    if (handle->field_58 == nullptr)
        handle->field_58 = handle->field_60->vf0();
    ++handle->field_54;
}

// 0x7100978850
void Unk_978850(Unk_239a418* self) {
    Unk_239a418_Handle* handle = self->m_handle.m_ptr;
    if (--handle->field_54 == 0) {
        handle->field_60 = nullptr;
        self->vf3();
    }
}
