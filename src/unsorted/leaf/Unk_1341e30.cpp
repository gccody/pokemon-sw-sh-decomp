// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1341e30_628 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1341e30_628, field_58, 0x58);

struct Unk_1341e30 {
    u8 _0[0x628];
    Unk_1341e30_628* field_628;
};
PKMN_OFFSET_ASSERT(Unk_1341e30, field_628, 0x628);

// 0x7101341e30
void Unk_1341e30_set(const Unk_1341e30* self) {
    self->field_628->field_58 = self->field_628->field_58 | 1;
}

struct Unk_1345c90 {
    u8 _0[0x221f0];
    u8 field_221f0;
};
PKMN_OFFSET_ASSERT(Unk_1345c90, field_221f0, 0x221f0);

// 0x7101345c90
const u8* Unk_1345c90_get(const Unk_1345c90* self) {
    return &self->field_221f0;
}

struct Unk_1345ca0 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1345ca0, field_60, 0x60);

// 0x7101345ca0
u8* Unk_1345ca0_getField60Ptr(Unk_1345ca0* self) {
    return &self->field_60;
}

struct Unk_1345d00 {
    u8 _0[0x228];
    u64 field_228;
};
PKMN_OFFSET_ASSERT(Unk_1345d00, field_228, 0x228);

// 0x7101345d00
void Unk_1345d00_setField228(Unk_1345d00* self, u64 value) {
    self->field_228 = value;
}

struct Unk_1345d10 {
    u8 _0[0x230];
    u8 field_230;
};
PKMN_OFFSET_ASSERT(Unk_1345d10, field_230, 0x230);

// 0x7101345d10
u8* Unk_1345d10_getField230Ptr(Unk_1345d10* self) {
    return &self->field_230;
}

struct Unk_1354890 {
    u8 _0[0x56e];
    u8 field_56e;
};
PKMN_OFFSET_ASSERT(Unk_1354890, field_56e, 0x56e);

// 0x7101354890
u8 Unk_1354890_getField56e(const Unk_1354890* self) {
    return self->field_56e;
}

struct Unk_13548a0 {
    u8 _0[0x590];
    u16 field_590;
};
PKMN_OFFSET_ASSERT(Unk_13548a0, field_590, 0x590);

// 0x71013548a0
void Unk_13548a0_setField590(Unk_13548a0* self, u16 value) {
    self->field_590 = value;
}

struct Unk_13548b0 {
    u8 _0[0x590];
    u16 field_590;
};
PKMN_OFFSET_ASSERT(Unk_13548b0, field_590, 0x590);

// 0x71013548b0
u16 Unk_13548b0_getField590(const Unk_13548b0* self) {
    return self->field_590;
}

struct Unk_13573c0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13573c0, field_60, 0x60);

// 0x71013573c0
u32 Unk_13573c0_get(const Unk_13573c0* self) {
    return (self->field_60 >> 9) & 0xf;
}

struct Unk_13573d0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13573d0, field_60, 0x60);

// 0x71013573d0
u32 Unk_13573d0_get(const Unk_13573d0* self) {
    return (self->field_60 >> 0xd) & 0xf;
}

struct Unk_13573e0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13573e0, field_60, 0x60);

// 0x71013573e0
u32 Unk_13573e0_get(const Unk_13573e0* self) {
    return (self->field_60 >> 0x11) & 0xf;
}

struct Unk_13573f0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13573f0, field_60, 0x60);

// 0x71013573f0
void Unk_13573f0_set(Unk_13573f0* self, u32 value) {
    self->field_60 = (self->field_60 & 0xfffffffc) | (value & 3);
}

struct Unk_1357400 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1357400, field_60, 0x60);

// 0x7101357400
u32 Unk_1357400_get(const Unk_1357400* self) {
    return self->field_60 & 3;
}

struct Unk_1357420 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1357420, field_60, 0x60);

// 0x7101357420
u32 Unk_1357420_get(const Unk_1357420* self) {
    return (self->field_60 >> 2) & 1;
}

struct Unk_1357440 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1357440, field_60, 0x60);

// 0x7101357440
u32 Unk_1357440_get(const Unk_1357440* self) {
    return (self->field_60 >> 3) & 1;
}

struct Unk_13574f0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13574f0, field_60, 0x60);

// 0x71013574f0
u32 Unk_13574f0_get(const Unk_13574f0* self) {
    return (self->field_60 >> 4) & 0xf;
}

struct Unk_13575b0 {
    u8 _0[0x62];
    u8 field_62;
};
PKMN_OFFSET_ASSERT(Unk_13575b0, field_62, 0x62);

// 0x71013575b0
bool Unk_13575b0_check(const Unk_13575b0* self) {
    return (self->field_62 & 0x40) == 0;
}

struct Unk_13575e0 {
    u8 _0[0x63];
    u8 field_63;
};
PKMN_OFFSET_ASSERT(Unk_13575e0, field_63, 0x63);

// 0x71013575e0
bool Unk_13575e0_check(const Unk_13575e0* self) {
    return (self->field_63 & 1) == 0;
}

struct Unk_1357610 {
    u8 _0[0x63];
    u8 field_63;
};
PKMN_OFFSET_ASSERT(Unk_1357610, field_63, 0x63);

// 0x7101357610
bool Unk_1357610_check(const Unk_1357610* self) {
    return (self->field_63 & 2) == 0;
}

struct Unk_1357640 {
    u8 _0[0x63];
    u8 field_63;
};
PKMN_OFFSET_ASSERT(Unk_1357640, field_63, 0x63);

// 0x7101357640
bool Unk_1357640_check(const Unk_1357640* self) {
    return (self->field_63 & 4) == 0;
}

struct Unk_1357670 {
    u8 _0[0x63];
    u8 field_63;
};
PKMN_OFFSET_ASSERT(Unk_1357670, field_63, 0x63);

// 0x7101357670
bool Unk_1357670_check(const Unk_1357670* self) {
    return (self->field_63 & 8) == 0;
}

struct Unk_13576a0 {
    u8 _0[0x63];
    u8 field_63;
};
PKMN_OFFSET_ASSERT(Unk_13576a0, field_63, 0x63);

// 0x71013576a0
bool Unk_13576a0_check(const Unk_13576a0* self) {
    return (self->field_63 & 0x10) == 0;
}

struct Unk_13576d0 {
    u8 _0[0x63];
    u8 field_63;
};
PKMN_OFFSET_ASSERT(Unk_13576d0, field_63, 0x63);

// 0x71013576d0
bool Unk_13576d0_check(const Unk_13576d0* self) {
    return (self->field_63 & 0x20) == 0;
}

struct Unk_13576f0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13576f0, field_60, 0x60);

// 0x71013576f0
u32 Unk_13576f0_get(const Unk_13576f0* self) {
    return (self->field_60 >> 0x15) & 1;
}

struct Unk_1357f20 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_1357f20, field_150, 0x150);

// 0x7101357f20
u32 Unk_1357f20_getField150(const Unk_1357f20* self) {
    return self->field_150;
}
