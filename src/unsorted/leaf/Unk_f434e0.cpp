// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

u32 Unk_eb6530();

// 0x7100f434e0
u32 Unk_f434e0_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_f43630 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f43630, field_5cc, 0x5cc);

// 0x7100f43630
u32 Unk_f43630_getField5cc(const Unk_f43630* self) {
    return self->field_5cc;
}

struct Unk_f48af0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48af0, field_8, 0x8);

// 0x7100f48af0
void Unk_f48af0_call(Unk_f48af0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f48b30_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48b30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48b30_arg1, field_8, 0x8);

struct Unk_f48b30 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48b30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48b30, field_8, 0x8);

// 0x7100f48b30
void Unk_f48b30_call(const Unk_f48b30* self, Unk_f48b30_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f48b60_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48b60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48b60_arg1, field_8, 0x8);

struct Unk_f48b60 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48b60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48b60, field_8, 0x8);

// 0x7100f48b60
void Unk_f48b60_call(const Unk_f48b60* self, Unk_f48b60_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f48bd0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48bd0, field_8, 0x8);

// 0x7100f48bd0
void Unk_f48bd0_call(Unk_f48bd0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f48c10_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48c10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48c10_arg1, field_8, 0x8);

struct Unk_f48c10 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48c10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48c10, field_8, 0x8);

// 0x7100f48c10
void Unk_f48c10_call(const Unk_f48c10* self, Unk_f48c10_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f48c40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48c40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48c40_arg1, field_8, 0x8);

struct Unk_f48c40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48c40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48c40, field_8, 0x8);

// 0x7100f48c40
void Unk_f48c40_call(const Unk_f48c40* self, Unk_f48c40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f48e90 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48e90, field_8, 0x8);

// 0x7100f48e90
void Unk_f48e90_call(Unk_f48e90* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f48ed0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48ed0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48ed0_arg1, field_8, 0x8);

struct Unk_f48ed0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48ed0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48ed0, field_8, 0x8);

// 0x7100f48ed0
void Unk_f48ed0_call(const Unk_f48ed0* self, Unk_f48ed0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f48f00_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48f00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48f00_arg1, field_8, 0x8);

struct Unk_f48f00 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48f00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48f00, field_8, 0x8);

// 0x7100f48f00
void Unk_f48f00_call(const Unk_f48f00* self, Unk_f48f00_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f48f70 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48f70, field_8, 0x8);

// 0x7100f48f70
void Unk_f48f70_call(Unk_f48f70* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f48fb0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48fb0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48fb0_arg1, field_8, 0x8);

struct Unk_f48fb0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48fb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48fb0, field_8, 0x8);

// 0x7100f48fb0
void Unk_f48fb0_call(const Unk_f48fb0* self, Unk_f48fb0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f48fe0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48fe0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48fe0_arg1, field_8, 0x8);

struct Unk_f48fe0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f48fe0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f48fe0, field_8, 0x8);

// 0x7100f48fe0
void Unk_f48fe0_call(const Unk_f48fe0* self, Unk_f48fe0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
