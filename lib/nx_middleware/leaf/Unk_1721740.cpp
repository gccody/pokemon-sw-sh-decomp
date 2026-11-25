// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1721740 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_1721740, field_48, 0x48);

// 0x7101721740
void Unk_1721740_set(Unk_1721740* self) {
    self->field_48 = 0;
}

// 0x7101721750
void Unk_1721750_update(u64 /*unused*/) {
}

extern u8 Unk_27fc0a0 __attribute__((visibility("hidden")));

// 0x7101722410
u8 Unk_1722410_get() {
    return Unk_27fc0a0;
}

extern u8 Unk_27fc0a1 __attribute__((visibility("hidden")));

// 0x7101722580
u8 Unk_1722580_get() {
    return Unk_27fc0a1;
}

struct Unk_1723350 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1723350, field_8, 0x8);

// 0x7101723350
u16 Unk_1723350_get(const Unk_1723350* self) {
    return self->field_8;
}

struct Unk_1723360 {
    u8 _0[0xa];
    u8 field_a;
};
PKMN_OFFSET_ASSERT(Unk_1723360, field_a, 0xa);

// 0x7101723360
u8 Unk_1723360_get(const Unk_1723360* self) {
    return self->field_a;
}

struct Unk_1723380 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1723380, field_c, 0xc);

// 0x7101723380
u16 Unk_1723380_get(const Unk_1723380* self) {
    return self->field_c;
}

struct Unk_1723390 {
    u8 _0[0xe];
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_1723390, field_e, 0xe);

// 0x7101723390
u8 Unk_1723390_get(const Unk_1723390* self) {
    return self->field_e;
}

struct Unk_17233a0_arg1 {
    u8 _0[0x8];
    u16 field_8;
    u8 field_a;
    u8 _b[0x1];
    u16 field_c;
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_17233a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17233a0_arg1, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_17233a0_arg1, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_17233a0_arg1, field_e, 0xe);

struct Unk_17233a0 {
    u8 _0[0x8];
    u16 field_8;
    u8 field_a;
    u8 _b[0x1];
    u16 field_c;
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_17233a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17233a0, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_17233a0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_17233a0, field_e, 0xe);

// 0x71017233a0
void Unk_17233a0_set(Unk_17233a0* self, const Unk_17233a0_arg1* value) {
    self->field_8 = value->field_8;
    self->field_a = value->field_a;
    self->field_c = value->field_c;
    self->field_e = value->field_e;
}

struct Unk_17255c0 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_17255c0, field_90, 0x90);

// 0x71017255c0
bool Unk_17255c0_check(const Unk_17255c0* self) {
    return self->field_90 >= 9 && self->field_90 <= 0xa;
}

struct Unk_1726360 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_1726360, field_90, 0x90);

// 0x7101726360
bool Unk_1726360_check(const Unk_1726360* self) {
    return self->field_90 >= 6 && self->field_90 <= 8;
}

struct Unk_172adc0_68 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Unk_172adc0 {
    u8 _0[0x68];
    Unk_172adc0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_172adc0, field_68, 0x68);

// 0x710172adc0
void Unk_172adc0_call(const Unk_172adc0* self) {
    if (self->field_68 != nullptr) {
        self->field_68->vf3();
    }
}

struct Unk_172ade0 {
    u8 _0[0x110];
    u32 field_110;
};
PKMN_OFFSET_ASSERT(Unk_172ade0, field_110, 0x110);

// 0x710172ade0
bool Unk_172ade0_check(const Unk_172ade0* self) {
    return self->field_110 == 1;
}

struct Unk_172aef0 {
    u8 _0[0x110];
    u32 field_110;
    u8 _114[0x2c];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_172aef0, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_172aef0, field_140, 0x140);

// 0x710172aef0
bool Unk_172aef0_check(const Unk_172aef0* self) {
    if (self->field_140 != 1) {
        return false;
    }
    return self->field_110 >= 2 && self->field_110 <= 4;
}

void Unk_172afc0(void*, u32);

// 0x710172afb0
void Unk_172afb0_call(void* self) {
    Unk_172afc0(self, 1);
}

struct Unk_172b1c0 {
    u8 _0[0x110];
    u32 field_110;
    u8 _114[0x2c];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_172b1c0, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_172b1c0, field_140, 0x140);

// 0x710172b1c0
bool Unk_172b1c0_check(const Unk_172b1c0* self) {
    if (self->field_140 != 2) {
        return false;
    }
    return self->field_110 >= 2 && self->field_110 <= 4;
}

struct Unk_172b3a0 {
    u8 _0[0x110];
    u32 field_110;
    u8 _114[0x2c];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_172b3a0, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_172b3a0, field_140, 0x140);

// 0x710172b3a0
bool Unk_172b3a0_check(const Unk_172b3a0* self) {
    if (self->field_140 != 3) {
        return false;
    }
    return self->field_110 >= 2 && self->field_110 <= 4;
}

struct Unk_172b550 {
    u8 _0[0x110];
    u32 field_110;
    u8 _114[0x2c];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_172b550, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_172b550, field_140, 0x140);

// 0x710172b550
bool Unk_172b550_check(const Unk_172b550* self) {
    if (self->field_140 != 4) {
        return false;
    }
    return self->field_110 >= 2 && self->field_110 <= 4;
}

void Unk_172afc0(void*, u32);

// 0x710172b610
void Unk_172b610_call(void* self) {
    Unk_172afc0(self, 4);
}

struct Unk_172b780 {
    u8 _0[0x110];
    u32 field_110;
    u8 _114[0x2c];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_172b780, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_172b780, field_140, 0x140);

// 0x710172b780
bool Unk_172b780_check(const Unk_172b780* self) {
    if (self->field_140 != 5) {
        return false;
    }
    return self->field_110 >= 2 && self->field_110 <= 4;
}

struct Unk_172bae0 {
    u8 _0[0x110];
    u32 field_110;
    u8 _114[0x2c];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_172bae0, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_172bae0, field_140, 0x140);

// 0x710172bae0
bool Unk_172bae0_check(const Unk_172bae0* self) {
    if (self->field_140 != 7) {
        return false;
    }
    return self->field_110 >= 2 && self->field_110 <= 4;
}

struct Unk_172bcc0 {
    u8 _0[0x110];
    u32 field_110;
    u8 _114[0x2c];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_172bcc0, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_172bcc0, field_140, 0x140);

// 0x710172bcc0
bool Unk_172bcc0_check(const Unk_172bcc0* self) {
    if (self->field_140 != 0x11) {
        return false;
    }
    return self->field_110 >= 2 && self->field_110 <= 4;
}

struct Unk_172be60 {
    u8 _0[0x1a8];
    u32 field_1a8;
};
PKMN_OFFSET_ASSERT(Unk_172be60, field_1a8, 0x1a8);

// 0x710172be60
u32 Unk_172be60_get(const Unk_172be60* self) {
    return self->field_1a8;
}

struct Unk_172be70 {
    u8 _0[0x1a8];
    u32 field_1a8;
};
PKMN_OFFSET_ASSERT(Unk_172be70, field_1a8, 0x1a8);

// 0x710172be70
u32 Unk_172be70_get(const Unk_172be70* self) {
    return self->field_1a8;
}

struct Unk_172be80 {
    u8 _0[0x208];
    u16 field_208;
};
PKMN_OFFSET_ASSERT(Unk_172be80, field_208, 0x208);

// 0x710172be80
u16 Unk_172be80_get(const Unk_172be80* self) {
    return self->field_208;
}

struct Unk_172be90_8 {
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
};

struct Unk_172be90 {
    u8 _0[0x8];
    Unk_172be90_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_172be90, field_8, 0x8);

// 0x710172be90
void Unk_172be90_call(const Unk_172be90* self) {
    if (self->field_8 != nullptr) {
        self->field_8->vf11();
    }
}

struct Unk_172c050_8 {
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
};

struct Unk_172c050 {
    u8 _0[0x8];
    Unk_172c050_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_172c050, field_8, 0x8);

// 0x710172c050
void Unk_172c050_call(const Unk_172c050* self) {
    if (self->field_8 != nullptr) {
        self->field_8->vf10();
    }
}

struct Unk_172c1b0 {
    u8 _0[0x70];
    u64 field_70;
    u8 _78[0x88];
    u64 field_100;
};
PKMN_OFFSET_ASSERT(Unk_172c1b0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_172c1b0, field_100, 0x100);

// 0x710172c1b0
u64 Unk_172c1b0_get(const Unk_172c1b0* self) {
    if (self->field_70 == 0) {
        return 0;
    }
    return self->field_100;
}

struct Unk_172c3d0 {
    u8 _0[0x15d];
    u8 field_15d;
};
PKMN_OFFSET_ASSERT(Unk_172c3d0, field_15d, 0x15d);

// 0x710172c3d0
u8 Unk_172c3d0_get(const Unk_172c3d0* self) {
    return self->field_15d;
}

struct Unk_172c5a0 {
    u8 _0[0xa0];
    u64 field_a0;
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_172c5a0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_172c5a0, field_a8, 0xa8);

// 0x710172c5a0
void Unk_172c5a0_set(Unk_172c5a0* self) {
    self->field_a0 = 0;
    self->field_a8 = 0;
}

struct Unk_172ca20 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_172ca20, field_b0, 0xb0);

// 0x710172ca20
void Unk_172ca20_set(Unk_172ca20* self, u64 value) {
    self->field_b0 = value;
}

struct Unk_172ca30 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_172ca30, field_b0, 0xb0);

// 0x710172ca30
void Unk_172ca30_set(Unk_172ca30* self) {
    self->field_b0 = 0;
}

struct Unk_172ca60 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_172ca60, field_148, 0x148);

// 0x710172ca60
u64 Unk_172ca60_get(const Unk_172ca60* self) {
    return self->field_148;
}

struct Unk_172d080 {
    u8 _0[0x1e4];
    bool field_1e4;
};
PKMN_OFFSET_ASSERT(Unk_172d080, field_1e4, 0x1e4);

// 0x710172d080
void Unk_172d080_set(Unk_172d080* self, bool value) {
    self->field_1e4 = value;
}

struct Unk_172d090 {
    u8 _0[0x1e5];
    u8 field_1e5;
};
PKMN_OFFSET_ASSERT(Unk_172d090, field_1e5, 0x1e5);

// 0x710172d090
const u8* Unk_172d090_get(const Unk_172d090* self) {
    return &self->field_1e5;
}

struct Unk_172dea0_8 {
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
};

struct Unk_172dea0 {
    u8 _0[0x8];
    Unk_172dea0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_172dea0, field_8, 0x8);

// 0x710172dea0
void Unk_172dea0_call(const Unk_172dea0* self) {
    if (self->field_8 != nullptr) {
        self->field_8->vf17();
    }
}

struct Unk_172e080_70 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_172e080_70, field_90, 0x90);
struct Unk_172e080 {
    u8 _0[0x70];
    Unk_172e080_70* field_70;
    u8 _78[0x5c];
    u32 field_d4;
    u32 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_172e080, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_172e080, field_d4, 0xd4);
PKMN_OFFSET_ASSERT(Unk_172e080, field_d8, 0xd8);

// 0x710172e080
u32 Unk_172e080_get(const Unk_172e080* self) {
    if (self->field_70 != nullptr) {
        if (self->field_d8 >= 2 && self->field_d8 <= 7) {
            return 0;
        }
        if (self->field_d4 == 3) {
            return self->field_70->field_90;
        }
        return 0;
    }
    return 0;
}

struct Unk_17315c0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_17315c0, field_8, 0x8);

// 0x71017315c0
u32 Unk_17315c0_get(const Unk_17315c0* self) {
    return self->field_8;
}

struct Unk_17315d0 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_17315d0, field_c, 0xc);

// 0x71017315d0
u32 Unk_17315d0_get(const Unk_17315d0* self) {
    return self->field_c;
}

struct Unk_17315e0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_17315e0, field_10, 0x10);

// 0x71017315e0
u32 Unk_17315e0_get(const Unk_17315e0* self) {
    return self->field_10;
}

void Unk_1733880(void*, u32, u32, void*, u32, u64, u64, u32);

// 0x7101732ec0
void Unk_1732ec0_call(void* self, u32 value, void* arg2, u32 arg3, u64 arg4, u64 arg5, u32 arg6) {
    Unk_1733880(self, 0x14, value, arg2, arg3, arg4, arg5, arg6);
}

void Unk_1733880(void*, u32, u32, void*, u32, u64, u64, u32);

// 0x7101733c70
void Unk_1733c70_call(void* self, u32 value, void* arg2, u32 arg3, u64 arg4, u64 arg5, u32 arg6) {
    Unk_1733880(self, 6, value, arg2, arg3, arg4, arg5, arg6);
}

void Unk_1733880(void*, u32, u32, void*, u32, u64, u64, u32);

// 0x7101733c90
void Unk_1733c90_call(void* self, u32 value, void* arg2, u32 arg3, u64 arg4, u64 arg5, u32 arg6) {
    Unk_1733880(self, 8, value, arg2, arg3, arg4, arg5, arg6);
}

void Unk_1733880(void*, u32, u32, void*, u32, u64, u64, u32);

// 0x7101733cb0
void Unk_1733cb0_call(void* self, u32 value, void* arg2, u32 arg3, u64 arg4, u64 arg5, u32 arg6) {
    Unk_1733880(self, 0xa, value, arg2, arg3, arg4, arg5, arg6);
}

struct Unk_1733d50_arg1 {
    u8 _0[0x8];
    u32 field_8;
    u32 field_c;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1733d50_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1733d50_arg1, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1733d50_arg1, field_10, 0x10);

struct Unk_1733d50 {
    u8 _0[0x8];
    u32 field_8;
    u32 field_c;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1733d50, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1733d50, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1733d50, field_10, 0x10);

// 0x7101733d50
void Unk_1733d50_set(Unk_1733d50* self, const Unk_1733d50_arg1* value) {
    self->field_10 = value->field_10;
    self->field_8 = value->field_8;
    self->field_c = value->field_c;
}

struct Unk_1733de0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1733de0, field_10, 0x10);

// 0x7101733de0
u32 Unk_1733de0_get(const Unk_1733de0* self) {
    return self->field_10;
}

struct Unk_1733df0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1733df0, field_8, 0x8);

// 0x7101733df0
u32 Unk_1733df0_get(const Unk_1733df0* self) {
    return self->field_8;
}

struct Unk_1733e00 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1733e00, field_c, 0xc);

// 0x7101733e00
u32 Unk_1733e00_get(const Unk_1733e00* self) {
    return self->field_c;
}

struct Unk_1733e70 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1733e70, field_8, 0x8);

// 0x7101733e70
void Unk_1733e70_set(Unk_1733e70* self, u32 value) {
    self->field_8 = value;
}

struct Unk_1733e80 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1733e80, field_8, 0x8);

// 0x7101733e80
u32 Unk_1733e80_get(const Unk_1733e80* self) {
    return self->field_8;
}

struct Unk_1734ab0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(u32);
    virtual void vf3();
    virtual void vf4();
};

// 0x7101734ab0
void Unk_1734ab0_call(Unk_1734ab0* self) {
    self->vf4();
    self->vf2(1);
}

// 0x7101735d40
void Unk_1735d40_update(u64 /*unused*/, void* /*unused*/) {
}

struct Unk_17360c0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_17360c0, field_8, 0x8);

// 0x71017360c0
u32 Unk_17360c0_get(const Unk_17360c0* self) {
    return self->field_8;
}

struct Unk_17360d0 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_17360d0, field_8, 0x8);

// 0x71017360d0
u16 Unk_17360d0_get(const Unk_17360d0* self) {
    return self->field_8;
}

struct Unk_17360e0 {
    u8 _0[0xa];
    u16 field_a;
};
PKMN_OFFSET_ASSERT(Unk_17360e0, field_a, 0xa);

// 0x71017360e0
u16 Unk_17360e0_get(const Unk_17360e0* self) {
    return self->field_a;
}

extern u8 Unk_27fc0b8 __attribute__((visibility("hidden")));

// 0x71017363e0
u8 Unk_17363e0_get() {
    return Unk_27fc0b8;
}

extern u8 Unk_27fc0b9 __attribute__((visibility("hidden")));

// 0x71017363f0
u8 Unk_17363f0_get() {
    return Unk_27fc0b9;
}

struct Unk_1736d20 {
    u8 _0[0x78];
    u32 field_78;
    u8 _7c[0x2c];
    u8 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_1736d20, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_1736d20, field_a8, 0xa8);

// 0x7101736d20
void Unk_1736d20_set(Unk_1736d20* self) {
    if (self->field_78 >= 1 && self->field_78 <= 3) {
        self->field_a8 = 1;
    }
}

struct Unk_1736d40 {
    u8 _0[0x48];
    u8 field_48;
    u8 _49[0x2f];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_1736d40, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_1736d40, field_78, 0x78);

// 0x7101736d40
bool Unk_1736d40_check(const Unk_1736d40* self) {
    if (self->field_48 == 0) {
        return false;
    }
    return (self->field_78 & 0xfffffffe) == 4;
}

struct Unk_1738980_68 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

struct Unk_1738980 {
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
    virtual u64 vf12();
    u8 _8[0x60];
    Unk_1738980_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_1738980, field_68, 0x68);

// 0x7101738980
void Unk_1738980_call(Unk_1738980* self) {
    u64 r0 = self->vf12();
    if (r0 != 0) {
        self->field_68->vf4();
    }
}

struct Unk_17399e0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_17399e0, field_0, 0x0);

// 0x71017399e0
void Unk_17399e0_set(Unk_17399e0* self) {
    self->field_0 = 1;
}

// 0x71017399f0
void Unk_17399f0_update(u64 /*unused*/) {
}

struct Unk_1739a90 {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_1739a90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1739a90, field_4, 0x4);

// 0x7101739a90
void Unk_1739a90_set(Unk_1739a90* self) {
    self->field_0 = 0x3e8;
    self->field_4 = 1;
}

// 0x7101739ab0
void Unk_1739ab0_update(u64 /*unused*/) {
}

struct Unk_173ab60_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_173ab60_arg1, field_0, 0x0);

struct Unk_173ab60 {
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
    u8 _8[0xd0];
    u32 field_d8;
    u8 _dc[0xc];
    u8 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_173ab60, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_173ab60, field_e8, 0xe8);

// 0x710173ab60
u8* Unk_173ab60_call(Unk_173ab60* self, const Unk_173ab60_arg1* value) {
    self->field_d8 = value->field_0;
    self->vf19();
    return &self->field_e8;
}

struct Unk_173aef0 {
    u8 _0[0xd0];
    void* field_d0;
};
PKMN_OFFSET_ASSERT(Unk_173aef0, field_d0, 0xd0);

void Unk_173b750(void*);

// 0x710173aef0
void Unk_173aef0_call(const Unk_173aef0* self) {
    if (self->field_d0 != nullptr) {
        Unk_173b750(self->field_d0);
    }
}

struct Unk_173b500 {
    u8 _0[0x368];
    u8 field_368;
};
PKMN_OFFSET_ASSERT(Unk_173b500, field_368, 0x368);

// 0x710173b500
void Unk_173b500_set(Unk_173b500* self) {
    if (self->field_368 != 0) {
        self->field_368 = 0;
    }
}

// 0x710173bb30
void Unk_173bb30_update(u64 /*unused*/, void* /*unused*/) {
}

struct Unk_173bc80 {
    u8 _0[0x8];
    u32 field_8;
    u32 field_c;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_173bc80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_173bc80, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_173bc80, field_10, 0x10);

// 0x710173bc80
void Unk_173bc80_set(Unk_173bc80* self) {
    self->field_8 = self->field_c;
    self->field_10 = 0;
}

struct Unk_173bd40 {
    u8 _0[0x8];
    u32 field_8;
    u32 field_c;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_173bd40, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_173bd40, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_173bd40, field_10, 0x10);

// 0x710173bd40
void Unk_173bd40_set(Unk_173bd40* self) {
    self->field_8 = self->field_c;
    self->field_10 = 0;
}

struct Unk_173cfc0 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_173cfc0, field_28, 0x28);

// 0x710173cfc0
void Unk_173cfc0_set(Unk_173cfc0* self, u32 value) {
    self->field_28 = value;
}

struct Unk_173e5e0 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_40, 0x40);

// 0x710173e5e0
u64 Unk_173e5e0_get(const Unk_173e5e0* self) {
    return self->field_40;
}

// 0x710173e7c0
void Unk_173e7c0_update(u64 /*unused*/, u64 /*unused*/) {
}

// 0x710173eb40
void Unk_173eb40_update(u64 /*unused*/) {
}

struct Unk_173eb50 {
    u8 _0[0xbb0];
    u64 field_bb0;
};
PKMN_OFFSET_ASSERT(Unk_173eb50, field_bb0, 0xbb0);

// 0x710173eb50
void Unk_173eb50_set(Unk_173eb50* self, u64 value) {
    self->field_bb0 = value;
}

struct Unk_173f370 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_173f370, field_0, 0x0);

void Unk_174fcd0(u8);

// 0x710173f370
void Unk_173f370_call(const Unk_173f370* self) {
    Unk_174fcd0(self->field_0);
}

extern u32 Unk_1f452f4;
struct Unk_1743f00 {
    u8 _0[0x440];
    u32 field_440;
};
PKMN_OFFSET_ASSERT(Unk_1743f00, field_440, 0x440);

// 0x7101743f00
bool Unk_1743f00_check(const Unk_1743f00* self) {
    return self->field_440 != Unk_1f452f4;
}

void Unk_1748f30(s64);

// 0x7101748960
void Unk_1748960_call(u64 self) {
    Unk_1748f30(self);
}

// 0x7101748ae0
void Unk_1748ae0_update(u64 /*unused*/) {
}

struct Unk_1748d10 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1748d10, field_8, 0x8);

// 0x7101748d10
void Unk_1748d10_set(Unk_1748d10* self) {
    self->field_8 = 0xffffffffffffffff;
}

struct Unk_1748d20 {
    u8 field_0;
    u8 _1[0x7];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1748d20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1748d20, field_8, 0x8);

// 0x7101748d20
u32 Unk_1748d20_get(const Unk_1748d20* self) {
    if (self->field_0 == 0) {
        return 0xffffffff;
    }
    return self->field_8;
}

struct Unk_1748d40 {
    u8 field_0;
    u8 _1[0xb];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1748d40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1748d40, field_c, 0xc);

// 0x7101748d40
u32 Unk_1748d40_get(const Unk_1748d40* self) {
    if (self->field_0 == 0) {
        return 0xffffffff;
    }
    return self->field_c;
}

struct Unk_1748e60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1748e60_arg1, field_0, 0x0);

struct Unk_1748e60 {
    u8 _0[0x10];
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1748e60, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1748e60, field_18, 0x18);

// 0x7101748e60
void Unk_1748e60_set(Unk_1748e60* self, const Unk_1748e60_arg1* value) {
    self->field_18 = 1;
    self->field_10 = value->field_0;
}

// 0x71017490e0
void Unk_17490e0_update(u64 /*unused*/) {
}

struct Unk_1749400 {
    u8 _0[0x38];
    u8 field_38;
    u8 _39[0x7];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_1749400, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_1749400, field_40, 0x40);

// 0x7101749400
void Unk_1749400_set(Unk_1749400* self, u64 value, u8 arg2) {
    self->field_40 = value;
    self->field_38 = arg2;
}

struct Unk_17497e0 {
    u8 _0[0x38];
    u8 field_38;
    u8 _39[0x17];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_17497e0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_17497e0, field_50, 0x50);

void Unk_17488a0(void*, u8);

// 0x71017497e0
void Unk_17497e0_call(const Unk_17497e0* self) {
    if (self->field_50 != nullptr) {
        Unk_17488a0(self->field_50, self->field_38);
    }
}

struct Unk_1749cd0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1749cd0, field_8, 0x8);

// 0x7101749cd0
const u8* Unk_1749cd0_get(const Unk_1749cd0* self) {
    return &self->field_8;
}

struct Unk_1749ce0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_1749ce0, field_28, 0x28);

// 0x7101749ce0
const u8* Unk_1749ce0_get(const Unk_1749ce0* self) {
    return &self->field_28;
}

struct Unk_1749d50 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_1749d50, field_78, 0x78);

// 0x7101749d50
u32 Unk_1749d50_get(const Unk_1749d50* self) {
    return (self->field_78 >> 2) & 3;
}

struct Unk_1749d60 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_1749d60, field_78, 0x78);

// 0x7101749d60
u32 Unk_1749d60_get(const Unk_1749d60* self) {
    return self->field_78 & 3;
}

struct Unk_1749d70 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_1749d70, field_78, 0x78);

// 0x7101749d70
u32 Unk_1749d70_get(const Unk_1749d70* self) {
    return self->field_78 >> 4;
}

struct Unk_1749d80 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1749d80, field_68, 0x68);

// 0x7101749d80
u64 Unk_1749d80_get(const Unk_1749d80* self) {
    return self->field_68;
}

struct Unk_1749d90 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_1749d90, field_70, 0x70);

// 0x7101749d90
u32 Unk_1749d90_get(const Unk_1749d90* self) {
    return self->field_70;
}

struct Unk_1749da0 {
    u8 _0[0x74];
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_1749da0, field_74, 0x74);

// 0x7101749da0
u32 Unk_1749da0_get(const Unk_1749da0* self) {
    return self->field_74;
}

struct Unk_1749db0 {
    u8 _0[0x79];
    u8 field_79;
};
PKMN_OFFSET_ASSERT(Unk_1749db0, field_79, 0x79);

// 0x7101749db0
u8 Unk_1749db0_get(const Unk_1749db0* self) {
    return self->field_79;
}

struct Unk_1749dc0 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_1749dc0, field_78, 0x78);

// 0x7101749dc0
bool Unk_1749dc0_check(const Unk_1749dc0* self) {
    return (self->field_78 & 0xc) == 8;
}

struct Unk_1749de0 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_1749de0, field_78, 0x78);

// 0x7101749de0
bool Unk_1749de0_check(const Unk_1749de0* self) {
    return (self->field_78 & 0xc) == 4;
}

struct Unk_1749e00 {
    u8 _0[0x79];
    u8 field_79;
};
PKMN_OFFSET_ASSERT(Unk_1749e00, field_79, 0x79);

// 0x7101749e00
u32 Unk_1749e00_get(const Unk_1749e00* self) {
    return self->field_79 & 1;
}

struct Unk_1749e10 {
    u8 _0[0x79];
    u8 field_79;
};
PKMN_OFFSET_ASSERT(Unk_1749e10, field_79, 0x79);

// 0x7101749e10
u32 Unk_1749e10_get(const Unk_1749e10* self) {
    return (self->field_79 >> 1) & 1;
}

struct Unk_1749e20 {
    u8 _0[0x79];
    u8 field_79;
};
PKMN_OFFSET_ASSERT(Unk_1749e20, field_79, 0x79);

// 0x7101749e20
bool Unk_1749e20_check(const Unk_1749e20* self) {
    return (self->field_79 & 3) == 2;
}

struct Unk_1749e40 {
    u8 _0[0x48];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_1749e40, field_48, 0x48);

// 0x7101749e40
const u8* Unk_1749e40_get(const Unk_1749e40* self) {
    return &self->field_48;
}

struct Unk_1749e50 {
    u8 _0[0x48];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_1749e50, field_48, 0x48);

// 0x7101749e50
const u8* Unk_1749e50_get(const Unk_1749e50* self) {
    return &self->field_48;
}

struct Unk_1749e80_arg1 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1749e80_arg1, field_68, 0x68);

struct Unk_1749e80 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1749e80, field_68, 0x68);

// 0x7101749e80
bool Unk_1749e80_check(const Unk_1749e80* self, const Unk_1749e80_arg1* value) {
    return self->field_68 == value->field_68;
}

struct Unk_1749ea0_arg1 {
    u8 _0[0x74];
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_1749ea0_arg1, field_74, 0x74);

struct Unk_1749ea0 {
    u8 _0[0x74];
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_1749ea0, field_74, 0x74);

// 0x7101749ea0
bool Unk_1749ea0_check(const Unk_1749ea0* self, const Unk_1749ea0_arg1* value) {
    return self->field_74 == value->field_74;
}

struct Unk_1749ec0_arg1 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_1749ec0_arg1, field_70, 0x70);

struct Unk_1749ec0 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_1749ec0, field_70, 0x70);

// 0x7101749ec0
bool Unk_1749ec0_check(const Unk_1749ec0* self, const Unk_1749ec0_arg1* value) {
    return self->field_70 == value->field_70;
}

struct Unk_1749ee0 {
    u8 _0[0x7a];
    u8 field_7a;
};
PKMN_OFFSET_ASSERT(Unk_1749ee0, field_7a, 0x7a);

// 0x7101749ee0
bool Unk_1749ee0_check(const Unk_1749ee0* self) {
    return self->field_7a == 1;
}

struct Unk_1749ef0 {
    u8 _0[0x7b];
    u8 field_7b;
};
PKMN_OFFSET_ASSERT(Unk_1749ef0, field_7b, 0x7b);

// 0x7101749ef0
bool Unk_1749ef0_check(const Unk_1749ef0* self) {
    return self->field_7b == 1;
}

struct Unk_1749f30 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1749f30, field_68, 0x68);

// 0x7101749f30
void Unk_1749f30_set(Unk_1749f30* self, u64 value) {
    self->field_68 = value;
}

struct Unk_1749f40 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_1749f40, field_70, 0x70);

// 0x7101749f40
void Unk_1749f40_set(Unk_1749f40* self, u32 value) {
    self->field_70 = value;
}

struct Unk_1749f50 {
    u8 _0[0x74];
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_1749f50, field_74, 0x74);

// 0x7101749f50
void Unk_1749f50_set(Unk_1749f50* self, u32 value) {
    self->field_74 = value;
}

struct Unk_1749f80 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_1749f80, field_78, 0x78);

// 0x7101749f80
void Unk_1749f80_set(Unk_1749f80* self, u32 value) {
    self->field_78 = (self->field_78 & 0xfffffffc) | (value & 3);
}

struct Unk_1749f90 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_1749f90, field_78, 0x78);

// 0x7101749f90
void Unk_1749f90_set(Unk_1749f90* self, u32 value) {
    self->field_78 = (self->field_78 & 0xf) | ((value & 0xfffffff) << 4);
}

struct Unk_1749fa0 {
    u8 _0[0x79];
    u8 field_79;
};
PKMN_OFFSET_ASSERT(Unk_1749fa0, field_79, 0x79);

// 0x7101749fa0
void Unk_1749fa0_set(Unk_1749fa0* self, u8 value) {
    self->field_79 = value;
}

struct Unk_1749fb0 {
    u8 _0[0x7a];
    bool field_7a;
};
PKMN_OFFSET_ASSERT(Unk_1749fb0, field_7a, 0x7a);

// 0x7101749fb0
void Unk_1749fb0_set(Unk_1749fb0* self, bool value) {
    self->field_7a = value;
}

struct Unk_1749fc0 {
    u8 _0[0x7b];
    bool field_7b;
};
PKMN_OFFSET_ASSERT(Unk_1749fc0, field_7b, 0x7b);

// 0x7101749fc0
void Unk_1749fc0_set(Unk_1749fc0* self, bool value) {
    self->field_7b = value;
}

struct Unk_174b0e0 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_174b0e0, field_28, 0x28);

// 0x710174b0e0
u32 Unk_174b0e0_get(const Unk_174b0e0* self) {
    return self->field_28;
}

struct Unk_174b770 {
    u8 _0[0x4f0];
    u64 field_4f0;
};
PKMN_OFFSET_ASSERT(Unk_174b770, field_4f0, 0x4f0);

void Unk_174f6d0(void*);

// 0x710174b770
void Unk_174b770_call(Unk_174b770* self) {
    Unk_174f6d0(self);
    self->field_4f0 = 0;
}

struct Unk_174be00 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_174be00, field_50, 0x50);

// 0x710174be00
void Unk_174be00_set(Unk_174be00* self, u64 value) {
    self->field_50 = value;
}

struct Unk_174be10 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_174be10, field_48, 0x48);

// 0x710174be10
void Unk_174be10_set(Unk_174be10* self, u64 value) {
    self->field_48 = value;
}

struct Unk_174c7a0 {
    u8 _0[0x4f0];
    u64 field_4f0;
};
PKMN_OFFSET_ASSERT(Unk_174c7a0, field_4f0, 0x4f0);

void Unk_174f6d0(void*);

// 0x710174c7a0
void Unk_174c7a0_call(Unk_174c7a0* self) {
    Unk_174f6d0(self);
    self->field_4f0 = 0;
}

struct Unk_174dbc0_60 {
    u8 _0[0xfec];
    u32 field_fec;
};
PKMN_OFFSET_ASSERT(Unk_174dbc0_60, field_fec, 0xfec);

struct Unk_174dbc0 {
    u8 _0[0x60];
    Unk_174dbc0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_174dbc0, field_60, 0x60);

// 0x710174dbc0
u32 Unk_174dbc0_get(const Unk_174dbc0* self) {
    return self->field_60->field_fec;
}

struct Unk_174de50 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_174de50, field_90, 0x90);

// 0x710174de50
u64 Unk_174de50_get(const Unk_174de50* self) {
    return self->field_90;
}

struct Unk_174de60 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_174de60, field_98, 0x98);

// 0x710174de60
u64 Unk_174de60_get(const Unk_174de60* self) {
    return self->field_98;
}

struct Unk_174e2a0_a8 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_174e2a0_a8, field_8, 0x8);

struct Unk_174e2a0 {
    u8 _0[0xa8];
    Unk_174e2a0_a8* field_a8;
};
PKMN_OFFSET_ASSERT(Unk_174e2a0, field_a8, 0xa8);

// 0x710174e2a0
u64 Unk_174e2a0_get(const Unk_174e2a0* self) {
    if (self->field_a8 == nullptr) {
        return 0;
    }
    return self->field_a8->field_8;
}

struct Unk_174e2c0_a8 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_174e2c0_a8, field_10, 0x10);

struct Unk_174e2c0 {
    u8 _0[0xa8];
    Unk_174e2c0_a8* field_a8;
};
PKMN_OFFSET_ASSERT(Unk_174e2c0, field_a8, 0xa8);

// 0x710174e2c0
u64 Unk_174e2c0_get(const Unk_174e2c0* self) {
    if (self->field_a8 == nullptr) {
        return 0;
    }
    return self->field_a8->field_10;
}

struct Unk_174e320_60 {
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
};

struct Unk_174e320 {
    u8 _0[0x60];
    Unk_174e320_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_174e320, field_60, 0x60);

// 0x710174e320
void Unk_174e320_call(const Unk_174e320* self) {
    self->field_60->vf16();
}

struct Unk_174e330 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_174e330, field_8, 0x8);

// 0x710174e330
u64 Unk_174e330_get(const Unk_174e330* self) {
    return self->field_8;
}

struct Unk_174e340 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_174e340, field_a0, 0xa0);

// 0x710174e340
u64 Unk_174e340_get(const Unk_174e340* self) {
    return self->field_a0;
}

struct Unk_174e350 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_174e350, field_a8, 0xa8);

// 0x710174e350
u64 Unk_174e350_get(const Unk_174e350* self) {
    return self->field_a8;
}

// 0x710174ea90
void Unk_174ea90_update() {
}

struct Unk_174ebe0 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_174ebe0, field_18, 0x18);

// 0x710174ebe0
void Unk_174ebe0_set(Unk_174ebe0* self) {
    if (self->field_18 != 0) {
        self->field_18 = 0;
    }
}
