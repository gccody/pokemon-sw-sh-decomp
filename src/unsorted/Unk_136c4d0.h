#pragma once
// A class of game/unk_133d350 (vtable 0x7102432618) whose data is one block of
// the scrambled block store (src/unsorted/families/Unk_13471e0.h): a table of
// 110 entries and a value after it, read from and written to the store whole.
// Placeholder names: rename once the class is known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/families/Unk_13471e0.h"

// The base (vtable 0x7102431858), as in src/unsorted/virtual/Unk_1345f20.cpp.
class Unk_2431de8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_2431de8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

// An entry's key: a class of its own (its setter copies it whole, not a u64).
struct Unk_136c4d0_Key {
    u64 field_0;
};
PKMN_SIZE_ASSERT(Unk_136c4d0_Key, 0x8);

// An entry of the table. The magic key 0x0cf9069c673b98d1 in field_0 marks
// the entries the setter of field_a60 updates.
struct Unk_136c4d0_Entry {
    Unk_136c4d0_Key field_0;
    u64 field_8;
    u8 field_10;
    u8 field_11;
    s8 field_12 : 8;
    bool field_13_0 : 1;
    bool field_13_1 : 1;
};
PKMN_SIZE_ASSERT(Unk_136c4d0_Entry, 0x18);
PKMN_OFFSET_ASSERT(Unk_136c4d0_Entry, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_136c4d0_Entry, field_11, 0x11);

// The block: what goes to the store.
struct Unk_136c4d0_T {
    Unk_136c4d0_Entry field_0[110];
    u8 _a50[0x10];
    u16 field_a60;
    u8 _a62[0x6];
};
PKMN_SIZE_ASSERT(Unk_136c4d0_T, 0xa68);
PKMN_OFFSET_ASSERT(Unk_136c4d0_T, field_a60, 0xa60);

class Unk_2432608 : public Unk_2431de8 {
public:
    ~Unk_2432608() override;
    void vf7() override;
    void vf8() override;  // read the block from the store
    void vf9() override;  // write it

    u32 Unk_136c700(const int& index);
    void Unk_136c720(const int& index, const Unk_136c4d0_Key& value);
    void Unk_136c740(const int& index, const u64& value);
    void Unk_136c760(const int& index, const u8& value);
    void Unk_136c780(const int& index, const u8& value);
    void Unk_136c7a0(const int& index, const int& value);
    void Unk_136c7e0(const int& index, const bool& value);
    int Unk_136c810(const int& index);
    void Unk_136c830(const int& index, const bool& value);
    bool Unk_136c860(const int& index);
    bool Unk_136c880(const int& index);
    void Unk_136c8a0(const u16& value);
    bool Unk_136c910(const int& index);
    u32 Unk_136c940(const int& index);
    u32 Unk_136c960(const int& index);

    Unk_136c4d0_T field_60;
};
PKMN_OFFSET_ASSERT(Unk_2432608, field_60, 0x60);
