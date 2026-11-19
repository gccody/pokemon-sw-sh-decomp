// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d17bc0 {
    u8 _0[0x600];
    u64 field_600;
};
PKMN_OFFSET_ASSERT(Unk_d17bc0, field_600, 0x600);

// 0x7100d17bc0
bool Unk_d17bc0_check(const Unk_d17bc0* self) {
    return self->field_600 != 0xcbf29ce484222645;
}

// 0x7100d185f0
void Unk_d185f0_update() {}

struct Unk_d18600_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d18600_arg1, field_0, 0x0);

struct Unk_d18600 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d18600, field_0, 0x0);

// 0x7100d18600
void Unk_d18600_set(const Unk_d18600* self, Unk_d18600_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d18610_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d18610_arg1, field_0, 0x0);

struct Unk_d18610 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d18610, field_0, 0x0);

// 0x7100d18610
void Unk_d18610_set(const Unk_d18610* self, Unk_d18610_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27dc00c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dc00c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dc00c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dc00c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dc00c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dc00c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dc00c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dc00c_Data, field_18, 0x18);

extern Unk_27dc00c_Data Unk_27dc00c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d18620
void Unk_d18620_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dc00c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dc00c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dc00c.field_18 = 0xffff;
    Unk_27dc00c.field_10 = 0;
    Unk_27dc00c.field_8 = r2;
    Unk_27dc00c.field_c = 0;
    Unk_27dc00c.field_14 = 0xffffffff;
}
