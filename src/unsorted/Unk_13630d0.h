#pragma once
// A class of game/unk_133d350 (vtable 0x7102432210) whose data is one block of
// the scrambled block store (src/unsorted/families/Unk_13471e0.h): 512
// entries of a state byte and two random numbers from 1 to 100, and the two
// seeds they're drawn with, read from and written to the store whole.
// Placeholder names: rename once the class is known.
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

// An entry: a state (0, 1 or 2) and two numbers from 1 to 100.
struct Unk_1363ac0_Entry {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 _3;
};
PKMN_SIZE_ASSERT(Unk_1363ac0_Entry, 0x4);

// The block: what goes to the store.
struct Unk_1363ac0_T {
    Unk_1363ac0_Entry field_0[512];
    u64 field_800;  // the seed the entries were drawn with
    u64 field_808;  // the next one
};
PKMN_SIZE_ASSERT(Unk_1363ac0_T, 0x810);
PKMN_OFFSET_ASSERT(Unk_1363ac0_T, field_800, 0x800);

class Unk_2432200 : public Unk_2431de8 {
public:
    Unk_2432200();
    ~Unk_2432200() override;
    void vf7() override;  // reset the block and write it
    void vf8() override;  // read the block from the store
    void vf9() override;  // write it

    // Clears the entries and draws their numbers and both seeds anew.
    void Unk_1363780();
    // Draws the numbers of the entries in state 2 again from the seed (and
    // sets them to state 1), then moves to the next seed.
    void Unk_1363cf0();

    Unk_1363ac0_T field_60;
};
PKMN_OFFSET_ASSERT(Unk_2432200, field_60, 0x60);
PKMN_SIZE_ASSERT(Unk_2432200, 0x870);

// A xoroshiro128+ generator, as a URNG for libc++'s distributions (as in
// src/unsorted/Unk_1373970.cpp).
class Unk_ead0f0_Random {
public:
    using result_type = u64;
    static constexpr u64 min() { return 0; }
    static constexpr u64 max() { return ~0ull; }

    Unk_ead0f0_Random() : field_0(0x0f4b17a579f18960), field_8(0x82a2b175229d6a5b), field_10(0) {}

    // 0x7100ead0f0
    void Unk_ead0f0(u64 seed);

    u64 operator()() {
        u64 s0 = field_0;
        u64 s1 = field_8;
        u64 result = s0 + s1;
        s1 ^= s0;
        field_0 = ((s0 << 24) | (s0 >> 40)) ^ s1 ^ (s1 << 16);
        field_8 = (s1 << 37) | (s1 >> 27);
        return result;
    }

    u64 field_0;
    u64 field_8;
    u64 field_10;  // the seed
};
PKMN_SIZE_ASSERT(Unk_ead0f0_Random, 0x18);

// 0x7100ead110: a random seed (8 random bytes from the SDK).
u64 Unk_ead110();
