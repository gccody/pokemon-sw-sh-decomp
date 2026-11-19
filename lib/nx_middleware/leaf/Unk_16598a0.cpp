// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71016598a0
u32 Unk_16598a0_get() {
    return 0x10;
}

// 0x7101659bf0
u32 Unk_1659bf0_get() {
    return 0x10;
}

struct Unk_165af60 {
    u64 field_0;
    u8 field_8;
    u8 _9[0x3];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_165af60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_165af60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_165af60, field_c, 0xc);

// 0x710165af60
void Unk_165af60_set(Unk_165af60* self) {
    self->field_0 = 0xffffffff;
    self->field_8 = 0;
    self->field_c = 0xffffffff;
}

// 0x710165af80
void Unk_165af80_update(u64 /*unused*/) {
}

void Unk_165b490(void*, u64, u64, void*, u64, void*, u32);

// 0x710165b480
void Unk_165b480_call(void* self, u64 value, u64 arg2, void* arg3, u64 arg4, void* arg5) {
    Unk_165b490(self, value, arg2, arg3, arg4, arg5, 0);
}

// 0x710165ba30
void Unk_165ba30_update(void* /*unused*/) {
}

// 0x710165ba40
void Unk_165ba40_update(void* /*unused*/, void* /*unused*/) {
}

struct Unk_165be70 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_165be70, field_8, 0x8);

// 0x710165be70
u64 Unk_165be70_get(const Unk_165be70* self) {
    return self->field_8;
}

struct Unk_165be80 {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_165be80, field_14, 0x14);

// 0x710165be80
u32 Unk_165be80_get(const Unk_165be80* self) {
    return self->field_14;
}

struct Unk_165be90 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_165be90, field_8, 0x8);

// 0x710165be90
u64 Unk_165be90_get(const Unk_165be90* self) {
    return self->field_8;
}

struct Unk_165c180 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_165c180, field_18, 0x18);

// 0x710165c180
u32 Unk_165c180_get(const Unk_165c180* self) {
    return self->field_18;
}

struct Unk_165c600 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_165c600, field_0, 0x0);

namespace nn { namespace os { u64 GetSystemTick(); } }

// 0x710165c600
void Unk_165c600_call(Unk_165c600* self) {
    u64 r0 = nn::os::GetSystemTick();
    self->field_0 = r0;
}

struct Unk_165c9b0 {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
};
PKMN_OFFSET_ASSERT(Unk_165c9b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_165c9b0, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_165c9b0, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_165c9b0, field_3, 0x3);

// 0x710165c9b0
void Unk_165c9b0_set(Unk_165c9b0* self, u32 value) {
    self->field_0 = value >> 0x18;
    self->field_1 = value >> 0x10;
    self->field_2 = value >> 8;
    self->field_3 = value;
}

struct Unk_165c9e0 {
    u8 field_0;
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_165c9e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_165c9e0, field_1, 0x1);

// 0x710165c9e0
void Unk_165c9e0_set(Unk_165c9e0* self, u32 value) {
    self->field_0 = value >> 8;
    self->field_1 = value;
}

struct Unk_165ca00 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_165ca00, field_0, 0x0);

// 0x710165ca00
void Unk_165ca00_set(Unk_165ca00* self, u8 value) {
    self->field_0 = value;
}

struct Unk_165ca10 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_165ca10, field_0, 0x0);

// 0x710165ca10
u8 Unk_165ca10_get(const Unk_165ca10* self) {
    return self->field_0;
}

struct Unk_165d900 {
    u8 _0[0x20];
    u8 field_20;
    u8 _21[0x67];
    u8 field_88;
    u8 _89[0x67];
    u8 field_f0;
    u8 _f1[0x67];
    u8 field_158;
    u8 _159[0x67];
    u8 field_1c0;
    u8 _1c1[0x67];
    u8 field_228;
    u8 _229[0x67];
    u8 field_290;
    u8 _291[0x67];
    u8 field_2f8;
    u8 _2f9[0x67];
    u8 field_360;
    u8 _361[0x67];
    u8 field_3c8;
    u8 _3c9[0x67];
    u8 field_430;
    u8 _431[0x67];
    u8 field_498;
};
PKMN_OFFSET_ASSERT(Unk_165d900, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_165d900, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_165d900, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_165d900, field_158, 0x158);
PKMN_OFFSET_ASSERT(Unk_165d900, field_1c0, 0x1c0);
PKMN_OFFSET_ASSERT(Unk_165d900, field_228, 0x228);
PKMN_OFFSET_ASSERT(Unk_165d900, field_290, 0x290);
PKMN_OFFSET_ASSERT(Unk_165d900, field_2f8, 0x2f8);
PKMN_OFFSET_ASSERT(Unk_165d900, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_165d900, field_3c8, 0x3c8);
PKMN_OFFSET_ASSERT(Unk_165d900, field_430, 0x430);
PKMN_OFFSET_ASSERT(Unk_165d900, field_498, 0x498);

// 0x710165d900
void Unk_165d900_set(Unk_165d900* self) {
    self->field_20 = 1;
    self->field_88 = 1;
    self->field_f0 = 1;
    self->field_158 = 1;
    self->field_1c0 = 1;
    self->field_228 = 1;
    self->field_290 = 1;
    self->field_2f8 = 1;
    self->field_360 = 1;
    self->field_3c8 = 1;
    self->field_430 = 1;
    self->field_498 = 1;
}

// 0x710165da10
void Unk_165da10_update(u64 /*unused*/) {
}

// 0x710165dae0
void Unk_165dae0_update(void* /*unused*/) {
}

struct Unk_165dba0 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_165dba0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_165dba0, field_8, 0x8);

// 0x710165dba0
void Unk_165dba0_set(Unk_165dba0* self) {
    self->field_0 = 0;
    self->field_8 = 0;
}

struct Unk_165ffd0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_165ffd0, field_8, 0x8);

// 0x710165ffd0
void Unk_165ffd0_set(Unk_165ffd0* self) {
    self->field_8 = 0;
}

// 0x7101660970
void Unk_1660970_update(u64 /*unused*/, void* /*unused*/, u32 /*unused*/) {
}

// 0x7101660a30
void Unk_1660a30_update(u64 /*unused*/) {
}

struct Unk_1660a40 {
    u8 _0[0x20];
    u64 field_20;
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_1660a40, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1660a40, field_28, 0x28);

// 0x7101660a40
void Unk_1660a40_set(Unk_1660a40* self, u64 value, u64 arg2) {
    self->field_20 = value;
    self->field_28 = arg2;
}

struct Unk_1660cb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1660cb0, field_0, 0x0);

// 0x7101660cb0
void Unk_1660cb0_set(Unk_1660cb0* self) {
    self->field_0 = 0;
}

// 0x7101661520
void Unk_1661520_update(u64 /*unused*/) {
}

struct Unk_16615e0 {
    u8 _0[0x70];
    u64 field_70;
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_16615e0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_16615e0, field_78, 0x78);

// 0x71016615e0
void Unk_16615e0_set(Unk_16615e0* self) {
    self->field_70 = 0;
    self->field_78 = 0;
}

extern u8 Unk_27fb088 __attribute__((visibility("hidden")));

// 0x71016619b0
u8 Unk_16619b0_get() {
    return Unk_27fb088;
}

extern u8 Unk_27fb089 __attribute__((visibility("hidden")));

// 0x7101661a70
u8 Unk_1661a70_get() {
    return Unk_27fb089;
}

struct Unk_1661d70 {
    u8 _0[0x10];
    u32 field_10;
    u8 _14[0x1a4];
    u32 field_1b8;
};
PKMN_OFFSET_ASSERT(Unk_1661d70, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1661d70, field_1b8, 0x1b8);

// 0x7101661d70
void Unk_1661d70_set(Unk_1661d70* self, u32 value) {
    self->field_10 = value;
    self->field_1b8 = self->field_1b8 | 1;
}

struct Unk_1661d90 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1661d90, field_10, 0x10);

// 0x7101661d90
u32 Unk_1661d90_get(const Unk_1661d90* self) {
    return self->field_10;
}

struct Unk_1661da0 {
    u8 _0[0x1b8];
    u32 field_1b8;
};
PKMN_OFFSET_ASSERT(Unk_1661da0, field_1b8, 0x1b8);

// 0x7101661da0
u32 Unk_1661da0_get(const Unk_1661da0* self) {
    return self->field_1b8 & 1;
}

struct Unk_1661db0 {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1661db0, field_14, 0x14);

// 0x7101661db0
u32 Unk_1661db0_get(const Unk_1661db0* self) {
    return self->field_14;
}

struct Unk_1661dc0 {
    u8 _0[0x1b8];
    u8 field_1b8;
};
PKMN_OFFSET_ASSERT(Unk_1661dc0, field_1b8, 0x1b8);

// 0x7101661dc0
u32 Unk_1661dc0_get(const Unk_1661dc0* self) {
    return (self->field_1b8 >> 1) & 1;
}

struct Unk_1661e80 {
    u8 _0[0x1b8];
    u32 field_1b8;
};
PKMN_OFFSET_ASSERT(Unk_1661e80, field_1b8, 0x1b8);

// 0x7101661e80
bool Unk_1661e80_check(const Unk_1661e80* self, u32 value) {
    return (self->field_1b8 & (1 << (value + 2))) != 0;
}

struct Unk_1661ea0 {
    u8 _0[0x1b4];
    bool field_1b4;
    u8 _1b5[0x3];
    u32 field_1b8;
};
PKMN_OFFSET_ASSERT(Unk_1661ea0, field_1b4, 0x1b4);
PKMN_OFFSET_ASSERT(Unk_1661ea0, field_1b8, 0x1b8);

// 0x7101661ea0
void Unk_1661ea0_set(Unk_1661ea0* self, bool value) {
    self->field_1b4 = value;
    self->field_1b8 = self->field_1b8 | 0x200;
}

struct Unk_1661ec0 {
    u8 _0[0x1b4];
    u8 field_1b4;
};
PKMN_OFFSET_ASSERT(Unk_1661ec0, field_1b4, 0x1b4);

// 0x7101661ec0
u8 Unk_1661ec0_get(const Unk_1661ec0* self) {
    return self->field_1b4;
}

struct Unk_1661ed0 {
    u8 _0[0x1b9];
    u8 field_1b9;
};
PKMN_OFFSET_ASSERT(Unk_1661ed0, field_1b9, 0x1b9);

// 0x7101661ed0
u32 Unk_1661ed0_get(const Unk_1661ed0* self) {
    return (self->field_1b9 >> 1) & 1;
}

extern u64 Unk_27fb090;

// 0x71016620c0
u64 Unk_16620c0_get() {
    return Unk_27fb090;
}

struct Unk_1662140 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1662140, field_0, 0x0);

void Unk_16710b0(void*);

// 0x7101662140
void Unk_1662140_call(const Unk_1662140* self) {
    if (self->field_0 != nullptr) {
        Unk_16710b0(self->field_0);
    }
}

struct Unk_16621d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_16621d0, field_0, 0x0);

// 0x71016621d0
u64 Unk_16621d0_get(const Unk_16621d0* self) {
    return self->field_0;
}

struct Unk_1662300 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1662300, field_0, 0x0);

void Unk_1672020(void*);

// 0x7101662300
void Unk_1662300_call(const Unk_1662300* self) {
    if (self->field_0 != nullptr) {
        Unk_1672020(self->field_0);
    }
}

struct Unk_1662310 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1662310, field_0, 0x0);

void Unk_1672060(void*);

// 0x7101662310
void Unk_1662310_call(const Unk_1662310* self) {
    Unk_1672060(self->field_0);
}

struct Unk_1662320 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1662320, field_0, 0x0);

void Unk_16727e0(void*);

// 0x7101662320
void Unk_1662320_call(const Unk_1662320* self) {
    Unk_16727e0(self->field_0);
}

struct Unk_1662350_0 {
    u8 _0[0x98];
    u8 field_98;
};
PKMN_OFFSET_ASSERT(Unk_1662350_0, field_98, 0x98);

struct Unk_1662350 {
    Unk_1662350_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1662350, field_0, 0x0);

// 0x7101662350
u8 Unk_1662350_get(const Unk_1662350* self) {
    return self->field_0->field_98;
}

struct Unk_1662360 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1662360, field_0, 0x0);

void Unk_16728b0(u64);

// 0x7101662360
void Unk_1662360_call(const Unk_1662360* self) {
    Unk_16728b0(self->field_0);
}

struct Unk_1662390 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1662390, field_0, 0x0);

void Unk_1674d00(void*);

// 0x7101662390
void Unk_1662390_call(const Unk_1662390* self) {
    Unk_1674d00(self->field_0);
}

struct Unk_1663d40 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_1663d40, field_b0, 0xb0);

// 0x7101663d40
void Unk_1663d40_set(Unk_1663d40* self, u64 value) {
    self->field_b0 = value;
}

struct Unk_1663d50 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_1663d50, field_b0, 0xb0);

// 0x7101663d50
void Unk_1663d50_set(Unk_1663d50* self) {
    self->field_b0 = 0;
}

struct Unk_1667420 {
    u8 _0[0x16c8];
    u32 field_16c8;
};
PKMN_OFFSET_ASSERT(Unk_1667420, field_16c8, 0x16c8);

// 0x7101667420
u32 Unk_1667420_get(const Unk_1667420* self) {
    return self->field_16c8;
}

struct Unk_1667430 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1667430, field_18, 0x18);

// 0x7101667430
const u8* Unk_1667430_get(const Unk_1667430* self) {
    return &self->field_18;
}

struct Unk_1667440 {
    u8 _0[0x900];
    u8 field_900;
};
PKMN_OFFSET_ASSERT(Unk_1667440, field_900, 0x900);

// 0x7101667440
const u8* Unk_1667440_get(const Unk_1667440* self) {
    return &self->field_900;
}

struct Unk_1667450 {
    u8 _0[0x16c0];
    u64 field_16c0;
};
PKMN_OFFSET_ASSERT(Unk_1667450, field_16c0, 0x16c0);

// 0x7101667450
u64 Unk_1667450_get(const Unk_1667450* self) {
    return self->field_16c0;
}

struct Unk_1667490 {
    u8 _0[0x16cc];
    u32 field_16cc;
};
PKMN_OFFSET_ASSERT(Unk_1667490, field_16cc, 0x16cc);

// 0x7101667490
void Unk_1667490_set(Unk_1667490* self, u32 value) {
    self->field_16cc = value;
}

struct Unk_16674a0 {
    u8 _0[0x16d0];
    u32 field_16d0;
};
PKMN_OFFSET_ASSERT(Unk_16674a0, field_16d0, 0x16d0);

// 0x71016674a0
void Unk_16674a0_set(Unk_16674a0* self, u32 value) {
    self->field_16d0 = value;
}

struct Unk_166d0f0 {
    u8 _0[0x2b0];
    u32 field_2b0;
};
PKMN_OFFSET_ASSERT(Unk_166d0f0, field_2b0, 0x2b0);

// 0x710166d0f0
void Unk_166d0f0_set(Unk_166d0f0* self) {
    self->field_2b0 = 3;
}

struct Unk_166e080 {
    u8 _0[0x220];
    u64 field_220;
};
PKMN_OFFSET_ASSERT(Unk_166e080, field_220, 0x220);

// 0x710166e080
void Unk_166e080_set(Unk_166e080* self, u64 value) {
    self->field_220 = value;
}

struct Unk_166e090 {
    u8 _0[0x220];
    u64 field_220;
};
PKMN_OFFSET_ASSERT(Unk_166e090, field_220, 0x220);

// 0x710166e090
void Unk_166e090_set(Unk_166e090* self) {
    self->field_220 = 0;
}

struct Unk_16711e0 {
    u8 _0[0x134c];
    u32 field_134c;
};
PKMN_OFFSET_ASSERT(Unk_16711e0, field_134c, 0x134c);

// 0x71016711e0
bool Unk_16711e0_check(const Unk_16711e0* self) {
    return self->field_134c != 0;
}

struct Unk_1672890 {
    u8 _0[0xc8];
    void* field_c8;
};
PKMN_OFFSET_ASSERT(Unk_1672890, field_c8, 0xc8);

void Unk_1676830(void*, u32);

// 0x7101672890
void Unk_1672890_call(const Unk_1672890* self, u32 value) {
    Unk_1676830(self->field_c8, value);
}

struct Unk_16735f0 {
    u8 _0[0x12a0];
    u32 field_12a0;
};
PKMN_OFFSET_ASSERT(Unk_16735f0, field_12a0, 0x12a0);

// 0x71016735f0
bool Unk_16735f0_check(const Unk_16735f0* self) {
    return self->field_12a0 >= 2 && self->field_12a0 <= 4;
}

struct Unk_1673660 {
    u8 _0[0x1310];
    u32 field_1310;
};
PKMN_OFFSET_ASSERT(Unk_1673660, field_1310, 0x1310);

// 0x7101673660
bool Unk_1673660_check(const Unk_1673660* self) {
    return self->field_1310 >= 2 && self->field_1310 <= 4;
}

struct Unk_1673e40 {
    u8 _0[0x12d8];
    u32 field_12d8;
};
PKMN_OFFSET_ASSERT(Unk_1673e40, field_12d8, 0x12d8);

// 0x7101673e40
bool Unk_1673e40_check(const Unk_1673e40* self) {
    return self->field_12d8 >= 2 && self->field_12d8 <= 4;
}

struct Unk_16768b0 {
    u8 _0[0xd88];
    u32 field_d88;
};
PKMN_OFFSET_ASSERT(Unk_16768b0, field_d88, 0xd88);

// 0x71016768b0
bool Unk_16768b0_check(const Unk_16768b0* self) {
    return self->field_d88 >= 2 && self->field_d88 <= 4;
}

struct Unk_1678240 {
    u8 _0[0x3a];
    u16 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_1678240, field_3a, 0x3a);

// 0x7101678240
u16 Unk_1678240_get(const Unk_1678240* self) {
    return self->field_3a;
}

struct Unk_16782c0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_16782c0, field_10, 0x10);

// 0x71016782c0
void Unk_16782c0_set(Unk_16782c0* self, u32 value) {
    self->field_10 = value;
}

struct Unk_16782d0 {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_16782d0, field_14, 0x14);

// 0x71016782d0
void Unk_16782d0_set(Unk_16782d0* self, u32 value) {
    self->field_14 = value;
}

struct Unk_16782e0 {
    u8 _0[0x18];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16782e0, field_18, 0x18);

// 0x71016782e0
void Unk_16782e0_set(Unk_16782e0* self, u16 value) {
    self->field_18 = value;
}

struct Unk_16782f0 {
    u8 _0[0x1a];
    u16 field_1a;
};
PKMN_OFFSET_ASSERT(Unk_16782f0, field_1a, 0x1a);

// 0x71016782f0
void Unk_16782f0_set(Unk_16782f0* self, u16 value) {
    self->field_1a = value;
}

struct Unk_1678300 {
    u8 _0[0x1c];
    u16 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_1678300, field_1c, 0x1c);

// 0x7101678300
void Unk_1678300_set(Unk_1678300* self, u16 value) {
    self->field_1c = value;
}

struct Unk_1678310 {
    u8 _0[0x1e];
    bool field_1e;
};
PKMN_OFFSET_ASSERT(Unk_1678310, field_1e, 0x1e);

// 0x7101678310
void Unk_1678310_set(Unk_1678310* self, bool value) {
    self->field_1e = value;
}

struct Unk_1678560 {
    u8 _0[0x1e0];
    u8 field_1e0;
};
PKMN_OFFSET_ASSERT(Unk_1678560, field_1e0, 0x1e0);

// 0x7101678560
const u8* Unk_1678560_get(const Unk_1678560* self) {
    return &self->field_1e0;
}

struct Unk_1678570 {
    u8 _0[0x3a];
    u16 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_1678570, field_3a, 0x3a);

// 0x7101678570
void Unk_1678570_set(Unk_1678570* self, u16 value) {
    self->field_3a = value;
}

struct Unk_1678580 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_1678580, field_38, 0x38);

// 0x7101678580
void Unk_1678580_set(Unk_1678580* self, u8 value) {
    self->field_38 = value;
}

struct Unk_1678590 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_1678590, field_38, 0x38);

// 0x7101678590
u8 Unk_1678590_get(const Unk_1678590* self) {
    return self->field_38;
}

struct Unk_16785a0 {
    u8 _0[0x39];
    u8 field_39;
};
PKMN_OFFSET_ASSERT(Unk_16785a0, field_39, 0x39);

// 0x71016785a0
void Unk_16785a0_set(Unk_16785a0* self, u8 value) {
    self->field_39 = value;
}

struct Unk_16785b0 {
    u8 _0[0x39];
    u8 field_39;
};
PKMN_OFFSET_ASSERT(Unk_16785b0, field_39, 0x39);

// 0x71016785b0
u8 Unk_16785b0_get(const Unk_16785b0* self) {
    return self->field_39;
}

struct Unk_16785c0 {
    u8 _0[0x3c];
    u8 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_16785c0, field_3c, 0x3c);

// 0x71016785c0
const u8* Unk_16785c0_get(const Unk_16785c0* self) {
    return &self->field_3c;
}

struct Unk_1679ec0 {
    u8 _0[0x25a];
    u16 field_25a;
    u16 field_25c;
    u8 _25e[0x2];
    u32 field_260;
};
PKMN_OFFSET_ASSERT(Unk_1679ec0, field_25a, 0x25a);
PKMN_OFFSET_ASSERT(Unk_1679ec0, field_25c, 0x25c);
PKMN_OFFSET_ASSERT(Unk_1679ec0, field_260, 0x260);

// 0x7101679ec0
void Unk_1679ec0_set(Unk_1679ec0* self, u16 value) {
    self->field_25a = value;
    self->field_25c = value;
    self->field_260 = self->field_260 | 2;
}

struct Unk_1679ee0 {
    u8 _0[0x20];
    u32 field_20;
    u8 _24[0x23c];
    u32 field_260;
};
PKMN_OFFSET_ASSERT(Unk_1679ee0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1679ee0, field_260, 0x260);

// 0x7101679ee0
void Unk_1679ee0_set(Unk_1679ee0* self, u32 value) {
    self->field_20 = value;
    self->field_260 = self->field_260 | 0x10;
}

struct Unk_167b070 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_167b070, field_60, 0x60);

// 0x710167b070
void Unk_167b070_set(Unk_167b070* self, u64 value) {
    self->field_60 = value;
}

struct Unk_167b080 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_167b080, field_60, 0x60);

// 0x710167b080
u64 Unk_167b080_get(const Unk_167b080* self) {
    return self->field_60;
}

struct Unk_167b0c0 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_167b0c0, field_18, 0x18);

// 0x710167b0c0
const u8* Unk_167b0c0_get(const Unk_167b0c0* self) {
    return &self->field_18;
}

struct Unk_167b940 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_167b940, field_c, 0xc);

// 0x710167b940
u16 Unk_167b940_get(const Unk_167b940* self) {
    return self->field_c;
}

struct Unk_167b950 {
    u8 _0[0xe];
    u16 field_e;
};
PKMN_OFFSET_ASSERT(Unk_167b950, field_e, 0xe);

// 0x710167b950
u16 Unk_167b950_get(const Unk_167b950* self) {
    return self->field_e;
}

struct Unk_167b960 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_167b960, field_10, 0x10);

// 0x710167b960
u32 Unk_167b960_get(const Unk_167b960* self) {
    return self->field_10;
}

extern u8 Unk_27fb0a0 __attribute__((visibility("hidden")));

// 0x710167bd20
u8 Unk_167bd20_get() {
    return Unk_27fb0a0;
}

extern u8 Unk_27fb0a1 __attribute__((visibility("hidden")));

// 0x710167bde0
u8 Unk_167bde0_get() {
    return Unk_27fb0a1;
}

struct Unk_27fb0a8_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u8 _c[0x4];
    u32 field_10;
    u16 field_14;
    u8 _16[0x2];
    u32 field_18;
    u16 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_27fb0a8_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27fb0a8_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27fb0a8_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27fb0a8_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27fb0a8_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27fb0a8_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_27fb0a8_Data, field_1c, 0x1c);

extern Unk_27fb0a8_Data Unk_27fb0a8 __attribute__((visibility("hidden")));
namespace nn { namespace ldn { u64 MakeIpv4Address(u8, u8, u8, u8); } }

// 0x710167c1c0
void Unk_167c1c0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27fb0a8.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27fb0a8.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27fb0a8.field_1c = 0xffff;
    Unk_27fb0a8.field_14 = 0;
    Unk_27fb0a8.field_8 = r2;
    Unk_27fb0a8.field_10 = 0;
    Unk_27fb0a8.field_18 = 0xffffffff;
}
