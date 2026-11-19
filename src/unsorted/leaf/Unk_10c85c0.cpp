// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10c85c0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10c85c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10c85c0_arg1, field_8, 0x8);

struct Unk_10c85c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10c85c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10c85c0, field_8, 0x8);

// 0x71010c85c0
void Unk_10c85c0_set(Unk_10c85c0* self, Unk_10c85c0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10c86d0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10c86d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10c86d0_arg1, field_8, 0x8);

struct Unk_10c86d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10c86d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10c86d0, field_8, 0x8);

// 0x71010c86d0
void Unk_10c86d0_set(Unk_10c86d0* self, Unk_10c86d0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10c8750 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c8750, field_0, 0x0);

// 0x71010c8750
void Unk_10c8750_call(Unk_10c8750* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10c8790_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c8790_arg1, field_0, 0x0);

struct Unk_10c8790 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c8790, field_0, 0x0);

// 0x71010c8790
void Unk_10c8790_call(const Unk_10c8790* self, Unk_10c8790_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10c87b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c87b0_arg1, field_0, 0x0);

struct Unk_10c87b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c87b0, field_0, 0x0);

// 0x71010c87b0
void Unk_10c87b0_set(Unk_10c87b0* self, Unk_10c87b0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10ca080_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10ca080_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10ca080_arg1, field_8, 0x8);

struct Unk_10ca080 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10ca080, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10ca080, field_8, 0x8);

// 0x71010ca080
void Unk_10ca080_set(Unk_10ca080* self, Unk_10ca080_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10ca0b0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca0b0, field_0, 0x0);

// 0x71010ca0b0
void Unk_10ca0b0_call(Unk_10ca0b0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10ca0f0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca0f0_arg1, field_0, 0x0);

struct Unk_10ca0f0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca0f0, field_0, 0x0);

// 0x71010ca0f0
void Unk_10ca0f0_call(const Unk_10ca0f0* self, Unk_10ca0f0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10ca110_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca110_arg1, field_0, 0x0);

struct Unk_10ca110 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca110, field_0, 0x0);

// 0x71010ca110
void Unk_10ca110_set(Unk_10ca110* self, Unk_10ca110_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10ca180 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca180, field_0, 0x0);

// 0x71010ca180
void Unk_10ca180_call(Unk_10ca180* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10ca1c0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca1c0_arg1, field_0, 0x0);

struct Unk_10ca1c0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca1c0, field_0, 0x0);

// 0x71010ca1c0
void Unk_10ca1c0_call(const Unk_10ca1c0* self, Unk_10ca1c0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10ca1e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca1e0_arg1, field_0, 0x0);

struct Unk_10ca1e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ca1e0, field_0, 0x0);

// 0x71010ca1e0
void Unk_10ca1e0_set(Unk_10ca1e0* self, Unk_10ca1e0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}
