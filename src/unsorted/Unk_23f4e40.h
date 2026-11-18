#pragma once
// An abstract class on gflib3's reference-counted object (vtable
// 0x71023f4e40): four references and a state (+0x6c, 0 to 2) that a member
// (0x7100e9d4b0) steps through vf7-vf10. Classes derive from it without a
// destructor of their own (their D0s and thunks tail-call its D2), or with
// reference members of their own (their D2s release them, then tail-call
// its D2). Placeholder names: rename once the classes are known.
#include "gflib3/Unk_239a418.h"

class Unk_23f4e40 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's. A derived class's own getter
    // (an inline static member like this one) has it as its parent; its
    // vf_type tail-calls it, and this one is inlined into vf_type.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_23f4e40() override;
    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual u32 vf7() = 0;
    virtual void vf8() = 0;
    virtual u32 vf9() = 0;
    virtual void vf10() = 0;

    Unk_239a418_Ref<Unk_239a418> field_60;
    u32 field_68;
    u32 field_6c;
    Unk_239a418_Ref<Unk_239a418> field_70;
    Unk_239a418_Ref<Unk_239a418> field_78;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_23f4e40) == 0x88, "Unk_23f4e40");
static_assert(__builtin_offsetof(Unk_23f4e40, field_60) == 0x60, "Unk_23f4e40::field_60");
static_assert(__builtin_offsetof(Unk_23f4e40, field_6c) == 0x6c, "Unk_23f4e40::field_6c");
static_assert(__builtin_offsetof(Unk_23f4e40, field_80) == 0x80, "Unk_23f4e40::field_80");
