// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1498d80 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1498d80, field_58, 0x58);

void Unk_1498d90(u64);

// 0x7101498d80
void Unk_1498d80_call(const Unk_1498d80* self) {
    Unk_1498d90(self->field_58);
}

struct Unk_149e880 {
    u8 _0[0xb68];
    u32 field_b68;
    u32 field_b6c;
    u32 field_b70;
    u32 field_b74;
    u32 field_b78;
    u32 field_b7c;
};
PKMN_OFFSET_ASSERT(Unk_149e880, field_b68, 0xb68);
PKMN_OFFSET_ASSERT(Unk_149e880, field_b6c, 0xb6c);
PKMN_OFFSET_ASSERT(Unk_149e880, field_b70, 0xb70);
PKMN_OFFSET_ASSERT(Unk_149e880, field_b74, 0xb74);
PKMN_OFFSET_ASSERT(Unk_149e880, field_b78, 0xb78);
PKMN_OFFSET_ASSERT(Unk_149e880, field_b7c, 0xb7c);

// 0x710149e880
void Unk_149e880_set(Unk_149e880* self) {
    self->field_b68 = self->field_b6c;
    self->field_b70 = self->field_b74;
    self->field_b78 = self->field_b7c;
}

struct Unk_149f950_5d8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_149f950_5d8, field_58, 0x58);

struct Unk_149f950 {
    u8 _0[0x5d8];
    Unk_149f950_5d8* field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_149f950, field_5d8, 0x5d8);

// 0x710149f950
void Unk_149f950_set(const Unk_149f950* self) {
    self->field_5d8->field_58 = self->field_5d8->field_58 & 0xfe;
}

struct Unk_149fa80_5d8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_149fa80_5d8, field_58, 0x58);

struct Unk_149fa80 {
    u8 _0[0x5d8];
    Unk_149fa80_5d8* field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_149fa80, field_5d8, 0x5d8);

// 0x710149fa80
void Unk_149fa80_set(const Unk_149fa80* self) {
    self->field_5d8->field_58 = self->field_5d8->field_58 | 1;
}

// 0x71014a8b70
u32 Unk_14a8b70_get() {
    return 1;
}

struct Unk_14a91a0 {
    u8 _0[0x78];
    u32 field_78;
    u8 _7c[0x5c];
    u8 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_14a91a0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_14a91a0, field_d8, 0xd8);

// 0x71014a91a0
void Unk_14a91a0_set(Unk_14a91a0* self) {
    self->field_d8 = 1;
    self->field_78 = 2;
}

struct Unk_14a92b0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_14a92b0, field_78, 0x78);

// 0x71014a92b0
u32 Unk_14a92b0_getField78(const Unk_14a92b0* self) {
    return self->field_78;
}

struct Unk_14a92c0 {
    u8 _0[0xb0];
    u32 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_14a92c0, field_b0, 0xb0);

// 0x71014a92c0
u32 Unk_14a92c0_getFieldb0(const Unk_14a92c0* self) {
    return self->field_b0;
}

struct Unk_14a9570 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_14a9570, field_c0, 0xc0);

void Unk_6859b0(u64);

// 0x71014a9570
void Unk_14a9570_call(const Unk_14a9570* self) {
    Unk_6859b0(self->field_c0);
}

struct Unk_14a9580 {
    u8 _0[0xd9];
    bool field_d9;
};
PKMN_OFFSET_ASSERT(Unk_14a9580, field_d9, 0xd9);

// 0x71014a9580
void Unk_14a9580_set(Unk_14a9580* self, bool value) {
    self->field_d9 = value;
}

struct Unk_14ac420 {
    u8 _0[0x2fc];
    u8 field_2fc;
};
PKMN_OFFSET_ASSERT(Unk_14ac420, field_2fc, 0x2fc);

// 0x71014ac420
u8 Unk_14ac420_getField2fc(const Unk_14ac420* self) {
    return self->field_2fc;
}
