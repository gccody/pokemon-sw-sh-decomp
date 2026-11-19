// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern const u8 Unk_24368b0[] __attribute__((visibility("hidden")));

// 0x71013ef8a0
const u8* Unk_13ef8a0_get() {
    return Unk_24368b0;
}

u64 Unk_e591a0();

// 0x71013f15c0
u64 Unk_13f15c0_call() {
    u64 r0 = Unk_e591a0();
    return r0 & 1;
}

void Unk_d9cea0();

// 0x71013f2170
u32 Unk_13f2170_call() {
    Unk_d9cea0();
    return 1;
}

struct Unk_66efd0;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_d720e0(u32);

// 0x71013f4200
u32 Unk_13f4200_call(Unk_66efd0* self) {
    Unk_d720e0(0);
    Unk_66efd0_update(self, 0xc);
    return 1;
}

struct Unk_66efd0;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_d720e0(u32);

// 0x71013f4240
u32 Unk_13f4240_call(Unk_66efd0* self) {
    Unk_d720e0(1);
    Unk_66efd0_update(self, 0xc);
    return 1;
}

struct Unk_66efd0;
u32 Unk_66efd0_update(Unk_66efd0*, u32);
void Unk_d6cb90();

// 0x71013f5d50
u32 Unk_13f5d50_call(Unk_66efd0* self) {
    Unk_d6cb90();
    Unk_66efd0_update(self, 0xc);
    return 1;
}

u64 Unk_1376830();

// 0x71013f5ee0
u64 Unk_13f5ee0_call() {
    u64 r0 = Unk_1376830();
    return r0 & 1;
}

// 0x71013f5f00
u64 Unk_13f5f00_get() {
    return 0;
}

// 0x71013f5f10
u64 Unk_13f5f10_get() {
    return 0;
}

struct Unk_27f040c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f040c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f040c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f040c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f040c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f040c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f040c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f040c_Data, field_18, 0x18);

extern Unk_27f040c_Data Unk_27f040c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71013f7520
void Unk_13f7520_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f040c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f040c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f040c.field_18 = 0xffff;
    Unk_27f040c.field_10 = 0;
    Unk_27f040c.field_8 = r2;
    Unk_27f040c.field_c = 0;
    Unk_27f040c.field_14 = 0xffffffff;
}
