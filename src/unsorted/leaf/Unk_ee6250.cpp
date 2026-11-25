// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ee6250 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_ee6250, field_58, 0x58);

void Unk_ee6260(void*, u64);

// 0x7100ee6250
void Unk_ee6250_call(const Unk_ee6250* self, u64 value) {
    if (self->field_58 != nullptr) {
        Unk_ee6260(self->field_58, value);
    }
}

struct Unk_ee7580 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_ee7580, field_58, 0x58);

void Unk_ee7590(void*, void*, u64, void*, u64);

// 0x7100ee7580
void Unk_ee7580_call(const Unk_ee7580* self, void* value, u64 arg2, void* arg3, u64 arg4) {
    if (self->field_58 != nullptr) {
        Unk_ee7590(self->field_58, value, arg2, arg3, arg4);
    }
}

struct Unk_ee76c0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_ee76c0, field_58, 0x58);

void Unk_ee76d0(void*);

// 0x7100ee76c0
void Unk_ee76c0_call(const Unk_ee76c0* self) {
    if (self->field_58 != nullptr) {
        Unk_ee76d0(self->field_58);
    }
}

struct Unk_ee79c0_58 {
    u8 _0[0x198];
    u8 field_198;
};
PKMN_OFFSET_ASSERT(Unk_ee79c0_58, field_198, 0x198);

struct Unk_ee79c0 {
    u8 _0[0x58];
    Unk_ee79c0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_ee79c0, field_58, 0x58);

// 0x7100ee79c0
u8* Unk_ee79c0_get(const Unk_ee79c0* self) {
    return &self->field_58->field_198;
}

// 0x7100ee79d0
void Unk_ee79d0() {}

// 0x7100ee9ba0
void Unk_ee9ba0_update() {}

struct Unk_ee9bb0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ee9bb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ee9bb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ee9bb0, field_10, 0x10);

// 0x7100ee9bb0
void Unk_ee9bb0_set(const Unk_ee9bb0* self, Unk_ee9bb0* value) {
    *value = *self;
}

struct Unk_ee9bd0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ee9bd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ee9bd0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ee9bd0, field_10, 0x10);

// 0x7100ee9bd0
void Unk_ee9bd0_set(const Unk_ee9bd0* self, Unk_ee9bd0* value) {
    *value = *self;
}

struct Unk_eeb410 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eeb410, field_0, 0x0);

// 0x7100eeb410
u32 Unk_eeb410_getField0(const Unk_eeb410* self) {
    return self->field_0;
}

struct Unk_eef800 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_eef800, field_0, 0x0);

void Unk_eb6230(void*, u32);

// 0x7100eef800
void Unk_eef800_call(const Unk_eef800* self) {
    Unk_eb6230(self->field_0, 3);
}

// 0x7100eef810
void Unk_eef810_update() {}

struct Unk_eef820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eef820_arg1, field_0, 0x0);

struct Unk_eef820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eef820, field_0, 0x0);

// 0x7100eef820
void Unk_eef820_set(const Unk_eef820* self, Unk_eef820_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_eef830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eef830_arg1, field_0, 0x0);

struct Unk_eef830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eef830, field_0, 0x0);

// 0x7100eef830
void Unk_eef830_set(const Unk_eef830* self, Unk_eef830_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ef3930_5d0_1f8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_ef3930_5d0_1f8, field_58, 0x58);

struct Unk_ef3930_5d0_60 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef3930_5d0_60, field_0, 0x0);

struct Unk_ef3930_5d0 {
    u8 _0[0x60];
    Unk_ef3930_5d0_60* field_60;
    u8 field_68;
    u8 _69[0x18f];
    Unk_ef3930_5d0_1f8* field_1f8;
};
PKMN_OFFSET_ASSERT(Unk_ef3930_5d0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_ef3930_5d0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_ef3930_5d0, field_1f8, 0x1f8);

struct Unk_ef3930 {
    u8 _0[0x5d0];
    Unk_ef3930_5d0* field_5d0;
    u8 _5d8[0xc0];
    u64 field_698;
};
PKMN_OFFSET_ASSERT(Unk_ef3930, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_ef3930, field_698, 0x698);

u32 Unk_ef8720(void*, u32);
u64 Unk_ef8700(void*, u32, u32);

// 0x7100ef3930
void Unk_ef3930_call(Unk_ef3930* self) {
    if (self->field_5d0->field_60->field_0 == 0) {
        if (self->field_5d0->field_1f8->field_58 != 1)
            return;
        if (self->field_698 != 0xd009f2ab0d98b2d7)
            return;
        u32 r0 = Unk_ef8720(&self->field_5d0->field_68, 1);
        if (r0 == 0)
            return;
        u64 r1 = Unk_ef8700(&self->field_5d0->field_68, 1, 0);
        if (r1 == 0xd009f2ab0d98b2d7)
            return;
        self->field_698 = r1;
    }
}

struct Unk_ef3dd0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x110];
    u32 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_ef3dd0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_ef3dd0, field_5d8, 0x5d8);

void Unk_1500c40(u64);

// 0x7100ef3dd0
void Unk_ef3dd0_call(Unk_ef3dd0* self) {
    self->field_5d8 = 1;
    if (self->field_4c0 != 0) {
        Unk_1500c40(self->field_4c0);
    }
}

struct Unk_ef3df0 {
    u8 _0[0x4c0];
    void* field_4c0;
    u8 _4c8[0x110];
    u32 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_ef3df0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_ef3df0, field_5d8, 0x5d8);

void Unk_1500c90(void*);

// 0x7100ef3df0
void Unk_ef3df0_call(Unk_ef3df0* self) {
    self->field_5d8 = 0;
    if (self->field_4c0 != nullptr) {
        Unk_1500c90(self->field_4c0);
    }
}

struct Unk_ef4580 {
    u8 _0[0x688];
    u64 field_688;
};
PKMN_OFFSET_ASSERT(Unk_ef4580, field_688, 0x688);

void Unk_eb75e0(u64);

// 0x7100ef4580
void Unk_ef4580_call(const Unk_ef4580* self) {
    Unk_eb75e0(self->field_688);
}

// 0x7100ef77a0
void Unk_ef77a0_update() {}

struct Unk_ef77b0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ef77b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef77b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ef77b0, field_10, 0x10);

// 0x7100ef77b0
void Unk_ef77b0_set(const Unk_ef77b0* self, Unk_ef77b0* value) {
    *value = *self;
}

struct Unk_ef77d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ef77d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef77d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ef77d0, field_10, 0x10);

// 0x7100ef77d0
void Unk_ef77d0_set(const Unk_ef77d0* self, Unk_ef77d0* value) {
    *value = *self;
}

// 0x7100ef7850
void Unk_ef7850_update() {}

struct Unk_ef7860_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7860_arg1, field_0, 0x0);

struct Unk_ef7860 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7860, field_0, 0x0);

// 0x7100ef7860
void Unk_ef7860_set(const Unk_ef7860* self, Unk_ef7860_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ef7870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7870_arg1, field_0, 0x0);

struct Unk_ef7870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7870, field_0, 0x0);

// 0x7100ef7870
void Unk_ef7870_set(const Unk_ef7870* self, Unk_ef7870_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ef78e0
void Unk_ef78e0_update() {}

struct Unk_ef78f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef78f0_arg1, field_0, 0x0);

struct Unk_ef78f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef78f0, field_0, 0x0);

// 0x7100ef78f0
void Unk_ef78f0_set(const Unk_ef78f0* self, Unk_ef78f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ef7900_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7900_arg1, field_0, 0x0);

struct Unk_ef7900 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7900, field_0, 0x0);

// 0x7100ef7900
void Unk_ef7900_set(const Unk_ef7900* self, Unk_ef7900_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ef79a0
void Unk_ef79a0_update() {}

struct Unk_ef79b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef79b0_arg1, field_0, 0x0);

struct Unk_ef79b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef79b0, field_0, 0x0);

// 0x7100ef79b0
void Unk_ef79b0_set(const Unk_ef79b0* self, Unk_ef79b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ef79c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef79c0_arg1, field_0, 0x0);

struct Unk_ef79c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef79c0, field_0, 0x0);

// 0x7100ef79c0
void Unk_ef79c0_set(const Unk_ef79c0* self, Unk_ef79c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ef7a60
void Unk_ef7a60_update() {}

struct Unk_ef7a70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7a70_arg1, field_0, 0x0);

struct Unk_ef7a70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7a70, field_0, 0x0);

// 0x7100ef7a70
void Unk_ef7a70_set(const Unk_ef7a70* self, Unk_ef7a70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ef7a80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7a80_arg1, field_0, 0x0);

struct Unk_ef7a80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7a80, field_0, 0x0);

// 0x7100ef7a80
void Unk_ef7a80_set(const Unk_ef7a80* self, Unk_ef7a80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ef7a90_0 {
    u8 _0[0x5d8];
    u32 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_ef7a90_0, field_5d8, 0x5d8);

struct Unk_ef7a90 {
    Unk_ef7a90_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7a90, field_0, 0x0);

// 0x7100ef7a90
void Unk_ef7a90_set(const Unk_ef7a90* self) {
    self->field_0->field_5d8 = 3;
}

// 0x7100ef7aa0
void Unk_ef7aa0_update() {}

struct Unk_ef7ab0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7ab0_arg1, field_0, 0x0);

struct Unk_ef7ab0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7ab0, field_0, 0x0);

// 0x7100ef7ab0
void Unk_ef7ab0_set(const Unk_ef7ab0* self, Unk_ef7ab0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ef7ac0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7ac0_arg1, field_0, 0x0);

struct Unk_ef7ac0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7ac0, field_0, 0x0);

// 0x7100ef7ac0
void Unk_ef7ac0_set(const Unk_ef7ac0* self, Unk_ef7ac0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ef7b90
void Unk_ef7b90_update() {}

struct Unk_ef7ba0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7ba0_arg1, field_0, 0x0);

struct Unk_ef7ba0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7ba0, field_0, 0x0);

// 0x7100ef7ba0
void Unk_ef7ba0_set(const Unk_ef7ba0* self, Unk_ef7ba0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ef7bb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7bb0_arg1, field_0, 0x0);

struct Unk_ef7bb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ef7bb0, field_0, 0x0);

// 0x7100ef7bb0
void Unk_ef7bb0_set(const Unk_ef7bb0* self, Unk_ef7bb0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ef7d00
void Unk_ef7d00_update() {}

struct Unk_ef7d10 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_ef7d10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef7d10, field_8, 0x8);

// 0x7100ef7d10
void Unk_ef7d10_set(const Unk_ef7d10* self, Unk_ef7d10* value) {
    *value = *self;
}

struct Unk_ef7d20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_ef7d20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef7d20, field_8, 0x8);

// 0x7100ef7d20
void Unk_ef7d20_set(const Unk_ef7d20* self, Unk_ef7d20* value) {
    *value = *self;
}

// 0x7100ef7e00
void Unk_ef7e00_update() {}

struct Unk_ef7e10 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_ef7e10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef7e10, field_8, 0x8);

// 0x7100ef7e10
void Unk_ef7e10_set(const Unk_ef7e10* self, Unk_ef7e10* value) {
    *value = *self;
}

struct Unk_ef7e20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_ef7e20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef7e20, field_8, 0x8);

// 0x7100ef7e20
void Unk_ef7e20_set(const Unk_ef7e20* self, Unk_ef7e20* value) {
    *value = *self;
}

// 0x7100ef7ec0
void Unk_ef7ec0_update() {}

struct Unk_ef7ed0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ef7ed0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef7ed0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ef7ed0, field_10, 0x10);

// 0x7100ef7ed0
void Unk_ef7ed0_set(const Unk_ef7ed0* self, Unk_ef7ed0* value) {
    *value = *self;
}

struct Unk_ef7ef0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ef7ef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef7ef0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ef7ef0, field_10, 0x10);

// 0x7100ef7ef0
void Unk_ef7ef0_set(const Unk_ef7ef0* self, Unk_ef7ef0* value) {
    *value = *self;
}

// 0x7100ef9520
void Unk_ef9520_update() {}

struct Unk_ef9530 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ef9530, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef9530, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ef9530, field_10, 0x10);

// 0x7100ef9530
void Unk_ef9530_set(const Unk_ef9530* self, Unk_ef9530* value) {
    *value = *self;
}

struct Unk_ef9550 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ef9550, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ef9550, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ef9550, field_10, 0x10);

// 0x7100ef9550
void Unk_ef9550_set(const Unk_ef9550* self, Unk_ef9550* value) {
    *value = *self;
}

// 0x7100efca00
void Unk_efca00_update() {}

struct Unk_efca10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_efca10_arg1, field_0, 0x0);

struct Unk_efca10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_efca10, field_0, 0x0);

// 0x7100efca10
void Unk_efca10_set(const Unk_efca10* self, Unk_efca10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_efca20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_efca20_arg1, field_0, 0x0);

struct Unk_efca20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_efca20, field_0, 0x0);

// 0x7100efca20
void Unk_efca20_set(const Unk_efca20* self, Unk_efca20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_efcb80 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_efcb80, field_6c, 0x6c);

// 0x7100efcb80
void Unk_efcb80_setField6c(Unk_efcb80* self, u32 value) {
    self->field_6c = value;
}

struct Unk_efd570 {
    u8 _0[0x720];
    u64 field_720;
};
PKMN_OFFSET_ASSERT(Unk_efd570, field_720, 0x720);

// 0x7100efd570
void Unk_efd570_setField720(Unk_efd570* self, u64 value) {
    self->field_720 = value;
}

struct Unk_27e0e34_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e0e34_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e0e34_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e0e34_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e0e34_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e0e34_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e0e34_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e0e34_Data, field_18, 0x18);

extern Unk_27e0e34_Data Unk_27e0e34 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100eff720
void Unk_eff720_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e0e34.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e0e34.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e0e34.field_18 = 0xffff;
    Unk_27e0e34.field_10 = 0;
    Unk_27e0e34.field_8 = r2;
    Unk_27e0e34.field_c = 0;
    Unk_27e0e34.field_14 = 0xffffffff;
}
