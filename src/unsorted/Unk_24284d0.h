#pragma once
// A class on gflib3's reference-counted object (vtable 0x71024284d0, 11
// slots), in game/pokecamp: two references, six callables and five hashes
// that its constructor (0x710126ab20) sets to the 64-bit FNV-1a hash of "".
// Its destructor is inline, like the object's: classes on it without members
// to destroy have its D2 (0x710126bd00) in their slot 0 (20 of them), and
// their D0s and destructor thunks are copies of it; 108 functions reference
// its vtable. Unk_242af50 (its D2 0x71012928c0, shared by 6 classes in
// game/unk_1290e40) is on it with a reference of its own. Placeholder names:
// rename once the classes are known.
//
// The classes on it have internal linkage (an anonymous namespace): their
// constructors (0x710127de10, ...) and Unk_242af50's D2 store their vptrs
// with adrp+add instead of loading them from the GOT, their types are local
// statics, and their secondary type thunks call vf_type and return the type
// itself (IPSCCP knows what an internal vf_type returns). clang emits such a
// class only with the code of its TU that uses it, so they wait for their
// constructors.
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23d4470.h"

// The first five callables, one member of the class: its destructor clears
// the first callable's words through a pointer to it (`add x9, x19, #0xa0`,
// then `stp xzr, xzr, [x9, #0x10]` and `[x9]`). With five members or an
// array of them, they're addressed from `this` (InstCombine doesn't fold a GEP
// with all-zero indices into a GEP with other uses, so the first member of a
// member keeps its own pointer).
struct Unk_24284d0_Callables {
    Unk_23d4470_Callable field_0;
    Unk_23d4470_Callable field_80;
    Unk_23d4470_Callable field_100;
    Unk_23d4470_Callable field_180;
    Unk_23d4470_Callable field_200;
};
static_assert(sizeof(Unk_24284d0_Callables) == 0x280, "Unk_24284d0_Callables");

class Unk_24284d0 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's. Inlined into vf_type and into
    // the getters of the classes on it.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    // 0x710126ab20, not defined yet: written with its members in declaration
    // order (callables zeroing their four words), the same instructions come
    // out in another order (the hash of "" is materialized before the vptr
    // stores, where the original does it after them).
    Unk_24284d0();

    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7(u64 arg);
    // field_70, or a reference to itself when that's empty.
    virtual Unk_239a418_Ref<Unk_239a418> vf8();
    virtual void vf9();
    virtual void vf10();

    u32 field_60;
    u32 field_64;
    u64 field_68;
    Unk_239a418_Ref<Unk_239a418> field_70;
    Unk_239a418_Ref<Unk_239a418> field_78;
    u64 field_80;  // the hash of "", from the constructor (and the next three)
    u64 field_88;
    u64 field_90;
    u64 field_98;
    Unk_24284d0_Callables field_a0;
    u64 field_320;  // the hash of ""
    u64 field_328;
    Unk_23d4470_Callable field_330;
    u32 field_3b0;
};
static_assert(sizeof(Unk_24284d0) == 0x3c0, "Unk_24284d0");  // its callables are 16-byte aligned
static_assert(__builtin_offsetof(Unk_24284d0, field_70) == 0x70, "Unk_24284d0::field_70");
static_assert(__builtin_offsetof(Unk_24284d0, field_a0) == 0xa0, "Unk_24284d0::field_a0");
static_assert(__builtin_offsetof(Unk_24284d0, field_320) == 0x320, "Unk_24284d0::field_320");
static_assert(__builtin_offsetof(Unk_24284d0, field_330) == 0x330, "Unk_24284d0::field_330");
static_assert(__builtin_offsetof(Unk_24284d0, field_3b0) == 0x3b0, "Unk_24284d0::field_3b0");
