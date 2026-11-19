// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_ce08f0 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_ce08f0, field_68, 0x68);

// 0x7100ce08f0
bool Unk_ce08f0_check(const Unk_ce08f0* self) {
    return self->field_68 != 0;
}

// 0x7100ce0de0
void Unk_ce0de0_update() {}

struct Unk_ce0df0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ce0df0_arg1, field_0, 0x0);

struct Unk_ce0df0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ce0df0, field_0, 0x0);

// 0x7100ce0df0
void Unk_ce0df0_set(const Unk_ce0df0* self, Unk_ce0df0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ce0e00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ce0e00_arg1, field_0, 0x0);

struct Unk_ce0e00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ce0e00, field_0, 0x0);

// 0x7100ce0e00
void Unk_ce0e00_set(const Unk_ce0e00* self, Unk_ce0e00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ce1730 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ce1730, field_8, 0x8);

// 0x7100ce1730
void Unk_ce1730_call(Unk_ce1730* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_ce1770_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ce1770_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ce1770_arg1, field_8, 0x8);

struct Unk_ce1770 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ce1770, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ce1770, field_8, 0x8);

// 0x7100ce1770
void Unk_ce1770_call(const Unk_ce1770* self, Unk_ce1770_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ce17a0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_ce17a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ce17a0_arg1, field_8, 0x8);

struct Unk_ce17a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_ce17a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ce17a0, field_8, 0x8);

// 0x7100ce17a0
void Unk_ce17a0_set(Unk_ce17a0* self, Unk_ce17a0_arg1* value) {
    value->field_0 = self->field_0;
    u64 v0 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v0;
}

void Unk_ce1ba0();
void Unk_ce2020(void*);
void Unk_ce21b0(void*);
void Unk_ce23c0(void*);

// 0x7100ce1fe0
void Unk_ce1fe0_call(void* self) {
    Unk_ce1ba0();
    Unk_ce2020(self);
    Unk_ce21b0(self);
    Unk_ce23c0(self);
}
