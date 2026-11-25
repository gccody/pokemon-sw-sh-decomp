#pragma once
// A class of game/unk_133d350 (vtable 0x7102432c78) whose data is one block of
// the scrambled block store (src/unsorted/families/Unk_13471e0.h): two tables
// of 15 x 1024 bits, the second kept inverted (a bit that's clear is on).
// field_60 is the object 0x7100b751c0 looks entries up in, taken from
// Unk_24ba5a8 whenever the block is read or written. Placeholder names:
// rename once the class is known.
#include <cstring>

#include <types.h>

#include "unsorted/Unk_1392d70.h"

// What 0x7100b751c0 is a member of (0x7100b4c070 hands it out).
class Unk_b751c0_Self : public Unk_239a418 {};

// The block: what goes to the store.
struct Unk_137c710_T {
    u8 field_0[15][0x80];
    u8 field_780[15][0x80];
    u32 field_f00;
    u8 field_f04;
    u8 field_f05[0x17];

    void Unk_Reset() {
        std::memset(field_0, 0, sizeof(field_0));
        std::memset(field_780, 0, sizeof(field_780));
        field_f00 = 0;
        field_f04 = 2;
        std::memset(field_f05, 0, sizeof(field_f05));
    }
};
PKMN_SIZE_ASSERT(Unk_137c710_T, 0xf1c);
PKMN_OFFSET_ASSERT(Unk_137c710_T, field_f00, 0xf00);
PKMN_OFFSET_ASSERT(Unk_137c710_T, field_f04, 0xf04);

class Unk_2432c78 : public Unk_2431de8 {
public:
    Unk_2432c78();
    ~Unk_2432c78() override;
    void vf7() override;  // reset the block and write it
    void vf8() override;  // read the block from the store
    void vf9() override;  // write it

    bool Unk_137c850(s32 index, u32 bit);
    bool Unk_137c8a0(s32 index, const u64& key);
    void Unk_137c9c0(s32 index, u32 bit, bool value);
    void Unk_137ca10(s32 index, const u64& key, bool value);
    bool Unk_137cb30(s32 index, u32 bit);
    void Unk_137cb80(s32 index, u32 bit, bool value);

    Unk_b751c0_Self* field_60;
    Unk_137c710_T field_68;
};
PKMN_OFFSET_ASSERT(Unk_2432c78, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_2432c78, field_68, 0x68);
PKMN_SIZE_ASSERT(Unk_2432c78, 0xf88);
