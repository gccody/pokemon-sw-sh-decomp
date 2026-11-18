// Scope: common
//
// gflib3's reference-counted objects (src/gflib3/Unk_239a418.h and
// src/gflib3/Unk_239a4c0.h): the functions of their vtables. Each one's
// first out-of-line virtual function is its key function, so their vtables,
// inline destructors and their thunks are emitted here.
#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_239a4c0.h"

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

// 0x71005e3640; its D0 0x71005e3630 and the thunks from +0x48 0x71005e3690,
// 0x71005e36a0 come with its vtable
void Unk_239a4c0::vf2() {
    Unk_239a418_Allocator* allocator = field_8;
    u64 arg1 = field_10;
    u64 arg2 = field_18;
    u64 arg3 = field_20;
    this->~Unk_239a4c0();
    allocator->vf3(arg1, arg2, arg3);
}
