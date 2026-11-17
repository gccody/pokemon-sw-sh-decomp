// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c5a8d0 {
    u8 _0[0x85];
    bool field_85;
};
PKMN_OFFSET_ASSERT(Unk_c5a8d0, field_85, 0x85);

// 0x7100c5a8d0
void Unk_c5a8d0_set(Unk_c5a8d0* self, bool value) {
    self->field_85 = value;
}

struct Unk_c63670_2c0 {
    u8 _0[0x84];
    bool field_84;
};
PKMN_OFFSET_ASSERT(Unk_c63670_2c0, field_84, 0x84);

struct Unk_c63670 {
    u8 _0[0x2c0];
    Unk_c63670_2c0* field_2c0;
};
PKMN_OFFSET_ASSERT(Unk_c63670, field_2c0, 0x2c0);

// 0x7100c63670
void Unk_c63670_set(const Unk_c63670* self, bool value) {
    if (self->field_2c0 != nullptr) {
        self->field_2c0->field_84 = value;
    }
}

struct Unk_c63690_2c0 {
    u8 _0[0x84];
    u8 field_84;
};
PKMN_OFFSET_ASSERT(Unk_c63690_2c0, field_84, 0x84);

struct Unk_c63690 {
    u8 _0[0x2c0];
    Unk_c63690_2c0* field_2c0;
};
PKMN_OFFSET_ASSERT(Unk_c63690, field_2c0, 0x2c0);

// 0x7100c63690
bool Unk_c63690_check(const Unk_c63690* self) {
    if (self->field_2c0 == nullptr) {
        return false;
    }
    return self->field_2c0->field_84 != 0;
}

extern bool Unk_23dc938;

// 0x7100c64770
void Unk_c64770_set(bool self) {
    Unk_23dc938 = self;
}

extern f32 Unk_23dc93c;

// 0x7100c64790
void Unk_c64790_set(f32 fvalue) {
    Unk_23dc93c = fvalue;
}

extern u32 Unk_27d9b88;

// 0x7100c647b0
u32 Unk_c647b0_get() {
    return Unk_27d9b88;
}

struct Unk_c68570 {
    u8 _0[0xe0];
    u64 field_e0;
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_c68570, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_c68570, field_e8, 0xe8);

// 0x7100c68570
void Unk_c68570_set(Unk_c68570* self) {
    self->field_e8 = self->field_e0;
}
