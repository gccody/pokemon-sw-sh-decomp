// Scope: common
// The functions of the classes in Unk_102e970.h, their maker, and a forwarder.
#include "network/net_contents/source/trade/box/box_sync_state/Unk_102e970.h"

#include <utility>

#include "gflib3/Unk_New.h"

// Out of this TU: what makes an object's handle and holds it in `handle`, the
// owner being the object's interface at +0x50.
void Unk_102a330(Unk_239a418_Ref<Unk_239a418_Handle>* handle, Unk_239a498* owner);
void Unk_102de10(u64 arg0, u32 arg1, u64 arg2);

// Inlined into Unk_2409528's constructor.
Unk_2409608::Unk_2409608() {
    Unk_102a330(&m_handle, this);
}

// 0x710102f470, 0x710102f4c0 (D0, a trap: the class is abstract), thunks
// 0x710102f4d0/0x710102f520 (+0x48) and 0x710102f550/0x710102f5a0 (+0x50)
Unk_2409608::~Unk_2409608() {}

// 0x710102ed70, 0x710102f0a0 (its thunk from +0x48)
Unk_239a418_Ref<Unk_239a418_Handle> Unk_2409608::vf2() {
    return m_handle;
}

// 0x710102ede0, 0x710102f010 (its thunk from +0x48)
void Unk_2409608::vf4() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (handle->field_58 == nullptr)
        handle->field_58 = handle->field_60->vf0();
    ++handle->field_54;
}

// 0x710102ee30, 0x710102f060 (its thunk from +0x48)
void Unk_2409608::vf5() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (--handle->field_54 == 0) {
        handle->field_60 = nullptr;
        vf3();
    }
}

// 0x710102e970: its constructor is 0x710102eb20.
// NON_MATCHING: the null path. Call site splitting gives two calls of the
// constructor (one with a null pointer), as in the original, but here the
// allocation record stores stay in the block after them, so the two calls are
// tail-merged into one; the original keeps one copy of each per path (the
// null one storing to constant addresses).
template Unk_2409528* Unk_New::Create<Unk_2409528>(Unk_239a418_Allocator*);

// 0x710102ec30, 0x710102ecd0 (D0), thunks 0x710102eed0/0x710102ef70 (+0x48)
// and 0x710102f330/0x710102f3d0 (+0x50)
Unk_2409528::~Unk_2409528() {}

// 0x710102cd40, 0x710102f130 (its thunk from +0x48)
void Unk_2409528::vf6(Unk_102f6a0* listener) {
    field_90.Lock();
    field_60.push_back(listener);
    listener->vf0(m_handle);
    field_90.Unlock();
}

// 0x710102d0d0, 0x710102f140 (its thunk from +0x48)
void Unk_2409528::vf7(Unk_102f6a0* listener) {
    field_90.Lock();
    auto it = std::find(field_60.begin(), field_60.end(), listener);
    if (it != field_60.end())
        field_60.erase(it);
    field_90.Unlock();
}

// 0x710102d9b0, 0x710102f230 (its thunk from +0x48)
void Unk_2409528::vf8(Unk_102f6a0_Arg arg) {
    for (Unk_102f6a0* listener : field_60)
        listener->vf1(std::move(arg));
}

// 0x710102f860
// NON_MATCHING: ordering. The original loads the first value last (w1, x2,
// then x0); a member function reading its own field gives the same order.
void Unk_102f860(const u64& arg0, const u32& arg1, const u64& arg2) {
    Unk_102de10(arg0, arg1, arg2);
}
