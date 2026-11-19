// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710146c920
void Unk_146c920_update() {}

struct Unk_146c930_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_146c930_arg1, field_0, 0x0);

struct Unk_146c930 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_146c930, field_0, 0x0);

// 0x710146c930
void Unk_146c930_set(const Unk_146c930* self, Unk_146c930_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_146c940_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_146c940_arg1, field_0, 0x0);

struct Unk_146c940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_146c940, field_0, 0x0);

// 0x710146c940
void Unk_146c940_set(const Unk_146c940* self, Unk_146c940_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710146c990
void Unk_146c990_update() {}

struct Unk_146c9a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_146c9a0_arg1, field_0, 0x0);

struct Unk_146c9a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_146c9a0, field_0, 0x0);

// 0x710146c9a0
void Unk_146c9a0_set(const Unk_146c9a0* self, Unk_146c9a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_146c9b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_146c9b0_arg1, field_0, 0x0);

struct Unk_146c9b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_146c9b0, field_0, 0x0);

// 0x710146c9b0
void Unk_146c9b0_set(const Unk_146c9b0* self, Unk_146c9b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27f0e74_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f0e74_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f0e74_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f0e74_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f0e74_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f0e74_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f0e74_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f0e74_Data, field_18, 0x18);

extern Unk_27f0e74_Data Unk_27f0e74 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710146c9c0
void Unk_146c9c0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f0e74.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f0e74.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f0e74.field_18 = 0xffff;
    Unk_27f0e74.field_10 = 0;
    Unk_27f0e74.field_8 = r2;
    Unk_27f0e74.field_c = 0;
    Unk_27f0e74.field_14 = 0xffffffff;
}
