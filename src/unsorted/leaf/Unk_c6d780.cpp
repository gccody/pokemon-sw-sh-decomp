// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100c6d780
void Unk_c6d780() {}

// 0x7100c6ebd0
void Unk_c6ebd0_update() {}

struct Unk_c6ebe0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6ebe0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6ebe0, field_8, 0x8);

// 0x7100c6ebe0
void Unk_c6ebe0_set(const Unk_c6ebe0* self, Unk_c6ebe0* value) {
    *value = *self;
}

struct Unk_c6ebf0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6ebf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6ebf0, field_8, 0x8);

// 0x7100c6ebf0
void Unk_c6ebf0_set(const Unk_c6ebf0* self, Unk_c6ebf0* value) {
    *value = *self;
}

// 0x7100c6ec60
void Unk_c6ec60_update() {}

struct Unk_c6ec70 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6ec70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6ec70, field_8, 0x8);

// 0x7100c6ec70
void Unk_c6ec70_set(const Unk_c6ec70* self, Unk_c6ec70* value) {
    *value = *self;
}

struct Unk_c6ec80 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6ec80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6ec80, field_8, 0x8);

// 0x7100c6ec80
void Unk_c6ec80_set(const Unk_c6ec80* self, Unk_c6ec80* value) {
    *value = *self;
}

// 0x7100c6ecf0
void Unk_c6ecf0_update() {}

struct Unk_c6ed00 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6ed00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6ed00, field_8, 0x8);

// 0x7100c6ed00
void Unk_c6ed00_set(const Unk_c6ed00* self, Unk_c6ed00* value) {
    *value = *self;
}

struct Unk_c6ed10 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6ed10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6ed10, field_8, 0x8);

// 0x7100c6ed10
void Unk_c6ed10_set(const Unk_c6ed10* self, Unk_c6ed10* value) {
    *value = *self;
}

// 0x7100c6ed60
void Unk_c6ed60_update() {}

struct Unk_c6ed70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c6ed70_arg1, field_0, 0x0);

struct Unk_c6ed70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c6ed70, field_0, 0x0);

// 0x7100c6ed70
void Unk_c6ed70_set(const Unk_c6ed70* self, Unk_c6ed70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c6ed80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c6ed80_arg1, field_0, 0x0);

struct Unk_c6ed80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c6ed80, field_0, 0x0);

// 0x7100c6ed80
void Unk_c6ed80_set(const Unk_c6ed80* self, Unk_c6ed80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c6ed90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c6ed90_arg1, field_0, 0x0);

void Unk_59b280(u64);

// 0x7100c6ed90
void Unk_c6ed90_call(void* /*unused*/, const Unk_c6ed90_arg1* value) {
    Unk_59b280(value->field_0);
}

// 0x7100c6eda0
void Unk_c6eda0_update() {}

// 0x7100c6edb0
void Unk_c6edb0_update() {}

// 0x7100c6edc0
void Unk_c6edc0_update() {}

// 0x7100c6ede0
void Unk_c6ede0_update() {}

// 0x7100c6edf0
void Unk_c6edf0_update() {}

// 0x7100c6ee00
void Unk_c6ee00_update() {}

struct Unk_59b2c0;
struct Unk_c6ee10_arg1 {
    Unk_59b2c0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_c6ee10_arg1, field_0, 0x0);

void Unk_59b2c0_set(Unk_59b2c0*);

// 0x7100c6ee10
void Unk_c6ee10_call(void* /*unused*/, const Unk_c6ee10_arg1* value) {
    Unk_59b2c0_set(value->field_0);
}

// 0x7100c6ee20
void Unk_c6ee20_update() {}

// 0x7100c6ee30
void Unk_c6ee30_update() {}

// 0x7100c6ee40
void Unk_c6ee40_update() {}

// 0x7100c6ee60
void Unk_c6ee60_update() {}

// 0x7100c6ee70
void Unk_c6ee70_update() {}

// 0x7100c6ee80
void Unk_c6ee80_update() {}

// 0x7100c6f030
void Unk_c6f030_update() {}

struct Unk_c6f040 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_c6f040, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6f040, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_c6f040, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_c6f040, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_c6f040, field_20, 0x20);

// 0x7100c6f040
void Unk_c6f040_set(const Unk_c6f040* self, Unk_c6f040* value) {
    *value = *self;
}

struct Unk_c6f060 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_c6f060, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6f060, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_c6f060, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_c6f060, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_c6f060, field_20, 0x20);

// 0x7100c6f060
void Unk_c6f060_set(const Unk_c6f060* self, Unk_c6f060* value) {
    *value = *self;
}

// 0x7100c6f2c0
void Unk_c6f2c0_update() {}

struct Unk_c6f2d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6f2d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6f2d0, field_8, 0x8);

// 0x7100c6f2d0
void Unk_c6f2d0_set(const Unk_c6f2d0* self, Unk_c6f2d0* value) {
    *value = *self;
}

struct Unk_c6f2e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6f2e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6f2e0, field_8, 0x8);

// 0x7100c6f2e0
void Unk_c6f2e0_set(const Unk_c6f2e0* self, Unk_c6f2e0* value) {
    *value = *self;
}

// 0x7100c6fca0
void Unk_c6fca0_update() {}

struct Unk_c6fcb0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6fcb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6fcb0, field_8, 0x8);

// 0x7100c6fcb0
void Unk_c6fcb0_set(const Unk_c6fcb0* self, Unk_c6fcb0* value) {
    *value = *self;
}

struct Unk_c6fcc0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6fcc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6fcc0, field_8, 0x8);

// 0x7100c6fcc0
void Unk_c6fcc0_set(const Unk_c6fcc0* self, Unk_c6fcc0* value) {
    *value = *self;
}

// 0x7100c6fed0
void Unk_c6fed0_update() {}

struct Unk_c6fee0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6fee0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6fee0, field_8, 0x8);

// 0x7100c6fee0
void Unk_c6fee0_set(const Unk_c6fee0* self, Unk_c6fee0* value) {
    *value = *self;
}

struct Unk_c6fef0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c6fef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c6fef0, field_8, 0x8);

// 0x7100c6fef0
void Unk_c6fef0_set(const Unk_c6fef0* self, Unk_c6fef0* value) {
    *value = *self;
}
