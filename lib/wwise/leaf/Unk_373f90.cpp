// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_373f90 {
    u8 _0[0x5c];
    u32 field_5c;
    u32 field_60;
    u8 _64[0x4];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_373f90, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_373f90, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_373f90, field_68, 0x68);

// 0x7100373f90
void Unk_373f90_set(Unk_373f90* self, u32 value) {
    if (self->field_5c == 0x7fffffff) {
        self->field_5c = self->field_60 + value;
        if (self->field_68 == 3) return;
        self->field_68 = 2;
    }
}

struct Unk_373fd0 {
    u8 _0[0x10];
    u64 field_10;
    u8 _18[0x50];
    u32 field_68;
    s32 field_6c;
    u8 _70[0x4];
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_373fd0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_373fd0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_373fd0, field_6c, 0x6c);
PKMN_OFFSET_ASSERT(Unk_373fd0, field_74, 0x74);

// 0x7100373fd0
bool Unk_373fd0_get(const Unk_373fd0* self) {
    if (self->field_10 != 0) {
        if (self->field_68 == 3) {
            return 1;
        }
        if (self->field_6c <= 1) {
            return self->field_74 == 0;
        }
        return 0;
    }
    return 1;
}

// 0x7100377580
void Unk_377580_update() {
}

struct Unk_378ab0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_378ab0, field_18, 0x18);

void Unk_375490(u64);

// 0x7100378ab0
void Unk_378ab0_call(const Unk_378ab0* self) {
    if (self->field_18 != 0) {
        Unk_375490(self->field_18);
    }
}

struct Unk_379b50 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_379b50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_379b50, field_8, 0x8);

// 0x7100379b50
void Unk_379b50_set(Unk_379b50* self) {
    self->field_0 = 0;
    self->field_8 = 0xffffffff;
}

struct Unk_37af50 {
    u8 _0[0x118];
    u64 field_118;
    u8 _120[0x4];
    u8 field_124;
};
PKMN_OFFSET_ASSERT(Unk_37af50, field_118, 0x118);
PKMN_OFFSET_ASSERT(Unk_37af50, field_124, 0x124);

// 0x710037af50
void Unk_37af50_set(Unk_37af50* self) {
    self->field_124 = 0;
    self->field_118 = 0;
}

void Unk_37ce00(u32);

// 0x710037cdf0
void Unk_37cdf0_call() {
    Unk_37ce00(0);
}

u32 Unk_37f4b0();

// 0x710037f540
bool Unk_37f540_call() {
    u32 r0 = Unk_37f4b0();
    return r0 == 1;
}

extern u32 Unk_24bcb48;

// 0x7100380fd0
void Unk_380fd0_set() {
    Unk_24bcb48 = Unk_24bcb48 + 1;
}

struct Unk_381010 {
    u64 field_0;
    u64 field_8;
    u16 field_10;
    bool field_12;
    bool field_13;
    u8 _14[0x14];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_381010, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_381010, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_381010, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_381010, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_381010, field_13, 0x13);
PKMN_OFFSET_ASSERT(Unk_381010, field_28, 0x28);

// 0x7100381010
void Unk_381010_set(Unk_381010* self, u16 value, bool arg2, bool arg3) {
    self->field_10 = value;
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_12 = arg2;
    self->field_13 = arg3;
    self->field_28 = 0;
}

extern u8 Unk_24df138;
struct Unk_3825f0 {
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
    u8 _8[0x68];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_3825f0, field_70, 0x70);

// 0x71003825f0
void Unk_3825f0_call(Unk_3825f0* self) {
    if (self->field_70 != 0) {
        self->vf29();
        Unk_24df138 = 1;
    }
}

struct Unk_384e70 {
    u8 _0[0x9e];
    u8 field_9e;
};
PKMN_OFFSET_ASSERT(Unk_384e70, field_9e, 0x9e);

// 0x7100384e70
u32 Unk_384e70_get(const Unk_384e70* self) {
    return (self->field_9e >> 3) & 1;
}

struct Unk_387770_70 {
    u8 _0[0x8];
    u32 field_8;
    u8 _c[0x4];
    u64 field_10;
    u8 _18[0x70];
    u16 field_88;
    u16 field_8a;
    u8 _8c[0x4];
    s16 field_90;
    u8 _92[0x2];
    s16 field_94;
};
PKMN_OFFSET_ASSERT(Unk_387770_70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_387770_70, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_387770_70, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_387770_70, field_8a, 0x8a);
PKMN_OFFSET_ASSERT(Unk_387770_70, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_387770_70, field_94, 0x94);
struct Unk_387770 {
    u8 _0[0x70];
    Unk_387770_70* field_70;
};
PKMN_OFFSET_ASSERT(Unk_387770, field_70, 0x70);
void Unk_381f40();

// 0x7100387770
void Unk_387770_update(const Unk_387770* self) {
    if (self->field_70 != nullptr) {
        if (self->field_70->field_90 <= 0) {
            if (self->field_70->field_94 <= 0) {
                if (self->field_70->field_88 == 0) {
                    if (self->field_70->field_8a == 0) {
                        if (self->field_70->field_10 == 0) {
                            if (self->field_70->field_8 != 0) {
                                return;
                            }
                            Unk_381f40();
                            return;
                        }
                        return;
                    }
                    return;
                }
                return;
            }
            return;
        }
        return;
    }
}

struct Unk_3887a0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_3887a0, field_68, 0x68);

void Unk_3633e0(u64);

// 0x71003887a0
void Unk_3887a0_call(const Unk_3887a0* self) {
    if (self->field_68 != 0) {
        Unk_3633e0(self->field_68);
    }
}
