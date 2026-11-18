// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_132cb10 {
    u8 _0[0x20];
    u64 field_20;
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_132cb10, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_132cb10, field_28, 0x28);

// 0x710132cb10
void Unk_132cb10_set(Unk_132cb10* self, u64 value, u64 arg2) {
    self->field_20 = value;
    self->field_28 = arg2;
}

struct Unk_132cca0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_132cca0, field_28, 0x28);

void Unk_eb8a30(u64, u32);

// 0x710132cca0
void Unk_132cca0_call(const Unk_132cca0* self) {
    Unk_eb8a30(self->field_28, 1);
}

struct Unk_132e400_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e400_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e400_arg1, field_8, 0x8);

struct Unk_132e400 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e400, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e400, field_8, 0x8);

// 0x710132e400
void Unk_132e400_call(const Unk_132e400* self, Unk_132e400_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_132e430_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e430_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e430_arg1, field_8, 0x8);

struct Unk_132e430 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e430, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e430, field_8, 0x8);

// 0x710132e430
void Unk_132e430_call(const Unk_132e430* self, Unk_132e430_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_132e500_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e500_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e500_arg1, field_8, 0x8);

struct Unk_132e500 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e500, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e500, field_8, 0x8);

// 0x710132e500
void Unk_132e500_call(const Unk_132e500* self, Unk_132e500_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_132e530_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e530_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e530_arg1, field_8, 0x8);

struct Unk_132e530 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e530, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e530, field_8, 0x8);

// 0x710132e530
void Unk_132e530_call(const Unk_132e530* self, Unk_132e530_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x710132e5d0
void Unk_132e5d0_update() {}

struct Unk_132e5e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_132e5e0_arg1, field_0, 0x0);

struct Unk_132e5e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_132e5e0, field_0, 0x0);

// 0x710132e5e0
void Unk_132e5e0_set(const Unk_132e5e0* self, Unk_132e5e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_132e5f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_132e5f0_arg1, field_0, 0x0);

struct Unk_132e5f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_132e5f0, field_0, 0x0);

// 0x710132e5f0
void Unk_132e5f0_set(const Unk_132e5f0* self, Unk_132e5f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710132e600
void Unk_132e600_update() {}

// 0x710132e610
void Unk_132e610_update() {}

// 0x710132e620
void Unk_132e620_update() {}

// 0x710132e630
void Unk_132e630_update() {}

struct Unk_132e850_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e850_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e850_arg1, field_8, 0x8);

struct Unk_132e850 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e850, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e850, field_8, 0x8);

// 0x710132e850
void Unk_132e850_call(const Unk_132e850* self, Unk_132e850_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_132e880_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e880_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e880_arg1, field_8, 0x8);

struct Unk_132e880 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_132e880, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132e880, field_8, 0x8);

// 0x710132e880
void Unk_132e880_call(const Unk_132e880* self, Unk_132e880_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_132e8b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_132e8b0, field_0, 0x0);

void Unk_132dfc0(u64, u32);

// 0x710132e8b0
void Unk_132e8b0_call(const Unk_132e8b0* self) {
    Unk_132dfc0(self->field_0, 0);
}

// 0x710132e8c0
void Unk_132e8c0_update() {}

struct Unk_132e8d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_132e8d0_arg1, field_0, 0x0);

struct Unk_132e8d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_132e8d0, field_0, 0x0);

// 0x710132e8d0
void Unk_132e8d0_set(const Unk_132e8d0* self, Unk_132e8d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_132e8e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_132e8e0_arg1, field_0, 0x0);

struct Unk_132e8e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_132e8e0, field_0, 0x0);

// 0x710132e8e0
void Unk_132e8e0_set(const Unk_132e8e0* self, Unk_132e8e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710132e8f0
void Unk_132e8f0_update() {}

// 0x710132e900
void Unk_132e900_update() {}

// 0x710132e910
void Unk_132e910_update() {}

// 0x710132e920
void Unk_132e920_update() {}
