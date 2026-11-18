// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100fb1040
void Unk_fb1040_update() {}

struct Unk_fb1050_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1050_arg1, field_0, 0x0);

struct Unk_fb1050 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1050, field_0, 0x0);

// 0x7100fb1050
void Unk_fb1050_set(const Unk_fb1050* self, Unk_fb1050_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1060_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1060_arg1, field_0, 0x0);

struct Unk_fb1060 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1060, field_0, 0x0);

// 0x7100fb1060
void Unk_fb1060_set(const Unk_fb1060* self, Unk_fb1060_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1070_0 {
    u8 _0[0x7c];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_fb1070_0, field_7c, 0x7c);

struct Unk_fb1070 {
    Unk_fb1070_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1070, field_0, 0x0);

// 0x7100fb1070
void Unk_fb1070_set(const Unk_fb1070* self) {
    self->field_0->field_7c = 5;
}

// 0x7100fb1080
void Unk_fb1080_update() {}

struct Unk_fb1090_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1090_arg1, field_0, 0x0);

struct Unk_fb1090 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1090, field_0, 0x0);

// 0x7100fb1090
void Unk_fb1090_set(const Unk_fb1090* self, Unk_fb1090_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb10a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb10a0_arg1, field_0, 0x0);

struct Unk_fb10a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb10a0, field_0, 0x0);

// 0x7100fb10a0
void Unk_fb10a0_set(const Unk_fb10a0* self, Unk_fb10a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb1130
void Unk_fb1130_update() {}

struct Unk_fb1140_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1140_arg1, field_0, 0x0);

struct Unk_fb1140 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1140, field_0, 0x0);

// 0x7100fb1140
void Unk_fb1140_set(const Unk_fb1140* self, Unk_fb1140_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1150_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1150_arg1, field_0, 0x0);

struct Unk_fb1150 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1150, field_0, 0x0);

// 0x7100fb1150
void Unk_fb1150_set(const Unk_fb1150* self, Unk_fb1150_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fb1160_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fb1160_0, field_360, 0x360);

struct Unk_fb1160 {
    Unk_fb1160_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1160, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fb1160
void Unk_fb1160_call(const Unk_fb1160* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fb1170
void Unk_fb1170_update() {}

struct Unk_fb1180_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1180_arg1, field_0, 0x0);

struct Unk_fb1180 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1180, field_0, 0x0);

// 0x7100fb1180
void Unk_fb1180_set(const Unk_fb1180* self, Unk_fb1180_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1190_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1190_arg1, field_0, 0x0);

struct Unk_fb1190 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1190, field_0, 0x0);

// 0x7100fb1190
void Unk_fb1190_set(const Unk_fb1190* self, Unk_fb1190_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb1220
void Unk_fb1220_update() {}

struct Unk_fb1230_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1230_arg1, field_0, 0x0);

struct Unk_fb1230 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1230, field_0, 0x0);

// 0x7100fb1230
void Unk_fb1230_set(const Unk_fb1230* self, Unk_fb1230_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1240_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1240_arg1, field_0, 0x0);

struct Unk_fb1240 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1240, field_0, 0x0);

// 0x7100fb1240
void Unk_fb1240_set(const Unk_fb1240* self, Unk_fb1240_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb1250
void Unk_fb1250_update() {}

// 0x7100fb1260
void Unk_fb1260_update() {}

// 0x7100fb1270
void Unk_fb1270_update() {}

// 0x7100fb1280
void Unk_fb1280_update() {}

// 0x7100fb12b0
void Unk_fb12b0_update() {}

struct Unk_fb12c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb12c0_arg1, field_0, 0x0);

struct Unk_fb12c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb12c0, field_0, 0x0);

// 0x7100fb12c0
void Unk_fb12c0_set(const Unk_fb12c0* self, Unk_fb12c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb12d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb12d0_arg1, field_0, 0x0);

struct Unk_fb12d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb12d0, field_0, 0x0);

// 0x7100fb12d0
void Unk_fb12d0_set(const Unk_fb12d0* self, Unk_fb12d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb12e0_0 {
    u8 _0[0x378];
    u32 field_378;
};
PKMN_OFFSET_ASSERT(Unk_fb12e0_0, field_378, 0x378);

struct Unk_fb12e0 {
    Unk_fb12e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb12e0, field_0, 0x0);

void Unk_fb0a70(void*, u32);

// 0x7100fb12e0
void Unk_fb12e0_call(const Unk_fb12e0* self) {
    Unk_fb0a70(self->field_0, self->field_0->field_378);
}

// 0x7100fb12f0
void Unk_fb12f0_update() {}

struct Unk_fb1300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1300_arg1, field_0, 0x0);

struct Unk_fb1300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1300, field_0, 0x0);

// 0x7100fb1300
void Unk_fb1300_set(const Unk_fb1300* self, Unk_fb1300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1310_arg1, field_0, 0x0);

struct Unk_fb1310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1310, field_0, 0x0);

// 0x7100fb1310
void Unk_fb1310_set(const Unk_fb1310* self, Unk_fb1310_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fb1320_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fb1320_0, field_360, 0x360);

struct Unk_fb1320 {
    Unk_fb1320_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1320, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fb1320
void Unk_fb1320_call(const Unk_fb1320* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fb1330
void Unk_fb1330_update() {}

struct Unk_fb1340_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1340_arg1, field_0, 0x0);

struct Unk_fb1340 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1340, field_0, 0x0);

// 0x7100fb1340
void Unk_fb1340_set(const Unk_fb1340* self, Unk_fb1340_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1350_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1350_arg1, field_0, 0x0);

struct Unk_fb1350 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1350, field_0, 0x0);

// 0x7100fb1350
void Unk_fb1350_set(const Unk_fb1350* self, Unk_fb1350_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb13d0
void Unk_fb13d0_update() {}

struct Unk_fb13e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb13e0_arg1, field_0, 0x0);

struct Unk_fb13e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb13e0, field_0, 0x0);

// 0x7100fb13e0
void Unk_fb13e0_set(const Unk_fb13e0* self, Unk_fb13e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb13f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb13f0_arg1, field_0, 0x0);

struct Unk_fb13f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb13f0, field_0, 0x0);

// 0x7100fb13f0
void Unk_fb13f0_set(const Unk_fb13f0* self, Unk_fb13f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fb1400_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fb1400_0, field_360, 0x360);

struct Unk_fb1400 {
    Unk_fb1400_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1400, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fb1400
void Unk_fb1400_call(const Unk_fb1400* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fb1410
void Unk_fb1410_update() {}

struct Unk_fb1420_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1420_arg1, field_0, 0x0);

struct Unk_fb1420 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1420, field_0, 0x0);

// 0x7100fb1420
void Unk_fb1420_set(const Unk_fb1420* self, Unk_fb1420_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1430_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1430_arg1, field_0, 0x0);

struct Unk_fb1430 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1430, field_0, 0x0);

// 0x7100fb1430
void Unk_fb1430_set(const Unk_fb1430* self, Unk_fb1430_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb14b0
void Unk_fb14b0_update() {}

struct Unk_fb14c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb14c0_arg1, field_0, 0x0);

struct Unk_fb14c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb14c0, field_0, 0x0);

// 0x7100fb14c0
void Unk_fb14c0_set(const Unk_fb14c0* self, Unk_fb14c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb14d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb14d0_arg1, field_0, 0x0);

struct Unk_fb14d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb14d0, field_0, 0x0);

// 0x7100fb14d0
void Unk_fb14d0_set(const Unk_fb14d0* self, Unk_fb14d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fb14e0_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fb14e0_0, field_360, 0x360);

struct Unk_fb14e0 {
    Unk_fb14e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb14e0, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fb14e0
void Unk_fb14e0_call(const Unk_fb14e0* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fb14f0
void Unk_fb14f0_update() {}

struct Unk_fb1500_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1500_arg1, field_0, 0x0);

struct Unk_fb1500 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1500, field_0, 0x0);

// 0x7100fb1500
void Unk_fb1500_set(const Unk_fb1500* self, Unk_fb1500_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1510_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1510_arg1, field_0, 0x0);

struct Unk_fb1510 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1510, field_0, 0x0);

// 0x7100fb1510
void Unk_fb1510_set(const Unk_fb1510* self, Unk_fb1510_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb15a0
void Unk_fb15a0_update() {}

struct Unk_fb15b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb15b0_arg1, field_0, 0x0);

struct Unk_fb15b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb15b0, field_0, 0x0);

// 0x7100fb15b0
void Unk_fb15b0_set(const Unk_fb15b0* self, Unk_fb15b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb15c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb15c0_arg1, field_0, 0x0);

struct Unk_fb15c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb15c0, field_0, 0x0);

// 0x7100fb15c0
void Unk_fb15c0_set(const Unk_fb15c0* self, Unk_fb15c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb16c0
void Unk_fb16c0_update() {}

struct Unk_fb16d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb16d0_arg1, field_0, 0x0);

struct Unk_fb16d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb16d0, field_0, 0x0);

// 0x7100fb16d0
void Unk_fb16d0_set(const Unk_fb16d0* self, Unk_fb16d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb16e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb16e0_arg1, field_0, 0x0);

struct Unk_fb16e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb16e0, field_0, 0x0);

// 0x7100fb16e0
void Unk_fb16e0_set(const Unk_fb16e0* self, Unk_fb16e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fb16f0_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fb16f0_0, field_360, 0x360);

struct Unk_fb16f0 {
    Unk_fb16f0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb16f0, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fb16f0
void Unk_fb16f0_call(const Unk_fb16f0* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fb1700
void Unk_fb1700_update() {}

struct Unk_fb1710_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1710_arg1, field_0, 0x0);

struct Unk_fb1710 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1710, field_0, 0x0);

// 0x7100fb1710
void Unk_fb1710_set(const Unk_fb1710* self, Unk_fb1710_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1720_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1720_arg1, field_0, 0x0);

struct Unk_fb1720 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1720, field_0, 0x0);

// 0x7100fb1720
void Unk_fb1720_set(const Unk_fb1720* self, Unk_fb1720_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1730_0 {
    u8 _0[0x7c];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_fb1730_0, field_7c, 0x7c);

struct Unk_fb1730 {
    Unk_fb1730_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1730, field_0, 0x0);

// 0x7100fb1730
void Unk_fb1730_set(const Unk_fb1730* self) {
    self->field_0->field_7c = 0xc;
}

// 0x7100fb1740
void Unk_fb1740_update() {}

struct Unk_fb1750_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1750_arg1, field_0, 0x0);

struct Unk_fb1750 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1750, field_0, 0x0);

// 0x7100fb1750
void Unk_fb1750_set(const Unk_fb1750* self, Unk_fb1750_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1760_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1760_arg1, field_0, 0x0);

struct Unk_fb1760 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1760, field_0, 0x0);

// 0x7100fb1760
void Unk_fb1760_set(const Unk_fb1760* self, Unk_fb1760_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb17f0
void Unk_fb17f0_update() {}

struct Unk_fb1800_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1800_arg1, field_0, 0x0);

struct Unk_fb1800 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1800, field_0, 0x0);

// 0x7100fb1800
void Unk_fb1800_set(const Unk_fb1800* self, Unk_fb1800_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1810_arg1, field_0, 0x0);

struct Unk_fb1810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1810, field_0, 0x0);

// 0x7100fb1810
void Unk_fb1810_set(const Unk_fb1810* self, Unk_fb1810_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fb1820_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fb1820_0, field_360, 0x360);

struct Unk_fb1820 {
    Unk_fb1820_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1820, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fb1820
void Unk_fb1820_call(const Unk_fb1820* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fb1830
void Unk_fb1830_update() {}

struct Unk_fb1840_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1840_arg1, field_0, 0x0);

struct Unk_fb1840 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1840, field_0, 0x0);

// 0x7100fb1840
void Unk_fb1840_set(const Unk_fb1840* self, Unk_fb1840_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1850_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1850_arg1, field_0, 0x0);

struct Unk_fb1850 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1850, field_0, 0x0);

// 0x7100fb1850
void Unk_fb1850_set(const Unk_fb1850* self, Unk_fb1850_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb1950
void Unk_fb1950_update() {}

struct Unk_fb1960_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1960_arg1, field_0, 0x0);

struct Unk_fb1960 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1960, field_0, 0x0);

// 0x7100fb1960
void Unk_fb1960_set(const Unk_fb1960* self, Unk_fb1960_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1970_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1970_arg1, field_0, 0x0);

struct Unk_fb1970 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1970, field_0, 0x0);

// 0x7100fb1970
void Unk_fb1970_set(const Unk_fb1970* self, Unk_fb1970_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb19f0
void Unk_fb19f0_update() {}

struct Unk_fb1a00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1a00_arg1, field_0, 0x0);

struct Unk_fb1a00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1a00, field_0, 0x0);

// 0x7100fb1a00
void Unk_fb1a00_set(const Unk_fb1a00* self, Unk_fb1a00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1a10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1a10_arg1, field_0, 0x0);

struct Unk_fb1a10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1a10, field_0, 0x0);

// 0x7100fb1a10
void Unk_fb1a10_set(const Unk_fb1a10* self, Unk_fb1a10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fb1a20_0 {
    u8 _0[0x360];
    Unk_e807f0* field_360;
};
PKMN_OFFSET_ASSERT(Unk_fb1a20_0, field_360, 0x360);

struct Unk_fb1a20 {
    Unk_fb1a20_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1a20, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fb1a20
void Unk_fb1a20_call(const Unk_fb1a20* self) {
    Unk_e807f0_call(self->field_0->field_360, false);
}

// 0x7100fb1a30
void Unk_fb1a30_update() {}

struct Unk_fb1a40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1a40_arg1, field_0, 0x0);

struct Unk_fb1a40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1a40, field_0, 0x0);

// 0x7100fb1a40
void Unk_fb1a40_set(const Unk_fb1a40* self, Unk_fb1a40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1a50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1a50_arg1, field_0, 0x0);

struct Unk_fb1a50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1a50, field_0, 0x0);

// 0x7100fb1a50
void Unk_fb1a50_set(const Unk_fb1a50* self, Unk_fb1a50_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb1b10
void Unk_fb1b10_update() {}

struct Unk_fb1b20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1b20_arg1, field_0, 0x0);

struct Unk_fb1b20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1b20, field_0, 0x0);

// 0x7100fb1b20
void Unk_fb1b20_set(const Unk_fb1b20* self, Unk_fb1b20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1b30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1b30_arg1, field_0, 0x0);

struct Unk_fb1b30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1b30, field_0, 0x0);

// 0x7100fb1b30
void Unk_fb1b30_set(const Unk_fb1b30* self, Unk_fb1b30_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb1b40
void Unk_fb1b40_update() {}

// 0x7100fb1b50
void Unk_fb1b50_update() {}

// 0x7100fb1b60
void Unk_fb1b60_update() {}

// 0x7100fb1b70
void Unk_fb1b70_update() {}

// 0x7100fb1c00
void Unk_fb1c00_update() {}

struct Unk_fb1c10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1c10_arg1, field_0, 0x0);

struct Unk_fb1c10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1c10, field_0, 0x0);

// 0x7100fb1c10
void Unk_fb1c10_set(const Unk_fb1c10* self, Unk_fb1c10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb1c20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1c20_arg1, field_0, 0x0);

struct Unk_fb1c20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb1c20, field_0, 0x0);

// 0x7100fb1c20
void Unk_fb1c20_set(const Unk_fb1c20* self, Unk_fb1c20_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb1c30
void Unk_fb1c30_update() {}

// 0x7100fb1c40
void Unk_fb1c40_update() {}

// 0x7100fb1c50
void Unk_fb1c50_update() {}

// 0x7100fb1c60
void Unk_fb1c60_update() {}
