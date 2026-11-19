// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100ff7c20
void Unk_ff7c20_update() {}

struct Unk_ff7c30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7c30_arg1, field_0, 0x0);

struct Unk_ff7c30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7c30, field_0, 0x0);

// 0x7100ff7c30
void Unk_ff7c30_set(const Unk_ff7c30* self, Unk_ff7c30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7c40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7c40_arg1, field_0, 0x0);

struct Unk_ff7c40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7c40, field_0, 0x0);

// 0x7100ff7c40
void Unk_ff7c40_set(const Unk_ff7c40* self, Unk_ff7c40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7c80 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7c80, field_8, 0x8);

// 0x7100ff7c80
void Unk_ff7c80_call(Unk_ff7c80* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_ff7cc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7cc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7cc0_arg1, field_8, 0x8);

struct Unk_ff7cc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7cc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7cc0, field_8, 0x8);

// 0x7100ff7cc0
void Unk_ff7cc0_call(const Unk_ff7cc0* self, Unk_ff7cc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7cf0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7cf0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7cf0_arg1, field_8, 0x8);

struct Unk_ff7cf0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7cf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7cf0, field_8, 0x8);

// 0x7100ff7cf0
void Unk_ff7cf0_call(const Unk_ff7cf0* self, Unk_ff7cf0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7d50 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7d50, field_8, 0x8);

// 0x7100ff7d50
void Unk_ff7d50_call(Unk_ff7d50* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_ff7d90_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7d90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7d90_arg1, field_8, 0x8);

struct Unk_ff7d90 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7d90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7d90, field_8, 0x8);

// 0x7100ff7d90
void Unk_ff7d90_call(const Unk_ff7d90* self, Unk_ff7d90_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7dc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7dc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7dc0_arg1, field_8, 0x8);

struct Unk_ff7dc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7dc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7dc0, field_8, 0x8);

// 0x7100ff7dc0
void Unk_ff7dc0_call(const Unk_ff7dc0* self, Unk_ff7dc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7df0_0 {
    u8 _0[0x218];
    u8 field_218;
    u8 _219[0x3];
    u32 field_21c;
};
PKMN_OFFSET_ASSERT(Unk_ff7df0_0, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_ff7df0_0, field_21c, 0x21c);

struct Unk_ff7df0 {
    Unk_ff7df0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7df0, field_0, 0x0);

// 0x7100ff7df0
void Unk_ff7df0_set(const Unk_ff7df0* self) {
    Unk_ff7df0_0* p0 = self->field_0;
    p0->field_21c = 5;
    p0->field_218 = 1;
}

// 0x7100ff7e10
void Unk_ff7e10_update() {}

struct Unk_ff7e20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e20_arg1, field_0, 0x0);

struct Unk_ff7e20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e20, field_0, 0x0);

// 0x7100ff7e20
void Unk_ff7e20_set(const Unk_ff7e20* self, Unk_ff7e20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7e30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e30_arg1, field_0, 0x0);

struct Unk_ff7e30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e30, field_0, 0x0);

// 0x7100ff7e30
void Unk_ff7e30_set(const Unk_ff7e30* self, Unk_ff7e30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7e40_0 {
    u8 _0[0x218];
    u8 field_218;
    u8 _219[0x3];
    u32 field_21c;
};
PKMN_OFFSET_ASSERT(Unk_ff7e40_0, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_ff7e40_0, field_21c, 0x21c);

struct Unk_ff7e40 {
    Unk_ff7e40_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e40, field_0, 0x0);

// 0x7100ff7e40
void Unk_ff7e40_set(const Unk_ff7e40* self) {
    Unk_ff7e40_0* p0 = self->field_0;
    p0->field_21c = 6;
    p0->field_218 = 1;
}

// 0x7100ff7e60
void Unk_ff7e60_update() {}

struct Unk_ff7e70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e70_arg1, field_0, 0x0);

struct Unk_ff7e70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e70, field_0, 0x0);

// 0x7100ff7e70
void Unk_ff7e70_set(const Unk_ff7e70* self, Unk_ff7e70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7e80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e80_arg1, field_0, 0x0);

struct Unk_ff7e80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7e80, field_0, 0x0);

// 0x7100ff7e80
void Unk_ff7e80_set(const Unk_ff7e80* self, Unk_ff7e80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e2954_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e2954_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e2954_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e2954_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e2954_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e2954_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e2954_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e2954_Data, field_18, 0x18);

extern Unk_27e2954_Data Unk_27e2954 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100ff7e90
void Unk_ff7e90_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e2954.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e2954.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e2954.field_18 = 0xffff;
    Unk_27e2954.field_10 = 0;
    Unk_27e2954.field_8 = r2;
    Unk_27e2954.field_c = 0;
    Unk_27e2954.field_14 = 0xffffffff;
}
