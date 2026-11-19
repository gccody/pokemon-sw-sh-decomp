// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12ad280 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad280, field_0, 0x0);

u32 Unk_12a47f0(void*);
void Unk_12acba0(void*);

// 0x71012ad280
void Unk_12ad280_call(const Unk_12ad280* self) {
    void* v0 = self->field_0;
    u32 r0 = Unk_12a47f0(v0);
    if (r0 == 1) {
        Unk_12acba0(v0);
    }
}

// 0x71012ad2c0
void Unk_12ad2c0_update() {}

struct Unk_12ad2d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad2d0_arg1, field_0, 0x0);

struct Unk_12ad2d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad2d0, field_0, 0x0);

// 0x71012ad2d0
void Unk_12ad2d0_set(const Unk_12ad2d0* self, Unk_12ad2d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad2e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad2e0_arg1, field_0, 0x0);

struct Unk_12ad2e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad2e0, field_0, 0x0);

// 0x71012ad2e0
void Unk_12ad2e0_set(const Unk_12ad2e0* self, Unk_12ad2e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012ad350
void Unk_12ad350_update() {}

struct Unk_12ad360_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad360_arg1, field_0, 0x0);

struct Unk_12ad360 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad360, field_0, 0x0);

// 0x71012ad360
void Unk_12ad360_set(const Unk_12ad360* self, Unk_12ad360_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad370_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad370_arg1, field_0, 0x0);

struct Unk_12ad370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad370, field_0, 0x0);

// 0x71012ad370
void Unk_12ad370_set(const Unk_12ad370* self, Unk_12ad370_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012ad3a0
void Unk_12ad3a0_update() {}

struct Unk_12ad3b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad3b0_arg1, field_0, 0x0);

struct Unk_12ad3b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad3b0, field_0, 0x0);

// 0x71012ad3b0
void Unk_12ad3b0_set(const Unk_12ad3b0* self, Unk_12ad3b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad3c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad3c0_arg1, field_0, 0x0);

struct Unk_12ad3c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad3c0, field_0, 0x0);

// 0x71012ad3c0
void Unk_12ad3c0_set(const Unk_12ad3c0* self, Unk_12ad3c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012ad450
void Unk_12ad450_update() {}

struct Unk_12ad460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad460_arg1, field_0, 0x0);

struct Unk_12ad460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad460, field_0, 0x0);

// 0x71012ad460
void Unk_12ad460_set(const Unk_12ad460* self, Unk_12ad460_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad470_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad470_arg1, field_0, 0x0);

struct Unk_12ad470 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad470, field_0, 0x0);

// 0x71012ad470
void Unk_12ad470_set(const Unk_12ad470* self, Unk_12ad470_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad480_0 {
    u8 _0[0x1b4];
    u32 field_1b4;
};
PKMN_OFFSET_ASSERT(Unk_12ad480_0, field_1b4, 0x1b4);

struct Unk_12ad480 {
    Unk_12ad480_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad480, field_0, 0x0);

// 0x71012ad480
void Unk_12ad480_set(const Unk_12ad480* self) {
    self->field_0->field_1b4 = 6;
}

// 0x71012ad490
void Unk_12ad490_update() {}

struct Unk_12ad4a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad4a0_arg1, field_0, 0x0);

struct Unk_12ad4a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad4a0, field_0, 0x0);

// 0x71012ad4a0
void Unk_12ad4a0_set(const Unk_12ad4a0* self, Unk_12ad4a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad4b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad4b0_arg1, field_0, 0x0);

struct Unk_12ad4b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad4b0, field_0, 0x0);

// 0x71012ad4b0
void Unk_12ad4b0_set(const Unk_12ad4b0* self, Unk_12ad4b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad4c0_0 {
    u8 _0[0x1b4];
    u32 field_1b4;
};
PKMN_OFFSET_ASSERT(Unk_12ad4c0_0, field_1b4, 0x1b4);

struct Unk_12ad4c0 {
    Unk_12ad4c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad4c0, field_0, 0x0);

// 0x71012ad4c0
void Unk_12ad4c0_set(const Unk_12ad4c0* self) {
    self->field_0->field_1b4 = 6;
}

// 0x71012ad4d0
void Unk_12ad4d0_update() {}

struct Unk_12ad4e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad4e0_arg1, field_0, 0x0);

struct Unk_12ad4e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad4e0, field_0, 0x0);

// 0x71012ad4e0
void Unk_12ad4e0_set(const Unk_12ad4e0* self, Unk_12ad4e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad4f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad4f0_arg1, field_0, 0x0);

struct Unk_12ad4f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad4f0, field_0, 0x0);

// 0x71012ad4f0
void Unk_12ad4f0_set(const Unk_12ad4f0* self, Unk_12ad4f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012ad520
void Unk_12ad520_update() {}

struct Unk_12ad530_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad530_arg1, field_0, 0x0);

struct Unk_12ad530 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad530, field_0, 0x0);

// 0x71012ad530
void Unk_12ad530_set(const Unk_12ad530* self, Unk_12ad530_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad540_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad540_arg1, field_0, 0x0);

struct Unk_12ad540 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad540, field_0, 0x0);

// 0x71012ad540
void Unk_12ad540_set(const Unk_12ad540* self, Unk_12ad540_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad550_0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_12ad550_0, field_78, 0x78);

struct Unk_12ad550 {
    Unk_12ad550_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad550, field_0, 0x0);

void Unk_12a48b0(void*, u32);
void Unk_12aca80(void*, u32, u32, u32, u32);

// 0x71012ad550
void Unk_12ad550_call(const Unk_12ad550* self) {
    Unk_12ad550_0* v0 = self->field_0;
    v0->field_78 = 6;
    Unk_12a48b0(v0, 6);
    Unk_12aca80(v0, 1, 1, 1, 0);
}

// 0x71012ad5a0
void Unk_12ad5a0_update() {}

struct Unk_12ad5b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad5b0_arg1, field_0, 0x0);

struct Unk_12ad5b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad5b0, field_0, 0x0);

// 0x71012ad5b0
void Unk_12ad5b0_set(const Unk_12ad5b0* self, Unk_12ad5b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad5c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad5c0_arg1, field_0, 0x0);

struct Unk_12ad5c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad5c0, field_0, 0x0);

// 0x71012ad5c0
void Unk_12ad5c0_set(const Unk_12ad5c0* self, Unk_12ad5c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad5d0_0 {
    u8 _0[0x1b4];
    u32 field_1b4;
};
PKMN_OFFSET_ASSERT(Unk_12ad5d0_0, field_1b4, 0x1b4);

struct Unk_12ad5d0 {
    Unk_12ad5d0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad5d0, field_0, 0x0);

// 0x71012ad5d0
void Unk_12ad5d0_set(const Unk_12ad5d0* self) {
    self->field_0->field_1b4 = 6;
}

// 0x71012ad5e0
void Unk_12ad5e0_update() {}

struct Unk_12ad5f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad5f0_arg1, field_0, 0x0);

struct Unk_12ad5f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad5f0, field_0, 0x0);

// 0x71012ad5f0
void Unk_12ad5f0_set(const Unk_12ad5f0* self, Unk_12ad5f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad600_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad600_arg1, field_0, 0x0);

struct Unk_12ad600 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad600, field_0, 0x0);

// 0x71012ad600
void Unk_12ad600_set(const Unk_12ad600* self, Unk_12ad600_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad610_0 {
    u8 _0[0x1b4];
    u32 field_1b4;
};
PKMN_OFFSET_ASSERT(Unk_12ad610_0, field_1b4, 0x1b4);

struct Unk_12ad610 {
    Unk_12ad610_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad610, field_0, 0x0);

// 0x71012ad610
void Unk_12ad610_set(const Unk_12ad610* self) {
    self->field_0->field_1b4 = 6;
}

// 0x71012ad620
void Unk_12ad620_update() {}

struct Unk_12ad630_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad630_arg1, field_0, 0x0);

struct Unk_12ad630 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad630, field_0, 0x0);

// 0x71012ad630
void Unk_12ad630_set(const Unk_12ad630* self, Unk_12ad630_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad640_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad640_arg1, field_0, 0x0);

struct Unk_12ad640 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad640, field_0, 0x0);

// 0x71012ad640
void Unk_12ad640_set(const Unk_12ad640* self, Unk_12ad640_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad650_0 {
    u8 _0[0x1b4];
    u32 field_1b4;
};
PKMN_OFFSET_ASSERT(Unk_12ad650_0, field_1b4, 0x1b4);

struct Unk_12ad650 {
    Unk_12ad650_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad650, field_0, 0x0);

// 0x71012ad650
void Unk_12ad650_set(const Unk_12ad650* self) {
    self->field_0->field_1b4 = 6;
}

// 0x71012ad660
void Unk_12ad660_update() {}

struct Unk_12ad670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad670_arg1, field_0, 0x0);

struct Unk_12ad670 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad670, field_0, 0x0);

// 0x71012ad670
void Unk_12ad670_set(const Unk_12ad670* self, Unk_12ad670_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad680_arg1, field_0, 0x0);

struct Unk_12ad680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad680, field_0, 0x0);

// 0x71012ad680
void Unk_12ad680_set(const Unk_12ad680* self, Unk_12ad680_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012ad810
void Unk_12ad810_update() {}

struct Unk_12ad820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad820_arg1, field_0, 0x0);

struct Unk_12ad820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad820, field_0, 0x0);

// 0x71012ad820
void Unk_12ad820_set(const Unk_12ad820* self, Unk_12ad820_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad830_arg1, field_0, 0x0);

struct Unk_12ad830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad830, field_0, 0x0);

// 0x71012ad830
void Unk_12ad830_set(const Unk_12ad830* self, Unk_12ad830_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad840_0 {
    u8 _0[0x1b4];
    u32 field_1b4;
};
PKMN_OFFSET_ASSERT(Unk_12ad840_0, field_1b4, 0x1b4);

struct Unk_12ad840 {
    Unk_12ad840_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad840, field_0, 0x0);

// 0x71012ad840
void Unk_12ad840_set(const Unk_12ad840* self) {
    self->field_0->field_1b4 = 6;
}

// 0x71012ad850
void Unk_12ad850_update() {}

struct Unk_12ad860_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad860_arg1, field_0, 0x0);

struct Unk_12ad860 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad860, field_0, 0x0);

// 0x71012ad860
void Unk_12ad860_set(const Unk_12ad860* self, Unk_12ad860_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad870_arg1, field_0, 0x0);

struct Unk_12ad870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad870, field_0, 0x0);

// 0x71012ad870
void Unk_12ad870_set(const Unk_12ad870* self, Unk_12ad870_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012ad8f0
void Unk_12ad8f0_update() {}

struct Unk_12ad900_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad900_arg1, field_0, 0x0);

struct Unk_12ad900 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad900, field_0, 0x0);

// 0x71012ad900
void Unk_12ad900_set(const Unk_12ad900* self, Unk_12ad900_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad910_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad910_arg1, field_0, 0x0);

struct Unk_12ad910 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad910, field_0, 0x0);

// 0x71012ad910
void Unk_12ad910_set(const Unk_12ad910* self, Unk_12ad910_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012ad9d0
void Unk_12ad9d0_update() {}

struct Unk_12ad9e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad9e0_arg1, field_0, 0x0);

struct Unk_12ad9e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad9e0, field_0, 0x0);

// 0x71012ad9e0
void Unk_12ad9e0_set(const Unk_12ad9e0* self, Unk_12ad9e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ad9f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad9f0_arg1, field_0, 0x0);

struct Unk_12ad9f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ad9f0, field_0, 0x0);

// 0x71012ad9f0
void Unk_12ad9f0_set(const Unk_12ad9f0* self, Unk_12ad9f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012ada70
void Unk_12ada70_update() {}

struct Unk_12ada80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ada80_arg1, field_0, 0x0);

struct Unk_12ada80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ada80, field_0, 0x0);

// 0x71012ada80
void Unk_12ada80_set(const Unk_12ada80* self, Unk_12ada80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ada90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ada90_arg1, field_0, 0x0);

struct Unk_12ada90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ada90, field_0, 0x0);

// 0x71012ada90
void Unk_12ada90_set(const Unk_12ada90* self, Unk_12ada90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12adaa0_0 {
    u8 _0[0x1b4];
    u32 field_1b4;
};
PKMN_OFFSET_ASSERT(Unk_12adaa0_0, field_1b4, 0x1b4);

struct Unk_12adaa0 {
    Unk_12adaa0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adaa0, field_0, 0x0);

// 0x71012adaa0
void Unk_12adaa0_set(const Unk_12adaa0* self) {
    self->field_0->field_1b4 = 6;
}

// 0x71012adab0
void Unk_12adab0_update() {}

struct Unk_12adac0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adac0_arg1, field_0, 0x0);

struct Unk_12adac0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adac0, field_0, 0x0);

// 0x71012adac0
void Unk_12adac0_set(const Unk_12adac0* self, Unk_12adac0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12adad0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adad0_arg1, field_0, 0x0);

struct Unk_12adad0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adad0, field_0, 0x0);

// 0x71012adad0
void Unk_12adad0_set(const Unk_12adad0* self, Unk_12adad0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12adae0_0 {
    u8 _0[0x1b4];
    u32 field_1b4;
};
PKMN_OFFSET_ASSERT(Unk_12adae0_0, field_1b4, 0x1b4);

struct Unk_12adae0 {
    Unk_12adae0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adae0, field_0, 0x0);

// 0x71012adae0
void Unk_12adae0_set(const Unk_12adae0* self) {
    self->field_0->field_1b4 = 0x17;
}

// 0x71012adaf0
void Unk_12adaf0_update() {}

struct Unk_12adb00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adb00_arg1, field_0, 0x0);

struct Unk_12adb00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adb00, field_0, 0x0);

// 0x71012adb00
void Unk_12adb00_set(const Unk_12adb00* self, Unk_12adb00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12adb10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adb10_arg1, field_0, 0x0);

struct Unk_12adb10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adb10, field_0, 0x0);

// 0x71012adb10
void Unk_12adb10_set(const Unk_12adb10* self, Unk_12adb10_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012adb70
void Unk_12adb70_update() {}

struct Unk_12adb80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adb80_arg1, field_0, 0x0);

struct Unk_12adb80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adb80, field_0, 0x0);

// 0x71012adb80
void Unk_12adb80_set(const Unk_12adb80* self, Unk_12adb80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12adb90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adb90_arg1, field_0, 0x0);

struct Unk_12adb90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12adb90, field_0, 0x0);

// 0x71012adb90
void Unk_12adb90_set(const Unk_12adb90* self, Unk_12adb90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27ee9ac_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27ee9ac_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ee9ac_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ee9ac_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ee9ac_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27ee9ac_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ee9ac_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ee9ac_Data, field_18, 0x18);

extern Unk_27ee9ac_Data Unk_27ee9ac __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71012adba0
void Unk_12adba0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ee9ac.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ee9ac.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ee9ac.field_18 = 0xffff;
    Unk_27ee9ac.field_10 = 0;
    Unk_27ee9ac.field_8 = r2;
    Unk_27ee9ac.field_c = 0;
    Unk_27ee9ac.field_14 = 0xffffffff;
}
