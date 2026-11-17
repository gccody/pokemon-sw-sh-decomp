// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_113e9c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_113e9c0_arg1, field_0, 0x0);

struct Unk_113e9c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_113e9c0, field_0, 0x0);

// 0x710113e9c0
bool Unk_113e9c0_check(const Unk_113e9c0* self, const Unk_113e9c0_arg1* value) {
    return self->field_0 == value->field_0;
}

struct Unk_113e9e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_113e9e0_arg1, field_0, 0x0);

struct Unk_113e9e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_113e9e0, field_0, 0x0);

// 0x710113e9e0
bool Unk_113e9e0_check(const Unk_113e9e0* self, const Unk_113e9e0_arg1* value) {
    return self->field_0 != value->field_0;
}

struct Unk_113ea00 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_113ea00, field_8, 0x8);

// 0x710113ea00
bool Unk_113ea00_check(const Unk_113ea00* self) {
    return (self->field_8 & 0x10) == 0;
}

struct Unk_113f1b0 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_113f1b0, field_90, 0x90);

// 0x710113f1b0
u8 Unk_113f1b0_getField90(const Unk_113f1b0* self) {
    return self->field_90;
}

struct Unk_113f1c0 {
    u8 _0[0x90];
    bool field_90;
};
PKMN_OFFSET_ASSERT(Unk_113f1c0, field_90, 0x90);

// 0x710113f1c0
void Unk_113f1c0_set(Unk_113f1c0* self, bool value) {
    self->field_90 = value;
}
