#pragma once
// A class on Unk_23f4660 (src/unsorted/Unk_23f4660.h), vtable 0x71024034f8,
// 22 slots, 0x710 bytes and 16-aligned (its std::functions), in the link
// battle app's area: references, four slots with a callable each and a
// pointer that the non-virtual functions of its TU use (0x7100fcd060 sets
// it). 3 classes share its D2 (two derive from it without a destructor of
// their own; their constructors allocate 0x710 bytes with alignment 0x10),
// and 2 more tail-call it. Placeholder names: rename once the classes are
// known.
//
// In the original its destructor is implicit (its D0 and thunks follow its
// last virtual function, emitted with its vtable) and too big to be inlined
// into them: they tail-call its D2. Here it's its key function instead, which
// makes the same code.
#include <functional>

#include "unsorted/Unk_23f4660.h"

struct Unk_24034f8_5f0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_24034f8_5f0, field_58, 0x58);

// One of its four slots: a callable, after 0x10 bytes nothing here initialises.
struct Unk_24034f8_Slot {
    u64 field_0;
    u64 field_8;
    std::function<void()> field_10;
};
static_assert(sizeof(Unk_24034f8_Slot) == 0x40, "Unk_24034f8_Slot");
PKMN_OFFSET_ASSERT(Unk_24034f8_Slot, field_10, 0x10);

class Unk_24034f8 : public Unk_23f4660 {
public:
    // Its type, whose parent is Unk_23f4660's (inlined: 0x7100fcce00 has four
    // guarded statics). Too big to be inlined into vf_type: vf_type, its
    // thunks and the derived classes' getters call it.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_24034f8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    // The derived classes' vf8 call it first.
    void vf8() override;
    virtual void vf17() {}
    virtual u32 vf18() { return 1; }
    virtual void vf19() {}
    virtual void vf20() { field_5e8 = 0; }
    virtual void vf21() { field_5f0->field_58 = field_5f0->field_58 & 0xfe; }

    Unk_239a418_Ref<Unk_239a418> field_5d0;
    Unk_239a418_Ref<Unk_239a418> field_5d8;
    Unk_239a418_Ref<Unk_239a418> field_5e0;
    u64 field_5e8;
    Unk_24034f8_5f0* field_5f0;
    u64 field_5f8;
    Unk_24034f8_Slot field_600[4];
    u64 field_700;
};
static_assert(sizeof(Unk_24034f8) == 0x710, "Unk_24034f8");
static_assert(__builtin_offsetof(Unk_24034f8, field_5d0) == 0x5d0, "Unk_24034f8::field_5d0");
static_assert(__builtin_offsetof(Unk_24034f8, field_5f0) == 0x5f0, "Unk_24034f8::field_5f0");
static_assert(__builtin_offsetof(Unk_24034f8, field_600) == 0x600, "Unk_24034f8::field_600");
static_assert(__builtin_offsetof(Unk_24034f8, field_700) == 0x700, "Unk_24034f8::field_700");
