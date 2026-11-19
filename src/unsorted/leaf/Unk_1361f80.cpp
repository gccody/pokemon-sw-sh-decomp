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

extern void* Unk_24ba588;
struct Unk_1362190 {
    u8 _0[0x190];
    u8 field_190;
    u8 _191[0x7];
    u64 field_198;
};
PKMN_OFFSET_ASSERT(Unk_1362190, field_190, 0x190);
PKMN_OFFSET_ASSERT(Unk_1362190, field_198, 0x198);

u64 Unk_eadb70(void*, u32, u32);

// 0x7101362190
void Unk_1362190_call(Unk_1362190* self, u32 value, u32 arg2) {
    self->field_190 = 1;
    u64 r0 = Unk_eadb70(Unk_24ba588, value, arg2);
    self->field_198 = r0;
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

struct Unk_136b820 {
    u8 _0[0x130];
    u32 field_130;
};
PKMN_OFFSET_ASSERT(Unk_136b820, field_130, 0x130);

// 0x710136b820
u32 Unk_136b820_update(Unk_136b820* self, u32 value) {
    u32 v0 = self->field_130;
    self->field_130 = (v0 > value ? v0 : value) - value;
    return (v0 > value ? v0 : value) - value;
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

struct Unk_136b870 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_136b870, field_60, 0x60);

extern "C" void* memcpy(void*, const void*, unsigned long);

// 0x710136b870
u32 Unk_136b870_call(const Unk_136b870* self, void* value) {
    memcpy(value, &self->field_60, 0x110);
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

// 0x710136f7c0
void Unk_136f7c0_update() {}

struct Unk_136f7d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_136f7d0_arg1, field_0, 0x0);

struct Unk_136f7d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_136f7d0, field_0, 0x0);

// 0x710136f7d0
void Unk_136f7d0_set(const Unk_136f7d0* self, Unk_136f7d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_136f7e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_136f7e0_arg1, field_0, 0x0);

struct Unk_136f7e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_136f7e0, field_0, 0x0);

// 0x710136f7e0
void Unk_136f7e0_set(const Unk_136f7e0* self, Unk_136f7e0_arg1* value) {
    value->field_0 = self->field_0;
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

struct Unk_1377780 {
    u8 _0[0x60];
    u8 field_60;
    u8 _61[0x2af];
    u64 field_310;
    u64 field_318;
    u64 field_320;
    u64 field_328;
    u64 field_330;
    u64 field_338;
    u64 field_340;
    u16 field_348;
};
PKMN_OFFSET_ASSERT(Unk_1377780, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_1377780, field_310, 0x310);
PKMN_OFFSET_ASSERT(Unk_1377780, field_318, 0x318);
PKMN_OFFSET_ASSERT(Unk_1377780, field_320, 0x320);
PKMN_OFFSET_ASSERT(Unk_1377780, field_328, 0x328);
PKMN_OFFSET_ASSERT(Unk_1377780, field_330, 0x330);
PKMN_OFFSET_ASSERT(Unk_1377780, field_338, 0x338);
PKMN_OFFSET_ASSERT(Unk_1377780, field_340, 0x340);
PKMN_OFFSET_ASSERT(Unk_1377780, field_348, 0x348);

extern "C" void* memset(void*, int, unsigned long);

// 0x7101377780
void Unk_1377780_call(Unk_1377780* self) {
    memset(&self->field_60, 0, 0x2b0);
    self->field_348 = 0;
    self->field_340 = 0;
    self->field_310 = 0xffffffffffffffff;
    self->field_338 = 0;
    self->field_330 = 0;
    self->field_328 = 0;
    self->field_320 = 0;
    self->field_318 = 0;
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

struct Unk_1377d90 {
    u8 _0[0x60];
    u8 field_60;
    u8 _61[0x2be];
    u8 field_31f;
    u8 _320[0x2c];
    u8 field_34c;
};
PKMN_OFFSET_ASSERT(Unk_1377d90, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_1377d90, field_31f, 0x31f);
PKMN_OFFSET_ASSERT(Unk_1377d90, field_34c, 0x34c);

extern "C" void* memcpy(void*, const void*, unsigned long);

// 0x7101377d90
void Unk_1377d90_call(Unk_1377d90* self) {
    memcpy(&self->field_60, &self->field_34c, 0x2ec);
    self->field_31f = 1;
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

struct Unk_137b940 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_137b940, field_64, 0x64);

// 0x710137b940
u32 Unk_137b940_update(Unk_137b940* self, u32 value) {
    u32 v0 = self->field_64;
    self->field_64 = (v0 < value ? value : v0) - value;
    return (v0 < value ? value : v0) - value;
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

struct Unk_137bab0 {
    u8 _0[0x17c];
    u32 field_17c;
};
PKMN_OFFSET_ASSERT(Unk_137bab0, field_17c, 0x17c);

void Unk_136e780(u32, u32);

// 0x710137bab0
u32 Unk_137bab0_call(Unk_137bab0* self, u32 value) {
    self->field_17c = value < 0x270f ? value : 0x270f;
    Unk_136e780(0x19, value < 0x270f ? value : 0x270f);
    return value < 0x270f ? value : 0x270f;
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

struct Unk_137bbc0 {
    u8 _0[0x27e];
    u16 field_27e;
};
PKMN_OFFSET_ASSERT(Unk_137bbc0, field_27e, 0x27e);

// 0x710137bbc0
u32 Unk_137bbc0_update(Unk_137bbc0* self) {
    u16 v0 = self->field_27e;
    if (v0 == 0) {
        return 0;
    }
    self->field_27e = v0 - 1;
    return (v0 - 1) & 0xffff;
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

void Unk_1390b90();

// 0x71013825d0
void Unk_13825d0_call() {
    Unk_1390b90();
}

// 0x71013825e0
void Unk_13825e0_update() {}

// 0x71013825f0
void Unk_13825f0_update() {}

// 0x7101382600
void Unk_1382600_update() {}

// 0x71013828a0
void Unk_13828a0_update() {}

// 0x71013828b0
void Unk_13828b0_update() {}

// 0x71013828c0
void Unk_13828c0_update() {}

// 0x71013828d0
void Unk_13828d0_update() {}

// 0x7101382b70
void Unk_1382b70_update() {}

// 0x7101382b80
void Unk_1382b80_update() {}

// 0x7101382b90
void Unk_1382b90_update() {}

// 0x7101382ba0
void Unk_1382ba0_update() {}

void Unk_1376a70();

// 0x7101382e40
void Unk_1382e40_call() {
    Unk_1376a70();
}

// 0x7101382e50
void Unk_1382e50_update() {}

// 0x7101382e60
void Unk_1382e60_update() {}

// 0x7101382e70
void Unk_1382e70_update() {}

// 0x7101383110
void Unk_1383110_update() {}

// 0x7101383120
void Unk_1383120_update() {}

// 0x7101383130
void Unk_1383130_update() {}

// 0x7101383140
void Unk_1383140_update() {}

// 0x71013833e0
void Unk_13833e0_update() {}

// 0x71013833f0
void Unk_13833f0_update() {}

// 0x7101383400
void Unk_1383400_update() {}

// 0x7101383410
void Unk_1383410_update() {}

void Unk_1387740();

// 0x71013836b0
void Unk_13836b0_call() {
    Unk_1387740();
}

// 0x71013836c0
void Unk_13836c0_update() {}

// 0x71013836d0
void Unk_13836d0_update() {}

// 0x71013836e0
void Unk_13836e0_update() {}

// 0x7101383980
void Unk_1383980_update() {}

// 0x7101383990
void Unk_1383990_update() {}

// 0x71013839a0
void Unk_13839a0_update() {}

// 0x71013839b0
void Unk_13839b0_update() {}

// 0x7101383c50
void Unk_1383c50_update() {}

// 0x7101383c60
void Unk_1383c60_update() {}

// 0x7101383c70
void Unk_1383c70_update() {}

// 0x7101383c80
void Unk_1383c80_update() {}

void Unk_138cba0();

// 0x7101383f20
void Unk_1383f20_call() {
    Unk_138cba0();
}

// 0x7101383f30
void Unk_1383f30_update() {}

// 0x7101383f40
void Unk_1383f40_update() {}

// 0x7101383f50
void Unk_1383f50_update() {}

// 0x71013841f0
void Unk_13841f0_update() {}

// 0x7101384200
void Unk_1384200_update() {}

// 0x7101384210
void Unk_1384210_update() {}

// 0x7101384220
void Unk_1384220_update() {}

// 0x71013844c0
void Unk_13844c0_update() {}

// 0x71013844d0
void Unk_13844d0_update() {}

// 0x71013844e0
void Unk_13844e0_update() {}

// 0x71013844f0
void Unk_13844f0_update() {}

void Unk_13925f0();

// 0x7101384790
void Unk_1384790_call() {
    Unk_13925f0();
}

// 0x71013847a0
void Unk_13847a0_update() {}

// 0x71013847b0
void Unk_13847b0_update() {}

// 0x71013847c0
void Unk_13847c0_update() {}

// 0x7101384a60
void Unk_1384a60_update() {}

// 0x7101384a70
void Unk_1384a70_update() {}

// 0x7101384a80
void Unk_1384a80_update() {}

// 0x7101384a90
void Unk_1384a90_update() {}

// 0x7101384d30
void Unk_1384d30_update() {}

// 0x7101384d40
void Unk_1384d40_update() {}

// 0x7101384d50
void Unk_1384d50_update() {}

// 0x7101384d60
void Unk_1384d60_update() {}

void Unk_1397ae0();

// 0x7101385000
void Unk_1385000_call() {
    Unk_1397ae0();
}

// 0x7101385010
void Unk_1385010_update() {}

// 0x7101385020
void Unk_1385020_update() {}

// 0x7101385030
void Unk_1385030_update() {}

// 0x71013852d0
void Unk_13852d0_update() {}

// 0x71013852e0
void Unk_13852e0_update() {}

// 0x71013852f0
void Unk_13852f0_update() {}

// 0x7101385300
void Unk_1385300_update() {}

void Unk_1397c60();

// 0x71013855a0
void Unk_13855a0_call() {
    Unk_1397c60();
}

// 0x71013855b0
void Unk_13855b0_update() {}

// 0x71013855c0
void Unk_13855c0_update() {}

// 0x71013855d0
void Unk_13855d0_update() {}

// 0x7101385880
void Unk_1385880_update() {}

// 0x7101385890
void Unk_1385890_update() {}

// 0x71013858a0
void Unk_13858a0_update() {}

// 0x7101385b40
void Unk_1385b40_update() {}

// 0x7101385b50
void Unk_1385b50_update() {}

// 0x7101385b60
void Unk_1385b60_update() {}

// 0x7101385b70
void Unk_1385b70_update() {}

// 0x7101385e10
void Unk_1385e10_update() {}

// 0x7101385e20
void Unk_1385e20_update() {}

// 0x7101385e30
void Unk_1385e30_update() {}

// 0x7101385e40
void Unk_1385e40_update() {}

void Unk_138dbc0();

// 0x71013860e0
void Unk_13860e0_call() {
    Unk_138dbc0();
}

// 0x71013860f0
void Unk_13860f0_update() {}

// 0x7101386100
void Unk_1386100_update() {}

// 0x7101386110
void Unk_1386110_update() {}

// 0x71013863b0
void Unk_13863b0_update() {}

// 0x71013863c0
void Unk_13863c0_update() {}

// 0x71013863d0
void Unk_13863d0_update() {}

// 0x71013863e0
void Unk_13863e0_update() {}

// 0x7101386680
void Unk_1386680_update() {}

// 0x7101386690
void Unk_1386690_update() {}

// 0x71013866a0
void Unk_13866a0_update() {}

// 0x71013866b0
void Unk_13866b0_update() {}

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

struct Unk_27efb1c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27efb1c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27efb1c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27efb1c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27efb1c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27efb1c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27efb1c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27efb1c_Data, field_18, 0x18);

extern Unk_27efb1c_Data Unk_27efb1c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710138c6e0
void Unk_138c6e0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27efb1c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27efb1c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27efb1c.field_18 = 0xffff;
    Unk_27efb1c.field_10 = 0;
    Unk_27efb1c.field_8 = r2;
    Unk_27efb1c.field_c = 0;
    Unk_27efb1c.field_14 = 0xffffffff;
}
