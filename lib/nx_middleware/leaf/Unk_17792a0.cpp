// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71017792a0
void Unk_17792a0_update(void* /*unused*/) {
}

struct Unk_17796b0_30 {
    u8 _0[0x9c];
    u32 field_9c;
};
PKMN_OFFSET_ASSERT(Unk_17796b0_30, field_9c, 0x9c);

struct Unk_17796b0 {
    u8 _0[0x30];
    Unk_17796b0_30* field_30;
};
PKMN_OFFSET_ASSERT(Unk_17796b0, field_30, 0x30);

// 0x71017796b0
void Unk_17796b0_set(const Unk_17796b0* self) {
    self->field_30->field_9c = 0;
}

// 0x71017796c0
void Unk_17796c0_update(void* /*unused*/) {
}

struct Unk_17796d0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u64 field_50;
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u64 field_a0;
    u64 field_a8;
    u64 field_b0;
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_17796d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_17796d0, field_b8, 0xb8);

// 0x71017796d0
void Unk_17796d0_set(Unk_17796d0* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_b0 = 0;
    self->field_b8 = 0;
    self->field_a0 = 0;
    self->field_a8 = 0;
    self->field_90 = 0;
    self->field_98 = 0;
    self->field_80 = 0;
    self->field_88 = 0;
    self->field_70 = 0;
    self->field_78 = 0;
    self->field_60 = 0;
    self->field_68 = 0;
    self->field_50 = 0;
    self->field_58 = 0;
    self->field_40 = 0;
    self->field_48 = 0;
    self->field_30 = 0;
    self->field_38 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
}

// 0x7101779710
void Unk_1779710_update(u64 /*unused*/) {
}

struct Unk_1779890 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_1779890, field_b0, 0xb0);

// 0x7101779890
void Unk_1779890_set(Unk_1779890* self, u64 value) {
    self->field_b0 = value;
}

struct Unk_177a5b0 {
    u8 _0[0xbc];
    f32 field_bc;
};
PKMN_OFFSET_ASSERT(Unk_177a5b0, field_bc, 0xbc);

// 0x710177a5b0
void Unk_177a5b0_set(Unk_177a5b0* self, f32 fvalue) {
    self->field_bc = fvalue;
}

struct Unk_177c0b0 {
    u8 _0[0x10];
    u64 field_10;
    u8 _18[0x8];
    u64 field_20;
    u8 _28[0x38];
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_177c0b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_177c0b0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_177c0b0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_177c0b0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_177c0b0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_177c0b0, field_78, 0x78);

// 0x710177c0b0
void Unk_177c0b0_set(Unk_177c0b0* self, u64 value, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6) {
    self->field_10 = value;
    self->field_20 = arg2;
    self->field_60 = arg3;
    self->field_68 = arg4;
    self->field_70 = arg5;
    self->field_78 = arg6;
}

struct Unk_177c0d0 {
    u8 _0[0x10];
    u64 field_10;
    u8 _18[0x8];
    u64 field_20;
    u8 _28[0x38];
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_177c0d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_177c0d0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_177c0d0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_177c0d0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_177c0d0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_177c0d0, field_78, 0x78);

// 0x710177c0d0
u64 Unk_177c0d0_update(Unk_177c0d0* self) {
    u64 v0 = self->field_10;
    self->field_10 = 0;
    self->field_20 = 0;
    self->field_70 = 0;
    self->field_78 = 0;
    self->field_60 = 0;
    self->field_68 = 0;
    return v0;
}

struct Unk_177c9e0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_177c9e0, field_28, 0x28);

void Unk_177c9f0(void*, u64, void*);

// 0x710177c9e0
void Unk_177c9e0_call(Unk_177c9e0* self, u64 value) {
    Unk_177c9f0(self, value, &self->field_28);
}

struct Unk_177cd90 {
    u8 _0[0x8];
    u64 field_8;
    u16 field_10;
    u16 field_12;
    u16 field_14;
    u8 field_16;
    bool field_17;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_177cd90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_177cd90, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_177cd90, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_177cd90, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_177cd90, field_16, 0x16);
PKMN_OFFSET_ASSERT(Unk_177cd90, field_17, 0x17);
PKMN_OFFSET_ASSERT(Unk_177cd90, field_18, 0x18);

// 0x710177cd90
void Unk_177cd90_set(Unk_177cd90* self, u64 value, u16 arg2, u16 arg3, u16 arg4, u8 arg5, bool arg6) {
    self->field_17 = arg6;
    self->field_8 = value;
    self->field_14 = arg2;
    self->field_12 = arg3;
    self->field_10 = arg4;
    self->field_16 = arg5;
    self->field_18 = 1;
}

struct Unk_177cff0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_177cff0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_177cff0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_177cff0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_177cff0, field_18, 0x18);

// 0x710177cff0
void Unk_177cff0_set(Unk_177cff0* self) {
    self->field_0 = 0;
    self->field_8 = 0x28;
    self->field_10 = 0x3f;
    self->field_18 = 0;
}

struct Unk_1780850 {
    u8 _0[0x30];
    void* field_30;
};
PKMN_OFFSET_ASSERT(Unk_1780850, field_30, 0x30);

void Unk_17822e0(void*, u32);

// 0x7101780850
void Unk_1780850_call(const Unk_1780850* self, u32 value) {
    if (self->field_30 != nullptr) {
        Unk_17822e0(self->field_30, 1 << value);
    }
}

struct Unk_1781780 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1781780, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1781780, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1781780, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1781780, field_18, 0x18);

// 0x7101781780
void Unk_1781780_set(Unk_1781780* self) {
    self->field_18 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_0 = 0;
}
