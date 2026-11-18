// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_ff23d0 {
    u8 _0[0x178];
    u32 field_178;
};
PKMN_OFFSET_ASSERT(Unk_ff23d0, field_178, 0x178);

// 0x7100ff23d0
void Unk_ff23d0_set(Unk_ff23d0* self) {
    self->field_178 = 0xb;
}

struct Unk_ff23e0 {
    u8 _0[0x178];
    u32 field_178;
};
PKMN_OFFSET_ASSERT(Unk_ff23e0, field_178, 0x178);

// 0x7100ff23e0
bool Unk_ff23e0_check(const Unk_ff23e0* self) {
    return self->field_178 == 0xd;
}

struct Unk_ff3ef0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff3ef0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff3ef0_arg1, field_8, 0x8);

struct Unk_ff3ef0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff3ef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff3ef0, field_8, 0x8);

// 0x7100ff3ef0
void Unk_ff3ef0_call(const Unk_ff3ef0* self, Unk_ff3ef0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff3f20_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff3f20_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff3f20_arg1, field_8, 0x8);

struct Unk_ff3f20 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff3f20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff3f20, field_8, 0x8);

// 0x7100ff3f20
void Unk_ff3f20_call(const Unk_ff3f20* self, Unk_ff3f20_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff3fb0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff3fb0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff3fb0_arg1, field_8, 0x8);

struct Unk_ff3fb0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff3fb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff3fb0, field_8, 0x8);

// 0x7100ff3fb0
void Unk_ff3fb0_call(const Unk_ff3fb0* self, Unk_ff3fb0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff3fe0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff3fe0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff3fe0_arg1, field_8, 0x8);

struct Unk_ff3fe0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff3fe0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff3fe0, field_8, 0x8);

// 0x7100ff3fe0
void Unk_ff3fe0_call(const Unk_ff3fe0* self, Unk_ff3fe0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff4080_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff4080_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff4080_arg1, field_8, 0x8);

struct Unk_ff4080 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff4080, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff4080, field_8, 0x8);

// 0x7100ff4080
void Unk_ff4080_call(const Unk_ff4080* self, Unk_ff4080_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff40b0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff40b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff40b0_arg1, field_8, 0x8);

struct Unk_ff40b0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff40b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff40b0, field_8, 0x8);

// 0x7100ff40b0
void Unk_ff40b0_call(const Unk_ff40b0* self, Unk_ff40b0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff4140_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff4140_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff4140_arg1, field_8, 0x8);

struct Unk_ff4140 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff4140, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff4140, field_8, 0x8);

// 0x7100ff4140
void Unk_ff4140_call(const Unk_ff4140* self, Unk_ff4140_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff4170_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff4170_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff4170_arg1, field_8, 0x8);

struct Unk_ff4170 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff4170, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff4170, field_8, 0x8);

// 0x7100ff4170
void Unk_ff4170_call(const Unk_ff4170* self, Unk_ff4170_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff41a0_0 {
    u8 _0[0x17c];
    u8 field_17c;
};
PKMN_OFFSET_ASSERT(Unk_ff41a0_0, field_17c, 0x17c);

struct Unk_ff41a0 {
    Unk_ff41a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff41a0, field_0, 0x0);

// 0x7100ff41a0
void Unk_ff41a0_set(const Unk_ff41a0* self) {
    self->field_0->field_17c = 1;
}

// 0x7100ff41b0
void Unk_ff41b0_update() {}

struct Unk_ff41c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff41c0_arg1, field_0, 0x0);

struct Unk_ff41c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff41c0, field_0, 0x0);

// 0x7100ff41c0
void Unk_ff41c0_set(const Unk_ff41c0* self, Unk_ff41c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff41d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff41d0_arg1, field_0, 0x0);

struct Unk_ff41d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff41d0, field_0, 0x0);

// 0x7100ff41d0
void Unk_ff41d0_set(const Unk_ff41d0* self, Unk_ff41d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff41e0_0 {
    u8 _0[0x17c];
    u8 field_17c;
};
PKMN_OFFSET_ASSERT(Unk_ff41e0_0, field_17c, 0x17c);

struct Unk_ff41e0 {
    Unk_ff41e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff41e0, field_0, 0x0);

// 0x7100ff41e0
void Unk_ff41e0_set(const Unk_ff41e0* self) {
    self->field_0->field_17c = 0;
}

// 0x7100ff41f0
void Unk_ff41f0_update() {}

struct Unk_ff4200_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff4200_arg1, field_0, 0x0);

struct Unk_ff4200 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff4200, field_0, 0x0);

// 0x7100ff4200
void Unk_ff4200_set(const Unk_ff4200* self, Unk_ff4200_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff4210_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff4210_arg1, field_0, 0x0);

struct Unk_ff4210 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff4210, field_0, 0x0);

// 0x7100ff4210
void Unk_ff4210_set(const Unk_ff4210* self, Unk_ff4210_arg1* value) {
    value->field_0 = self->field_0;
}
