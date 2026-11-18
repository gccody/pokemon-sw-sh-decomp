// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b1cf80_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1cf80_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1cf80_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1cf80_arg1, field_10, 0x10);

struct Unk_b1cf80 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1cf80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1cf80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1cf80, field_10, 0x10);

// 0x7100b1cf80
void Unk_b1cf80_call(const Unk_b1cf80* self, Unk_b1cf80_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1cfb0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1cfb0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1cfb0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1cfb0_arg1, field_10, 0x10);

struct Unk_b1cfb0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1cfb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1cfb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1cfb0, field_10, 0x10);

// 0x7100b1cfb0
void Unk_b1cfb0_call(const Unk_b1cfb0* self, Unk_b1cfb0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1d050_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d050_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d050_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d050_arg1, field_10, 0x10);

struct Unk_b1d050 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d050, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d050, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d050, field_10, 0x10);

// 0x7100b1d050
void Unk_b1d050_call(const Unk_b1d050* self, Unk_b1d050_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1d080_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d080_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d080_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d080_arg1, field_10, 0x10);

struct Unk_b1d080 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d080, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d080, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d080, field_10, 0x10);

// 0x7100b1d080
void Unk_b1d080_call(const Unk_b1d080* self, Unk_b1d080_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1d180_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1d180_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d180_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d180_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1d180_arg1, field_18, 0x18);

struct Unk_b1d180 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1d180, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d180, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d180, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1d180, field_18, 0x18);

// 0x7100b1d180
void Unk_b1d180_call(const Unk_b1d180* self, Unk_b1d180_arg1* value) {
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

struct Unk_b1d1b0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1d1b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d1b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d1b0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1d1b0_arg1, field_18, 0x18);

struct Unk_b1d1b0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1d1b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d1b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d1b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1d1b0, field_18, 0x18);

// 0x7100b1d1b0
void Unk_b1d1b0_call(const Unk_b1d1b0* self, Unk_b1d1b0_arg1* value) {
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

struct Unk_b1d250_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d250_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d250_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d250_arg1, field_10, 0x10);

struct Unk_b1d250 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d250, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d250, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d250, field_10, 0x10);

// 0x7100b1d250
void Unk_b1d250_call(const Unk_b1d250* self, Unk_b1d250_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1d280_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d280_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d280_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d280_arg1, field_10, 0x10);

struct Unk_b1d280 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d280, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1d280, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1d280, field_10, 0x10);

// 0x7100b1d280
void Unk_b1d280_call(const Unk_b1d280* self, Unk_b1d280_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1dd60_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dd60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dd60_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1dd60_arg1, field_10, 0x10);

struct Unk_b1dd60 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dd60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dd60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1dd60, field_10, 0x10);

// 0x7100b1dd60
void Unk_b1dd60_call(const Unk_b1dd60* self, Unk_b1dd60_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1dd90_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dd90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dd90_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1dd90_arg1, field_10, 0x10);

struct Unk_b1dd90 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dd90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dd90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1dd90, field_10, 0x10);

// 0x7100b1dd90
void Unk_b1dd90_call(const Unk_b1dd90* self, Unk_b1dd90_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1e0b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e0b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e0b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e0b0_arg1, field_10, 0x10);

struct Unk_b1e0b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e0b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e0b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e0b0, field_10, 0x10);

// 0x7100b1e0b0
void Unk_b1e0b0_call(const Unk_b1e0b0* self, Unk_b1e0b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1e0e0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e0e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e0e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e0e0_arg1, field_10, 0x10);

struct Unk_b1e0e0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e0e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e0e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e0e0, field_10, 0x10);

// 0x7100b1e0e0
void Unk_b1e0e0_call(const Unk_b1e0e0* self, Unk_b1e0e0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1e290_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e290_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e290_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e290_arg1, field_10, 0x10);

struct Unk_b1e290 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e290, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e290, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e290, field_10, 0x10);

// 0x7100b1e290
void Unk_b1e290_call(const Unk_b1e290* self, Unk_b1e290_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1e2c0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e2c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e2c0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e2c0_arg1, field_10, 0x10);

struct Unk_b1e2c0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e2c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e2c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e2c0, field_10, 0x10);

// 0x7100b1e2c0
void Unk_b1e2c0_call(const Unk_b1e2c0* self, Unk_b1e2c0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1e4d0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e4d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e4d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e4d0_arg1, field_10, 0x10);

struct Unk_b1e4d0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e4d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e4d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e4d0, field_10, 0x10);

// 0x7100b1e4d0
void Unk_b1e4d0_call(const Unk_b1e4d0* self, Unk_b1e4d0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1e500_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e500_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e500_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e500_arg1, field_10, 0x10);

struct Unk_b1e500 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e500, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e500, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e500, field_10, 0x10);

// 0x7100b1e500
void Unk_b1e500_call(const Unk_b1e500* self, Unk_b1e500_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1e5b0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e5b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e5b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e5b0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1e5b0_arg1, field_18, 0x18);

struct Unk_b1e5b0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e5b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e5b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e5b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1e5b0, field_18, 0x18);

// 0x7100b1e5b0
void Unk_b1e5b0_call(const Unk_b1e5b0* self, Unk_b1e5b0_arg1* value) {
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

struct Unk_b1e5e0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e5e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e5e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e5e0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1e5e0_arg1, field_18, 0x18);

struct Unk_b1e5e0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e5e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e5e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e5e0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1e5e0, field_18, 0x18);

// 0x7100b1e5e0
void Unk_b1e5e0_call(const Unk_b1e5e0* self, Unk_b1e5e0_arg1* value) {
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

struct Unk_b1e680_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e680_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e680_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e680_arg1, field_10, 0x10);

struct Unk_b1e680 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e680, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e680, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e680, field_10, 0x10);

// 0x7100b1e680
void Unk_b1e680_call(const Unk_b1e680* self, Unk_b1e680_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b1e6b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e6b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e6b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e6b0_arg1, field_10, 0x10);

struct Unk_b1e6b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e6b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e6b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e6b0, field_10, 0x10);

// 0x7100b1e6b0
void Unk_b1e6b0_call(const Unk_b1e6b0* self, Unk_b1e6b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}
