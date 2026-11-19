// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7101295980
void Unk_1295980_update() {}

struct Unk_1295990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1295990_arg1, field_0, 0x0);

struct Unk_1295990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1295990, field_0, 0x0);

// 0x7101295990
void Unk_1295990_set(const Unk_1295990* self, Unk_1295990_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12959a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12959a0_arg1, field_0, 0x0);

struct Unk_12959a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12959a0, field_0, 0x0);

// 0x71012959a0
void Unk_12959a0_set(const Unk_12959a0* self, Unk_12959a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1296040 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1296040, field_0, 0x0);

// 0x7101296040
void Unk_1296040_call(Unk_1296040* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_1296080_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1296080_arg1, field_0, 0x0);

struct Unk_1296080 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1296080, field_0, 0x0);

// 0x7101296080
void Unk_1296080_call(const Unk_1296080* self, Unk_1296080_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_12960a0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12960a0_arg1, field_0, 0x0);

struct Unk_12960a0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12960a0, field_0, 0x0);

// 0x71012960a0
void Unk_12960a0_call(const Unk_12960a0* self, Unk_12960a0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x71012960d0
void Unk_12960d0_update() {}

struct Unk_12960e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12960e0_arg1, field_0, 0x0);

struct Unk_12960e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12960e0, field_0, 0x0);

// 0x71012960e0
void Unk_12960e0_set(const Unk_12960e0* self, Unk_12960e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12960f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12960f0_arg1, field_0, 0x0);

struct Unk_12960f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12960f0, field_0, 0x0);

// 0x71012960f0
void Unk_12960f0_set(const Unk_12960f0* self, Unk_12960f0_arg1* value) {
    value->field_0 = self->field_0;
}
