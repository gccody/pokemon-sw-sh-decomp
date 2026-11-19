// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_76d280_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_76d280 {
    u64 field_0;
    Unk_76d280_8* field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_76d280, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_76d280, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_76d280, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_76d280, field_18, 0x18);

// 0x710076d280
void Unk_76d280_call(Unk_76d280* self) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    if (v0 != 0) {
        self->field_8->vf3(v0, self->field_10, self->field_18);
    }
}

struct Unk_76d640 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_76d640, field_8, 0x8);

// 0x710076d640
u32 Unk_76d640_getField8(const Unk_76d640* self) {
    return self->field_8;
}

struct Unk_76d650 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_76d650, field_c, 0xc);

// 0x710076d650
u16 Unk_76d650_getFieldc(const Unk_76d650* self) {
    return self->field_c;
}

struct Unk_76d6f0_arg1 {
    u8 _0[0x8];
    u32 field_8;
    u16 field_c;
    u8 field_e;
    u8 _f[0x103];
    u8 field_112;
};
PKMN_OFFSET_ASSERT(Unk_76d6f0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_76d6f0_arg1, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_76d6f0_arg1, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_76d6f0_arg1, field_112, 0x112);

struct Unk_76d6f0 {
    u8 _0[0x8];
    u32 field_8;
    u16 field_c;
    u8 field_e;
    u8 _f[0x103];
    u8 field_112;
};
PKMN_OFFSET_ASSERT(Unk_76d6f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_76d6f0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_76d6f0, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_76d6f0, field_112, 0x112);

extern "C" void* memcpy(void*, const void*, unsigned long);

// 0x710076d6f0
void Unk_76d6f0_call(const Unk_76d6f0* self, Unk_76d6f0_arg1* value) {
    memcpy(&value->field_e, &self->field_e, 0x104);
    value->field_8 = self->field_8;
    value->field_c = self->field_c;
    value->field_112 = self->field_112;
}

struct Unk_76d740 {
    u8 _0[0x112];
    u8 field_112;
};
PKMN_OFFSET_ASSERT(Unk_76d740, field_112, 0x112);

// 0x710076d740
u8 Unk_76d740_getField112(const Unk_76d740* self) {
    return self->field_112;
}
