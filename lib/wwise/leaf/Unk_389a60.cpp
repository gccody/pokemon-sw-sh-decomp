// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_389a60 {
    u32 field_0;
    u8 _4[0x54];
    u32 field_58;
};
PKMN_OFFSET_ASSERT(Unk_389a60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_389a60, field_58, 0x58);

// 0x7100389a60
void Unk_389a60_set(Unk_389a60* self, u32 value) {
    self->field_58 = value;
    self->field_0 = 2;
}

struct Unk_389ec0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_389ec0, field_0, 0x0);

// 0x7100389ec0
bool Unk_389ec0_check(const Unk_389ec0* self) {
    return self->field_0 == 0;
}

struct Unk_38a390 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_38a390, field_80, 0x80);

// 0x710038a390
void Unk_38a390_set(Unk_38a390* self, u32 value) {
    self->field_80 = value;
}

struct Unk_38a3a0 {
    u8 _0[0x84];
    u32 field_84;
};
PKMN_OFFSET_ASSERT(Unk_38a3a0, field_84, 0x84);

// 0x710038a3a0
void Unk_38a3a0_set(Unk_38a3a0* self, u32 value) {
    self->field_84 = value;
}

struct Unk_38a3b0 {
    u8 _0[0x2d];
    bool field_2d;
};
PKMN_OFFSET_ASSERT(Unk_38a3b0, field_2d, 0x2d);

// 0x710038a3b0
void Unk_38a3b0_set(Unk_38a3b0* self, bool value) {
    self->field_2d = value;
}

struct Unk_38a6f0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_38a6f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_38a6f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_38a6f0, field_10, 0x10);

// 0x710038a6f0
void Unk_38a6f0_set(Unk_38a6f0* self) {
    self->field_10 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

// 0x710038a700
void Unk_38a700_update() {
}

struct Unk_38acb0_arg1 {
    u8 _0[0x40];
    u8 field_40;
};
PKMN_OFFSET_ASSERT(Unk_38acb0_arg1, field_40, 0x40);

// 0x710038acb0
void Unk_38acb0_set(void* /*unused*/, Unk_38acb0_arg1* value) {
    value->field_40 = value->field_40 + 1;
}

void Unk_389f80(u64, u64, u32, u32, u32, u64);

// 0x710038adb0
void Unk_38adb0_call(void* /*unused*/, u64 value, u64 arg2, u32 arg3, u32 arg4, bool arg5, u64 arg6) {
    Unk_389f80(value, arg2, arg3, arg4, arg5, arg6);
}

struct Unk_38ca70 {
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
    u8 _8[0x198];
    u8 field_1a0;
};
PKMN_OFFSET_ASSERT(Unk_38ca70, field_1a0, 0x1a0);

void Unk_38cab0(void*, u64, u32);

// 0x710038ca70
void Unk_38ca70_call(Unk_38ca70* self, u64 value, bool arg2) {
    Unk_38cab0(&self->field_1a0, value, arg2);
    self->vf13();
}

struct Unk_38d2c0 {
    u8 _0[0x26a];
    u8 field_26a;
};
PKMN_OFFSET_ASSERT(Unk_38d2c0, field_26a, 0x26a);

// 0x710038d2c0
void Unk_38d2c0_set(Unk_38d2c0* self) {
    self->field_26a = self->field_26a & 0xffffff87;
}

struct Unk_38d2d0 {
    u8 _0[0x26a];
    u8 field_26a;
};
PKMN_OFFSET_ASSERT(Unk_38d2d0, field_26a, 0x26a);

// 0x710038d2d0
void Unk_38d2d0_set(Unk_38d2d0* self) {
    self->field_26a = (self->field_26a & 0xffffff8f) | 8;
}

struct Unk_38d2f0 {
    u8 _0[0x26a];
    u8 field_26a;
};
PKMN_OFFSET_ASSERT(Unk_38d2f0, field_26a, 0x26a);

// 0x710038d2f0
void Unk_38d2f0_set(Unk_38d2f0* self) {
    self->field_26a = (self->field_26a & 0xffffff9f) | 0x18;
}

struct Unk_38d310 {
    u8 _0[0x26a];
    u8 field_26a;
};
PKMN_OFFSET_ASSERT(Unk_38d310, field_26a, 0x26a);

// 0x710038d310
void Unk_38d310_set(Unk_38d310* self) {
    self->field_26a = (self->field_26a & 0xffffff9f) | 0x18;
}

struct Unk_38e020_160 {
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
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58(u64, u64, u64);
};

struct Unk_38e020 {
    u8 _0[0x160];
    Unk_38e020_160* field_160;
};
PKMN_OFFSET_ASSERT(Unk_38e020, field_160, 0x160);

// 0x710038e020
void Unk_38e020_call(const Unk_38e020* self, u64 value, u64 arg2, u64 arg3) {
    self->field_160->vf58(value, arg2, arg3);
}

struct Unk_38e030_200 {
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
    virtual void vf25(u64);
};

struct Unk_38e030 {
    u8 _0[0x16d];
    u8 field_16d;
    u8 _16e[0x92];
    Unk_38e030_200* field_200;
};
PKMN_OFFSET_ASSERT(Unk_38e030, field_16d, 0x16d);
PKMN_OFFSET_ASSERT(Unk_38e030, field_200, 0x200);

// 0x710038e030
void Unk_38e030_call(const Unk_38e030* self, u64 value) {
    if ((self->field_16d & 8) == 0) {
        if (self->field_200 == nullptr) return;
        self->field_200->vf25(value);
    }
}

struct Unk_38e5c0_8 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_38e5c0_8, field_10, 0x10);
struct Unk_38e5c0 {
    u8 _0[0x8];
    Unk_38e5c0_8* field_8;
    u8 _10[0x88];
    u8 field_98;
};
PKMN_OFFSET_ASSERT(Unk_38e5c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_38e5c0, field_98, 0x98);

// 0x710038e5c0
u32 Unk_38e5c0_get(const Unk_38e5c0* self) {
    if (self->field_98 != 0) {
        if (self->field_8 != nullptr) {
            return self->field_8->field_10;
        }
        return 0;
    }
    return 0;
}

extern u32 Unk_2381488;
struct Unk_390440 {
    u8 _0[0x14];
    u16 field_14;
    u8 _16[0x2];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_390440, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_390440, field_18, 0x18);
void Unk_3047c0(int, void*);

// 0x7100390440
void Unk_390440_set(Unk_390440* self) {
    if (self->field_18 != 0) {
        Unk_3047c0(Unk_2381488, reinterpret_cast<void*>(self->field_18));
    }
    self->field_14 = 0;
    self->field_18 = 0;
}

extern u32 Unk_2381488;
struct Unk_390500 {
    u64 field_0;
    u8 _8[0x8];
    u16 field_10;
};
PKMN_OFFSET_ASSERT(Unk_390500, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_390500, field_10, 0x10);

void Unk_304740(int, void*);

// 0x7100390500
void Unk_390500_call(Unk_390500* self) {
    Unk_304740(Unk_2381488, reinterpret_cast<void*>(self->field_0));
    self->field_0 = 0;
    self->field_10 = 0;
}

extern u32 Unk_237e820;
struct Unk_390540 {
    u64 field_0;
    u8 _8[0x4];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_390540, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_390540, field_c, 0xc);

void* Unk_3045e0(int, size_t);

// 0x7100390540
u32 Unk_390540_call(Unk_390540* self) {
    u64 r0 = reinterpret_cast<u64>(Unk_3045e0(Unk_237e820, 0x140));
    self->field_0 = r0;
    if (r0 == 0) {
        return 0x34;
    }
    self->field_c = 8;
    return 1;
}

struct Unk_393270 {
    u8 _0[0xfc];
    u8 field_fc;
};
PKMN_OFFSET_ASSERT(Unk_393270, field_fc, 0xfc);

// 0x7100393270
u32 Unk_393270_get(const Unk_393270* self) {
    return self->field_fc & 0xf;
}

struct Unk_3936b0_c8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

struct Unk_3936b0 {
    u8 _0[0xc8];
    Unk_3936b0_c8* field_c8;
};
PKMN_OFFSET_ASSERT(Unk_3936b0, field_c8, 0xc8);

// 0x71003936b0
void Unk_3936b0_call(const Unk_3936b0* self) {
    if (self->field_c8 != nullptr) {
        self->field_c8->vf4();
    }
}
