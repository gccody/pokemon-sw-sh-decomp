#pragma once
// A class on Unk_23f4660 (vtable 0x71023c9470), 0x850 bytes and 16-aligned
// (its std::functions): references, an owned array of 0x1a0-byte elements
// freed through an allocator, eight slots with a callable each. 10 classes
// derive from it without a destructor of their own (their D2 is this one,
// their D0s and thunks tail-call it: the family's operator delete is empty),
// and 7 more release members of their own first. Their constructors allocate
// 0x850 bytes (or more) with alignment 0x10 and zero its fields; two of them
// put a field of their own at +0x848, in its tail padding. Placeholder names:
// rename once the classes are known.
#include <functional>
#include <memory>

#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4660.h"

// The element of the owned array (vtable 0x71023bf428), 0x1a0 bytes: a
// reference and a callable. Its destructor is inline (the array's deleter
// inlines it, so final: the call isn't virtual). Its slot 2 is the 3-slot
// interface's (0x71008efda0), declared here so that its vtable stays the one
// of another TU.
class Unk_23bf428 final {
public:
    virtual ~Unk_23bf428() {}
    virtual void vf2();

    void* field_8;
    u64 field_10;
    Unk_239a418_Ref<Unk_239a418> field_18;
    Unk_23d4470_Callable field_20;
    u8 _a0[0x100];
};
static_assert(sizeof(Unk_23bf428) == 0x1a0, "Unk_23bf428");
static_assert(__builtin_offsetof(Unk_23bf428, field_20) == 0x20, "Unk_23bf428::field_20");

// What frees an owned array: destroys its elements (as many as its size
// holds) and gives its memory back to the allocator, with the size and
// alignment it was allocated with.
struct Unk_23c9470_ArrayDeleter {
    template <class T>
    void operator()(T* p) const {
        u64 n = field_8 / sizeof(T);
        for (u64 i = 0; i < n; ++i)
            p[i].~T();
        field_0->vf3(reinterpret_cast<u64>(p), field_8, field_10);
    }

    Unk_239a418_Allocator* field_0;
    u64 field_8;
    u64 field_10;
};

struct Unk_23c9470_630 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23c9470_630, field_58, 0x58);

// One of its eight slots: a value (8 when constructed) and a callable.
struct Unk_23c9470_Slot {
    u32 field_0;
    std::function<void()> field_10;
};
static_assert(sizeof(Unk_23c9470_Slot) == 0x40, "Unk_23c9470_Slot");
PKMN_OFFSET_ASSERT(Unk_23c9470_Slot, field_10, 0x10);

class Unk_23c9470 : public Unk_23f4660 {
public:
    // Its type, whose parent is Unk_23f4660's (inlined: 0x7100ac7630 has
    // four guarded statics). Its derived classes' getters call it.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23c9470() override;
    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    virtual void vf17() {}
    virtual u32 vf18() { return 1; }
    virtual void vf19() {}
    virtual void vf20();
    virtual void vf21();

    Unk_239a418_Ref<Unk_239a418> field_5d0;
    u8 field_5d8;
    Unk_239a418_Ref<Unk_239a418> field_5e0;
    Unk_239a418_Ref<Unk_239a418> field_5e8;
    Unk_239a418_Ref<Unk_239a418> field_5f0;
    Unk_239a418_Ref<Unk_239a418> field_5f8;
    u64 field_600;
    u32 field_608;
    std::unique_ptr<Unk_23bf428[], Unk_23c9470_ArrayDeleter> field_610;
    Unk_23c9470_630* field_630;
    u64 field_638;
    Unk_23c9470_Slot field_640[8];
    u64 field_840;
};
static_assert(sizeof(Unk_23c9470) == 0x850, "Unk_23c9470");
static_assert(__builtin_offsetof(Unk_23c9470, field_5d0) == 0x5d0, "Unk_23c9470::field_5d0");
static_assert(__builtin_offsetof(Unk_23c9470, field_600) == 0x600, "Unk_23c9470::field_600");
static_assert(__builtin_offsetof(Unk_23c9470, field_610) == 0x610, "Unk_23c9470::field_610");
static_assert(__builtin_offsetof(Unk_23c9470, field_630) == 0x630, "Unk_23c9470::field_630");
static_assert(__builtin_offsetof(Unk_23c9470, field_640) == 0x640, "Unk_23c9470::field_640");
static_assert(__builtin_offsetof(Unk_23c9470, field_840) == 0x840, "Unk_23c9470::field_840");
