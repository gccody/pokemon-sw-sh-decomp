// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1475be0 {
    u8 _0[0x600];
    u64 field_600;
};
PKMN_OFFSET_ASSERT(Unk_1475be0, field_600, 0x600);

void Unk_14e1a00(u64, u32);

// 0x7101475be0
void Unk_1475be0_call(const Unk_1475be0* self, bool value) {
    Unk_14e1a00(self->field_600, value);
}

struct Unk_1476870 {
    u8 _0[0x684];
    u32 field_684;
};
PKMN_OFFSET_ASSERT(Unk_1476870, field_684, 0x684);

// 0x7101476870
void Unk_1476870_set(Unk_1476870* self, u32 value) {
    self->field_684 = value;
}

struct Unk_1476880 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_1476880, field_5d0, 0x5d0);

void Unk_1459dd0(u64);

// 0x7101476880
void Unk_1476880_call(const Unk_1476880* self) {
    Unk_1459dd0(self->field_5d0);
}

struct Unk_1476c80_0 {
    u8 _0[0x68c];
    u32 field_68c;
};
PKMN_OFFSET_ASSERT(Unk_1476c80_0, field_68c, 0x68c);

struct Unk_1476c80 {
    Unk_1476c80_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476c80, field_0, 0x0);

// 0x7101476c80
void Unk_1476c80_set(const Unk_1476c80* self) {
    self->field_0->field_68c = 1;
}

// 0x7101476c90
void Unk_1476c90_update() {}

struct Unk_1476ca0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476ca0_arg1, field_0, 0x0);

struct Unk_1476ca0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476ca0, field_0, 0x0);

// 0x7101476ca0
void Unk_1476ca0_set(const Unk_1476ca0* self, Unk_1476ca0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1476cb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476cb0_arg1, field_0, 0x0);

struct Unk_1476cb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476cb0, field_0, 0x0);

// 0x7101476cb0
void Unk_1476cb0_set(const Unk_1476cb0* self, Unk_1476cb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1476cc0_0 {
    u8 _0[0x68c];
    u32 field_68c;
};
PKMN_OFFSET_ASSERT(Unk_1476cc0_0, field_68c, 0x68c);

struct Unk_1476cc0 {
    Unk_1476cc0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476cc0, field_0, 0x0);

// 0x7101476cc0
void Unk_1476cc0_set(const Unk_1476cc0* self) {
    self->field_0->field_68c = 2;
}

// 0x7101476cd0
void Unk_1476cd0_update() {}

struct Unk_1476ce0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476ce0_arg1, field_0, 0x0);

struct Unk_1476ce0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476ce0, field_0, 0x0);

// 0x7101476ce0
void Unk_1476ce0_set(const Unk_1476ce0* self, Unk_1476ce0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1476cf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476cf0_arg1, field_0, 0x0);

struct Unk_1476cf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476cf0, field_0, 0x0);

// 0x7101476cf0
void Unk_1476cf0_set(const Unk_1476cf0* self, Unk_1476cf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1476d00_0 {
    u8 _0[0x68c];
    u32 field_68c;
};
PKMN_OFFSET_ASSERT(Unk_1476d00_0, field_68c, 0x68c);

struct Unk_1476d00 {
    Unk_1476d00_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476d00, field_0, 0x0);

// 0x7101476d00
void Unk_1476d00_set(const Unk_1476d00* self) {
    self->field_0->field_68c = 3;
}

// 0x7101476d10
void Unk_1476d10_update() {}

struct Unk_1476d20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476d20_arg1, field_0, 0x0);

struct Unk_1476d20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476d20, field_0, 0x0);

// 0x7101476d20
void Unk_1476d20_set(const Unk_1476d20* self, Unk_1476d20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1476d30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476d30_arg1, field_0, 0x0);

struct Unk_1476d30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1476d30, field_0, 0x0);

// 0x7101476d30
void Unk_1476d30_set(const Unk_1476d30* self, Unk_1476d30_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101476d70
void Unk_1476d70_update() {}

struct Unk_1476d80 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1476d80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1476d80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1476d80, field_10, 0x10);

// 0x7101476d80
void Unk_1476d80_set(const Unk_1476d80* self, Unk_1476d80* value) {
    *value = *self;
}

struct Unk_1476da0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1476da0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1476da0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1476da0, field_10, 0x10);

// 0x7101476da0
void Unk_1476da0_set(const Unk_1476da0* self, Unk_1476da0* value) {
    *value = *self;
}

struct Unk_1478790_0 {
    u8 _0[0x5cc];
    u32 field_5cc;
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_1478790_0, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_1478790_0, field_5d0, 0x5d0);

struct Unk_1478790 {
    Unk_1478790_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478790, field_0, 0x0);

void Unk_14e1a30(u64, u32);

// 0x7101478790
void Unk_1478790_call(const Unk_1478790* self) {
    Unk_1478790_0* p0 = self->field_0;
    p0->field_5cc = 0;
    Unk_14e1a30(p0->field_5d0, 0);
}

// 0x71014787b0
void Unk_14787b0_update() {}

struct Unk_14787c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14787c0_arg1, field_0, 0x0);

struct Unk_14787c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14787c0, field_0, 0x0);

// 0x71014787c0
void Unk_14787c0_set(const Unk_14787c0* self, Unk_14787c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14787d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14787d0_arg1, field_0, 0x0);

struct Unk_14787d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14787d0, field_0, 0x0);

// 0x71014787d0
void Unk_14787d0_set(const Unk_14787d0* self, Unk_14787d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14787e0_0 {
    u8 _0[0x5cc];
    u32 field_5cc;
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_14787e0_0, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_14787e0_0, field_5d0, 0x5d0);

struct Unk_14787e0 {
    Unk_14787e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_14787e0, field_0, 0x0);

void Unk_14e1a30(u64, u32);

// 0x71014787e0
void Unk_14787e0_call(const Unk_14787e0* self) {
    Unk_14787e0_0* p0 = self->field_0;
    p0->field_5cc = 1;
    Unk_14e1a30(p0->field_5d0, 0);
}

// 0x7101478800
void Unk_1478800_update() {}

struct Unk_1478810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478810_arg1, field_0, 0x0);

struct Unk_1478810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478810, field_0, 0x0);

// 0x7101478810
void Unk_1478810_set(const Unk_1478810* self, Unk_1478810_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1478820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478820_arg1, field_0, 0x0);

struct Unk_1478820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478820, field_0, 0x0);

// 0x7101478820
void Unk_1478820_set(const Unk_1478820* self, Unk_1478820_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1478830_0 {
    u8 _0[0x5cc];
    u32 field_5cc;
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_1478830_0, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_1478830_0, field_5d0, 0x5d0);

struct Unk_1478830 {
    Unk_1478830_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478830, field_0, 0x0);

void Unk_14e1a30(u64, u32);

// 0x7101478830
void Unk_1478830_call(const Unk_1478830* self) {
    Unk_1478830_0* p0 = self->field_0;
    p0->field_5cc = 2;
    Unk_14e1a30(p0->field_5d0, 0);
}

// 0x7101478850
void Unk_1478850_update() {}

struct Unk_1478860_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478860_arg1, field_0, 0x0);

struct Unk_1478860 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478860, field_0, 0x0);

// 0x7101478860
void Unk_1478860_set(const Unk_1478860* self, Unk_1478860_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1478870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478870_arg1, field_0, 0x0);

struct Unk_1478870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1478870, field_0, 0x0);

// 0x7101478870
void Unk_1478870_set(const Unk_1478870* self, Unk_1478870_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101479ec0
void Unk_1479ec0_update() {}

struct Unk_1479ed0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1479ed0_arg1, field_0, 0x0);

struct Unk_1479ed0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1479ed0, field_0, 0x0);

// 0x7101479ed0
void Unk_1479ed0_set(const Unk_1479ed0* self, Unk_1479ed0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1479ee0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1479ee0_arg1, field_0, 0x0);

struct Unk_1479ee0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1479ee0, field_0, 0x0);

// 0x7101479ee0
void Unk_1479ee0_set(const Unk_1479ee0* self, Unk_1479ee0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27f119c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f119c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f119c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f119c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f119c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f119c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f119c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f119c_Data, field_18, 0x18);

extern Unk_27f119c_Data Unk_27f119c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101482ab0
void Unk_1482ab0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f119c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f119c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f119c.field_18 = 0xffff;
    Unk_27f119c.field_10 = 0;
    Unk_27f119c.field_8 = r2;
    Unk_27f119c.field_c = 0;
    Unk_27f119c.field_14 = 0xffffffff;
}
