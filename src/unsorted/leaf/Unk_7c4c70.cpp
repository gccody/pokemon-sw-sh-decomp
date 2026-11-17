// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7c4c70_88 {
    u8 _0[0x3a4];
    u8 field_3a4;
};
PKMN_OFFSET_ASSERT(Unk_7c4c70_88, field_3a4, 0x3a4);

struct Unk_7c4c70 {
    u8 _0[0x88];
    Unk_7c4c70_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7c4c70, field_88, 0x88);

// 0x71007c4c70
u8 Unk_7c4c70_get(const Unk_7c4c70* self) {
    return self->field_88->field_3a4;
}

// 0x71007c5070
void Unk_7c5070() {}

struct Unk_7c5520_88 {
    u8 _0[0x3a7];
    u8 field_3a7;
};
PKMN_OFFSET_ASSERT(Unk_7c5520_88, field_3a7, 0x3a7);

struct Unk_7c5520 {
    u8 _0[0x88];
    Unk_7c5520_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7c5520, field_88, 0x88);

// 0x71007c5520
bool Unk_7c5520_check(const Unk_7c5520* self) {
    return self->field_88->field_3a7 == 1;
}

struct Unk_7c56e0_88 {
    u8 _0[0xa60];
    u32 field_a60;
};
PKMN_OFFSET_ASSERT(Unk_7c56e0_88, field_a60, 0xa60);

struct Unk_7c56e0 {
    u8 _0[0x88];
    Unk_7c56e0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7c56e0, field_88, 0x88);

// 0x71007c56e0
bool Unk_7c56e0_check(const Unk_7c56e0* self, u32 value) {
    return (self->field_88->field_a60 & value) != 0;
}

struct Unk_7c58b0_88 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7c58b0_88, field_0, 0x0);

struct Unk_7c58b0 {
    u8 _0[0x88];
    Unk_7c58b0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7c58b0, field_88, 0x88);

// 0x71007c58b0
u32 Unk_7c58b0_get(const Unk_7c58b0* self) {
    return self->field_88->field_0;
}

struct Unk_7c5910_88 {
    u8 _0[0x3a5];
    u8 field_3a5;
};
PKMN_OFFSET_ASSERT(Unk_7c5910_88, field_3a5, 0x3a5);

struct Unk_7c5910 {
    u8 _0[0x88];
    Unk_7c5910_88* field_88;
    u8 _90[0xc0];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7c5910, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_7c5910, field_150, 0x150);

void Unk_7faf80(u32, u8, u32);

// 0x71007c5910
void Unk_7c5910_call(const Unk_7c5910* self, u32 value) {
    Unk_7faf80(self->field_150, self->field_88->field_3a5, value & 0xff);
}

struct Unk_7ca070 {
    u8 _0[0x166];
    u16 field_166;
};
PKMN_OFFSET_ASSERT(Unk_7ca070, field_166, 0x166);

// 0x71007ca070
u16 Unk_7ca070_getField166(const Unk_7ca070* self) {
    return self->field_166;
}

struct Unk_7ca1c0 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7ca1c0, field_150, 0x150);

// 0x71007ca1c0
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self) {
    return self->field_150;
}

struct Unk_7ca1d0_88 {
    u8 _0[0x3a5];
    u8 field_3a5;
};
PKMN_OFFSET_ASSERT(Unk_7ca1d0_88, field_3a5, 0x3a5);

struct Unk_7ca1d0 {
    u8 _0[0x88];
    Unk_7ca1d0_88* field_88;
    u8 _90[0xc0];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7ca1d0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_7ca1d0, field_150, 0x150);

void Unk_7facf0(u32, u8);

// 0x71007ca1d0
void Unk_7ca1d0_call(const Unk_7ca1d0* self) {
    Unk_7facf0(self->field_150, self->field_88->field_3a5);
}

struct Unk_7ca890_88 {
    u8 _0[0x3a5];
    u8 field_3a5;
};
PKMN_OFFSET_ASSERT(Unk_7ca890_88, field_3a5, 0x3a5);

struct Unk_7ca890 {
    u8 _0[0x88];
    Unk_7ca890_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7ca890, field_88, 0x88);

// 0x71007ca890
u8 Unk_7ca890_get(const Unk_7ca890* self) {
    return self->field_88->field_3a5;
}

struct Unk_7ca9e0 {
    u8 _0[0x183];
    u8 field_183;
};
PKMN_OFFSET_ASSERT(Unk_7ca9e0, field_183, 0x183);

// 0x71007ca9e0
u32 Unk_7ca9e0_get(const Unk_7ca9e0* self) {
    return (self->field_183 >> 2) & 1;
}

struct Unk_7ca9f0_88 {
    u8 _0[0xa5a];
    u8 field_a5a;
};
PKMN_OFFSET_ASSERT(Unk_7ca9f0_88, field_a5a, 0xa5a);

struct Unk_7ca9f0 {
    u8 _0[0x88];
    Unk_7ca9f0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7ca9f0, field_88, 0x88);

// 0x71007ca9f0
u8 Unk_7ca9f0_get(const Unk_7ca9f0* self) {
    return self->field_88->field_a5a;
}

struct Unk_7caa00_88 {
    u8 _0[0xa59];
    u8 field_a59;
};
PKMN_OFFSET_ASSERT(Unk_7caa00_88, field_a59, 0xa59);

struct Unk_7caa00 {
    u8 _0[0x88];
    Unk_7caa00_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7caa00, field_88, 0x88);

// 0x71007caa00
u8 Unk_7caa00_get(const Unk_7caa00* self) {
    return self->field_88->field_a59;
}

struct Unk_7caa10_88 {
    u8 _0[0xa5b];
    u8 field_a5b;
};
PKMN_OFFSET_ASSERT(Unk_7caa10_88, field_a5b, 0xa5b);

struct Unk_7caa10 {
    u8 _0[0x88];
    Unk_7caa10_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7caa10, field_88, 0x88);

// 0x71007caa10
u8 Unk_7caa10_get(const Unk_7caa10* self) {
    return self->field_88->field_a5b;
}

struct Unk_7caa20_88 {
    u8 _0[0xa5c];
    u8 field_a5c;
};
PKMN_OFFSET_ASSERT(Unk_7caa20_88, field_a5c, 0xa5c);

struct Unk_7caa20 {
    u8 _0[0x88];
    Unk_7caa20_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7caa20, field_88, 0x88);

// 0x71007caa20
u8 Unk_7caa20_get(const Unk_7caa20* self) {
    return self->field_88->field_a5c;
}

struct Unk_7cac10_88 {
    u8 _0[0xa70];
    u8 field_a70;
};
PKMN_OFFSET_ASSERT(Unk_7cac10_88, field_a70, 0xa70);

struct Unk_7cac10 {
    u8 _0[0x88];
    Unk_7cac10_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7cac10, field_88, 0x88);

// 0x71007cac10
bool Unk_7cac10_check(const Unk_7cac10* self) {
    return self->field_88->field_a70 == 0;
}

struct Unk_7cac30 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7cac30, field_150, 0x150);

void Unk_7f9c40(u32);

// 0x71007cac30
void Unk_7cac30_call(const Unk_7cac30* self) {
    Unk_7f9c40(self->field_150);
}

struct Unk_7cac80 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7cac80, field_150, 0x150);

void Unk_7fa500(u32, u32);

// 0x71007cac80
void Unk_7cac80_call(const Unk_7cac80* self, u32 value) {
    Unk_7fa500(self->field_150, value & 0xff);
}

struct Unk_7caf40_88 {
    u8 _0[0x1b0];
    u8 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_7caf40_88, field_1b0, 0x1b0);

struct Unk_7caf40 {
    u8 _0[0x88];
    Unk_7caf40_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7caf40, field_88, 0x88);

// 0x71007caf40
u8* Unk_7caf40_get(const Unk_7caf40* self) {
    return &self->field_88->field_1b0;
}

struct Unk_7caf50_88 {
    u8 _0[0x2f0];
    u8 field_2f0;
};
PKMN_OFFSET_ASSERT(Unk_7caf50_88, field_2f0, 0x2f0);

struct Unk_7caf50 {
    u8 _0[0x88];
    Unk_7caf50_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7caf50, field_88, 0x88);

// 0x71007caf50
u8 Unk_7caf50_get(const Unk_7caf50* self) {
    return self->field_88->field_2f0;
}

struct Unk_7caf60_88 {
    u8 _0[0x2f2];
    u8 field_2f2;
};
PKMN_OFFSET_ASSERT(Unk_7caf60_88, field_2f2, 0x2f2);

struct Unk_7caf60 {
    u8 _0[0x88];
    Unk_7caf60_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7caf60, field_88, 0x88);

// 0x71007caf60
u8 Unk_7caf60_get(const Unk_7caf60* self) {
    return self->field_88->field_2f2;
}

struct Unk_7caf70_88 {
    u8 _0[0x310];
    u8 field_310;
};
PKMN_OFFSET_ASSERT(Unk_7caf70_88, field_310, 0x310);

struct Unk_7caf70 {
    u8 _0[0x88];
    Unk_7caf70_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7caf70, field_88, 0x88);

// 0x71007caf70
u8* Unk_7caf70_get(const Unk_7caf70* self) {
    return &self->field_88->field_310;
}

struct Unk_7cb070_88 {
    u8 _0[0xa30];
    u64 field_a30;
};
PKMN_OFFSET_ASSERT(Unk_7cb070_88, field_a30, 0xa30);

struct Unk_7cb070 {
    u8 _0[0x88];
    Unk_7cb070_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7cb070, field_88, 0x88);

// 0x71007cb070
u64 Unk_7cb070_get(const Unk_7cb070* self) {
    return self->field_88->field_a30;
}

struct Unk_7cb2c0_88 {
    u8 _0[0x3a5];
    u8 field_3a5;
};
PKMN_OFFSET_ASSERT(Unk_7cb2c0_88, field_3a5, 0x3a5);

struct Unk_7cb2c0 {
    u8 _0[0x88];
    Unk_7cb2c0_88* field_88;
    u8 _90[0xc0];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7cb2c0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_7cb2c0, field_150, 0x150);

void Unk_7f9a10(u32, u8, u32);

// 0x71007cb2c0
void Unk_7cb2c0_call(const Unk_7cb2c0* self, u32 value) {
    Unk_7f9a10(self->field_150, self->field_88->field_3a5, value & 0xff);
}

struct Unk_7cb2e0_88 {
    u8 _0[0x3a5];
    u8 field_3a5;
};
PKMN_OFFSET_ASSERT(Unk_7cb2e0_88, field_3a5, 0x3a5);

struct Unk_7cb2e0 {
    u8 _0[0x88];
    Unk_7cb2e0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7cb2e0, field_88, 0x88);

// 0x71007cb2e0
bool Unk_7cb2e0_check(const Unk_7cb2e0* self) {
    return self->field_88->field_3a5 != 0;
}

struct Unk_7cb300_88 {
    u8 _0[0x3f8];
    u8 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_7cb300_88, field_3f8, 0x3f8);

struct Unk_7cb300 {
    u8 _0[0x88];
    Unk_7cb300_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7cb300, field_88, 0x88);

// 0x71007cb300
u8 Unk_7cb300_get(const Unk_7cb300* self) {
    return self->field_88->field_3f8;
}

struct Unk_7cb310_88 {
    u8 _0[0xb28];
    u8 field_b28;
};
PKMN_OFFSET_ASSERT(Unk_7cb310_88, field_b28, 0xb28);

struct Unk_7cb310 {
    u8 _0[0x88];
    Unk_7cb310_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7cb310, field_88, 0x88);

// 0x71007cb310
u32 Unk_7cb310_get(const Unk_7cb310* self) {
    return (self->field_88->field_b28 >> 4) & 1;
}

struct Unk_7cb350 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7cb350, field_150, 0x150);

void Unk_7fa9d0(u32);

// 0x71007cb350
void Unk_7cb350_call(const Unk_7cb350* self) {
    Unk_7fa9d0(self->field_150);
}

struct Unk_7cb360 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7cb360, field_150, 0x150);

void Unk_7fa9e0(u64, u64, u32);

// 0x71007cb360
void Unk_7cb360_call(const Unk_7cb360* self, u64 value, u64 arg2) {
    Unk_7fa9e0(value, arg2, self->field_150);
}

struct Unk_7cb380 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7cb380, field_150, 0x150);

void Unk_7f9e00(u32);

// 0x71007cb380
void Unk_7cb380_call(const Unk_7cb380* self) {
    Unk_7f9e00(self->field_150);
}

struct Unk_7cb390_88 {
    u8 _0[0x3a5];
    u8 field_3a5;
};
PKMN_OFFSET_ASSERT(Unk_7cb390_88, field_3a5, 0x3a5);

struct Unk_7cb390 {
    u8 _0[0x88];
    Unk_7cb390_88* field_88;
    u8 _90[0xc0];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7cb390, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_7cb390, field_150, 0x150);

void Unk_7fb3c0(u32, u8, u32);

// 0x71007cb390
void Unk_7cb390_call(const Unk_7cb390* self, u32 value) {
    Unk_7fb3c0(self->field_150, self->field_88->field_3a5, value & 0xff);
}

struct Unk_7cb410 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7cb410, field_150, 0x150);

void Unk_7fb6f0(u32, u32, u32);

// 0x71007cb410
void Unk_7cb410_call(const Unk_7cb410* self, u32 value, u32 arg2) {
    Unk_7fb6f0(self->field_150, value & 0xff, arg2 & 0xff);
}

struct Unk_7cb850 {
    u8 _0[0x174];
    u8 field_174;
};
PKMN_OFFSET_ASSERT(Unk_7cb850, field_174, 0x174);

// 0x71007cb850
u8 Unk_7cb850_getField174(const Unk_7cb850* self) {
    return self->field_174;
}

struct Unk_7cbc20 {
    u8 _0[0x170];
    u32 field_170;
};
PKMN_OFFSET_ASSERT(Unk_7cbc20, field_170, 0x170);

// 0x71007cbc20
u32 Unk_7cbc20_getField170(const Unk_7cbc20* self) {
    return self->field_170;
}

struct Unk_7cc070 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7cc070, field_150, 0x150);

void Unk_7f9de0(u32);

// 0x71007cc070
void Unk_7cc070_call(const Unk_7cc070* self) {
    Unk_7f9de0(self->field_150);
}

// 0x71007cc160
void Unk_7cc160() {}

struct Unk_7cc3c0 {
    u8 _0[0x168];
    u16 field_168;
};
PKMN_OFFSET_ASSERT(Unk_7cc3c0, field_168, 0x168);

// 0x71007cc3c0
u16 Unk_7cc3c0_getField168(const Unk_7cc3c0* self) {
    return self->field_168;
}

struct Unk_7cc400 {
    u8 _0[0x164];
    u16 field_164;
};
PKMN_OFFSET_ASSERT(Unk_7cc400, field_164, 0x164);

// 0x71007cc400
u16 Unk_7cc400_getField164(const Unk_7cc400* self) {
    return self->field_164;
}

// 0x71007cd130
u32 Unk_7cd130_get() {
    return 1;
}

struct Unk_7cd1f0_88 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7cd1f0_88, field_8, 0x8);

struct Unk_7cd1f0 {
    u8 _0[0x88];
    Unk_7cd1f0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7cd1f0, field_88, 0x88);

// 0x71007cd1f0
u8* Unk_7cd1f0_get(const Unk_7cd1f0* self) {
    return &self->field_88->field_8;
}

struct Unk_7cd240_88 {
    u8 _0[0xb98];
    u8 field_b98;
};
PKMN_OFFSET_ASSERT(Unk_7cd240_88, field_b98, 0xb98);

struct Unk_7cd240 {
    u8 _0[0x88];
    Unk_7cd240_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7cd240, field_88, 0x88);

void Unk_8c9a70(void*, void*, u64, u64);

// 0x71007cd240
void Unk_7cd240_call(Unk_7cd240* self, u64 value, u64 arg2) {
    Unk_8c9a70(&self->field_88->field_b98, self, value, arg2);
}

struct Unk_7cd430_88 {
    u8 _0[0x9];
    u8 field_9;
};
PKMN_OFFSET_ASSERT(Unk_7cd430_88, field_9, 0x9);

struct Unk_7cd430 {
    u8 _0[0x88];
    Unk_7cd430_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7cd430, field_88, 0x88);

// 0x71007cd430
u8 Unk_7cd430_get(const Unk_7cd430* self) {
    return self->field_88->field_9;
}

struct Unk_7cd930_88 {
    u8 _0[0x3f9];
    u8 field_3f9;
};
PKMN_OFFSET_ASSERT(Unk_7cd930_88, field_3f9, 0x3f9);

struct Unk_7cd930 {
    u8 _0[0x88];
    Unk_7cd930_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7cd930, field_88, 0x88);

// 0x71007cd930
u8 Unk_7cd930_get(const Unk_7cd930* self) {
    return self->field_88->field_3f9;
}
