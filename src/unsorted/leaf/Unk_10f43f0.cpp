// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10f43f0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f43f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f43f0_arg1, field_8, 0x8);

struct Unk_10f43f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f43f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f43f0, field_8, 0x8);

// 0x71010f43f0
void Unk_10f43f0_set(Unk_10f43f0* self, Unk_10f43f0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10f44f0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f44f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f44f0_arg1, field_8, 0x8);

struct Unk_10f44f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f44f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f44f0, field_8, 0x8);

// 0x71010f44f0
void Unk_10f44f0_set(Unk_10f44f0* self, Unk_10f44f0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10f4570 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f4570, field_0, 0x0);

// 0x71010f4570
void Unk_10f4570_call(Unk_10f4570* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10f45b0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f45b0_arg1, field_0, 0x0);

struct Unk_10f45b0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f45b0, field_0, 0x0);

// 0x71010f45b0
void Unk_10f45b0_call(const Unk_10f45b0* self, Unk_10f45b0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10f45d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f45d0_arg1, field_0, 0x0);

struct Unk_10f45d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f45d0, field_0, 0x0);

// 0x71010f45d0
void Unk_10f45d0_set(Unk_10f45d0* self, Unk_10f45d0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_27e4f04_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e4f04_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e4f04_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e4f04_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e4f04_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e4f04_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e4f04_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e4f04_Data, field_18, 0x18);

extern Unk_27e4f04_Data Unk_27e4f04 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71010f45e0
void Unk_10f45e0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e4f04.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e4f04.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e4f04.field_10 = 0xffff;
    Unk_27e4f04.field_8 = r2;
    Unk_27e4f04.field_c = 0xffffffff;
    Unk_27e4f04.field_18 = 0;
    Unk_27e4f04.field_14 = 0;
}
