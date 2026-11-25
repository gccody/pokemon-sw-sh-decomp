#pragma once
// The round-trip times transport::RttProtocol keeps per station (its
// 0x58-byte entries at 0x58): the last 9 samples in a ring, their minimum,
// maximum and a cached median. Not polymorphic and no RTTI: placeholder
// names, after its constructor (lib/pia/common/Unk_17484c0.cpp). Its small
// members tools/leafgen.py matched (lib/nx_middleware/leaf/Unk_1721740.cpp)
// take their own placeholder structs: Unk_1748d10_set (clears the minimum and
// maximum), Unk_1748d20_get (the minimum), Unk_1748d40_get (the maximum) and
// Unk_1748e60_set (starts timing).
#include "pia/common/Unk_165e060.h"

// The ring of the last 9 samples (Unk_1748ab0's field_1c).
struct Unk_1748ab0_1c {
    // A sample, from the oldest.
    s32 At(size_t index) const { return data[(head + index) % 9]; }

    void Push(s32 sample) {
        data[(head + count) % 9] = sample;
        if (count == 9) {
            head = (head + 1) % 9;
        } else {
            ++count;
        }
    }

    void Clear() {
        count = 0;
        head = 0;
    }

    u32 count;  // at most 9
    u32 head;   // the oldest sample
    s32 data[9];
};
PKMN_OFFSET_ASSERT(Unk_1748ab0_1c, head, 0x4);
PKMN_OFFSET_ASSERT(Unk_1748ab0_1c, data, 0x8);
PKMN_SIZE_ASSERT(Unk_1748ab0_1c, 0x2c);

struct Unk_1748ab0 {
    Unk_1748ab0();

    s32 Unk_1748af0();          // the median of the last 9 samples (-1: none)
    s32 Unk_1748c00(u32 count); // the median of the last `count` samples (-1: none)
    void Unk_1748d60();         // starts measuring
    void Unk_1748da0();         // stops measuring
    bool Unk_1748de0();         // the timing started by Unk_1748e60_set has expired
    void Unk_1748e80(s32 sample);  // adds a sample

    void Reset() {
        field_4 = -1;
        field_8 = -1;
        field_c = -1;
        field_10 = 0;
        field_18 = false;
        field_48 = 0;
        field_4c = 0;
        field_1c.Clear();
        field_50 = 0;
    }

    bool field_0;      // measuring
    s32 field_4;       // the last sample
    s32 field_8;       // the smallest sample (-1: none)
    s32 field_c;       // the largest sample (-1: none)
    s64 field_10;      // a tick
    bool field_18;     // field_10 is set
    Unk_1748ab0_1c field_1c;  // the last samples
    u32 field_48;      // the sample count field_4c is the median of (0: none)
    s32 field_4c;      // the cached median
    u32 field_50;      // the samples added
};
PKMN_OFFSET_ASSERT(Unk_1748ab0, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1748ab0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1748ab0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1748ab0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1748ab0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1748ab0, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_1748ab0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_1748ab0, field_4c, 0x4c);
PKMN_OFFSET_ASSERT(Unk_1748ab0, field_50, 0x50);
PKMN_SIZE_ASSERT(Unk_1748ab0, 0x58);

// The leaf members (lib/nx_middleware/leaf/Unk_1721740.cpp).
struct Unk_1748d10;
struct Unk_1748d20;
struct Unk_1748d40;
void Unk_1748d10_set(Unk_1748d10* self);
s32 Unk_1748d20_get(const Unk_1748d20* self);
s32 Unk_1748d40_get(const Unk_1748d40* self);
