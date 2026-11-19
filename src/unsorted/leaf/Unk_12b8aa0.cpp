// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12b8aa0_208 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_12b8aa0_208, field_60, 0x60);

struct Unk_12b8aa0 {
    u8 _0[0x208];
    Unk_12b8aa0_208* field_208;
};
PKMN_OFFSET_ASSERT(Unk_12b8aa0, field_208, 0x208);

// 0x71012b8aa0
bool Unk_12b8aa0_check(const Unk_12b8aa0* self) {
    if (self->field_208 == nullptr) {
        return true;
    }
    return self->field_208->field_60 == 0;
}

struct Unk_12bd7e0 {
    u8 _0[0x600];
    void* field_600;
};
PKMN_OFFSET_ASSERT(Unk_12bd7e0, field_600, 0x600);

void Unk_14e69a0(void*);

// 0x71012bd7e0
void Unk_12bd7e0_call(const Unk_12bd7e0* self) {
    Unk_14e69a0(self->field_600);
}

struct Unk_12bda50_5e0 {
    u8 _0[0x218];
    u8 field_218;
    u8 _219[0x217];
    u8 field_430;
    u8 _431[0x217];
    u8 field_648;
    u8 _649[0x217];
    u8 field_860;
    u8 _861[0x217];
    u8 field_a78;
};
PKMN_OFFSET_ASSERT(Unk_12bda50_5e0, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_12bda50_5e0, field_430, 0x430);
PKMN_OFFSET_ASSERT(Unk_12bda50_5e0, field_648, 0x648);
PKMN_OFFSET_ASSERT(Unk_12bda50_5e0, field_860, 0x860);
PKMN_OFFSET_ASSERT(Unk_12bda50_5e0, field_a78, 0xa78);

struct Unk_12bda50 {
    u8 _0[0x5e0];
    Unk_12bda50_5e0* field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_12bda50, field_5e0, 0x5e0);

void Unk_12b84f0(void*, u32);

// 0x71012bda50
void Unk_12bda50_call(const Unk_12bda50* self, bool value) {
    Unk_12b84f0(self->field_5e0, value);
    Unk_12b84f0(&self->field_5e0->field_218, value);
    Unk_12b84f0(&self->field_5e0->field_430, value);
    Unk_12b84f0(&self->field_5e0->field_648, value);
    Unk_12b84f0(&self->field_5e0->field_860, value);
    Unk_12b84f0(&self->field_5e0->field_a78, value);
}

// 0x71012be370
void Unk_12be370_update() {}

struct Unk_12be380_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be380_arg1, field_0, 0x0);

struct Unk_12be380 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be380, field_0, 0x0);

// 0x71012be380
void Unk_12be380_set(const Unk_12be380* self, Unk_12be380_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12be390_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be390_arg1, field_0, 0x0);

struct Unk_12be390 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be390, field_0, 0x0);

// 0x71012be390
void Unk_12be390_set(const Unk_12be390* self, Unk_12be390_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012be400
void Unk_12be400_update() {}

struct Unk_12be410_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be410_arg1, field_0, 0x0);

struct Unk_12be410 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be410, field_0, 0x0);

// 0x71012be410
void Unk_12be410_set(const Unk_12be410* self, Unk_12be410_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12be420_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be420_arg1, field_0, 0x0);

struct Unk_12be420 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be420, field_0, 0x0);

// 0x71012be420
void Unk_12be420_set(const Unk_12be420* self, Unk_12be420_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012be4a0
void Unk_12be4a0_update() {}

struct Unk_12be4b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be4b0_arg1, field_0, 0x0);

struct Unk_12be4b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be4b0, field_0, 0x0);

// 0x71012be4b0
void Unk_12be4b0_set(const Unk_12be4b0* self, Unk_12be4b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12be4c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be4c0_arg1, field_0, 0x0);

struct Unk_12be4c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be4c0, field_0, 0x0);

// 0x71012be4c0
void Unk_12be4c0_set(const Unk_12be4c0* self, Unk_12be4c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012be560
void Unk_12be560_update() {}

struct Unk_12be570_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be570_arg1, field_0, 0x0);

struct Unk_12be570 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be570, field_0, 0x0);

// 0x71012be570
void Unk_12be570_set(const Unk_12be570* self, Unk_12be570_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12be580_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be580_arg1, field_0, 0x0);

struct Unk_12be580 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be580, field_0, 0x0);

// 0x71012be580
void Unk_12be580_set(const Unk_12be580* self, Unk_12be580_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012be780
void Unk_12be780_update() {}

struct Unk_12be790_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be790_arg1, field_0, 0x0);

struct Unk_12be790 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be790, field_0, 0x0);

// 0x71012be790
void Unk_12be790_set(const Unk_12be790* self, Unk_12be790_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12be7a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be7a0_arg1, field_0, 0x0);

struct Unk_12be7a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be7a0, field_0, 0x0);

// 0x71012be7a0
void Unk_12be7a0_set(const Unk_12be7a0* self, Unk_12be7a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012be890
void Unk_12be890_update() {}

struct Unk_12be8a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be8a0_arg1, field_0, 0x0);

struct Unk_12be8a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be8a0, field_0, 0x0);

// 0x71012be8a0
void Unk_12be8a0_set(const Unk_12be8a0* self, Unk_12be8a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12be8b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be8b0_arg1, field_0, 0x0);

struct Unk_12be8b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12be8b0, field_0, 0x0);

// 0x71012be8b0
void Unk_12be8b0_set(const Unk_12be8b0* self, Unk_12be8b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12bedf0 {
    u8 _0[0x70];
    void* field_70;
};
PKMN_OFFSET_ASSERT(Unk_12bedf0, field_70, 0x70);

void Unk_1505660(void*, u32);

// 0x71012bedf0
void Unk_12bedf0_call(const Unk_12bedf0* self, u32 value) {
    Unk_1505660(self->field_70, value);
}

// 0x71012c3250
void Unk_12c3250_update() {}

struct Unk_12c3260_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3260_arg1, field_0, 0x0);

struct Unk_12c3260 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3260, field_0, 0x0);

// 0x71012c3260
void Unk_12c3260_set(const Unk_12c3260* self, Unk_12c3260_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12c3270_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3270_arg1, field_0, 0x0);

struct Unk_12c3270 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3270, field_0, 0x0);

// 0x71012c3270
void Unk_12c3270_set(const Unk_12c3270* self, Unk_12c3270_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012c32a0
void Unk_12c32a0_update() {}

struct Unk_12c32b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c32b0_arg1, field_0, 0x0);

struct Unk_12c32b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c32b0, field_0, 0x0);

// 0x71012c32b0
void Unk_12c32b0_set(const Unk_12c32b0* self, Unk_12c32b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12c32c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c32c0_arg1, field_0, 0x0);

struct Unk_12c32c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c32c0, field_0, 0x0);

// 0x71012c32c0
void Unk_12c32c0_set(const Unk_12c32c0* self, Unk_12c32c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012c3700
void Unk_12c3700_update() {}

struct Unk_12c3710_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3710_arg1, field_0, 0x0);

struct Unk_12c3710 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3710, field_0, 0x0);

// 0x71012c3710
void Unk_12c3710_set(const Unk_12c3710* self, Unk_12c3710_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12c3720_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3720_arg1, field_0, 0x0);

struct Unk_12c3720 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3720, field_0, 0x0);

// 0x71012c3720
void Unk_12c3720_set(const Unk_12c3720* self, Unk_12c3720_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012c37f0
void Unk_12c37f0_update() {}

struct Unk_12c3800_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3800_arg1, field_0, 0x0);

struct Unk_12c3800 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3800, field_0, 0x0);

// 0x71012c3800
void Unk_12c3800_set(const Unk_12c3800* self, Unk_12c3800_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12c3810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3810_arg1, field_0, 0x0);

struct Unk_12c3810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c3810, field_0, 0x0);

// 0x71012c3810
void Unk_12c3810_set(const Unk_12c3810* self, Unk_12c3810_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012c6a00
void Unk_12c6a00_update() {}

struct Unk_12c6a10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c6a10_arg1, field_0, 0x0);

struct Unk_12c6a10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c6a10, field_0, 0x0);

// 0x71012c6a10
void Unk_12c6a10_set(const Unk_12c6a10* self, Unk_12c6a10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12c6a20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c6a20_arg1, field_0, 0x0);

struct Unk_12c6a20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c6a20, field_0, 0x0);

// 0x71012c6a20
void Unk_12c6a20_set(const Unk_12c6a20* self, Unk_12c6a20_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012c72b0
void Unk_12c72b0_update() {}

struct Unk_12c72c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c72c0_arg1, field_0, 0x0);

struct Unk_12c72c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c72c0, field_0, 0x0);

// 0x71012c72c0
void Unk_12c72c0_set(const Unk_12c72c0* self, Unk_12c72c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12c72d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c72d0_arg1, field_0, 0x0);

struct Unk_12c72d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12c72d0, field_0, 0x0);

// 0x71012c72d0
void Unk_12c72d0_set(const Unk_12c72d0* self, Unk_12c72d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27eea84_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27eea84_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27eea84_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27eea84_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27eea84_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27eea84_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27eea84_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27eea84_Data, field_18, 0x18);

extern Unk_27eea84_Data Unk_27eea84 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71012c9b10
void Unk_12c9b10_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27eea84.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27eea84.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27eea84.field_18 = 0xffff;
    Unk_27eea84.field_10 = 0;
    Unk_27eea84.field_8 = r2;
    Unk_27eea84.field_c = 0;
    Unk_27eea84.field_14 = 0xffffffff;
}
