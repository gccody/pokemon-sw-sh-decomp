// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ff8950 {
    u8 _0[0x30];
    u32 field_30;
    u8 _34[0x4c];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_ff8950, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_ff8950, field_80, 0x80);
void Unk_ff8820(void*, u32, u32, u32, void*, void*, void*, void*);

// 0x7100ff8950
void Unk_ff8950_update(Unk_ff8950* self, void* value, void* arg2, void* arg3, void* arg4) {
    if (self->field_80 != 0) {
        return;
    }
    self->field_30 = 0;
    Unk_ff8820(self, 1, 1, 0, value, arg2, arg3, arg4);
}

// 0x7100ff8ce0
void Unk_ff8ce0_update() {}

struct Unk_ff8cf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8cf0_arg1, field_0, 0x0);

struct Unk_ff8cf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8cf0, field_0, 0x0);

// 0x7100ff8cf0
void Unk_ff8cf0_set(const Unk_ff8cf0* self, Unk_ff8cf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff8d00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8d00_arg1, field_0, 0x0);

struct Unk_ff8d00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8d00, field_0, 0x0);

// 0x7100ff8d00
void Unk_ff8d00_set(const Unk_ff8d00* self, Unk_ff8d00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e2974_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e2974_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e2974_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e2974_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e2974_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e2974_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e2974_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e2974_Data, field_18, 0x18);

extern Unk_27e2974_Data Unk_27e2974 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100ff8d10
void Unk_ff8d10_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e2974.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e2974.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e2974.field_18 = 0xffff;
    Unk_27e2974.field_10 = 0;
    Unk_27e2974.field_8 = r2;
    Unk_27e2974.field_c = 0;
    Unk_27e2974.field_14 = 0xffffffff;
}
