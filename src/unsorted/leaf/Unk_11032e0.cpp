// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_11032e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11032e0, field_0, 0x0);

// 0x71011032e0
void Unk_11032e0_call(Unk_11032e0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_1103320_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103320_arg1, field_0, 0x0);

struct Unk_1103320 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103320, field_0, 0x0);

// 0x7101103320
void Unk_1103320_call(const Unk_1103320* self, Unk_1103320_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1103340_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103340_arg1, field_0, 0x0);

struct Unk_1103340 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103340, field_0, 0x0);

// 0x7101103340
void Unk_1103340_set(Unk_1103340* self, Unk_1103340_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1103420_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1103420_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1103420_arg1, field_8, 0x8);

struct Unk_1103420 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1103420, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1103420, field_8, 0x8);

// 0x7101103420
void Unk_1103420_set(Unk_1103420* self, Unk_1103420_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_11034a0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11034a0, field_0, 0x0);

// 0x71011034a0
void Unk_11034a0_call(Unk_11034a0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_11034e0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11034e0_arg1, field_0, 0x0);

struct Unk_11034e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11034e0, field_0, 0x0);

// 0x71011034e0
void Unk_11034e0_call(const Unk_11034e0* self, Unk_11034e0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1103500_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103500_arg1, field_0, 0x0);

struct Unk_1103500 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103500, field_0, 0x0);

// 0x7101103500
void Unk_1103500_set(Unk_1103500* self, Unk_1103500_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}
