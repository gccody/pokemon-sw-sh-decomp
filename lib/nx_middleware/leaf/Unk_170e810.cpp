// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_170e810 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_170e810, field_18, 0x18);

// 0x710170e810
u64 Unk_170e810_get(const Unk_170e810* self) {
    return self->field_18;
}

struct Unk_170e820 {
    u8 _0[0x14];
    u8 field_14;
};
PKMN_OFFSET_ASSERT(Unk_170e820, field_14, 0x14);

// 0x710170e820
u8 Unk_170e820_get(const Unk_170e820* self) {
    return self->field_14;
}

struct Unk_170e830 {
    u8 _0[0x14];
    u8 field_14;
};
PKMN_OFFSET_ASSERT(Unk_170e830, field_14, 0x14);

// 0x710170e830
const u8* Unk_170e830_get(const Unk_170e830* self) {
    return &self->field_14;
}

struct Unk_170e840 {
    u8 _0[0x1a4];
    u32 field_1a4;
};
PKMN_OFFSET_ASSERT(Unk_170e840, field_1a4, 0x1a4);

// 0x710170e840
u32 Unk_170e840_get(const Unk_170e840* self) {
    return self->field_1a4;
}

struct Unk_170e850 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_170e850, field_18, 0x18);

// 0x710170e850
u64 Unk_170e850_get(const Unk_170e850* self) {
    return self->field_18;
}

struct Unk_1713c10 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1713c10, field_8, 0x8);

// 0x7101713c10
void Unk_1713c10_set(Unk_1713c10* self, u32 value) {
    self->field_8 = value;
}

struct Unk_1713c20 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1713c20, field_c, 0xc);

// 0x7101713c20
void Unk_1713c20_set(Unk_1713c20* self, u32 value) {
    self->field_c = value;
}

struct Unk_1713c30 {
    u8 _0[0x268];
    u32 field_268;
};
PKMN_OFFSET_ASSERT(Unk_1713c30, field_268, 0x268);

// 0x7101713c30
void Unk_1713c30_set(Unk_1713c30* self, u32 value) {
    self->field_268 = value;
}

struct Unk_1713c40 {
    u8 _0[0x10];
    u16 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1713c40, field_10, 0x10);

// 0x7101713c40
void Unk_1713c40_set(Unk_1713c40* self, u16 value) {
    self->field_10 = value;
}

struct Unk_1713c50 {
    u8 _0[0x12];
    u16 field_12;
};
PKMN_OFFSET_ASSERT(Unk_1713c50, field_12, 0x12);

// 0x7101713c50
void Unk_1713c50_set(Unk_1713c50* self, u16 value) {
    self->field_12 = value;
}

struct Unk_1713c60 {
    u8 _0[0x14];
    u16 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1713c60, field_14, 0x14);

// 0x7101713c60
void Unk_1713c60_set(Unk_1713c60* self, u16 value) {
    self->field_14 = value;
}

struct Unk_1713c70 {
    u8 _0[0x16];
    bool field_16;
};
PKMN_OFFSET_ASSERT(Unk_1713c70, field_16, 0x16);

// 0x7101713c70
void Unk_1713c70_set(Unk_1713c70* self, bool value) {
    self->field_16 = value;
}

struct Unk_1713dc0 {
    u8 _0[0x234];
    bool field_234;
};
PKMN_OFFSET_ASSERT(Unk_1713dc0, field_234, 0x234);

// 0x7101713dc0
void Unk_1713dc0_set(Unk_1713dc0* self, bool value) {
    self->field_234 = value;
}

struct Unk_1713dd0 {
    u8 _0[0x235];
    bool field_235;
};
PKMN_OFFSET_ASSERT(Unk_1713dd0, field_235, 0x235);

// 0x7101713dd0
void Unk_1713dd0_set(Unk_1713dd0* self, bool value) {
    self->field_235 = value;
}

struct Unk_1713de0 {
    u8 _0[0x238];
    u32 field_238;
    bool field_23c;
};
PKMN_OFFSET_ASSERT(Unk_1713de0, field_238, 0x238);
PKMN_OFFSET_ASSERT(Unk_1713de0, field_23c, 0x23c);

// 0x7101713de0
void Unk_1713de0_set(Unk_1713de0* self, u32 value, bool arg2) {
    self->field_238 = value;
    self->field_23c = arg2;
}

struct Unk_1713df0 {
    u8 _0[0x240];
    u64 field_240;
};
PKMN_OFFSET_ASSERT(Unk_1713df0, field_240, 0x240);

// 0x7101713df0
void Unk_1713df0_set(Unk_1713df0* self, u64 value) {
    self->field_240 = value;
}

struct Unk_1713e00 {
    u8 _0[0x248];
    u64 field_248;
};
PKMN_OFFSET_ASSERT(Unk_1713e00, field_248, 0x248);

// 0x7101713e00
void Unk_1713e00_set(Unk_1713e00* self, u64 value) {
    self->field_248 = value;
}

struct Unk_1713e10 {
    u8 _0[0x250];
    u8 field_250;
};
PKMN_OFFSET_ASSERT(Unk_1713e10, field_250, 0x250);

// 0x7101713e10
void Unk_1713e10_set(Unk_1713e10* self, u8 value) {
    self->field_250 = value;
}

struct Unk_1713e20_arg1 {
    u8 _0[0x8];
    u16 field_8;
    u8 field_a;
    u8 field_b;
    u8 field_c;
    u8 field_d;
    u8 field_e;
    u8 field_f;
};
PKMN_OFFSET_ASSERT(Unk_1713e20_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1713e20_arg1, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_1713e20_arg1, field_b, 0xb);
PKMN_OFFSET_ASSERT(Unk_1713e20_arg1, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1713e20_arg1, field_d, 0xd);
PKMN_OFFSET_ASSERT(Unk_1713e20_arg1, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_1713e20_arg1, field_f, 0xf);

struct Unk_1713e20 {
    u8 _0[0x260];
    u16 field_260;
    u8 field_262;
    u8 field_263;
    u8 field_264;
    u8 field_265;
    u8 field_266;
    u8 field_267;
};
PKMN_OFFSET_ASSERT(Unk_1713e20, field_260, 0x260);
PKMN_OFFSET_ASSERT(Unk_1713e20, field_262, 0x262);
PKMN_OFFSET_ASSERT(Unk_1713e20, field_263, 0x263);
PKMN_OFFSET_ASSERT(Unk_1713e20, field_264, 0x264);
PKMN_OFFSET_ASSERT(Unk_1713e20, field_265, 0x265);
PKMN_OFFSET_ASSERT(Unk_1713e20, field_266, 0x266);
PKMN_OFFSET_ASSERT(Unk_1713e20, field_267, 0x267);

// 0x7101713e20
void Unk_1713e20_set(Unk_1713e20* self, const Unk_1713e20_arg1* value) {
    self->field_260 = value->field_8;
    self->field_262 = value->field_a;
    self->field_263 = value->field_b;
    self->field_264 = value->field_c;
    self->field_265 = value->field_d;
    self->field_266 = value->field_e;
    self->field_267 = value->field_f;
}

struct Unk_1714580 {
    u8 _0[0xa38];
    u16 field_a38;
    u16 field_a3a;
    u8 _a3c[0x2f4];
    u32 field_d30;
};
PKMN_OFFSET_ASSERT(Unk_1714580, field_a38, 0xa38);
PKMN_OFFSET_ASSERT(Unk_1714580, field_a3a, 0xa3a);
PKMN_OFFSET_ASSERT(Unk_1714580, field_d30, 0xd30);

// 0x7101714580
void Unk_1714580_set(Unk_1714580* self, u16 value) {
    self->field_a38 = 0xffff;
    self->field_a3a = value;
    self->field_d30 = self->field_d30 | 2;
}

struct Unk_17145a0 {
    u8 _0[0x14];
    u32 field_14;
    u8 _18[0xd18];
    u32 field_d30;
};
PKMN_OFFSET_ASSERT(Unk_17145a0, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_17145a0, field_d30, 0xd30);

// 0x71017145a0
void Unk_17145a0_set(Unk_17145a0* self, u32 value) {
    self->field_14 = value;
    self->field_d30 = self->field_d30 | 0x10;
}

struct Unk_17159a0 {
    u8 _0[0xd30];
    u8 field_d30;
};
PKMN_OFFSET_ASSERT(Unk_17159a0, field_d30, 0xd30);

// 0x71017159a0
u32 Unk_17159a0_get(const Unk_17159a0* self) {
    return (self->field_d30 >> 4) & 1;
}

struct Unk_17159c0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_17159c0, field_18, 0x18);

// 0x71017159c0
u64 Unk_17159c0_get(const Unk_17159c0* self) {
    return self->field_18;
}

struct Unk_17159d0 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_17159d0, field_18, 0x18);

// 0x71017159d0
const u8* Unk_17159d0_get(const Unk_17159d0* self) {
    return &self->field_18;
}

struct Unk_17159e0 {
    u8 _0[0x978];
    u32 field_978;
};
PKMN_OFFSET_ASSERT(Unk_17159e0, field_978, 0x978);

// 0x71017159e0
u32 Unk_17159e0_get(const Unk_17159e0* self) {
    return self->field_978;
}

struct Unk_17159f0 {
    u8 _0[0x97d];
    u8 field_97d;
};
PKMN_OFFSET_ASSERT(Unk_17159f0, field_97d, 0x97d);

// 0x71017159f0
u8 Unk_17159f0_get(const Unk_17159f0* self) {
    return self->field_97d;
}

struct Unk_1715a00 {
    u8 _0[0x97e];
    u8 field_97e;
};
PKMN_OFFSET_ASSERT(Unk_1715a00, field_97e, 0x97e);

// 0x7101715a00
u8 Unk_1715a00_get(const Unk_1715a00* self) {
    return self->field_97e;
}

struct Unk_1715a10 {
    u8 _0[0x97f];
    u8 field_97f;
};
PKMN_OFFSET_ASSERT(Unk_1715a10, field_97f, 0x97f);

// 0x7101715a10
u8 Unk_1715a10_get(const Unk_1715a10* self) {
    return self->field_97f;
}

struct Unk_1715a20 {
    u8 _0[0x14];
    u8 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1715a20, field_14, 0x14);

// 0x7101715a20
const u8* Unk_1715a20_get(const Unk_1715a20* self) {
    return &self->field_14;
}

struct Unk_1715a30 {
    u8 _0[0x1a4];
    u32 field_1a4;
};
PKMN_OFFSET_ASSERT(Unk_1715a30, field_1a4, 0x1a4);

// 0x7101715a30
u32 Unk_1715a30_get(const Unk_1715a30* self) {
    return self->field_1a4;
}

struct Unk_1715a40 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1715a40, field_8, 0x8);

// 0x7101715a40
u32 Unk_1715a40_get(const Unk_1715a40* self) {
    return self->field_8;
}

struct Unk_1715a50 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1715a50, field_c, 0xc);

// 0x7101715a50
u16 Unk_1715a50_get(const Unk_1715a50* self) {
    return self->field_c;
}

struct Unk_1715a60 {
    u8 _0[0xe];
    u16 field_e;
};
PKMN_OFFSET_ASSERT(Unk_1715a60, field_e, 0xe);

// 0x7101715a60
u16 Unk_1715a60_get(const Unk_1715a60* self) {
    return self->field_e;
}

struct Unk_1715a90 {
    u8 _0[0x650];
    u8 field_650;
};
PKMN_OFFSET_ASSERT(Unk_1715a90, field_650, 0x650);

// 0x7101715a90
const u8* Unk_1715a90_get(const Unk_1715a90* self) {
    return &self->field_650;
}

struct Unk_1715aa0 {
    u8 _0[0x710];
    u8 field_710;
};
PKMN_OFFSET_ASSERT(Unk_1715aa0, field_710, 0x710);

// 0x7101715aa0
u32 Unk_1715aa0_get(const Unk_1715aa0* self) {
    return self->field_710 >> 7;
}

struct Unk_1715ab0 {
    u8 _0[0x230];
    u8 field_230;
};
PKMN_OFFSET_ASSERT(Unk_1715ab0, field_230, 0x230);

// 0x7101715ab0
const u8* Unk_1715ab0_get(const Unk_1715ab0* self) {
    return &self->field_230;
}

// 0x7101715c80
u32 Unk_1715c80_get() {
    return 1;
}

struct Unk_1715c90 {
    u8 _0[0x6f0];
    u8 field_6f0;
};
PKMN_OFFSET_ASSERT(Unk_1715c90, field_6f0, 0x6f0);

// 0x7101715c90
const u8* Unk_1715c90_get(const Unk_1715c90* self) {
    return &self->field_6f0;
}

struct Unk_1715ca0 {
    u8 _0[0x700];
    u8 field_700;
};
PKMN_OFFSET_ASSERT(Unk_1715ca0, field_700, 0x700);

// 0x7101715ca0
const u8* Unk_1715ca0_get(const Unk_1715ca0* self) {
    return &self->field_700;
}

struct Unk_1715cb0 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1715cb0, field_c, 0xc);

// 0x7101715cb0
u16 Unk_1715cb0_get(const Unk_1715cb0* self) {
    return self->field_c;
}

struct Unk_1715cc0 {
    u8 _0[0xe];
    u16 field_e;
};
PKMN_OFFSET_ASSERT(Unk_1715cc0, field_e, 0xe);

// 0x7101715cc0
u16 Unk_1715cc0_get(const Unk_1715cc0* self) {
    return self->field_e;
}

struct Unk_1715cd0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1715cd0, field_10, 0x10);

// 0x7101715cd0
u32 Unk_1715cd0_get(const Unk_1715cd0* self) {
    return self->field_10;
}

struct Unk_1715ce0 {
    u8 _0[0x14];
    u8 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1715ce0, field_14, 0x14);

// 0x7101715ce0
u8 Unk_1715ce0_get(const Unk_1715ce0* self) {
    return self->field_14;
}

struct Unk_1715d20 {
    u8 _0[0x240];
    u8 field_240;
};
PKMN_OFFSET_ASSERT(Unk_1715d20, field_240, 0x240);

// 0x7101715d20
const u8* Unk_1715d20_get(const Unk_1715d20* self) {
    return &self->field_240;
}

struct Unk_1715d30 {
    u8 _0[0x2e0];
    u8 field_2e0;
};
PKMN_OFFSET_ASSERT(Unk_1715d30, field_2e0, 0x2e0);

// 0x7101715d30
const u8* Unk_1715d30_get(const Unk_1715d30* self) {
    return &self->field_2e0;
}

struct Unk_1715d40 {
    u8 _0[0x23c];
    u8 field_23c;
};
PKMN_OFFSET_ASSERT(Unk_1715d40, field_23c, 0x23c);

// 0x7101715d40
u8 Unk_1715d40_get(const Unk_1715d40* self) {
    return self->field_23c;
}

struct Unk_1715d50 {
    u8 _0[0x390];
    u32 field_390;
};
PKMN_OFFSET_ASSERT(Unk_1715d50, field_390, 0x390);

// 0x7101715d50
u32 Unk_1715d50_get(const Unk_1715d50* self) {
    return self->field_390;
}

struct Unk_1715d60 {
    u8 _0[0x394];
    u8 field_394;
};
PKMN_OFFSET_ASSERT(Unk_1715d60, field_394, 0x394);

// 0x7101715d60
u8 Unk_1715d60_get(const Unk_1715d60* self) {
    return self->field_394;
}

struct Unk_1715d70 {
    u8 _0[0x398];
    u32 field_398;
};
PKMN_OFFSET_ASSERT(Unk_1715d70, field_398, 0x398);

// 0x7101715d70
u32 Unk_1715d70_get(const Unk_1715d70* self) {
    return self->field_398;
}

struct Unk_1715d80 {
    u8 _0[0x39c];
    u8 field_39c;
};
PKMN_OFFSET_ASSERT(Unk_1715d80, field_39c, 0x39c);

// 0x7101715d80
u8 Unk_1715d80_get(const Unk_1715d80* self) {
    return self->field_39c;
}

struct Unk_1715d90 {
    u8 _0[0x3a0];
    u32 field_3a0;
};
PKMN_OFFSET_ASSERT(Unk_1715d90, field_3a0, 0x3a0);

// 0x7101715d90
u32 Unk_1715d90_get(const Unk_1715d90* self) {
    return self->field_3a0;
}

struct Unk_1715da0 {
    u8 _0[0x3a4];
    u8 field_3a4;
};
PKMN_OFFSET_ASSERT(Unk_1715da0, field_3a4, 0x3a4);

// 0x7101715da0
u8 Unk_1715da0_get(const Unk_1715da0* self) {
    return self->field_3a4;
}

struct Unk_1715db0 {
    u8 _0[0x3a8];
    u8 field_3a8;
};
PKMN_OFFSET_ASSERT(Unk_1715db0, field_3a8, 0x3a8);

// 0x7101715db0
const u8* Unk_1715db0_get(const Unk_1715db0* self) {
    return &self->field_3a8;
}

struct Unk_1715dc0 {
    u8 _0[0x3d0];
    u8 field_3d0;
};
PKMN_OFFSET_ASSERT(Unk_1715dc0, field_3d0, 0x3d0);

// 0x7101715dc0
u8 Unk_1715dc0_get(const Unk_1715dc0* self) {
    return self->field_3d0;
}

struct Unk_1715dd0 {
    u8 _0[0x3d1];
    u8 field_3d1;
};
PKMN_OFFSET_ASSERT(Unk_1715dd0, field_3d1, 0x3d1);

// 0x7101715dd0
u8 Unk_1715dd0_get(const Unk_1715dd0* self) {
    return self->field_3d1;
}

struct Unk_17162c0 {
    u8 _0[0x380];
    u8 field_380;
};
PKMN_OFFSET_ASSERT(Unk_17162c0, field_380, 0x380);

// 0x71017162c0
const u8* Unk_17162c0_get(const Unk_17162c0* self) {
    return &self->field_380;
}
