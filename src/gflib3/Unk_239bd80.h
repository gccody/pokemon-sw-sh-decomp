#pragma once
// A class on Unk_239bb58 (src/gflib3/Unk_239bb58.h), vtable 0x710239bd80, 16
// slots: it overrides vf7 and adds vf15. Its constructor is 0x7100602030. 7
// classes derive from it with destructors of their own, which tail-call its
// D2. Placeholder names: rename once the classes are known.
#include <vector>

#include "gflib3/Unk_239bb58.h"
#include "unsorted/Unk_23c1a68.h"

class Unk_239bd80 : public Unk_239bb58 {
public:
    // Its type, whose parent is Unk_239bb58's. The copy the classes on it
    // call is 0x71005f19d0, with Unk_239bb58's inlined.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }

    // Its key function. Its D2 is too big to be inlined: the D0 and the four
    // destructor thunks tail-call it.
    ~Unk_239bd80() override;
    // 0x7100603670, thunks 0x7100603710 (+0x48) and 0x7100603780 (+0x50):
    // its getter inlined, calling Unk_239bb58's out of line (0x7100603900).
    // Not defined yet. The original's TU keeps Unk_239bb58's getter out of
    // line because of its other callers there (inlined type casts in
    // 0x7100602930, 0x71006032f0, 0x7100604ab0, ...): with only this caller,
    // clang defers inlining the object's getter into it, inlines it into ours
    // instead, and ours (cost 390) is then too big for vf_type, which becomes
    // `b Unk_GetType`.
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    virtual void vf15() {}

    u64 field_a0;
    u64 field_a8;
    // Vectors of references; the allocator is the constructor's (from a
    // thread's stack of them, or the default one).
    std::vector<Unk_239a418_Ref<Unk_239a418>, Unk_23c1a68_Allocator<Unk_239a418_Ref<Unk_239a418>>>
        field_b0;
    std::vector<Unk_239a418_Ref<Unk_239a418>, Unk_23c1a68_Allocator<Unk_239a418_Ref<Unk_239a418>>>
        field_e0;
    u32 field_110;
    Unk_23c1a68_Event field_114;  // initialized signalled, cleared by hand
    u64 field_120;
    Unk_239a418_Ref<Unk_239a418> field_128;
    Unk_239a418_Ref<Unk_239a418> field_130;
    Unk_239a418_Ref<Unk_239a418> field_138;
    u32 field_140;
};
static_assert(sizeof(Unk_239bd80) == 0x148, "Unk_239bd80");
static_assert(__builtin_offsetof(Unk_239bd80, field_b0) == 0xb0, "Unk_239bd80::field_b0");
static_assert(__builtin_offsetof(Unk_239bd80, field_e0) == 0xe0, "Unk_239bd80::field_e0");
static_assert(__builtin_offsetof(Unk_239bd80, field_114) == 0x114, "Unk_239bd80::field_114");
static_assert(__builtin_offsetof(Unk_239bd80, field_128) == 0x128, "Unk_239bd80::field_128");
static_assert(__builtin_offsetof(Unk_239bd80, field_140) == 0x140, "Unk_239bd80::field_140");
