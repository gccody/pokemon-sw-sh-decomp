// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_1330130 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_1330130, field_10, 0x10);

// 0x7101330130
void Unk_1330130_call(Unk_1330130* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_1330170_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_1330170_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1330170_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1330170_arg1, field_10, 0x10);

struct Unk_1330170 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_1330170, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1330170, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1330170, field_10, 0x10);

// 0x7101330170
void Unk_1330170_call(const Unk_1330170* self, Unk_1330170_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_13301a0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_13301a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13301a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13301a0_arg1, field_10, 0x10);

struct Unk_13301a0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_13301a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13301a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13301a0, field_10, 0x10);

// 0x71013301a0
void Unk_13301a0_call(const Unk_13301a0* self, Unk_13301a0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_1330240 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1330240, field_8, 0x8);

// 0x7101330240
void Unk_1330240_call(Unk_1330240* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_1330280_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1330280_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1330280_arg1, field_8, 0x8);

struct Unk_1330280 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1330280, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1330280, field_8, 0x8);

// 0x7101330280
void Unk_1330280_call(const Unk_1330280* self, Unk_1330280_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_13302b0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13302b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13302b0_arg1, field_8, 0x8);

struct Unk_13302b0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13302b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13302b0, field_8, 0x8);

// 0x71013302b0
void Unk_13302b0_call(const Unk_13302b0* self, Unk_13302b0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x7101330300
void Unk_1330300_update() {}

struct Unk_1330310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330310_arg1, field_0, 0x0);

struct Unk_1330310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330310, field_0, 0x0);

// 0x7101330310
void Unk_1330310_set(const Unk_1330310* self, Unk_1330310_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1330320_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330320_arg1, field_0, 0x0);

struct Unk_1330320 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330320, field_0, 0x0);

// 0x7101330320
void Unk_1330320_set(const Unk_1330320* self, Unk_1330320_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101330330
void Unk_1330330_update() {}

// 0x7101330340
void Unk_1330340_update() {}

// 0x7101330350
void Unk_1330350_update() {}

// 0x7101330360
void Unk_1330360_update() {}

// 0x71013303c0
void Unk_13303c0_update() {}

struct Unk_13303d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13303d0_arg1, field_0, 0x0);

struct Unk_13303d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13303d0, field_0, 0x0);

// 0x71013303d0
void Unk_13303d0_set(const Unk_13303d0* self, Unk_13303d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_13303e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13303e0_arg1, field_0, 0x0);

struct Unk_13303e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13303e0, field_0, 0x0);

// 0x71013303e0
void Unk_13303e0_set(const Unk_13303e0* self, Unk_13303e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71013303f0
void Unk_13303f0_update() {}

// 0x7101330400
void Unk_1330400_update() {}

// 0x7101330410
void Unk_1330410_update() {}

// 0x7101330420
void Unk_1330420_update() {}

struct Unk_1330430 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330430, field_0, 0x0);

void Unk_132fcc0(u64, u32);

// 0x7101330430
void Unk_1330430_call(const Unk_1330430* self) {
    Unk_132fcc0(self->field_0, 0);
}

// 0x7101330440
void Unk_1330440_update() {}

struct Unk_1330450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330450_arg1, field_0, 0x0);

struct Unk_1330450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330450, field_0, 0x0);

// 0x7101330450
void Unk_1330450_set(const Unk_1330450* self, Unk_1330450_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1330460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330460_arg1, field_0, 0x0);

struct Unk_1330460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330460, field_0, 0x0);

// 0x7101330460
void Unk_1330460_set(const Unk_1330460* self, Unk_1330460_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101330470
void Unk_1330470_update() {}

// 0x7101330480
void Unk_1330480_update() {}

// 0x7101330490
void Unk_1330490_update() {}

// 0x71013304a0
void Unk_13304a0_update() {}

// 0x7101330520
void Unk_1330520_update() {}

struct Unk_1330530_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330530_arg1, field_0, 0x0);

struct Unk_1330530 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330530, field_0, 0x0);

// 0x7101330530
void Unk_1330530_set(const Unk_1330530* self, Unk_1330530_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1330540_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330540_arg1, field_0, 0x0);

struct Unk_1330540 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330540, field_0, 0x0);

// 0x7101330540
void Unk_1330540_set(const Unk_1330540* self, Unk_1330540_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101330550
void Unk_1330550_update() {}

// 0x7101330560
void Unk_1330560_update() {}

// 0x7101330570
void Unk_1330570_update() {}

// 0x7101330580
void Unk_1330580_update() {}

// 0x7101330600
void Unk_1330600_update() {}

struct Unk_1330610_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330610_arg1, field_0, 0x0);

struct Unk_1330610 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330610, field_0, 0x0);

// 0x7101330610
void Unk_1330610_set(const Unk_1330610* self, Unk_1330610_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1330620_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330620_arg1, field_0, 0x0);

struct Unk_1330620 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1330620, field_0, 0x0);

// 0x7101330620
void Unk_1330620_set(const Unk_1330620* self, Unk_1330620_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101330630
void Unk_1330630_update() {}

// 0x7101330640
void Unk_1330640_update() {}

// 0x7101330650
void Unk_1330650_update() {}

// 0x7101330660
void Unk_1330660_update() {}
