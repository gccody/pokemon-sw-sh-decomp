#pragma once
// A class of game/unk_133d350 (vtable 0x7102432550) whose data is one block of
// the scrambled block store (src/unsorted/families/Unk_13471e0.h): an ID, the
// game's version ID (pkmn::GameVersion), a byte from 0x71007c2280, a string
// of 13 u16 units and a random number below 56, read from and written to the
// store whole. Placeholder names: rename once the class is known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/families/Unk_13471e0.h"

// The base (vtable 0x7102431858), as in src/unsorted/Unk_1392d70.h: its
// destructor is inline (this class's destructors store the vtables of
// Unk_239a418 themselves).
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

// The first 0x90 bytes of the block: a class with a constructor
// (0x7100b6f8c0) and a reset (0x7100b70d80).
struct Unk_b6f8c0 {
    Unk_b6f8c0();
    void Unk_b70d80();

    u8 _0[0x90];
};
PKMN_SIZE_ASSERT(Unk_b6f8c0, 0x90);

// The block: what goes to the store.
struct Unk_136b2b0_T {
    Unk_b6f8c0 field_0;
    u64 field_90;
    u64 field_98;
    u32 field_a0;
    u8 field_a4;
    u8 field_a5;
    u8 _a6;
    u8 field_a7;
    u64 field_a8;
    u16 field_b0[13];
    u32 field_cc;
    u32 field_d0;
    u16 field_d4;
    u8 field_d6;
    u8 _d7[0x39];
};
PKMN_SIZE_ASSERT(Unk_136b2b0_T, 0x110);
PKMN_OFFSET_ASSERT(Unk_136b2b0_T, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_136b2b0_T, field_a7, 0xa7);
PKMN_OFFSET_ASSERT(Unk_136b2b0_T, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_136b2b0_T, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_136b2b0_T, field_d6, 0xd6);

struct Unk_67bde0;
struct Unk_67be60;

// What Unk_2432540::Unk_136b5b0 fills: the ID, the bytes at +0xa5 and
// +0xa7, and the string.
struct Unk_136b5b0_Out {
    u32 field_0;
    u8 field_4;
    u8 field_5;
    u16 field_6[13];
};
PKMN_OFFSET_ASSERT(Unk_136b5b0_Out, field_6, 0x6);

class Unk_2432540 : public Unk_2431de8 {
public:
    Unk_2432540();
    ~Unk_2432540() override;
    void vf7() override;  // reset the block and write it
    void vf8() override;  // read the block from the store
    void vf9() override;  // write it

    void Unk_136b4f0(const Unk_2432540& other);
    u32 Unk_136b500(Unk_67bde0* source);
    u32 Unk_136b520(Unk_67be60* target);
    u32 Unk_136b530(u16* name);
    void Unk_136b5b0(Unk_136b5b0_Out* out);
    bool Unk_136b5e0(void* object);
    u32 Unk_136b6a0();

    Unk_136b2b0_T field_60;
};
PKMN_OFFSET_ASSERT(Unk_2432540, field_60, 0x60);
PKMN_SIZE_ASSERT(Unk_2432540, 0x170);
