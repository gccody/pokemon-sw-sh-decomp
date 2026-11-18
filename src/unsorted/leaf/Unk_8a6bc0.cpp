// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_8a6bc0 {
    u8 _0[0x70];
    u32 field_70;
    u8 field_74;
};
PKMN_OFFSET_ASSERT(Unk_8a6bc0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_8a6bc0, field_74, 0x74);

// 0x71008a6bc0
bool Unk_8a6bc0_check(const Unk_8a6bc0* self) {
    if (self->field_74 == 0) {
        return false;
    }
    return self->field_70 != 8;
}

struct Unk_8a6d00 {
    u8 _0[0x75];
    u8 field_75;
};
PKMN_OFFSET_ASSERT(Unk_8a6d00, field_75, 0x75);

// 0x71008a6d00
void Unk_8a6d00_set(Unk_8a6d00* self) {
    self->field_75 = 1;
}

struct Unk_8a7710_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7710_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8a7710_arg1, field_8, 0x8);

struct Unk_8a7710 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7710, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8a7710, field_8, 0x8);

// 0x71008a7710
void Unk_8a7710_call(const Unk_8a7710* self, Unk_8a7710_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_8a7740_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7740_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8a7740_arg1, field_8, 0x8);

struct Unk_8a7740 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7740, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8a7740, field_8, 0x8);

// 0x71008a7740
void Unk_8a7740_call(const Unk_8a7740* self, Unk_8a7740_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_8a7830_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7830_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8a7830_arg1, field_8, 0x8);

struct Unk_8a7830 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7830, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8a7830, field_8, 0x8);

// 0x71008a7830
void Unk_8a7830_call(const Unk_8a7830* self, Unk_8a7830_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_8a7860_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7860_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8a7860_arg1, field_8, 0x8);

struct Unk_8a7860 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7860, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8a7860, field_8, 0x8);

// 0x71008a7860
void Unk_8a7860_call(const Unk_8a7860* self, Unk_8a7860_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
