// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_c25e80 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_c25e80, field_8, 0x8);

// 0x7100c25e80
void Unk_c25e80_call(Unk_c25e80* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_c25ec0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_c25ec0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c25ec0_arg1, field_8, 0x8);

struct Unk_c25ec0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_c25ec0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c25ec0, field_8, 0x8);

// 0x7100c25ec0
void Unk_c25ec0_call(const Unk_c25ec0* self, Unk_c25ec0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_c25ef0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c25ef0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c25ef0_arg1, field_8, 0x8);

struct Unk_c25ef0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c25ef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c25ef0, field_8, 0x8);

// 0x7100c25ef0
void Unk_c25ef0_set(Unk_c25ef0* self, Unk_c25ef0_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

// 0x7100c26090
void Unk_c26090_update() {}

struct Unk_c260a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c260a0_arg1, field_0, 0x0);

struct Unk_c260a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c260a0, field_0, 0x0);

// 0x7100c260a0
void Unk_c260a0_set(const Unk_c260a0* self, Unk_c260a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c260b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c260b0_arg1, field_0, 0x0);

struct Unk_c260b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c260b0, field_0, 0x0);

// 0x7100c260b0
void Unk_c260b0_set(const Unk_c260b0* self, Unk_c260b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c262e0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_c262e0, field_58, 0x58);

void Unk_c21b90(void*);
void Unk_c338e0(void*, void*);

// 0x7100c262e0
void Unk_c262e0_call(Unk_c262e0* self) {
    Unk_c21b90(&self->field_58);
    Unk_c338e0(self, &self->field_58);
}

// 0x7100c28fa0
void Unk_c28fa0_update() {}

struct Unk_c28fb0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c28fb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c28fb0, field_8, 0x8);

// 0x7100c28fb0
void Unk_c28fb0_set(const Unk_c28fb0* self, Unk_c28fb0* value) {
    *value = *self;
}

struct Unk_c28fc0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_c28fc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c28fc0, field_8, 0x8);

// 0x7100c28fc0
void Unk_c28fc0_set(const Unk_c28fc0* self, Unk_c28fc0* value) {
    *value = *self;
}
