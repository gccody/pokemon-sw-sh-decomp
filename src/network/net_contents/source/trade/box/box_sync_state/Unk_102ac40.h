#pragma once
// An abstract class on gflib3's reference-counted object shape (vtable
// 0x71024091f8) and the type its interfaces return (0x71027e51c8). Like
// Unk_239a418 (src/gflib3/Unk_239a418.h) it has the object's primary base,
// two interfaces at +0x48 and +0x50 and a handle at +0x58, and overrides the
// handle getter and the reference counting itself (0x710102a870-0x710102a930).
// Its +0x48 interface adds three pure virtual functions, so its deleting
// destructor and that destructor's thunks are traps. Placeholder names:
// rename once the classes are known.
#include <algorithm>
#include <vector>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_65f110.h"
#include "unsorted/Unk_2771620.h"

// The type 0x71027e51c8, whose parent is the object's. Its getter is inline
// (its statics are reached through the GOT) but isn't inlined into the
// interfaces' type getters, which emit it here.
struct Unk_27e51c8 {
    // 0x710102b0b0
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// A listener, named after its list's growth (src/gflib3/families/Unk_5ac520.cpp):
// what Unk_2409238's vf8 calls, each given a reference.
class Unk_102bf70 {
public:
    // Called when it's added, with the list's handle.
    virtual void vf0(Unk_239a418_Ref<Unk_239a418_Handle> handle);
    virtual void vf1(Unk_239a418_Ref<Unk_239a418> ref);
};

// The interface at +0x48 (vtable 0x7102409238): the object's, with the type
// 0x71027e51c8 and three functions of its own: a list of listeners (add,
// remove, and call them all with a reference).
class Unk_2409238 : public Unk_239a458 {
public:
    const Unk_239a418_Type* vf_type() override { return Unk_27e51c8::Unk_GetType(); }
    virtual void vf6(Unk_102bf70* listener) = 0;
    virtual void vf7(Unk_102bf70* listener) = 0;
    virtual void vf8(const Unk_239a418_Ref<Unk_239a418>& ref) = 0;
};

// The interface at +0x50 (vtable 0x7102409290).
class Unk_2409290 : public Unk_239a498 {
public:
    const Unk_239a418_Type* vf_type() override { return Unk_27e51c8::Unk_GetType(); }
};

class Unk_24091f8 : public Unk_239a418_Base, public Unk_2409238, public Unk_2409290 {
public:
    ~Unk_24091f8() override;
    Unk_239a418_Ref<Unk_239a418_Handle> vf2() override;
    void vf3() override;
    void vf4() override;
    void vf5() override;

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
};
static_assert(sizeof(Unk_24091f8) == 0x60, "Unk_24091f8");
static_assert(__builtin_offsetof(Unk_24091f8, m_handle) == 0x58, "Unk_24091f8::m_handle");

// A class on it (vtable 0x7102409118): a vector, then a lock. Its type getter
// is in src/unsorted/types/Unk_102a960.cpp.
class Unk_2409118 : public Unk_24091f8 {
public:
    ~Unk_2409118() override;
    const Unk_239a418_Type* vf_type() override;
    void vf6(Unk_102bf70* listener) override;
    void vf7(Unk_102bf70* listener) override;
    void vf8(const Unk_239a418_Ref<Unk_239a418>& ref) override;

    std::vector<Unk_102bf70*, Unk_2771620_Allocator<Unk_102bf70*>> field_60;
    // A lock of the shape of gflib3's static one (src/gflib3/Unk_65f110.h).
    Unk_2778770 field_90;
};
static_assert(sizeof(Unk_2409118) == 0xa8, "Unk_2409118");
static_assert(__builtin_offsetof(Unk_2409118, field_60) == 0x60, "Unk_2409118::field_60");
static_assert(__builtin_offsetof(Unk_2409118, field_90) == 0x90, "Unk_2409118::field_90");
