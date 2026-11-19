// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f280f0_5f8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_f280f0_5f8, field_58, 0x58);

struct Unk_f280f0 {
    u8 _0[0x5f8];
    Unk_f280f0_5f8* field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_f280f0, field_5f8, 0x5f8);

// 0x7100f280f0
void Unk_f280f0_set(const Unk_f280f0* self, bool value) {
    self->field_5f8->field_58 = (self->field_5f8->field_58 & 0xfffffffe) | (value);
}

struct Unk_f28570 {
    u8 _0[0x5f0];
    void* field_5f0;
};
PKMN_OFFSET_ASSERT(Unk_f28570, field_5f0, 0x5f0);

void Unk_14e1b40(void*);

// 0x7100f28570
void Unk_f28570_call(const Unk_f28570* self) {
    Unk_14e1b40(self->field_5f0);
}

struct Unk_f2a6c0_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x104];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f2a6c0_0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_f2a6c0_0, field_5cc, 0x5cc);

struct Unk_f2a6c0 {
    Unk_f2a6c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a6c0, field_0, 0x0);

void Unk_1500c40(u64);

// 0x7100f2a6c0
void Unk_f2a6c0_call(const Unk_f2a6c0* self) {
    Unk_f2a6c0_0* p0 = self->field_0;
    p0->field_5cc = 1;
    if (p0->field_4c0 != 0) {
        Unk_1500c40(p0->field_4c0);
    }
}

// 0x7100f2a6e0
void Unk_f2a6e0_update() {}

struct Unk_f2a6f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a6f0_arg1, field_0, 0x0);

struct Unk_f2a6f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a6f0, field_0, 0x0);

// 0x7100f2a6f0
void Unk_f2a6f0_set(const Unk_f2a6f0* self, Unk_f2a6f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f2a700_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a700_arg1, field_0, 0x0);

struct Unk_f2a700 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a700, field_0, 0x0);

// 0x7100f2a700
void Unk_f2a700_set(const Unk_f2a700* self, Unk_f2a700_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f2a710_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x104];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f2a710_0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_f2a710_0, field_5cc, 0x5cc);

struct Unk_f2a710 {
    Unk_f2a710_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a710, field_0, 0x0);

void Unk_1500c40(u64);

// 0x7100f2a710
void Unk_f2a710_call(const Unk_f2a710* self) {
    Unk_f2a710_0* p0 = self->field_0;
    p0->field_5cc = 1;
    if (p0->field_4c0 != 0) {
        Unk_1500c40(p0->field_4c0);
    }
}

// 0x7100f2a730
void Unk_f2a730_update() {}

struct Unk_f2a740_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a740_arg1, field_0, 0x0);

struct Unk_f2a740 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a740, field_0, 0x0);

// 0x7100f2a740
void Unk_f2a740_set(const Unk_f2a740* self, Unk_f2a740_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f2a750_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a750_arg1, field_0, 0x0);

struct Unk_f2a750 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2a750, field_0, 0x0);

// 0x7100f2a750
void Unk_f2a750_set(const Unk_f2a750* self, Unk_f2a750_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f2ad40
void Unk_f2ad40_update() {}

struct Unk_f2ad50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2ad50_arg1, field_0, 0x0);

struct Unk_f2ad50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2ad50, field_0, 0x0);

// 0x7100f2ad50
void Unk_f2ad50_set(const Unk_f2ad50* self, Unk_f2ad50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f2ad60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2ad60_arg1, field_0, 0x0);

struct Unk_f2ad60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2ad60, field_0, 0x0);

// 0x7100f2ad60
void Unk_f2ad60_set(const Unk_f2ad60* self, Unk_f2ad60_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f2b110
void Unk_f2b110_update() {}

struct Unk_f2b120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2b120_arg1, field_0, 0x0);

struct Unk_f2b120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2b120, field_0, 0x0);

// 0x7100f2b120
void Unk_f2b120_set(const Unk_f2b120* self, Unk_f2b120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f2b130_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2b130_arg1, field_0, 0x0);

struct Unk_f2b130 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2b130, field_0, 0x0);

// 0x7100f2b130
void Unk_f2b130_set(const Unk_f2b130* self, Unk_f2b130_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f2c220
void Unk_f2c220_update() {}

struct Unk_f2c230_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c230_arg1, field_0, 0x0);

struct Unk_f2c230 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c230, field_0, 0x0);

// 0x7100f2c230
void Unk_f2c230_set(const Unk_f2c230* self, Unk_f2c230_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f2c240_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c240_arg1, field_0, 0x0);

struct Unk_f2c240 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c240, field_0, 0x0);

// 0x7100f2c240
void Unk_f2c240_set(const Unk_f2c240* self, Unk_f2c240_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f2c460
void Unk_f2c460_update() {}

struct Unk_f2c470_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c470_arg1, field_0, 0x0);

struct Unk_f2c470 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c470, field_0, 0x0);

// 0x7100f2c470
void Unk_f2c470_set(const Unk_f2c470* self, Unk_f2c470_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f2c480_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c480_arg1, field_0, 0x0);

struct Unk_f2c480 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c480, field_0, 0x0);

// 0x7100f2c480
void Unk_f2c480_set(const Unk_f2c480* self, Unk_f2c480_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f2c4b0
void Unk_f2c4b0_update() {}

struct Unk_f2c4c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c4c0_arg1, field_0, 0x0);

struct Unk_f2c4c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c4c0, field_0, 0x0);

// 0x7100f2c4c0
void Unk_f2c4c0_set(const Unk_f2c4c0* self, Unk_f2c4c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f2c4d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c4d0_arg1, field_0, 0x0);

struct Unk_f2c4d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f2c4d0, field_0, 0x0);

// 0x7100f2c4d0
void Unk_f2c4d0_set(const Unk_f2c4d0* self, Unk_f2c4d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e1104_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e1104_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e1104_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e1104_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e1104_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e1104_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e1104_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e1104_Data, field_18, 0x18);

extern Unk_27e1104_Data Unk_27e1104 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f2c4e0
void Unk_f2c4e0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e1104.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e1104.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e1104.field_18 = 0xffff;
    Unk_27e1104.field_10 = 0;
    Unk_27e1104.field_8 = r2;
    Unk_27e1104.field_c = 0;
    Unk_27e1104.field_14 = 0xffffffff;
}
