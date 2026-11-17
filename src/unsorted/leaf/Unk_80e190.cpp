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
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_80e2a0, field_18, 0x18);

void Unk_816500(u64, u32, u32, u32, u32, u32, u32, u32);

// 0x710080e2a0
void Unk_80e2a0_call(const Unk_80e2a0* self, u32 value, u32 arg2, u32 arg3, bool arg4, u32 arg5) {
    Unk_816500(self->field_18, arg5, 0xb8, value & 0xff, 0, arg2 & 0xffff, arg3 & 0xff, arg4);
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
