#pragma once
// A class on gflib3's reference-counted object (vtable 0x7102423ec8, 18
// slots, 0x80 bytes), in game/pokecamp: a number and two references, and
// eleven virtual functions of its own. Its destructor is inline: the classes
// on it without members to destroy have its D2 (0x7101216dc0) in their slot
// 0, and their D0s and destructor thunks are copies of it. Placeholder names.
//
// The classes on it have internal linkage, like those on Unk_24284d0
// (src/unsorted/Unk_24284d0.h): they're written a TU at a time
// (src/unsorted/Unk_1238d90.cpp, ...).
//
// tools/vtables.py writes this class's own virtual functions, with its own
// copy of the class (src/unsorted/virtual/Unk_12163d0.cpp): the two have to
// agree on the layout and the virtual functions. This one names the fields
// the classes on it use, and declares the getter `inline` (see
// Unk_24284d0::Unk_GetType: the getters of the classes on it then inline it,
// as the original's do).
#include "gflib3/Unk_239a418.h"

// What Unk_2423ec8::Unk_12164a0 finds (156 bytes, not decompiled).
class Unk_1127d00_Owner;
struct Unk_12164a0_Result {
    u8 _0[0x60];
    Unk_1127d00_Owner* field_60;  // src/unsorted/Unk_1127d00.h
    u8 _68[0x10];
    u32 field_78;
};

// 0x71012165c0, written as a leaf.
struct Unk_12165c0;
void Unk_12165c0_call(const Unk_12165c0*);

class Unk_2423ec8 : public Unk_239a418 {
public:
    static inline const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    // 0x7101216380, not decompiled yet.
    Unk_2423ec8();

    // Not decompiled yet: 0x71012164a0, something of its owner's; 0x7101216550,
    // field_78 becomes `next`.
    Unk_12164a0_Result* Unk_12164a0();
    void Unk_1216550(Unk_239a418_Ref<Unk_239a418> next);
    // 0x71012165c0
    void Unk_12165c0() { Unk_12165c0_call(reinterpret_cast<const ::Unk_12165c0*>(this)); }

    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7(u64 value);
    virtual Unk_239a418_Ref<Unk_239a418> vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();

    u32 field_60;
    u32 field_64;
    u64 field_68;
    Unk_239a418_Ref<Unk_239a418> field_70;
    Unk_239a418_Ref<Unk_239a418> field_78;
};
static_assert(sizeof(Unk_2423ec8) == 0x80, "Unk_2423ec8");
PKMN_OFFSET_ASSERT(Unk_2423ec8, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_2423ec8, field_78, 0x78);
