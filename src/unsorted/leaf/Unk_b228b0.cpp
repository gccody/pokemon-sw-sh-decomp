// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b228b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b228b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b228b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b228b0_arg1, field_10, 0x10);

struct Unk_b228b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b228b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b228b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b228b0, field_10, 0x10);

// 0x7100b228b0
void Unk_b228b0_call(const Unk_b228b0* self, Unk_b228b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b228e0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b228e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b228e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b228e0_arg1, field_10, 0x10);

struct Unk_b228e0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b228e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b228e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b228e0, field_10, 0x10);

// 0x7100b228e0
void Unk_b228e0_call(const Unk_b228e0* self, Unk_b228e0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b22a80_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22a80_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22a80_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22a80_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22a80_arg1, field_18, 0x18);

struct Unk_b22a80 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22a80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22a80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22a80, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22a80, field_18, 0x18);

// 0x7100b22a80
void Unk_b22a80_call(const Unk_b22a80* self, Unk_b22a80_arg1* value) {
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

struct Unk_b22ab0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22ab0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22ab0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22ab0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22ab0_arg1, field_18, 0x18);

struct Unk_b22ab0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22ab0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22ab0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22ab0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22ab0, field_18, 0x18);

// 0x7100b22ab0
void Unk_b22ab0_call(const Unk_b22ab0* self, Unk_b22ab0_arg1* value) {
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

struct Unk_b22c40_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22c40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22c40_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22c40_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22c40_arg1, field_18, 0x18);

struct Unk_b22c40 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22c40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22c40, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22c40, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22c40, field_18, 0x18);

// 0x7100b22c40
void Unk_b22c40_call(const Unk_b22c40* self, Unk_b22c40_arg1* value) {
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

struct Unk_b22c70_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22c70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22c70_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22c70_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22c70_arg1, field_18, 0x18);

struct Unk_b22c70 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22c70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22c70, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22c70, field_18, 0x18);

// 0x7100b22c70
void Unk_b22c70_call(const Unk_b22c70* self, Unk_b22c70_arg1* value) {
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

struct Unk_b22da0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22da0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22da0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22da0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22da0_arg1, field_18, 0x18);

struct Unk_b22da0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22da0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22da0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22da0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22da0, field_18, 0x18);

// 0x7100b22da0
void Unk_b22da0_call(const Unk_b22da0* self, Unk_b22da0_arg1* value) {
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

struct Unk_b22dd0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22dd0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22dd0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22dd0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22dd0_arg1, field_18, 0x18);

struct Unk_b22dd0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b22dd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b22dd0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b22dd0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b22dd0, field_18, 0x18);

// 0x7100b22dd0
void Unk_b22dd0_call(const Unk_b22dd0* self, Unk_b22dd0_arg1* value) {
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

struct Unk_b23030_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23030_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23030_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23030_arg1, field_10, 0x10);

struct Unk_b23030 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23030, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23030, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23030, field_10, 0x10);

// 0x7100b23030
void Unk_b23030_call(const Unk_b23030* self, Unk_b23030_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b23060_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23060_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23060_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23060_arg1, field_10, 0x10);

struct Unk_b23060 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23060, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23060, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23060, field_10, 0x10);

// 0x7100b23060
void Unk_b23060_call(const Unk_b23060* self, Unk_b23060_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b23100_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23100_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23100_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23100_arg1, field_10, 0x10);

struct Unk_b23100 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23100, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23100, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23100, field_10, 0x10);

// 0x7100b23100
void Unk_b23100_call(const Unk_b23100* self, Unk_b23100_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b23130_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23130_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23130_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23130_arg1, field_10, 0x10);

struct Unk_b23130 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23130, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23130, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23130, field_10, 0x10);

// 0x7100b23130
void Unk_b23130_call(const Unk_b23130* self, Unk_b23130_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b232c0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b232c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b232c0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b232c0_arg1, field_10, 0x10);

struct Unk_b232c0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b232c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b232c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b232c0, field_10, 0x10);

// 0x7100b232c0
void Unk_b232c0_call(const Unk_b232c0* self, Unk_b232c0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b232f0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b232f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b232f0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b232f0_arg1, field_10, 0x10);

struct Unk_b232f0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b232f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b232f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b232f0, field_10, 0x10);

// 0x7100b232f0
void Unk_b232f0_call(const Unk_b232f0* self, Unk_b232f0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b23390_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23390_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23390_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23390_arg1, field_10, 0x10);

struct Unk_b23390 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b23390, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b23390, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b23390, field_10, 0x10);

// 0x7100b23390
void Unk_b23390_call(const Unk_b23390* self, Unk_b23390_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b233c0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b233c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b233c0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b233c0_arg1, field_10, 0x10);

struct Unk_b233c0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b233c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b233c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b233c0, field_10, 0x10);

// 0x7100b233c0
void Unk_b233c0_call(const Unk_b233c0* self, Unk_b233c0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}
