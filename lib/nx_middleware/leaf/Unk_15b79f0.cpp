// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71015b79f0
void Unk_15b79f0_update() {
}

struct Unk_15b7a70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7a70, field_0, 0x0);

// 0x71015b7a70
void Unk_15b7a70_set(Unk_15b7a70* self) {
    self->field_0 = 0;
}

struct Unk_15b7a80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7a80_arg1, field_0, 0x0);

struct Unk_15b7a80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7a80, field_0, 0x0);

// 0x71015b7a80
void Unk_15b7a80_set(Unk_15b7a80* self, const Unk_15b7a80_arg1* value) {
    self->field_0 = value->field_0;
}

struct Unk_15b7b20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7b20_arg1, field_0, 0x0);

struct Unk_15b7b20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7b20, field_0, 0x0);

// 0x71015b7b20
void Unk_15b7b20_set(Unk_15b7b20* self, const Unk_15b7b20_arg1* value) {
    self->field_0 = value->field_0;
}

struct Unk_15b7d30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7d30, field_0, 0x0);

// 0x71015b7d30
u64 Unk_15b7d30_get(const Unk_15b7d30* self) {
    return self->field_0;
}

struct Unk_15b7d40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7d40, field_0, 0x0);

// 0x71015b7d40
u64 Unk_15b7d40_get(const Unk_15b7d40* self) {
    return self->field_0;
}

struct Unk_15b7d50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7d50_arg1, field_0, 0x0);

struct Unk_15b7d50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7d50, field_0, 0x0);

// 0x71015b7d50
bool Unk_15b7d50_check(const Unk_15b7d50* self, const Unk_15b7d50_arg1* value) {
    return self->field_0 > value->field_0;
}

struct Unk_15b7d70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7d70_arg1, field_0, 0x0);

struct Unk_15b7d70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b7d70, field_0, 0x0);

// 0x71015b7d70
bool Unk_15b7d70_check(const Unk_15b7d70* self, const Unk_15b7d70_arg1* value) {
    return self->field_0 <= value->field_0;
}

struct Unk_15b80a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b80a0, field_0, 0x0);

// 0x71015b80a0
u64 Unk_15b80a0_get(const Unk_15b80a0* self) {
    return (self->field_0 >> 0x1a) & 0x3fff;
}

struct Unk_15b80b0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b80b0, field_0, 0x0);

// 0x71015b80b0
u32 Unk_15b80b0_get(const Unk_15b80b0* self) {
    return (self->field_0 >> 0x16) & 0xf;
}

struct Unk_15b80c0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b80c0, field_0, 0x0);

// 0x71015b80c0
u32 Unk_15b80c0_get(const Unk_15b80c0* self) {
    return (self->field_0 >> 0x11) & 0x1f;
}

struct Unk_15b80d0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b80d0, field_0, 0x0);

// 0x71015b80d0
u32 Unk_15b80d0_get(const Unk_15b80d0* self) {
    return (self->field_0 >> 0xc) & 0x1f;
}

struct Unk_15b80e0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b80e0, field_0, 0x0);

// 0x71015b80e0
u32 Unk_15b80e0_get(const Unk_15b80e0* self) {
    return (self->field_0 >> 6) & 0x3f;
}

struct Unk_15b80f0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b80f0, field_0, 0x0);

// 0x71015b80f0
u32 Unk_15b80f0_get(const Unk_15b80f0* self) {
    return self->field_0 & 0x3f;
}

struct Unk_15b8100 {
    u8 _0[0x5];
    u8 field_5;
};
PKMN_OFFSET_ASSERT(Unk_15b8100, field_5, 0x5);

// 0x71015b8100
bool Unk_15b8100_check(const Unk_15b8100* self) {
    return (self->field_5 & 3) == 0;
}

struct Unk_15b8290 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15b8290, field_0, 0x0);

// 0x71015b8290
u64 Unk_15b8290_get(const Unk_15b8290* self) {
    return ((((((((((self->field_0 << 0x22) & 0x3f0000000000) & 0xffc0ffffffffffff) | ((self->field_0 & 0x3f) << 0x30)) & 0xffffffe0ffffffff) | (((self->field_0 >> 0xc) & 0x1f) << 0x20)) & 0xffffffffe0ffffff) | (((self->field_0 >> 0x11) & 0x1f) << 0x18)) | ((self->field_0 >> 6) & 0xf0000)) & 0xffffffffffffc000) | ((self->field_0 >> 0x1a) & 0x3fff);
}

struct Unk_15b8a10 {
    u8 _0[0x2];
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_15b8a10, field_2, 0x2);

// 0x71015b8a10
u32 Unk_15b8a10_get(const Unk_15b8a10* self) {
    return self->field_2 & 0x7ff;
}

struct Unk_15b9280 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_15b9280, field_10, 0x10);

// 0x71015b9280
u64 Unk_15b9280_get(const Unk_15b9280* self) {
    return self->field_10;
}

void Unk_15c0b80();

// 0x71015b9320
void Unk_15b9320_call() {
    Unk_15c0b80();
}

void Unk_15c0c80();

// 0x71015b9330
void Unk_15b9330_call() {
    Unk_15c0c80();
}

struct Unk_15b9c70_60 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_15b9c70_60, field_10, 0x10);

struct Unk_15b9c70 {
    u8 _0[0x60];
    Unk_15b9c70_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_15b9c70, field_60, 0x60);

// 0x71015b9c70
u64 Unk_15b9c70_get(const Unk_15b9c70* self) {
    if (self->field_60 == nullptr) {
        return 0;
    }
    return self->field_60->field_10;
}

struct Unk_15baa10 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15baa10, field_8, 0x8);

// 0x71015baa10
void Unk_15baa10_set(Unk_15baa10* self) {
    self->field_8 = 2;
}

struct Unk_15baaf0 {
    u8 _0[0x51];
    u8 field_51;
};
PKMN_OFFSET_ASSERT(Unk_15baaf0, field_51, 0x51);

// 0x71015baaf0
void Unk_15baaf0_set(Unk_15baaf0* self) {
    self->field_51 = 1;
}

struct Unk_15bacc0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15bacc0, field_8, 0x8);

// 0x71015bacc0
void Unk_15bacc0_set(Unk_15bacc0* self, u32 value) {
    self->field_8 = self->field_8 + value;
}

struct Unk_15bacd0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15bacd0, field_8, 0x8);

// 0x71015bacd0
void Unk_15bacd0_set(Unk_15bacd0* self, u32 value) {
    self->field_8 = (self->field_8 > value ? self->field_8 : value) - value;
}

struct Unk_15bacf0 {
    u8 _0[0x120];
    u8 field_120;
    u8 _121[0x2];
    u8 field_123;
};
PKMN_OFFSET_ASSERT(Unk_15bacf0, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_15bacf0, field_123, 0x123);

// 0x71015bacf0
void Unk_15bacf0_set(Unk_15bacf0* self) {
    self->field_120 = 1;
    self->field_123 = 1;
}

struct Unk_15bad00 {
    u8 _0[0x121];
    u8 field_121;
};
PKMN_OFFSET_ASSERT(Unk_15bad00, field_121, 0x121);

// 0x71015bad00
void Unk_15bad00_set(Unk_15bad00* self) {
    self->field_121 = 0;
}

// 0x71015bb240
void Unk_15bb240_update() {
}

struct Unk_15bb880 {
    u8 _0[0x20];
    u64 field_20;
    u64 field_28;
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_15bb880, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_15bb880, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_15bb880, field_30, 0x30);

// 0x71015bb880
void Unk_15bb880_set(Unk_15bb880* self) {
    self->field_28 = 0;
    self->field_30 = 0;
    self->field_20 = 0;
}

struct Unk_15bbc70_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15bbc70_arg1, field_0, 0x0);

struct Unk_15bbc70 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15bbc70, field_0, 0x0);

// 0x71015bbc70
bool Unk_15bbc70_check(const Unk_15bbc70* self, const Unk_15bbc70_arg1* value) {
    return self->field_0 == value->field_0;
}

struct Unk_15bbc90_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15bbc90_arg1, field_0, 0x0);

struct Unk_15bbc90 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15bbc90, field_0, 0x0);

// 0x71015bbc90
bool Unk_15bbc90_check(const Unk_15bbc90* self, const Unk_15bbc90_arg1* value) {
    return ((self->field_0 >> 0x1f) ^ 1) == value->field_0;
}

struct Unk_15bbd10_arg1 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_15bbd10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_15bbd10_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_15bbd10_arg1, field_10, 0x10);

struct Unk_15bbd10 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_15bbd10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_15bbd10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_15bbd10, field_10, 0x10);

// 0x71015bbd10
void Unk_15bbd10_set(Unk_15bbd10* self, const Unk_15bbd10_arg1* value) {
    self->field_0 = value->field_0;
    self->field_8 = value->field_8;
    self->field_10 = value->field_10;
}

struct Unk_15bd7f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15bd7f0, field_0, 0x0);

// 0x71015bd7f0
u64 Unk_15bd7f0_get(const Unk_15bd7f0* self) {
    return self->field_0;
}

struct Unk_15bd800 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15bd800, field_8, 0x8);

// 0x71015bd800
u64 Unk_15bd800_get(const Unk_15bd800* self) {
    return self->field_8;
}

struct Unk_15bd900 {
    u8 _0[0x8];
    u64 field_8;
    u8 _10[0x8];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_15bd900, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_15bd900, field_18, 0x18);

// 0x71015bd900
u64 Unk_15bd900_get(const Unk_15bd900* self) {
    return self->field_18 - self->field_8;
}

struct Unk_15beca0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15beca0, field_8, 0x8);

// 0x71015beca0
void Unk_15beca0_set(Unk_15beca0* self) {
    self->field_8 = 0;
}

struct Unk_15becb0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15becb0, field_8, 0x8);

void Unk_15becc0();

// 0x71015becb0
void Unk_15becb0_call(Unk_15becb0* self) {
    self->field_8 = 0;
    Unk_15becc0();
}

struct Unk_15beeb0 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15beeb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_15beeb0, field_8, 0x8);

// 0x71015beeb0
void Unk_15beeb0_set(Unk_15beeb0* self, u64 value) {
    self->field_0 = value;
    self->field_8 = 1;
}

struct Unk_15beec0 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15beec0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_15beec0, field_8, 0x8);

// 0x71015beec0
void Unk_15beec0_set(Unk_15beec0* self, u64 value) {
    self->field_0 = value;
    self->field_8 = 6;
}

struct Unk_15bef10 {
    f64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15bef10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_15bef10, field_8, 0x8);

// 0x71015bef10
void Unk_15bef10_set(Unk_15bef10* self, f64 fvalue) {
    self->field_0 = fvalue;
    self->field_8 = 2;
}

struct Unk_15bef20 {
    bool field_0;
    u8 _1[0x7];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15bef20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_15bef20, field_8, 0x8);

// 0x71015bef20
void Unk_15bef20_set(Unk_15bef20* self, bool value) {
    self->field_0 = value;
    self->field_8 = 3;
}

struct Unk_15bf100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15bf100_arg1, field_0, 0x0);

struct Unk_15bf100 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15bf100, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_15bf100, field_8, 0x8);

// 0x71015bf100
void Unk_15bf100_set(Unk_15bf100* self, const Unk_15bf100_arg1* value) {
    self->field_0 = value->field_0;
    self->field_8 = 5;
}

struct Unk_15bf120 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15bf120, field_8, 0x8);

// 0x71015bf120
u32 Unk_15bf120_get(const Unk_15bf120* self) {
    return self->field_8;
}

struct Unk_15bf1b0 {
    u8 field_0;
    u8 _1[0x7];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15bf1b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_15bf1b0, field_8, 0x8);

// 0x71015bf1b0
bool Unk_15bf1b0_check(const Unk_15bf1b0* self) {
    if (self->field_8 != 3) {
        return false;
    }
    return self->field_0 != 0;
}
