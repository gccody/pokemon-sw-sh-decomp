#pragma once
// The Poke Job app's save data (game/unk_133d350, vtable 0x7102432938): a
// class on the block store's base (src/unsorted/Unk_1392d70.h) whose blocks
// are the job table (Unk_24ba4e0->field_268 hands it to the app,
// src/unsorted/Unk_1298270.h), 32 lists of up to 30 entries of the kind
// unk_761f70 reads and writes (Unk_1393080_Entry), and a few counters.
// Placeholder names: rename once the class is known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_1392d70.h"

// What 0x710076f440 constructs (game/unk_761f70): the object a list entry is
// read into.
class Unk_76f440 : public Unk_239a418 {
public:
    explicit Unk_76f440(Unk_239a418_Allocator* allocator);

    u8 _60[0x58];
};
PKMN_SIZE_ASSERT(Unk_76f440, 0xb8);

// A job of the table.
struct Unk_2432938_Job {
    u8 field_0;  // its state
    u8 field_1;
    u8 field_2;
    u64 field_8;   // when it reached state 2
    u64 field_10;  // when it reached state 4 or 5
    u8 field_18;
    bool field_19;
    u8 _1a[0x16];
};
PKMN_OFFSET_ASSERT(Unk_2432938_Job, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2432938_Job, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2432938_Job, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_2432938_Job, field_19, 0x19);
PKMN_SIZE_ASSERT(Unk_2432938_Job, 0x30);

// The job table's block.
struct Unk_1373320_R {
    Unk_2432938_Job field_0[167];
};
PKMN_SIZE_ASSERT(Unk_1373320_R, 0x1f50);

// A list: its length and its entries.
struct Unk_2432938_List {
    u8 field_0;
    Unk_1393080_Entry field_1[30];
    u8 _2851[0x10];
};
PKMN_OFFSET_ASSERT(Unk_2432938_List, field_1, 0x1);
PKMN_SIZE_ASSERT(Unk_2432938_List, 0x2861);

// The lists' block.
struct Unk_1373460_R {
    Unk_2432938_List field_0[32];
};
PKMN_SIZE_ASSERT(Unk_1373460_R, 0x50c20);

// The third block. What's in it isn't known yet.
struct Unk_13735a0_R {
    u8 _0[0x538];
};
PKMN_SIZE_ASSERT(Unk_13735a0_R, 0x538);

class Unk_2432938 : public Unk_2431de8 {
public:
    ~Unk_2432938() override;
    void vf7() override;
    void vf8() override;
    void vf9() override;  // write the blocks and counters

    Unk_2432938_List* Unk_13736f0(s32 list);
    void Unk_1373710(s32 job, u8 value);
    void Unk_1373720(s32 job, u64 time);
    void Unk_1373730(s32 job, u64 time);
    void Unk_1373740(s32 job, u8 value);
    void Unk_1373750(s32 job, u8 value);
    void Unk_1373760(s32 job, u8 value);
    void Unk_1373770(s32 list, void* const& object);
    bool Unk_13737c0(s32 list, void* const& object);
    Unk_239a418_Ref<Unk_76f440> Unk_1373860(s32 list, s32 index, Unk_239a418_Allocator* allocator);

    Unk_1373320_R field_60;
    Unk_1373460_R field_1fb0;
    u32 field_52bd0;
    u32 field_52bd4;
    u32 field_52bd8;
    u64 field_52be0;
    Unk_13735a0_R field_52be8;
    u8 field_53120;
};
PKMN_OFFSET_ASSERT(Unk_2432938, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_2432938, field_1fb0, 0x1fb0);
PKMN_OFFSET_ASSERT(Unk_2432938, field_52bd0, 0x52bd0);
PKMN_OFFSET_ASSERT(Unk_2432938, field_52be0, 0x52be0);
PKMN_OFFSET_ASSERT(Unk_2432938, field_52be8, 0x52be8);
PKMN_OFFSET_ASSERT(Unk_2432938, field_53120, 0x53120);
