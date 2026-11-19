// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_34dc20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u8 _38[0x5];
    u8 field_3d;
};
PKMN_OFFSET_ASSERT(Unk_34dc20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_34dc20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_34dc20, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_34dc20, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_34dc20, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_34dc20, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_34dc20, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_34dc20, field_3d, 0x3d);

// 0x710034dc20
void Unk_34dc20_set(Unk_34dc20* self) {
    self->field_3d = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_20 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_28 = 0;
    self->field_30 = 0;
}

// 0x710034dc40
void Unk_34dc40_update() {
}

struct Unk_34dc90 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x14];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_34dc90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_34dc90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_34dc90, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_34dc90, field_28, 0x28);

// 0x710034dc90
void Unk_34dc90_set(Unk_34dc90* self) {
    self->field_10 = 0;
    self->field_28 = 0;
    self->field_8 = self->field_0;
}

struct Unk_34e050 {
    u8 _0[0x10];
    u32 field_10;
    u8 _14[0x14];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_34e050, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_34e050, field_28, 0x28);

// 0x710034e050
u32 Unk_34e050_update(Unk_34e050* self, u64 value, u32 arg2) {
    self->field_28 = value;
    self->field_10 = arg2;
    return 1;
}

extern u32 Unk_237e820;
struct Unk_34e550 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_34e550, field_20, 0x20);

void Unk_304740(u32, u64);

// 0x710034e550
void Unk_34e550_call(Unk_34e550* self) {
    if (self->field_20 != 0) {
        Unk_304740(Unk_237e820, self->field_20);
        self->field_20 = 0;
    }
}

extern u64 Unk_24bbbf0;
struct Unk_34f480 {
    u8 _0[0x100];
    u64 field_100;
    u8 _108[0x40];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_34f480, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_34f480, field_148, 0x148);

u64 Unk_3887b0(u64);
void Unk_38add0(u64, u64, u64);

// 0x710034f480
void Unk_34f480_call(const Unk_34f480* self) {
    u64 v0 = self->field_100;
    if (v0 != 0) {
        u64 v1 = Unk_24bbbf0;
        u64 r0 = Unk_3887b0(self->field_148);
        Unk_38add0(v1, v0, r0);
    }
}

struct Unk_34fb90_148 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_34fb90_148, field_10, 0x10);

struct Unk_34fb90 {
    u8 _0[0x148];
    Unk_34fb90_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_34fb90, field_148, 0x148);

// 0x710034fb90
u32 Unk_34fb90_get(const Unk_34fb90* self) {
    return self->field_148->field_10;
}

struct Unk_34fbc0_10_38_0 {
    u8 _0[0x3a];
    u8 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_34fbc0_10_38_0, field_3a, 0x3a);

struct Unk_34fbc0_10_38 {
    Unk_34fbc0_10_38_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_34fbc0_10_38, field_0, 0x0);

struct Unk_34fbc0_10 {
    u8 _0[0x38];
    Unk_34fbc0_10_38* field_38;
};
PKMN_OFFSET_ASSERT(Unk_34fbc0_10, field_38, 0x38);

struct Unk_34fbc0 {
    u8 _0[0x10];
    Unk_34fbc0_10* field_10;
    u8 _18[0x13c];
    u16 field_154;
};
PKMN_OFFSET_ASSERT(Unk_34fbc0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_34fbc0, field_154, 0x154);

// 0x710034fbc0
bool Unk_34fbc0_check(const Unk_34fbc0* self) {
    if ((self->field_154 & 0xf) != 5) {
        return false;
    }
    return (self->field_10->field_38->field_0->field_3a & 7) == 1;
}

extern u64 Unk_24bbbf0;
struct Unk_3514b0 {
    u8 _0[0x100];
    u64 field_100;
};
PKMN_OFFSET_ASSERT(Unk_3514b0, field_100, 0x100);
void Unk_38af50(u64, u64);
void Unk_38afa0(u64, u64);

// 0x71003514b0
void Unk_3514b0_call(const Unk_3514b0* self, bool value) {
    if (self->field_100 != 0) {
        if (value != 0) {
            Unk_38af50(Unk_24bbbf0, self->field_100);
            return;
        }
        Unk_38afa0(Unk_24bbbf0, self->field_100);
        return;
    }
}

struct Unk_351500 {
    u8 _0[0xc4];
    u32 field_c4;
    u32 field_c8;
    u32 field_cc;
    u32 field_d0;
    u8 _d4[0xc];
    u8 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_351500, field_c4, 0xc4);
PKMN_OFFSET_ASSERT(Unk_351500, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_351500, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_351500, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_351500, field_e0, 0xe0);

// 0x7100351500
bool Unk_351500_get(const Unk_351500* self) {
    if (self->field_e0 != 0) {
        return 1;
    }
    if (self->field_c4 != 0) {
        return 1;
    }
    if (self->field_c8 != 0) {
        return 1;
    }
    if (self->field_cc != 0) {
        return 1;
    }
    return self->field_d0 != 0;
}

struct Unk_352820 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_352820, field_80, 0x80);

// 0x7100352820
bool Unk_352820_check(const Unk_352820* self) {
    return self->field_80 == 0;
}

struct Unk_355bf0 {
    u8 _0[0x164];
    u8 field_164;
};
PKMN_OFFSET_ASSERT(Unk_355bf0, field_164, 0x164);

void Unk_3557c0();

// 0x7100355bf0
void Unk_355bf0_call(Unk_355bf0* self) {
    if ((self->field_164 & 7) == 2) {
        self->field_164 = self->field_164 & 0xf8;
        Unk_3557c0();
    }
}

void Unk_384140();

// 0x7100356a80
void Unk_356a80_call() {
    Unk_384140();
}
