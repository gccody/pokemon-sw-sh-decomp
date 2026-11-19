// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8c1d30 {
    u8 _0[0xac];
    u8 field_ac;
};
PKMN_OFFSET_ASSERT(Unk_8c1d30, field_ac, 0xac);

// 0x71008c1d30
u8* Unk_8c1d30_getFieldacPtr(Unk_8c1d30* self) {
    return &self->field_ac;
}

struct Unk_8c1ee0 {
    u8 _0[0x70];
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_8c1ee0, field_70, 0x70);

// 0x71008c1ee0
u8* Unk_8c1ee0_getField70Ptr(Unk_8c1ee0* self) {
    return &self->field_70;
}

struct Unk_8c1ef0 {
    u8 _0[0x290];
    u8 field_290;
};
PKMN_OFFSET_ASSERT(Unk_8c1ef0, field_290, 0x290);

// 0x71008c1ef0
u8* Unk_8c1ef0_getField290Ptr(Unk_8c1ef0* self) {
    return &self->field_290;
}

struct Unk_8c1f00 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_8c1f00, field_58, 0x58);

// 0x71008c1f00
u64 Unk_8c1f00_getField58(const Unk_8c1f00* self) {
    return self->field_58;
}

struct Unk_8c1f10 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_8c1f10, field_68, 0x68);

// 0x71008c1f10
u64 Unk_8c1f10_getField68(const Unk_8c1f10* self) {
    return self->field_68;
}

struct Unk_7fe1d0;
struct Unk_8c1f20 {
    u8 _0[0x60];
    Unk_7fe1d0* field_60;
};
PKMN_OFFSET_ASSERT(Unk_8c1f20, field_60, 0x60);

u64 Unk_7fe1d0_getField8(const Unk_7fe1d0*);

// 0x71008c1f20
void Unk_8c1f20_call(const Unk_8c1f20* self) {
    Unk_7fe1d0_getField8(self->field_60);
}

struct Unk_8c1f30 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8c1f30, field_60, 0x60);

// 0x71008c1f30
u64 Unk_8c1f30_getField60(const Unk_8c1f30* self) {
    return self->field_60;
}

struct Unk_8c1f40 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_8c1f40, field_78, 0x78);

// 0x71008c1f40
u64 Unk_8c1f40_getField78(const Unk_8c1f40* self) {
    return self->field_78;
}

struct Unk_8c1f50 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_8c1f50, field_80, 0x80);

// 0x71008c1f50
u64 Unk_8c1f50_getField80(const Unk_8c1f50* self) {
    return self->field_80;
}

struct Unk_8c2040 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_8c2040, field_88, 0x88);

// 0x71008c2040
u8 Unk_8c2040_getField88(const Unk_8c2040* self) {
    return self->field_88;
}

struct Unk_8c2050 {
    u8 _0[0x8c];
    u32 field_8c;
};
PKMN_OFFSET_ASSERT(Unk_8c2050, field_8c, 0x8c);

// 0x71008c2050
u32 Unk_8c2050_getField8c(const Unk_8c2050* self) {
    return self->field_8c;
}

struct Unk_8c2060 {
    u8 _0[0x90];
    u16 field_90;
};
PKMN_OFFSET_ASSERT(Unk_8c2060, field_90, 0x90);

// 0x71008c2060
u16 Unk_8c2060_getField90(const Unk_8c2060* self) {
    return self->field_90;
}

struct Unk_8c2610 {
    u8 _0[0x288];
    u8 field_288;
};
PKMN_OFFSET_ASSERT(Unk_8c2610, field_288, 0x288);

// 0x71008c2610
void Unk_8c2610_clearField288(Unk_8c2610* self) {
    self->field_288 = 0;
}

struct Unk_8c2620 {
    u8 _0[0x288];
    u8 field_288;
};
PKMN_OFFSET_ASSERT(Unk_8c2620, field_288, 0x288);

// 0x71008c2620
void Unk_8c2620_set(Unk_8c2620* self) {
    self->field_288 = 1;
}

struct Unk_8c2630 {
    u8 _0[0x288];
    u8 field_288;
};
PKMN_OFFSET_ASSERT(Unk_8c2630, field_288, 0x288);

// 0x71008c2630
u8 Unk_8c2630_getField288(const Unk_8c2630* self) {
    return self->field_288;
}
