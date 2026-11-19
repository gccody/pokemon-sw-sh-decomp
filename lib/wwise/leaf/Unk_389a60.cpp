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

extern u32 Unk_2381488;
struct Unk_390500 {
    u64 field_0;
    u8 _8[0x8];
    u16 field_10;
};
PKMN_OFFSET_ASSERT(Unk_390500, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_390500, field_10, 0x10);

void Unk_304740(u32, u64);

// 0x7100390500
void Unk_390500_call(Unk_390500* self) {
    Unk_304740(Unk_2381488, self->field_0);
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

u64 Unk_3045e0(u32, u32);

// 0x7100390540
u32 Unk_390540_call(Unk_390540* self) {
    u64 r0 = Unk_3045e0(Unk_237e820, 0x140);
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
