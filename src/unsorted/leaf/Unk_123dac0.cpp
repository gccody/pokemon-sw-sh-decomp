// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x710123dac0
void Unk_123dac0_update() {}

struct Unk_123dce0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_123dce0_arg1, field_0, 0x0);

struct Unk_123dce0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_123dce0, field_0, 0x0);

// 0x710123dce0
void Unk_123dce0_call(const Unk_123dce0* self, Unk_123dce0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_123dd00_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_123dd00_arg1, field_0, 0x0);

struct Unk_123dd00 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_123dd00, field_0, 0x0);

// 0x710123dd00
void Unk_123dd00_call(const Unk_123dd00* self, Unk_123dd00_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_123dd20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_123dd20_arg1, field_0, 0x0);

struct Unk_123dd20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_123dd20, field_0, 0x0);

// 0x710123dd20
void Unk_123dd20_set(const Unk_123dd20* self, Unk_123dd20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_123dd30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_123dd30_arg1, field_0, 0x0);

struct Unk_123dd30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_123dd30, field_0, 0x0);

// 0x710123dd30
void Unk_123dd30_set(const Unk_123dd30* self, Unk_123dd30_arg1* value) {
    value->field_0 = self->field_0;
}
