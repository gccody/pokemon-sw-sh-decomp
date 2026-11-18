#pragma once
// An abstract class on gflib3's reference-counted object (vtable
// 0x710241b640, 11 slots, vf7 pure), in game/pokecamp: a vector of entries
// that each hold a callable, a u32, a byte its constructor (0x7101162c30)
// takes, a reference and a byte. Its data ends at 0xa1, where a derived class
// (Unk_241b570, constructed by 0x7101161f40) puts a byte of its own.
//
// Its destructor is inline, like the object's: classes on it without
// members to destroy have its D2 (0x71011622d0) in their slot 0, and their
// D0s and destructor thunks are copies of it. 27 constructors call its
// constructor. Three classes override its vf_type (0x7101192910,
// 0x71011962c0, 0x71011a3de0, each also in the slot 6 of classes on them: 21
// classes in all): their getters are inlined, calling its getter out of line
// (0x710113e1f0, the copy of Unk_GetType), and their secondary type slots are
// copies. Of the 21, 18 have its D2 in their slot 0; 2 release a reference,
// then tail-call it (0x71011a8700, 0x71011aafd0); 1 has a D2 of its own
// (0x71011af850, which its D0 tail-calls). Placeholder names: rename once the
// classes are known.
#include <vector>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23d4470.h"

// The elements of Unk_241b640::field_60, 16-aligned (the vector frees them
// with that alignment): two words, then a callable.
struct alignas(16) Unk_241b640_Entry {
    u64 field_0;
    u64 field_8;
    Unk_23d4470_Callable field_10;
};
static_assert(sizeof(Unk_241b640_Entry) == 0x90, "Unk_241b640_Entry");

class Unk_241b640 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's. Inlined into vf_type; the copy
    // other TUs call is 0x710113e1f0.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    // 0x7101162c30 (its callers pass 0 or their own argument)
    explicit Unk_241b640(u8 arg);

    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7() = 0;
    virtual u32 vf8() { return 1; }
    virtual void vf9();
    virtual void vf10();

    std::vector<Unk_241b640_Entry, Unk_239a418_StdAllocator<Unk_241b640_Entry>> field_60;
    u64 field_80;
    u32 field_88;
    u32 field_8c;
    u8 field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    u8 field_a0;
};
static_assert(sizeof(Unk_241b640) == 0xa8, "Unk_241b640");
static_assert(__builtin_offsetof(Unk_241b640, field_60) == 0x60, "Unk_241b640::field_60");
static_assert(__builtin_offsetof(Unk_241b640, field_88) == 0x88, "Unk_241b640::field_88");
static_assert(__builtin_offsetof(Unk_241b640, field_90) == 0x90, "Unk_241b640::field_90");
static_assert(__builtin_offsetof(Unk_241b640, field_98) == 0x98, "Unk_241b640::field_98");
static_assert(__builtin_offsetof(Unk_241b640, field_a0) == 0xa0, "Unk_241b640::field_a0");
