// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10f43f0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f43f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f43f0_arg1, field_8, 0x8);

struct Unk_10f43f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f43f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f43f0, field_8, 0x8);

// 0x71010f43f0
void Unk_10f43f0_set(Unk_10f43f0* self, Unk_10f43f0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10f44f0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f44f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f44f0_arg1, field_8, 0x8);

struct Unk_10f44f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f44f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f44f0, field_8, 0x8);

// 0x71010f44f0
void Unk_10f44f0_set(Unk_10f44f0* self, Unk_10f44f0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10f4570 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f4570, field_0, 0x0);

// 0x71010f4570
void Unk_10f4570_call(Unk_10f4570* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10f45b0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f45b0_arg1, field_0, 0x0);

struct Unk_10f45b0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f45b0, field_0, 0x0);

// 0x71010f45b0
void Unk_10f45b0_call(const Unk_10f45b0* self, Unk_10f45b0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10f45d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f45d0_arg1, field_0, 0x0);

struct Unk_10f45d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f45d0, field_0, 0x0);

// 0x71010f45d0
void Unk_10f45d0_set(Unk_10f45d0* self, Unk_10f45d0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}
