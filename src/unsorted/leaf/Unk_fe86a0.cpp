// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_fe86a0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe86a0, field_8, 0x8);

// 0x7100fe86a0
void Unk_fe86a0_call(Unk_fe86a0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_fe86e0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe86e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe86e0_arg1, field_8, 0x8);

struct Unk_fe86e0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe86e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe86e0, field_8, 0x8);

// 0x7100fe86e0
void Unk_fe86e0_call(const Unk_fe86e0* self, Unk_fe86e0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fe8710_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe8710_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe8710_arg1, field_8, 0x8);

struct Unk_fe8710 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe8710, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe8710, field_8, 0x8);

// 0x7100fe8710
void Unk_fe8710_call(const Unk_fe8710* self, Unk_fe8710_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fe8770 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe8770, field_8, 0x8);

// 0x7100fe8770
void Unk_fe8770_call(Unk_fe8770* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_fe87b0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe87b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe87b0_arg1, field_8, 0x8);

struct Unk_fe87b0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe87b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe87b0, field_8, 0x8);

// 0x7100fe87b0
void Unk_fe87b0_call(const Unk_fe87b0* self, Unk_fe87b0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fe87e0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe87e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe87e0_arg1, field_8, 0x8);

struct Unk_fe87e0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe87e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe87e0, field_8, 0x8);

// 0x7100fe87e0
void Unk_fe87e0_call(const Unk_fe87e0* self, Unk_fe87e0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x7100fe9600
void Unk_fe9600_update() {}

struct Unk_fe9610 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe9610, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe9610, field_8, 0x8);

// 0x7100fe9610
void Unk_fe9610_set(const Unk_fe9610* self, Unk_fe9610* value) {
    *value = *self;
}

struct Unk_fe9620 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_fe9620, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe9620, field_8, 0x8);

// 0x7100fe9620
void Unk_fe9620_set(const Unk_fe9620* self, Unk_fe9620* value) {
    *value = *self;
}

// 0x7100fe96b0
void Unk_fe96b0_update() {}

struct Unk_fe96c0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_fe96c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe96c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_fe96c0, field_10, 0x10);

// 0x7100fe96c0
void Unk_fe96c0_set(const Unk_fe96c0* self, Unk_fe96c0* value) {
    *value = *self;
}

struct Unk_fe96e0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_fe96e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe96e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_fe96e0, field_10, 0x10);

// 0x7100fe96e0
void Unk_fe96e0_set(const Unk_fe96e0* self, Unk_fe96e0* value) {
    *value = *self;
}

// 0x7100fe97e0
void Unk_fe97e0_update() {}

struct Unk_fe97f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_fe97f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe97f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_fe97f0, field_10, 0x10);

// 0x7100fe97f0
void Unk_fe97f0_set(const Unk_fe97f0* self, Unk_fe97f0* value) {
    *value = *self;
}

struct Unk_fe9810 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_fe9810, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fe9810, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_fe9810, field_10, 0x10);

// 0x7100fe9810
void Unk_fe9810_set(const Unk_fe9810* self, Unk_fe9810* value) {
    *value = *self;
}
