// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

u32 Unk_eb6530();

// 0x7101321380
u32 Unk_1321380_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_13235b0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13235b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13235b0_arg1, field_8, 0x8);

struct Unk_13235b0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13235b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13235b0, field_8, 0x8);

// 0x71013235b0
void Unk_13235b0_call(const Unk_13235b0* self, Unk_13235b0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_13235e0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13235e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13235e0_arg1, field_8, 0x8);

struct Unk_13235e0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13235e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13235e0, field_8, 0x8);

// 0x71013235e0
void Unk_13235e0_call(const Unk_13235e0* self, Unk_13235e0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1323680_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1323680_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1323680_arg1, field_8, 0x8);

struct Unk_1323680 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1323680, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1323680, field_8, 0x8);

// 0x7101323680
void Unk_1323680_call(const Unk_1323680* self, Unk_1323680_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_13236b0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13236b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13236b0_arg1, field_8, 0x8);

struct Unk_13236b0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13236b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13236b0, field_8, 0x8);

// 0x71013236b0
void Unk_13236b0_call(const Unk_13236b0* self, Unk_13236b0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_13238a0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_13238a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13238a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13238a0_arg1, field_10, 0x10);

struct Unk_13238a0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_13238a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13238a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13238a0, field_10, 0x10);

// 0x71013238a0
void Unk_13238a0_call(const Unk_13238a0* self, Unk_13238a0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_13238d0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_13238d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13238d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13238d0_arg1, field_10, 0x10);

struct Unk_13238d0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_13238d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13238d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13238d0, field_10, 0x10);

// 0x71013238d0
void Unk_13238d0_call(const Unk_13238d0* self, Unk_13238d0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_1323980_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1323980_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1323980_arg1, field_8, 0x8);

struct Unk_1323980 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1323980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1323980, field_8, 0x8);

// 0x7101323980
void Unk_1323980_call(const Unk_1323980* self, Unk_1323980_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_13239b0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13239b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13239b0_arg1, field_8, 0x8);

struct Unk_13239b0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13239b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13239b0, field_8, 0x8);

// 0x71013239b0
void Unk_13239b0_call(const Unk_13239b0* self, Unk_13239b0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
