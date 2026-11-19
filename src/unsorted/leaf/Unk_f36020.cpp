// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f36020_5d0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_f36020_5d0, field_58, 0x58);

struct Unk_f36020 {
    u8 _0[0x5d0];
    Unk_f36020_5d0* field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_f36020, field_5d0, 0x5d0);

// 0x7100f36020
void Unk_f36020_set(const Unk_f36020* self, bool value) {
    self->field_5d0->field_58 = (self->field_5d0->field_58 & 0xfffffffe) | (value);
}

// 0x7100f37150
void Unk_f37150_update() {}

struct Unk_f37160_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f37160_arg1, field_0, 0x0);

struct Unk_f37160 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f37160, field_0, 0x0);

// 0x7100f37160
void Unk_f37160_set(const Unk_f37160* self, Unk_f37160_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f37170_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f37170_arg1, field_0, 0x0);

struct Unk_f37170 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f37170, field_0, 0x0);

// 0x7100f37170
void Unk_f37170_set(const Unk_f37170* self, Unk_f37170_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f372d0
void Unk_f372d0_update() {}

struct Unk_f372e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f372e0_arg1, field_0, 0x0);

struct Unk_f372e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f372e0, field_0, 0x0);

// 0x7100f372e0
void Unk_f372e0_set(const Unk_f372e0* self, Unk_f372e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f372f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f372f0_arg1, field_0, 0x0);

struct Unk_f372f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f372f0, field_0, 0x0);

// 0x7100f372f0
void Unk_f372f0_set(const Unk_f372f0* self, Unk_f372f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f37460
void Unk_f37460_update() {}

struct Unk_f37470_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f37470_arg1, field_0, 0x0);

struct Unk_f37470 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f37470, field_0, 0x0);

// 0x7100f37470
void Unk_f37470_set(const Unk_f37470* self, Unk_f37470_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f37480_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f37480_arg1, field_0, 0x0);

struct Unk_f37480 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f37480, field_0, 0x0);

// 0x7100f37480
void Unk_f37480_set(const Unk_f37480* self, Unk_f37480_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e1174_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e1174_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e1174_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e1174_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e1174_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e1174_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e1174_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e1174_Data, field_18, 0x18);

extern Unk_27e1174_Data Unk_27e1174 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f37490
void Unk_f37490_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e1174.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e1174.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e1174.field_18 = 0xffff;
    Unk_27e1174.field_10 = 0;
    Unk_27e1174.field_8 = r2;
    Unk_27e1174.field_c = 0;
    Unk_27e1174.field_14 = 0xffffffff;
}
