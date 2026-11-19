#pragma once
// A class on gflib3's reference-counted object (vtable 0x71023f43c8): three
// references and its own type. 246 classes derive from it without a
// destructor of their own: their D2 is this one, their D0 tail-calls it
// (the family's operator delete is empty), and their thunks tail-call it.
// Placeholder names: rename once the classes are known.
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_d0c0.h"

// Another class on the object, from the same TU (vtable 0x71023f4318): nothing
// of its own to destroy, but an out-of-line destructor and its own type. 13
// classes derive from it the way the 224 below derive from Unk_23f43c8.
class Unk_23f4318 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_23f4318() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
};
static_assert(sizeof(Unk_23f4318) == 0x60, "Unk_23f4318");

class Unk_23f43c8 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's. A derived class's own getter
    // (an inline static member like this one) has it as its parent; its
    // vf_type tail-calls it, and this one is inlined into vf_type.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    // 0x7100e7c430: takes the first two references; the third is looked up by
    // a name (0x710000d0c0, not decompiled yet).
    Unk_23f43c8(Unk_239a418_Ref<Unk_239a418> field_60, Unk_239a418_Ref<Unk_239a418> field_68);
    ~Unk_23f43c8() override;
    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual u32 vf10();

    // Handles (the objects' vf2) of the app's frame and of the app.
    Unk_239a418_Ref<Unk_239a418> field_60;
    Unk_239a418_Ref<Unk_239a418> field_68;
    // The state's name: its vf7 sets it ("boxtray_in", ...).
    Unk_d0c0_String field_70;
};
static_assert(sizeof(Unk_23f43c8) == 0x78, "Unk_23f43c8");
static_assert(__builtin_offsetof(Unk_23f43c8, field_60) == 0x60, "Unk_23f43c8::field_60");
