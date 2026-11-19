// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_11032e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11032e0, field_0, 0x0);

// 0x71011032e0
void Unk_11032e0_call(Unk_11032e0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_1103320_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103320_arg1, field_0, 0x0);

struct Unk_1103320 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103320, field_0, 0x0);

// 0x7101103320
void Unk_1103320_call(const Unk_1103320* self, Unk_1103320_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1103340_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103340_arg1, field_0, 0x0);

struct Unk_1103340 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103340, field_0, 0x0);

// 0x7101103340
void Unk_1103340_set(Unk_1103340* self, Unk_1103340_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1103420_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1103420_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1103420_arg1, field_8, 0x8);

struct Unk_1103420 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1103420, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1103420, field_8, 0x8);

// 0x7101103420
void Unk_1103420_set(Unk_1103420* self, Unk_1103420_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_11034a0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11034a0, field_0, 0x0);

// 0x71011034a0
void Unk_11034a0_call(Unk_11034a0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_11034e0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11034e0_arg1, field_0, 0x0);

struct Unk_11034e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11034e0, field_0, 0x0);

// 0x71011034e0
void Unk_11034e0_call(const Unk_11034e0* self, Unk_11034e0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1103500_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103500_arg1, field_0, 0x0);

struct Unk_1103500 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103500, field_0, 0x0);

// 0x7101103500
void Unk_1103500_set(Unk_1103500* self, Unk_1103500_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_27e519c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e519c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e519c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e519c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e519c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e519c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e519c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e519c_Data, field_18, 0x18);

extern Unk_27e519c_Data Unk_27e519c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101103510
void Unk_1103510_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e519c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e519c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e519c.field_10 = 0xffff;
    Unk_27e519c.field_8 = r2;
    Unk_27e519c.field_c = 0xffffffff;
    Unk_27e519c.field_18 = 0;
    Unk_27e519c.field_14 = 0;
}
