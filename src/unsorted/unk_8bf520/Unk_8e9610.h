#pragma once
// The Battle Tower's states (their names, "statebattletower..."), on a state
// with four more references (Unk_23bcdf0, vtable 0x71023bcdf0) on
// Unk_23f43c8. They have no destructor of their own: their D1 is
// Unk_23bcdf0's D2, and their D0s and thunks are emitted with their vtables,
// whose key function is their vf7. Their vf9s are in
// src/unsorted/virtual/Unk_8e4150.cpp. Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "contents/common/framework.h"
#include "unsorted/Unk_23f43c8.h"

// As src/unsorted/virtual/Unk_8e87e0.cpp declares it (its vf_type is there,
// its destructors are emitted with its vtable).
class Unk_23bcdf0 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    // 0x71008e8f80, not decompiled: looks up the views it keeps in field_78
    // to field_90.
    void Unk_8e8f80();

    Unk_239a418_Ref<Unk_239a418> field_78;
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
};
static_assert(sizeof(Unk_23bcdf0) == 0x98, "Unk_23bcdf0");
PKMN_OFFSET_ASSERT(Unk_23bcdf0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_23bcdf0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_23bcdf0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23bcdf0, field_90, 0x90);

// The state "statebattletowershowhelp" (vtable 0x71023bcf90).
class Unk_23bcf90 : public Unk_23bcdf0 {
public:
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// The state "statebattletowerselectmode" (vtable 0x71023bd060).
class Unk_23bd060 : public Unk_23bcdf0 {
public:
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// The view Unk_23bcf90 keeps in field_88: its slot 17.
class Unk_8e9900_View : public Unk_23f4660 {
public:
    virtual u32 vf17();
};

// The view Unk_23bd060 keeps in field_78 (Unk_8e80e0_call's).
class Unk_8e9cc0_View : public Unk_23f4660 {
public:
    u8 _5cb;
    bool field_5cc;
    u8 _5cd[7];
    bool field_5d4;
    u32 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_8e9cc0_View, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_8e9cc0_View, field_5d4, 0x5d4);
PKMN_OFFSET_ASSERT(Unk_8e9cc0_View, field_5d8, 0x5d8);

// What the app (a state's field_68) refers to (type 0x71008e5870's): the
// selected mode goes to its field_60.
class Unk_23bcb40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_23bcb40, field_60, 0x60);
