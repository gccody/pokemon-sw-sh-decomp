#pragma once
// An abstract class on Unk_23f5ec8 (src/unsorted/Unk_23f5ec8.h), vtable
// 0x71023f2df0, 17 slots (vf13 and vf16 are pure, so its D0 and the D0
// thunks are traps), 0x2c0 bytes: a holder of a reference, a reference and a
// hashed name. 3 classes derive from it without a destructor of their own:
// their D2 is this one, their D0s and thunks tail-call it. Their constructors
// allocate 0x2c0 bytes and construct every member below. Placeholder names:
// rename once the classes are known.
#include "gflib3/Unk_5e2bc0.h"
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f5ec8.h"

// A class with two callables (vtable 0x71023dba98: vf0 and vf1 invoke them,
// 0x7100c49f80 and 0x7100c49fa0) and a reference to an object, which its
// destructor (not virtual) hands to Unk_5e2bc0 and drops: Unk_23c14c0's
// shape (src/unsorted/Unk_23dcdd0.h).
class Unk_23dba98 {
public:
    virtual void vf0();
    virtual void vf1();

    ~Unk_23dba98() {
        if (field_8.m_ptr)
            Unk_5e2bc0(field_8.m_ptr, this);
        Unk_239a418* object = field_8.m_ptr;
        field_8.m_ptr = nullptr;
        if (object)
            static_cast<Unk_239a458*>(object)->vf5();
    }

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_23dba98) == 0x110, "Unk_23dba98");

// The class Unk_23f2df0's member is constructed as (vtable 0x71023dba78, with
// Unk_23dba98's slots): its destructor is Unk_23dba98's.
class Unk_23dba78 : public Unk_23dba98 {};

// A member the derived classes' constructors build with 0x71006835f0; nothing
// destroys it.
struct Unk_23f2df0_1e0 {
    u64 field_0[0x1c];
};
static_assert(sizeof(Unk_23f2df0_1e0) == 0xe0, "Unk_23f2df0_1e0");

class Unk_23f2df0 : public Unk_23f5ec8 {
public:
    // Its type, whose parent is Unk_23f5ec8's (inlined: 0x7100e67540 has four
    // guarded statics). Too big to be inlined into vf_type: vf_type, its
    // thunks and the derived classes' getters call it.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5ec8::Unk_GetType());
        return &type;
    }

    ~Unk_23f2df0() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    void vf11() override;
    virtual void vf13() = 0;
    virtual void vf14();
    virtual void vf15();
    virtual void vf16() = 0;

    u32 field_80;
    u16 field_84;
    u64 field_88;
    Unk_23dba78 field_90;
    Unk_239a418_Ref<Unk_239a418> field_1a0;
    Unk_23f4660_Name field_1a8;
    u64 field_1d8;
    Unk_23f2df0_1e0 field_1e0;
};
static_assert(sizeof(Unk_23f2df0) == 0x2c0, "Unk_23f2df0");
static_assert(__builtin_offsetof(Unk_23f2df0, field_90) == 0x90, "Unk_23f2df0::field_90");
static_assert(__builtin_offsetof(Unk_23f2df0, field_1a0) == 0x1a0, "Unk_23f2df0::field_1a0");
static_assert(__builtin_offsetof(Unk_23f2df0, field_1a8) == 0x1a8, "Unk_23f2df0::field_1a8");
static_assert(__builtin_offsetof(Unk_23f2df0, field_1e0) == 0x1e0, "Unk_23f2df0::field_1e0");
