#pragma once
// A class of game/unk_133d350 (vtable 0x7102432af0) whose data is one block of
// the scrambled block store (src/unsorted/families/Unk_13471e0.h): a table of
// 400 entries, one per number that 0x71012fa520 gives a species (counted from
// 1; 0x71012fa530 is its inverse), what the battle code hands it, and four
// records of a Pokemon. Placeholder names: rename once the class is known.
#include <types.h>

#include "unsorted/Unk_1392d70.h"

struct Unk_762fd0;

// 0x71012fa520: the number of a species in the table (0 when it has none).
u32 Unk_12fa520(u32 species);
// 0x71012fa530: the species of a number.
u32 Unk_12fa530(u32 number);

// What 0x71012f9ef0 reads from a Pokemon: its species, form and the values
// the table records (field_18 is a second form number, of species 869 only).
struct Unk_12f9ef0_Info {
    u32 field_0 = 0;
    u16 field_4 = 0;
    u32 field_8 = 0;
    u8 field_c = 0;
    bool field_d = false;
    u32 field_10 = 0;
    u32 field_14 = 0;
    s32 field_18 = -1;
};
PKMN_SIZE_ASSERT(Unk_12f9ef0_Info, 0x1c);
PKMN_OFFSET_ASSERT(Unk_12f9ef0_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_12f9ef0_Info, field_d, 0xd);
PKMN_OFFSET_ASSERT(Unk_12f9ef0_Info, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_12f9ef0_Info, field_18, 0x18);

// 0x71012f9ef0
void Unk_12f9ef0(Unk_12f9ef0_Info* info, const Unk_762fd0* pokemon);

// An entry of the table: a bit per form in each of field_0 (which one by the
// info's field_8 and field_c; bit 63 when its field_14 is 2), and a bit per
// value of 0x7100762fd0 in field_20_2.
struct Unk_2432ae0_Entry {
    u64 field_0[4];
    u32 field_20_0 : 1;
    u32 field_20_1 : 1;
    u32 field_20_2 : 13;
    u32 _20_15 : 17;  // unknown: the original reads the bits as a whole word
    u32 field_24;
    u8 _28[0x8];
};
PKMN_SIZE_ASSERT(Unk_2432ae0_Entry, 0x30);
PKMN_OFFSET_ASSERT(Unk_2432ae0_Entry, field_24, 0x24);

struct Unk_2432ae0_Record {
    Unk_12f9ef0_Info field_0;
    u32 field_1c;
};
PKMN_SIZE_ASSERT(Unk_2432ae0_Record, 0x20);

// The block: what goes to the store.
struct Unk_2432ae0_T {
    Unk_2432ae0_Entry field_0[400];
    u8 _4b00[0x2];
    u8 field_4b02;
    u8 field_4b03;
    u8 _4b04[0x4];
    Unk_2432ae0_Record field_4b08[4];
    u64 field_4b88;
    bool field_4b90;
    u8 _4b91[0x7];
    u64 field_4b98;
    u8 _4ba0[0x10];
};
PKMN_SIZE_ASSERT(Unk_2432ae0_T, 0x4bb0);
PKMN_OFFSET_ASSERT(Unk_2432ae0_T, field_4b02, 0x4b02);
PKMN_OFFSET_ASSERT(Unk_2432ae0_T, field_4b08, 0x4b08);
PKMN_OFFSET_ASSERT(Unk_2432ae0_T, field_4b88, 0x4b88);
PKMN_OFFSET_ASSERT(Unk_2432ae0_T, field_4b90, 0x4b90);
PKMN_OFFSET_ASSERT(Unk_2432ae0_T, field_4b98, 0x4b98);

class Unk_2432ae0 : public Unk_2431de8 {
public:
    Unk_2432ae0();
    ~Unk_2432ae0() override;
    void vf7() override;
    void vf8() override;
    void vf9() override;

    // The entry of a species: null when it has no number.
    Unk_2432ae0_Entry* Unk_GetEntry(u32 species) {
        u32 index = Unk_12fa520(species) - 1;
        if (index >= 400)
            return nullptr;
        return field_60.field_0 + index;
    }

    u32 Unk_1379660(u32 species);
    void Unk_13796b0(u32 species);
    void Unk_1379700(const Unk_762fd0* pokemon, u32 kind);
    void Unk_13797a0(const Unk_12f9ef0_Info* info, u32 value);
    bool Unk_1379870(const Unk_12f9ef0_Info* info);
    void Unk_1379aa0(const Unk_762fd0* pokemon, u32 kind);
    bool Unk_1379b90(u32 species);
    u32 Unk_1379c20();
    bool Unk_1379c60(const Unk_12f9ef0_Info* info);
    bool Unk_1379d60();
    bool Unk_1379da0();
    void Unk_1379170(u32 species, u32 field_8, u8 field_c, u32 form, u32 field_14);

    bool Unk_1379df0(u32 species, u32 value);
    u32 Unk_1379eb0();
    u8 Unk_1379ef0();
    void Unk_1379f00(u8 value);
    void Unk_1379f10(u8 value);
    u8 Unk_1379f20();
    bool Unk_1379f90(u32 species);
    u32 Unk_137a010();
    bool Unk_137a050();
    void Unk_137a060();
    Unk_2432ae0_Record* Unk_137a070(u32 index);
    u32 Unk_137a090(u32 index);
    bool Unk_137a0b0(const Unk_12f9ef0_Info* info, u32 value);
    void Unk_137a170(u64 value);

    Unk_2432ae0_T field_60;
};
PKMN_OFFSET_ASSERT(Unk_2432ae0, field_60, 0x60);
PKMN_SIZE_ASSERT(Unk_2432ae0, 0x4c10);

// 0x7101379460: whether a species has the form that field_14 == 2 stands
// for. It doesn't use its first parameter, which the callers leave unset: an
// empty object, passed by value.
struct Unk_1379460_Arg {};
bool Unk_1379460(Unk_1379460_Arg, u32 species);

// The form bit of an info: species 869 counts both its form numbers.
inline u32 Unk_2432ae0_Form(u32 species, u32 form, s32 second) {
    if (species == 869)
        form = form * 7 + second;
    if (form > 62)
        form = 0;
    return form;
}

// The bit of field_20_2 of a value of 0x7100762fd0.
inline u32 Unk_2432ae0_ValueBit(u32 value) {
    switch (value) {
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 8;
        default:
            return 0;
    }
}
