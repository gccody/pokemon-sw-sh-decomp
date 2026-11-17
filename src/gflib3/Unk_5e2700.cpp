// Scope: common
//
// gflib3's reference-counted object (src/gflib3/Unk_239a418.h): the
// functions of its vtables. vf2 is its key function, so its vtables, inline
// destructors and their thunks are emitted here.
#include "gflib3/Unk_239a418.h"

// 0x71005e2700
void Unk_239a418::vf3() {
    Unk_239a418_Allocator* allocator = field_8;
    u64 arg1 = field_10;
    u64 arg2 = field_18;
    u64 arg3 = field_20;
    this->~Unk_239a418();
    allocator->vf3(arg1, arg2, arg3);
}

// 0x71005e3050, 0x71005e3290 (its thunk from +0x48)
Unk_239a418_Ref<Unk_239a418_Handle> Unk_239a418::vf2() {
    return m_handle;
}

// 0x71005e3070, 0x71005e3200 (its thunk from +0x48)
void Unk_239a418::vf4() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (handle->field_58 == nullptr)
        handle->field_58 = handle->field_60->vf0();
    ++handle->field_54;
}

// 0x71005e30c0, 0x71005e3250 (its thunk from +0x48)
void Unk_239a418::vf5() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (--handle->field_54 == 0) {
        handle->field_60 = nullptr;
        vf3();
    }
}
