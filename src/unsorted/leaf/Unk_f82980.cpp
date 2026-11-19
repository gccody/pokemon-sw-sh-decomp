// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_f82980_0 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_f82980_0, field_80, 0x80);

struct Unk_f82980 {
    Unk_f82980_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f82980, field_0, 0x0);

// 0x7100f82980
void Unk_f82980_set(const Unk_f82980* self) {
    self->field_0->field_80 = 3;
}

// 0x7100f82990
void Unk_f82990_update() {}

struct Unk_f829a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f829a0_arg1, field_0, 0x0);

struct Unk_f829a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f829a0, field_0, 0x0);

// 0x7100f829a0
void Unk_f829a0_set(const Unk_f829a0* self, Unk_f829a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f829b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f829b0_arg1, field_0, 0x0);

struct Unk_f829b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f829b0, field_0, 0x0);

// 0x7100f829b0
void Unk_f829b0_set(const Unk_f829b0* self, Unk_f829b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f82ae0
void Unk_f82ae0_update() {}

struct Unk_f82af0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f82af0_arg1, field_0, 0x0);

struct Unk_f82af0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f82af0, field_0, 0x0);

// 0x7100f82af0
void Unk_f82af0_set(const Unk_f82af0* self, Unk_f82af0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f82b00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f82b00_arg1, field_0, 0x0);

struct Unk_f82b00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f82b00, field_0, 0x0);

// 0x7100f82b00
void Unk_f82b00_set(const Unk_f82b00* self, Unk_f82b00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f858b0 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f858b0, field_0, 0x0);

void Unk_f7dbe0(void*, u32);

// 0x7100f858b0
void Unk_f858b0_call(const Unk_f858b0* self) {
    Unk_f7dbe0(self->field_0, 0);
}

// 0x7100f858c0
void Unk_f858c0_update() {}

struct Unk_f858d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f858d0_arg1, field_0, 0x0);

struct Unk_f858d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f858d0, field_0, 0x0);

// 0x7100f858d0
void Unk_f858d0_set(const Unk_f858d0* self, Unk_f858d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f858e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f858e0_arg1, field_0, 0x0);

struct Unk_f858e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f858e0, field_0, 0x0);

// 0x7100f858e0
void Unk_f858e0_set(const Unk_f858e0* self, Unk_f858e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f85920
void Unk_f85920_update() {}

struct Unk_f85930_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85930_arg1, field_0, 0x0);

struct Unk_f85930 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85930, field_0, 0x0);

// 0x7100f85930
void Unk_f85930_set(const Unk_f85930* self, Unk_f85930_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f85940_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85940_arg1, field_0, 0x0);

struct Unk_f85940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85940, field_0, 0x0);

// 0x7100f85940
void Unk_f85940_set(const Unk_f85940* self, Unk_f85940_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f85950_0 {
    u8 _0[0x2a8];
    u8 field_2a8;
    u8 _2a9[0x3];
    u32 field_2ac;
};
PKMN_OFFSET_ASSERT(Unk_f85950_0, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(Unk_f85950_0, field_2ac, 0x2ac);

struct Unk_f85950 {
    Unk_f85950_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85950, field_0, 0x0);

// 0x7100f85950
void Unk_f85950_set(const Unk_f85950* self) {
    Unk_f85950_0* p0 = self->field_0;
    p0->field_2ac = 2;
    p0->field_2a8 = 1;
}

// 0x7100f85970
void Unk_f85970_update() {}

struct Unk_f85980_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85980_arg1, field_0, 0x0);

struct Unk_f85980 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85980, field_0, 0x0);

// 0x7100f85980
void Unk_f85980_set(const Unk_f85980* self, Unk_f85980_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f85990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85990_arg1, field_0, 0x0);

struct Unk_f85990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85990, field_0, 0x0);

// 0x7100f85990
void Unk_f85990_set(const Unk_f85990* self, Unk_f85990_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f859a0 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f859a0, field_0, 0x0);

void Unk_f7d670(void*, u32);

// 0x7100f859a0
void Unk_f859a0_call(const Unk_f859a0* self) {
    Unk_f7d670(self->field_0, 3);
}

// 0x7100f859b0
void Unk_f859b0_update() {}

struct Unk_f859c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f859c0_arg1, field_0, 0x0);

struct Unk_f859c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f859c0, field_0, 0x0);

// 0x7100f859c0
void Unk_f859c0_set(const Unk_f859c0* self, Unk_f859c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f859d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f859d0_arg1, field_0, 0x0);

struct Unk_f859d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f859d0, field_0, 0x0);

// 0x7100f859d0
void Unk_f859d0_set(const Unk_f859d0* self, Unk_f859d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f85a40
void Unk_f85a40_update() {}

struct Unk_f85a50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85a50_arg1, field_0, 0x0);

struct Unk_f85a50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85a50, field_0, 0x0);

// 0x7100f85a50
void Unk_f85a50_set(const Unk_f85a50* self, Unk_f85a50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f85a60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85a60_arg1, field_0, 0x0);

struct Unk_f85a60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85a60, field_0, 0x0);

// 0x7100f85a60
void Unk_f85a60_set(const Unk_f85a60* self, Unk_f85a60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f85a70 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85a70, field_0, 0x0);

void Unk_f7dbe0(void*, u32);

// 0x7100f85a70
void Unk_f85a70_call(const Unk_f85a70* self) {
    Unk_f7dbe0(self->field_0, 0);
}

// 0x7100f85a80
void Unk_f85a80_update() {}

struct Unk_f85a90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85a90_arg1, field_0, 0x0);

struct Unk_f85a90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85a90, field_0, 0x0);

// 0x7100f85a90
void Unk_f85a90_set(const Unk_f85a90* self, Unk_f85a90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f85aa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85aa0_arg1, field_0, 0x0);

struct Unk_f85aa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85aa0, field_0, 0x0);

// 0x7100f85aa0
void Unk_f85aa0_set(const Unk_f85aa0* self, Unk_f85aa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f85b20 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85b20, field_8, 0x8);

// 0x7100f85b20
void Unk_f85b20_call(Unk_f85b20* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f85b60_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85b60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85b60_arg1, field_8, 0x8);

struct Unk_f85b60 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85b60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85b60, field_8, 0x8);

// 0x7100f85b60
void Unk_f85b60_call(const Unk_f85b60* self, Unk_f85b60_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f85b90_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85b90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85b90_arg1, field_8, 0x8);

struct Unk_f85b90 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85b90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85b90, field_8, 0x8);

// 0x7100f85b90
void Unk_f85b90_call(const Unk_f85b90* self, Unk_f85b90_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f85c00 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85c00, field_8, 0x8);

// 0x7100f85c00
void Unk_f85c00_call(Unk_f85c00* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f85c40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85c40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85c40_arg1, field_8, 0x8);

struct Unk_f85c40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85c40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85c40, field_8, 0x8);

// 0x7100f85c40
void Unk_f85c40_call(const Unk_f85c40* self, Unk_f85c40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f85c70_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85c70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85c70_arg1, field_8, 0x8);

struct Unk_f85c70 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85c70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85c70, field_8, 0x8);

// 0x7100f85c70
void Unk_f85c70_call(const Unk_f85c70* self, Unk_f85c70_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x7100f85ca0
void Unk_f85ca0_update() {}

// 0x7100f85cb0
void Unk_f85cb0_update() {}

// 0x7100f85cc0
void Unk_f85cc0_update() {}

// 0x7100f85cd0
void Unk_f85cd0_update() {}

struct Unk_f85ce0_0 {
    u8 _0[0xb0];
    u8 field_b0;
    u8 _b1[0x1f7];
    u8 field_2a8;
    u8 _2a9[0x3];
    u32 field_2ac;
    u8 _2b0[0x118];
    u8 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_f85ce0_0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_f85ce0_0, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(Unk_f85ce0_0, field_2ac, 0x2ac);
PKMN_OFFSET_ASSERT(Unk_f85ce0_0, field_3c8, 0x3c8);

struct Unk_f85ce0 {
    Unk_f85ce0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85ce0, field_0, 0x0);

void Unk_f6cd80(void*);

// 0x7100f85ce0
void Unk_f85ce0_call(const Unk_f85ce0* self) {
    Unk_f85ce0_0* p0 = self->field_0;
    p0->field_3c8 = 1;
    Unk_f6cd80(&p0->field_b0);
    p0->field_2ac = 8;
    p0->field_2a8 = 1;
}

// 0x7100f85d20
void Unk_f85d20_update() {}

struct Unk_f85d30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85d30_arg1, field_0, 0x0);

struct Unk_f85d30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85d30, field_0, 0x0);

// 0x7100f85d30
void Unk_f85d30_set(const Unk_f85d30* self, Unk_f85d30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f85d40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85d40_arg1, field_0, 0x0);

struct Unk_f85d40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f85d40, field_0, 0x0);

// 0x7100f85d40
void Unk_f85d40_set(const Unk_f85d40* self, Unk_f85d40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f85da0
void Unk_f85da0_update() {}

struct Unk_f85db0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85db0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85db0, field_8, 0x8);

// 0x7100f85db0
void Unk_f85db0_set(const Unk_f85db0* self, Unk_f85db0* value) {
    *value = *self;
}

struct Unk_f85dc0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85dc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85dc0, field_8, 0x8);

// 0x7100f85dc0
void Unk_f85dc0_set(const Unk_f85dc0* self, Unk_f85dc0* value) {
    *value = *self;
}

struct Unk_f85ef0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85ef0, field_8, 0x8);

// 0x7100f85ef0
void Unk_f85ef0_call(Unk_f85ef0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f85f30_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85f30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85f30_arg1, field_8, 0x8);

struct Unk_f85f30 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85f30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85f30, field_8, 0x8);

// 0x7100f85f30
void Unk_f85f30_call(const Unk_f85f30* self, Unk_f85f30_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f85f60_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85f60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85f60_arg1, field_8, 0x8);

struct Unk_f85f60 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85f60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f85f60, field_8, 0x8);

// 0x7100f85f60
void Unk_f85f60_call(const Unk_f85f60* self, Unk_f85f60_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f85fc0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f85fc0, field_8, 0x8);

// 0x7100f85fc0
void Unk_f85fc0_call(Unk_f85fc0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f86000_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f86000_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f86000_arg1, field_8, 0x8);

struct Unk_f86000 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f86000, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f86000, field_8, 0x8);

// 0x7100f86000
void Unk_f86000_call(const Unk_f86000* self, Unk_f86000_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f86030_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f86030_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f86030_arg1, field_8, 0x8);

struct Unk_f86030 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f86030, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f86030, field_8, 0x8);

// 0x7100f86030
void Unk_f86030_call(const Unk_f86030* self, Unk_f86030_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f86060_0 {
    u8 _0[0x2a8];
    u8 field_2a8;
    u8 _2a9[0x3];
    u32 field_2ac;
};
PKMN_OFFSET_ASSERT(Unk_f86060_0, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(Unk_f86060_0, field_2ac, 0x2ac);

struct Unk_f86060 {
    Unk_f86060_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86060, field_0, 0x0);

void Unk_f7de70(void*);

// 0x7100f86060
void Unk_f86060_call(const Unk_f86060* self) {
    Unk_f86060_0* p0 = self->field_0;
    Unk_f7de70(p0);
    p0->field_2ac = 0xb;
    p0->field_2a8 = 1;
}

// 0x7100f860a0
void Unk_f860a0_update() {}

struct Unk_f860b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f860b0_arg1, field_0, 0x0);

struct Unk_f860b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f860b0, field_0, 0x0);

// 0x7100f860b0
void Unk_f860b0_set(const Unk_f860b0* self, Unk_f860b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f860c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f860c0_arg1, field_0, 0x0);

struct Unk_f860c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f860c0, field_0, 0x0);

// 0x7100f860c0
void Unk_f860c0_set(const Unk_f860c0* self, Unk_f860c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f860d0 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f860d0, field_0, 0x0);

void Unk_f7dbe0(void*, u32);

// 0x7100f860d0
void Unk_f860d0_call(const Unk_f860d0* self) {
    Unk_f7dbe0(self->field_0, 0);
}

// 0x7100f860e0
void Unk_f860e0_update() {}

struct Unk_f860f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f860f0_arg1, field_0, 0x0);

struct Unk_f860f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f860f0, field_0, 0x0);

// 0x7100f860f0
void Unk_f860f0_set(const Unk_f860f0* self, Unk_f860f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f86100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86100_arg1, field_0, 0x0);

struct Unk_f86100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86100, field_0, 0x0);

// 0x7100f86100
void Unk_f86100_set(const Unk_f86100* self, Unk_f86100_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f86110 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86110, field_0, 0x0);

void Unk_f7dbe0(void*, u32);

// 0x7100f86110
void Unk_f86110_call(const Unk_f86110* self) {
    Unk_f7dbe0(self->field_0, 0);
}

// 0x7100f86120
void Unk_f86120_update() {}

struct Unk_f86130_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86130_arg1, field_0, 0x0);

struct Unk_f86130 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86130, field_0, 0x0);

// 0x7100f86130
void Unk_f86130_set(const Unk_f86130* self, Unk_f86130_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f86140_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86140_arg1, field_0, 0x0);

struct Unk_f86140 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86140, field_0, 0x0);

// 0x7100f86140
void Unk_f86140_set(const Unk_f86140* self, Unk_f86140_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f86180
void Unk_f86180_update() {}

struct Unk_f86190_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86190_arg1, field_0, 0x0);

struct Unk_f86190 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86190, field_0, 0x0);

// 0x7100f86190
void Unk_f86190_set(const Unk_f86190* self, Unk_f86190_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f861a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f861a0_arg1, field_0, 0x0);

struct Unk_f861a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f861a0, field_0, 0x0);

// 0x7100f861a0
void Unk_f861a0_set(const Unk_f861a0* self, Unk_f861a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f862e0
void Unk_f862e0_update() {}

struct Unk_f862f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f862f0_arg1, field_0, 0x0);

struct Unk_f862f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f862f0, field_0, 0x0);

// 0x7100f862f0
void Unk_f862f0_set(const Unk_f862f0* self, Unk_f862f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f86300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86300_arg1, field_0, 0x0);

struct Unk_f86300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86300, field_0, 0x0);

// 0x7100f86300
void Unk_f86300_set(const Unk_f86300* self, Unk_f86300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f86310 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86310, field_0, 0x0);

void Unk_f7dbe0(void*, u32);

// 0x7100f86310
void Unk_f86310_call(const Unk_f86310* self) {
    Unk_f7dbe0(self->field_0, 0);
}

// 0x7100f86320
void Unk_f86320_update() {}

struct Unk_f86330_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86330_arg1, field_0, 0x0);

struct Unk_f86330 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86330, field_0, 0x0);

// 0x7100f86330
void Unk_f86330_set(const Unk_f86330* self, Unk_f86330_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f86340_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86340_arg1, field_0, 0x0);

struct Unk_f86340 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f86340, field_0, 0x0);

// 0x7100f86340
void Unk_f86340_set(const Unk_f86340* self, Unk_f86340_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e17b4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e17b4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e17b4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e17b4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e17b4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e17b4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e17b4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e17b4_Data, field_18, 0x18);

extern Unk_27e17b4_Data Unk_27e17b4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f86350
void Unk_f86350_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e17b4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e17b4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e17b4.field_18 = 0xffff;
    Unk_27e17b4.field_10 = 0;
    Unk_27e17b4.field_8 = r2;
    Unk_27e17b4.field_c = 0;
    Unk_27e17b4.field_14 = 0xffffffff;
}
