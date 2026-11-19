// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u8 Unk_24942d4;

// 0x71017d25f0
u8* Unk_17d25f0_get() {
    return &Unk_24942d4;
}

extern u64 Unk_27fdb08;
extern u64 Unk_27fdb10;
void Unk_17ccb80(u64);

// 0x71017d2890
void Unk_17d2890_call() {
    Unk_17ccb80(Unk_27fdb08);
    Unk_17ccb80(Unk_27fdb10);
    Unk_27fdb08 = 0;
    Unk_27fdb10 = 0;
}

struct Unk_17d57a0 {
    u8 field_0;
    u8 _1[0x7];
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u32 field_30;
};
PKMN_OFFSET_ASSERT(Unk_17d57a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_17d57a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17d57a0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_17d57a0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17d57a0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_17d57a0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_17d57a0, field_30, 0x30);

// 0x71017d57a0
void Unk_17d57a0_set(Unk_17d57a0* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_30 = 0;
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
}

struct Unk_17d5c10 {
    u8 field_0;
    u8 _1[0x17];
    u64 field_18;
    u64 field_20;
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_17d5c10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_17d5c10, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17d5c10, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_17d5c10, field_28, 0x28);

// 0x71017d5c10
void Unk_17d5c10_set(Unk_17d5c10* self) {
    self->field_0 = 0;
    self->field_28 = 0;
    self->field_18 = 0;
    self->field_20 = 0;
}

struct Unk_17d60b0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_17d60b0, field_0, 0x0);

// 0x71017d60b0
void Unk_17d60b0_set(Unk_17d60b0* self) {
    self->field_0 = 0;
}

extern u64 Unk_27fdb20;
struct Unk_17d6bd0_0_a0 {
    u8 _0[0x752];
    u8 field_752;
};
PKMN_OFFSET_ASSERT(Unk_17d6bd0_0_a0, field_752, 0x752);
struct Unk_17d6bd0_0 {
    u8 _0[0xa0];
    Unk_17d6bd0_0_a0* field_a0;
};
PKMN_OFFSET_ASSERT(Unk_17d6bd0_0, field_a0, 0xa0);
struct Unk_17d6bd0 {
    Unk_17d6bd0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_17d6bd0, field_0, 0x0);
void Unk_17d8150(u64, void*);

// 0x71017d6bd0
void Unk_17d6bd0_update(const Unk_17d6bd0* self) {
    if (self->field_0->field_a0->field_752 != 0) {
        return;
    }
    Unk_17d8150(Unk_27fdb20, self->field_0);
}

// 0x71017d6d30
u32 Unk_17d6d30_get() {
    return 1;
}

extern u64 Unk_27fdb28;
struct Unk_17d9ec0_0_a0 {
    u8 _0[0x752];
    u8 field_752;
};
PKMN_OFFSET_ASSERT(Unk_17d9ec0_0_a0, field_752, 0x752);
struct Unk_17d9ec0_0 {
    u8 _0[0xa0];
    Unk_17d9ec0_0_a0* field_a0;
};
PKMN_OFFSET_ASSERT(Unk_17d9ec0_0, field_a0, 0xa0);
struct Unk_17d9ec0 {
    Unk_17d9ec0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_17d9ec0, field_0, 0x0);
void Unk_17dca00(u64, void*);

// 0x71017d9ec0
void Unk_17d9ec0_update(const Unk_17d9ec0* self) {
    if (self->field_0->field_a0->field_752 != 0) {
        return;
    }
    Unk_17dca00(Unk_27fdb28, self->field_0);
}

struct Unk_17de500_arg1 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_17de500_arg1, field_98, 0x98);

struct Unk_17de500 {
    u8 _0[0x8c0];
    u64 field_8c0;
};
PKMN_OFFSET_ASSERT(Unk_17de500, field_8c0, 0x8c0);

// 0x71017de500
void Unk_17de500_set(const Unk_17de500* self, Unk_17de500_arg1* value) {
    value->field_98 = self->field_8c0;
}

struct Unk_17de510 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_17de510, field_80, 0x80);

void Unk_17c91d0(void*);

// 0x71017de510
void Unk_17de510_call(Unk_17de510* self, void* value) {
    Unk_17c91d0(value);
    self->field_80 = self->field_80 + 1;
}

void Unk_17de540(void*, void*, u64, u64, u64, u32, u64, u32);

// 0x71017de780
void Unk_17de780_call(void* self, void* value, u64 arg2, u64 arg3, u64 arg4, u64 arg5, bool arg6) {
    Unk_17de540(self, value, arg2, arg3, arg4, 0, arg5, arg6);
}

struct Unk_17df790 {
    u8 _0[0x1188];
    u32 field_1188;
    u8 _118c[0x1c];
    u64 field_11a8;
};
PKMN_OFFSET_ASSERT(Unk_17df790, field_1188, 0x1188);
PKMN_OFFSET_ASSERT(Unk_17df790, field_11a8, 0x11a8);

// 0x71017df790
void Unk_17df790_set(Unk_17df790* self, u32 value, u64 arg2) {
    self->field_1188 = value;
    self->field_11a8 = arg2;
}

void Unk_17d2530(u64, u64);

// 0x71017dfdb0
void Unk_17dfdb0_call(void* /*unused*/, u64 value, u64 arg2) {
    Unk_17d2530(value, arg2);
}

void Unk_17d2550(u64, u64);

// 0x71017dfdc0
void Unk_17dfdc0_call(void* /*unused*/, u64 value, u64 arg2) {
    Unk_17d2550(value, arg2);
}

void Unk_17e89f0(u64, u64);

// 0x71017dfdd0
void Unk_17dfdd0_call(void* /*unused*/, u64 value, u64 arg2) {
    Unk_17e89f0(value, arg2);
}

void Unk_17e8a70(u64, u64);

// 0x71017dfde0
void Unk_17dfde0_call(void* /*unused*/, u64 value, u64 arg2) {
    Unk_17e8a70(value, arg2);
}

// 0x71017e5360
u32 Unk_17e5360_get() {
    return 1;
}

struct Unk_17e5370 {
    void* field_0;
    void* field_8;
    u32 field_10;
    u8 _14[0x4];
    u64 field_18;
    void* field_20;
};
PKMN_OFFSET_ASSERT(Unk_17e5370, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_17e5370, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17e5370, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_17e5370, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17e5370, field_20, 0x20);

void Unk_17e53b0(void*, void*, u32, u64, void*);

// 0x71017e5370
u32 Unk_17e5370_call(const Unk_17e5370* self) {
    Unk_17e53b0(self->field_0, self->field_8, self->field_10, self->field_18, self->field_20);
    return 1;
}

// 0x71017e53a0
u32 Unk_17e53a0_get() {
    return 1;
}

extern u64 Unk_27fdb30;
struct Unk_17e5ca0_8_a0 {
    u8 _0[0x752];
    u8 field_752;
};
PKMN_OFFSET_ASSERT(Unk_17e5ca0_8_a0, field_752, 0x752);

struct Unk_17e5ca0_8 {
    u8 _0[0xa0];
    Unk_17e5ca0_8_a0* field_a0;
};
PKMN_OFFSET_ASSERT(Unk_17e5ca0_8, field_a0, 0xa0);

struct Unk_17e5ca0 {
    void* field_0;
    Unk_17e5ca0_8* field_8;
    u32 field_10;
    u8 _14[0x4];
    u64 field_18;
    void* field_20;
};
PKMN_OFFSET_ASSERT(Unk_17e5ca0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_17e5ca0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17e5ca0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_17e5ca0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17e5ca0, field_20, 0x20);

void Unk_17e7e40(u64, void*, void*, u32, u64, void*);

// 0x71017e5ca0
u32 Unk_17e5ca0_call(const Unk_17e5ca0* self) {
    if (self->field_8->field_a0->field_752 != 0) {
        return 0;
    }
    Unk_17e7e40(Unk_27fdb30, self->field_0, self->field_8, self->field_10, self->field_18, self->field_20);
    return 1;
}

struct Unk_17e8260 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u8 _28[0x8];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_17e8260, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_17e8260, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17e8260, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_17e8260, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17e8260, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_17e8260, field_30, 0x30);

// 0x71017e8260
void Unk_17e8260_set(Unk_17e8260* self) {
    self->field_0 = 0;
    self->field_30 = 0;
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
}

// 0x71017e84c0
void Unk_17e84c0_update(u64 /*unused*/) {
}

struct Unk_17e84d0 {
    u32 field_0;
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_17e84d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_17e84d0, field_4, 0x4);

u32 Unk_178f1e0(void*, u32, u32, void*);

// 0x71017e84d0
u32 Unk_17e84d0_call(Unk_17e84d0* self, void* value, void* arg2) {
    u32 r0 = Unk_178f1e0(value, 0, 2, arg2);
    self->field_4 = r0;
    u32 r1 = Unk_178f1e0(value, 4, 2, arg2);
    self->field_0 = r1;
    return 1;
}

struct Unk_17e8b00 {
    u32 field_0;
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_17e8b00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_17e8b00, field_4, 0x4);

u32 Unk_178f1e0(void*, u32, u32, void*);

// 0x71017e8b00
void Unk_17e8b00_call(Unk_17e8b00* self, void* value, void* arg2) {
    u32 r0 = Unk_178f1e0(value, 0, 3, arg2);
    self->field_0 = r0;
    u32 r1 = Unk_178f1e0(value, 4, 3, arg2);
    self->field_4 = r1;
}

struct Unk_17e8c90_arg2 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64);
};
struct Unk_17e8c90 {
    u8 _0[0x50];
    u8 field_50;
    u8 _51[0x7];
    u8 field_58;
    u8 _59[0x11f];
    u64 field_178;
};
PKMN_OFFSET_ASSERT(Unk_17e8c90, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_17e8c90, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_17e8c90, field_178, 0x178);
struct Unk_1787ac0_Buffer;
struct Unk_1791080_Device;
void Unk_1787bb0(Unk_1787ac0_Buffer*, Unk_1791080_Device*);
struct Unk_1789c10_MemoryPool;
void Unk_1789ca0(Unk_1789c10_MemoryPool*, Unk_1791080_Device*);

// 0x71017e8c90
void Unk_17e8c90_call(Unk_17e8c90* self, u64 value, Unk_17e8c90_arg2* arg2) {
    if (self->field_50 != 0) {
        Unk_1787bb0(reinterpret_cast<Unk_1787ac0_Buffer*>(self), reinterpret_cast<Unk_1791080_Device*>(value));
        Unk_1789ca0(reinterpret_cast<Unk_1789c10_MemoryPool*>(&self->field_58), reinterpret_cast<Unk_1791080_Device*>(value));
        if (self->field_178 != 0) {
            arg2->vf3(self->field_178);
            self->field_178 = 0;
            self->field_50 = 0;
            return;
        }
        self->field_50 = 0;
        return;
    }
}

struct Unk_17e8d00 {
    u8 _0[0x20];
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u64 field_50;
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_17e8d00, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_17e8d00, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_17e8d00, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_17e8d00, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_17e8d00, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_17e8d00, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_17e8d00, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_17e8d00, field_58, 0x58);

// 0x71017e8d00
void Unk_17e8d00_set(Unk_17e8d00* self) {
    self->field_50 = 0;
    self->field_58 = 0;
    self->field_40 = 0;
    self->field_48 = 0;
    self->field_30 = 0;
    self->field_38 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
}

struct Unk_17e8e80 {
    u64 field_0;
    u8 _8[0x8];
    void* field_10;
};
PKMN_OFFSET_ASSERT(Unk_17e8e80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_17e8e80, field_10, 0x10);

void Unk_17c9f80(void*, u64, u32);

// 0x71017e8e80
void Unk_17e8e80_call(Unk_17e8e80* self) {
    if (self->field_0 != 0) {
        Unk_17c9f80(self->field_10, self->field_0, 0);
        self->field_0 = 0;
    }
}

// 0x71017e8ed0
void Unk_17e8ed0_update(u64 /*unused*/) {
}
