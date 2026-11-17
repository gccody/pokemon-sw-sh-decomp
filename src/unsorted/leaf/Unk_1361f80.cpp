// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1361f80 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1361f80, field_60, 0x60);

// 0x7101361f80
bool Unk_1361f80_check(const Unk_1361f80* self) {
    return self->field_60 == 0x20180110;
}

struct Unk_1362000 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_1362000, field_a8, 0xa8);

// 0x7101362000
void Unk_1362000_setFielda8(Unk_1362000* self, u64 value) {
    self->field_a8 = value;
}

struct Unk_1362080 {
    u8 _0[0xb8];
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_1362080, field_b8, 0xb8);

// 0x7101362080
bool Unk_1362080_check(const Unk_1362080* self) {
    return self->field_b8 != 0;
}

struct Unk_1365920 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1365920, field_60, 0x60);

// 0x7101365920
void Unk_1365920_clearField60(Unk_1365920* self) {
    self->field_60 = 0;
}

// 0x710136b4e0
void Unk_136b4e0() {}

struct Unk_136b550 {
    u8 _0[0x104];
    u8 field_104;
};
PKMN_OFFSET_ASSERT(Unk_136b550, field_104, 0x104);

// 0x710136b550
u8 Unk_136b550_getField104(const Unk_136b550* self) {
    return self->field_104;
}

struct Unk_136b560 {
    u8 _0[0x60];
    u8 field_60;
    u8 _61[0xa4];
    u8 field_105;
};
PKMN_OFFSET_ASSERT(Unk_136b560, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_136b560, field_105, 0x105);

// 0x710136b560
void Unk_136b560_set(Unk_136b560* self, u8 value) {
    self->field_105 = value;
    self->field_60 = (value & 0xff) == 1;
}

struct Unk_136b580 {
    u8 _0[0x105];
    u8 field_105;
};
PKMN_OFFSET_ASSERT(Unk_136b580, field_105, 0x105);

// 0x710136b580
u8 Unk_136b580_getField105(const Unk_136b580* self) {
    return self->field_105;
}

struct Unk_136b590 {
    u8 _0[0x107];
    u8 field_107;
};
PKMN_OFFSET_ASSERT(Unk_136b590, field_107, 0x107);

// 0x710136b590
u8 Unk_136b590_getField107(const Unk_136b590* self) {
    return self->field_107;
}

struct Unk_136b5a0 {
    u8 _0[0x107];
    u8 field_107;
};
PKMN_OFFSET_ASSERT(Unk_136b5a0, field_107, 0x107);

// 0x710136b5a0
void Unk_136b5a0_setField107(Unk_136b5a0* self, u8 value) {
    self->field_107 = value;
}

struct Unk_136b680 {
    u8 _0[0x100];
    u32 field_100;
};
PKMN_OFFSET_ASSERT(Unk_136b680, field_100, 0x100);

// 0x710136b680
void Unk_136b680_setField100(Unk_136b680* self, u32 value) {
    self->field_100 = value;
}

struct Unk_136b690 {
    u8 _0[0x100];
    u32 field_100;
};
PKMN_OFFSET_ASSERT(Unk_136b690, field_100, 0x100);

// 0x710136b690
u32 Unk_136b690_getField100(const Unk_136b690* self) {
    return self->field_100;
}

struct Unk_136b6d0 {
    u8 _0[0x108];
    u64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_136b6d0, field_108, 0x108);

// 0x710136b6d0
void Unk_136b6d0_setField108(Unk_136b6d0* self, u64 value) {
    self->field_108 = value;
}

struct Unk_136b6e0 {
    u8 _0[0x108];
    u64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_136b6e0, field_108, 0x108);

// 0x710136b6e0
u64 Unk_136b6e0_getField108(const Unk_136b6e0* self) {
    return self->field_108;
}

struct Unk_136b6f0 {
    u8 _0[0x108];
    u64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_136b6f0, field_108, 0x108);

// 0x710136b6f0
bool Unk_136b6f0_check(const Unk_136b6f0* self) {
    return self->field_108 != 0;
}

struct Unk_136b700 {
    u8 _0[0x138];
    u64 field_138;
};
PKMN_OFFSET_ASSERT(Unk_136b700, field_138, 0x138);

// 0x710136b700
bool Unk_136b700_check(const Unk_136b700* self) {
    return self->field_138 != 0;
}

struct Unk_136b710 {
    u8 _0[0x138];
    u64 field_138;
};
PKMN_OFFSET_ASSERT(Unk_136b710, field_138, 0x138);

// 0x710136b710
u64 Unk_136b710_getField138(const Unk_136b710* self) {
    return self->field_138;
}

struct Unk_136b720 {
    u8 _0[0x138];
    u64 field_138;
};
PKMN_OFFSET_ASSERT(Unk_136b720, field_138, 0x138);

// 0x710136b720
void Unk_136b720_setField138(Unk_136b720* self, u64 value) {
    self->field_138 = value;
}

struct Unk_136b730 {
    u8 _0[0x106];
    u8 field_106;
};
PKMN_OFFSET_ASSERT(Unk_136b730, field_106, 0x106);

// 0x710136b730
u32 Unk_136b730_get(const Unk_136b730* self) {
    return (self->field_106 >> 2) & 1;
}

struct Unk_136b760 {
    u8 _0[0x12c];
    u32 field_12c;
};
PKMN_OFFSET_ASSERT(Unk_136b760, field_12c, 0x12c);

// 0x710136b760
void Unk_136b760_setField12c(Unk_136b760* self, u32 value) {
    self->field_12c = value;
}

struct Unk_136b770 {
    u8 _0[0x12c];
    u32 field_12c;
};
PKMN_OFFSET_ASSERT(Unk_136b770, field_12c, 0x12c);

// 0x710136b770
u32 Unk_136b770_getField12c(const Unk_136b770* self) {
    return self->field_12c;
}

struct Unk_136b780 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_136b780, field_60, 0x60);

// 0x710136b780
u8* Unk_136b780_getField60Ptr(Unk_136b780* self) {
    return &self->field_60;
}

struct Unk_136b790 {
    u8 _0[0x130];
    u32 field_130;
};
PKMN_OFFSET_ASSERT(Unk_136b790, field_130, 0x130);

// 0x710136b790
u32 Unk_136b790_getField130(const Unk_136b790* self) {
    return self->field_130;
}

struct Unk_136b7a0 {
    u8 _0[0x130];
    u32 field_130;
};
PKMN_OFFSET_ASSERT(Unk_136b7a0, field_130, 0x130);

// 0x710136b7a0
u32 Unk_136b7a0_update(Unk_136b7a0* self, u32 value) {
    self->field_130 = value < 0x98967f ? value : 0x98967f;
    return value < 0x98967f ? value : 0x98967f;
}

struct Unk_136b840 {
    u8 _0[0x136];
    u8 field_136;
};
PKMN_OFFSET_ASSERT(Unk_136b840, field_136, 0x136);

// 0x710136b840
u8 Unk_136b840_getField136(const Unk_136b840* self) {
    return self->field_136;
}

struct Unk_136b850 {
    u8 _0[0x136];
    u8 field_136;
};
PKMN_OFFSET_ASSERT(Unk_136b850, field_136, 0x136);

// 0x710136b850
void Unk_136b850_setField136(Unk_136b850* self, u8 value) {
    self->field_136 = value;
}

// 0x710136b860
u32 Unk_136b860() {
    return 0x110;
}

void Unk_136d010();

// 0x710136d000
void Unk_136d000_call() {
    Unk_136d010();
}

struct Unk_136f5a0 {
    u8 _0[0x60];
    u16 field_60;
};
PKMN_OFFSET_ASSERT(Unk_136f5a0, field_60, 0x60);

// 0x710136f5a0
u16 Unk_136f5a0_getField60(const Unk_136f5a0* self) {
    return self->field_60;
}

struct Unk_136f5b0 {
    u8 _0[0x62];
    u8 field_62;
};
PKMN_OFFSET_ASSERT(Unk_136f5b0, field_62, 0x62);

// 0x710136f5b0
u8 Unk_136f5b0_getField62(const Unk_136f5b0* self) {
    return self->field_62;
}

struct Unk_136f5c0 {
    u8 _0[0x64];
    u32 field_64;
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_136f5c0, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_136f5c0, field_68, 0x68);

// 0x710136f5c0
void Unk_136f5c0_set(Unk_136f5c0* self) {
    self->field_68 = self->field_64;
}

struct Unk_136f5d0 {
    u8 _0[0x64];
    u32 field_64;
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_136f5d0, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_136f5d0, field_68, 0x68);

// 0x710136f5d0
void Unk_136f5d0_set(Unk_136f5d0* self) {
    self->field_64 = self->field_68;
}

struct Unk_136f5e0 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_136f5e0, field_64, 0x64);

// 0x710136f5e0
u32 Unk_136f5e0_get(const Unk_136f5e0* self) {
    return self->field_64 & 0xfff;
}

struct Unk_136f5f0 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_136f5f0, field_64, 0x64);

// 0x710136f5f0
u32 Unk_136f5f0_get(const Unk_136f5f0* self) {
    return (self->field_64 >> 0xc) & 0xf;
}

struct Unk_136f600 {
    u8 _0[0x66];
    u16 field_66;
};
PKMN_OFFSET_ASSERT(Unk_136f600, field_66, 0x66);

// 0x710136f600
u32 Unk_136f600_get(const Unk_136f600* self) {
    return self->field_66 & 0x1f;
}

struct Unk_136f610 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_136f610, field_64, 0x64);

// 0x710136f610
u32 Unk_136f610_get(const Unk_136f610* self) {
    return (self->field_64 >> 0x15) & 0x1f;
}

struct Unk_136f620 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_136f620, field_64, 0x64);

// 0x710136f620
u32 Unk_136f620_get(const Unk_136f620* self) {
    return self->field_64 >> 0x1a;
}

struct Unk_1370980 {
    u8 _0[0x6830];
    u64 field_6830;
    u64 field_6838;
    u64 field_6840;
    u64 field_6848;
    u64 field_6850;
    u64 field_6858;
    u64 field_6860;
};
PKMN_OFFSET_ASSERT(Unk_1370980, field_6830, 0x6830);
PKMN_OFFSET_ASSERT(Unk_1370980, field_6838, 0x6838);
PKMN_OFFSET_ASSERT(Unk_1370980, field_6840, 0x6840);
PKMN_OFFSET_ASSERT(Unk_1370980, field_6848, 0x6848);
PKMN_OFFSET_ASSERT(Unk_1370980, field_6850, 0x6850);
PKMN_OFFSET_ASSERT(Unk_1370980, field_6858, 0x6858);
PKMN_OFFSET_ASSERT(Unk_1370980, field_6860, 0x6860);

// 0x7101370980
void Unk_1370980_set(Unk_1370980* self) {
    self->field_6860 = 0;
    self->field_6858 = 0;
    self->field_6850 = 0;
    self->field_6848 = 0;
    self->field_6840 = 0;
    self->field_6838 = 0;
    self->field_6830 = 0;
}

struct Unk_1377d30 {
    u8 _0[0x31f];
    u8 field_31f;
};
PKMN_OFFSET_ASSERT(Unk_1377d30, field_31f, 0x31f);

// 0x7101377d30
void Unk_1377d30_set(Unk_1377d30* self) {
    self->field_31f = 1;
}

struct Unk_1377d40 {
    u8 _0[0x31f];
    u8 field_31f;
};
PKMN_OFFSET_ASSERT(Unk_1377d40, field_31f, 0x31f);

// 0x7101377d40
void Unk_1377d40_set(Unk_1377d40* self) {
    self->field_31f = 2;
}

struct Unk_1377d50 {
    u8 _0[0x31f];
    u8 field_31f;
};
PKMN_OFFSET_ASSERT(Unk_1377d50, field_31f, 0x31f);

// 0x7101377d50
bool Unk_1377d50_check(const Unk_1377d50* self) {
    return self->field_31f == 1;
}

struct Unk_1377d60 {
    u8 _0[0x31f];
    u8 field_31f;
};
PKMN_OFFSET_ASSERT(Unk_1377d60, field_31f, 0x31f);

// 0x7101377d60
bool Unk_1377d60_check(const Unk_1377d60* self) {
    return self->field_31f == 2;
}

struct Unk_1378bd0 {
    u8 _0[0x4bf8];
    u64 field_4bf8;
};
PKMN_OFFSET_ASSERT(Unk_1378bd0, field_4bf8, 0x4bf8);

// 0x7101378bd0
void Unk_1378bd0_setField4bf8(Unk_1378bd0* self, u64 value) {
    self->field_4bf8 = value;
}

struct Unk_137a160 {
    u8 _0[0x4be8];
    u64 field_4be8;
};
PKMN_OFFSET_ASSERT(Unk_137a160, field_4be8, 0x4be8);

// 0x710137a160
u64 Unk_137a160_getField4be8(const Unk_137a160* self) {
    return self->field_4be8;
}

struct Unk_137a280 {
    u8 _0[0x4bf8];
    u64 field_4bf8;
};
PKMN_OFFSET_ASSERT(Unk_137a280, field_4bf8, 0x4bf8);

// 0x710137a280
u64 Unk_137a280_getField4bf8(const Unk_137a280* self) {
    return self->field_4bf8;
}

struct Unk_137b8b0 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_137b8b0, field_64, 0x64);

// 0x710137b8b0
u32 Unk_137b8b0_getField64(const Unk_137b8b0* self) {
    return self->field_64;
}

struct Unk_137b8c0 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_137b8c0, field_64, 0x64);

// 0x710137b8c0
u32 Unk_137b8c0_update(Unk_137b8c0* self, u32 value) {
    self->field_64 = value < 0x98967f ? value : 0x98967f;
    return value < 0x98967f ? value : 0x98967f;
}

struct Unk_137b960 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_137b960, field_68, 0x68);

// 0x710137b960
u32 Unk_137b960_get(const Unk_137b960* self) {
    return self->field_68 & 1;
}

struct Unk_137baa0 {
    u8 _0[0x17c];
    u32 field_17c;
};
PKMN_OFFSET_ASSERT(Unk_137baa0, field_17c, 0x17c);

// 0x710137baa0
u32 Unk_137baa0_getField17c(const Unk_137baa0* self) {
    return self->field_17c;
}

struct Unk_137baf0 {
    u8 _0[0x190];
    u32 field_190;
};
PKMN_OFFSET_ASSERT(Unk_137baf0, field_190, 0x190);

// 0x710137baf0
u32 Unk_137baf0_getField190(const Unk_137baf0* self) {
    return self->field_190;
}

struct Unk_137bba0 {
    u8 _0[0x27c];
    u16 field_27c;
};
PKMN_OFFSET_ASSERT(Unk_137bba0, field_27c, 0x27c);

// 0x710137bba0
u16 Unk_137bba0_getField27c(const Unk_137bba0* self) {
    return self->field_27c;
}

struct Unk_137bbb0 {
    u8 _0[0x27e];
    u16 field_27e;
};
PKMN_OFFSET_ASSERT(Unk_137bbb0, field_27e, 0x27e);

// 0x710137bbb0
u16 Unk_137bbb0_getField27e(const Unk_137bbb0* self) {
    return self->field_27e;
}

struct Unk_137bbe0 {
    u8 _0[0x27c];
    u32 field_27c;
};
PKMN_OFFSET_ASSERT(Unk_137bbe0, field_27c, 0x27c);

// 0x710137bbe0
void Unk_137bbe0_clearField27c(Unk_137bbe0* self) {
    self->field_27c = 0;
}

struct Unk_137bc10 {
    u8 _0[0x280];
    u8 field_280;
};
PKMN_OFFSET_ASSERT(Unk_137bc10, field_280, 0x280);

// 0x710137bc10
void Unk_137bc10_clearField280(Unk_137bc10* self) {
    self->field_280 = 0;
}

struct Unk_137bc20 {
    u8 _0[0x282];
    u16 field_282;
};
PKMN_OFFSET_ASSERT(Unk_137bc20, field_282, 0x282);

// 0x710137bc20
u16 Unk_137bc20_getField282(const Unk_137bc20* self) {
    return self->field_282;
}

struct Unk_137bc30 {
    u8 _0[0x282];
    u16 field_282;
};
PKMN_OFFSET_ASSERT(Unk_137bc30, field_282, 0x282);

// 0x710137bc30
void Unk_137bc30_setField282(Unk_137bc30* self, u16 value) {
    self->field_282 = value;
}

struct Unk_137bc40 {
    u8 _0[0x284];
    u32 field_284;
};
PKMN_OFFSET_ASSERT(Unk_137bc40, field_284, 0x284);

// 0x710137bc40
u32 Unk_137bc40_getField284(const Unk_137bc40* self) {
    return self->field_284;
}

struct Unk_137bc50 {
    u8 _0[0x284];
    u32 field_284;
};
PKMN_OFFSET_ASSERT(Unk_137bc50, field_284, 0x284);

// 0x710137bc50
void Unk_137bc50_setField284(Unk_137bc50* self, u32 value) {
    self->field_284 = value;
}

struct Unk_137bc60 {
    u8 _0[0x68];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_137bc60, field_68, 0x68);

// 0x710137bc60
bool Unk_137bc60_check(const Unk_137bc60* self) {
    return (self->field_68 & 0x20) == 0;
}

struct Unk_137bc90 {
    u8 _0[0x68];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_137bc90, field_68, 0x68);

// 0x710137bc90
bool Unk_137bc90_check(const Unk_137bc90* self) {
    return (self->field_68 & 0x40) == 0;
}

struct Unk_137cd00 {
    u8 _0[0xf68];
    u32 field_f68;
};
PKMN_OFFSET_ASSERT(Unk_137cd00, field_f68, 0xf68);

// 0x710137cd00
bool Unk_137cd00_check(const Unk_137cd00* self, u32 value) {
    return (self->field_f68 & (1 << value)) == 0;
}

struct Unk_1389e90 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1389e90, field_c, 0xc);

// 0x7101389e90
bool Unk_1389e90_check(const Unk_1389e90* self) {
    return self->field_c == 1;
}

struct Unk_1389ea0 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1389ea0, field_c, 0xc);

// 0x7101389ea0
bool Unk_1389ea0_check(const Unk_1389ea0* self) {
    return self->field_c == 2;
}

struct Unk_1389eb0 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1389eb0, field_c, 0xc);

// 0x7101389eb0
bool Unk_1389eb0_check(const Unk_1389eb0* self) {
    return self->field_c == 3;
}

struct Unk_1389ec0 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1389ec0, field_c, 0xc);

// 0x7101389ec0
bool Unk_1389ec0_check(const Unk_1389ec0* self) {
    return self->field_c == 4;
}

struct Unk_1389ed0 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1389ed0, field_c, 0xc);

// 0x7101389ed0
bool Unk_1389ed0_check(const Unk_1389ed0* self) {
    return self->field_c == 5;
}

struct Unk_138a340 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_138a340, field_60, 0x60);

// 0x710138a340
u8* Unk_138a340_getField60Ptr(Unk_138a340* self) {
    return &self->field_60;
}

struct Unk_138be50 {
    u8 _0[0x15b0];
    u64 field_15b0;
    u16 field_15b8;
};
PKMN_OFFSET_ASSERT(Unk_138be50, field_15b0, 0x15b0);
PKMN_OFFSET_ASSERT(Unk_138be50, field_15b8, 0x15b8);

// 0x710138be50
void Unk_138be50_set(Unk_138be50* self) {
    self->field_15b0 = 0;
    self->field_15b8 = 0;
}
