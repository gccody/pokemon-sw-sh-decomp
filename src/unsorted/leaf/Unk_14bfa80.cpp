// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14bfa80_58 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_14bfa80_58, field_150, 0x150);

struct Unk_14bfa80 {
    u8 _0[0x58];
    Unk_14bfa80_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfa80, field_58, 0x58);

// 0x71014bfa80
void Unk_14bfa80_set(const Unk_14bfa80* self, u32 value) {
    self->field_58->field_150 = value;
}

struct Unk_14bfb70_58 {
    u8 _0[0x670];
    u8 field_670;
};
PKMN_OFFSET_ASSERT(Unk_14bfb70_58, field_670, 0x670);

struct Unk_14bfb70 {
    u8 _0[0x58];
    Unk_14bfb70_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfb70, field_58, 0x58);

// 0x71014bfb70
u8 Unk_14bfb70_get(const Unk_14bfb70* self) {
    return self->field_58->field_670;
}

struct Unk_14bfb80_58 {
    u8 _0[0x66c];
    u32 field_66c;
};
PKMN_OFFSET_ASSERT(Unk_14bfb80_58, field_66c, 0x66c);

struct Unk_14bfb80 {
    u8 _0[0x58];
    Unk_14bfb80_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfb80, field_58, 0x58);

// 0x71014bfb80
bool Unk_14bfb80_check(const Unk_14bfb80* self) {
    return (self->field_58->field_66c | 2) == 2;
}

struct Unk_14bfba0_58 {
    u8 _0[0x671];
    u8 field_671;
};
PKMN_OFFSET_ASSERT(Unk_14bfba0_58, field_671, 0x671);

struct Unk_14bfba0 {
    u8 _0[0x58];
    Unk_14bfba0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfba0, field_58, 0x58);

// 0x71014bfba0
u8 Unk_14bfba0_get(const Unk_14bfba0* self) {
    return self->field_58->field_671;
}

struct Unk_14c5510_58 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14c5510_58, field_68, 0x68);

struct Unk_14c5510 {
    u8 _0[0x58];
    Unk_14c5510_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c5510, field_58, 0x58);

// 0x71014c5510
void Unk_14c5510_set(const Unk_14c5510* self) {
    self->field_58->field_68 = 2;
}

struct Unk_14c5e60_58 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_14c5e60_58, field_88, 0x88);

struct Unk_14c5e60 {
    u8 _0[0x58];
    Unk_14c5e60_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c5e60, field_58, 0x58);

// 0x71014c5e60
u8 Unk_14c5e60_get(const Unk_14c5e60* self) {
    return self->field_58->field_88;
}

struct Unk_14c5e70_58 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_14c5e70_58, field_88, 0x88);

struct Unk_14c5e70 {
    u8 _0[0x58];
    Unk_14c5e70_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c5e70, field_58, 0x58);

// 0x71014c5e70
bool Unk_14c5e70_check(const Unk_14c5e70* self) {
    return self->field_58->field_88 == 0;
}

struct Unk_14d44d0_600 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_14d44d0_600, field_58, 0x58);

struct Unk_14d44d0 {
    u8 _0[0x600];
    Unk_14d44d0_600* field_600;
};
PKMN_OFFSET_ASSERT(Unk_14d44d0, field_600, 0x600);

// 0x71014d44d0
void Unk_14d44d0_set(const Unk_14d44d0* self, bool value) {
    self->field_600->field_58 = (self->field_600->field_58 & 0xfffffffe) | (value);
}

struct Unk_14d5a80 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14d5a80, field_68, 0x68);

// 0x71014d5a80
bool Unk_14d5a80_check(const Unk_14d5a80* self) {
    return self->field_68 == 0;
}

struct Unk_14d6890 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14d6890, field_68, 0x68);

// 0x71014d6890
bool Unk_14d6890_check(const Unk_14d6890* self) {
    return self->field_68 == 0;
}

struct Unk_14d9c20 {
    u8 _0[0x16c];
    u32 field_16c;
    u32 field_170;
    u32 field_174;
    u32 field_178;
    u8 _17c[0x1c];
    u8 field_198;
};
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_16c, 0x16c);
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_170, 0x170);
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_174, 0x174);
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_178, 0x178);
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_198, 0x198);

// 0x71014d9c20
void Unk_14d9c20_set(Unk_14d9c20* self, u32 value, u32 arg2, u32 arg3, u32 arg4) {
    self->field_174 = value;
    self->field_16c = arg2;
    self->field_170 = arg3;
    self->field_178 = arg4;
    self->field_198 = 1;
}

struct Unk_14dbb00 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14dbb00, field_68, 0x68);

// 0x71014dbb00
bool Unk_14dbb00_check(const Unk_14dbb00* self) {
    return self->field_68 == 0;
}
