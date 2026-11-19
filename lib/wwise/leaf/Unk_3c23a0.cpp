// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern const u8 Unk_2383c38[] __attribute__((visibility("hidden")));

// 0x71003c23a0
const u8* Unk_3c23a0_get() {
    return Unk_2383c38;
}

struct Unk_3c2c10 {
    u8 _0[0x4c];
    u32 field_4c;
};
PKMN_OFFSET_ASSERT(Unk_3c2c10, field_4c, 0x4c);

// 0x71003c2c10
u32 Unk_3c2c10_update(Unk_3c2c10* self) {
    u32 v0 = self->field_4c;
    self->field_4c = v0 + 1;
    return v0 + 1;
}

struct Unk_3c4790 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3c4790, field_0, 0x0);

// 0x71003c4790
u32 Unk_3c4790_update(Unk_3c4790* self) {
    u32 v0 = self->field_0;
    self->field_0 = v0 + 1;
    return v0 + 1;
}

void Unk_3c5b10(u32);

// 0x71003c5b00
void Unk_3c5b00_call() {
    Unk_3c5b10(1);
}

struct Unk_3ca2c0_0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_3ca2c0_0, field_10, 0x10);

struct Unk_3ca2c0 {
    Unk_3ca2c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_3ca2c0, field_0, 0x0);

// 0x71003ca2c0
u32 Unk_3ca2c0_get(const Unk_3ca2c0* self) {
    if (self->field_0 == nullptr) {
        return 0;
    }
    return self->field_0->field_10;
}

struct Unk_3ca380_0_b0 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_3ca380_0_b0, field_4, 0x4);
struct Unk_3ca380_0 {
    u8 _0[0xb0];
    Unk_3ca380_0_b0* field_b0;
};
PKMN_OFFSET_ASSERT(Unk_3ca380_0, field_b0, 0xb0);
struct Unk_3ca380 {
    Unk_3ca380_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_3ca380, field_0, 0x0);

// 0x71003ca380
bool Unk_3ca380_check(const Unk_3ca380* self) {
    if (self->field_0 != nullptr) {
        if (self->field_0->field_b0 != nullptr) {
            return self->field_0->field_b0->field_4 != 0;
        }
        return 0;
    }
    return 0;
}

struct Unk_3ca420_0 {
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
    virtual u32 vf17();
};

struct Unk_3ca420 {
    Unk_3ca420_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_3ca420, field_0, 0x0);

// 0x71003ca420
bool Unk_3ca420_call(const Unk_3ca420* self) {
    if (self->field_0 == nullptr) {
        return false;
    }
    u32 r0 = self->field_0->vf17();
    return r0 == 0xa;
}

struct Unk_3cad80 {
    u16 field_0;
    u8 _2[0x2];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_3cad80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3cad80, field_4, 0x4);

// 0x71003cad80
void Unk_3cad80_set(Unk_3cad80* self) {
    self->field_0 = 0;
    self->field_4 = 0;
}

struct Unk_3cd090_arg2 {
    u8 _0[0x4];
    u32 field_4;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_3cd090_arg2, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_3cd090_arg2, field_8, 0x8);

struct Unk_3cd090 {
    u8 _0[0x78];
    u32 field_78;
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_3cd090, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_3cd090, field_7c, 0x7c);

// 0x71003cd090
void Unk_3cd090_set(const Unk_3cd090* self, bool value, Unk_3cd090_arg2* arg2) {
    if ((value) != 0) {
        arg2->field_4 = self->field_78;
        arg2->field_8 = self->field_7c;
        return;
    }
    arg2->field_4 = 0;
    arg2->field_8 = 0;
}

struct Unk_3d45c0_328_60 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(u64);
};

struct Unk_3d45c0_328 {
    u8 _0[0x60];
    Unk_3d45c0_328_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_3d45c0_328, field_60, 0x60);

struct Unk_3d45c0 {
    u8 _0[0x328];
    Unk_3d45c0_328* field_328;
    u8 _330[0x1c];
    u32 field_34c;
};
PKMN_OFFSET_ASSERT(Unk_3d45c0, field_328, 0x328);
PKMN_OFFSET_ASSERT(Unk_3d45c0, field_34c, 0x34c);

// 0x71003d45c0
void Unk_3d45c0_call(Unk_3d45c0* self, u64 value) {
    self->field_34c = self->field_34c - 1;
    if (self->field_328 != nullptr) {
        if (self->field_328->field_60 == nullptr) return;
        self->field_328->field_60->vf9(value);
    }
}

struct Unk_3d6150 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_3d6150, field_8, 0x8);

// 0x71003d6150
void Unk_3d6150_set(Unk_3d6150* self) {
    self->field_8 = 0;
}

struct Unk_3d6c80 {
    u8 _0[0x10];
    u8 field_10;
    u8 _11[0xd7];
    u64 field_e8;
    u8 field_f0;
    u8 _f1[0x1];
    u8 field_f2;
};
PKMN_OFFSET_ASSERT(Unk_3d6c80, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3d6c80, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_3d6c80, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_3d6c80, field_f2, 0xf2);

void Unk_3d73d0(void*, u64, u32);

// 0x71003d6c80
void Unk_3d6c80_call(Unk_3d6c80* self, u64 value, u64 arg2, u32 arg3) {
    self->field_e8 = arg2;
    self->field_f0 = 0;
    self->field_f2 = 1;
    Unk_3d73d0(&self->field_10, value, arg3);
}

// 0x71003d6da0
void Unk_3d6da0_update() {
}

struct Unk_3d7680 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_3d7680, field_28, 0x28);

// 0x71003d7680
void Unk_3d7680_set(Unk_3d7680* self) {
    self->field_28 = 0;
}

extern u32 Unk_2381488;
struct Unk_3d7690 {
    u8 _0[0x20];
    u64 field_20;
    u8 _28[0x20];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_3d7690, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_3d7690, field_48, 0x48);

void Unk_304740(u32, u64);

// 0x71003d7690
void Unk_3d7690_call(const Unk_3d7690* self) {
    if (self->field_48 != 0) {
        Unk_304740(Unk_2381488, self->field_20);
    }
}

struct Unk_3dabb0 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_3dabb0, field_90, 0x90);

// 0x71003dabb0
void Unk_3dabb0_set(Unk_3dabb0* self, u32 value) {
    self->field_90 = value;
}

struct Unk_3dc310_20 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_3dc310_20, field_120, 0x120);

struct Unk_3dc310 {
    u8 _0[0x20];
    Unk_3dc310_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_3dc310, field_20, 0x20);

// 0x71003dc310
void Unk_3dc310_set(const Unk_3dc310* self) {
    self->field_20->field_120 = 0x42ca0000;
}

struct Unk_3e0ad0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_3e0ad0, field_10, 0x10);

// 0x71003e0ad0
u32 Unk_3e0ad0_update(Unk_3e0ad0* self, u64 value) {
    self->field_10 = value;
    return 1;
}

struct Unk_3e0ae0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3e0ae0_arg1, field_0, 0x0);
struct Unk_3e0ae0_10 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_3e0ae0_10, field_68, 0x68);
struct Unk_3e0ae0 {
    u8 _0[0x10];
    Unk_3e0ae0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_3e0ae0, field_10, 0x10);
void Unk_3e0b00();

// 0x71003e0ae0
void Unk_3e0ae0_call(const Unk_3e0ae0* self, const Unk_3e0ae0_arg1* value) {
    if (value->field_0 != 0) {
        if (self->field_10->field_68 != 0) {
            Unk_3e0b00();
            return;
        }
        return;
    }
}

struct Unk_3e3550_arg1 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_3e3550_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3e3550_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_3e3550_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3e3550_arg1, field_c, 0xc);

struct Unk_3e3550 {
    u8 _0[0x5c];
    u32 field_5c;
    u32 field_60;
    u32 field_64;
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_3e3550, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_3e3550, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_3e3550, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_3e3550, field_68, 0x68);

// 0x71003e3550
void Unk_3e3550_set(const Unk_3e3550* self, Unk_3e3550_arg1* value) {
    value->field_8 = self->field_64;
    value->field_c = self->field_68;
    value->field_0 = self->field_5c;
    value->field_4 = self->field_60;
}

extern u64 Unk_24df1b0;
void Unk_3e3910(u64);

// 0x71003e3900
void Unk_3e3900_call() {
    Unk_3e3910(Unk_24df1b0);
}

extern u32 Unk_2385820;

// 0x71003e3fa0
u32 Unk_3e3fa0_get() {
    return Unk_2385820;
}
