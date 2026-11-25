// Scope: common
// The functions of the classes in Unk_102b460.h.
#include "network/net_contents/source/trade/box/box_sync_state/Unk_102b460.h"

// 0x710102bc60, 0x710102bcb0 (D0), thunks 0x710102bcc0/0x710102bd10 (+0x48)
// and 0x710102bd40/0x710102bd90 (+0x50). Its key function: inlined into the
// derived class's destructors.
Unk_2409398::~Unk_2409398() {}

// 0x710102b460, 0x710102b500 (D0), thunks 0x710102b700/0x710102b7a0 (+0x48)
// and 0x710102bb20/0x710102bbc0 (+0x50)
Unk_24092b8::~Unk_24092b8() {}

// 0x710102b5a0, 0x710102b8d0 (its thunk from +0x48)
Unk_239a418_Ref<Unk_239a418_Handle> Unk_2409398::vf2() {
    return m_handle;
}

// 0x710102b610, 0x710102b840 (its thunk from +0x48)
void Unk_2409398::vf4() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (handle->field_58 == nullptr)
        handle->field_58 = handle->field_60->vf0();
    ++handle->field_54;
}

// 0x710102b660, 0x710102b890 (its thunk from +0x48)
void Unk_2409398::vf5() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (--handle->field_54 == 0) {
        handle->field_60 = nullptr;
        vf3();
    }
}

// 0x7101029020, 0x710102b960 (its thunk from +0x48). A caller calls it directly (Unk_1028e70.cpp).
void Unk_24092b8::vf6(Unk_102c130* listener) {
    field_90.Lock();
    field_60.push_back(listener);
    listener->vf0(m_handle);
    field_90.Unlock();
}

// 0x7101029340, 0x710102b970 (its thunk from +0x48)
void Unk_24092b8::vf7(Unk_102c130* listener) {
    field_90.Lock();
    auto it = std::find(field_60.begin(), field_60.end(), listener);
    if (it != field_60.end())
        field_60.erase(it);
    field_90.Unlock();
}

// 0x7101029e70, 0x710102ba60 (its thunk from +0x48)
void Unk_24092b8::vf8(u64 value) {
    for (Unk_102c130* listener : field_60)
        listener->vf1(value);
}
