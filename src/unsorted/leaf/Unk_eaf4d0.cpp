// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_eaf4d0 {
    u8 _0[0x54];
    u8 field_54;
    u8 _55[0x3];
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_eaf4d0, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_eaf4d0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_eaf4d0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_eaf4d0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_eaf4d0, field_70, 0x70);

// 0x7100eaf4d0
void Unk_eaf4d0_set(Unk_eaf4d0* self) {
    self->field_54 = 0;
    self->field_70 = 0;
    self->field_58 = 0;
    self->field_60 = 0;
    self->field_68 = 0;
}

struct Unk_eb1810 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_eb1810, field_148, 0x148);

// 0x7100eb1810
bool Unk_eb1810_check(const Unk_eb1810* self) {
    return self->field_148 != 0;
}

struct Unk_eb50f0_60 {
    u8 _0[0x48];
    bool field_48;
};
PKMN_OFFSET_ASSERT(Unk_eb50f0_60, field_48, 0x48);

struct Unk_eb50f0 {
    u8 _0[0x60];
    Unk_eb50f0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_eb50f0, field_60, 0x60);

// 0x7100eb50f0
void Unk_eb50f0_set(const Unk_eb50f0* self, bool value) {
    self->field_60->field_48 = value;
}

struct Unk_eb5c60 {
    u8 _0[0x40];
    s32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_eb5c60, field_40, 0x40);

// 0x7100eb5c60
bool Unk_eb5c60_check(const Unk_eb5c60* self) {
    return self->field_40 > 1;
}

struct Unk_eb5c70 {
    u8 _0[0x40];
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_eb5c70, field_40, 0x40);

// 0x7100eb5c70
bool Unk_eb5c70_check(const Unk_eb5c70* self) {
    return (self->field_40 | 1) == 3;
}

void Unk_eb6230(void*, u32);

// 0x7100eb6070
void Unk_eb6070_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_eb66b0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u32);
};

struct Unk_eb66b0 {
    Unk_eb66b0_0* field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb66b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb66b0, field_8, 0x8);

// 0x7100eb66b0
u32 Unk_eb66b0_call(const Unk_eb66b0* self) {
    self->field_0->vf12(self->field_8);
    return 1;
}

// 0x7100eb66e0
void Unk_eb66e0_update() {}

struct Unk_eb66f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb66f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb66f0, field_8, 0x8);

// 0x7100eb66f0
void Unk_eb66f0_set(const Unk_eb66f0* self, Unk_eb66f0* value) {
    *value = *self;
}

struct Unk_eb6700 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb6700, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb6700, field_8, 0x8);

// 0x7100eb6700
void Unk_eb6700_set(const Unk_eb6700* self, Unk_eb6700* value) {
    *value = *self;
}

struct Unk_eb6710_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u32);
};

struct Unk_eb6710 {
    Unk_eb6710_0* field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb6710, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb6710, field_8, 0x8);

// 0x7100eb6710
u32 Unk_eb6710_call(const Unk_eb6710* self) {
    self->field_0->vf12(self->field_8);
    return 1;
}

// 0x7100eb6740
void Unk_eb6740_update() {}

struct Unk_eb6750 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb6750, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb6750, field_8, 0x8);

// 0x7100eb6750
void Unk_eb6750_set(const Unk_eb6750* self, Unk_eb6750* value) {
    *value = *self;
}

struct Unk_eb6760 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb6760, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb6760, field_8, 0x8);

// 0x7100eb6760
void Unk_eb6760_set(const Unk_eb6760* self, Unk_eb6760* value) {
    *value = *self;
}

struct Unk_eb6770_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u32);
};

struct Unk_eb6770 {
    Unk_eb6770_0* field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb6770, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb6770, field_8, 0x8);

// 0x7100eb6770
u32 Unk_eb6770_call(const Unk_eb6770* self) {
    self->field_0->vf12(self->field_8);
    return 1;
}

// 0x7100eb67a0
void Unk_eb67a0_update() {}

struct Unk_eb67b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb67b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb67b0, field_8, 0x8);

// 0x7100eb67b0
void Unk_eb67b0_set(const Unk_eb67b0* self, Unk_eb67b0* value) {
    *value = *self;
}

struct Unk_eb67c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb67c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb67c0, field_8, 0x8);

// 0x7100eb67c0
void Unk_eb67c0_set(const Unk_eb67c0* self, Unk_eb67c0* value) {
    *value = *self;
}

struct Unk_eb67d0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u32);
};

struct Unk_eb67d0 {
    Unk_eb67d0_0* field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb67d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb67d0, field_8, 0x8);

// 0x7100eb67d0
u32 Unk_eb67d0_call(const Unk_eb67d0* self) {
    self->field_0->vf12(self->field_8);
    return 1;
}

// 0x7100eb6800
void Unk_eb6800_update() {}

struct Unk_eb6810 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb6810, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb6810, field_8, 0x8);

// 0x7100eb6810
void Unk_eb6810_set(const Unk_eb6810* self, Unk_eb6810* value) {
    *value = *self;
}

struct Unk_eb6820 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_eb6820, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_eb6820, field_8, 0x8);

// 0x7100eb6820
void Unk_eb6820_set(const Unk_eb6820* self, Unk_eb6820* value) {
    *value = *self;
}

void Unk_eb6a00();
void Unk_eb6ba0(void*);

// 0x7100eb6b70
void Unk_eb6b70_call(void* self) {
    Unk_eb6a00();
    Unk_eb6ba0(self);
}

struct Unk_14e4110;
struct Unk_eb7070 {
    u8 _0[0x18];
    Unk_14e4110* field_18;
};
PKMN_OFFSET_ASSERT(Unk_eb7070, field_18, 0x18);

void Unk_14e4110_set(Unk_14e4110*);

// 0x7100eb7070
void Unk_eb7070_call(const Unk_eb7070* self) {
    Unk_14e4110_set(self->field_18);
}

// 0x7100eb7250
void Unk_eb7250_update() {}

struct Unk_eb7260_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eb7260_arg1, field_0, 0x0);

struct Unk_eb7260 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eb7260, field_0, 0x0);

// 0x7100eb7260
void Unk_eb7260_set(const Unk_eb7260* self, Unk_eb7260_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_eb7270_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eb7270_arg1, field_0, 0x0);

struct Unk_eb7270 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eb7270, field_0, 0x0);

// 0x7100eb7270
void Unk_eb7270_set(const Unk_eb7270* self, Unk_eb7270_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_eb76a0 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_eb76a0, field_5d0, 0x5d0);

void Unk_14eaa70(u64);

// 0x7100eb76a0
void Unk_eb76a0_call(const Unk_eb76a0* self) {
    Unk_14eaa70(self->field_5d0);
}

struct Unk_eb7720 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_eb7720, field_5d0, 0x5d0);

void Unk_14eaaf0(u64);

// 0x7100eb7720
void Unk_eb7720_call(const Unk_eb7720* self) {
    Unk_14eaaf0(self->field_5d0);
}

struct Unk_eb8ea0_5e0 {
    u8 _0[0x5c];
    u32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_eb8ea0_5e0, field_5c, 0x5c);

struct Unk_eb8ea0 {
    u8 _0[0x5e0];
    Unk_eb8ea0_5e0* field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_eb8ea0, field_5e0, 0x5e0);

// 0x7100eb8ea0
u32 Unk_eb8ea0_get(const Unk_eb8ea0* self) {
    if (self->field_5e0 == nullptr) {
        return 0;
    }
    return self->field_5e0->field_5c;
}

// 0x7100eb8fc0
void Unk_eb8fc0_update() {}

// 0x7100eb8fd0
void Unk_eb8fd0_update() {}

struct Unk_eb8fe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eb8fe0_arg1, field_0, 0x0);

struct Unk_eb8fe0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eb8fe0, field_0, 0x0);

// 0x7100eb8fe0
void Unk_eb8fe0_set(const Unk_eb8fe0* self, Unk_eb8fe0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_eb8ff0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eb8ff0_arg1, field_0, 0x0);

struct Unk_eb8ff0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eb8ff0, field_0, 0x0);

// 0x7100eb8ff0
void Unk_eb8ff0_set(const Unk_eb8ff0* self, Unk_eb8ff0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ebb1f0_b40 {
    u8 _0[0x198];
    u32 field_198;
};
PKMN_OFFSET_ASSERT(Unk_ebb1f0_b40, field_198, 0x198);

struct Unk_ebb1f0 {
    u8 _0[0xb40];
    Unk_ebb1f0_b40* field_b40;
};
PKMN_OFFSET_ASSERT(Unk_ebb1f0, field_b40, 0xb40);

// 0x7100ebb1f0
bool Unk_ebb1f0_check(const Unk_ebb1f0* self) {
    if (self->field_b40 == nullptr) {
        return false;
    }
    return self->field_b40->field_198 == 3;
}

// 0x7100ebb860
void Unk_ebb860_update() {}

struct Unk_ebb870 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ebb870, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ebb870, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ebb870, field_10, 0x10);

// 0x7100ebb870
void Unk_ebb870_set(const Unk_ebb870* self, Unk_ebb870* value) {
    *value = *self;
}

struct Unk_ebb890 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ebb890, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ebb890, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ebb890, field_10, 0x10);

// 0x7100ebb890
void Unk_ebb890_set(const Unk_ebb890* self, Unk_ebb890* value) {
    *value = *self;
}

struct Unk_ebc2f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebc2f0_arg1, field_0, 0x0);

struct Unk_ebc2f0 {
    u8 _0[0x6b8];
    u64 field_6b8;
};
PKMN_OFFSET_ASSERT(Unk_ebc2f0, field_6b8, 0x6b8);

void Unk_67bc30(u64, u64);

// 0x7100ebc2f0
void Unk_ebc2f0_call(const Unk_ebc2f0* self, const Unk_ebc2f0_arg1* value) {
    Unk_67bc30(self->field_6b8, value->field_0);
}

// 0x7100ebcb20
void Unk_ebcb20_update() {}

struct Unk_ebcb30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcb30_arg1, field_0, 0x0);

struct Unk_ebcb30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcb30, field_0, 0x0);

// 0x7100ebcb30
void Unk_ebcb30_set(const Unk_ebcb30* self, Unk_ebcb30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ebcb40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcb40_arg1, field_0, 0x0);

struct Unk_ebcb40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcb40, field_0, 0x0);

// 0x7100ebcb40
void Unk_ebcb40_set(const Unk_ebcb40* self, Unk_ebcb40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ebcba0
void Unk_ebcba0_update() {}

struct Unk_ebcbb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcbb0_arg1, field_0, 0x0);

struct Unk_ebcbb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcbb0, field_0, 0x0);

// 0x7100ebcbb0
void Unk_ebcbb0_set(const Unk_ebcbb0* self, Unk_ebcbb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ebcbc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcbc0_arg1, field_0, 0x0);

struct Unk_ebcbc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcbc0, field_0, 0x0);

// 0x7100ebcbc0
void Unk_ebcbc0_set(const Unk_ebcbc0* self, Unk_ebcbc0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ebcbe0
void Unk_ebcbe0_update() {}

struct Unk_ebcbf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcbf0_arg1, field_0, 0x0);

struct Unk_ebcbf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcbf0, field_0, 0x0);

// 0x7100ebcbf0
void Unk_ebcbf0_set(const Unk_ebcbf0* self, Unk_ebcbf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ebcc00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcc00_arg1, field_0, 0x0);

struct Unk_ebcc00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcc00, field_0, 0x0);

// 0x7100ebcc00
void Unk_ebcc00_set(const Unk_ebcc00* self, Unk_ebcc00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ebcc60
void Unk_ebcc60_update() {}

struct Unk_ebcc70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcc70_arg1, field_0, 0x0);

struct Unk_ebcc70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcc70, field_0, 0x0);

// 0x7100ebcc70
void Unk_ebcc70_set(const Unk_ebcc70* self, Unk_ebcc70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ebcc80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcc80_arg1, field_0, 0x0);

struct Unk_ebcc80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcc80, field_0, 0x0);

// 0x7100ebcc80
void Unk_ebcc80_set(const Unk_ebcc80* self, Unk_ebcc80_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ebcca0
void Unk_ebcca0_update() {}

struct Unk_ebccb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebccb0_arg1, field_0, 0x0);

struct Unk_ebccb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebccb0, field_0, 0x0);

// 0x7100ebccb0
void Unk_ebccb0_set(const Unk_ebccb0* self, Unk_ebccb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ebccc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebccc0_arg1, field_0, 0x0);

struct Unk_ebccc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebccc0, field_0, 0x0);

// 0x7100ebccc0
void Unk_ebccc0_set(const Unk_ebccc0* self, Unk_ebccc0_arg1* value) {
    value->field_0 = self->field_0;
}

void Unk_eb6230(void*, u32);

// 0x7100ec2fb0
void Unk_ec2fb0_call(void* self) {
    Unk_eb6230(self, 3);
}

void Unk_eb6230(void*, u32);

// 0x7100ec6e20
void Unk_ec6e20_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_ec6e30_5d0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_ec6e30_5d0, field_58, 0x58);

struct Unk_ec6e30 {
    u8 _0[0x5d0];
    Unk_ec6e30_5d0* field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_ec6e30, field_5d0, 0x5d0);

// 0x7100ec6e30
u32 Unk_ec6e30_get(const Unk_ec6e30* self) {
    return self->field_5d0->field_58 & 1;
}
