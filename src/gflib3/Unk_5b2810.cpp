// Scope: common
// Unk_2398ab8's reference counting and the callables Unk_2398848 keeps
// (src/gflib3/Unk_5b2810.h). Placeholder names.
#include "gflib3/Unk_5b2810.h"

#include <utility>

// 0x71005b2810, 0x71005b2ae0 (its thunk from +0x48). The key function: the
// vtables come with it, and with them 0x71005b2e50 (the D2), 0x71005b2ea0 (the
// D0), thunks 0x71005b2eb0/0x71005b2f00 (+0x48) and 0x71005b2f30/0x71005b2f80
// (+0x50), 0x71005b2b70 (the thunk of vf2 from +0x48) and 0x71005b2f90
// (Unk_27715a0::Unk_GetType, which the interface's vf_type calls).
void Unk_2398ab8::vf4() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (handle->field_58 == nullptr)
        handle->field_58 = handle->field_60->vf0();
    ++handle->field_54;
}

// 0x71005b2860, 0x71005b2b30 (its thunk from +0x48)
void Unk_2398ab8::vf5() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (--handle->field_54 == 0) {
        handle->field_60 = nullptr;
        vf3();
    }
}

// 0x71005b2900, 0x71005b2c00 (its thunk from +0x48)
void Unk_2398848::vf30(Unk_2398af8_Callable callable) {
    field_130 = std::move(callable);
}

// 0x71005b2970, 0x71005b2c70 (its thunk from +0x48)
void Unk_2398848::vf31(Unk_2398af8_Callable callable) {
    field_1b0 = std::move(callable);
}

// 0x71005b29e0, 0x71005b2ce0 (its thunk from +0x48)
void Unk_2398848::vf32(Unk_2398af8_Callable callable) {
    field_230 = std::move(callable);
}

// 0x71005b2a50, 0x71005b2d50 (its thunk from +0x48)
void Unk_2398848::vf33(Unk_2398af8_Callable callable) {
    field_2b0 = std::move(callable);
}
