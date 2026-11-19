// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x7100a8b7c0
void Unk_a8b7c0_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100a8b7d0
void Unk_a8b7d0_call(void* self) {
    Unk_eb6230(self, 3);
}

u32 Unk_eb6530();

// 0x7100a8b7e0
u32 Unk_a8b7e0_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_a8b800 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a8b800, field_5cc, 0x5cc);

// 0x7100a8b800
u32 Unk_a8b800_getField5cc(const Unk_a8b800* self) {
    return self->field_5cc;
}

struct Unk_a8b810 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a8b810, field_5cc, 0x5cc);

// 0x7100a8b810
void Unk_a8b810_clearField5cc(Unk_a8b810* self) {
    self->field_5cc = 0;
}

void Unk_eb6230(void*, u32);

// 0x7100a8c930
void Unk_a8c930_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100a8c940
void Unk_a8c940_call(void* self) {
    Unk_eb6230(self, 3);
}

u32 Unk_eb6530();

// 0x7100a8c950
u32 Unk_a8c950_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_a8c970 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a8c970, field_5cc, 0x5cc);

// 0x7100a8c970
u32 Unk_a8c970_getField5cc(const Unk_a8c970* self) {
    return self->field_5cc;
}

struct Unk_a8c980 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a8c980, field_5cc, 0x5cc);

// 0x7100a8c980
void Unk_a8c980_clearField5cc(Unk_a8c980* self) {
    self->field_5cc = 0;
}

struct Unk_a8c990 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_a8c990, field_5d0, 0x5d0);

// 0x7100a8c990
void Unk_a8c990_setField5d0(Unk_a8c990* self, u64 value) {
    self->field_5d0 = value;
}

// 0x7100a92a60
void Unk_a92a60_update() {}

struct Unk_a92a70 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_a92a70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a92a70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a92a70, field_10, 0x10);

// 0x7100a92a70
void Unk_a92a70_set(const Unk_a92a70* self, Unk_a92a70* value) {
    *value = *self;
}

struct Unk_a92a90 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_a92a90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_a92a90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_a92a90, field_10, 0x10);

// 0x7100a92a90
void Unk_a92a90_set(const Unk_a92a90* self, Unk_a92a90* value) {
    *value = *self;
}

struct Unk_a94040 {
    u8 _0[0x614];
    u32 field_614;
};
PKMN_OFFSET_ASSERT(Unk_a94040, field_614, 0x614);

// 0x7100a94040
u32 Unk_a94040_getField614(const Unk_a94040* self) {
    return self->field_614;
}

void Unk_eb6230(void*, u32);

// 0x7100a96ad0
void Unk_a96ad0_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100a96ae0
void Unk_a96ae0_call(void* self) {
    Unk_eb6230(self, 3);
}

u32 Unk_eb6530();

// 0x7100a96af0
u32 Unk_a96af0_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_a96b10 {
    u8 _0[0x4c0];
    u64 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_a96b10, field_4c0, 0x4c0);

void Unk_1500c40(u64);

// 0x7100a96b10
void Unk_a96b10_call(const Unk_a96b10* self) {
    if (self->field_4c0 != 0) {
        Unk_1500c40(self->field_4c0);
    }
}

struct Unk_a96b20 {
    u8 _0[0x608];
    u32 field_608;
};
PKMN_OFFSET_ASSERT(Unk_a96b20, field_608, 0x608);

// 0x7100a96b20
u32 Unk_a96b20_getField608(const Unk_a96b20* self) {
    return self->field_608;
}

struct Unk_a96b30 {
    u8 _0[0x608];
    u32 field_608;
};
PKMN_OFFSET_ASSERT(Unk_a96b30, field_608, 0x608);

// 0x7100a96b30
void Unk_a96b30_clearField608(Unk_a96b30* self) {
    self->field_608 = 0;
}

struct Unk_a96b40 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a96b40, field_5cc, 0x5cc);

// 0x7100a96b40
void Unk_a96b40_setField5cc(Unk_a96b40* self, u32 value) {
    self->field_5cc = value;
}

struct Unk_a96bb0 {
    u8 _0[0x5d0];
    u64 field_5d0;
    u64 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_a96bb0, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_a96bb0, field_5d8, 0x5d8);

// 0x7100a96bb0
void Unk_a96bb0_set(Unk_a96bb0* self, u64 value, u64 arg2) {
    self->field_5d0 = value;
    self->field_5d8 = arg2;
}

struct Unk_a96bc0 {
    u8 _0[0x6dc];
    u32 field_6dc;
};
PKMN_OFFSET_ASSERT(Unk_a96bc0, field_6dc, 0x6dc);

// 0x7100a96bc0
void Unk_a96bc0_setField6dc(Unk_a96bc0* self, u32 value) {
    self->field_6dc = value;
}

struct Unk_a96bd0 {
    u8 _0[0x618];
    u32 field_618;
};
PKMN_OFFSET_ASSERT(Unk_a96bd0, field_618, 0x618);

// 0x7100a96bd0
void Unk_a96bd0_setField618(Unk_a96bd0* self, u32 value) {
    self->field_618 = value;
}

struct Unk_a96be0 {
    u8 _0[0x618];
    u32 field_618;
};
PKMN_OFFSET_ASSERT(Unk_a96be0, field_618, 0x618);

// 0x7100a96be0
u32 Unk_a96be0_getField618(const Unk_a96be0* self) {
    return self->field_618;
}

struct Unk_a97440 {
    u8 _0[0x614];
    u32 field_614;
};
PKMN_OFFSET_ASSERT(Unk_a97440, field_614, 0x614);

// 0x7100a97440
void Unk_a97440_setField614(Unk_a97440* self, u32 value) {
    self->field_614 = value;
}

struct Unk_aa0b40 {
    u8 _0[0x6d8];
    u16 field_6d8;
    u16 field_6da;
};
PKMN_OFFSET_ASSERT(Unk_aa0b40, field_6d8, 0x6d8);
PKMN_OFFSET_ASSERT(Unk_aa0b40, field_6da, 0x6da);

// 0x7100aa0b40
bool Unk_aa0b40_check(const Unk_aa0b40* self) {
    return self->field_6da == self->field_6d8;
}

struct Unk_aad500;
struct Unk_aa3130 {
    u8 _0[0x5e8];
    Unk_aad500* field_5e8;
};
PKMN_OFFSET_ASSERT(Unk_aa3130, field_5e8, 0x5e8);

u32 Unk_aad500_getField80(const Unk_aad500*);

// 0x7100aa3130
void Unk_aa3130_call(const Unk_aa3130* self) {
    Unk_aad500_getField80(self->field_5e8);
}

struct Unk_aa4660 {
    u8 _0[0x681];
    u8 field_681;
};
PKMN_OFFSET_ASSERT(Unk_aa4660, field_681, 0x681);

// 0x7100aa4660
u8 Unk_aa4660_getField681(const Unk_aa4660* self) {
    return self->field_681;
}

struct Unk_aa4670 {
    u8 _0[0x684];
    u32 field_684;
};
PKMN_OFFSET_ASSERT(Unk_aa4670, field_684, 0x684);

// 0x7100aa4670
u32 Unk_aa4670_getField684(const Unk_aa4670* self) {
    return self->field_684;
}

struct Unk_aa5440 {
    u8 _0[0x688];
    u32 field_688;
};
PKMN_OFFSET_ASSERT(Unk_aa5440, field_688, 0x688);

// 0x7100aa5440
u32 Unk_aa5440_getField688(const Unk_aa5440* self) {
    return self->field_688;
}

struct Unk_aa6650 {
    u8 _0[0x68c];
    u32 field_68c;
};
PKMN_OFFSET_ASSERT(Unk_aa6650, field_68c, 0x68c);

// 0x7100aa6650
bool Unk_aa6650_check(const Unk_aa6650* self) {
    return self->field_68c != 1;
}

struct Unk_aa75b0 {
    u8 _0[0x68c];
    u32 field_68c;
};
PKMN_OFFSET_ASSERT(Unk_aa75b0, field_68c, 0x68c);

// 0x7100aa75b0
bool Unk_aa75b0_check(const Unk_aa75b0* self) {
    return self->field_68c == 2;
}

struct Unk_aa89f0 {
    u8 _0[0x5f0];
    u64 field_5f0;
};
PKMN_OFFSET_ASSERT(Unk_aa89f0, field_5f0, 0x5f0);

void Unk_ab18f0(u64, u32);

// 0x7100aa89f0
void Unk_aa89f0_call(const Unk_aa89f0* self) {
    Unk_ab18f0(self->field_5f0, 0);
}

struct Unk_aaa310 {
    u8 _0[0x6da];
    u16 field_6da;
};
PKMN_OFFSET_ASSERT(Unk_aaa310, field_6da, 0x6da);

// 0x7100aaa310
u16 Unk_aaa310_getField6da(const Unk_aaa310* self) {
    return self->field_6da;
}

struct Unk_aab1a0 {
    u8 _0[0x680];
    u8 field_680;
};
PKMN_OFFSET_ASSERT(Unk_aab1a0, field_680, 0x680);

// 0x7100aab1a0
u8 Unk_aab1a0_getField680(const Unk_aab1a0* self) {
    return self->field_680;
}

struct Unk_aab1b0 {
    u8 _0[0x620];
    u8 field_620;
};
PKMN_OFFSET_ASSERT(Unk_aab1b0, field_620, 0x620);

// 0x7100aab1b0
u8 Unk_aab1b0_getField620(const Unk_aab1b0* self) {
    return self->field_620;
}

struct Unk_aab2c0 {
    u8 _0[0x6f8];
    bool field_6f8;
};
PKMN_OFFSET_ASSERT(Unk_aab2c0, field_6f8, 0x6f8);

// 0x7100aab2c0
void Unk_aab2c0_set(Unk_aab2c0* self, bool value) {
    self->field_6f8 = value;
}

struct Unk_aab8b0 {
    u8 _0[0x60c];
    u8 field_60c;
};
PKMN_OFFSET_ASSERT(Unk_aab8b0, field_60c, 0x60c);

// 0x7100aab8b0
u8 Unk_aab8b0_getField60c(const Unk_aab8b0* self) {
    return self->field_60c;
}

// 0x7100aabcf0
void Unk_aabcf0_update() {}

struct Unk_aabd00 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_aabd00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_aabd00, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_aabd00, field_10, 0x10);

// 0x7100aabd00
void Unk_aabd00_set(const Unk_aabd00* self, Unk_aabd00* value) {
    *value = *self;
}

struct Unk_aabd20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_aabd20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_aabd20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_aabd20, field_10, 0x10);

// 0x7100aabd20
void Unk_aabd20_set(const Unk_aabd20* self, Unk_aabd20* value) {
    *value = *self;
}

// 0x7100aabd60
void Unk_aabd60_update() {}

struct Unk_aabd70 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_aabd70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_aabd70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_aabd70, field_10, 0x10);

// 0x7100aabd70
void Unk_aabd70_set(const Unk_aabd70* self, Unk_aabd70* value) {
    *value = *self;
}

struct Unk_aabd90 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_aabd90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_aabd90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_aabd90, field_10, 0x10);

// 0x7100aabd90
void Unk_aabd90_set(const Unk_aabd90* self, Unk_aabd90* value) {
    *value = *self;
}

// 0x7100aabf70
void Unk_aabf70_update() {}

struct Unk_aabf80 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_aabf80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_aabf80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_aabf80, field_10, 0x10);

// 0x7100aabf80
void Unk_aabf80_set(const Unk_aabf80* self, Unk_aabf80* value) {
    *value = *self;
}

struct Unk_aabfa0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_aabfa0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_aabfa0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_aabfa0, field_10, 0x10);

// 0x7100aabfa0
void Unk_aabfa0_set(const Unk_aabfa0* self, Unk_aabfa0* value) {
    *value = *self;
}

struct Unk_27d763c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d763c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d763c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d763c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d763c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d763c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d763c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d763c_Data, field_18, 0x18);

extern Unk_27d763c_Data Unk_27d763c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100aac3b0
void Unk_aac3b0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d763c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d763c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d763c.field_18 = 0xffff;
    Unk_27d763c.field_10 = 0;
    Unk_27d763c.field_8 = r2;
    Unk_27d763c.field_c = 0;
    Unk_27d763c.field_14 = 0xffffffff;
}
