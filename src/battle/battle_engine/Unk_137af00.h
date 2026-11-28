#pragma once
// A class of game/unk_133d350 (vtable 0x7102432bb8) whose data is one block of
// the scrambled block store (src/unsorted/families/Unk_13471e0.h), key
// 0x1b882b09, and five values it stores on their own, each under a key of its
// own. In the block: a word of bits whose count picks an entry of a table of
// 9 multipliers (0x710137ba50), a counter capped at 9,999,999 (0x710137b8e0
// adds to it) and a string of u16 units at +0x200. Of the values: field_27c is
// an item ID that 0x710137bb10 accepts only as 76, 77 or 79, and field_27e a
// count it starts at 200, 250 or 100 with it. Placeholder names: rename once
// the class is known.
#include <types.h>

#include "unsorted/Unk_1392d70.h"

// The block: what goes to the store.
struct Unk_137b770_T {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u8 _c[0x100];
    s32 field_10c;
    s32 field_110;
    u8 _114[0x1c];
    u32 field_130;
    u8 _134[0xcc];
    u16 field_200[14];
};
PKMN_SIZE_ASSERT(Unk_137b770_T, 0x21c);
PKMN_OFFSET_ASSERT(Unk_137b770_T, field_10c, 0x10c);
PKMN_OFFSET_ASSERT(Unk_137b770_T, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_137b770_T, field_200, 0x200);

struct Unk_67be60;

// final: vf7 calls vf9 and vf10 directly (it inlines vf10 and tail-calls
// vf9), as the constructor does vf10.
class Unk_2432ba8 final : public Unk_2431de8 {
public:
    Unk_2432ba8();
    ~Unk_2432ba8() override;
    void vf7() override;  // reset everything and write it
    void vf8() override;  // read everything from the store
    void vf9() override;  // write it
    virtual void vf10();  // reset everything

    u32 Unk_137b970();
    void Unk_137b9a0(u8 count);
    u32 Unk_137bb00(Unk_67be60* target);

    Unk_137b770_T field_60;
    u16 field_27c;
    u16 field_27e;
    u8 field_280;
    u16 field_282;
    u32 field_284;
};
PKMN_OFFSET_ASSERT(Unk_2432ba8, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_2432ba8, field_27c, 0x27c);
PKMN_OFFSET_ASSERT(Unk_2432ba8, field_280, 0x280);
PKMN_OFFSET_ASSERT(Unk_2432ba8, field_282, 0x282);
PKMN_OFFSET_ASSERT(Unk_2432ba8, field_284, 0x284);
PKMN_SIZE_ASSERT(Unk_2432ba8, 0x288);

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// What the store's reads of one value return: whether it was there, and the
// value.
template <class T>
struct Unk_2432ba8_Value {
    u8 field_0;
    T field_value;
};

// The store's reads and writes of one value, by key: a u16 (0x7101346e90,
// 0x7101345aa0), a u8 (0x710134d370, 0x710134c3e0) and a u32 (0x71013586b0,
// 0x7101358150).
Unk_2432ba8_Value<u16> Unk_1346e90(Unk_13471e0_Store* self, const u32& key);
Unk_2432ba8_Value<u8> Unk_134d370(Unk_13471e0_Store* self, const u32& key);
Unk_2432ba8_Value<u32> Unk_13586b0(Unk_13471e0_Store* self, const u32& key);
bool Unk_1345aa0(Unk_13471e0_Store* self, const u32& key, const u16& value);
bool Unk_134c3e0(Unk_13471e0_Store* self, const u32& key, const u8& value);
bool Unk_1358150(Unk_13471e0_Store* self, const u32& key, const u32& value);
