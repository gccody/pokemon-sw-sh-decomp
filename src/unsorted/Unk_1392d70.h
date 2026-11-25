#pragma once
// A class of game/unk_133d350 (vtable 0x71024331c0) whose data is one block of
// the scrambled block store (src/unsorted/families/Unk_13471e0.h): a table of
// three entries, read from and written to the store whole. Placeholder names:
// rename once the class is known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/families/Unk_13471e0.h"

// The base (vtable 0x7102431858), as in src/unsorted/virtual/Unk_1345f20.cpp,
// but with its destructor inline: this class's destructors inline it (they
// store the object's own vtables), so the original's can't have been out of
// line. Its out-of-line copy (0x71013566f0) is a weak one.
class Unk_2431de8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_2431de8() override {}
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

// An entry of the table. What's in it isn't known yet: the functions of
// unk_761f70 it's handed to (0x710076f7d0, 0x710076f7e0) use the byte at
// +0x148.
struct Unk_1393080_Entry {
    u8 _0[0x158];
};
PKMN_SIZE_ASSERT(Unk_1393080_Entry, 0x158);

// The block: what goes to the store.
struct Unk_1393080_T {
    Unk_1393080_Entry field_0[3];
};
PKMN_SIZE_ASSERT(Unk_1393080_T, 0x408);

class Unk_24331b0 : public Unk_2431de8 {
public:
    Unk_24331b0();
    ~Unk_24331b0() override;
    void vf7() override;  // clear the block and write it
    void vf8() override;  // read the block from the store
    void vf9() override;  // write it

    void Unk_13931c0(int index, void* const& target);
    void Unk_13931e0(int index, void* const& target);
    void Unk_1393200(int index);

    Unk_1393080_T field_60;
};
PKMN_OFFSET_ASSERT(Unk_24331b0, field_60, 0x60);
