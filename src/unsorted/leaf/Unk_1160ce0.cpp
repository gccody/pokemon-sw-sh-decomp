// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1160ce0 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_1160ce0, field_80, 0x80);

// 0x7101160ce0
u8* Unk_1160ce0_getField80Ptr(Unk_1160ce0* self) {
    return &self->field_80;
}

// 0x7101161e90
void Unk_1161e90_update() {}

struct Unk_1161ea0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1161ea0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1161ea0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1161ea0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1161ea0, field_18, 0x18);

// 0x7101161ea0
void Unk_1161ea0_set(const Unk_1161ea0* self, Unk_1161ea0* value) {
    *value = *self;
}

struct Unk_1161ec0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1161ec0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1161ec0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1161ec0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1161ec0, field_18, 0x18);

// 0x7101161ec0
void Unk_1161ec0_set(const Unk_1161ec0* self, Unk_1161ec0* value) {
    *value = *self;
}

// 0x7101161ef0
void Unk_1161ef0_update() {}

struct Unk_1161f00 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1161f00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1161f00, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1161f00, field_10, 0x10);

// 0x7101161f00
void Unk_1161f00_set(const Unk_1161f00* self, Unk_1161f00* value) {
    *value = *self;
}

struct Unk_1161f20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1161f20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1161f20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1161f20, field_10, 0x10);

// 0x7101161f20
void Unk_1161f20_set(const Unk_1161f20* self, Unk_1161f20* value) {
    *value = *self;
}

// 0x7101162be0
void Unk_1162be0_update() {}

struct Unk_1162bf0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1162bf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1162bf0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1162bf0, field_10, 0x10);

// 0x7101162bf0
void Unk_1162bf0_set(const Unk_1162bf0* self, Unk_1162bf0* value) {
    *value = *self;
}

struct Unk_1162c10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1162c10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1162c10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1162c10, field_10, 0x10);

// 0x7101162c10
void Unk_1162c10_set(const Unk_1162c10* self, Unk_1162c10* value) {
    *value = *self;
}

struct Unk_1162c90 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_1162c90, field_90, 0x90);

// 0x7101162c90
u8 Unk_1162c90_getField90(const Unk_1162c90* self) {
    return self->field_90;
}

struct Unk_1163130 {
    u8 _0[0xa0];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1163130, field_a0, 0xa0);

// 0x7101163130
u8 Unk_1163130_getFielda0(const Unk_1163130* self) {
    return self->field_a0;
}

struct Unk_1163140 {
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
    u8 _8[0x98];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1163140, field_a0, 0xa0);

// 0x7101163140
void Unk_1163140_set(Unk_1163140* self) {
    if (self->field_a0 == 0) {
        self->vf9();
    }
    self->field_a0 = 1;
}

struct Unk_1163180 {
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
    u8 _8[0x98];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1163180, field_a0, 0xa0);

// 0x7101163180
void Unk_1163180_set(Unk_1163180* self) {
    if (self->field_a0 != 0) {
        self->vf10();
    }
    self->field_a0 = 0;
}

struct Unk_1164120 {
    u8 _0[0xb8];
    f32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_1164120, field_b8, 0xb8);

// 0x7101164120
void Unk_1164120_setFieldb8(Unk_1164120* self, f32 value) {
    self->field_b8 = value;
}

struct Unk_1164130 {
    u8 _0[0x140];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_1164130, field_140, 0x140);

// 0x7101164130
u64 Unk_1164130_getField140(const Unk_1164130* self) {
    return self->field_140;
}

struct Unk_1164140_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1164140_arg1, field_0, 0x0);

struct Unk_1164140 {
    u8 _0[0x140];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_1164140, field_140, 0x140);

// 0x7101164140
void Unk_1164140_set(Unk_1164140* self, const Unk_1164140_arg1* value) {
    self->field_140 = value->field_0;
}

struct Unk_1164150 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_1164150, field_b0, 0xb0);

// 0x7101164150
u64 Unk_1164150_getFieldb0(const Unk_1164150* self) {
    return self->field_b0;
}

struct Unk_1165010 {
    u8 _0[0x68];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1165010, field_68, 0x68);

// 0x7101165010
u8 Unk_1165010_getField68(const Unk_1165010* self) {
    return self->field_68;
}

struct Unk_1165020 {
    u8 _0[0x68];
    bool field_68;
};
PKMN_OFFSET_ASSERT(Unk_1165020, field_68, 0x68);

// 0x7101165020
void Unk_1165020_set(Unk_1165020* self, bool value) {
    self->field_68 = value;
}

struct Unk_1165170 {
    u8 _0[0x68];
    u8 field_68;
    u8 _69[0x377];
    u8 field_3e0;
};
PKMN_OFFSET_ASSERT(Unk_1165170, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_1165170, field_3e0, 0x3e0);
void Unk_1165190();

// 0x7101165170
void Unk_1165170_call(const Unk_1165170* self) {
    if (self->field_3e0 != 0) {
        if (self->field_68 != 0) {
            Unk_1165190();
            return;
        }
        return;
    }
}

struct Unk_1165dc0_58 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1165dc0_58, field_68, 0x68);

struct Unk_1165dc0 {
    u8 _0[0x58];
    Unk_1165dc0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1165dc0, field_58, 0x58);

// 0x7101165dc0
u64 Unk_1165dc0_get(const Unk_1165dc0* self) {
    if (self->field_58 == nullptr) {
        return 0;
    }
    return self->field_58->field_68;
}

struct Unk_1167c30_58 {
    u8 _0[0x4f0];
    u8 field_4f0;
};
PKMN_OFFSET_ASSERT(Unk_1167c30_58, field_4f0, 0x4f0);

struct Unk_1167c30 {
    u8 _0[0x58];
    Unk_1167c30_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1167c30, field_58, 0x58);

// 0x7101167c30
u8* Unk_1167c30_get(const Unk_1167c30* self) {
    return &self->field_58->field_4f0;
}

struct Unk_1167c40 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1167c40, field_60, 0x60);

// 0x7101167c40
u64 Unk_1167c40_getField60(const Unk_1167c40* self) {
    return self->field_60;
}

// 0x7101168bd0
void Unk_1168bd0_update() {}

// 0x7101168d60
void Unk_1168d60_update() {}

// 0x7101168db0
void Unk_1168db0_update() {}

struct Unk_1168dc0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1168dc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1168dc0, field_8, 0x8);

// 0x7101168dc0
void Unk_1168dc0_set(const Unk_1168dc0* self, Unk_1168dc0* value) {
    *value = *self;
}

struct Unk_1168dd0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1168dd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1168dd0, field_8, 0x8);

// 0x7101168dd0
void Unk_1168dd0_set(const Unk_1168dd0* self, Unk_1168dd0* value) {
    *value = *self;
}

struct Unk_1168de0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1168de0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1168de0, field_8, 0x8);

// 0x7101168de0
void Unk_1168de0_set(const Unk_1168de0* self, Unk_1168de0* value) {
    *value = *self;
}

struct Unk_1168df0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1168df0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1168df0, field_8, 0x8);

// 0x7101168df0
void Unk_1168df0_set(const Unk_1168df0* self, Unk_1168df0* value) {
    *value = *self;
}

struct Unk_1168e00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1168e00_arg1, field_0, 0x0);

struct Unk_1168e00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1168e00, field_0, 0x0);

// 0x7101168e00
void Unk_1168e00_set(const Unk_1168e00* self, Unk_1168e00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1168e10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1168e10_arg1, field_0, 0x0);

struct Unk_1168e10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1168e10, field_0, 0x0);

// 0x7101168e10
void Unk_1168e10_set(const Unk_1168e10* self, Unk_1168e10_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101168e30
void Unk_1168e30_update() {}

struct Unk_1168e40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1168e40_arg1, field_0, 0x0);

struct Unk_1168e40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1168e40, field_0, 0x0);

// 0x7101168e40
void Unk_1168e40_set(const Unk_1168e40* self, Unk_1168e40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1168e50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1168e50_arg1, field_0, 0x0);

struct Unk_1168e50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1168e50, field_0, 0x0);

// 0x7101168e50
void Unk_1168e50_set(const Unk_1168e50* self, Unk_1168e50_arg1* value) {
    value->field_0 = self->field_0;
}
