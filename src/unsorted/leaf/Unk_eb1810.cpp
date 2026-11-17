// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_eb1810 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_eb1810, field_148, 0x148);

// 0x7100eb1810
bool Unk_eb1810_check(const Unk_eb1810* self) {
    return self->field_148 != 0;
}

struct Unk_eb50f0_60 {
    u8 _0[0x48];
    bool field_48;
};
PKMN_OFFSET_ASSERT(Unk_eb50f0_60, field_48, 0x48);

struct Unk_eb50f0 {
    u8 _0[0x60];
    Unk_eb50f0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_eb50f0, field_60, 0x60);

// 0x7100eb50f0
void Unk_eb50f0_set(const Unk_eb50f0* self, bool value) {
    self->field_60->field_48 = value;
}

struct Unk_eb5c60 {
    u8 _0[0x40];
    s32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_eb5c60, field_40, 0x40);

// 0x7100eb5c60
bool Unk_eb5c60_check(const Unk_eb5c60* self) {
    return self->field_40 > 1;
}

struct Unk_eb5c70 {
    u8 _0[0x40];
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_eb5c70, field_40, 0x40);

// 0x7100eb5c70
bool Unk_eb5c70_check(const Unk_eb5c70* self) {
    return (self->field_40 | 1) == 3;
}

void Unk_eb6230(void*, u32);

// 0x7100eb6070
void Unk_eb6070_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_eb76a0 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_eb76a0, field_5d0, 0x5d0);

void Unk_14eaa70(u64);

// 0x7100eb76a0
void Unk_eb76a0_call(const Unk_eb76a0* self) {
    Unk_14eaa70(self->field_5d0);
}

struct Unk_eb7720 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_eb7720, field_5d0, 0x5d0);

void Unk_14eaaf0(u64);

// 0x7100eb7720
void Unk_eb7720_call(const Unk_eb7720* self) {
    Unk_14eaaf0(self->field_5d0);
}

struct Unk_ebc2f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebc2f0_arg1, field_0, 0x0);

struct Unk_ebc2f0 {
    u8 _0[0x6b8];
    u64 field_6b8;
};
PKMN_OFFSET_ASSERT(Unk_ebc2f0, field_6b8, 0x6b8);

void Unk_67bc30(u64, u64);

// 0x7100ebc2f0
void Unk_ebc2f0_call(const Unk_ebc2f0* self, const Unk_ebc2f0_arg1* value) {
    Unk_67bc30(self->field_6b8, value->field_0);
}

struct Unk_ebcbf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcbf0_arg1, field_0, 0x0);

struct Unk_ebcbf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ebcbf0, field_0, 0x0);

// 0x7100ebcbf0
void Unk_ebcbf0_set(const Unk_ebcbf0* self, Unk_ebcbf0_arg1* value) {
    value->field_0 = self->field_0;
}

void Unk_eb6230(void*, u32);

// 0x7100ec2fb0
void Unk_ec2fb0_call(void* self) {
    Unk_eb6230(self, 3);
}

void Unk_eb6230(void*, u32);

// 0x7100ec6e20
void Unk_ec6e20_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_ec6e30_5d0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_ec6e30_5d0, field_58, 0x58);

struct Unk_ec6e30 {
    u8 _0[0x5d0];
    Unk_ec6e30_5d0* field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_ec6e30, field_5d0, 0x5d0);

// 0x7100ec6e30
u32 Unk_ec6e30_get(const Unk_ec6e30* self) {
    return self->field_5d0->field_58 & 1;
}
