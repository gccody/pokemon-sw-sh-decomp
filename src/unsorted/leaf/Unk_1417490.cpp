// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_1417490 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1417490, field_8, 0x8);

// 0x7101417490
void Unk_1417490_call(Unk_1417490* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_14174d0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14174d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14174d0_arg1, field_8, 0x8);

struct Unk_14174d0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14174d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14174d0, field_8, 0x8);

// 0x71014174d0
void Unk_14174d0_call(const Unk_14174d0* self, Unk_14174d0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1417500_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1417500_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1417500_arg1, field_8, 0x8);

struct Unk_1417500 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1417500, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1417500, field_8, 0x8);

// 0x7101417500
void Unk_1417500_call(const Unk_1417500* self, Unk_1417500_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1417560 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1417560, field_8, 0x8);

// 0x7101417560
void Unk_1417560_call(Unk_1417560* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_14175a0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14175a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14175a0_arg1, field_8, 0x8);

struct Unk_14175a0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14175a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14175a0, field_8, 0x8);

// 0x71014175a0
void Unk_14175a0_call(const Unk_14175a0* self, Unk_14175a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_14175d0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14175d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14175d0_arg1, field_8, 0x8);

struct Unk_14175d0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14175d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14175d0, field_8, 0x8);

// 0x71014175d0
void Unk_14175d0_call(const Unk_14175d0* self, Unk_14175d0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
