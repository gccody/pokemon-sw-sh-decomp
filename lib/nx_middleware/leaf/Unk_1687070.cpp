// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101687070
u32 Unk_1687070_get() {
    return 8;
}

struct Unk_1688620_60 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1688620_60, field_0, 0x0);

struct Unk_1688620 {
    u8 _0[0x58];
    u64 field_58;
    Unk_1688620_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_1688620, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_1688620, field_60, 0x60);
void Unk_1655290(u64);

// 0x7101688620
u32 Unk_1688620_get(Unk_1688620* self) {
    if (self->field_60->field_0 >= 2 && self->field_60->field_0 <= 4) {
        Unk_1655290(self->field_58);
        self->field_58 = 0;
        return 1;
    }
    return 5;
}

struct Unk_1688860 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1688860, field_10, 0x10);

// 0x7101688860
const u8* Unk_1688860_get(const Unk_1688860* self) {
    return &self->field_10;
}

struct Unk_1688eb0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(u64);
    u8 field_8;
    u8 field_9;
    u8 _a[0x6];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1688eb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1688eb0, field_9, 0x9);
PKMN_OFFSET_ASSERT(Unk_1688eb0, field_10, 0x10);

// 0x7101688eb0
void Unk_1688eb0_call(Unk_1688eb0* self) {
    self->vf6();
    self->field_9 = 0;
    self->vf4();
    self->vf8(self->field_10);
    self->field_10 = 0;
    self->field_8 = 0;
}

struct Unk_1689120 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    u8 _8[0x1];
    u8 field_9;
};
PKMN_OFFSET_ASSERT(Unk_1689120, field_9, 0x9);

// 0x7101689120
void Unk_1689120_call(Unk_1689120* self) {
    self->vf6();
    self->field_9 = 0;
}

struct Unk_16893c0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16893c0, field_18, 0x18);

void Unk_16966d0(u64);

// 0x71016893c0
void Unk_16893c0_call(const Unk_16893c0* self) {
    if (self->field_18 != 0) {
        Unk_16966d0(self->field_18);
    }
}

struct Unk_16894d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16894d0, field_18, 0x18);

void Unk_16968c0(u64);

// 0x71016894d0
void Unk_16894d0_call(const Unk_16894d0* self) {
    if (self->field_18 != 0) {
        Unk_16968c0(self->field_18);
    }
}

struct Unk_16895e0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16895e0, field_18, 0x18);

void Unk_1696c70(u64);

// 0x71016895e0
void Unk_16895e0_call(const Unk_16895e0* self) {
    if (self->field_18 != 0) {
        Unk_1696c70(self->field_18);
    }
}

struct Unk_1689770 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1689770, field_18, 0x18);

void Unk_1696d80(u64);

// 0x7101689770
void Unk_1689770_call(const Unk_1689770* self) {
    if (self->field_18 != 0) {
        Unk_1696d80(self->field_18);
    }
}

struct Unk_16898a0_18 {
    u8 _0[0x418];
    u32 field_418;
};
PKMN_OFFSET_ASSERT(Unk_16898a0_18, field_418, 0x418);
struct Unk_16898a0 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0xf];
    Unk_16898a0_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_16898a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_16898a0, field_18, 0x18);

// 0x71016898a0
bool Unk_16898a0_check(const Unk_16898a0* self) {
    if (self->field_8 != 0) {
        if (self->field_18 != nullptr) {
            return self->field_18->field_418 != 0;
        }
        return 0;
    }
    return 0;
}

struct Unk_16898d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16898d0, field_18, 0x18);

void Unk_1696f80(u64);

// 0x71016898d0
void Unk_16898d0_call(const Unk_16898d0* self) {
    if (self->field_18 != 0) {
        Unk_1696f80(self->field_18);
    }
}

struct Unk_1689b30_18 {
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
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
};

struct Unk_1689b30 {
    u8 _0[0x18];
    Unk_1689b30_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_1689b30, field_18, 0x18);

// 0x7101689b30
void Unk_1689b30_call(const Unk_1689b30* self) {
    if (self->field_18 != nullptr) {
        self->field_18->vf31();
    }
}

struct Unk_1689d80_18 {
    u8 _0[0x378];
    u32 field_378;
};
PKMN_OFFSET_ASSERT(Unk_1689d80_18, field_378, 0x378);
struct Unk_1689d80 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0xf];
    Unk_1689d80_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_1689d80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1689d80, field_18, 0x18);

// 0x7101689d80
u32 Unk_1689d80_get(const Unk_1689d80* self) {
    if (self->field_8 != 0) {
        if (self->field_18 != nullptr) {
            return self->field_18->field_378;
        }
        return 0;
    }
    return 0;
}

struct Unk_1689e30 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1689e30, field_18, 0x18);

void Unk_1695c30(u64);

// 0x7101689e30
void Unk_1689e30_call(const Unk_1689e30* self) {
    if (self->field_18 != 0) {
        Unk_1695c30(self->field_18);
    }
}

struct Unk_168a380 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_168a380, field_18, 0x18);

void Unk_1693c90(u64);

// 0x710168a380
void Unk_168a380_call(const Unk_168a380* self) {
    Unk_1693c90(self->field_18);
}

struct Unk_168a390 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_168a390, field_18, 0x18);

void Unk_1693c80(u64, u32);

// 0x710168a390
void Unk_168a390_call(const Unk_168a390* self, bool value) {
    Unk_1693c80(self->field_18, value);
}
