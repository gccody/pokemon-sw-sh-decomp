// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_168ab60_60 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_168ab60_60, field_0, 0x0);

struct Unk_168ab60 {
    u8 _0[0x58];
    void* field_58;
    Unk_168ab60_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_168ab60, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_168ab60, field_60, 0x60);

void Unk_1655290(void*);
void Unk_168ad20(void*);

// 0x710168ab60
u32 Unk_168ab60_call(Unk_168ab60* self) {
    if (self->field_60->field_0 == 1) {
        return 5;
    }
    Unk_168ad20(self);
    Unk_1655290(self->field_58);
    self->field_58 = nullptr;
    return 1;
}

struct Unk_168bd00 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_168bd00, field_8, 0x8);

// 0x710168bd00
void Unk_168bd00_set(Unk_168bd00* self, u64 value) {
    self->field_8 = value;
}

struct Unk_168bd10 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_168bd10, field_8, 0x8);

// 0x710168bd10
void Unk_168bd10_set(Unk_168bd10* self) {
    self->field_8 = 0;
}

struct Unk_168c030 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_168c030, field_18, 0x18);

// 0x710168c030
const u8* Unk_168c030_get(const Unk_168c030* self) {
    return &self->field_18;
}

struct Unk_1690d00 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1690d00, field_8, 0x8);

// 0x7101690d00
void Unk_1690d00_set(Unk_1690d00* self, u64 value) {
    self->field_8 = value;
}

struct Unk_1690d10 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1690d10, field_8, 0x8);

// 0x7101690d10
void Unk_1690d10_set(Unk_1690d10* self) {
    self->field_8 = 0;
}

struct Unk_16927e0 {
    u8 _0[0xb0];
    u8 field_b0;
    u8 _b1[0x1f];
    u16 field_d0;
    u8 _d2[0x6];
    u32 field_d8;
    u16 field_dc;
    u8 _de[0x12];
    u8 field_f0;
    u8 _f1[0x1f];
    u16 field_110;
    u8 _112[0x6];
    u32 field_118;
    u16 field_11c;
    u8 _11e[0x12];
    u8 field_130;
    u8 _131[0x1f];
    u16 field_150;
    u8 _152[0x6];
    u32 field_158;
    u16 field_15c;
    u8 _15e[0x12];
    u8 field_170;
    u8 _171[0x1f];
    u16 field_190;
    u8 _192[0x6];
    u32 field_198;
    u16 field_19c;
    u8 _19e[0x12];
    u8 field_1b0;
    u8 _1b1[0x1f];
    u16 field_1d0;
    u8 _1d2[0x6];
    u32 field_1d8;
    u16 field_1dc;
    u8 _1de[0x12];
    u8 field_1f0;
    u8 _1f1[0x1f];
    u16 field_210;
    u8 _212[0x6];
    u32 field_218;
    u16 field_21c;
    u8 _21e[0x12];
    u8 field_230;
    u8 _231[0x1f];
    u16 field_250;
    u8 _252[0x6];
    u32 field_258;
    u16 field_25c;
    u8 _25e[0x12];
    u8 field_270;
    u8 _271[0x1f];
    u16 field_290;
    u8 _292[0x6];
    u32 field_298;
    u16 field_29c;
};
PKMN_OFFSET_ASSERT(Unk_16927e0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_dc, 0xdc);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_118, 0x118);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_11c, 0x11c);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_150, 0x150);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_158, 0x158);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_15c, 0x15c);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_170, 0x170);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_190, 0x190);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_198, 0x198);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_19c, 0x19c);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_1d0, 0x1d0);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_1d8, 0x1d8);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_1dc, 0x1dc);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_1f0, 0x1f0);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_210, 0x210);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_21c, 0x21c);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_230, 0x230);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_250, 0x250);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_258, 0x258);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_25c, 0x25c);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_270, 0x270);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_290, 0x290);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_298, 0x298);
PKMN_OFFSET_ASSERT(Unk_16927e0, field_29c, 0x29c);

void Unk_1653900(void*);

// 0x71016927e0
void Unk_16927e0_call(Unk_16927e0* self) {
    Unk_1653900(&self->field_b0);
    self->field_d0 = 0;
    self->field_d8 = 0;
    self->field_dc = 0xff00;
    Unk_1653900(&self->field_f0);
    self->field_110 = 0;
    self->field_118 = 0;
    self->field_11c = 0xff00;
    Unk_1653900(&self->field_130);
    self->field_150 = 0;
    self->field_158 = 0;
    self->field_15c = 0xff00;
    Unk_1653900(&self->field_170);
    self->field_190 = 0;
    self->field_198 = 0;
    self->field_19c = 0xff00;
    Unk_1653900(&self->field_1b0);
    self->field_1d0 = 0;
    self->field_1d8 = 0;
    self->field_1dc = 0xff00;
    Unk_1653900(&self->field_1f0);
    self->field_210 = 0;
    self->field_218 = 0;
    self->field_21c = 0xff00;
    Unk_1653900(&self->field_230);
    self->field_250 = 0;
    self->field_258 = 0;
    self->field_25c = 0xff00;
    Unk_1653900(&self->field_270);
    self->field_290 = 0;
    self->field_298 = 0;
    self->field_29c = 0xff00;
}

struct Unk_16928a0 {
    u8 _0[0x46c];
    u32 field_46c;
};
PKMN_OFFSET_ASSERT(Unk_16928a0, field_46c, 0x46c);

// 0x71016928a0
void Unk_16928a0_set(Unk_16928a0* self, u32 value) {
    self->field_46c = value;
}

struct Unk_16928b0 {
    u8 _0[0x474];
    u32 field_474;
};
PKMN_OFFSET_ASSERT(Unk_16928b0, field_474, 0x474);

// 0x71016928b0
void Unk_16928b0_set(Unk_16928b0* self, u32 value) {
    self->field_474 = value;
}

struct Unk_1693bb0 {
    u8 _0[0x520];
    u64 field_520;
    u64 field_528;
};
PKMN_OFFSET_ASSERT(Unk_1693bb0, field_520, 0x520);
PKMN_OFFSET_ASSERT(Unk_1693bb0, field_528, 0x528);

// 0x7101693bb0
void Unk_1693bb0_set(Unk_1693bb0* self, u64 value, u64 arg2) {
    self->field_520 = value;
    self->field_528 = arg2;
}

struct Unk_1694e90 {
    u8 _0[0x4e8];
    u32 field_4e8;
};
PKMN_OFFSET_ASSERT(Unk_1694e90, field_4e8, 0x4e8);

// 0x7101694e90
bool Unk_1694e90_check(const Unk_1694e90* self) {
    return self->field_4e8 == 1;
}

struct Unk_1695d90_408 {
    u8 _0[0x5c];
    u32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_1695d90_408, field_5c, 0x5c);

struct Unk_1695d90 {
    u8 _0[0x408];
    Unk_1695d90_408* field_408;
};
PKMN_OFFSET_ASSERT(Unk_1695d90, field_408, 0x408);

// 0x7101695d90
bool Unk_1695d90_check(const Unk_1695d90* self) {
    return self->field_408->field_5c != 0;
}

void Unk_1695280(void*, u32);

// 0x7101696700
void Unk_1696700_call(void* self) {
    Unk_1695280(self, 1);
}

void Unk_1695280(void*, u32);

// 0x71016968f0
void Unk_16968f0_call(void* self) {
    Unk_1695280(self, 2);
}

void Unk_1695280(void*, u32);

// 0x7101696ca0
void Unk_1696ca0_call(void* self) {
    Unk_1695280(self, 4);
}

void Unk_1695310(void*, u32);

// 0x7101696cb0
void Unk_1696cb0_call(void* self) {
    Unk_1695310(self, 4);
}

void Unk_1695280(void*, u32);

// 0x7101696db0
void Unk_1696db0_call(void* self) {
    Unk_1695280(self, 5);
}

void Unk_1695280(void*, u32);

// 0x7101696fb0
void Unk_1696fb0_call(void* self) {
    Unk_1695280(self, 3);
}

void Unk_1695310(void*, u32);

// 0x7101696fc0
void Unk_1696fc0_call(void* self) {
    Unk_1695310(self, 3);
}

struct Unk_1697210 {
    u8 _0[0x4d0];
    u32 field_4d0;
};
PKMN_OFFSET_ASSERT(Unk_1697210, field_4d0, 0x4d0);

// 0x7101697210
bool Unk_1697210_check(const Unk_1697210* self) {
    return self->field_4d0 != 0;
}

struct Unk_1697830 {
    u64 field_0;
    u32 field_8;
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1697830, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1697830, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1697830, field_c, 0xc);

// 0x7101697830
void Unk_1697830_set(Unk_1697830* self, u64 value, u32 arg2) {
    self->field_0 = value;
    self->field_8 = arg2;
    self->field_c = 0;
}

struct Unk_16980a0_60 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_16980a0_60, field_0, 0x0);

struct Unk_16980a0 {
    u8 _0[0x58];
    void* field_58;
    Unk_16980a0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_16980a0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_16980a0, field_60, 0x60);
void Unk_1655290(void*);

// 0x71016980a0
u32 Unk_16980a0_get(Unk_16980a0* self) {
    if (self->field_60->field_0 >= 2 && self->field_60->field_0 <= 4) {
        Unk_1655290(self->field_58);
        self->field_58 = nullptr;
        return 1;
    }
    return 5;
}

struct Unk_1698540_60 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1698540_60, field_0, 0x0);

struct Unk_1698540 {
    u8 _0[0x58];
    void* field_58;
    Unk_1698540_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_1698540, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_1698540, field_60, 0x60);

void Unk_1655290(void*);

// 0x7101698540
u32 Unk_1698540_call(Unk_1698540* self) {
    if (self->field_60->field_0 == 1) {
        return 5;
    }
    Unk_1655290(self->field_58);
    self->field_58 = nullptr;
    return 1;
}

struct Unk_1698dc0_60 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1698dc0_60, field_0, 0x0);

struct Unk_1698dc0 {
    u8 _0[0x58];
    void* field_58;
    Unk_1698dc0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_1698dc0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_1698dc0, field_60, 0x60);

void Unk_1655290(void*);

// 0x7101698dc0
u32 Unk_1698dc0_call(Unk_1698dc0* self) {
    if (self->field_60->field_0 == 1) {
        return 5;
    }
    Unk_1655290(self->field_58);
    self->field_58 = nullptr;
    return 1;
}

struct Unk_169a6f0 {
    u8 _0[0x58];
    u64 field_58;
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_169a6f0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_169a6f0, field_60, 0x60);

// 0x710169a6f0
void Unk_169a6f0_set(Unk_169a6f0* self) {
    self->field_58 = 0;
    self->field_60 = 0;
}

struct Unk_169ac60_arg1 {
    u8 _0[0x8];
    u8 field_8;
    u8 field_9;
    u8 field_a;
    u8 field_b;
};
PKMN_OFFSET_ASSERT(Unk_169ac60_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_169ac60_arg1, field_9, 0x9);
PKMN_OFFSET_ASSERT(Unk_169ac60_arg1, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_169ac60_arg1, field_b, 0xb);

struct Unk_169ac60 {
    u8 _0[0x8];
    u8 field_8;
    u8 field_9;
    u8 field_a;
    u8 field_b;
};
PKMN_OFFSET_ASSERT(Unk_169ac60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_169ac60, field_9, 0x9);
PKMN_OFFSET_ASSERT(Unk_169ac60, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_169ac60, field_b, 0xb);

// 0x710169ac60
void Unk_169ac60_set(Unk_169ac60* self, const Unk_169ac60_arg1* value) {
    self->field_8 = value->field_8;
    self->field_9 = value->field_9;
    self->field_a = value->field_a;
    self->field_b = value->field_b;
}

struct Unk_169ad10 {
    u8 _0[0x9];
    u8 field_9;
};
PKMN_OFFSET_ASSERT(Unk_169ad10, field_9, 0x9);

// 0x710169ad10
void Unk_169ad10_set(Unk_169ad10* self, u8 value) {
    self->field_9 = value;
}

struct Unk_169ad40 {
    u8 _0[0xb];
    u8 field_b;
};
PKMN_OFFSET_ASSERT(Unk_169ad40, field_b, 0xb);

// 0x710169ad40
void Unk_169ad40_set(Unk_169ad40* self, u8 value) {
    self->field_b = value;
}

void Unk_169c9f0(void*, void*);

// 0x710169d1d0
void Unk_169d1d0_call(void* self) {
    Unk_169c9f0(self, self);
}

// 0x710169df30
void Unk_169df30_update(void* /*unused*/, void* /*unused*/) {
}

struct Unk_16a1ed0 {
    u8 _0[0x98];
    u32 field_98;
};
PKMN_OFFSET_ASSERT(Unk_16a1ed0, field_98, 0x98);

// 0x71016a1ed0
u32 Unk_16a1ed0_get(const Unk_16a1ed0* self) {
    return self->field_98;
}

struct Unk_16a2460 {
    u8 _0[0x58];
    u64 field_58;
    u8 _60[0x8];
    u64 field_68;
    u8 _70[0xc];
    u8 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_16a2460, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_16a2460, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_16a2460, field_7c, 0x7c);

// 0x71016a2460
void Unk_16a2460_set(Unk_16a2460* self) {
    self->field_68 = 0;
    self->field_7c = 0;
    self->field_58 = 0;
}

void Unk_16a4440(void*);

// 0x71016a4430
void Unk_16a4430_call(void* self) {
    Unk_16a4440(self);
}

struct Unk_16a51e0 {
    u8 _0[0x80];
    void* field_80;
};
PKMN_OFFSET_ASSERT(Unk_16a51e0, field_80, 0x80);

void Unk_16ab5c0(void*);

// 0x71016a51e0
void Unk_16a51e0_call(const Unk_16a51e0* self) {
    Unk_16ab5c0(self->field_80);
}

struct Unk_16a56c0 {
    u8 _0[0x378];
    u64 field_378;
};
PKMN_OFFSET_ASSERT(Unk_16a56c0, field_378, 0x378);

// 0x71016a56c0
u64 Unk_16a56c0_get(const Unk_16a56c0* self) {
    return self->field_378;
}

struct Unk_16a63d0 {
    u8 _0[0xe8];
    u32 field_e8;
    u8 _ec[0x2c];
    u32 field_118;
};
PKMN_OFFSET_ASSERT(Unk_16a63d0, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_16a63d0, field_118, 0x118);

// 0x71016a63d0
bool Unk_16a63d0_check(const Unk_16a63d0* self) {
    if (self->field_118 != 1) {
        return false;
    }
    return self->field_e8 >= 2 && self->field_e8 <= 4;
}

void Unk_16a7d00(void*, u64, u32);

// 0x71016a6900
void Unk_16a6900_call(void* self, u64 value) {
    Unk_16a7d00(self, value, 1);
}

struct Unk_16a69c0 {
    u8 _0[0xe8];
    u32 field_e8;
    u8 _ec[0x2c];
    u32 field_118;
};
PKMN_OFFSET_ASSERT(Unk_16a69c0, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_16a69c0, field_118, 0x118);

// 0x71016a69c0
bool Unk_16a69c0_check(const Unk_16a69c0* self) {
    if (self->field_118 != 2) {
        return false;
    }
    return self->field_e8 >= 2 && self->field_e8 <= 4;
}

struct Unk_16a6bd0 {
    u8 _0[0xbe];
    u8 field_be;
};
PKMN_OFFSET_ASSERT(Unk_16a6bd0, field_be, 0xbe);

// 0x71016a6bd0
u8 Unk_16a6bd0_get(const Unk_16a6bd0* self) {
    return self->field_be;
}

struct Unk_16a6c90 {
    u8 _0[0xe8];
    u32 field_e8;
    u8 _ec[0x2c];
    u32 field_118;
};
PKMN_OFFSET_ASSERT(Unk_16a6c90, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_16a6c90, field_118, 0x118);

// 0x71016a6c90
bool Unk_16a6c90_check(const Unk_16a6c90* self) {
    if (self->field_118 != 3) {
        return false;
    }
    return self->field_e8 >= 2 && self->field_e8 <= 4;
}

struct Unk_16a73c0 {
    u8 _0[0xe8];
    u32 field_e8;
    u8 _ec[0x2c];
    u32 field_118;
};
PKMN_OFFSET_ASSERT(Unk_16a73c0, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_16a73c0, field_118, 0x118);

// 0x71016a73c0
bool Unk_16a73c0_check(const Unk_16a73c0* self) {
    if (self->field_118 != 4) {
        return false;
    }
    return self->field_e8 >= 2 && self->field_e8 <= 4;
}

void Unk_16a7490(void*, u32);

// 0x71016a7480
void Unk_16a7480_call(void* self) {
    Unk_16a7490(self, 4);
}

struct Unk_16a7700 {
    u8 _0[0xe8];
    u32 field_e8;
    u8 _ec[0x2c];
    u32 field_118;
};
PKMN_OFFSET_ASSERT(Unk_16a7700, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_16a7700, field_118, 0x118);

// 0x71016a7700
bool Unk_16a7700_check(const Unk_16a7700* self) {
    if (self->field_118 != 5) {
        return false;
    }
    return self->field_e8 >= 2 && self->field_e8 <= 4;
}

struct Unk_16a7890 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_16a7890, field_a0, 0xa0);

// 0x71016a7890
u64 Unk_16a7890_get(const Unk_16a7890* self) {
    return self->field_a0;
}

struct Unk_16a7a50 {
    u8 _0[0xab];
    u8 field_ab;
};
PKMN_OFFSET_ASSERT(Unk_16a7a50, field_ab, 0xab);

// 0x71016a7a50
u8 Unk_16a7a50_get(const Unk_16a7a50* self) {
    return self->field_ab;
}

struct Unk_16a7b10 {
    u8 _0[0xab];
    u8 field_ab;
    u8 field_ac;
};
PKMN_OFFSET_ASSERT(Unk_16a7b10, field_ab, 0xab);
PKMN_OFFSET_ASSERT(Unk_16a7b10, field_ac, 0xac);

// 0x71016a7b10
bool Unk_16a7b10_check(const Unk_16a7b10* self) {
    if (self->field_ac > 0x1f) {
        return 0;
    }
    return self->field_ac == self->field_ab;
}

struct Unk_16a7b40 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_16a7b40, field_60, 0x60);

// 0x71016a7b40
void Unk_16a7b40_set(Unk_16a7b40* self, u64 value) {
    self->field_60 = value;
}

struct Unk_16a7b50 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_16a7b50, field_60, 0x60);

// 0x71016a7b50
void Unk_16a7b50_set(Unk_16a7b50* self) {
    self->field_60 = 0;
}

struct Unk_16a7be0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_16a7be0, field_68, 0x68);

// 0x71016a7be0
void Unk_16a7be0_set(Unk_16a7be0* self) {
    self->field_68 = 0;
}

struct Unk_16a7bf0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_16a7bf0, field_70, 0x70);

// 0x71016a7bf0
void Unk_16a7bf0_set(Unk_16a7bf0* self, u64 value) {
    self->field_70 = value;
}

struct Unk_16a7c00 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_16a7c00, field_70, 0x70);

// 0x71016a7c00
void Unk_16a7c00_set(Unk_16a7c00* self) {
    self->field_70 = 0;
}

struct Unk_16a7c40 {
    u8 _0[0xb8];
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_16a7c40, field_b8, 0xb8);

// 0x71016a7c40
u32 Unk_16a7c40_get(const Unk_16a7c40* self) {
    return self->field_b8;
}

struct Unk_16a7c50 {
    u8 _0[0xe2];
    bool field_e2;
};
PKMN_OFFSET_ASSERT(Unk_16a7c50, field_e2, 0xe2);

// 0x71016a7c50
void Unk_16a7c50_set(Unk_16a7c50* self, bool value) {
    self->field_e2 = value;
}

struct Unk_16a7c60 {
    u8 _0[0xe2];
    u8 field_e2;
};
PKMN_OFFSET_ASSERT(Unk_16a7c60, field_e2, 0xe2);

// 0x71016a7c60
u8 Unk_16a7c60_get(const Unk_16a7c60* self) {
    return self->field_e2;
}

struct Unk_16a7cb0 {
    u8 _0[0x129];
    bool field_129;
};
PKMN_OFFSET_ASSERT(Unk_16a7cb0, field_129, 0x129);

// 0x71016a7cb0
void Unk_16a7cb0_set(Unk_16a7cb0* self, bool value) {
    self->field_129 = value;
}

struct Unk_16a7cc0 {
    u8 _0[0x128];
    bool field_128;
};
PKMN_OFFSET_ASSERT(Unk_16a7cc0, field_128, 0x128);

// 0x71016a7cc0
void Unk_16a7cc0_set(Unk_16a7cc0* self, bool value) {
    self->field_128 = value;
}

// 0x71016a7e70
void Unk_16a7e70_update(u64 /*unused*/) {
}

struct Unk_16a7e80 {
    u8 _0[0x120];
    u64 field_120;
};
PKMN_OFFSET_ASSERT(Unk_16a7e80, field_120, 0x120);

// 0x71016a7e80
void Unk_16a7e80_set(Unk_16a7e80* self, u64 value) {
    self->field_120 = value;
}

struct Unk_16a7e90 {
    u8 _0[0x120];
    u64 field_120;
};
PKMN_OFFSET_ASSERT(Unk_16a7e90, field_120, 0x120);

// 0x71016a7e90
void Unk_16a7e90_set(Unk_16a7e90* self) {
    self->field_120 = 0;
}

struct Unk_16a7ea0 {
    u8 _0[0xac];
    u8 field_ac;
};
PKMN_OFFSET_ASSERT(Unk_16a7ea0, field_ac, 0xac);

// 0x71016a7ea0
u8 Unk_16a7ea0_get(const Unk_16a7ea0* self) {
    return self->field_ac;
}

struct Unk_16a7eb0 {
    u8 _0[0xc8];
    u32 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_16a7eb0, field_c8, 0xc8);

// 0x71016a7eb0
u32 Unk_16a7eb0_get(const Unk_16a7eb0* self) {
    return self->field_c8;
}

struct Unk_16a7ec0 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_16a7ec0, field_80, 0x80);

// 0x71016a7ec0
u64 Unk_16a7ec0_get(const Unk_16a7ec0* self) {
    return self->field_80;
}

struct Unk_16a8020 {
    u8 _0[0xbd];
    u8 field_bd;
};
PKMN_OFFSET_ASSERT(Unk_16a8020, field_bd, 0xbd);

// 0x71016a8020
u8 Unk_16a8020_get(const Unk_16a8020* self) {
    return self->field_bd;
}

struct Unk_16a8080_38 {
    u8 _0[0x84];
    u8 field_84;
};
PKMN_OFFSET_ASSERT(Unk_16a8080_38, field_84, 0x84);

struct Unk_16a8080 {
    u8 _0[0x38];
    Unk_16a8080_38* field_38;
};
PKMN_OFFSET_ASSERT(Unk_16a8080, field_38, 0x38);

// 0x71016a8080
bool Unk_16a8080_check(const Unk_16a8080* self) {
    if (self->field_38 == nullptr) {
        return false;
    }
    return self->field_38->field_84 != 0;
}

struct Unk_16a80a0 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_16a80a0, field_50, 0x50);

void Unk_16a3220(void*, u8);

// 0x71016a80a0
void Unk_16a80a0_call(const Unk_16a80a0* self, u8 value) {
    if (self->field_50 != nullptr) {
        Unk_16a3220(self->field_50, value);
    }
}

struct Unk_16a80b0 {
    u8 _0[0xb0];
    u32 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_16a80b0, field_b0, 0xb0);

// 0x71016a80b0
u32 Unk_16a80b0_get(const Unk_16a80b0* self) {
    return self->field_b0;
}

struct Unk_16a80c0 {
    u8 _0[0x131];
    bool field_131;
};
PKMN_OFFSET_ASSERT(Unk_16a80c0, field_131, 0x131);

// 0x71016a80c0
void Unk_16a80c0_set(Unk_16a80c0* self, bool value) {
    self->field_131 = value;
}

struct Unk_16a80d0 {
    u8 _0[0x12a];
    u8 field_12a;
};
PKMN_OFFSET_ASSERT(Unk_16a80d0, field_12a, 0x12a);

// 0x71016a80d0
u8 Unk_16a80d0_get(const Unk_16a80d0* self) {
    return self->field_12a;
}

struct Unk_16a80e0 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_16a80e0, field_c0, 0xc0);

// 0x71016a80e0
u8 Unk_16a80e0_get(const Unk_16a80e0* self) {
    return self->field_c0;
}

struct Unk_16a82e0 {
    u8 _0[0x12b];
    u8 field_12b;
};
PKMN_OFFSET_ASSERT(Unk_16a82e0, field_12b, 0x12b);

// 0x71016a82e0
u8 Unk_16a82e0_get(const Unk_16a82e0* self) {
    return self->field_12b;
}

struct Unk_16a82f0 {
    u8 _0[0x132];
    bool field_132;
};
PKMN_OFFSET_ASSERT(Unk_16a82f0, field_132, 0x132);

// 0x71016a82f0
void Unk_16a82f0_set(Unk_16a82f0* self, bool value) {
    self->field_132 = value;
}

struct Unk_16a8300 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_16a8300, field_38, 0x38);

// 0x71016a8300
u64 Unk_16a8300_get(const Unk_16a8300* self) {
    return self->field_38;
}

struct Unk_16a8310 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_16a8310, field_50, 0x50);

// 0x71016a8310
u64 Unk_16a8310_get(const Unk_16a8310* self) {
    return self->field_50;
}

struct Unk_16a8320 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_16a8320, field_30, 0x30);

// 0x71016a8320
u64 Unk_16a8320_get(const Unk_16a8320* self) {
    return self->field_30;
}

struct Unk_16a8330 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_16a8330, field_20, 0x20);

// 0x71016a8330
u64 Unk_16a8330_get(const Unk_16a8330* self) {
    return self->field_20;
}

struct Unk_16a8340 {
    u8 _0[0xbc];
    u8 field_bc;
};
PKMN_OFFSET_ASSERT(Unk_16a8340, field_bc, 0xbc);

// 0x71016a8340
u8 Unk_16a8340_get(const Unk_16a8340* self) {
    return self->field_bc;
}

struct Unk_16a8350_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_16a8350_arg1, field_0, 0x0);

struct Unk_16a8350 {
    u8 _0[0xd8];
    u64 field_d8;
    u8 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_16a8350, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_16a8350, field_e0, 0xe0);

// 0x71016a8350
void Unk_16a8350_set(Unk_16a8350* self, const Unk_16a8350_arg1* value) {
    self->field_d8 = value->field_0;
    self->field_e0 = 1;
}

struct Unk_16a8370 {
    u8 _0[0x360];
    u64 field_360;
};
PKMN_OFFSET_ASSERT(Unk_16a8370, field_360, 0x360);

// 0x71016a8370
u64 Unk_16a8370_get(const Unk_16a8370* self) {
    return self->field_360;
}

struct Unk_16a8380 {
    u8 _0[0x368];
    u64 field_368;
};
PKMN_OFFSET_ASSERT(Unk_16a8380, field_368, 0x368);

// 0x71016a8380
u64 Unk_16a8380_get(const Unk_16a8380* self) {
    return self->field_368;
}

struct Unk_16a8390 {
    u8 _0[0x370];
    u64 field_370;
};
PKMN_OFFSET_ASSERT(Unk_16a8390, field_370, 0x370);

// 0x71016a8390
u64 Unk_16a8390_get(const Unk_16a8390* self) {
    return self->field_370;
}

struct Unk_16a83a0 {
    u8 _0[0x35a];
    u16 field_35a;
};
PKMN_OFFSET_ASSERT(Unk_16a83a0, field_35a, 0x35a);

// 0x71016a83a0
void Unk_16a83a0_set(Unk_16a83a0* self, u16 value) {
    self->field_35a = value;
}

struct Unk_16a83b0 {
    u8 _0[0x35c];
    u16 field_35c;
};
PKMN_OFFSET_ASSERT(Unk_16a83b0, field_35c, 0x35c);

// 0x71016a83b0
void Unk_16a83b0_set(Unk_16a83b0* self, u16 value) {
    self->field_35c = value;
}

struct Unk_16a83c0 {
    u8 _0[0x35a];
    u16 field_35a;
};
PKMN_OFFSET_ASSERT(Unk_16a83c0, field_35a, 0x35a);

// 0x71016a83c0
u16 Unk_16a83c0_get(const Unk_16a83c0* self) {
    return self->field_35a;
}

struct Unk_16a83d0 {
    u8 _0[0x35c];
    u16 field_35c;
};
PKMN_OFFSET_ASSERT(Unk_16a83d0, field_35c, 0x35c);

// 0x71016a83d0
u16 Unk_16a83d0_get(const Unk_16a83d0* self) {
    return self->field_35c;
}

extern u8 Unk_27fb2eb __attribute__((visibility("hidden")));

// 0x71016a83e0
u8 Unk_16a83e0_get() {
    return Unk_27fb2eb;
}

struct Unk_16afc70 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_16afc70, field_48, 0x48);

// 0x71016afc70
void Unk_16afc70_set(Unk_16afc70* self, u64 value) {
    self->field_48 = value;
}

struct Unk_16afc80 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_16afc80, field_50, 0x50);

// 0x71016afc80
void Unk_16afc80_set(Unk_16afc80* self, u64 value) {
    self->field_50 = value;
}

struct Unk_16afc90 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_16afc90, field_60, 0x60);

// 0x71016afc90
void Unk_16afc90_set(Unk_16afc90* self, u64 value) {
    self->field_60 = value;
}

// 0x71016b1780
void Unk_16b1780_update() {
}

struct Unk_16b5780 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_16b5780, field_64, 0x64);

// 0x71016b5780
void Unk_16b5780_set(Unk_16b5780* self) {
    self->field_64 = 0;
}

struct Unk_16b6d10 {
    u8 _0[0xc0];
    u16 field_c0;
    bool field_c2;
};
PKMN_OFFSET_ASSERT(Unk_16b6d10, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_16b6d10, field_c2, 0xc2);

// 0x71016b6d10
void Unk_16b6d10_set(Unk_16b6d10* self, bool value) {
    self->field_c0 = 0x100;
    self->field_c2 = value;
}

struct Unk_16b6db0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

// 0x71016b6db0
void Unk_16b6db0_call(Unk_16b6db0* self) {
    self->vf13();
    self->vf12();
}

struct Unk_16b7b10 {
    u8 _0[0x78];
    u64 field_78;
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_16b7b10, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_16b7b10, field_80, 0x80);

// 0x71016b7b10
void Unk_16b7b10_set(Unk_16b7b10* self) {
    self->field_78 = 0;
    self->field_80 = 0xffff00;
}

struct Unk_16b8770 {
    u8 _0[0xb8];
    u8 field_b8;
    u8 _b9[0x2];
    u8 field_bb;
};
PKMN_OFFSET_ASSERT(Unk_16b8770, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_16b8770, field_bb, 0xbb);

// 0x71016b8770
void Unk_16b8770_set(Unk_16b8770* self, u8 value) {
    if (self->field_b8 == (value)) {
        self->field_bb = 1;
    }
}

struct Unk_16bcc90 {
    u8 _0[0xf8];
    u32 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_16bcc90, field_f8, 0xf8);

// 0x71016bcc90
void Unk_16bcc90_set(Unk_16bcc90* self) {
    self->field_f8 = 0;
}

// 0x71016bd540
void Unk_16bd540_update(u64 /*unused*/) {
}

// 0x71016bf6e0
void Unk_16bf6e0_update(u64 /*unused*/, void* /*unused*/) {
}

// 0x71016c0410
void Unk_16c0410_update(u64 /*unused*/) {
}
