// Scope: common
// Pokémon stat rules: a stat from its base stat, IV, EVs and level (with the
// nature's 10% raise or cut, and a variant that scales it by a float table),
// HP (with Shedinja's fixed 1 and a per-level float multiplier), and the
// shiny check on a PID against a trainer ID, with the PID changes that make
// a Pokémon shiny or not. Placeholder names: rename once the owning classes
// are known.
#include "unsorted/unk_761f70/Unk_77fe40.h"

// HP multipliers, by a 0-10 level.
extern const f32 Unk_1f0c3e0[11] __attribute__((visibility("hidden")));
// Stat multipliers, by a 0-100 value divided by 10.
extern const f32 Unk_1f0c40c[11] __attribute__((visibility("hidden")));

namespace {

inline f32 CalcScaledStat(u8 level, u16 base, u16 iv, u16 ev, u8 value) {
    u32 index = value / 10;
    if (index > 10) {
        index = 10;
    }
    return Unk_1f0c40c[index] * (base * 2 + iv + ev / 4) * level / 100.0f + 5.0f;
}

inline bool IsShiny(u32 id, u32 pid) {
    u32 xor_ = (id >> 16) ^ (id & 0xffff) ^ (pid >> 16) ^ (pid & 0xffff);
    return xor_ < 16;
}

}  // namespace

// 0x710077fe40
u16 Unk_77fe40(u8 level, u16 base, u16 iv, u16 ev, u32 nature) {
    return Unk_77fe40_ApplyNature(Unk_77fe40_CalcStat(level, base, iv, ev), nature, 1);
}

// 0x710077fec0
u16 Unk_77fec0(u8 level, u16 base, u16 iv, u16 ev, u32 nature) {
    return Unk_77fe40_ApplyNature(Unk_77fe40_CalcStat(level, base, iv, ev), nature, 2);
}

// 0x710077ff40
u16 Unk_77ff40(u8 level, u16 base, u16 iv, u16 ev, u32 nature) {
    return Unk_77fe40_ApplyNature(Unk_77fe40_CalcStat(level, base, iv, ev), nature, 3);
}

// 0x710077ffc0
u16 Unk_77ffc0(u8 level, u16 base, u16 iv, u16 ev, u32 nature) {
    return Unk_77fe40_ApplyNature(Unk_77fe40_CalcStat(level, base, iv, ev), nature, 4);
}

// 0x7100780040
// NON_MATCHING: the sum and the level swap registers (w8/w9).
u16 Unk_780040(u32 species, u8 level, u16 base, u16 iv, u16 ev, u8 hpLevel) {
    if (species == Unk_77fe40_SPECIES_SHEDINJA) {
        return 1;
    }
    if (hpLevel > 10) {
        hpLevel = 10;
    }
    f32 rate = Unk_1f0c3e0[hpLevel];
    u32 hp = static_cast<u16>(level + 10 + (base * 2 + iv + ev / 4) * level / 100);
    return rate * hp;
}

// 0x71007800c0
u16 Unk_7800c0(u8 level, u16 base, u16 iv, u16 ev, u8 value, u32 nature) {
    u16 stat = CalcScaledStat(level, base, iv, ev, value);
    return Unk_77fe40_ApplyNature(stat, nature, 0);
}

// 0x7100780180
u16 Unk_780180(u8 level, u16 base, u16 iv, u16 ev, u8, u32 nature) {
    return Unk_77fe40_ApplyNature(Unk_77fe40_CalcStat(level, base, iv, ev), nature, 1);
}

// 0x7100780200
u16 Unk_780200(u8 level, u16 base, u16 iv, u16 ev, u8 value, u32 nature) {
    u32 stat = CalcScaledStat(level, base, iv, ev, value);
    return Unk_77fe40_ApplyNature(stat, nature, 2);
}

// 0x71007802c0
u16 Unk_7802c0(u8 level, u16 base, u16 iv, u16 ev, u8, u32 nature) {
    return Unk_77fe40_ApplyNature(Unk_77fe40_CalcStat(level, base, iv, ev), nature, 3);
}

// 0x7100780340
u16 Unk_780340(u8 level, u16 base, u16 iv, u16 ev, u8, u32 nature) {
    return Unk_77fe40_ApplyNature(Unk_77fe40_CalcStat(level, base, iv, ev), nature, 4);
}

// 0x71007803c0
u8 Unk_7803c0(u64 nature, u32 stat) {
    if (stat - 1 >= 5) {
        return 0;
    }
    return Unk_1f0c438[static_cast<u16>(nature)][stat - 1];
}

// 0x71007803f0
bool Unk_7803f0(u32 id, u32 pid) {
    return IsShiny(id, pid);
}

// 0x7100780410
u32 Unk_780410(u32 id, u32 pid) {
    if (IsShiny(id, pid)) {
        pid ^= 0x10000000;
    }
    return pid;
}

// 0x7100780440
u32 Unk_780440(u32 id, u32 pid) {
    if (IsShiny(id, pid)) {
        return pid;
    }
    u32 high = ((id >> 16) ^ id ^ pid) & 0xffff;
    return (pid & 0xffff) | (high << 16);
}

// 0x7100780480
// NON_MATCHING: the original keeps (id ^ pid) >> 16 shared between the two
// checks and masks the low halves separately; clang folds the whole xor here.
u32 Unk_780480(u32 id, u32 pid) {
    u32 xor_ = (id >> 16) ^ (id & 0xffff) ^ (pid >> 16) ^ (pid & 0xffff);
    if (xor_ >= 16) {
        return 0;
    }
    return xor_ == 0 ? 2 : 1;
}

// 0x71007804c0
u32 Unk_7804c0(u32 id, u32 pid, u8 shinyType) {
    if (shinyType == 0) {
        return Unk_780410(id, pid);
    }
    u32 high = ((id >> 16) ^ id ^ pid ^ (shinyType == 1)) & 0xffff;
    return (pid & 0xffff) | (high << 16);
}
