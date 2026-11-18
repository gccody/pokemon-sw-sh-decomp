// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b0e2e0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0e2e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0e2e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0e2e0_arg1, field_10, 0x10);

struct Unk_b0e2e0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0e2e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0e2e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0e2e0, field_10, 0x10);

// 0x7100b0e2e0
void Unk_b0e2e0_call(const Unk_b0e2e0* self, Unk_b0e2e0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0e310_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0e310_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0e310_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0e310_arg1, field_10, 0x10);

struct Unk_b0e310 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0e310, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0e310, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0e310, field_10, 0x10);

// 0x7100b0e310
void Unk_b0e310_call(const Unk_b0e310* self, Unk_b0e310_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0e6e0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0e6e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0e6e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0e6e0_arg1, field_10, 0x10);

struct Unk_b0e6e0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0e6e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0e6e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0e6e0, field_10, 0x10);

// 0x7100b0e6e0
void Unk_b0e6e0_call(const Unk_b0e6e0* self, Unk_b0e6e0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0e710_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0e710_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0e710_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0e710_arg1, field_10, 0x10);

struct Unk_b0e710 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0e710, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0e710, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0e710, field_10, 0x10);

// 0x7100b0e710
void Unk_b0e710_call(const Unk_b0e710* self, Unk_b0e710_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}
