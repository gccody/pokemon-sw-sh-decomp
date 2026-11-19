// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101104800
void Unk_1104800_update() {}

struct Unk_1104810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1104810_arg1, field_0, 0x0);

struct Unk_1104810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1104810, field_0, 0x0);

// 0x7101104810
void Unk_1104810_set(const Unk_1104810* self, Unk_1104810_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1104820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1104820_arg1, field_0, 0x0);

struct Unk_1104820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1104820, field_0, 0x0);

// 0x7101104820
void Unk_1104820_set(const Unk_1104820* self, Unk_1104820_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011048b0
void Unk_11048b0_update() {}

struct Unk_11048c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11048c0_arg1, field_0, 0x0);

struct Unk_11048c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11048c0, field_0, 0x0);

// 0x71011048c0
void Unk_11048c0_set(const Unk_11048c0* self, Unk_11048c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11048d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11048d0_arg1, field_0, 0x0);

struct Unk_11048d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11048d0, field_0, 0x0);

// 0x71011048d0
void Unk_11048d0_set(const Unk_11048d0* self, Unk_11048d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e51dc_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e51dc_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e51dc_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e51dc_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e51dc_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e51dc_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e51dc_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e51dc_Data, field_18, 0x18);

extern Unk_27e51dc_Data Unk_27e51dc __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101104ab0
void Unk_1104ab0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e51dc.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e51dc.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e51dc.field_10 = 0xffff;
    Unk_27e51dc.field_8 = r2;
    Unk_27e51dc.field_c = 0xffffffff;
    Unk_27e51dc.field_18 = 0;
    Unk_27e51dc.field_14 = 0;
}
