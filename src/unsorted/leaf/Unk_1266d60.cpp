// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101266d60
void Unk_1266d60_update() {}

struct Unk_1266d70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1266d70_arg1, field_0, 0x0);

struct Unk_1266d70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1266d70, field_0, 0x0);

// 0x7101266d70
void Unk_1266d70_set(const Unk_1266d70* self, Unk_1266d70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1266d80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1266d80_arg1, field_0, 0x0);

struct Unk_1266d80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1266d80, field_0, 0x0);

// 0x7101266d80
void Unk_1266d80_set(const Unk_1266d80* self, Unk_1266d80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1267a90 {
    u8 _0[0x650];
    u64 field_650;
};
PKMN_OFFSET_ASSERT(Unk_1267a90, field_650, 0x650);

void Unk_14bacd0(u64);

// 0x7101267a90
void Unk_1267a90_call(const Unk_1267a90* self) {
    if (self->field_650 != 0) {
        Unk_14bacd0(self->field_650);
    }
}

// 0x7101268210
void Unk_1268210_update() {}

struct Unk_1268220_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1268220_arg1, field_0, 0x0);

struct Unk_1268220 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1268220, field_0, 0x0);

// 0x7101268220
void Unk_1268220_set(const Unk_1268220* self, Unk_1268220_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1268230_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1268230_arg1, field_0, 0x0);

struct Unk_1268230 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1268230, field_0, 0x0);

// 0x7101268230
void Unk_1268230_set(const Unk_1268230* self, Unk_1268230_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012682d0
void Unk_12682d0_update() {}

struct Unk_12682e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_12682e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12682e0, field_8, 0x8);

// 0x71012682e0
void Unk_12682e0_set(const Unk_12682e0* self, Unk_12682e0* value) {
    *value = *self;
}

struct Unk_12682f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_12682f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_12682f0, field_8, 0x8);

// 0x71012682f0
void Unk_12682f0_set(const Unk_12682f0* self, Unk_12682f0* value) {
    *value = *self;
}
