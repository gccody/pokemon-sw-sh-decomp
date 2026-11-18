// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_11157b0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_11157b0, field_6c, 0x6c);

// 0x71011157b0
u32 Unk_11157b0_getField6c(const Unk_11157b0* self) {
    return self->field_6c;
}

struct Unk_11168d0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11168d0_arg1, field_0, 0x0);

struct Unk_11168d0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11168d0, field_0, 0x0);

// 0x71011168d0
void Unk_11168d0_call(const Unk_11168d0* self, Unk_11168d0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_11168f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11168f0_arg1, field_0, 0x0);

struct Unk_11168f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11168f0, field_0, 0x0);

// 0x71011168f0
void Unk_11168f0_set(Unk_11168f0* self, Unk_11168f0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

// 0x71011169f0
void Unk_11169f0_update() {}

// 0x7101116a00
void Unk_1116a00_update() {}

// 0x7101116a10
void Unk_1116a10_update() {}

// 0x7101116b00
void Unk_1116b00_update() {}

struct Unk_1116b10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1116b10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1116b10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1116b10, field_10, 0x10);

// 0x7101116b10
void Unk_1116b10_set(const Unk_1116b10* self, Unk_1116b10* value) {
    *value = *self;
}

struct Unk_1116b30 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1116b30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1116b30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1116b30, field_10, 0x10);

// 0x7101116b30
void Unk_1116b30_set(const Unk_1116b30* self, Unk_1116b30* value) {
    *value = *self;
}

// 0x71011186e0
void Unk_11186e0_update() {}

struct Unk_11186f0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11186f0_arg1, field_0, 0x0);

struct Unk_11186f0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11186f0, field_0, 0x0);

// 0x71011186f0
void Unk_11186f0_set(const Unk_11186f0* self, Unk_11186f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1118700_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1118700_arg1, field_0, 0x0);

struct Unk_1118700 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1118700, field_0, 0x0);

// 0x7101118700
void Unk_1118700_set(const Unk_1118700* self, Unk_1118700_arg1* value) {
    value->field_0 = self->field_0;
}
