// Scope: common
// Battle calculations after the battle Pokemon's TU (0x71007f7690 on): random
// numbers, fixed-point ratios, stage tables. The battle Pokemon's TU calls
// them out of line, so they're a TU of their own. Placeholder names: rename
// once the functions are known.
#include "battle/battle_engine/Unk_7ee6b0.h"

// 0x71007f7690
u32 Unk_7f7690(u32 max) {
    return Unk_7f8c20(Unk_27ced28, max);
}

// 0x71007f7700
u32 Unk_7f7700(u32 value, u32 ratio) {
    u32 product = value * ratio;
    u32 fraction = product & 0xfff;
    u32 result = product >> 12;
    if (fraction > 0x800)
        result++;
    return result;
}

// 0x71007f7720
u16 Unk_7f7720(u32 value, u32 ratio) {
    u32 product = value * ratio;
    u32 fraction = product & 0xfff;
    u32 result = product >> 12;
    if (fraction > 0x800)
        result++;
    if (result == 0)
        result = 1;
    return result;
}

// 0x71007f7740
u32 Unk_7f7740(u32 value, u32 percent) {
    u32 product = value * percent;
    u32 result = product / 100;
    if (product % 100 > 49)
        result++;
    return result;
}

// A condition as Unk_7f7940 makes it: a kind, turns and a Pokemon.
union Unk_7f7940_Condition {
    u64 field_0;
    struct {
        u64 kind : 3;
        u64 turns : 5;
        u64 pokeId : 6;
    };
};

// 0x71007f7940
// NON_MATCHING: the original builds the value with bfi
u64 Unk_7f7940(u8 pokeId, u8 turns) {
    Unk_7f7940_Condition condition;
    condition.field_0 = 0;
    condition.kind = 3;
    condition.turns = turns;
    condition.pokeId = pokeId;
    return condition.field_0;
}

// 0x71007f7960
u16 Unk_7f7960(u16 value, u8 stage) {
    if (stage > 12)
        return value;
    u16 product = Unk_1f118f4[stage].field_0 * value;
    return product / Unk_1f118f4[stage].field_1;
}

// 0x71007f7990
u32 Unk_7f7990(Unk_7ee6b0* self, u32 divisor, bool check) {
    u32 d = divisor != 0 ? divisor : 1;
    u32 hp;
    if (check && Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(self)))
        hp = Unk_7eef50(self, 0x10);
    else
        hp = Unk_7eef50(self, 0xf);
    return hp / d;
}

// 0x71007f79e0
u32 Unk_7f79e0(Unk_7ee6b0* self, u32 divisor, bool check) {
    u32 d = divisor != 0 ? divisor : 1;
    u32 hp;
    if (check && Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(self)))
        hp = Unk_7eef50(self, 0x10);
    else
        hp = Unk_7eef50(self, 0xf);
    u32 result = hp / d;
    if (d > hp)
        result = 1;
    return result;
}

// 0x71007f7a40
u8 Unk_7f7a40(u8 value, u8 stage) {
    if (stage > 12)
        return value;
    u32 result = value * Unk_1f1190e[stage].field_0 / Unk_1f1190e[stage].field_1;
    return result < 100 ? result : 100;
}

// 0x71007f7a80
bool Unk_7f7a80(u8 index, s32 divisor) {
    if (index < 4) {
        u8 range = Unk_1b14ad0[index] / divisor;
        u32 max = range != 0 ? range : 1;
        return static_cast<u8>(Unk_7f8c20(Unk_27ced28, max)) == 0;
    }
    return false;
}

// 0x71007f7b00
bool Unk_7f7b00(u32 arg) {
    return Unk_785c80(Unk_27cecf0, arg, 0x12) == 5;
}

// 0x71007f7b30
bool Unk_7f7b30(u32 arg) {
    return Unk_785c80(Unk_27cecf0, arg, 0x12) == 6;
}

// 0x71007f7b60
u32 Unk_7f7b60(u16 species, u8 form, u32 param) {
    Unk_76bc60(species, form);
    return Unk_76bc80(param);
}

// 0x71007f7b90
u32 Unk_7f7b90(u16 species, u8 form, u32 param) {
    Unk_76bd60(species, form);
    return Unk_76bdf0(param);
}

// 0x71007f7c40
bool Unk_7f7c40(s32 condition) {
    return condition < 6;
}

// 0x71007f7c50
u16 Unk_7f7c50(Unk_7ee6b0* poke, u8 kind) {
    switch (kind) {
        case 4:
            if (Unk_7f0670(poke, 5))
                return 0;
            if (Unk_7f0670(poke, 8))
                return 0;
            if (Unk_7f0670(poke, 4))
                return 0;
            break;
        case 3:
            if (Unk_7f0670(poke, 0xe))
                return 0;
            break;
        default:
            return 0;
    }
    s32 hp = Unk_7eef50(poke, 0x10);
    u16 damage = hp / 16;
    return damage != 0 ? damage : 1;
}

// 0x71007f7d40
u32 Unk_7f7d40(u8 type, u8 weather) {
    switch (type) {
        case 1:
        case 6:
            if (weather == 9)
                return 0x1800;
            if (weather == 0xa)
                return 0x800;
            return 0x1000;
        case 2:
        case 5:
            if (weather == 9)
                return 0x800;
            if (weather == 0xa)
                return 0x1800;
            return 0x1000;
        default:
            return 0x1000;
    }
}

// 0x71007f7db0
bool Unk_7f7db0(u8 value) {
    switch (value) {
        case 1:
        case 6:
            return true;
        default:
            return false;
    }
}

// 0x71007f7dd0
bool Unk_7f7dd0(u8 value) {
    switch (value) {
        case 2:
        case 5:
            return true;
        default:
            return false;
    }
}

// 0x71007f7f30
// NON_MATCHING: block layout of the default case
u8 Unk_7f7f30(u8 count) {
    if (count == 5) {
        u8 value = Unk_7f8c20(Unk_27ced28, 100);
        if (value < 0x23)
            return 2;
        if (value < 0x46)
            return 3;
        return value < 0x55 ? 4 : 5;
    }
    return count;
}

// 0x71007f7f90
u32 Unk_7f7f90(const Unk_7ee6b0* poke) {
    u32 i = 0;
    for (;;) {
        u32 condition = Unk_7eb660(i);
        if (condition == 0)
            return condition;
        i++;
        if (Unk_7ef4c0(poke, condition))
            return condition;
    }
}

// 0x71007f7ff0
bool Unk_7f7ff0(u32 percent) {
    return Unk_7f7690(100) < percent;
}

// 0x71007f8030
s32 Unk_7f8030(s32 a, s32 b) {
    return a < b ? b : a;
}

// 0x71007f8040
s32 Unk_7f8040(s32 a, s32 b) {
    return a > b ? b : a;
}

// 0x71007f8050
s32 Unk_7f8050(s32 value, s32 min, s32 max) {
    return Unk_7f8040(Unk_7f8030(value, min), max);
}

// 0x71007f8070
// NON_MATCHING: the original materialises the default argument before the tail call
u8 Unk_7f8070(u32 move, const Unk_7ee6b0* poke) {
    if (move == 0xae) {
        if (poke != nullptr)
            return Unk_7f0670(poke, 7) ? 0 : 7;
    }
    return Unk_7811e0(move);
}

// 0x71007f80c0
u8 Unk_7f80c0(const Unk_7ee6b0* poke) {
    return Unk_7f0670(poke, 7) ? 0 : 7;
}
