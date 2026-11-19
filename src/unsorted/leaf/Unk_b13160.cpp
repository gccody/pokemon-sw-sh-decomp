// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b13160 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b13160, field_18, 0x18);

// 0x7100b13160
void Unk_b13160_call(Unk_b13160* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
    }
}

struct Unk_b131a0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b131a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b131a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b131a0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b131a0_arg1, field_18, 0x18);

struct Unk_b131a0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b131a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b131a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b131a0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b131a0, field_18, 0x18);

// 0x7100b131a0
void Unk_b131a0_call(const Unk_b131a0* self, Unk_b131a0_arg1* value) {
    u64 v0 = self->field_0;
    u64 v1 = self->field_8;
    value->field_10 = self->field_10;
    value->field_0 = v0;
    value->field_8 = v1;
    Unk_239a418* v2 = self->field_18;
    value->field_18 = v2;
    if (v2 != nullptr) {
        static_cast<Unk_239a458*>(v2)->vf4();
    }
}

struct Unk_b131d0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b131d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b131d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b131d0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b131d0_arg1, field_18, 0x18);

struct Unk_b131d0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b131d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b131d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b131d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b131d0, field_18, 0x18);

// 0x7100b131d0
void Unk_b131d0_call(const Unk_b131d0* self, Unk_b131d0_arg1* value) {
    u64 v0 = self->field_0;
    u64 v1 = self->field_8;
    value->field_10 = self->field_10;
    value->field_0 = v0;
    value->field_8 = v1;
    Unk_239a418* v2 = self->field_18;
    value->field_18 = v2;
    if (v2 != nullptr) {
        static_cast<Unk_239a458*>(v2)->vf4();
    }
}

struct Unk_b13240 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13240, field_10, 0x10);

// 0x7100b13240
void Unk_b13240_call(Unk_b13240* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b13420 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13420, field_10, 0x10);

// 0x7100b13420
void Unk_b13420_call(Unk_b13420* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b134f0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b134f0, field_10, 0x10);

// 0x7100b134f0
void Unk_b134f0_call(Unk_b134f0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b13530_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13530_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13530_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13530_arg1, field_10, 0x10);

struct Unk_b13530 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13530, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13530, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13530, field_10, 0x10);

// 0x7100b13530
void Unk_b13530_call(const Unk_b13530* self, Unk_b13530_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b13560_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13560_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13560_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13560_arg1, field_10, 0x10);

struct Unk_b13560 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13560, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13560, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13560, field_10, 0x10);

// 0x7100b13560
void Unk_b13560_call(const Unk_b13560* self, Unk_b13560_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b13820 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b13820, field_18, 0x18);

// 0x7100b13820
void Unk_b13820_call(Unk_b13820* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
    }
}

struct Unk_b13a90_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b13a90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13a90_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13a90_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b13a90_arg1, field_18, 0x18);

struct Unk_b13a90 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b13a90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13a90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13a90, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b13a90, field_18, 0x18);

// 0x7100b13a90
void Unk_b13a90_call(const Unk_b13a90* self, Unk_b13a90_arg1* value) {
    u64 v0 = self->field_0;
    u64 v1 = self->field_8;
    value->field_10 = self->field_10;
    value->field_0 = v0;
    value->field_8 = v1;
    Unk_239a418* v2 = self->field_18;
    value->field_18 = v2;
    if (v2 != nullptr) {
        static_cast<Unk_239a458*>(v2)->vf4();
    }
}

struct Unk_b13ac0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b13ac0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13ac0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13ac0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b13ac0_arg1, field_18, 0x18);

struct Unk_b13ac0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b13ac0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13ac0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13ac0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b13ac0, field_18, 0x18);

// 0x7100b13ac0
void Unk_b13ac0_call(const Unk_b13ac0* self, Unk_b13ac0_arg1* value) {
    u64 v0 = self->field_0;
    u64 v1 = self->field_8;
    value->field_10 = self->field_10;
    value->field_0 = v0;
    value->field_8 = v1;
    Unk_239a418* v2 = self->field_18;
    value->field_18 = v2;
    if (v2 != nullptr) {
        static_cast<Unk_239a458*>(v2)->vf4();
    }
}

struct Unk_b13b20 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13b20, field_10, 0x10);

// 0x7100b13b20
void Unk_b13b20_call(Unk_b13b20* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b13b60_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13b60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13b60_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13b60_arg1, field_10, 0x10);

struct Unk_b13b60 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13b60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13b60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13b60, field_10, 0x10);

// 0x7100b13b60
void Unk_b13b60_call(const Unk_b13b60* self, Unk_b13b60_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b13b90_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13b90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13b90_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13b90_arg1, field_10, 0x10);

struct Unk_b13b90 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b13b90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b13b90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b13b90, field_10, 0x10);

// 0x7100b13b90
void Unk_b13b90_call(const Unk_b13b90* self, Unk_b13b90_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}
