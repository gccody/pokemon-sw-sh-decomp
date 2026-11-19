// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_1458120 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1458120, field_58, 0x58);

void Unk_1458130(void*);

// 0x7101458120
void Unk_1458120_call(const Unk_1458120* self) {
    Unk_1458130(self->field_58);
}

struct Unk_1458300_58 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1458300_58, field_18, 0x18);

struct Unk_1458300 {
    u8 _0[0x58];
    Unk_1458300_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1458300, field_58, 0x58);

// 0x7101458300
void Unk_1458300_set(const Unk_1458300* self, u64 value) {
    self->field_58->field_18 = value;
}

struct Unk_1458470_58 {
    u8 _0[0x44];
    u32 field_44;
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_1458470_58, field_44, 0x44);
PKMN_OFFSET_ASSERT(Unk_1458470_58, field_48, 0x48);

struct Unk_1458470 {
    u8 _0[0x58];
    Unk_1458470_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1458470, field_58, 0x58);

// 0x7101458470
void Unk_1458470_set(const Unk_1458470* self, u32 value, u32 arg2) {
    Unk_1458470_58* p0 = self->field_58;
    p0->field_44 = value;
    p0->field_48 = arg2;
}

struct Unk_1459ac0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1459ac0, field_58, 0x58);

void Unk_1459ad0(void*, void*);

// 0x7101459ac0
void Unk_1459ac0_call(const Unk_1459ac0* self, void* value) {
    Unk_1459ad0(self->field_58, value);
}

struct Unk_1459d60 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1459d60, field_58, 0x58);

void Unk_145a440(u64);
void Unk_145a5d0(u64);
void Unk_145a6d0(u64);
void Unk_145a820(u64);
void Unk_145a970(u64);
void Unk_145ab10(u64);
void Unk_145ac90(u64);
void Unk_145ae10(u64);
void Unk_145af90(u64);
void Unk_145b110(u64);
void Unk_145b290(u64);

// 0x7101459d60
void Unk_1459d60_call(const Unk_1459d60* self) {
    u64 v0 = self->field_58;
    Unk_145a440(v0);
    Unk_145a5d0(v0);
    Unk_145a6d0(v0);
    Unk_145a820(v0);
    Unk_145a970(v0);
    Unk_145ab10(v0);
    Unk_145ac90(v0);
    Unk_145ae10(v0);
    Unk_145af90(v0);
    Unk_145b110(v0);
    Unk_145b290(v0);
}

struct Unk_1459f50 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1459f50, field_58, 0x58);

void Unk_1459f60(void*, void*);

// 0x7101459f50
void Unk_1459f50_call(const Unk_1459f50* self, void* value) {
    Unk_1459f60(self->field_58, value);
}

// 0x710145b760
void Unk_145b760_update() {}

struct Unk_145b770 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_145b770, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_145b770, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_145b770, field_10, 0x10);

// 0x710145b770
void Unk_145b770_set(const Unk_145b770* self, Unk_145b770* value) {
    *value = *self;
}

struct Unk_145b790 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_145b790, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_145b790, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_145b790, field_10, 0x10);

// 0x710145b790
void Unk_145b790_set(const Unk_145b790* self, Unk_145b790* value) {
    *value = *self;
}

struct Unk_145f0b0_0 {
    u8 _0[0x5e0];
    u64 field_5e0;
    u8 _5e8[0x18];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_145f0b0_0, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_145f0b0_0, field_600, 0x600);

struct Unk_145f0b0 {
    Unk_145f0b0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f0b0, field_0, 0x0);

void Unk_14e1a30(u64, u32);

// 0x710145f0b0
void Unk_145f0b0_call(const Unk_145f0b0* self) {
    Unk_145f0b0_0* p0 = self->field_0;
    p0->field_600 = 1;
    Unk_14e1a30(p0->field_5e0, 0);
}

// 0x710145f0d0
void Unk_145f0d0_update() {}

struct Unk_145f0e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f0e0_arg1, field_0, 0x0);

struct Unk_145f0e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f0e0, field_0, 0x0);

// 0x710145f0e0
void Unk_145f0e0_set(const Unk_145f0e0* self, Unk_145f0e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_145f0f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f0f0_arg1, field_0, 0x0);

struct Unk_145f0f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f0f0, field_0, 0x0);

// 0x710145f0f0
void Unk_145f0f0_set(const Unk_145f0f0* self, Unk_145f0f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_145f100_0 {
    u8 _0[0x5e0];
    u64 field_5e0;
    u8 _5e8[0x18];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_145f100_0, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_145f100_0, field_600, 0x600);

struct Unk_145f100 {
    Unk_145f100_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f100, field_0, 0x0);

void Unk_14e1a30(u64, u32);

// 0x710145f100
void Unk_145f100_call(const Unk_145f100* self) {
    Unk_145f100_0* p0 = self->field_0;
    p0->field_600 = 2;
    Unk_14e1a30(p0->field_5e0, 0);
}

// 0x710145f120
void Unk_145f120_update() {}

struct Unk_145f130_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f130_arg1, field_0, 0x0);

struct Unk_145f130 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f130, field_0, 0x0);

// 0x710145f130
void Unk_145f130_set(const Unk_145f130* self, Unk_145f130_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_145f140_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f140_arg1, field_0, 0x0);

struct Unk_145f140 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f140, field_0, 0x0);

// 0x710145f140
void Unk_145f140_set(const Unk_145f140* self, Unk_145f140_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710145f190
void Unk_145f190_update() {}

struct Unk_145f1a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f1a0_arg1, field_0, 0x0);

struct Unk_145f1a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f1a0, field_0, 0x0);

// 0x710145f1a0
void Unk_145f1a0_set(const Unk_145f1a0* self, Unk_145f1a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_145f1b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f1b0_arg1, field_0, 0x0);

struct Unk_145f1b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f1b0, field_0, 0x0);

// 0x710145f1b0
void Unk_145f1b0_set(const Unk_145f1b0* self, Unk_145f1b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_145f1c0_0 {
    u8 _0[0x600];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_145f1c0_0, field_600, 0x600);

struct Unk_145f1c0 {
    Unk_145f1c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f1c0, field_0, 0x0);

// 0x710145f1c0
void Unk_145f1c0_set(const Unk_145f1c0* self) {
    self->field_0->field_600 = 2;
}

// 0x710145f1d0
void Unk_145f1d0_update() {}

struct Unk_145f1e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f1e0_arg1, field_0, 0x0);

struct Unk_145f1e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f1e0, field_0, 0x0);

// 0x710145f1e0
void Unk_145f1e0_set(const Unk_145f1e0* self, Unk_145f1e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_145f1f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f1f0_arg1, field_0, 0x0);

struct Unk_145f1f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_145f1f0, field_0, 0x0);

// 0x710145f1f0
void Unk_145f1f0_set(const Unk_145f1f0* self, Unk_145f1f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14cc6e0;
struct Unk_1460680 {
    Unk_14cc6e0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1460680, field_0, 0x0);

void Unk_14cc6e0_call(const Unk_14cc6e0*);

// 0x7101460680
void Unk_1460680_call(const Unk_1460680* self) {
    Unk_14cc6e0_call(self->field_0);
}

struct Unk_1460690 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1460690, field_0, 0x0);

// 0x7101460690
void Unk_1460690_call(Unk_1460690* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_14606d0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_14606d0_arg1, field_0, 0x0);

struct Unk_14606d0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_14606d0, field_0, 0x0);

// 0x71014606d0
void Unk_14606d0_call(const Unk_14606d0* self, Unk_14606d0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_14606f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14606f0_arg1, field_0, 0x0);

struct Unk_14606f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14606f0, field_0, 0x0);

// 0x71014606f0
void Unk_14606f0_set(Unk_14606f0* self, Unk_14606f0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_27f0c9c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f0c9c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f0c9c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f0c9c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f0c9c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f0c9c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f0c9c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f0c9c_Data, field_18, 0x18);

extern Unk_27f0c9c_Data Unk_27f0c9c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101460700
void Unk_1460700_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f0c9c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f0c9c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f0c9c.field_18 = 0xffff;
    Unk_27f0c9c.field_10 = 0;
    Unk_27f0c9c.field_8 = r2;
    Unk_27f0c9c.field_c = 0;
    Unk_27f0c9c.field_14 = 0xffffffff;
}
