// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_80e190 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_80e190, field_18, 0x18);

void Unk_816320(u64, u32, u32, u32, u32, u32);

// 0x710080e190
void Unk_80e190_call(const Unk_80e190* self,
                     u32 value,
                     u64 /*unused*/,
                     u64 /*unused*/,
                     u32 arg4,
                     u32 arg5) {
    Unk_816320(self->field_18, 0xb9, value & 0xffff, 0xffff0000, arg4, arg5);
}

struct Unk_80e1b0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_80e1b0, field_18, 0x18);

void Unk_816320(u64, u32, u32, u32, u32, u32);

// 0x710080e1b0
void Unk_80e1b0_call(const Unk_80e1b0* self,
                     u32 value,
                     u32 arg2,
                     u64 /*unused*/,
                     u64 /*unused*/,
                     u32 arg5) {
    Unk_816320(self->field_18, 0xb9, value & 0xffff, arg2, 0xffff0000, arg5);
}

struct Unk_80e1d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_80e1d0, field_18, 0x18);

void Unk_816320(u64, u32, u32, u32, u32, u32);

// 0x710080e1d0
void Unk_80e1d0_call(const Unk_80e1d0* self, u32 value, u32 arg2, u32 arg3) {
    Unk_816320(self->field_18, 0xb9, value & 0xffff, arg2, arg3, 0xffff0000);
}

struct Unk_80e230 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_80e230, field_18, 0x18);

void Unk_816320(u64, u32, u32, u32, u32, u32);

// 0x710080e230
void Unk_80e230_call(const Unk_80e230* self,
                     u32 value,
                     u32 arg2,
                     u64 /*unused*/,
                     u64 /*unused*/,
                     u32 arg5) {
    Unk_816320(self->field_18, 0xba, value & 0xffff, arg2, 0xffff0000, arg5);
}

struct Unk_80e250 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_80e250, field_18, 0x18);

void Unk_816320(u64, u32, u32, u32, u32, u32);

// 0x710080e250
void Unk_80e250_call(const Unk_80e250* self, u32 value, u32 arg2, u32 arg3) {
    Unk_816320(self->field_18, 0xba, value & 0xffff, arg2, arg3, 0xffff0000);
}

struct Unk_80e2a0 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_80e2a0, field_18, 0x18);

void Unk_816500(void*, u32, u32, u32, u32, u32, u32, u32);

// 0x710080e2a0
void Unk_80e2a0_call(const Unk_80e2a0* self, u8 value, u16 arg2, u8 arg3, bool arg4, u32 arg5) {
    Unk_816500(self->field_18, arg5, 0xb8, value, 0, arg2, arg3, arg4);
}

struct Unk_80e820 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_80e820, field_18, 0x18);

void Unk_816320(u64, u32, u32, u32, u32, u32);

// 0x710080e820
void Unk_80e820_call(const Unk_80e820* self,
                     u64 /*unused*/,
                     u64 /*unused*/,
                     u64 /*unused*/,
                     u32 arg4,
                     u32 arg5) {
    Unk_816320(self->field_18, 0xb9, 0x55, 0xffff0000, arg4, arg5);
}

struct Unk_810a70 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_810a70, field_18, 0x18);
void Unk_8150c0(u64, u32, ...);

// 0x7100810a70
void Unk_810a70_update(const Unk_810a70* self, u8 value) {
    if (value == 0x1f) {
        return;
    }
    Unk_8150c0(self->field_18, 0xb6, value);
}

struct Unk_810ae0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_810ae0, field_18, 0x18);
void Unk_8150c0(u64, u32, ...);

// 0x7100810ae0
void Unk_810ae0_update(const Unk_810ae0* self, u8 value) {
    if (value == 0x1f) {
        return;
    }
    Unk_8150c0(self->field_18, 0xb7, value);
}

struct Unk_27cef34_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cef34_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cef34_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cef34_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cef34_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cef34_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cef34_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cef34_Data, field_18, 0x18);

extern Unk_27cef34_Data Unk_27cef34 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100812b50
void Unk_812b50_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cef34.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cef34.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cef34.field_18 = 0xffff;
    Unk_27cef34.field_10 = 0;
    Unk_27cef34.field_8 = r2;
    Unk_27cef34.field_c = 0;
    Unk_27cef34.field_14 = 0xffffffff;
}
