// Scope: common
//
// A class (vtable 0x71024092b8) on an abstract class with the shape of
// gflib3's reference-counted object (vtable 0x7102409398, type 0x71027e51b8),
// as Unk_2409118 is on Unk_24091f8 (Unk_102ac40.cpp): a vector, then a lock.
// Here are the base's handle getter and reference counting, which it overrides
// itself as Unk_239a418 does (src/gflib3/Unk_5e2700.cpp), and the derived
// class's destructors. Placeholder names: rename once the classes are known.
#include <algorithm>
#include <vector>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_65f110.h"
#include "unsorted/Unk_2771620.h"

// The type 0x71027e51b8, whose parent is the object's. Its getter is inline
// but isn't inlined into the interfaces' type getters, which emit it here.
struct Unk_27e51b8 {
    // 0x710102bda0
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// What Unk_24093d8's vf8 calls, each given a value.
class Unk_24093d8_Listener {
public:
    virtual void vf0();
    virtual void vf1(u64 value);
};

// The interface at +0x48 (vtable 0x71024093d8): the object's, with the type
// 0x71027e51b8 and three functions of its own: a list of listeners (add,
// remove, and call them all with a value).
class Unk_24093d8 : public Unk_239a458 {
public:
    const Unk_239a418_Type* vf_type() override { return Unk_27e51b8::Unk_GetType(); }
    virtual void vf6(Unk_24093d8_Listener* listener) = 0;
    virtual void vf7(Unk_24093d8_Listener* listener) = 0;
    virtual void vf8(u64 value) = 0;
};

// The interface at +0x50 (vtable 0x7102409430).
class Unk_2409430 : public Unk_239a498 {
public:
    const Unk_239a418_Type* vf_type() override { return Unk_27e51b8::Unk_GetType(); }
};

class Unk_2409398 : public Unk_239a418_Base, public Unk_24093d8, public Unk_2409430 {
public:
    ~Unk_2409398() override;
    Unk_239a418_Ref<Unk_239a418_Handle> vf2() override;
    void vf3() override;
    void vf4() override;
    void vf5() override;

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
};
static_assert(sizeof(Unk_2409398) == 0x60, "Unk_2409398");
static_assert(__builtin_offsetof(Unk_2409398, m_handle) == 0x58, "Unk_2409398::m_handle");

class Unk_24092b8 : public Unk_2409398 {
public:
    ~Unk_24092b8() override;
    const Unk_239a418_Type* vf_type() override;
    void vf6(Unk_24093d8_Listener* listener) override;
    void vf7(Unk_24093d8_Listener* listener) override;
    void vf8(u64 value) override;

    std::vector<Unk_24093d8_Listener*, Unk_2771620_Allocator<Unk_24093d8_Listener*>> field_60;
    // A lock of the shape of gflib3's static one (src/gflib3/Unk_65f110.h).
    Unk_2778770 field_90;
};
static_assert(sizeof(Unk_24092b8) == 0xa8, "Unk_24092b8");
static_assert(__builtin_offsetof(Unk_24092b8, field_60) == 0x60, "Unk_24092b8::field_60");
static_assert(__builtin_offsetof(Unk_24092b8, field_90) == 0x90, "Unk_24092b8::field_90");

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

// 0x7101029340, 0x710102b970 (its thunk from +0x48)
void Unk_24092b8::vf7(Unk_24093d8_Listener* listener) {
    field_90.Lock();
    auto it = std::find(field_60.begin(), field_60.end(), listener);
    if (it != field_60.end())
        field_60.erase(it);
    field_90.Unlock();
}

// 0x7101029e70, 0x710102ba60 (its thunk from +0x48)
void Unk_24092b8::vf8(u64 value) {
    for (Unk_24093d8_Listener* listener : field_60)
        listener->vf1(value);
}
