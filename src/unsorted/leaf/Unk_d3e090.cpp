// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d3e090 {
    u8 _0[0x650];
    u32 field_650;
    bool field_654;
};
PKMN_OFFSET_ASSERT(Unk_d3e090, field_650, 0x650);
PKMN_OFFSET_ASSERT(Unk_d3e090, field_654, 0x654);

// 0x7100d3e090
void Unk_d3e090_set(Unk_d3e090* self, u32 value, bool arg2) {
    self->field_650 = value;
    self->field_654 = arg2;
}

void Unk_cf2010(void*);

// 0x7100d42e80
void Unk_d42e80_call(void* self) {
    Unk_cf2010(self);
}

struct Unk_d45b60 {
    u8 _0[0x7e8];
    u32 field_7e8;
};
PKMN_OFFSET_ASSERT(Unk_d45b60, field_7e8, 0x7e8);

// 0x7100d45b60
bool Unk_d45b60_check(const Unk_d45b60* self) {
    return self->field_7e8 != 0;
}

// 0x7100d496b0
void Unk_d496b0_update() {}

struct Unk_d49820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49820_arg1, field_0, 0x0);

struct Unk_d49820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49820, field_0, 0x0);

// 0x7100d49820
void Unk_d49820_set(const Unk_d49820* self, Unk_d49820_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d49830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49830_arg1, field_0, 0x0);

struct Unk_d49830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49830, field_0, 0x0);

// 0x7100d49830
void Unk_d49830_set(const Unk_d49830* self, Unk_d49830_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100d498f0
void Unk_d498f0_update() {}

struct Unk_d49900_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49900_arg1, field_0, 0x0);

struct Unk_d49900 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49900, field_0, 0x0);

// 0x7100d49900
void Unk_d49900_set(const Unk_d49900* self, Unk_d49900_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d49910_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49910_arg1, field_0, 0x0);

struct Unk_d49910 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49910, field_0, 0x0);

// 0x7100d49910
void Unk_d49910_set(const Unk_d49910* self, Unk_d49910_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100d49970
void Unk_d49970_update() {}

struct Unk_d49980_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49980_arg1, field_0, 0x0);

struct Unk_d49980 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49980, field_0, 0x0);

// 0x7100d49980
void Unk_d49980_set(const Unk_d49980* self, Unk_d49980_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d49990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49990_arg1, field_0, 0x0);

struct Unk_d49990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49990, field_0, 0x0);

// 0x7100d49990
void Unk_d49990_set(const Unk_d49990* self, Unk_d49990_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d49b70_0 {
    u8 _0[0x4ac];
    u8 field_4ac;
};
PKMN_OFFSET_ASSERT(Unk_d49b70_0, field_4ac, 0x4ac);

struct Unk_d49b70 {
    Unk_d49b70_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49b70, field_0, 0x0);

// 0x7100d49b70
void Unk_d49b70_set(const Unk_d49b70* self) {
    self->field_0->field_4ac = 1;
}

// 0x7100d49b80
void Unk_d49b80_update() {}

struct Unk_d49b90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49b90_arg1, field_0, 0x0);

struct Unk_d49b90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49b90, field_0, 0x0);

// 0x7100d49b90
void Unk_d49b90_set(const Unk_d49b90* self, Unk_d49b90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d49ba0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49ba0_arg1, field_0, 0x0);

struct Unk_d49ba0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d49ba0, field_0, 0x0);

// 0x7100d49ba0
void Unk_d49ba0_set(const Unk_d49ba0* self, Unk_d49ba0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100d49d30
void Unk_d49d30_update() {}

struct Unk_d49d40 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d49d40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d49d40, field_8, 0x8);

// 0x7100d49d40
void Unk_d49d40_set(const Unk_d49d40* self, Unk_d49d40* value) {
    *value = *self;
}

struct Unk_d49d50 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d49d50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d49d50, field_8, 0x8);

// 0x7100d49d50
void Unk_d49d50_set(const Unk_d49d50* self, Unk_d49d50* value) {
    *value = *self;
}

// 0x7100d49e00
void Unk_d49e00_update() {}

struct Unk_d49e10 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d49e10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d49e10, field_8, 0x8);

// 0x7100d49e10
void Unk_d49e10_set(const Unk_d49e10* self, Unk_d49e10* value) {
    *value = *self;
}

struct Unk_d49e20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d49e20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d49e20, field_8, 0x8);

// 0x7100d49e20
void Unk_d49e20_set(const Unk_d49e20* self, Unk_d49e20* value) {
    *value = *self;
}

struct Unk_d4a340_arg1 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_d4a340_arg1, field_90, 0x90);

// 0x7100d4a340
bool Unk_d4a340_check(void* /*unused*/, const Unk_d4a340_arg1* value) {
    return value->field_90 == 1;
}

// 0x7100d4a350
void Unk_d4a350_update() {}

// 0x7100d4a360
void Unk_d4a360_update() {}

// 0x7100d4a370
void Unk_d4a370_update() {}

// 0x7100d4a9b0
u32 Unk_d4a9b0_get() {
    return 1;
}

// 0x7100d4a9c0
void Unk_d4a9c0_update() {}

// 0x7100d4a9d0
void Unk_d4a9d0_update() {}

// 0x7100d4a9e0
void Unk_d4a9e0_update() {}

struct Unk_27dca2c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dca2c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dca2c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dca2c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dca2c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dca2c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dca2c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dca2c_Data, field_18, 0x18);

extern Unk_27dca2c_Data Unk_27dca2c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d4ca40
void Unk_d4ca40_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dca2c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dca2c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dca2c.field_18 = 0xffff;
    Unk_27dca2c.field_10 = 0;
    Unk_27dca2c.field_8 = r2;
    Unk_27dca2c.field_c = 0;
    Unk_27dca2c.field_14 = 0xffffffff;
}
