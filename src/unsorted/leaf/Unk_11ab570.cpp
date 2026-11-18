// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011ab570
void Unk_11ab570_update() {}

struct Unk_11ab580 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11ab580, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab580, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab580, field_10, 0x10);

// 0x71011ab580
void Unk_11ab580_set(const Unk_11ab580* self, Unk_11ab580* value) {
    *value = *self;
}

struct Unk_11ab5a0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11ab5a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab5a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab5a0, field_10, 0x10);

// 0x71011ab5a0
void Unk_11ab5a0_set(const Unk_11ab5a0* self, Unk_11ab5a0* value) {
    *value = *self;
}

struct Unk_11ab7c0_0 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_11ab7c0_0, field_b0, 0xb0);

struct Unk_11ab7c0 {
    Unk_11ab7c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ab7c0, field_0, 0x0);

// 0x71011ab7c0
void Unk_11ab7c0_set(const Unk_11ab7c0* self) {
    self->field_0->field_b0 = 3;
}

// 0x71011ab7d0
void Unk_11ab7d0_update() {}

struct Unk_11ab7e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ab7e0_arg1, field_0, 0x0);

struct Unk_11ab7e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ab7e0, field_0, 0x0);

// 0x71011ab7e0
void Unk_11ab7e0_set(const Unk_11ab7e0* self, Unk_11ab7e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ab7f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ab7f0_arg1, field_0, 0x0);

struct Unk_11ab7f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ab7f0, field_0, 0x0);

// 0x71011ab7f0
void Unk_11ab7f0_set(const Unk_11ab7f0* self, Unk_11ab7f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ab850
void Unk_11ab850_update() {}

struct Unk_11ab860_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_11ab860_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab860_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab860_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_11ab860_arg1, field_18, 0x18);

struct Unk_11ab860 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_11ab860, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab860, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab860, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_11ab860, field_18, 0x18);

// 0x71011ab860
void Unk_11ab860_set(const Unk_11ab860* self, Unk_11ab860_arg1* value) {
    u64 v0 = self->field_8;
    value->field_18 = self->field_18;
    value->field_8 = v0;
    u64 v1 = self->field_0;
    value->field_10 = self->field_10;
    value->field_0 = v1;
}

struct Unk_11ab890_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_11ab890_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab890_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab890_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_11ab890_arg1, field_18, 0x18);

struct Unk_11ab890 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_11ab890, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab890, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab890, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_11ab890, field_18, 0x18);

// 0x71011ab890
void Unk_11ab890_set(const Unk_11ab890* self, Unk_11ab890_arg1* value) {
    u64 v0 = self->field_8;
    value->field_18 = self->field_18;
    value->field_8 = v0;
    u64 v1 = self->field_0;
    value->field_10 = self->field_10;
    value->field_0 = v1;
}

// 0x71011ab910
void Unk_11ab910_update() {}

struct Unk_11ab920_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_11ab920_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab920_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab920_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_11ab920_arg1, field_18, 0x18);

struct Unk_11ab920 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_11ab920, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab920, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab920, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_11ab920, field_18, 0x18);

// 0x71011ab920
void Unk_11ab920_set(const Unk_11ab920* self, Unk_11ab920_arg1* value) {
    u64 v0 = self->field_8;
    value->field_18 = self->field_18;
    value->field_8 = v0;
    u64 v1 = self->field_0;
    value->field_10 = self->field_10;
    value->field_0 = v1;
}

struct Unk_11ab950_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_11ab950_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab950_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab950_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_11ab950_arg1, field_18, 0x18);

struct Unk_11ab950 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_11ab950, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11ab950, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11ab950, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_11ab950, field_18, 0x18);

// 0x71011ab950
void Unk_11ab950_set(const Unk_11ab950* self, Unk_11ab950_arg1* value) {
    u64 v0 = self->field_8;
    value->field_18 = self->field_18;
    value->field_8 = v0;
    u64 v1 = self->field_0;
    value->field_10 = self->field_10;
    value->field_0 = v1;
}
