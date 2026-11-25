#pragma once
// The battle scene's view system's scene (Unk_23c4ef0_Owner::field_5c8):
// every function of 0x710098a420-0x710098acbc is called through that field
// (the view system's own functions, its vtable's thunks at 0x71009b35d0 ...,
// the battle sequence functions). Two objects it holds (+0x38, +0x58) lead
// to the objects it forwards to. battle/battle_scene/Unk_23c4ef0_Seq.h
// declares the same class without its fields: merge the two once the class
// is known. Placeholder names: rename once the classes are known.
#include <bitset>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_Lock.h"

// The type 0x71027e0580: its getter is out of line (0x710098acc0, the same
// as the inline one in unsorted/types/Unk_90e070.cpp).
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9350: its getter is out of line (0x7100c39c40).
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// What the scene's +0x38 object's handle refers to (vtable 0x71023bdda8,
// type 0x71027d6140, as in unsorted/types/Unk_90e070.cpp).
class Unk_23bdd98 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    u8 _60[0x638 - 0x60];
    u8 field_638;
};
PKMN_OFFSET_ASSERT(Unk_23bdd98, field_638, 0x638);

// What the scene's objects' weak reference (+0xa0) refers to (type
// 0x71027f1758, vtable 0x71023bdbb0).
class Unk_23bdbb0 : public Unk_239a418 {
public:
    u8 _60[0x2c8 - 0x60];
    Unk_239a418* field_2c8;
};
PKMN_OFFSET_ASSERT(Unk_23bdbb0, field_2c8, 0x2c8);

// An app's frame (type 0x71027d9380, as in contents/common/framework.h): the
// last of what the scene's objects hold.
class Unk_23f41d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }

    u8 _60[0xe0 - 0x60];
    u32 field_e0;
    u8 _e4[0x268 - 0xe4];
    u64 field_268;
};
PKMN_OFFSET_ASSERT(Unk_23f41d0, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_23f41d0, field_268, 0x268);


// The +0x38 object's Unk_23bdd98 (its +0x638), and the +0x58 one's.
u8* Unk_98ab90(u64 object);
u8* Unk_98adb0(u64 object);

Unk_239a418_Ref<Unk_239a418> Unk_672980(u64 object);

// The scene's objects at +0x38 and +0x58.
struct Unk_98a950_Self {
    // The last frame the object holds, if it is one. Defined in the class:
    // the original's callers reload what it returns after a call, as for a
    // function whose definition may be replaced (an inline one), and it is
    // too big to be inlined into them.
    // 0x710098a950
    Unk_239a418_Ref<Unk_23f41d0> Unk_98a950() const {
        Unk_239a418_Ref<Unk_239a418> last = Unk_672980(field_10);
        Unk_239a498& object = *last.m_ptr;
        if (!Unk_IsKind<Unk_23f41d0>(object.vf_type()))
            return Unk_239a418_Ref<Unk_23f41d0>();
        Unk_23f41d0& frame = static_cast<Unk_23f41d0&>(object);
        return Unk_239a418_Ref<Unk_23f41d0>(&frame);
    }

    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_98a950_Self, field_10, 0x10);

struct Unk_23c4ef0_Scene {
    void Unk_98a440(bool arg1, u32 arg2);
    void Unk_98a530(u64 arg1, bool arg2);
    void Unk_98a570(u64 arg1, bool arg2);
    void Unk_98a5b0(u64 arg1, bool arg2);
    void Unk_98a5f0(u64 arg1, bool arg2);
    void Unk_98a630(u64 arg1, bool arg2);
    void Unk_98a690(bool arg1);
    void Unk_98a6c0(u64 arg1);
    void Unk_98a820(u32 arg1);
    void Unk_98a850(u32 arg1);
    void Unk_98a8b0();
    void Unk_98a8f0(bool arg1);
    void Unk_98aa50(u64 flags);
    void Unk_98aae0(bool arg1);

    u8 _0[0x20];
    std::bitset<1> field_20;
    u8 _28[0x38 - 0x28];
    Unk_98a950_Self* field_38;
    u8 _40[0x58 - 0x40];
    Unk_98a950_Self* field_58;
};
PKMN_OFFSET_ASSERT(Unk_23c4ef0_Scene, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23c4ef0_Scene, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_23c4ef0_Scene, field_58, 0x58);
