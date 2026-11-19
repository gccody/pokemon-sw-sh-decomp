// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b1cf40 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1cf40, field_10, 0x10);

// 0x7100b1cf40
void Unk_b1cf40_call(Unk_b1cf40* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

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

struct Unk_b1d010 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d010, field_10, 0x10);

// 0x7100b1d010
void Unk_b1d010_call(Unk_b1d010* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
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

struct Unk_b1d140 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1d140, field_18, 0x18);

// 0x7100b1d140
void Unk_b1d140_call(Unk_b1d140* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
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

struct Unk_b1d210 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d210, field_10, 0x10);

// 0x7100b1d210
void Unk_b1d210_call(Unk_b1d210* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
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

struct Unk_b1d460 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1d460, field_10, 0x10);

// 0x7100b1d460
void Unk_b1d460_call(Unk_b1d460* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b1dc90_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b1dc90_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dc90_head, field_8, 0x8);

struct Unk_b1dc90_arg1 {
    Unk_b1dc90_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dc90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dc90_arg1, field_10, 0x10);

struct Unk_b1dc90 {
    Unk_b1dc90_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dc90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dc90, field_10, 0x10);

// 0x7100b1dc90
void Unk_b1dc90_call(const Unk_b1dc90* self, Unk_b1dc90_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b1dcc0_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b1dcc0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dcc0_head, field_8, 0x8);

struct Unk_b1dcc0_arg1 {
    Unk_b1dcc0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dcc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dcc0_arg1, field_10, 0x10);

struct Unk_b1dcc0 {
    Unk_b1dcc0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dcc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dcc0, field_10, 0x10);

// 0x7100b1dcc0
void Unk_b1dcc0_call(const Unk_b1dcc0* self, Unk_b1dcc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b1dd20 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dd20, field_10, 0x10);

// 0x7100b1dd20
void Unk_b1dd20_call(Unk_b1dd20* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
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

struct Unk_b1dfa0 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1dfa0, field_18, 0x18);

// 0x7100b1dfa0
void Unk_b1dfa0_call(Unk_b1dfa0* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
    }
}

struct Unk_b1dfe0_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1dfe0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dfe0_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1dfe0_head, field_10, 0x10);

struct Unk_b1dfe0_arg1 {
    Unk_b1dfe0_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1dfe0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dfe0_arg1, field_18, 0x18);

struct Unk_b1dfe0 {
    Unk_b1dfe0_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1dfe0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1dfe0, field_18, 0x18);

// 0x7100b1dfe0
void Unk_b1dfe0_call(const Unk_b1dfe0* self, Unk_b1dfe0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_18;
    value->field_18 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b1e010_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e010_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e010_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e010_head, field_10, 0x10);

struct Unk_b1e010_arg1 {
    Unk_b1e010_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e010_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e010_arg1, field_18, 0x18);

struct Unk_b1e010 {
    Unk_b1e010_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e010, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e010, field_18, 0x18);

// 0x7100b1e010
void Unk_b1e010_call(const Unk_b1e010* self, Unk_b1e010_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_18;
    value->field_18 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b1e070 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e070, field_10, 0x10);

// 0x7100b1e070
void Unk_b1e070_call(Unk_b1e070* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
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

struct Unk_b1e180 {
    u8 _0[0x20];
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b1e180, field_20, 0x20);

// 0x7100b1e180
void Unk_b1e180_call(Unk_b1e180* self) {
    if (self->field_20 != nullptr) {
        static_cast<Unk_239a458*>(self->field_20)->vf5();
        self->field_20 = nullptr;
    }
}

struct Unk_b1e1c0_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e1c0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e1c0_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e1c0_head, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1e1c0_head, field_18, 0x18);

struct Unk_b1e1c0_arg1 {
    Unk_b1e1c0_head field_0;
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b1e1c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e1c0_arg1, field_20, 0x20);

struct Unk_b1e1c0 {
    Unk_b1e1c0_head field_0;
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b1e1c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e1c0, field_20, 0x20);

// 0x7100b1e1c0
void Unk_b1e1c0_call(const Unk_b1e1c0* self, Unk_b1e1c0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_20;
    value->field_20 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b1e1f0_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e1f0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e1f0_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e1f0_head, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b1e1f0_head, field_18, 0x18);

struct Unk_b1e1f0_arg1 {
    Unk_b1e1f0_head field_0;
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b1e1f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e1f0_arg1, field_20, 0x20);

struct Unk_b1e1f0 {
    Unk_b1e1f0_head field_0;
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b1e1f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e1f0, field_20, 0x20);

// 0x7100b1e1f0
void Unk_b1e1f0_call(const Unk_b1e1f0* self, Unk_b1e1f0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_20;
    value->field_20 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b1e250 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e250, field_10, 0x10);

// 0x7100b1e250
void Unk_b1e250_call(Unk_b1e250* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
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

struct Unk_b1e3a0 {
    u8 _0[0x30];
    Unk_239a418* field_30;
};
PKMN_OFFSET_ASSERT(Unk_b1e3a0, field_30, 0x30);

// 0x7100b1e3a0
void Unk_b1e3a0_call(Unk_b1e3a0* self) {
    if (self->field_30 != nullptr) {
        static_cast<Unk_239a458*>(self->field_30)->vf5();
        self->field_30 = nullptr;
    }
}

struct Unk_b1e490 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e490, field_10, 0x10);

// 0x7100b1e490
void Unk_b1e490_call(Unk_b1e490* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
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

struct Unk_b1e570 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e570, field_18, 0x18);

// 0x7100b1e570
void Unk_b1e570_call(Unk_b1e570* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
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

struct Unk_b1e640 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e640, field_10, 0x10);

// 0x7100b1e640
void Unk_b1e640_call(Unk_b1e640* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
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

struct Unk_b1e7a0 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e7a0, field_18, 0x18);

// 0x7100b1e7a0
void Unk_b1e7a0_call(Unk_b1e7a0* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
    }
}

struct Unk_b1e7e0_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e7e0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e7e0_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e7e0_head, field_10, 0x10);

struct Unk_b1e7e0_arg1 {
    Unk_b1e7e0_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e7e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e7e0_arg1, field_18, 0x18);

struct Unk_b1e7e0 {
    Unk_b1e7e0_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e7e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e7e0, field_18, 0x18);

// 0x7100b1e7e0
void Unk_b1e7e0_call(const Unk_b1e7e0* self, Unk_b1e7e0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_18;
    value->field_18 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b1e810_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e810_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e810_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b1e810_head, field_10, 0x10);

struct Unk_b1e810_arg1 {
    Unk_b1e810_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e810_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e810_arg1, field_18, 0x18);

struct Unk_b1e810 {
    Unk_b1e810_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b1e810, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e810, field_18, 0x18);

// 0x7100b1e810
void Unk_b1e810_call(const Unk_b1e810* self, Unk_b1e810_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_18;
    value->field_18 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b1e8b0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e8b0, field_10, 0x10);

// 0x7100b1e8b0
void Unk_b1e8b0_call(Unk_b1e8b0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b1e8f0_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b1e8f0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e8f0_head, field_8, 0x8);

struct Unk_b1e8f0_arg1 {
    Unk_b1e8f0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e8f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e8f0_arg1, field_10, 0x10);

struct Unk_b1e8f0 {
    Unk_b1e8f0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e8f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e8f0, field_10, 0x10);

// 0x7100b1e8f0
void Unk_b1e8f0_call(const Unk_b1e8f0* self, Unk_b1e8f0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b1e920_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b1e920_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e920_head, field_8, 0x8);

struct Unk_b1e920_arg1 {
    Unk_b1e920_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e920_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e920_arg1, field_10, 0x10);

struct Unk_b1e920 {
    Unk_b1e920_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b1e920, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b1e920, field_10, 0x10);

// 0x7100b1e920
void Unk_b1e920_call(const Unk_b1e920* self, Unk_b1e920_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
