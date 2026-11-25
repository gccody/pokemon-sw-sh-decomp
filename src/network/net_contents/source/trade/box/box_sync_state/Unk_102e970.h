#pragma once
// A class (vtable 0x7102409528) on an abstract class with the shape of
// gflib3's reference-counted object (vtable 0x7102409608, type 0x71027d9438),
// as Unk_2409118 is on Unk_24091f8 (Unk_102ac40.h): a vector of listeners,
// then a lock. Placeholder names: rename once the classes are known.
#include <algorithm>
#include <vector>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_65f110.h"
#include "unsorted/Unk_2771620.h"

// The type 0x71027d9438, whose parent is the object's. Its getter is inline
// (its statics are reached through the GOT) but isn't inlined into the
// interfaces' type getters, which emit it here.
struct Unk_27d9438 {
    // 0x710102f5b0
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// What the listeners are given: moved into each call in turn.
struct Unk_102f6a0_Arg {
    u32 field_0;
    Unk_239a418_Ref<Unk_239a418> field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_102f6a0_Arg) == 0x18, "Unk_102f6a0_Arg");
static_assert(__builtin_offsetof(Unk_102f6a0_Arg, field_8) == 0x8, "Unk_102f6a0_Arg::field_8");
static_assert(__builtin_offsetof(Unk_102f6a0_Arg, field_10) == 0x10, "Unk_102f6a0_Arg::field_10");

// A listener, named after its list's growth (src/gflib3/families/Unk_5ac520.cpp).
class Unk_102f6a0 {
public:
    // Called when it's added, with the list's handle.
    virtual void vf0(Unk_239a418_Ref<Unk_239a418_Handle> handle);
    virtual void vf1(Unk_102f6a0_Arg arg);
};

// The interface at +0x48 (vtable 0x7102409648): the object's, with the type
// 0x71027d9438 and three functions of its own: a list of listeners (add,
// remove, and call them all).
class Unk_2409648 : public Unk_239a458 {
public:
    const Unk_239a418_Type* vf_type() override { return Unk_27d9438::Unk_GetType(); }
    virtual void vf6(Unk_102f6a0* listener) = 0;
    virtual void vf7(Unk_102f6a0* listener) = 0;
    virtual void vf8(Unk_102f6a0_Arg arg) = 0;
};

// The interface at +0x50 (vtable 0x71024096a0).
class Unk_24096a0 : public Unk_239a498 {
public:
    const Unk_239a418_Type* vf_type() override { return Unk_27d9438::Unk_GetType(); }
};

class Unk_2409608 : public Unk_239a418_Base, public Unk_2409648, public Unk_24096a0 {
public:
    Unk_2409608();
    ~Unk_2409608() override;
    Unk_239a418_Ref<Unk_239a418_Handle> vf2() override;
    void vf3() override;
    void vf4() override;
    void vf5() override;

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
};
static_assert(sizeof(Unk_2409608) == 0x60, "Unk_2409608");
static_assert(__builtin_offsetof(Unk_2409608, m_handle) == 0x58, "Unk_2409608::m_handle");

// Its type getter is in src/unsorted/types/Unk_102ee60.cpp.
class Unk_2409528 : public Unk_2409608 {
public:
    ~Unk_2409528() override;
    const Unk_239a418_Type* vf_type() override;
    void vf6(Unk_102f6a0* listener) override;
    void vf7(Unk_102f6a0* listener) override;
    void vf8(Unk_102f6a0_Arg arg) override;

    std::vector<Unk_102f6a0*, Unk_2771620_Allocator<Unk_102f6a0*>> field_60;
    // A lock of the shape of gflib3's static one (src/gflib3/Unk_65f110.h).
    Unk_2778770 field_90;
};
static_assert(sizeof(Unk_2409528) == 0xa8, "Unk_2409528");
static_assert(__builtin_offsetof(Unk_2409528, field_60) == 0x60, "Unk_2409528::field_60");
static_assert(__builtin_offsetof(Unk_2409528, field_90) == 0x90, "Unk_2409528::field_90");
