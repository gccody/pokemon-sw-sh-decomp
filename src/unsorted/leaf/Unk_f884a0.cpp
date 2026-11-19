// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100f884a0
void Unk_f884a0_update() {}

struct Unk_f884b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f884b0_arg1, field_0, 0x0);

struct Unk_f884b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f884b0, field_0, 0x0);

// 0x7100f884b0
void Unk_f884b0_set(const Unk_f884b0* self, Unk_f884b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f884c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f884c0_arg1, field_0, 0x0);

struct Unk_f884c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f884c0, field_0, 0x0);

// 0x7100f884c0
void Unk_f884c0_set(const Unk_f884c0* self, Unk_f884c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f885f0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f885f0, field_8, 0x8);

// 0x7100f885f0
void Unk_f885f0_call(Unk_f885f0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f88630_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f88630_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f88630_arg1, field_8, 0x8);

struct Unk_f88630 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f88630, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f88630, field_8, 0x8);

// 0x7100f88630
void Unk_f88630_call(const Unk_f88630* self, Unk_f88630_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f88660_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f88660_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f88660_arg1, field_8, 0x8);

struct Unk_f88660 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f88660, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f88660, field_8, 0x8);

// 0x7100f88660
void Unk_f88660_call(const Unk_f88660* self, Unk_f88660_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f886c0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f886c0, field_8, 0x8);

// 0x7100f886c0
void Unk_f886c0_call(Unk_f886c0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f88700_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f88700_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f88700_arg1, field_8, 0x8);

struct Unk_f88700 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f88700, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f88700, field_8, 0x8);

// 0x7100f88700
void Unk_f88700_call(const Unk_f88700* self, Unk_f88700_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f88730_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f88730_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f88730_arg1, field_8, 0x8);

struct Unk_f88730 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f88730, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f88730, field_8, 0x8);

// 0x7100f88730
void Unk_f88730_call(const Unk_f88730* self, Unk_f88730_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f88760_0 {
    u8 _0[0x2a8];
    u8 field_2a8;
    u8 _2a9[0x3];
    u32 field_2ac;
};
PKMN_OFFSET_ASSERT(Unk_f88760_0, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(Unk_f88760_0, field_2ac, 0x2ac);

struct Unk_f88760 {
    Unk_f88760_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f88760, field_0, 0x0);

void Unk_f7de70(void*);

// 0x7100f88760
void Unk_f88760_call(const Unk_f88760* self) {
    Unk_f88760_0* p0 = self->field_0;
    Unk_f7de70(p0);
    p0->field_2ac = 6;
    p0->field_2a8 = 1;
}

// 0x7100f887a0
void Unk_f887a0_update() {}

struct Unk_f887b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f887b0_arg1, field_0, 0x0);

struct Unk_f887b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f887b0, field_0, 0x0);

// 0x7100f887b0
void Unk_f887b0_set(const Unk_f887b0* self, Unk_f887b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f887c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f887c0_arg1, field_0, 0x0);

struct Unk_f887c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f887c0, field_0, 0x0);

// 0x7100f887c0
void Unk_f887c0_set(const Unk_f887c0* self, Unk_f887c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e17f4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e17f4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e17f4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e17f4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e17f4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e17f4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e17f4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e17f4_Data, field_18, 0x18);

extern Unk_27e17f4_Data Unk_27e17f4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f887d0
void Unk_f887d0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e17f4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e17f4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e17f4.field_18 = 0xffff;
    Unk_27e17f4.field_10 = 0;
    Unk_27e17f4.field_8 = r2;
    Unk_27e17f4.field_c = 0;
    Unk_27e17f4.field_14 = 0xffffffff;
}
