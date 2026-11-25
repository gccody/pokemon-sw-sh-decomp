// Scope: common
//
// Unk_23c1b18's slots 2, 3 and 4 of its +0x48 vtable (0x71023c1b68): the
// this-adjusting copies of its add a reference, drop one and the handle
// (Unk_978800, Unk_978850 and Unk_978790 in src/unsorted/Unk_9782c0.cpp),
// with the bodies inlined. Unk_23c1b18 is declared by the virtual generator
// without its bases, so they're written as free functions over the interface.
// Placeholder names: rename once the class is known.
#include "gflib3/Unk_239a418.h"

// 0x7100978a60
void Unk_978a60(Unk_239a458* self) {
    Unk_239a418_Handle* handle = static_cast<Unk_239a418&>(*self).m_handle.m_ptr;
    if (handle->field_58 == nullptr)
        handle->field_58 = handle->field_60->vf0();
    ++handle->field_54;
}

// 0x7100978ab0
void Unk_978ab0(Unk_239a458* self) {
    Unk_239a418& object = static_cast<Unk_239a418&>(*self);
    Unk_239a418_Handle* handle = object.m_handle.m_ptr;
    if (--handle->field_54 == 0) {
        handle->field_60 = nullptr;
        object.vf3();
    }
}

// 0x7100978af0
Unk_239a418_Ref<Unk_239a418_Handle> Unk_978af0(const Unk_239a458* self) {
    return static_cast<const Unk_239a418&>(*self).m_handle;
}
