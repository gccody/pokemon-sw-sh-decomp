// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_16c48c0 {
    u8 _0[0x10];
    u32 field_10;
    u8 _14[0x624];
    u32 field_638;
};
PKMN_OFFSET_ASSERT(Unk_16c48c0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_16c48c0, field_638, 0x638);

// 0x71016c48c0
void Unk_16c48c0_set(Unk_16c48c0* self, u32 value) {
    self->field_10 = value;
    self->field_638 = self->field_638 | 1;
}

struct Unk_16c48e0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_16c48e0, field_10, 0x10);

// 0x71016c48e0
u32 Unk_16c48e0_get(const Unk_16c48e0* self) {
    return self->field_10;
}

struct Unk_16c48f0 {
    u8 _0[0x638];
    u32 field_638;
};
PKMN_OFFSET_ASSERT(Unk_16c48f0, field_638, 0x638);

// 0x71016c48f0
u32 Unk_16c48f0_get(const Unk_16c48f0* self) {
    return self->field_638 & 1;
}

struct Unk_16c4930 {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_16c4930, field_14, 0x14);

// 0x71016c4930
u32 Unk_16c4930_get(const Unk_16c4930* self) {
    return self->field_14;
}

struct Unk_16c4940 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16c4940, field_18, 0x18);

// 0x71016c4940
u8 Unk_16c4940_get(const Unk_16c4940* self) {
    return self->field_18;
}

struct Unk_16c4950 {
    u8 _0[0x638];
    u8 field_638;
};
PKMN_OFFSET_ASSERT(Unk_16c4950, field_638, 0x638);

// 0x71016c4950
u32 Unk_16c4950_get(const Unk_16c4950* self) {
    return (self->field_638 >> 1) & 1;
}

struct Unk_16c4cb0 {
    u8 _0[0x2a0];
    u8 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_16c4cb0, field_2a0, 0x2a0);

// 0x71016c4cb0
const u8* Unk_16c4cb0_get(const Unk_16c4cb0* self) {
    return &self->field_2a0;
}

struct Unk_16c4cc0 {
    u8 _0[0x639];
    u8 field_639;
};
PKMN_OFFSET_ASSERT(Unk_16c4cc0, field_639, 0x639);

// 0x71016c4cc0
u32 Unk_16c4cc0_get(const Unk_16c4cc0* self) {
    return (self->field_639 >> 2) & 1;
}

struct Unk_16c4dc0 {
    u8 _0[0x598];
    u8 field_598;
};
PKMN_OFFSET_ASSERT(Unk_16c4dc0, field_598, 0x598);

// 0x71016c4dc0
const u8* Unk_16c4dc0_get(const Unk_16c4dc0* self) {
    return &self->field_598;
}

struct Unk_16c4dd0 {
    u8 _0[0x63a];
    u8 field_63a;
};
PKMN_OFFSET_ASSERT(Unk_16c4dd0, field_63a, 0x63a);

// 0x71016c4dd0
u32 Unk_16c4dd0_get(const Unk_16c4dd0* self) {
    return (self->field_63a >> 6) & 1;
}

struct Unk_16c4de0 {
    u8 _0[0x238];
    bool field_238;
    u8 _239[0x3ff];
    u32 field_638;
};
PKMN_OFFSET_ASSERT(Unk_16c4de0, field_238, 0x238);
PKMN_OFFSET_ASSERT(Unk_16c4de0, field_638, 0x638);

// 0x71016c4de0
void Unk_16c4de0_set(Unk_16c4de0* self, bool value) {
    self->field_238 = value;
    self->field_638 = self->field_638 | 0x200;
}

struct Unk_16c4e00 {
    u8 _0[0x238];
    u8 field_238;
};
PKMN_OFFSET_ASSERT(Unk_16c4e00, field_238, 0x238);

// 0x71016c4e00
u8 Unk_16c4e00_get(const Unk_16c4e00* self) {
    return self->field_238;
}

struct Unk_16c4e10 {
    u8 _0[0x639];
    u8 field_639;
};
PKMN_OFFSET_ASSERT(Unk_16c4e10, field_639, 0x639);

// 0x71016c4e10
u32 Unk_16c4e10_get(const Unk_16c4e10* self) {
    return (self->field_639 >> 1) & 1;
}

struct Unk_16c4e20 {
    u8 _0[0x239];
    u8 field_239;
};
PKMN_OFFSET_ASSERT(Unk_16c4e20, field_239, 0x239);

// 0x71016c4e20
u8 Unk_16c4e20_get(const Unk_16c4e20* self) {
    return self->field_239;
}

struct Unk_16c4e30 {
    u8 _0[0x639];
    u8 field_639;
};
PKMN_OFFSET_ASSERT(Unk_16c4e30, field_639, 0x639);

// 0x71016c4e30
u32 Unk_16c4e30_get(const Unk_16c4e30* self) {
    return (self->field_639 >> 4) & 1;
}

struct Unk_16c4e40 {
    u8 _0[0x23c];
    u32 field_23c;
};
PKMN_OFFSET_ASSERT(Unk_16c4e40, field_23c, 0x23c);

// 0x71016c4e40
u32 Unk_16c4e40_get(const Unk_16c4e40* self) {
    return self->field_23c;
}

struct Unk_16c4e50 {
    u8 _0[0x639];
    u8 field_639;
};
PKMN_OFFSET_ASSERT(Unk_16c4e50, field_639, 0x639);

// 0x71016c4e50
u32 Unk_16c4e50_get(const Unk_16c4e50* self) {
    return self->field_639 >> 7;
}

struct Unk_16c4e60 {
    u8 _0[0x240];
    u32 field_240;
};
PKMN_OFFSET_ASSERT(Unk_16c4e60, field_240, 0x240);

// 0x71016c4e60
u32 Unk_16c4e60_get(const Unk_16c4e60* self) {
    return self->field_240;
}

struct Unk_16c4e70 {
    u8 _0[0x63a];
    u8 field_63a;
};
PKMN_OFFSET_ASSERT(Unk_16c4e70, field_63a, 0x63a);

// 0x71016c4e70
u32 Unk_16c4e70_get(const Unk_16c4e70* self) {
    return (self->field_63a >> 1) & 1;
}

struct Unk_16c4e80 {
    u8 _0[0x244];
    u32 field_244;
};
PKMN_OFFSET_ASSERT(Unk_16c4e80, field_244, 0x244);

// 0x71016c4e80
u32 Unk_16c4e80_get(const Unk_16c4e80* self) {
    return self->field_244;
}

struct Unk_16c4e90 {
    u8 _0[0x63a];
    u8 field_63a;
};
PKMN_OFFSET_ASSERT(Unk_16c4e90, field_63a, 0x63a);

// 0x71016c4e90
u32 Unk_16c4e90_get(const Unk_16c4e90* self) {
    return self->field_63a & 1;
}

struct Unk_16c4ea0 {
    u8 _0[0x248];
    u8 field_248;
};
PKMN_OFFSET_ASSERT(Unk_16c4ea0, field_248, 0x248);

// 0x71016c4ea0
u8 Unk_16c4ea0_get(const Unk_16c4ea0* self) {
    return self->field_248;
}

struct Unk_16c4eb0 {
    u8 _0[0x63a];
    u8 field_63a;
};
PKMN_OFFSET_ASSERT(Unk_16c4eb0, field_63a, 0x63a);

// 0x71016c4eb0
u32 Unk_16c4eb0_get(const Unk_16c4eb0* self) {
    return (self->field_63a >> 3) & 1;
}

struct Unk_16c4ec0 {
    u8 _0[0x250];
    u8 field_250;
};
PKMN_OFFSET_ASSERT(Unk_16c4ec0, field_250, 0x250);

// 0x71016c4ec0
const u8* Unk_16c4ec0_get(const Unk_16c4ec0* self) {
    return &self->field_250;
}

struct Unk_16c4ed0 {
    u8 _0[0x63a];
    u8 field_63a;
};
PKMN_OFFSET_ASSERT(Unk_16c4ed0, field_63a, 0x63a);

// 0x71016c4ed0
u32 Unk_16c4ed0_get(const Unk_16c4ed0* self) {
    return (self->field_63a >> 2) & 1;
}

struct Unk_16c4ee0 {
    u8 _0[0x278];
    u8 field_278;
};
PKMN_OFFSET_ASSERT(Unk_16c4ee0, field_278, 0x278);

// 0x71016c4ee0
const u8* Unk_16c4ee0_get(const Unk_16c4ee0* self) {
    return &self->field_278;
}

struct Unk_16c4ef0 {
    u8 _0[0x63a];
    u8 field_63a;
};
PKMN_OFFSET_ASSERT(Unk_16c4ef0, field_63a, 0x63a);

// 0x71016c4ef0
u32 Unk_16c4ef0_get(const Unk_16c4ef0* self) {
    return (self->field_63a >> 4) & 1;
}

struct Unk_16c5140 {
    u8 _0[0x298];
    u16 field_298;
};
PKMN_OFFSET_ASSERT(Unk_16c5140, field_298, 0x298);

// 0x71016c5140
u16 Unk_16c5140_get(const Unk_16c5140* self) {
    return self->field_298;
}

struct Unk_16c5150 {
    u8 _0[0x29c];
    u32 field_29c;
};
PKMN_OFFSET_ASSERT(Unk_16c5150, field_29c, 0x29c);

// 0x71016c5150
u32 Unk_16c5150_get(const Unk_16c5150* self) {
    return self->field_29c;
}

struct Unk_16c5160 {
    u8 _0[0x63a];
    u8 field_63a;
};
PKMN_OFFSET_ASSERT(Unk_16c5160, field_63a, 0x63a);

// 0x71016c5160
u32 Unk_16c5160_get(const Unk_16c5160* self) {
    return (self->field_63a >> 5) & 1;
}

struct Unk_16c5170 {
    u8 _0[0x340];
    u32 field_340;
};
PKMN_OFFSET_ASSERT(Unk_16c5170, field_340, 0x340);

// 0x71016c5170
u32 Unk_16c5170_get(const Unk_16c5170* self) {
    return self->field_340;
}

struct Unk_16c5180 {
    u8 _0[0x639];
    u8 field_639;
};
PKMN_OFFSET_ASSERT(Unk_16c5180, field_639, 0x639);

// 0x71016c5180
u32 Unk_16c5180_get(const Unk_16c5180* self) {
    return (self->field_639 >> 3) & 1;
}

struct Unk_16c6860_50 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Unk_16c6860 {
    u8 _0[0x50];
    Unk_16c6860_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_16c6860, field_50, 0x50);

// 0x71016c6860
void Unk_16c6860_call(const Unk_16c6860* self) {
    if (self->field_50 != nullptr) {
        self->field_50->vf3();
    }
}

struct Unk_16c6880 {
    u8 _0[0xb2];
    u8 field_b2;
};
PKMN_OFFSET_ASSERT(Unk_16c6880, field_b2, 0xb2);

// 0x71016c6880
u8 Unk_16c6880_get(const Unk_16c6880* self) {
    return self->field_b2;
}

extern u64 Unk_27fb310;
void Unk_16c6d90(u64);

// 0x71016c6d80
void Unk_16c6d80_call() {
    Unk_16c6d90(Unk_27fb310);
}

extern u64 Unk_27fb310;
void Unk_16c6f40(u64);

// 0x71016c6f30
void Unk_16c6f30_call() {
    Unk_16c6f40(Unk_27fb310);
}

// 0x71016c7e60
void Unk_16c7e60_update() {
}

struct Unk_16c7e70 {
    u8 _0[0x58];
    u32 field_58;
};
PKMN_OFFSET_ASSERT(Unk_16c7e70, field_58, 0x58);

// 0x71016c7e70
void Unk_16c7e70_set(Unk_16c7e70* self, u32 value) {
    self->field_58 = value;
}

void Unk_15a1030();

// 0x71016c8010
void Unk_16c8010_call() {
    Unk_15a1030();
}

struct Unk_16c8380 {
    u8 _0[0x188];
    bool field_188;
};
PKMN_OFFSET_ASSERT(Unk_16c8380, field_188, 0x188);

// 0x71016c8380
void Unk_16c8380_set(Unk_16c8380* self, bool value) {
    self->field_188 = value;
}

struct Unk_16c8410 {
    u8 _0[0x18c];
    u32 field_18c;
};
PKMN_OFFSET_ASSERT(Unk_16c8410, field_18c, 0x18c);

// 0x71016c8410
void Unk_16c8410_set(Unk_16c8410* self, u32 value) {
    self->field_18c = value;
}

struct Unk_16c84d0 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_16c84d0, field_90, 0x90);

void Unk_16ca5d0(u64);

// 0x71016c84d0
void Unk_16c84d0_call(const Unk_16c84d0* self) {
    if (self->field_90 != 0) {
        Unk_16ca5d0(self->field_90);
    }
}

struct Unk_16c84e0 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_16c84e0, field_90, 0x90);

void Unk_16ca610(u64);

// 0x71016c84e0
void Unk_16c84e0_call(const Unk_16c84e0* self) {
    if (self->field_90 != 0) {
        Unk_16ca610(self->field_90);
    }
}

struct Unk_16c8c70 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_16c8c70, field_90, 0x90);

void Unk_16ca310(u64);

// 0x71016c8c70
void Unk_16c8c70_call(const Unk_16c8c70* self) {
    if (self->field_90 != 0) {
        Unk_16ca310(self->field_90);
    }
}

struct Unk_16c8d00 {
    u8 _0[0x228];
    u64 field_228;
};
PKMN_OFFSET_ASSERT(Unk_16c8d00, field_228, 0x228);

// 0x71016c8d00
void Unk_16c8d00_set(Unk_16c8d00* self, u64 value) {
    self->field_228 = value;
}

struct Unk_16c8d10 {
    u8 _0[0x228];
    u64 field_228;
};
PKMN_OFFSET_ASSERT(Unk_16c8d10, field_228, 0x228);

// 0x71016c8d10
void Unk_16c8d10_set(Unk_16c8d10* self) {
    self->field_228 = 0;
}
