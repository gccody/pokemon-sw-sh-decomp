// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100ff7c20
void Unk_ff7c20_update() {}

struct Unk_ff7c30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7c30_arg1, field_0, 0x0);

struct Unk_ff7c30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7c30, field_0, 0x0);

// 0x7100ff7c30
void Unk_ff7c30_set(const Unk_ff7c30* self, Unk_ff7c30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7c40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7c40_arg1, field_0, 0x0);

struct Unk_ff7c40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7c40, field_0, 0x0);

// 0x7100ff7c40
void Unk_ff7c40_set(const Unk_ff7c40* self, Unk_ff7c40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7cc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7cc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7cc0_arg1, field_8, 0x8);

struct Unk_ff7cc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7cc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7cc0, field_8, 0x8);

// 0x7100ff7cc0
void Unk_ff7cc0_call(const Unk_ff7cc0* self, Unk_ff7cc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7cf0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7cf0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7cf0_arg1, field_8, 0x8);

struct Unk_ff7cf0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7cf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7cf0, field_8, 0x8);

// 0x7100ff7cf0
void Unk_ff7cf0_call(const Unk_ff7cf0* self, Unk_ff7cf0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7d90_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7d90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7d90_arg1, field_8, 0x8);

struct Unk_ff7d90 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7d90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7d90, field_8, 0x8);

// 0x7100ff7d90
void Unk_ff7d90_call(const Unk_ff7d90* self, Unk_ff7d90_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7dc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7dc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7dc0_arg1, field_8, 0x8);

struct Unk_ff7dc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7dc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7dc0, field_8, 0x8);

// 0x7100ff7dc0
void Unk_ff7dc0_call(const Unk_ff7dc0* self, Unk_ff7dc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7df0_0 {
    u8 _0[0x218];
    u8 field_218;
    u8 _219[0x3];
    u32 field_21c;
};
PKMN_OFFSET_ASSERT(Unk_ff7df0_0, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_ff7df0_0, field_21c, 0x21c);

struct Unk_ff7df0 {
    Unk_ff7df0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7df0, field_0, 0x0);

// 0x7100ff7df0
void Unk_ff7df0_set(const Unk_ff7df0* self) {
    Unk_ff7df0_0* p0 = self->field_0;
    p0->field_21c = 5;
    p0->field_218 = 1;
}

// 0x7100ff7e10
void Unk_ff7e10_update() {}

struct Unk_ff7e20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e20_arg1, field_0, 0x0);

struct Unk_ff7e20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e20, field_0, 0x0);

// 0x7100ff7e20
void Unk_ff7e20_set(const Unk_ff7e20* self, Unk_ff7e20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7e30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e30_arg1, field_0, 0x0);

struct Unk_ff7e30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e30, field_0, 0x0);

// 0x7100ff7e30
void Unk_ff7e30_set(const Unk_ff7e30* self, Unk_ff7e30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7e40_0 {
    u8 _0[0x218];
    u8 field_218;
    u8 _219[0x3];
    u32 field_21c;
};
PKMN_OFFSET_ASSERT(Unk_ff7e40_0, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_ff7e40_0, field_21c, 0x21c);

struct Unk_ff7e40 {
    Unk_ff7e40_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e40, field_0, 0x0);

// 0x7100ff7e40
void Unk_ff7e40_set(const Unk_ff7e40* self) {
    Unk_ff7e40_0* p0 = self->field_0;
    p0->field_21c = 6;
    p0->field_218 = 1;
}

// 0x7100ff7e60
void Unk_ff7e60_update() {}

struct Unk_ff7e70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e70_arg1, field_0, 0x0);

struct Unk_ff7e70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e70, field_0, 0x0);

// 0x7100ff7e70
void Unk_ff7e70_set(const Unk_ff7e70* self, Unk_ff7e70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7e80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e80_arg1, field_0, 0x0);

struct Unk_ff7e80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e80, field_0, 0x0);

// 0x7100ff7e80
void Unk_ff7e80_set(const Unk_ff7e80* self, Unk_ff7e80_arg1* value) {
    value->field_0 = self->field_0;
}
