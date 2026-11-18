#pragma once
// A class on gflib3's reference-counted object (vtable 0x710239bb58): four
// references and a u32 that vf11 tests. Two classes derive from it with
// destructors of their own (vtables 0x710239bd80 and 0x710239b8d8, whose
// D2s tail-call this one), and more from those. Placeholder names: rename
// once the classes are known.
#include "gflib3/Unk_239a418.h"

class Unk_239bb58 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's. A derived class's getter has it
    // as its parent; the copy other TUs call is 0x7100603900, and its own TU
    // gets it from Unk_601520.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_239bb58() override;
    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual bool vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();

    Unk_239a418_Ref<Unk_239a418> field_60;
    Unk_239a418_Ref<Unk_239a418> field_68;
    Unk_239a418_Ref<Unk_239a418> field_70;
    u32 field_78;
    u32 field_7c;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
};
static_assert(sizeof(Unk_239bb58) == 0xa0, "Unk_239bb58");
static_assert(__builtin_offsetof(Unk_239bb58, field_60) == 0x60, "Unk_239bb58::field_60");
static_assert(__builtin_offsetof(Unk_239bb58, field_78) == 0x78, "Unk_239bb58::field_78");
static_assert(__builtin_offsetof(Unk_239bb58, field_98) == 0x98, "Unk_239bb58::field_98");

// The functions of Unk_239bb58's TU get its type from this one
// (0x7100601520): its getter inlined, nothing else.
const Unk_239a418_Type* Unk_601520();
