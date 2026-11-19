// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_1474030 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1474030, field_8, 0x8);

// 0x7101474030
void Unk_1474030_call(Unk_1474030* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_1474070_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1474070_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1474070_arg1, field_8, 0x8);

struct Unk_1474070 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1474070, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1474070, field_8, 0x8);

// 0x7101474070
void Unk_1474070_call(const Unk_1474070* self, Unk_1474070_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_14740a0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14740a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14740a0_arg1, field_8, 0x8);

struct Unk_14740a0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14740a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14740a0, field_8, 0x8);

// 0x71014740a0
void Unk_14740a0_call(const Unk_14740a0* self, Unk_14740a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_14742b0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14742b0, field_8, 0x8);

// 0x71014742b0
void Unk_14742b0_call(Unk_14742b0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_14742f0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14742f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14742f0_arg1, field_8, 0x8);

struct Unk_14742f0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14742f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14742f0, field_8, 0x8);

// 0x71014742f0
void Unk_14742f0_call(const Unk_14742f0* self, Unk_14742f0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1474320_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1474320_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1474320_arg1, field_8, 0x8);

struct Unk_1474320 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1474320, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1474320, field_8, 0x8);

// 0x7101474320
void Unk_1474320_call(const Unk_1474320* self, Unk_1474320_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
