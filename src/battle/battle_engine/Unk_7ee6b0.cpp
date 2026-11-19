// Scope: common
// Member functions of the battle Pokemon (0x71007ed7b0 to 0x71007f7690).
// Placeholder names: rename once the functions are known.
#include "battle/battle_engine/Unk_7ee6b0.h"

// 0x71007eff10
u32 Unk_7eff10(const Unk_7ee6b0* self, u8 slot) {
    return self->field_2c8[slot].field_0.field_0;
}

// 0x71007eff30
bool Unk_7eff30(const Unk_7ee6b0* self, u8 slot) {
    return (self->field_2c8[slot].field_c.field_7 & 0xf) != 0;
}

// 0x71007eff50
void Unk_7eff50(const Unk_7ee6b0* self, Unk_7ee6b0* other) {
    for (s32 i = 0; i < 4; i++)
        other->field_2c8[i] = self->field_2c8[i];
    other->field_33c = self->field_33c;
}

// 0x71007f0010
u8 Unk_7f0010(const Unk_7ee6b0* self, u8 slot) {
    if (slot < self->field_33c)
        return self->field_2c8[slot].field_c.field_8;
    return 0;
}

// 0x71007f0040
void Unk_7f0040(Unk_7ee6b0* self, u8 slot, u8 value) {
    if (slot < self->field_33c) {
        self->field_2c8[slot].field_c.field_8 = value;
        if (self->field_2c8[slot].field_18)
            self->field_2c8[slot].field_0.field_8 = value;
    }
}

// 0x71007f0080
u8 Unk_7f0080(const Unk_7ee6b0* self, u8 slot) {
    if (slot < self->field_33c)
        return self->field_2c8[slot].field_c.field_9;
    return 0;
}

// 0x71007f00b0
void Unk_7f00b0(Unk_7ee6b0* self, u8 slot, u8 value) {
    if (slot < self->field_33c) {
        self->field_2c8[slot].field_c.field_9 = value;
        if (self->field_2c8[slot].field_18)
            self->field_2c8[slot].field_0.field_9 = value;
    }
}

// 0x71007f00f0
u8 Unk_7f00f0(const Unk_7ee6b0* self, u8 slot) {
    return self->field_2c8[slot].field_c.field_5 - self->field_2c8[slot].field_c.field_4;
}

// 0x71007f0110
u8 Unk_7f0110(const Unk_7ee6b0* self, u8 slot) {
    return self->field_2c8[slot].field_0.field_5 - self->field_2c8[slot].field_0.field_4;
}

// 0x71007f0130
u8 Unk_7f0130(const Unk_7ee6b0* self, u8 slot) {
    if (slot < self->field_33c)
        return self->field_2c8[slot].field_c.field_4;
    return 0;
}

// 0x71007f0160
u8 Unk_7f0160(const Unk_7ee6b0* self, u32 move) {
    for (u32 i = 0; i < self->field_33c; i++) {
        if (self->field_2c8[i].field_c.field_0 == move)
            return self->field_2c8[i].field_c.field_4;
    }
    return 0;
}

// 0x71007f01b0
u8 Unk_7f01b0(const Unk_7ee6b0* self, u8 slot) {
    return self->field_2c8[slot].field_0.field_4;
}

// 0x71007f01d0
u8 Unk_7f01d0(const Unk_7ee6b0* self, u8 slot) {
    if (slot < self->field_33c)
        return self->field_2c8[slot].field_c.field_5;
    return 0;
}

// 0x71007f0200
bool Unk_7f0200(const Unk_7ee6b0* self, u8 slot, bool original) {
    const Unk_7ee6b0_Move* move =
        original ? &self->field_2c8[slot].field_0 : &self->field_2c8[slot].field_c;
    if (move->field_0 != 0 && move->field_4 == move->field_5)
        return true;
    return false;
}

// 0x71007f0250
void Unk_7f0250(Unk_7ee6b0* self, u8 slot, u8 count) {
    u8 pp = self->field_2c8[slot].field_c.field_4;
    if (pp < count)
        pp = count;
    pp -= count;
    self->field_2c8[slot].field_c.field_4 = pp;
    if (self->field_2c8[slot].field_18) {
        self->field_2c8[slot].field_0.field_4 = pp;
        Unk_765b00(self->field_60.field_0, slot, pp);
    }
}

// 0x71007f0290
void Unk_7f0290(Unk_7ee6b0* self, u8 slot, u8 count) {
    if (self->field_2c8[slot].field_18)
        return;
    s32 pp = self->field_2c8[slot].field_0.field_4 - count;
    if (pp < 0)
        pp = 0;
    self->field_2c8[slot].field_0.field_4 = pp;
    Unk_765b00(self->field_60.field_0, slot, pp);
}

// 0x71007f02d0
u32 Unk_7f02d0(Unk_7ee6b0* self, u8 slot, u8 count) {
    u8 pp = self->field_2c8[slot].field_c.field_4 + count;
    if (pp > self->field_2c8[slot].field_c.field_5)
        pp = self->field_2c8[slot].field_c.field_5;
    self->field_2c8[slot].field_c.field_4 = pp;
    if (self->field_2c8[slot].field_18)
        self->field_2c8[slot].field_0.field_4 = pp;
    return self->field_2c8[slot].field_c.field_0;
}

// 0x71007f0320
u32 Unk_7f0320(Unk_7ee6b0* self, u8 slot, u8 count) {
    u8 pp = self->field_2c8[slot].field_0.field_4 + count;
    if (pp > self->field_2c8[slot].field_0.field_5)
        pp = self->field_2c8[slot].field_0.field_5;
    self->field_2c8[slot].field_0.field_4 = pp;
    if (self->field_2c8[slot].field_18)
        self->field_2c8[slot].field_c.field_4 = pp;
    return self->field_2c8[slot].field_0.field_0;
}

// 0x71007f0370
void Unk_7f0370(Unk_7ee6b0* self, u8 slot) {
    u8* bits = &self->field_2c8[slot].field_c.field_7;
    if ((*bits >> 4) == 0) {
        *bits = (*bits & 0xf) | 0x10;
        self->field_340++;
    }
    *bits = (*bits & 0xf0) | 1;
    if (self->field_2c8[slot].field_18)
        self->field_2c8[slot].field_0.field_7 = *bits;
}

// Sets a move slot's move and its PP, at most maxPP when that isn't 0.
static inline void Unk_7ee6b0_SetMove(Unk_7ee6b0_Move* m, u32 move, u8 maxPP) {
    m->field_0 = move;
    m->field_7 = 0;
    m->field_8 = 0;
    m->field_9 = 0;
    u8 pp = move != 0 ? Unk_780ca0(move, 0) : 0;
    if (pp > maxPP && maxPP != 0)
        pp = maxPP;
    m->field_5 = pp;
    m->field_4 = pp;
}

// 0x71007f03e0
void Unk_7f03e0(Unk_7ee6b0* self, u8 slot, u32 move, u8 maxPP, bool original) {
    if (original) {
        Unk_7ee6b0_SetMove(&self->field_2c8[slot].field_0, move, maxPP);
        if (self->field_2c8[slot].field_18)
            self->field_2c8[slot].field_c = self->field_2c8[slot].field_0;
    } else {
        Unk_7ee6b0_SetMove(&self->field_2c8[slot].field_c, move, maxPP);
        self->field_2c8[slot].field_18 = false;
    }
}

// 0x71007f0500
bool Unk_7f0500(const Unk_7ee6b0* self, u32 move) {
    for (s32 i = 0; i < 4; i++) {
        if (self->field_2c8[i].field_c.field_0 == move)
            return true;
    }
    return false;
}

// 0x71007f0540
u8 Unk_7f0540(const Unk_7ee6b0* self, u32 move) {
    if (move == 0)
        return 4;
    for (s32 i = 0; i < 4; i++) {
        if (self->field_2c8[i].field_c.field_0 == move)
            return i;
    }
    return 4;
}

// 0x71007f05a0
bool Unk_7f05a0(const Unk_7ee6b0* self, u32 flag) {
    return ((1 << (flag & 7)) & self->field_35c[static_cast<u8>(flag >> 3)]) != 0;
}

// 0x71007f0aa0
bool Unk_7f0aa0(const Unk_7ee6b0* self, u32 flag) {
    return ((1 << (flag & 7)) & self->field_358[static_cast<u8>(flag >> 3)]) != 0;
}

// 0x71007f0ad0
bool Unk_7f0ad0(const Unk_7ee6b0* self, u32 flag) {
    return ((1 << (flag & 7)) & self->field_360[static_cast<u8>(flag >> 3)]) != 0;
}

// Defense and special defense trade places while the effect at +0x460 lasts.
static inline u32 Unk_7ee6b0_Stat(const Unk_7ee6b0* self, u32 stat) {
    if (self->field_460 != nullptr) {
        if (stat == 9)
            stat = Unk_7ffe20(self->field_460, 4) ? 0xb : 9;
        else if (stat == 0xb)
            stat = Unk_7ffe20(self->field_460, 4) ? 9 : 0xb;
    }
    return stat;
}

// 0x71007f0750
void Unk_7f0750(Unk_7ee6b0* self, u32 stat, u16 value) {
    switch (Unk_7ee6b0_Stat(self, stat)) {
        case 8:
            self->field_2a2 = value;
            break;
        case 9:
            self->field_2a4 = value;
            break;
        case 0xa:
            self->field_2a6 = value;
            break;
        case 0xb:
            self->field_2a8 = value;
            break;
        case 0xc:
            self->field_2aa = value;
            break;
    }
}

// 0x71007f09e0
u16 Unk_7f09e0(Unk_7ee6b0* self, const Unk_7ee6b0_Field* field) {
    if (Unk_7ffe20(field, 5))
        return 0;
    if (self->field_60.field_30[0x13] & 7)
        return 0;
    if (Unk_7eef50(self, 0x13) == 0x67)
        return 0;
    return self->field_60.field_16;
}

// 0x71007f0b00
void Unk_7f0b00(Unk_7ee6b0* self, u32 flag) {
    self->field_360[static_cast<u8>(flag >> 3)] |= 1 << (flag & 7);
}

// 0x71007f0ba0
u8 Unk_7f0ba0(const Unk_7ee6b0* self, u32 index) {
    return self->field_361[index];
}

// 0x71007f0bb0
s32 Unk_7f0bb0(const Unk_7ee6b0* self) {
    f64 ratio =
        static_cast<f64>(self->field_60.field_14 * 100) / static_cast<f64>(self->field_60.field_12);
    return static_cast<s32>(ratio * 4096.0 + (ratio > 0.0 ? 0.5 : -0.5));
}

// The stage of a stat (1 to 7), nullptr for others.
static inline s8* Unk_7ee6b0_Stage(Unk_7ee6b0* self, u32 stat) {
    switch (stat) {
        case 1:
            return &self->field_2b4;
        case 2:
            return &self->field_2b5;
        case 3:
            return &self->field_2b6;
        case 4:
            return &self->field_2b7;
        case 5:
            return &self->field_2b8;
        case 6:
            return &self->field_2b9;
        case 7:
            return &self->field_2ba;
        default:
            return nullptr;
    }
}

static inline const s8* Unk_7ee6b0_Stage(const Unk_7ee6b0* self, u32 stat) {
    return Unk_7ee6b0_Stage(const_cast<Unk_7ee6b0*>(self), stat);
}

static inline s32 Unk_7ee6b0_GetStage(const Unk_7ee6b0* self, u32 stat) {
    const s8* stage = Unk_7ee6b0_Stage(self, stat);
    if (stage != nullptr)
        return *stage;
    return 0;
}

// 0x71007f0c00
bool Unk_7f0c00(const Unk_7ee6b0* self, u32 stat, s32 direction) {
    s8 stage = Unk_7ee6b0_GetStage(self, stat);
    if (direction > 0)
        return stage < 12;
    return stage > 0;
}

// 0x71007f0c80
s32 Unk_7f0c80(const Unk_7ee6b0* self, u32 stat) {
    return 12 - Unk_7ee6b0_GetStage(self, stat);
}

// 0x71007f0d40
s32 Unk_7f0d40(const Unk_7ee6b0* self, u32 stat) {
    return Unk_7ee6b0_GetStage(self, stat);
}

// 0x71007f0e50
u8 Unk_7f0e50(Unk_7ee6b0* self, u32 stat, u8 count) {
    s8* stage = Unk_7ee6b0_Stage(self, stat);
    if (stage == nullptr)
        return 0;
    if (*stage < 12) {
        s32 value = *stage;
        u8 added = value + count > 12 ? 12 - value : count;
        *stage = added + value;
        return added;
    }
    return 0;
}

// 0x71007f0f30
u8 Unk_7f0f30(Unk_7ee6b0* self, u32 stat, u8 count) {
    s8* stage = Unk_7ee6b0_Stage(self, stat);
    if (stage == nullptr)
        return 0;
    if (*stage > 0) {
        s32 value = *stage;
        u8 removed = value < count ? value : count;
        *stage = value - removed;
        return removed;
    }
    return 0;
}

// 0x71007f1000
void Unk_7f1000(Unk_7ee6b0* self, u32 stat, u8 value) {
    s8* stage = Unk_7ee6b0_Stage(self, stat);
    if (stage != nullptr && value <= 12)
        *stage = value;
}

// 0x71007f10b0
bool Unk_7f10b0(Unk_7ee6b0* self) {
    bool changed = false;
    if (self->field_2b4 <= 5) {
        self->field_2b4 = 6;
        changed = true;
    }
    if (self->field_2b5 <= 5) {
        self->field_2b5 = 6;
        changed = true;
    }
    if (self->field_2b6 <= 5) {
        self->field_2b6 = 6;
        changed = true;
    }
    if (self->field_2b7 <= 5) {
        self->field_2b7 = 6;
        changed = true;
    }
    if (self->field_2b8 <= 5) {
        self->field_2b8 = 6;
        changed = true;
    }
    if (self->field_2b9 <= 5) {
        self->field_2b9 = 6;
        changed = true;
    }
    if (self->field_2ba <= 5) {
        self->field_2ba = 6;
        changed = true;
    }
    return changed;
}

// 0x71007f11d0
bool Unk_7f11d0(Unk_7ee6b0* self) {
    bool changed = false;
    if (self->field_2b4 >= 7) {
        self->field_2b4 = 6;
        changed = true;
    }
    if (self->field_2b5 >= 7) {
        self->field_2b5 = 6;
        changed = true;
    }
    if (self->field_2b6 >= 7) {
        self->field_2b6 = 6;
        changed = true;
    }
    if (self->field_2b7 >= 7) {
        self->field_2b7 = 6;
        changed = true;
    }
    if (self->field_2b8 >= 7) {
        self->field_2b8 = 6;
        changed = true;
    }
    if (self->field_2b9 >= 7) {
        self->field_2b9 = 6;
        changed = true;
    }
    if (self->field_2ba >= 7) {
        self->field_2ba = 6;
        changed = true;
    }
    return changed;
}

// 0x71007f12d0
u8 Unk_7f12d0(const Unk_7ee6b0* self) {
    u8 value = self->field_33f;
    if (self->field_35c[1] & 2)
        value += 2;
    if (self->field_60.field_30[0x29] & 7)
        value += 3;
    return value < 3 ? value : 3;
}

// 0x71007f1320
bool Unk_7f1320(Unk_7ee6b0* self, s32 count) {
    u8 value = self->field_33f;
    if (count > 0) {
        if (value < 3) {
            value += count;
            self->field_33f = value < 3 ? value : 3;
            return true;
        }
        return false;
    }
    if (value == 0)
        return false;
    self->field_33f = value > -count ? value + count : 0;
    return true;
}

// 0x71007f1390
void Unk_7f1390(Unk_7ee6b0* self, u8 value) {
    if (value <= 3)
        self->field_33f = value;
}

// 0x71007f13e0
void Unk_7f13e0(Unk_7ee6b0* self, u16 amount) {
    u16 hp = self->field_60.field_14 + amount;
    if (hp > self->field_60.field_12)
        hp = self->field_60.field_12;
    self->field_60.field_14 = hp;
}

// 0x71007f1430
void Unk_7f1430(Unk_7ee6b0* self, u32 flag) {
    self->field_35c[static_cast<u8>(flag >> 3)] |= 1 << (flag & 7);
}

// 0x71007f1460
void Unk_7f1460(Unk_7ee6b0* self, u32 flag) {
    self->field_35c[static_cast<u8>(flag >> 3)] &= ~(1 << (flag & 7));
}

static inline void Unk_7ee6b0_ClearCondition(Unk_7ee6b0* self, u32 condition) {
    self->field_60.field_30[condition] = Unk_7f8780_get();
    self->field_60.field_198[condition] = 0;
}

// 0x71007f1530
void Unk_7f1530(Unk_7ee6b0* self) {
    Unk_7ee6b0_ClearCondition(self, 1);
    Unk_7ee6b0_ClearCondition(self, 2);
    Unk_7ee6b0_ClearCondition(self, 9);
    Unk_7ee6b0_ClearCondition(self, 3);
    Unk_7ee6b0_ClearCondition(self, 4);
    Unk_7ee6b0_ClearCondition(self, 5);
}

// 0x71007f1490
void Unk_7f1490(Unk_7ee6b0* self, u32 condition, const u64* value) {
    if (Unk_7f7c40(condition))
        Unk_7f1530(self);
    self->field_60.field_30[condition] = *value;
    self->field_60.field_198[condition] = 0;
}

// 0x71007f17c0
bool Unk_7f17c0(Unk_7ee6b0* self) {
    if (self->field_60.field_30[6] & 7) {
        u8 turns = Unk_7f8960(&self->field_60.field_30[6]);
        if (turns != 0) {
            self->field_60.field_198[6]++;
            if (self->field_60.field_198[6] >= turns)
                return true;
        }
    }
    return false;
}

// 0x71007f18b0
void Unk_7f18b0(Unk_7ee6b0* self, u8 pokeId) {
    if (pokeId == 0x1f)
        return;
    for (u64 i = 0; i < 0x2d; i++) {
        const u64* condition = &self->field_60.field_30[i];
        if (!Unk_7f8790_check(reinterpret_cast<const Unk_7f8790*>(condition)) &&
            Unk_7f88e0(condition) == pokeId) {
            self->field_60.field_30[i] = Unk_7f8780_get();
            if (i == 2)
                Unk_7ee6b0_ClearCondition(self, 9);
        }
    }
}

// 0x71007f19d0
void Unk_7f19d0(Unk_7ee6b0* self) {
    *reinterpret_cast<u32*>(self->field_358) = 0;
    if (self->field_344 < 9999)
        self->field_344++;
    u8 index = self->field_453 + 1;
    if (index > 2)
        index = 0;
    self->field_453 = index;
    self->field_450[index] = 0;
    self->field_342 = 1;
}

// 0x71007ef200
u16 Unk_7ef200(const Unk_7ee6b0* self) {
    return self->field_60.field_27_5 ? self->field_2a0 : self->field_60.field_10;
}

// 0x71007ef260
void Unk_7ef260(Unk_7ee6b0* self, u8 arg1, u8 arg2) {
    if (Unk_7eef50(self, 0xd) == 0) {
        self->field_270 = arg1;
        self->field_271 = arg2;
    }
}

// 0x71007ef340
void Unk_7ef340(Unk_7ee6b0* self, u8 pokeId) {
    self->field_60.field_27_6 = 1;
    self->field_60.field_1e6 = pokeId;
}

// 0x71007ef360
u8 Unk_7ef360(const Unk_7ee6b0* self) {
    return self->field_60.field_27_6 ? self->field_60.field_1e6 : self->field_60.field_1d;
}

// 0x71007ef380
void Unk_7ef380(Unk_7ee6b0* self, u8 pokeId) {
    u32 i;
    u8 count = self->field_60.field_1c5;
    for (i = 0; i < count; i++) {
        if (self->field_60.field_1c6[i] == pokeId)
            return;
    }
    if (i >= 0x1e)
        return;
    self->field_60.field_1c6[i] = pokeId;
    self->field_60.field_1c5 = count + 1;
}

// 0x71007ef4c0
bool Unk_7ef4c0(const Unk_7ee6b0* self, u32 condition) {
    return (self->field_60.field_30[condition] & 7) != 0;
}

// 0x71007ef4e0
bool Unk_7ef4e0(const Unk_7ee6b0* self) {
    if (self->field_460 == nullptr)
        return false;
    if (Unk_800290_call(self->field_460, self->field_338))
        return false;
    return Unk_800280_check(reinterpret_cast<const Unk_800280*>(self->field_460));
}

// 0x71007ef580
bool Unk_7ef580(Unk_7ee6b0* self) {
    if (Unk_767950(self->field_60.field_0, 2))
        return false;
    return Unk_7eef50(self, 0xd) != 0;
}

// 0x71007ef5d0
bool Unk_7ef5d0(Unk_7ee6b0* self, u32 arg) {
    if (arg == 1 && Unk_7eef50(self, 0x13) == 0xd5)
        return true;
    return (self->field_60.field_30[2] & 7) != 0;
}

// 0x71007ef670
u16 Unk_7ef670(const Unk_7ee6b0* self) {
    u64 condition = self->field_60.field_30[0x1a];
    u32 kind = condition & 7;
    if (kind == 1)
        return static_cast<u16>(condition >> 14);
    if (kind == 2)
        return static_cast<u16>(condition >> 14);
    return 0;
}

// 0x71007ef710
u32 Unk_7ef710(const Unk_7ee6b0* self, u32 index) {
    u64 condition = self->field_60.field_30[index];
    u32 kind = condition & 7;
    if (kind == 4)
        return (condition >> 14) & 0x3f;
    if (kind == 3)
        return (condition >> 8) & 0x3f;
    if (kind == 2)
        return condition >> 14;
    return 0;
}

// 0x71007ef750
u64 Unk_7ef750(const Unk_7ee6b0* self, u32 index) {
    return self->field_60.field_30[index];
}

// 0x71007ef760
u8 Unk_7ef760(const Unk_7ee6b0* self, u32 index) {
    return self->field_60.field_198[index];
}

// 0x71007ef770
bool Unk_7ef770(const Unk_7ee6b0* self, u32 index) {
    u64 condition = self->field_60.field_30[index];
    if (Unk_7f8790_check(reinterpret_cast<const Unk_7f8790*>(&condition)))
        return false;
    u8 turns = Unk_7f8960(&condition);
    return turns - self->field_60.field_198[index] < 2;
}

// 0x71007ef8d0
u32 Unk_7ef8d0(const Unk_7ee6b0* self) {
    u64 condition = self->field_60.field_30[0x1c];
    if (Unk_7f8790_check(reinterpret_cast<const Unk_7f8790*>(&condition)))
        return 0;
    return Unk_7f89e0(&condition);
}
