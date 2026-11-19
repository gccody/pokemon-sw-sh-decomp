// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7b4bb0_5e0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_7b4bb0_5e0, field_58, 0x58);

struct Unk_7b4bb0 {
    u8 _0[0x5e0];
    Unk_7b4bb0_5e0* field_5e0;
    u64 field_5e8;
};
PKMN_OFFSET_ASSERT(Unk_7b4bb0, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_7b4bb0, field_5e8, 0x5e8);

void Unk_14e6550(u64, void*, u32, u32);

// 0x71007b4bb0
void Unk_7b4bb0_call(const Unk_7b4bb0* self, bool value) {
    u64 l8;
    self->field_5e0->field_58 = (self->field_5e0->field_58 & 0xfffffffe) | value;
    if (value != 0) {
        u64 v0 = self->field_5e8;
        l8 = 0;
        Unk_14e6550(v0, &l8, 1, 0);
    }
}

struct Unk_7b5d90_0_5d8 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7b5d90_0_5d8, field_18, 0x18);

struct Unk_7b5d90_0 {
    u8 _0[0x5d8];
    Unk_7b5d90_0_5d8* field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_7b5d90_0, field_5d8, 0x5d8);

struct Unk_7b5d90_arg1 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7b5d90_arg1, field_4, 0x4);

struct Unk_7b5d90 {
    Unk_7b5d90_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5d90, field_0, 0x0);

// 0x71007b5d90
void Unk_7b5d90_set(const Unk_7b5d90* self, const Unk_7b5d90_arg1* value) {
    self->field_0->field_5d8->field_18 = value->field_4;
}

// 0x71007b5db0
void Unk_7b5db0_update() {}

struct Unk_7b5dc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5dc0_arg1, field_0, 0x0);

struct Unk_7b5dc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5dc0, field_0, 0x0);

// 0x71007b5dc0
void Unk_7b5dc0_set(const Unk_7b5dc0* self, Unk_7b5dc0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7b5dd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5dd0_arg1, field_0, 0x0);

struct Unk_7b5dd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5dd0, field_0, 0x0);

// 0x71007b5dd0
void Unk_7b5dd0_set(const Unk_7b5dd0* self, Unk_7b5dd0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007bada0
void Unk_7bada0_update() {}

struct Unk_7badb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7badb0_arg1, field_0, 0x0);

struct Unk_7badb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7badb0, field_0, 0x0);

// 0x71007badb0
void Unk_7badb0_set(const Unk_7badb0* self, Unk_7badb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7badc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7badc0_arg1, field_0, 0x0);

struct Unk_7badc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7badc0, field_0, 0x0);

// 0x71007badc0
void Unk_7badc0_set(const Unk_7badc0* self, Unk_7badc0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27ceabc_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27ceabc_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ceabc_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ceabc_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ceabc_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27ceabc_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ceabc_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ceabc_Data, field_18, 0x18);

extern Unk_27ceabc_Data Unk_27ceabc __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71007bf590
void Unk_7bf590_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ceabc.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ceabc.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ceabc.field_18 = 0xffff;
    Unk_27ceabc.field_10 = 0;
    Unk_27ceabc.field_8 = r2;
    Unk_27ceabc.field_c = 0;
    Unk_27ceabc.field_14 = 0xffffffff;
}
