#pragma once
// Two small records of the battle logic (0x71008a7f30 to 0x71008a81c0):
// one of 0x18 bytes, and a list of up to five entries (0x34 bytes) its
// constructor sizes from it. The leaf accessors in
// src/unsorted/leaf/Unk_8a7f50.cpp read and write the same fields.
// Placeholder names: rename once the classes are known.
#include <types.h>

// A 0x18-byte record: a u32, a u64, the list's capacity, a flag and six
// bytes 0x71008a7fe0 fills with 2.
struct Unk_8a7fc0 {
    Unk_8a7fc0(u32 a0, u64 a1, u8 a2);  // 0x71008a7fc0
    void Unk_8a7fe0(u8 count);          // 0x71008a7fe0

    u32 field_0;
    u64 field_8;
    u8 field_10;
    u8 field_11;
    u8 field_12[6];
};
PKMN_SIZE_ASSERT(Unk_8a7fc0, 0x18);
PKMN_OFFSET_ASSERT(Unk_8a7fc0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8a7fc0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8a7fc0, field_12, 0x12);

// A list of up to five entries, each a u32, two u8s, a u16 and a u8 in
// parallel arrays, with its count, its capacity and a flag.
struct Unk_8a8030 {
    explicit Unk_8a8030(const Unk_8a7fc0& record);            // 0x71008a8030
    void Unk_8a8080(u8 a0, u8 a1);                            // 0x71008a8080
    u8 Unk_8a8120() const;                                    // 0x71008a8120
    u8 Unk_8a8140(u8 index) const;                            // 0x71008a8140
    void Unk_8a8160(u32 a0, u8 a1, u16 a2, u8 a3);            // 0x71008a8160
    bool Unk_8a81c0(u32* a0, u8* a1, u16* a2, u8* a3) const;  // 0x71008a81c0

    u32 field_0;
    u32 field_4[5];
    u8 field_18[5];
    u8 field_1d[5];
    u16 field_22[5];
    u8 field_2c[5];
    u8 field_31;
    u8 field_32;
    bool field_33;
};
PKMN_SIZE_ASSERT(Unk_8a8030, 0x34);
PKMN_OFFSET_ASSERT(Unk_8a8030, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_8a8030, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_8a8030, field_1d, 0x1d);
PKMN_OFFSET_ASSERT(Unk_8a8030, field_22, 0x22);
PKMN_OFFSET_ASSERT(Unk_8a8030, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_8a8030, field_31, 0x31);
PKMN_OFFSET_ASSERT(Unk_8a8030, field_33, 0x33);
