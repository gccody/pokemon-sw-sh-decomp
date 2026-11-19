// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100f7ae70
void Unk_f7ae70_update() {}

struct Unk_f7ae80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7ae80_arg1, field_0, 0x0);

struct Unk_f7ae80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7ae80, field_0, 0x0);

// 0x7100f7ae80
void Unk_f7ae80_set(const Unk_f7ae80* self, Unk_f7ae80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7ae90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7ae90_arg1, field_0, 0x0);

struct Unk_f7ae90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7ae90, field_0, 0x0);

// 0x7100f7ae90
void Unk_f7ae90_set(const Unk_f7ae90* self, Unk_f7ae90_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f7afa0
void Unk_f7afa0_update() {}

struct Unk_f7afb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7afb0_arg1, field_0, 0x0);

struct Unk_f7afb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7afb0, field_0, 0x0);

// 0x7100f7afb0
void Unk_f7afb0_set(const Unk_f7afb0* self, Unk_f7afb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7afc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7afc0_arg1, field_0, 0x0);

struct Unk_f7afc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7afc0, field_0, 0x0);

// 0x7100f7afc0
void Unk_f7afc0_set(const Unk_f7afc0* self, Unk_f7afc0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f7c100
void Unk_f7c100_update() {}

struct Unk_f7c110_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c110_arg1, field_0, 0x0);

struct Unk_f7c110 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c110, field_0, 0x0);

// 0x7100f7c110
void Unk_f7c110_set(const Unk_f7c110* self, Unk_f7c110_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7c120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c120_arg1, field_0, 0x0);

struct Unk_f7c120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c120, field_0, 0x0);

// 0x7100f7c120
void Unk_f7c120_set(const Unk_f7c120* self, Unk_f7c120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7c130_0 {
    u8 _0[0x2a0];
    u8 field_2a0;
    u8 _2a1[0x3];
    u32 field_2a4;
};
PKMN_OFFSET_ASSERT(Unk_f7c130_0, field_2a0, 0x2a0);
PKMN_OFFSET_ASSERT(Unk_f7c130_0, field_2a4, 0x2a4);

struct Unk_f7c130 {
    Unk_f7c130_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c130, field_0, 0x0);

void Unk_f7de70(void*);

// 0x7100f7c130
void Unk_f7c130_call(const Unk_f7c130* self) {
    Unk_f7c130_0* p0 = self->field_0;
    Unk_f7de70(p0);
    p0->field_2a4 = 9;
    p0->field_2a0 = 1;
}

// 0x7100f7c170
void Unk_f7c170_update() {}

struct Unk_f7c180_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c180_arg1, field_0, 0x0);

struct Unk_f7c180 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c180, field_0, 0x0);

// 0x7100f7c180
void Unk_f7c180_set(const Unk_f7c180* self, Unk_f7c180_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7c190_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c190_arg1, field_0, 0x0);

struct Unk_f7c190 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c190, field_0, 0x0);

// 0x7100f7c190
void Unk_f7c190_set(const Unk_f7c190* self, Unk_f7c190_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f7c380
void Unk_f7c380_update() {}

struct Unk_f7c390_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c390_arg1, field_0, 0x0);

struct Unk_f7c390 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c390, field_0, 0x0);

// 0x7100f7c390
void Unk_f7c390_set(const Unk_f7c390* self, Unk_f7c390_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7c3a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c3a0_arg1, field_0, 0x0);

struct Unk_f7c3a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c3a0, field_0, 0x0);

// 0x7100f7c3a0
void Unk_f7c3a0_set(const Unk_f7c3a0* self, Unk_f7c3a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f7c3d0
void Unk_f7c3d0_update() {}

struct Unk_f7c3e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c3e0_arg1, field_0, 0x0);

struct Unk_f7c3e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c3e0, field_0, 0x0);

// 0x7100f7c3e0
void Unk_f7c3e0_set(const Unk_f7c3e0* self, Unk_f7c3e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7c3f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c3f0_arg1, field_0, 0x0);

struct Unk_f7c3f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c3f0, field_0, 0x0);

// 0x7100f7c3f0
void Unk_f7c3f0_set(const Unk_f7c3f0* self, Unk_f7c3f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f7c500
void Unk_f7c500_update() {}

struct Unk_f7c6e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c6e0_arg1, field_0, 0x0);

struct Unk_f7c6e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c6e0, field_0, 0x0);

// 0x7100f7c6e0
void Unk_f7c6e0_set(const Unk_f7c6e0* self, Unk_f7c6e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7c6f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c6f0_arg1, field_0, 0x0);

struct Unk_f7c6f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7c6f0, field_0, 0x0);

// 0x7100f7c6f0
void Unk_f7c6f0_set(const Unk_f7c6f0* self, Unk_f7c6f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7cb20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7cb20, field_0, 0x0);

void Unk_f7dbe0(u64, u32);

// 0x7100f7cb20
void Unk_f7cb20_call(const Unk_f7cb20* self) {
    Unk_f7dbe0(self->field_0, 1);
}

// 0x7100f7cb30
void Unk_f7cb30_update() {}

struct Unk_f7cb40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7cb40_arg1, field_0, 0x0);

struct Unk_f7cb40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7cb40, field_0, 0x0);

// 0x7100f7cb40
void Unk_f7cb40_set(const Unk_f7cb40* self, Unk_f7cb40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f7cb50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7cb50_arg1, field_0, 0x0);

struct Unk_f7cb50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f7cb50, field_0, 0x0);

// 0x7100f7cb50
void Unk_f7cb50_set(const Unk_f7cb50* self, Unk_f7cb50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e1754_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e1754_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e1754_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e1754_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e1754_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e1754_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e1754_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e1754_Data, field_18, 0x18);

extern Unk_27e1754_Data Unk_27e1754 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f7cb60
void Unk_f7cb60_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e1754.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e1754.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e1754.field_18 = 0xffff;
    Unk_27e1754.field_10 = 0;
    Unk_27e1754.field_8 = r2;
    Unk_27e1754.field_c = 0;
    Unk_27e1754.field_14 = 0xffffffff;
}
