// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100f875d0
void Unk_f875d0_update() {}

struct Unk_f875e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f875e0_arg1, field_0, 0x0);

struct Unk_f875e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f875e0, field_0, 0x0);

// 0x7100f875e0
void Unk_f875e0_set(const Unk_f875e0* self, Unk_f875e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f875f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f875f0_arg1, field_0, 0x0);

struct Unk_f875f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f875f0, field_0, 0x0);

// 0x7100f875f0
void Unk_f875f0_set(const Unk_f875f0* self, Unk_f875f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f87720 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f87720, field_8, 0x8);

// 0x7100f87720
void Unk_f87720_call(Unk_f87720* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f87760_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f87760_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f87760_arg1, field_8, 0x8);

struct Unk_f87760 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f87760, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f87760, field_8, 0x8);

// 0x7100f87760
void Unk_f87760_call(const Unk_f87760* self, Unk_f87760_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f87790_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f87790_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f87790_arg1, field_8, 0x8);

struct Unk_f87790 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f87790, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f87790, field_8, 0x8);

// 0x7100f87790
void Unk_f87790_call(const Unk_f87790* self, Unk_f87790_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f877f0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f877f0, field_8, 0x8);

// 0x7100f877f0
void Unk_f877f0_call(Unk_f877f0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f87830_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f87830_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f87830_arg1, field_8, 0x8);

struct Unk_f87830 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f87830, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f87830, field_8, 0x8);

// 0x7100f87830
void Unk_f87830_call(const Unk_f87830* self, Unk_f87830_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f87860_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f87860_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f87860_arg1, field_8, 0x8);

struct Unk_f87860 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f87860, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f87860, field_8, 0x8);

// 0x7100f87860
void Unk_f87860_call(const Unk_f87860* self, Unk_f87860_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f87890_0 {
    u8 _0[0x2a8];
    u8 field_2a8;
    u8 _2a9[0x3];
    u32 field_2ac;
};
PKMN_OFFSET_ASSERT(Unk_f87890_0, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(Unk_f87890_0, field_2ac, 0x2ac);

struct Unk_f87890 {
    Unk_f87890_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f87890, field_0, 0x0);

void Unk_f7de70(void*);

// 0x7100f87890
void Unk_f87890_call(const Unk_f87890* self) {
    Unk_f87890_0* p0 = self->field_0;
    Unk_f7de70(p0);
    p0->field_2ac = 6;
    p0->field_2a8 = 1;
}

// 0x7100f878d0
void Unk_f878d0_update() {}

struct Unk_f878e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f878e0_arg1, field_0, 0x0);

struct Unk_f878e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f878e0, field_0, 0x0);

// 0x7100f878e0
void Unk_f878e0_set(const Unk_f878e0* self, Unk_f878e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f878f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f878f0_arg1, field_0, 0x0);

struct Unk_f878f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f878f0, field_0, 0x0);

// 0x7100f878f0
void Unk_f878f0_set(const Unk_f878f0* self, Unk_f878f0_arg1* value) {
    value->field_0 = self->field_0;
}
