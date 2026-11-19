#pragma once
// A class on gflib3's reference-counted object (vtable 0x71023f4660), 0x5d0
// bytes: references, two hashed names, a 0x4a0-byte member and an object it
// owns, freed through an allocator. 50 classes derive from it without a
// destructor of their own: their D2 is this one, their D0s and thunks
// tail-call it (the family's operator delete is empty). Placeholder names:
// rename once the classes are known.
#include <memory>
#include <vector>

#include "gflib3/Unk_239a418.h"

// What frees the owned object: destroys it and gives its memory back to the
// allocator, with the size and alignment it was allocated with.
struct Unk_23f4660_Deleter {
    template <class T>
    void operator()(T* p) const {
        p->~T();
        field_0->vf3(reinterpret_cast<u64>(p), field_8, field_10);
    }

    Unk_239a418_Allocator* field_0;
    u64 field_8;
    u64 field_10;
};

// The object it owns (vtable 0x71023f47c0): two references and a vector of
// them. Its vtable has no destructor, and the deleter destroys it directly
// (final, so that clang doesn't warn about that).
class Unk_23f47c0 final {
public:
    virtual void vf0();

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
    std::vector<Unk_239a418_Ref<Unk_239a418>,
                Unk_239a418_StdAllocator<Unk_239a418_Ref<Unk_239a418>>>
        field_18;
};
static_assert(sizeof(Unk_23f47c0) == 0x38, "Unk_23f47c0");

// A name and its hash (64-bit FNV-1a) with two references it releases
// itself (plain pointers: nothing else releases them), reset when it goes.
class Unk_23f4660_Name {
public:
    ~Unk_23f4660_Name() { Reset(); }

    static void Release(Unk_239a418*& ref) {
        if (ref) {
            static_cast<Unk_239a458*>(ref)->vf5();
            ref = nullptr;
        }
    }

    void Reset() {
        if (field_18)
            Release(field_0);
        field_0 = nullptr;
        field_8 = 0xcbf29ce484222645;  // the hash of ""
        field_10 = "";
        field_18 = 0;
        Release(field_20);
        field_20 = nullptr;
        field_28 = 0;
    }

    // Empty, as the demo commands' constructors make it (src/demo/Unk_bc27d0.cpp).
    Unk_239a418* field_0 = nullptr;
    u64 field_8 = 0xcbf29ce484222645;
    const char* field_10 = "";
    u64 field_18 = 0;
    Unk_239a418* field_20 = nullptr;
    u32 field_28 = 0;
};
static_assert(sizeof(Unk_23f4660_Name) == 0x30, "Unk_23f4660_Name");

// A member with a destructor of its own (vtable 0x71023f4760).
class Unk_23f4760 {
public:
    virtual ~Unk_23f4760();

    u8 _8[0x498];
};
static_assert(sizeof(Unk_23f4760) == 0x4a0, "Unk_23f4760");

class Unk_23f4660 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's. A derived class's own getter
    // has it as its parent and inlines it; the copy the others call is
    // 0x7100e7f6c0.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_23f4660() override;
    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override;
    virtual u32 vf7() { return 1; }
    virtual void vf8() {}
    virtual u32 vf9() { return 1; }
    virtual void vf10();
    virtual void vf11() {}
    virtual void vf12() {}
    virtual void vf13() {}
    virtual void vf14() {}
    virtual void vf15() {}
    virtual u32 vf16() { return 1; }

    u64 field_60;
    u64 field_68;
    Unk_239a418_Ref<Unk_239a418> field_70;
    Unk_23f4660_Name field_78;
    Unk_23f4660_Name field_a8;
    u64 field_d8;
    u64 field_e0;
    u64 field_e8;
    u64 field_f0;
    u64 field_f8;
    Unk_23f4760 field_100;
    std::unique_ptr<Unk_23f47c0, Unk_23f4660_Deleter> field_5a0;
    Unk_239a418_Ref<Unk_239a418> field_5c0;
    u64 field_5c8;
};
static_assert(sizeof(Unk_23f4660) == 0x5d0, "Unk_23f4660");
static_assert(__builtin_offsetof(Unk_23f4660, field_70) == 0x70, "Unk_23f4660::field_70");
static_assert(__builtin_offsetof(Unk_23f4660, field_100) == 0x100, "Unk_23f4660::field_100");
static_assert(__builtin_offsetof(Unk_23f4660, field_5a0) == 0x5a0, "Unk_23f4660::field_5a0");
static_assert(__builtin_offsetof(Unk_23f4660, field_5c0) == 0x5c0, "Unk_23f4660::field_5c0");

// The functions of Unk_23f4660's TU get its type from this one
// (0x7100e81640): its getter inlined, nothing else.
const Unk_239a418_Type* Unk_e81640();
