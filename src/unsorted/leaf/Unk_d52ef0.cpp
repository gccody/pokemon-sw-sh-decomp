// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d52ef0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d52ef0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d52ef0_arg1, field_8, 0x8);
struct Unk_d52ef0 {
    u8 _0[0xb0];
    u64 field_b0;
    u64 field_b8;
    u8 field_c0;
    u8 _c1[0x498];
    u8 field_559;
};
PKMN_OFFSET_ASSERT(Unk_d52ef0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_d52ef0, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_d52ef0, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_d52ef0, field_559, 0x559);

// 0x7100d52ef0
void Unk_d52ef0_update(Unk_d52ef0* self, const Unk_d52ef0_arg1* value) {
    if (self->field_559 != 0) {
        return;
    }
    self->field_b8 = value->field_8;
    self->field_b0 = value->field_0;
    self->field_c0 = 1;
}

// 0x7100d538b0
void Unk_d538b0_update() {}

struct Unk_d538c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d538c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d538c0, field_8, 0x8);

// 0x7100d538c0
void Unk_d538c0_set(const Unk_d538c0* self, Unk_d538c0* value) {
    *value = *self;
}

struct Unk_d538d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d538d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d538d0, field_8, 0x8);

// 0x7100d538d0
void Unk_d538d0_set(const Unk_d538d0* self, Unk_d538d0* value) {
    *value = *self;
}
