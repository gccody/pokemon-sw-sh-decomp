// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_f5ca40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5ca40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5ca40_arg1, field_8, 0x8);

struct Unk_f5ca40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5ca40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5ca40, field_8, 0x8);

// 0x7100f5ca40
void Unk_f5ca40_call(const Unk_f5ca40* self, Unk_f5ca40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f5ca70_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5ca70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5ca70_arg1, field_8, 0x8);

struct Unk_f5ca70 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5ca70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5ca70, field_8, 0x8);

// 0x7100f5ca70
void Unk_f5ca70_call(const Unk_f5ca70* self, Unk_f5ca70_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f5cb10_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5cb10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5cb10_arg1, field_8, 0x8);

struct Unk_f5cb10 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5cb10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5cb10, field_8, 0x8);

// 0x7100f5cb10
void Unk_f5cb10_call(const Unk_f5cb10* self, Unk_f5cb10_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f5cb40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5cb40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5cb40_arg1, field_8, 0x8);

struct Unk_f5cb40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5cb40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5cb40, field_8, 0x8);

// 0x7100f5cb40
void Unk_f5cb40_call(const Unk_f5cb40* self, Unk_f5cb40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
