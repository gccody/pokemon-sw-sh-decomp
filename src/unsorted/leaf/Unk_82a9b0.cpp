// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82a9b0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_82a9b0, field_8, 0x8);

// 0x710082a9b0
u64 Unk_82a9b0_getField8(const Unk_82a9b0* self) {
    return self->field_8;
}

struct Unk_82a9c0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_82a9c0, field_10, 0x10);

// 0x710082a9c0
u64 Unk_82a9c0_getField10(const Unk_82a9c0* self) {
    return self->field_10;
}

struct Unk_82a9d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_82a9d0, field_18, 0x18);

// 0x710082a9d0
u64 Unk_82a9d0_getField18(const Unk_82a9d0* self) {
    return self->field_18;
}

struct Unk_82a9e0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_82a9e0, field_20, 0x20);

// 0x710082a9e0
u64 Unk_82a9e0_getField20(const Unk_82a9e0* self) {
    return self->field_20;
}

struct Unk_82a9f0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_82a9f0, field_28, 0x28);

// 0x710082a9f0
u64 Unk_82a9f0_getField28(const Unk_82a9f0* self) {
    return self->field_28;
}

struct Unk_82aa00 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_82aa00, field_30, 0x30);

// 0x710082aa00
u64 Unk_82aa00_getField30(const Unk_82aa00* self) {
    return self->field_30;
}

struct Unk_82aa10 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_82aa10, field_38, 0x38);

// 0x710082aa10
u64 Unk_82aa10_getField38(const Unk_82aa10* self) {
    return self->field_38;
}

struct Unk_82aa20 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_82aa20, field_40, 0x40);

// 0x710082aa20
u64 Unk_82aa20_getField40(const Unk_82aa20* self) {
    return self->field_40;
}

struct Unk_82b4f0;
struct Unk_82aa30 {
    u8 _0[0x40];
    Unk_82b4f0* field_40;
};
PKMN_OFFSET_ASSERT(Unk_82aa30, field_40, 0x40);

u64 Unk_82b4f0_getField8(const Unk_82b4f0*);
void Unk_82afd0();

// 0x710082aa30
void Unk_82aa30_call(const Unk_82aa30* self) {
    Unk_82b4f0_getField8(self->field_40);
    Unk_82afd0();
}

struct Unk_82aa50 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_82aa50, field_48, 0x48);

// 0x710082aa50
u64 Unk_82aa50_getField48(const Unk_82aa50* self) {
    return self->field_48;
}

struct Unk_82aa60 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_82aa60, field_50, 0x50);

// 0x710082aa60
u64 Unk_82aa60_getField50(const Unk_82aa60* self) {
    return self->field_50;
}

struct Unk_82aa70 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_82aa70, field_58, 0x58);

// 0x710082aa70
u64 Unk_82aa70_getField58(const Unk_82aa70* self) {
    return self->field_58;
}

struct Unk_82aa80 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_82aa80, field_60, 0x60);

// 0x710082aa80
u64 Unk_82aa80_getField60(const Unk_82aa80* self) {
    return self->field_60;
}

struct Unk_82ac10 {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ac10, field_8, 0x8);

void Unk_7cc000(void*, u8);

// 0x710082ac10
void Unk_82ac10_call(const Unk_82ac10* self, u32 value) {
    Unk_7cc000(self->field_8, value);
}

struct Unk_7ca1c0;
struct Unk_82ac50 {
    u8 _0[0x8];
    Unk_7ca1c0* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ac50, field_8, 0x8);

u32 Unk_7ca1c0_getField150(const Unk_7ca1c0*);

// 0x710082ac50
void Unk_82ac50_call(const Unk_82ac50* self) {
    Unk_7ca1c0_getField150(self->field_8);
}

struct Unk_7ca890;
struct Unk_82ac60 {
    u8 _0[0x8];
    Unk_7ca890* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ac60, field_8, 0x8);

u8 Unk_7ca890_get(const Unk_7ca890*);

// 0x710082ac60
void Unk_82ac60_call(const Unk_82ac60* self) {
    Unk_7ca890_get(self->field_8);
}

struct Unk_7c58b0;
struct Unk_82ac70 {
    u8 _0[0x8];
    Unk_7c58b0* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ac70, field_8, 0x8);

u32 Unk_7c58b0_get(const Unk_7c58b0*);

// 0x710082ac70
void Unk_82ac70_call(const Unk_82ac70* self) {
    Unk_7c58b0_get(self->field_8);
}

struct Unk_7c4c70;
struct Unk_82ac80 {
    u8 _0[0x8];
    Unk_7c4c70* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ac80, field_8, 0x8);

u8 Unk_7c4c70_get(const Unk_7c4c70*);

// 0x710082ac80
bool Unk_82ac80_call(const Unk_82ac80* self) {
    u8 r0 = Unk_7c4c70_get(self->field_8);
    return (r0 & 0xff) != 0;
}

struct Unk_82ad00 {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ad00, field_8, 0x8);

void Unk_7cbf80(void*, u8, u8);

// 0x710082ad00
void Unk_82ad00_call(const Unk_82ad00* self, u32 value, u32 arg2) {
    Unk_7cbf80(self->field_8, value, arg2);
}

struct Unk_82ad10 {
    u8 _0[0x8];
    void* field_8;
    void* field_10;
};
PKMN_OFFSET_ASSERT(Unk_82ad10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82ad10, field_10, 0x10);

void Unk_80d4b0(void*, void*);

// 0x710082ad10
void Unk_82ad10_call(const Unk_82ad10* self) {
    Unk_80d4b0(self->field_8, self->field_10);
}

struct Unk_82ad20 {
    u8 _0[0x8];
    void* field_8;
    void* field_10;
};
PKMN_OFFSET_ASSERT(Unk_82ad20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82ad20, field_10, 0x10);

void Unk_80d700(void*, void*, u32);

// 0x710082ad20
void Unk_82ad20_call(const Unk_82ad20* self, u32 value) {
    Unk_80d700(self->field_8, self->field_10, value);
}

struct Unk_82ad30 {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ad30, field_8, 0x8);

void Unk_80d8f0(void*);

// 0x710082ad30
void Unk_82ad30_call(const Unk_82ad30* self) {
    Unk_80d8f0(self->field_8);
}

void Unk_80d910(u32);

// 0x710082ad40
void Unk_82ad40_call(void* /*unused*/, u32 value) {
    Unk_80d910(value);
}

struct Unk_82ad50 {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ad50, field_8, 0x8);

void Unk_80d940_call(void*, void*);

// 0x710082ad50
void Unk_82ad50_call(const Unk_82ad50* self, void* value) {
    Unk_80d940_call(self->field_8, value);
}

struct Unk_82ad60 {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ad60, field_8, 0x8);

void Unk_80d950(void*, void*);

// 0x710082ad60
void Unk_82ad60_call(const Unk_82ad60* self, void* value) {
    Unk_80d950(self->field_8, value);
}

struct Unk_82adb0 {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82adb0, field_8, 0x8);

void Unk_80d980(void*, void*);

// 0x710082adb0
void Unk_82adb0_call(const Unk_82adb0* self, void* value) {
    Unk_80d980(self->field_8, value);
}

struct Unk_7fe250;
struct Unk_82adc0 {
    u8 _0[0x8];
    u64 field_8;
    Unk_7fe250* field_10;
};
PKMN_OFFSET_ASSERT(Unk_82adc0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82adc0, field_10, 0x10);

u64 Unk_7fe250_getFielda8(const Unk_7fe250*);
void Unk_80d9c0(u64, u64, u64, u64);

// 0x710082adc0
void Unk_82adc0_call(const Unk_82adc0* self, u64 value, u64 arg2) {
    u64 v0 = self->field_8;
    u64 r0 = Unk_7fe250_getFielda8(self->field_10);
    Unk_80d9c0(v0, value, arg2, r0);
}

struct Unk_82ae20 {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_82ae20, field_8, 0x8);

void Unk_80daf0(void*, u32);

// 0x710082ae20
void Unk_82ae20_call(const Unk_82ae20* self, u32 value) {
    Unk_80daf0(self->field_8, value);
}

void Unk_80db30(void*);

// 0x710082ae30
void Unk_82ae30_call(void* /*unused*/, void* value) {
    Unk_80db30(value);
}

struct Unk_27cf0c4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cf0c4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cf0c4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cf0c4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cf0c4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cf0c4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cf0c4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cf0c4_Data, field_18, 0x18);

extern Unk_27cf0c4_Data Unk_27cf0c4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710082ae80
void Unk_82ae80_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cf0c4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cf0c4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cf0c4.field_18 = 0xffff;
    Unk_27cf0c4.field_10 = 0;
    Unk_27cf0c4.field_8 = r2;
    Unk_27cf0c4.field_c = 0;
    Unk_27cf0c4.field_14 = 0xffffffff;
}
