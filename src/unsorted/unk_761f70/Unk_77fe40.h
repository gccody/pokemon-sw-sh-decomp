#pragma once
// The stat formula shared by src/unsorted/unk_761f70/Unk_77f5f0.cpp and
// Unk_77fe40.cpp.
#include <types.h>

// The nature table: per nature, -1 (cut), 0 or 1 (raise) for each of the five
// non-HP stats.
extern const s8 Unk_1f0c438[][5] __attribute__((visibility("hidden")));

// National Pokédex number; its HP is always 1.
constexpr u32 Unk_77fe40_SPECIES_SHEDINJA = 292;

// A stat before the nature: (2 * base + IV + EVs / 4) * level / 100 + 5.
inline u16 Unk_77fe40_CalcStat(u8 level, u16 base, u16 iv, u16 ev) {
    return (base * 2 + iv + ev / 4) * level / 100 + 5;
}

// The nature's 10% raise or cut of one of the five non-HP stats.
inline u16 Unk_77fe40_ApplyNature(u16 stat, u32 nature, u32 index) {
    switch (Unk_1f0c438[static_cast<u16>(nature)][index]) {
        case 1:
            return static_cast<u16>(stat * 110) / 100;
        case -1:
            return static_cast<u16>(stat * 90) / 100;
    }
    return stat;
}
