// Scope: common
// The functions of the classes in Unk_102ac40.h.
#include "network/net_contents/source/trade/box/box_sync_state/Unk_102ac40.h"

// 0x710102af70, 0x710102afc0 (D0), thunks 0x710102afd0/0x710102b020 (+0x48)
// and 0x710102b050/0x710102b0a0 (+0x50)
Unk_24091f8::~Unk_24091f8() {}

// 0x710102a870, 0x710102aba0 (its thunk from +0x48)
Unk_239a418_Ref<Unk_239a418_Handle> Unk_24091f8::vf2() {
    return m_handle;
}

// 0x710102a8e0, 0x710102ab10 (its thunk from +0x48)
void Unk_24091f8::vf4() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (handle->field_58 == nullptr)
        handle->field_58 = handle->field_60->vf0();
    ++handle->field_54;
}

// 0x710102a930, 0x710102ab60 (its thunk from +0x48)
void Unk_24091f8::vf5() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (--handle->field_54 == 0) {
        handle->field_60 = nullptr;
        vf3();
    }
}

// 0x710102a730, 0x710102a7d0 (D0), thunks 0x710102a9d0/0x710102aa70 (+0x48)
// and 0x710102ae30/0x710102aed0 (+0x50)
Unk_2409118::~Unk_2409118() {}

// 0x7101028ec0, 0x710102ac30 (its thunk from +0x48). A caller calls it directly (Unk_1028e70.cpp).
void Unk_2409118::vf6(Unk_102bf70* listener) {
    field_90.Lock();
    field_60.push_back(listener);
    listener->vf0(m_handle);
    field_90.Unlock();
}

// 0x7101029430, 0x710102ac40 (its thunk from +0x48)
void Unk_2409118::vf7(Unk_102bf70* listener) {
    field_90.Lock();
    auto it = std::find(field_60.begin(), field_60.end(), listener);
    if (it != field_60.end())
        field_60.erase(it);
    field_90.Unlock();
}

// 0x7101029de0, 0x710102ad30 (its thunk from +0x48)
void Unk_2409118::vf8(const Unk_239a418_Ref<Unk_239a418>& ref) {
    for (Unk_102bf70* listener : field_60)
        listener->vf1(ref);
}
