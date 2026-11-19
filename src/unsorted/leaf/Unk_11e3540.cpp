// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11e3540 {
    u8 _0[0x33c];
    u8 field_33c;
};
PKMN_OFFSET_ASSERT(Unk_11e3540, field_33c, 0x33c);

void Unk_11e3550(void*);

// 0x71011e3540
void Unk_11e3540_call(Unk_11e3540* self) {
    self->field_33c = 1;
    Unk_11e3550(self);
}

struct Unk_11e3990 {
    u8 _0[0x33c];
    u8 field_33c;
};
PKMN_OFFSET_ASSERT(Unk_11e3990, field_33c, 0x33c);

void Unk_11e3550(void*);

// 0x71011e3990
void Unk_11e3990_call(Unk_11e3990* self) {
    self->field_33c = 0;
    Unk_11e3550(self);
}

struct Unk_11e39a0 {
    u8 _0[0x338];
    u32 field_338;
};
PKMN_OFFSET_ASSERT(Unk_11e39a0, field_338, 0x338);

void Unk_11e3550(void*);

// 0x71011e39a0
void Unk_11e39a0_call(Unk_11e39a0* self, u32 value) {
    self->field_338 = value;
    Unk_11e3550(self);
}

// 0x71011e43e0
void Unk_11e43e0_update() {}

// 0x71011e43f0
void Unk_11e43f0_update() {}

// 0x71011e4400
void Unk_11e4400_update() {}

// 0x71011e4410
void Unk_11e4410_update() {}

// 0x71011e44f0
void Unk_11e44f0_update() {}

struct Unk_11e4500 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11e4500, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11e4500, field_8, 0x8);

// 0x71011e4500
void Unk_11e4500_set(const Unk_11e4500* self, Unk_11e4500* value) {
    *value = *self;
}

struct Unk_11e4510 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11e4510, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11e4510, field_8, 0x8);

// 0x71011e4510
void Unk_11e4510_set(const Unk_11e4510* self, Unk_11e4510* value) {
    *value = *self;
}

// 0x71011e4580
void Unk_11e4580_update() {}

struct Unk_11e4590 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11e4590, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11e4590, field_8, 0x8);

// 0x71011e4590
void Unk_11e4590_set(const Unk_11e4590* self, Unk_11e4590* value) {
    *value = *self;
}

struct Unk_11e45a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11e45a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11e45a0, field_8, 0x8);

// 0x71011e45a0
void Unk_11e45a0_set(const Unk_11e45a0* self, Unk_11e45a0* value) {
    *value = *self;
}

struct Unk_11e45b0 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e45b0, field_0, 0x0);

void Unk_11e39b0(void*);

// 0x71011e45b0
void Unk_11e45b0_call(const Unk_11e45b0* self) {
    Unk_11e39b0(self->field_0);
}

// 0x71011e45c0
void Unk_11e45c0_update() {}

struct Unk_11e45d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e45d0_arg1, field_0, 0x0);

struct Unk_11e45d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e45d0, field_0, 0x0);

// 0x71011e45d0
void Unk_11e45d0_set(const Unk_11e45d0* self, Unk_11e45d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11e45e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e45e0_arg1, field_0, 0x0);

struct Unk_11e45e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e45e0, field_0, 0x0);

// 0x71011e45e0
void Unk_11e45e0_set(const Unk_11e45e0* self, Unk_11e45e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011e45f0
void Unk_11e45f0_update() {}

// 0x71011e4600
void Unk_11e4600_update() {}

// 0x71011e4610
void Unk_11e4610_update() {}

// 0x71011e4620
void Unk_11e4620_update() {}

// 0x71011e46d0
void Unk_11e46d0_update() {}

struct Unk_11e46e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e46e0_arg1, field_0, 0x0);

struct Unk_11e46e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e46e0, field_0, 0x0);

// 0x71011e46e0
void Unk_11e46e0_set(const Unk_11e46e0* self, Unk_11e46e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11e46f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e46f0_arg1, field_0, 0x0);

struct Unk_11e46f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e46f0, field_0, 0x0);

// 0x71011e46f0
void Unk_11e46f0_set(const Unk_11e46f0* self, Unk_11e46f0_arg1* value) {
    value->field_0 = self->field_0;
}

void Unk_112e3e0(void*, u32);

// 0x71011e4c30
void Unk_11e4c30_call(void* self) {
    Unk_112e3e0(self, 0);
}

struct Unk_11e4c40 {
    u8 _0[0x114];
    f32 field_114;
};
PKMN_OFFSET_ASSERT(Unk_11e4c40, field_114, 0x114);

// 0x71011e4c40
void Unk_11e4c40_setField114(Unk_11e4c40* self, f32 value) {
    self->field_114 = value;
}

struct Unk_11e7550 {
    u8 _0[0xa0];
    u32 field_a0;
    u8 _a4[0x14];
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_11e7550, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_11e7550, field_b8, 0xb8);

void Unk_11e6940(void*, u32);

// 0x71011e7550
void Unk_11e7550_call(Unk_11e7550* self, u32 value) {
    self->field_b8 = value;
    if (value == 1) {
        Unk_11e6940(self, 0);
        self->field_a0 = 0;
    }
}

// 0x71011ea0e0
void Unk_11ea0e0_update() {}

struct Unk_11ea0f0 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea0f0, field_0, 0x0);

void Unk_11e9050(void*);

// 0x71011ea0f0
void Unk_11ea0f0_call(const Unk_11ea0f0* self) {
    Unk_11e9050(self->field_0);
}

// 0x71011ea100
void Unk_11ea100_update() {}

struct Unk_11ea110_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea110_arg1, field_0, 0x0);

struct Unk_11ea110 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea110, field_0, 0x0);

// 0x71011ea110
void Unk_11ea110_set(const Unk_11ea110* self, Unk_11ea110_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea120_arg1, field_0, 0x0);

struct Unk_11ea120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea120, field_0, 0x0);

// 0x71011ea120
void Unk_11ea120_set(const Unk_11ea120* self, Unk_11ea120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea130_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea130_arg1, field_0, 0x0);

struct Unk_11ea130 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea130, field_0, 0x0);

// 0x71011ea130
void Unk_11ea130_set(const Unk_11ea130* self, Unk_11ea130_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea140_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea140_arg1, field_0, 0x0);

struct Unk_11ea140 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea140, field_0, 0x0);

// 0x71011ea140
void Unk_11ea140_set(const Unk_11ea140* self, Unk_11ea140_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ea190
void Unk_11ea190_update() {}

struct Unk_11ea1a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea1a0_arg1, field_0, 0x0);

struct Unk_11ea1a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea1a0, field_0, 0x0);

// 0x71011ea1a0
void Unk_11ea1a0_set(const Unk_11ea1a0* self, Unk_11ea1a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea1b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea1b0_arg1, field_0, 0x0);

struct Unk_11ea1b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea1b0, field_0, 0x0);

// 0x71011ea1b0
void Unk_11ea1b0_set(const Unk_11ea1b0* self, Unk_11ea1b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ea2e0
void Unk_11ea2e0_update() {}

struct Unk_11ea2f0 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea2f0, field_0, 0x0);

void Unk_11e8cc0(void*);

// 0x71011ea2f0
void Unk_11ea2f0_call(const Unk_11ea2f0* self) {
    Unk_11e8cc0(self->field_0);
}

// 0x71011ea300
void Unk_11ea300_update() {}

struct Unk_11ea310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea310_arg1, field_0, 0x0);

struct Unk_11ea310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea310, field_0, 0x0);

// 0x71011ea310
void Unk_11ea310_set(const Unk_11ea310* self, Unk_11ea310_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea320_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea320_arg1, field_0, 0x0);

struct Unk_11ea320 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea320, field_0, 0x0);

// 0x71011ea320
void Unk_11ea320_set(const Unk_11ea320* self, Unk_11ea320_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea330 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea330, field_0, 0x0);

void Unk_11e92b0(void*);

// 0x71011ea330
void Unk_11ea330_call(const Unk_11ea330* self) {
    Unk_11e92b0(self->field_0);
}

// 0x71011ea340
void Unk_11ea340_update() {}

struct Unk_11ea350_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea350_arg1, field_0, 0x0);

struct Unk_11ea350 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea350, field_0, 0x0);

// 0x71011ea350
void Unk_11ea350_set(const Unk_11ea350* self, Unk_11ea350_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea360_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea360_arg1, field_0, 0x0);

struct Unk_11ea360 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea360, field_0, 0x0);

// 0x71011ea360
void Unk_11ea360_set(const Unk_11ea360* self, Unk_11ea360_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea370_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea370_arg1, field_0, 0x0);

struct Unk_11ea370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea370, field_0, 0x0);

// 0x71011ea370
void Unk_11ea370_set(const Unk_11ea370* self, Unk_11ea370_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea380_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea380_arg1, field_0, 0x0);

struct Unk_11ea380 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea380, field_0, 0x0);

// 0x71011ea380
void Unk_11ea380_set(const Unk_11ea380* self, Unk_11ea380_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ea650
void Unk_11ea650_update() {}

// 0x71011ea700
void Unk_11ea700_update() {}

struct Unk_11ea710_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea710_arg1, field_0, 0x0);

struct Unk_11ea710 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea710, field_0, 0x0);

// 0x71011ea710
void Unk_11ea710_set(const Unk_11ea710* self, Unk_11ea710_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea720_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea720_arg1, field_0, 0x0);

struct Unk_11ea720 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea720, field_0, 0x0);

// 0x71011ea720
void Unk_11ea720_set(const Unk_11ea720* self, Unk_11ea720_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea730_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea730_arg1, field_0, 0x0);

struct Unk_11ea730 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea730, field_0, 0x0);

// 0x71011ea730
void Unk_11ea730_set(const Unk_11ea730* self, Unk_11ea730_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea740_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea740_arg1, field_0, 0x0);

struct Unk_11ea740 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea740, field_0, 0x0);

// 0x71011ea740
void Unk_11ea740_set(const Unk_11ea740* self, Unk_11ea740_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ea7d0
void Unk_11ea7d0_update() {}

struct Unk_11ea7e0 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea7e0, field_0, 0x0);

void Unk_11e93d0(void*);

// 0x71011ea7e0
void Unk_11ea7e0_call(const Unk_11ea7e0* self) {
    Unk_11e93d0(self->field_0);
}

// 0x71011ea7f0
void Unk_11ea7f0_update() {}

struct Unk_11ea800_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea800_arg1, field_0, 0x0);

struct Unk_11ea800 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea800, field_0, 0x0);

// 0x71011ea800
void Unk_11ea800_set(const Unk_11ea800* self, Unk_11ea800_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea810_arg1, field_0, 0x0);

struct Unk_11ea810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea810, field_0, 0x0);

// 0x71011ea810
void Unk_11ea810_set(const Unk_11ea810* self, Unk_11ea810_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea820_arg1, field_0, 0x0);

struct Unk_11ea820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea820, field_0, 0x0);

// 0x71011ea820
void Unk_11ea820_set(const Unk_11ea820* self, Unk_11ea820_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea830_arg1, field_0, 0x0);

struct Unk_11ea830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea830, field_0, 0x0);

// 0x71011ea830
void Unk_11ea830_set(const Unk_11ea830* self, Unk_11ea830_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ea880
void Unk_11ea880_update() {}

struct Unk_11ea890_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea890_arg1, field_0, 0x0);

struct Unk_11ea890 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea890, field_0, 0x0);

// 0x71011ea890
void Unk_11ea890_set(const Unk_11ea890* self, Unk_11ea890_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea8a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea8a0_arg1, field_0, 0x0);

struct Unk_11ea8a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea8a0, field_0, 0x0);

// 0x71011ea8a0
void Unk_11ea8a0_set(const Unk_11ea8a0* self, Unk_11ea8a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ea8c0
void Unk_11ea8c0_update() {}

struct Unk_11ea8d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea8d0_arg1, field_0, 0x0);

struct Unk_11ea8d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea8d0, field_0, 0x0);

// 0x71011ea8d0
void Unk_11ea8d0_set(const Unk_11ea8d0* self, Unk_11ea8d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ea8e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea8e0_arg1, field_0, 0x0);

struct Unk_11ea8e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ea8e0, field_0, 0x0);

// 0x71011ea8e0
void Unk_11ea8e0_set(const Unk_11ea8e0* self, Unk_11ea8e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ebbe0
void Unk_11ebbe0_update() {}

struct Unk_11ebbf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebbf0_arg1, field_0, 0x0);

struct Unk_11ebbf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebbf0, field_0, 0x0);

// 0x71011ebbf0
void Unk_11ebbf0_set(const Unk_11ebbf0* self, Unk_11ebbf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ebc00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebc00_arg1, field_0, 0x0);

struct Unk_11ebc00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebc00, field_0, 0x0);

// 0x71011ebc00
void Unk_11ebc00_set(const Unk_11ebc00* self, Unk_11ebc00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ebc20
void Unk_11ebc20_update() {}

struct Unk_11ebc30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebc30_arg1, field_0, 0x0);

struct Unk_11ebc30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebc30, field_0, 0x0);

// 0x71011ebc30
void Unk_11ebc30_set(const Unk_11ebc30* self, Unk_11ebc30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ebc40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebc40_arg1, field_0, 0x0);

struct Unk_11ebc40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebc40, field_0, 0x0);

// 0x71011ebc40
void Unk_11ebc40_set(const Unk_11ebc40* self, Unk_11ebc40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ebd20
void Unk_11ebd20_update() {}

struct Unk_11ebd30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebd30_arg1, field_0, 0x0);

struct Unk_11ebd30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebd30, field_0, 0x0);

// 0x71011ebd30
void Unk_11ebd30_set(const Unk_11ebd30* self, Unk_11ebd30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ebd40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebd40_arg1, field_0, 0x0);

struct Unk_11ebd40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebd40, field_0, 0x0);

// 0x71011ebd40
void Unk_11ebd40_set(const Unk_11ebd40* self, Unk_11ebd40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ebd90
void Unk_11ebd90_update() {}

struct Unk_11ebda0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebda0_arg1, field_0, 0x0);

struct Unk_11ebda0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebda0, field_0, 0x0);

// 0x71011ebda0
void Unk_11ebda0_set(const Unk_11ebda0* self, Unk_11ebda0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ebdb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebdb0_arg1, field_0, 0x0);

struct Unk_11ebdb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebdb0, field_0, 0x0);

// 0x71011ebdb0
void Unk_11ebdb0_set(const Unk_11ebdb0* self, Unk_11ebdb0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ebeb0
void Unk_11ebeb0_update() {}

struct Unk_11ebec0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebec0_arg1, field_0, 0x0);

struct Unk_11ebec0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebec0, field_0, 0x0);

// 0x71011ebec0
void Unk_11ebec0_set(const Unk_11ebec0* self, Unk_11ebec0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ebed0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebed0_arg1, field_0, 0x0);

struct Unk_11ebed0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ebed0, field_0, 0x0);

// 0x71011ebed0
void Unk_11ebed0_set(const Unk_11ebed0* self, Unk_11ebed0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ebee0
void Unk_11ebee0_update() {}

// 0x71011ebef0
void Unk_11ebef0_update() {}

// 0x71011ebf00
void Unk_11ebf00_update() {}

// 0x71011ebf10
void Unk_11ebf10_update() {}

// 0x71011ee270
void Unk_11ee270_update() {}

struct Unk_11ee280_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee280_arg1, field_0, 0x0);

struct Unk_11ee280 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee280, field_0, 0x0);

// 0x71011ee280
void Unk_11ee280_set(const Unk_11ee280* self, Unk_11ee280_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ee290_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee290_arg1, field_0, 0x0);

struct Unk_11ee290 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee290, field_0, 0x0);

// 0x71011ee290
void Unk_11ee290_set(const Unk_11ee290* self, Unk_11ee290_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ee2b0
void Unk_11ee2b0_update() {}

struct Unk_11ee2c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee2c0_arg1, field_0, 0x0);

struct Unk_11ee2c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee2c0, field_0, 0x0);

// 0x71011ee2c0
void Unk_11ee2c0_set(const Unk_11ee2c0* self, Unk_11ee2c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ee2d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee2d0_arg1, field_0, 0x0);

struct Unk_11ee2d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee2d0, field_0, 0x0);

// 0x71011ee2d0
void Unk_11ee2d0_set(const Unk_11ee2d0* self, Unk_11ee2d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ee2f0
void Unk_11ee2f0_update() {}

struct Unk_11ee300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee300_arg1, field_0, 0x0);

struct Unk_11ee300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee300, field_0, 0x0);

// 0x71011ee300
void Unk_11ee300_set(const Unk_11ee300* self, Unk_11ee300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ee310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee310_arg1, field_0, 0x0);

struct Unk_11ee310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee310, field_0, 0x0);

// 0x71011ee310
void Unk_11ee310_set(const Unk_11ee310* self, Unk_11ee310_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ee360
void Unk_11ee360_update() {}

struct Unk_11ee370_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee370_arg1, field_0, 0x0);

struct Unk_11ee370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee370, field_0, 0x0);

// 0x71011ee370
void Unk_11ee370_set(const Unk_11ee370* self, Unk_11ee370_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ee380_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee380_arg1, field_0, 0x0);

struct Unk_11ee380 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee380, field_0, 0x0);

// 0x71011ee380
void Unk_11ee380_set(const Unk_11ee380* self, Unk_11ee380_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ee4b0
void Unk_11ee4b0_update() {}

struct Unk_11ee4c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee4c0_arg1, field_0, 0x0);

struct Unk_11ee4c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee4c0, field_0, 0x0);

// 0x71011ee4c0
void Unk_11ee4c0_set(const Unk_11ee4c0* self, Unk_11ee4c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ee4d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee4d0_arg1, field_0, 0x0);

struct Unk_11ee4d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ee4d0, field_0, 0x0);

// 0x71011ee4d0
void Unk_11ee4d0_set(const Unk_11ee4d0* self, Unk_11ee4d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011ee4e0
void Unk_11ee4e0_update() {}

// 0x71011ee4f0
void Unk_11ee4f0_update() {}

// 0x71011ee500
void Unk_11ee500_update() {}

// 0x71011ee510
void Unk_11ee510_update() {}

// 0x71011f1630
void Unk_11f1630_update() {}

struct Unk_11f1640 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1640, field_0, 0x0);

void Unk_11f09a0(void*);

// 0x71011f1640
void Unk_11f1640_call(const Unk_11f1640* self) {
    Unk_11f09a0(self->field_0);
}

// 0x71011f1650
void Unk_11f1650_update() {}

struct Unk_11f1660_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1660_arg1, field_0, 0x0);

struct Unk_11f1660 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1660, field_0, 0x0);

// 0x71011f1660
void Unk_11f1660_set(const Unk_11f1660* self, Unk_11f1660_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1670_arg1, field_0, 0x0);

struct Unk_11f1670 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1670, field_0, 0x0);

// 0x71011f1670
void Unk_11f1670_set(const Unk_11f1670* self, Unk_11f1670_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1680_arg1, field_0, 0x0);

struct Unk_11f1680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1680, field_0, 0x0);

// 0x71011f1680
void Unk_11f1680_set(const Unk_11f1680* self, Unk_11f1680_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1690_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1690_arg1, field_0, 0x0);

struct Unk_11f1690 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1690, field_0, 0x0);

// 0x71011f1690
void Unk_11f1690_set(const Unk_11f1690* self, Unk_11f1690_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011f16e0
void Unk_11f16e0_update() {}

struct Unk_11f16f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f16f0_arg1, field_0, 0x0);

struct Unk_11f16f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f16f0, field_0, 0x0);

// 0x71011f16f0
void Unk_11f16f0_set(const Unk_11f16f0* self, Unk_11f16f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1700_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1700_arg1, field_0, 0x0);

struct Unk_11f1700 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1700, field_0, 0x0);

// 0x71011f1700
void Unk_11f1700_set(const Unk_11f1700* self, Unk_11f1700_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011f1840
void Unk_11f1840_update() {}

// 0x71011f18f0
void Unk_11f18f0_update() {}

struct Unk_11f1900 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1900, field_0, 0x0);

void Unk_11f09a0(void*);

// 0x71011f1900
void Unk_11f1900_call(const Unk_11f1900* self) {
    Unk_11f09a0(self->field_0);
}

// 0x71011f1910
void Unk_11f1910_update() {}

struct Unk_11f1920_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1920_arg1, field_0, 0x0);

struct Unk_11f1920 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1920, field_0, 0x0);

// 0x71011f1920
void Unk_11f1920_set(const Unk_11f1920* self, Unk_11f1920_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1930_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1930_arg1, field_0, 0x0);

struct Unk_11f1930 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1930, field_0, 0x0);

// 0x71011f1930
void Unk_11f1930_set(const Unk_11f1930* self, Unk_11f1930_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1940_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1940_arg1, field_0, 0x0);

struct Unk_11f1940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1940, field_0, 0x0);

// 0x71011f1940
void Unk_11f1940_set(const Unk_11f1940* self, Unk_11f1940_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1950_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1950_arg1, field_0, 0x0);

struct Unk_11f1950 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1950, field_0, 0x0);

// 0x71011f1950
void Unk_11f1950_set(const Unk_11f1950* self, Unk_11f1950_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1960_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1960_arg1, field_0, 0x0);

struct Unk_11f1960 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1960, field_0, 0x0);

// 0x71011f1960
void Unk_11f1960_set(const Unk_11f1960* self, Unk_11f1960_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1970_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1970_arg1, field_0, 0x0);

struct Unk_11f1970 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1970, field_0, 0x0);

// 0x71011f1970
void Unk_11f1970_set(const Unk_11f1970* self, Unk_11f1970_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1980 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1980, field_0, 0x0);

void Unk_11f0770(void*);

// 0x71011f1980
void Unk_11f1980_call(const Unk_11f1980* self) {
    Unk_11f0770(self->field_0);
}

// 0x71011f1990
void Unk_11f1990_update() {}

struct Unk_11f19a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f19a0_arg1, field_0, 0x0);

struct Unk_11f19a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f19a0, field_0, 0x0);

// 0x71011f19a0
void Unk_11f19a0_set(const Unk_11f19a0* self, Unk_11f19a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f19b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f19b0_arg1, field_0, 0x0);

struct Unk_11f19b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f19b0, field_0, 0x0);

// 0x71011f19b0
void Unk_11f19b0_set(const Unk_11f19b0* self, Unk_11f19b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011f1a40
void Unk_11f1a40_update() {}

struct Unk_11f1a50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1a50_arg1, field_0, 0x0);

struct Unk_11f1a50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1a50, field_0, 0x0);

// 0x71011f1a50
void Unk_11f1a50_set(const Unk_11f1a50* self, Unk_11f1a50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1a60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1a60_arg1, field_0, 0x0);

struct Unk_11f1a60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1a60, field_0, 0x0);

// 0x71011f1a60
void Unk_11f1a60_set(const Unk_11f1a60* self, Unk_11f1a60_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011f1b20
void Unk_11f1b20_update() {}

struct Unk_11f1b30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1b30_arg1, field_0, 0x0);

struct Unk_11f1b30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1b30, field_0, 0x0);

// 0x71011f1b30
void Unk_11f1b30_set(const Unk_11f1b30* self, Unk_11f1b30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1b40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1b40_arg1, field_0, 0x0);

struct Unk_11f1b40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1b40, field_0, 0x0);

// 0x71011f1b40
void Unk_11f1b40_set(const Unk_11f1b40* self, Unk_11f1b40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011f1b90
void Unk_11f1b90_update() {}

struct Unk_11f1ba0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1ba0_arg1, field_0, 0x0);

struct Unk_11f1ba0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1ba0, field_0, 0x0);

// 0x71011f1ba0
void Unk_11f1ba0_set(const Unk_11f1ba0* self, Unk_11f1ba0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f1bb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1bb0_arg1, field_0, 0x0);

struct Unk_11f1bb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f1bb0, field_0, 0x0);

// 0x71011f1bb0
void Unk_11f1bb0_set(const Unk_11f1bb0* self, Unk_11f1bb0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011f5da0
void Unk_11f5da0_update() {}

struct Unk_11f5db0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11f5db0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11f5db0, field_8, 0x8);

// 0x71011f5db0
void Unk_11f5db0_set(const Unk_11f5db0* self, Unk_11f5db0* value) {
    *value = *self;
}

struct Unk_11f5dc0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11f5dc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11f5dc0, field_8, 0x8);

// 0x71011f5dc0
void Unk_11f5dc0_set(const Unk_11f5dc0* self, Unk_11f5dc0* value) {
    *value = *self;
}

// 0x71011f5e50
void Unk_11f5e50_update() {}

struct Unk_11f5e60 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11f5e60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11f5e60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11f5e60, field_10, 0x10);

// 0x71011f5e60
void Unk_11f5e60_set(const Unk_11f5e60* self, Unk_11f5e60* value) {
    *value = *self;
}

struct Unk_11f5e80 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11f5e80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11f5e80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11f5e80, field_10, 0x10);

// 0x71011f5e80
void Unk_11f5e80_set(const Unk_11f5e80* self, Unk_11f5e80* value) {
    *value = *self;
}

// 0x71011f5f80
void Unk_11f5f80_update() {}

struct Unk_11f5f90 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11f5f90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11f5f90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11f5f90, field_10, 0x10);

// 0x71011f5f90
void Unk_11f5f90_set(const Unk_11f5f90* self, Unk_11f5f90* value) {
    *value = *self;
}

struct Unk_11f5fb0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11f5fb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11f5fb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11f5fb0, field_10, 0x10);

// 0x71011f5fb0
void Unk_11f5fb0_set(const Unk_11f5fb0* self, Unk_11f5fb0* value) {
    *value = *self;
}

// 0x71011f65d0
void Unk_11f65d0_update() {}

struct Unk_11f65e0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11f65e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11f65e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11f65e0, field_10, 0x10);

// 0x71011f65e0
void Unk_11f65e0_set(const Unk_11f65e0* self, Unk_11f65e0* value) {
    *value = *self;
}

struct Unk_11f6600 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11f6600, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11f6600, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11f6600, field_10, 0x10);

// 0x71011f6600
void Unk_11f6600_set(const Unk_11f6600* self, Unk_11f6600* value) {
    *value = *self;
}

// 0x71011f6e50
void Unk_11f6e50_update() {}

struct Unk_11f6e60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f6e60_arg1, field_0, 0x0);

struct Unk_11f6e60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f6e60, field_0, 0x0);

// 0x71011f6e60
void Unk_11f6e60_set(const Unk_11f6e60* self, Unk_11f6e60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11f6e70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f6e70_arg1, field_0, 0x0);

struct Unk_11f6e70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11f6e70, field_0, 0x0);

// 0x71011f6e70
void Unk_11f6e70_set(const Unk_11f6e70* self, Unk_11f6e70_arg1* value) {
    value->field_0 = self->field_0;
}
