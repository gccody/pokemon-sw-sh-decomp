// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71007f8780
u32 Unk_7f8780_get() {
    return 0xf8;
}

struct Unk_7f8790 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7f8790, field_0, 0x0);

// 0x71007f8790
bool Unk_7f8790_check(const Unk_7f8790* self) {
    return (self->field_0 & 7) == 0;
}

struct Unk_7f88c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7f88c0, field_0, 0x0);

// 0x71007f88c0
bool Unk_7f88c0_check(const Unk_7f88c0* self) {
    return (self->field_0 & 0x3f07) == 0xf01;
}

struct Unk_7f8b70 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7f8b70, field_0, 0x0);

// 0x71007f8b70
u32 Unk_7f8b70_get(const Unk_7f8b70* self) {
    return (self->field_0 >> 3) & 0x1f;
}

struct Unk_7f8ce0 {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7f8ce0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7f8ce0, field_4, 0x4);

// 0x71007f8ce0
void Unk_7f8ce0_set(Unk_7f8ce0* self) {
    self->field_0 = 0;
    self->field_4 = 5;
}

struct Unk_7f8cf0 {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7f8cf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7f8cf0, field_4, 0x4);

// 0x71007f8cf0
void Unk_7f8cf0_set(Unk_7f8cf0* self, u32 value, u8 arg2) {
    self->field_0 = value;
    self->field_4 = arg2;
}

struct Unk_7f8d00_arg1 {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7f8d00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7f8d00_arg1, field_4, 0x4);

struct Unk_7f8d00 {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7f8d00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7f8d00, field_4, 0x4);

// 0x71007f8d00
void Unk_7f8d00_set(Unk_7f8d00* self, const Unk_7f8d00_arg1* value) {
    self->field_0 = value->field_0;
    self->field_4 = value->field_4;
}

// 0x71007fc160
bool Unk_7fc160_check(void* /*unused*/, u32 value) {
    return (value | 1) == 3;
}

// 0x71007fc180
u32 Unk_7fc180_get() {
    return 1;
}

struct Unk_7fc1c0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7fc1c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7fc1c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7fc1c0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7fc1c0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_7fc1c0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_7fc1c0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_7fc1c0, field_30, 0x30);

// 0x71007fc1c0
void Unk_7fc1c0_set(Unk_7fc1c0* self) {
    self->field_30 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

// 0x71007fc1e0
void Unk_7fc1e0() {}

struct Unk_7fc1f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7fc1f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7fc1f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7fc1f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7fc1f0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_7fc1f0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_7fc1f0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_7fc1f0, field_30, 0x30);

// 0x71007fc1f0
void Unk_7fc1f0_set(Unk_7fc1f0* self) {
    self->field_30 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

struct Unk_7fc2e0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7fc2e0, field_30, 0x30);

// 0x71007fc2e0
u8 Unk_7fc2e0_getField30(const Unk_7fc2e0* self) {
    return self->field_30;
}

struct Unk_27ced74_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27ced74_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ced74_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ced74_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ced74_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27ced74_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ced74_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ced74_Data, field_18, 0x18);

extern Unk_27ced74_Data Unk_27ced74 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71007fc6c0
void Unk_7fc6c0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ced74.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ced74.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ced74.field_18 = 0xffff;
    Unk_27ced74.field_10 = 0;
    Unk_27ced74.field_8 = r2;
    Unk_27ced74.field_c = 0;
    Unk_27ced74.field_14 = 0xffffffff;
}
