// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_830df0_arg1 {
    u8 _0[0x2];
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_830df0_arg1, field_2, 0x2);

struct Unk_830df0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_830df0, field_8, 0x8);

u32 Unk_816460(u64, u32);

// 0x7100830df0
void Unk_830df0_call(const Unk_830df0* self, Unk_830df0_arg1* value) {
    u32 r0 = Unk_816460(self->field_8, 0xb8);
    value->field_2 = r0;
}

struct Unk_831020 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_831020, field_0, 0x0);

// 0x7100831020
void Unk_831020_set(Unk_831020* self) {
    self->field_0 = 0xffffffff;
}

struct Unk_831030 {
    u8 _0[0x2];
    s16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_831030, field_2, 0x2);

// 0x7100831030
bool Unk_831030_check(const Unk_831030* self) {
    return self->field_2 != -1;
}

struct Unk_831040 {
    u16 field_0;
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_831040, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_831040, field_2, 0x2);

u32 Unk_816460(u64, u32);

// 0x7100831040
void Unk_831040_call(Unk_831040* self, u64 value) {
    u32 r0 = Unk_816460(value, 0x97);
    self->field_0 = r0;
    u32 r1 = Unk_816460(value, 0x86);
    self->field_2 = r1;
}

struct Unk_27cf464_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cf464_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cf464_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cf464_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cf464_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cf464_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cf464_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cf464_Data, field_18, 0x18);

extern Unk_27cf464_Data Unk_27cf464 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100831230
void Unk_831230_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cf464.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cf464.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cf464.field_18 = 0xffff;
    Unk_27cf464.field_10 = 0;
    Unk_27cf464.field_8 = r2;
    Unk_27cf464.field_c = 0;
    Unk_27cf464.field_14 = 0xffffffff;
}
