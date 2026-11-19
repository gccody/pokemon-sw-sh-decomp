// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_fb3180 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb3180, field_8, 0x8);

// 0x7100fb3180
void Unk_fb3180_call(Unk_fb3180* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_fb31c0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb31c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb31c0_arg1, field_8, 0x8);

struct Unk_fb31c0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb31c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb31c0, field_8, 0x8);

// 0x7100fb31c0
void Unk_fb31c0_call(const Unk_fb31c0* self, Unk_fb31c0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fb31f0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb31f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb31f0_arg1, field_8, 0x8);

struct Unk_fb31f0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb31f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb31f0, field_8, 0x8);

// 0x7100fb31f0
void Unk_fb31f0_call(const Unk_fb31f0* self, Unk_fb31f0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fb3270 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb3270, field_8, 0x8);

// 0x7100fb3270
void Unk_fb3270_call(Unk_fb3270* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_fb32b0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb32b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb32b0_arg1, field_8, 0x8);

struct Unk_fb32b0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb32b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb32b0, field_8, 0x8);

// 0x7100fb32b0
void Unk_fb32b0_call(const Unk_fb32b0* self, Unk_fb32b0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fb32e0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb32e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb32e0_arg1, field_8, 0x8);

struct Unk_fb32e0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb32e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb32e0, field_8, 0x8);

// 0x7100fb32e0
void Unk_fb32e0_call(const Unk_fb32e0* self, Unk_fb32e0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
