// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_1331d50 {
    u8 _0[0x1c0];
    u64 field_1c0;
};
PKMN_OFFSET_ASSERT(Unk_1331d50, field_1c0, 0x1c0);

// 0x7101331d50
u64 Unk_1331d50_getField1c0(const Unk_1331d50* self) {
    return self->field_1c0;
}

struct Unk_1331d60 {
    u8 _0[0x1e0];
    u64 field_1e0;
};
PKMN_OFFSET_ASSERT(Unk_1331d60, field_1e0, 0x1e0);

// 0x7101331d60
u64 Unk_1331d60_getField1e0(const Unk_1331d60* self) {
    return self->field_1e0;
}

struct Unk_1331d70 {
    u8 _0[0x200];
    u64 field_200;
};
PKMN_OFFSET_ASSERT(Unk_1331d70, field_200, 0x200);

// 0x7101331d70
u64 Unk_1331d70_getField200(const Unk_1331d70* self) {
    return self->field_200;
}

struct Unk_1331eb0 {
    u8 _0[0x260];
    u8 field_260;
};
PKMN_OFFSET_ASSERT(Unk_1331eb0, field_260, 0x260);

// 0x7101331eb0
u8* Unk_1331eb0_getField260Ptr(Unk_1331eb0* self) {
    return &self->field_260;
}

struct Unk_1334360_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1334360_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1334360_arg1, field_8, 0x8);

struct Unk_1334360 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1334360, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1334360, field_8, 0x8);

// 0x7101334360
void Unk_1334360_call(const Unk_1334360* self, Unk_1334360_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1334390_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1334390_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1334390_arg1, field_8, 0x8);

struct Unk_1334390 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1334390, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1334390, field_8, 0x8);

// 0x7101334390
void Unk_1334390_call(const Unk_1334390* self, Unk_1334390_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_13344a0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13344a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13344a0_arg1, field_8, 0x8);

struct Unk_13344a0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13344a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13344a0, field_8, 0x8);

// 0x71013344a0
void Unk_13344a0_call(const Unk_13344a0* self, Unk_13344a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_13344d0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13344d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13344d0_arg1, field_8, 0x8);

struct Unk_13344d0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13344d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13344d0, field_8, 0x8);

// 0x71013344d0
void Unk_13344d0_call(const Unk_13344d0* self, Unk_13344d0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x7101334660
void Unk_1334660_update() {}

struct Unk_1334670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334670_arg1, field_0, 0x0);

struct Unk_1334670 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334670, field_0, 0x0);

// 0x7101334670
void Unk_1334670_set(const Unk_1334670* self, Unk_1334670_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1334680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334680_arg1, field_0, 0x0);

struct Unk_1334680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334680, field_0, 0x0);

// 0x7101334680
void Unk_1334680_set(const Unk_1334680* self, Unk_1334680_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101334690
void Unk_1334690_update() {}

// 0x71013346a0
void Unk_13346a0_update() {}

// 0x71013346b0
void Unk_13346b0_update() {}

// 0x71013346c0
void Unk_13346c0_update() {}

// 0x71013347c0
void Unk_13347c0_update() {}

struct Unk_13347d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13347d0_arg1, field_0, 0x0);

struct Unk_13347d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13347d0, field_0, 0x0);

// 0x71013347d0
void Unk_13347d0_set(const Unk_13347d0* self, Unk_13347d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_13347e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13347e0_arg1, field_0, 0x0);

struct Unk_13347e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13347e0, field_0, 0x0);

// 0x71013347e0
void Unk_13347e0_set(const Unk_13347e0* self, Unk_13347e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71013347f0
void Unk_13347f0_update() {}

// 0x7101334800
void Unk_1334800_update() {}

// 0x7101334810
void Unk_1334810_update() {}

// 0x7101334820
void Unk_1334820_update() {}

// 0x7101334880
void Unk_1334880_update() {}

struct Unk_1334890_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334890_arg1, field_0, 0x0);

struct Unk_1334890 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334890, field_0, 0x0);

// 0x7101334890
void Unk_1334890_set(const Unk_1334890* self, Unk_1334890_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_13348a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13348a0_arg1, field_0, 0x0);

struct Unk_13348a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13348a0, field_0, 0x0);

// 0x71013348a0
void Unk_13348a0_set(const Unk_13348a0* self, Unk_13348a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71013348b0
void Unk_13348b0_update() {}

// 0x71013348c0
void Unk_13348c0_update() {}

// 0x71013348d0
void Unk_13348d0_update() {}

// 0x71013348e0
void Unk_13348e0_update() {}

// 0x7101334960
void Unk_1334960_update() {}

struct Unk_1334970_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334970_arg1, field_0, 0x0);

struct Unk_1334970 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334970, field_0, 0x0);

// 0x7101334970
void Unk_1334970_set(const Unk_1334970* self, Unk_1334970_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1334980_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334980_arg1, field_0, 0x0);

struct Unk_1334980 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1334980, field_0, 0x0);

// 0x7101334980
void Unk_1334980_set(const Unk_1334980* self, Unk_1334980_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101334990
void Unk_1334990_update() {}

// 0x71013349a0
void Unk_13349a0_update() {}

// 0x71013349b0
void Unk_13349b0_update() {}

// 0x71013349c0
void Unk_13349c0_update() {}

// 0x7101334a90
void Unk_1334a90_update() {}

struct Unk_1334aa0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1334aa0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1334aa0, field_8, 0x8);

// 0x7101334aa0
void Unk_1334aa0_set(const Unk_1334aa0* self, Unk_1334aa0* value) {
    *value = *self;
}

struct Unk_1334ab0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1334ab0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1334ab0, field_8, 0x8);

// 0x7101334ab0
void Unk_1334ab0_set(const Unk_1334ab0* self, Unk_1334ab0* value) {
    *value = *self;
}

// 0x7101334ac0
void Unk_1334ac0_update() {}

// 0x7101334ad0
void Unk_1334ad0_update() {}

// 0x7101334ae0
void Unk_1334ae0_update() {}

// 0x7101334af0
void Unk_1334af0_update() {}
