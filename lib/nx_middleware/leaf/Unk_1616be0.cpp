// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101616be0
u32 Unk_1616be0_get() {
    return 0;
}

// 0x71016180c0
u32 Unk_16180c0_get() {
    return 1;
}

// 0x71016180d0
u32 Unk_16180d0_get() {
    return 1;
}

struct Unk_1618570 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1618570, field_c, 0xc);

// 0x7101618570
void Unk_1618570_set(Unk_1618570* self, u32 value) {
    self->field_c = value;
}

struct Unk_1618830 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1618830, field_0, 0x0);

// 0x7101618830
u32 Unk_1618830_get(const Unk_1618830* self) {
    return self->field_0;
}

struct Unk_1618840 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_1618840, field_4, 0x4);

// 0x7101618840
u32 Unk_1618840_get(const Unk_1618840* self) {
    return self->field_4;
}

struct Unk_1618850 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1618850, field_c, 0xc);

// 0x7101618850
u32 Unk_1618850_get(const Unk_1618850* self) {
    return self->field_c;
}

struct Unk_1618860 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1618860, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1618860, field_8, 0x8);

// 0x7101618860
void Unk_1618860_set(Unk_1618860* self) {
    self->field_0 = 0;
    self->field_8 = 0;
}

struct Unk_1618a20 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1618a20, field_0, 0x0);

// 0x7101618a20
u32 Unk_1618a20_get(const Unk_1618a20* self) {
    return self->field_0;
}

struct Unk_16199e0_b0_10 {
    virtual void vf0(u32);
};

struct Unk_16199e0_b0 {
    u8 _0[0x10];
    Unk_16199e0_b0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_16199e0_b0, field_10, 0x10);

struct Unk_16199e0 {
    u8 _0[0x9c];
    u32 field_9c;
    u8 _a0[0x10];
    Unk_16199e0_b0* field_b0;
    u8 _b8[0x8];
    u32 field_c0;
    u16 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_16199e0, field_9c, 0x9c);
PKMN_OFFSET_ASSERT(Unk_16199e0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_16199e0, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_16199e0, field_c4, 0xc4);

// 0x71016199e0
void Unk_16199e0_call(Unk_16199e0* self) {
    self->field_c4 = 0;
    self->field_c0 = 0;
    self->field_b0->field_10->vf0(self->field_9c);
}

struct Unk_161cea0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_161cea0, field_8, 0x8);

// 0x710161cea0
const u8* Unk_161cea0_get(const Unk_161cea0* self) {
    return &self->field_8;
}

struct Unk_161db80_b0_10 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct Unk_161db80_b0 {
    u8 _0[0x10];
    Unk_161db80_b0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_161db80_b0, field_10, 0x10);

struct Unk_161db80 {
    u8 _0[0xb0];
    Unk_161db80_b0* field_b0;
};
PKMN_OFFSET_ASSERT(Unk_161db80, field_b0, 0xb0);

// 0x710161db80
void Unk_161db80_call(const Unk_161db80* self) {
    self->field_b0->field_10->vf6();
}

// 0x71016224f0
void Unk_16224f0_update() {
}

// 0x71016234f0
void Unk_16234f0_update() {
}
