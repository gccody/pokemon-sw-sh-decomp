#pragma once
// A class on gflib3's reference-counted object (vtable 0x71023c44f8, 8
// slots), in game/battle_scene: three references, constructed by
// 0x710142a040 (which about 50 constructors call). Its destructor is
// inline, like the object's: classes on it without members to destroy have
// its D2 (0x710099cf10) in their slot 0, and their D0s and destructor thunks
// are copies of it; 228 functions reference its vtable. Most of its derived
// classes inherit its vf_type (0x7100999800, slot 6); three that override
// it (5 classes, with the ones on them) call its getter out of line
// (0x710142b300, the copy of Unk_GetType). Placeholder names: rename once
// the classes are known.
#include "gflib3/Unk_239a418.h"

class Unk_23c44f8 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's. Inlined into vf_type; the copy
    // other TUs call is 0x710142b300.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    // An override (Unk_23c2c68's, 0x710098f020) adds its argument to a
    // signed count and compares it with a limit.
    virtual void vf7(s32 arg);

    Unk_239a418_Ref<Unk_239a418> field_60;
    Unk_239a418_Ref<Unk_239a418> field_68;
    u32 field_70;  // the constructor zeroes 0x70-0x74
    u8 field_74;
    Unk_239a418_Ref<Unk_239a418> field_78;
};
static_assert(sizeof(Unk_23c44f8) == 0x80, "Unk_23c44f8");
static_assert(__builtin_offsetof(Unk_23c44f8, field_60) == 0x60, "Unk_23c44f8::field_60");
static_assert(__builtin_offsetof(Unk_23c44f8, field_70) == 0x70, "Unk_23c44f8::field_70");
static_assert(__builtin_offsetof(Unk_23c44f8, field_78) == 0x78, "Unk_23c44f8::field_78");
