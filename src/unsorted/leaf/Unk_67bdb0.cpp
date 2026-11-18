// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_67bdb0 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_67bdb0, field_58, 0x58);

// 0x710067bdb0
u64 Unk_67bdb0_getField58(const Unk_67bdb0* self) {
    return self->field_58;
}

struct Unk_67bdc0 {
    u8 _0[0x7a];
    u16 field_7a;
};
PKMN_OFFSET_ASSERT(Unk_67bdc0, field_7a, 0x7a);

// 0x710067bdc0
u16 Unk_67bdc0_getField7a(const Unk_67bdc0* self) {
    return self->field_7a;
}

struct Unk_67bdd0 {
    u8 _0[0x78];
    u16 field_78;
};
PKMN_OFFSET_ASSERT(Unk_67bdd0, field_78, 0x78);

// 0x710067bdd0
u16 Unk_67bdd0_getField78(const Unk_67bdd0* self) {
    return self->field_78;
}

// 0x710067c960
void Unk_67c960() {}

struct Unk_67d360_90 {
    u8 _0[0x2];
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_67d360_90, field_2, 0x2);

struct Unk_67d360 {
    u8 _0[0x90];
    Unk_67d360_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_67d360, field_90, 0x90);

// 0x710067d360
u16 Unk_67d360_get(const Unk_67d360* self) {
    return self->field_90->field_2;
}

struct Unk_67e9f0 {
    u8 _0[0x9d];
    u8 field_9d;
    u8 _9e[0x6];
    u8 field_a4;
    u8 field_a5;
    u8 field_a6;
};
PKMN_OFFSET_ASSERT(Unk_67e9f0, field_9d, 0x9d);
PKMN_OFFSET_ASSERT(Unk_67e9f0, field_a4, 0xa4);
PKMN_OFFSET_ASSERT(Unk_67e9f0, field_a5, 0xa5);
PKMN_OFFSET_ASSERT(Unk_67e9f0, field_a6, 0xa6);

// 0x710067e9f0
void Unk_67e9f0_set(Unk_67e9f0* self, u8 value, u8 arg2) {
    self->field_9d = value;
    self->field_a5 = value;
    self->field_a4 = arg2;
    self->field_a6 = arg2;
}

struct Unk_67ea10 {
    u8 _0[0x9d];
    u8 field_9d;
    u8 _9e[0x6];
    u8 field_a4;
};
PKMN_OFFSET_ASSERT(Unk_67ea10, field_9d, 0x9d);
PKMN_OFFSET_ASSERT(Unk_67ea10, field_a4, 0xa4);

// 0x710067ea10
void Unk_67ea10_set(Unk_67ea10* self, u8 value, u8 arg2) {
    self->field_9d = value;
    self->field_a4 = arg2;
}

struct Unk_67ea20_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_67ea20_arg1, field_0, 0x0);

struct Unk_67ea20_arg2 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_67ea20_arg2, field_0, 0x0);

struct Unk_67ea20 {
    u8 _0[0x9d];
    u8 field_9d;
    u8 _9e[0x6];
    u8 field_a4;
};
PKMN_OFFSET_ASSERT(Unk_67ea20, field_9d, 0x9d);
PKMN_OFFSET_ASSERT(Unk_67ea20, field_a4, 0xa4);

// 0x710067ea20
void Unk_67ea20_set(const Unk_67ea20* self, Unk_67ea20_arg1* value, Unk_67ea20_arg2* arg2) {
    value->field_0 = self->field_9d;
    arg2->field_0 = self->field_a4;
}

struct Unk_67ea40 {
    u8 _0[0x94];
    u16 field_94;
};
PKMN_OFFSET_ASSERT(Unk_67ea40, field_94, 0x94);

// 0x710067ea40
void Unk_67ea40_setField94(Unk_67ea40* self, u16 value) {
    self->field_94 = value;
}

struct Unk_67ea50 {
    u8 _0[0x96];
    u16 field_96;
};
PKMN_OFFSET_ASSERT(Unk_67ea50, field_96, 0x96);

// 0x710067ea50
void Unk_67ea50_setField96(Unk_67ea50* self, u16 value) {
    self->field_96 = value;
}

struct Unk_67f4a0 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_67f4a0, field_a8, 0xa8);

// 0x710067f4a0
void Unk_67f4a0_set(Unk_67f4a0* self) {
    self->field_a8 = 2;
}

struct Unk_67f4b0 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_67f4b0, field_a8, 0xa8);

// 0x710067f4b0
u32 Unk_67f4b0_getFielda8(const Unk_67f4b0* self) {
    return self->field_a8;
}

struct Unk_67f540 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_67f540, field_60, 0x60);

// 0x710067f540
u64 Unk_67f540_getField60(const Unk_67f540* self) {
    return self->field_60;
}

// 0x710067f940
void Unk_67f940_update() {}

struct Unk_67f950_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_67f950_arg1, field_0, 0x0);

struct Unk_67f950 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_67f950, field_0, 0x0);

// 0x710067f950
void Unk_67f950_set(const Unk_67f950* self, Unk_67f950_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_67f960_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_67f960_arg1, field_0, 0x0);

struct Unk_67f960 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_67f960, field_0, 0x0);

// 0x710067f960
void Unk_67f960_set(const Unk_67f960* self, Unk_67f960_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_67fb20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_67fb20, field_0, 0x0);

// 0x710067fb20
void Unk_67fb20_setField0(Unk_67fb20* self, u64 value) {
    self->field_0 = value;
}

struct Unk_680570 {
    u8 _0[0x98];
    f32 field_98;
};
PKMN_OFFSET_ASSERT(Unk_680570, field_98, 0x98);

// 0x7100680570
f32 Unk_680570_getField98(const Unk_680570* self) {
    return self->field_98;
}

struct Unk_680be0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_680be0, field_8, 0x8);

// 0x7100680be0
u8* Unk_680be0_getField8Ptr(Unk_680be0* self) {
    return &self->field_8;
}

struct Unk_680bf0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_680bf0, field_28, 0x28);

// 0x7100680bf0
u8* Unk_680bf0_getField28Ptr(Unk_680bf0* self) {
    return &self->field_28;
}

struct Unk_6812d0 {
    u8 _0[0x48];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_6812d0, field_48, 0x48);

// 0x71006812d0
u32 Unk_6812d0_getField48(const Unk_6812d0* self) {
    return self->field_48;
}

struct Unk_681620 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_681620, field_58, 0x58);

// 0x7100681620
u8* Unk_681620_getField58Ptr(Unk_681620* self) {
    return &self->field_58;
}

// 0x7100681fa0
void Unk_681fa0() {}

struct Unk_683670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_683670_arg1, field_0, 0x0);

struct Unk_683670 {
    u8 _0[0xd0];
    u64 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_683670, field_d0, 0xd0);

// 0x7100683670
void Unk_683670_set(Unk_683670* self, const Unk_683670_arg1* value) {
    self->field_d0 = value->field_0;
}

struct Unk_683680 {
    u8 _0[0xd0];
    u8 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_683680, field_d0, 0xd0);

// 0x7100683680
u8* Unk_683680_getFieldd0Ptr(Unk_683680* self) {
    return &self->field_d0;
}

struct Unk_683690 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_683690, field_10, 0x10);

// 0x7100683690
u8* Unk_683690_getField10Ptr(Unk_683690* self) {
    return &self->field_10;
}

struct Unk_683cc0 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_683cc0, field_90, 0x90);

// 0x7100683cc0
u8* Unk_683cc0_getField90Ptr(Unk_683cc0* self) {
    return &self->field_90;
}

struct Unk_683cd0 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_683cd0, field_50, 0x50);

// 0x7100683cd0
u8* Unk_683cd0_getField50Ptr(Unk_683cd0* self) {
    return &self->field_50;
}

struct Unk_685230 {
    u8 _0[0xb9];
    u8 field_b9;
    u8 _ba[0x1c6];
    u64 field_280;
};
PKMN_OFFSET_ASSERT(Unk_685230, field_b9, 0xb9);
PKMN_OFFSET_ASSERT(Unk_685230, field_280, 0x280);

// 0x7100685230
void Unk_685230_set(Unk_685230* self, u64 value) {
    self->field_280 = value;
    self->field_b9 = 0;
}

struct Unk_685240_c0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_685240_c0, field_18, 0x18);

struct Unk_685240 {
    u8 _0[0xc0];
    Unk_685240_c0* field_c0;
};
PKMN_OFFSET_ASSERT(Unk_685240, field_c0, 0xc0);

// 0x7100685240
u64 Unk_685240_get(const Unk_685240* self) {
    return self->field_c0->field_18;
}

struct Unk_685810 {
    u8 _0[0x2a8];
    u32 field_2a8;
};
PKMN_OFFSET_ASSERT(Unk_685810, field_2a8, 0x2a8);

// 0x7100685810
u32 Unk_685810_getField2a8(const Unk_685810* self) {
    return self->field_2a8;
}

struct Unk_685dc0 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_685dc0, field_c0, 0xc0);

void Unk_179f410(u64);

// 0x7100685dc0
void Unk_685dc0_call(const Unk_685dc0* self) {
    if (self->field_c0 != 0) {
        Unk_179f410(self->field_c0);
    }
}

struct Unk_685dd0 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_685dd0, field_c0, 0xc0);

void Unk_179ef20(u64);

// 0x7100685dd0
void Unk_685dd0_call(const Unk_685dd0* self) {
    if (self->field_c0 != 0) {
        Unk_179ef20(self->field_c0);
    }
}

// 0x71006861c0
void Unk_6861c0_update() {}

struct Unk_6861d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6861d0_arg1, field_0, 0x0);

struct Unk_6861d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6861d0, field_0, 0x0);

// 0x71006861d0
void Unk_6861d0_set(const Unk_6861d0* self, Unk_6861d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6861e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6861e0_arg1, field_0, 0x0);

struct Unk_6861e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6861e0, field_0, 0x0);

// 0x71006861e0
void Unk_6861e0_set(const Unk_6861e0* self, Unk_6861e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100686970
void Unk_686970_update() {}

struct Unk_686980_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686980_arg1, field_0, 0x0);

struct Unk_686980 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686980, field_0, 0x0);

// 0x7100686980
void Unk_686980_set(const Unk_686980* self, Unk_686980_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_686990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686990_arg1, field_0, 0x0);

struct Unk_686990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686990, field_0, 0x0);

// 0x7100686990
void Unk_686990_set(const Unk_686990* self, Unk_686990_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6869a0_0 {
    u8 _0[0x320];
    u8 field_320;
};
PKMN_OFFSET_ASSERT(Unk_6869a0_0, field_320, 0x320);

struct Unk_6869a0 {
    Unk_6869a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_6869a0, field_0, 0x0);

// 0x71006869a0
void Unk_6869a0_set(const Unk_6869a0* self) {
    self->field_0->field_320 = 0;
}

// 0x71006869b0
void Unk_6869b0_update() {}

struct Unk_6869c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6869c0_arg1, field_0, 0x0);

struct Unk_6869c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6869c0, field_0, 0x0);

// 0x71006869c0
void Unk_6869c0_set(const Unk_6869c0* self, Unk_6869c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6869d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6869d0_arg1, field_0, 0x0);

struct Unk_6869d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6869d0, field_0, 0x0);

// 0x71006869d0
void Unk_6869d0_set(const Unk_6869d0* self, Unk_6869d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_686dd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686dd0, field_0, 0x0);

void Unk_686b00(u64);

// 0x7100686dd0
void Unk_686dd0_call(const Unk_686dd0* self) {
    Unk_686b00(self->field_0);
}

// 0x7100686de0
void Unk_686de0_update() {}

struct Unk_686df0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686df0_arg1, field_0, 0x0);

struct Unk_686df0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686df0, field_0, 0x0);

// 0x7100686df0
void Unk_686df0_set(const Unk_686df0* self, Unk_686df0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_686e00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686e00_arg1, field_0, 0x0);

struct Unk_686e00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686e00, field_0, 0x0);

// 0x7100686e00
void Unk_686e00_set(const Unk_686e00* self, Unk_686e00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_686e50 {
    u8 field_0;
    u8 _1[0x7];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_686e50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_686e50, field_8, 0x8);

// 0x7100686e50
void Unk_686e50_set(Unk_686e50* self) {
    if (self->field_0 != 0) {
        self->field_8 = 0;
        self->field_0 = 0;
    }
}

struct Unk_686e70 {
    u8 field_0;
    u8 _1[0x7];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_686e70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_686e70, field_8, 0x8);

// 0x7100686e70
void Unk_686e70_set(Unk_686e70* self) {
    if (self->field_0 != 0) {
        self->field_8 = 0;
        self->field_0 = 0;
    }
}

struct Unk_686fa0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_686fa0, field_0, 0x0);

// 0x7100686fa0
u8 Unk_686fa0_getField0(const Unk_686fa0* self) {
    return self->field_0;
}

struct Unk_6870c0 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_6870c0, field_2, 0x2);

// 0x71006870c0
u8 Unk_6870c0_getField2(const Unk_6870c0* self) {
    return self->field_2;
}

struct Unk_687100 {
    u8 _0[0x3];
    u8 field_3;
};
PKMN_OFFSET_ASSERT(Unk_687100, field_3, 0x3);

// 0x7100687100
u8 Unk_687100_getField3(const Unk_687100* self) {
    return self->field_3;
}

struct Unk_687270 {
    u8 _0[0x1];
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_687270, field_1, 0x1);

// 0x7100687270
u8 Unk_687270_getField1(const Unk_687270* self) {
    return self->field_1;
}

struct Unk_687280 {
    u8 _0[0x1];
    bool field_1;
};
PKMN_OFFSET_ASSERT(Unk_687280, field_1, 0x1);

// 0x7100687280
void Unk_687280_set(Unk_687280* self, bool value) {
    self->field_1 = value;
}

struct Unk_687290 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_687290, field_8, 0x8);

// 0x7100687290
u64 Unk_687290_getField8(const Unk_687290* self) {
    return self->field_8;
}

struct Unk_6872a0 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_6872a0, field_38, 0x38);

// 0x71006872a0
u64 Unk_6872a0_getField38(const Unk_6872a0* self) {
    return self->field_38;
}

struct Unk_687450 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_687450, field_58, 0x58);

void Unk_1798ad0(u64, u64, u64);

// 0x7100687450
void Unk_687450_call(const Unk_687450* self, u64 value, u64 arg2) {
    Unk_1798ad0(self->field_58, arg2, value);
}

struct Unk_687aa0 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_687aa0, field_58, 0x58);

// 0x7100687aa0
u64 Unk_687aa0_getField58(const Unk_687aa0* self) {
    return self->field_58;
}
