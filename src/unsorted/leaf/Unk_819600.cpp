// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_819600 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_819600, field_30, 0x30);

void Unk_7e9830(u64, u32);

// 0x7100819600
void Unk_819600_call(const Unk_819600* self, u32 value) {
    Unk_7e9830(self->field_30, value);
}

struct Unk_819630 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_819630, field_30, 0x30);

void Unk_7e9830(u64, u32);

// 0x7100819630
void Unk_819630_call(const Unk_819630* self) {
    Unk_7e9830(self->field_30, 0x1b);
}

struct Unk_819640 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_819640, field_30, 0x30);

void Unk_7e97b0(u64, u32, u32);

// 0x7100819640
void Unk_819640_call(const Unk_819640* self, u32 value, u32 arg2) {
    Unk_7e97b0(self->field_30, value, arg2);
}

struct Unk_819650 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_819650, field_30, 0x30);

void Unk_7e97b0(u64, u32, u32);

// 0x7100819650
void Unk_819650_call(const Unk_819650* self, u32 value) {
    Unk_7e97b0(self->field_30, 0x25, value & 0xff);
}

struct Unk_819660 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_819660, field_30, 0x30);

void Unk_7e97f0(u64);

// 0x7100819660
void Unk_819660_call(const Unk_819660* self) {
    Unk_7e97f0(self->field_30);
}

struct Unk_819670 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_819670, field_30, 0x30);

void Unk_7e9860(u64);

// 0x7100819670
void Unk_819670_call(const Unk_819670* self) {
    Unk_7e9860(self->field_30);
}

struct Unk_819680 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_819680, field_30, 0x30);

void Unk_7e9910(u64);

// 0x7100819680
void Unk_819680_call(const Unk_819680* self) {
    Unk_7e9910(self->field_30);
}

struct Unk_7e9ba0;
struct Unk_819690 {
    u8 _0[0x40];
    Unk_7e9ba0* field_40;
};
PKMN_OFFSET_ASSERT(Unk_819690, field_40, 0x40);

u16 Unk_7e9ba0_getField38(const Unk_7e9ba0*);

// 0x7100819690
void Unk_819690_call(const Unk_819690* self) {
    Unk_7e9ba0_getField38(self->field_40);
}

struct Unk_8196a0 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_8196a0, field_40, 0x40);

void Unk_7e9a00(u64);

// 0x71008196a0
void Unk_8196a0_call(const Unk_8196a0* self) {
    Unk_7e9a00(self->field_40);
}

struct Unk_8196b0 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_8196b0, field_40, 0x40);

void Unk_7e9a10(u64);

// 0x71008196b0
void Unk_8196b0_call(const Unk_8196b0* self) {
    Unk_7e9a10(self->field_40);
}

struct Unk_8196c0 {
    u8 _0[0x30];
    u64 field_30;
    u8 _38[0x8];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_8196c0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_8196c0, field_40, 0x40);

void Unk_7e8d00(u64, u64);

// 0x71008196c0
void Unk_8196c0_call(const Unk_8196c0* self) {
    Unk_7e8d00(self->field_30, self->field_40);
}

struct Unk_7ca1c0;
struct Unk_819790 {
    Unk_7ca1c0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_819790, field_0, 0x0);

u32 Unk_7ca1c0_getField150(const Unk_7ca1c0*);

// 0x7100819790
void Unk_819790_call(const Unk_819790* self) {
    Unk_7ca1c0_getField150(self->field_0);
}

struct Unk_8197a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8197a0, field_0, 0x0);

void Unk_7cc000(u64);

// 0x71008197a0
void Unk_8197a0_call(const Unk_8197a0* self) {
    Unk_7cc000(self->field_0);
}

struct Unk_8197e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8197e0, field_0, 0x0);

void Unk_7cc030(u64);

// 0x71008197e0
void Unk_8197e0_call(const Unk_8197e0* self) {
    Unk_7cc030(self->field_0);
}

struct Unk_8197f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8197f0, field_0, 0x0);

void Unk_7cbf80(u64);

// 0x71008197f0
void Unk_8197f0_call(const Unk_8197f0* self) {
    Unk_7cbf80(self->field_0);
}

struct Unk_819800 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_819800, field_0, 0x0);

void Unk_7cbf80(u64);

// 0x7100819800
void Unk_819800_call(const Unk_819800* self) {
    Unk_7cbf80(self->field_0);
}

struct Unk_7caf40;
struct Unk_819830 {
    Unk_7caf40* field_0;
};
PKMN_OFFSET_ASSERT(Unk_819830, field_0, 0x0);

u8* Unk_7caf40_get(const Unk_7caf40*);

// 0x7100819830
void Unk_819830_call(const Unk_819830* self) {
    Unk_7caf40_get(self->field_0);
}

struct Unk_819910 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_819910, field_10, 0x10);

void Unk_82cff0(u64, u64, u32);

// 0x7100819910
void Unk_819910_call(const Unk_819910* self, u64 value, bool arg2) {
    Unk_82cff0(self->field_10, value, arg2);
}

struct Unk_7fe270;
struct Unk_819920 {
    u8 _0[0x8];
    Unk_7fe270* field_8;
};
PKMN_OFFSET_ASSERT(Unk_819920, field_8, 0x8);

u64 Unk_7fe270_getFielde8(const Unk_7fe270*);

// 0x7100819920
void Unk_819920_call(const Unk_819920* self) {
    Unk_7fe270_getFielde8(self->field_8);
}

struct Unk_7c58b0;
struct Unk_819930 {
    Unk_7c58b0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_819930, field_0, 0x0);

u32 Unk_7c58b0_get(const Unk_7c58b0*);

// 0x7100819930
void Unk_819930_call(const Unk_819930* self) {
    Unk_7c58b0_get(self->field_0);
}

struct Unk_819940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_819940, field_0, 0x0);

void Unk_7cb320(u64);

// 0x7100819940
void Unk_819940_call(const Unk_819940* self) {
    Unk_7cb320(self->field_0);
}

struct Unk_7ca9e0;
struct Unk_819960 {
    Unk_7ca9e0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_819960, field_0, 0x0);

u32 Unk_7ca9e0_get(const Unk_7ca9e0*);

// 0x7100819960
void Unk_819960_call(const Unk_819960* self) {
    Unk_7ca9e0_get(self->field_0);
}

struct Unk_819a10 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_819a10, field_40, 0x40);

void Unk_7e9a30(u64);

// 0x7100819a10
void Unk_819a10_call(const Unk_819a10* self) {
    Unk_7e9a30(self->field_40);
}

struct Unk_84f450;
struct Unk_819a20 {
    u8 _0[0x18];
    Unk_84f450* field_18;
};
PKMN_OFFSET_ASSERT(Unk_819a20, field_18, 0x18);

bool Unk_84f450_check(const Unk_84f450*);

// 0x7100819a20
void Unk_819a20_call(const Unk_819a20* self) {
    Unk_84f450_check(self->field_18);
}

struct Unk_819a60 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_819a60, field_10, 0x10);

void Unk_82cd00(u64);

// 0x7100819a60
void Unk_819a60_call(const Unk_819a60* self) {
    Unk_82cd00(self->field_10);
}

struct Unk_7e9aa0;
struct Unk_819a70 {
    u8 _0[0x40];
    Unk_7e9aa0* field_40;
};
PKMN_OFFSET_ASSERT(Unk_819a70, field_40, 0x40);

void Unk_7e9aa0_set(Unk_7e9aa0*);

// 0x7100819a70
void Unk_819a70_call(const Unk_819a70* self) {
    Unk_7e9aa0_set(self->field_40);
}

struct Unk_7caf50;
struct Unk_81a3b0 {
    Unk_7caf50* field_0;
};
PKMN_OFFSET_ASSERT(Unk_81a3b0, field_0, 0x0);

u8 Unk_7caf50_get(const Unk_7caf50*);

// 0x710081a3b0
void Unk_81a3b0_call(const Unk_81a3b0* self) {
    Unk_7caf50_get(self->field_0);
}

struct Unk_81a670 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_81a670, field_8, 0x8);

void Unk_7fe3b0(u64);

// 0x710081a670
void Unk_81a670_call(const Unk_81a670* self) {
    Unk_7fe3b0(self->field_8);
}

struct Unk_81be90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_81be90, field_0, 0x0);

void Unk_7cce80(u64);

// 0x710081be90
void Unk_81be90_call(const Unk_81be90* self) {
    Unk_7cce80(self->field_0);
}

struct Unk_81c3a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_81c3a0, field_0, 0x0);

void Unk_7cab30(u64);

// 0x710081c3a0
void Unk_81c3a0_call(const Unk_81c3a0* self) {
    Unk_7cab30(self->field_0);
}

struct Unk_27cefc4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cefc4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cefc4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cefc4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cefc4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cefc4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cefc4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cefc4_Data, field_18, 0x18);

extern Unk_27cefc4_Data Unk_27cefc4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710081c3b0
void Unk_81c3b0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cefc4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cefc4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cefc4.field_18 = 0xffff;
    Unk_27cefc4.field_10 = 0;
    Unk_27cefc4.field_8 = r2;
    Unk_27cefc4.field_c = 0;
    Unk_27cefc4.field_14 = 0xffffffff;
}
