// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e7c1c0 {
    u8 _0[0x540];
    u32 field_540;
};
PKMN_OFFSET_ASSERT(Unk_e7c1c0, field_540, 0x540);

// 0x7100e7c1c0
bool Unk_e7c1c0_check(const Unk_e7c1c0* self) {
    return self->field_540 == 0;
}

struct Unk_e7c1d0 {
    u8 _0[0x540];
    u32 field_540;
};
PKMN_OFFSET_ASSERT(Unk_e7c1d0, field_540, 0x540);

// 0x7100e7c1d0
bool Unk_e7c1d0_check(const Unk_e7c1d0* self) {
    return self->field_540 >= 1 && self->field_540 <= 2;
}

struct Unk_e7c1f0 {
    u8 _0[0x540];
    u32 field_540;
};
PKMN_OFFSET_ASSERT(Unk_e7c1f0, field_540, 0x540);

// 0x7100e7c1f0
bool Unk_e7c1f0_check(const Unk_e7c1f0* self) {
    return self->field_540 >= 3 && self->field_540 <= 4;
}

struct Unk_e7f7b0_8_60 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_e7f7b0_8_60, field_b0, 0xb0);

struct Unk_e7f7b0_8 {
    u8 _0[0x60];
    Unk_e7f7b0_8_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e7f7b0_8, field_60, 0x60);

struct Unk_e7f7b0 {
    u8 _0[0x8];
    Unk_e7f7b0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_e7f7b0, field_8, 0x8);

// 0x7100e7f7b0
u64 Unk_e7f7b0_get(const Unk_e7f7b0* self) {
    return self->field_8->field_60->field_b0;
}

struct Unk_e7f7c0_60 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_e7f7c0_60, field_b0, 0xb0);

struct Unk_e7f7c0 {
    u8 _0[0x60];
    Unk_e7f7c0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e7f7c0, field_60, 0x60);

// 0x7100e7f7c0
u64 Unk_e7f7c0_get(const Unk_e7f7c0* self) {
    return self->field_60->field_b0;
}

struct Unk_e7f7d0_8_60 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_e7f7d0_8_60, field_b0, 0xb0);

struct Unk_e7f7d0_8 {
    u8 _0[0x60];
    Unk_e7f7d0_8_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e7f7d0_8, field_60, 0x60);

struct Unk_e7f7d0 {
    u8 _0[0x8];
    Unk_e7f7d0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_e7f7d0, field_8, 0x8);

// 0x7100e7f7d0
u64 Unk_e7f7d0_get(const Unk_e7f7d0* self) {
    return self->field_8->field_60->field_b0;
}

struct Unk_e7f7e0_60 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_e7f7e0_60, field_b0, 0xb0);

struct Unk_e7f7e0 {
    u8 _0[0x60];
    Unk_e7f7e0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e7f7e0, field_60, 0x60);

// 0x7100e7f7e0
u64 Unk_e7f7e0_get(const Unk_e7f7e0* self) {
    return self->field_60->field_b0;
}

struct Unk_e806a0 {
    u8 _0[0x5a0];
    u64 field_5a0;
};
PKMN_OFFSET_ASSERT(Unk_e806a0, field_5a0, 0x5a0);

// 0x7100e806a0
u64 Unk_e806a0_getField5a0(const Unk_e806a0* self) {
    return self->field_5a0;
}

// 0x7100e87c40
void Unk_e87c40() {}

// 0x7100e88350
void Unk_e88350() {}

struct Unk_e88fe0 {
    u8 _0[0xd30];
    u64 field_d30;
};
PKMN_OFFSET_ASSERT(Unk_e88fe0, field_d30, 0xd30);

// 0x7100e88fe0
bool Unk_e88fe0_check(const Unk_e88fe0* self) {
    return self->field_d30 != 0;
}

struct Unk_e88ff0 {
    u8 _0[0xd5c];
    s32 field_d5c;
};
PKMN_OFFSET_ASSERT(Unk_e88ff0, field_d5c, 0xd5c);

// 0x7100e88ff0
bool Unk_e88ff0_check(const Unk_e88ff0* self) {
    return self->field_d5c > 0;
}
