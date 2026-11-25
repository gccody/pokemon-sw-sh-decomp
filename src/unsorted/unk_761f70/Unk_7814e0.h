#pragma once
// A table of 0x31d (797) holders of loaded FlatBuffers data (Unk_277a1a0), and
// the class that reads one of them (vtable 0x71023a7b38): its field_8 picks
// the holder, and its accessors read the fields of the data's root table.
// Unk_7814e0 loads all of them, Unk_781640 lets them go. Placeholder names:
// rename once the classes are known.
//
// The class's destructor (its key function, 0x71007816d0) is
// tools/vtables.py's (src/unsorted/virtual/Unk_7816d0.cpp), declared there
// without the field.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_5e2bc0.h"
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_Table.h"

// What a holder holds: an object on gflib3's reference-counted one, with the
// data at +0x190 (a FlatBuffers buffer: the offset of its root table first).
class Unk_7814e0_Data : public Unk_239a418 {
public:
    const Unk_Table* Unk_Root() const {
        return reinterpret_cast<const Unk_Table*>(field_190 +
                                                  *reinterpret_cast<const u32*>(field_190));
    }

    u8 _60[0x130];
    const u8* field_190;
};
PKMN_OFFSET_ASSERT(Unk_7814e0_Data, field_190, 0x190);

// A holder: two callables and a reference to the object, which it hands to
// Unk_5e2bc0 and drops when it lets go of it (Unk_236d3d8's shape,
// src/unsorted/Unk_236d3d8.h).
class Unk_277a1a0_Entry {
public:
    virtual void vf0();
    virtual void vf1();

    void Unk_Load(const class Unk_23f4660_Name& name, void* heap);
    void Unk_Release() {
        if (field_8.m_ptr)
            Unk_5e2bc0(field_8.m_ptr, this);
        field_8.Reset();
    }

    Unk_239a418_Ref<Unk_7814e0_Data> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_277a1a0_Entry) == 0x110, "Unk_277a1a0_Entry");

extern Unk_277a1a0_Entry Unk_277a1a0[0x31d];

class Unk_23a7b38 {
public:
    Unk_23a7b38();
    virtual ~Unk_23a7b38();

    const Unk_Table* Unk_Root() const { return Unk_277a1a0[field_8].field_8.m_ptr->Unk_Root(); }

    void Unk_7816f0(s32 index);
    bool Unk_781700() const;
    u8 Unk_781760() const;
    u8 Unk_7817c0() const;
    u8 Unk_781820() const;
    u8 Unk_781880() const;
    u8 Unk_7818e0() const;
    bool Unk_781940() const;
    u8 Unk_7819a0() const;
    s32 Unk_781a00() const;
    u8 Unk_781a60() const;
    u8 Unk_781ac0() const;
    u8 Unk_781b20() const;
    u16 Unk_781b80() const;
    u8 Unk_781be0() const;
    u8 Unk_781c40() const;
    u8 Unk_781ca0() const;
    u8 Unk_781d00() const;
    u16 Unk_781d60() const;
    u8 Unk_781dc0(u8 kind) const;
    s32 Unk_781ee0(u8 kind) const;
    u8 Unk_782000(u8 kind) const;
    u8 Unk_782120() const;
    s32 Unk_782180() const;
    s32 Unk_7821e0() const;
    s32 Unk_782240() const;
    s32 Unk_7822a0() const;

    u32 field_8;
};
static_assert(sizeof(Unk_23a7b38) == 0x10, "Unk_23a7b38");
PKMN_OFFSET_ASSERT(Unk_23a7b38, field_8, 0x8);
