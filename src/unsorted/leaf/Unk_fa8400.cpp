// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100fa8400
void Unk_fa8400_update() {}

struct Unk_fa8410_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8410_arg1, field_0, 0x0);

struct Unk_fa8410 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8410, field_0, 0x0);

// 0x7100fa8410
void Unk_fa8410_set(const Unk_fa8410* self, Unk_fa8410_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8420_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8420_arg1, field_0, 0x0);

struct Unk_fa8420 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8420, field_0, 0x0);

// 0x7100fa8420
void Unk_fa8420_set(const Unk_fa8420* self, Unk_fa8420_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8430_0 {
    u8 _0[0x380];
    u32 field_380;
};
PKMN_OFFSET_ASSERT(Unk_fa8430_0, field_380, 0x380);

struct Unk_fa8430 {
    Unk_fa8430_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8430, field_0, 0x0);

void Unk_fa76f0(void*, u32);

// 0x7100fa8430
void Unk_fa8430_call(const Unk_fa8430* self) {
    Unk_fa76f0(self->field_0, self->field_0->field_380);
}

// 0x7100fa8440
void Unk_fa8440_update() {}

struct Unk_fa8450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8450_arg1, field_0, 0x0);

struct Unk_fa8450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8450, field_0, 0x0);

// 0x7100fa8450
void Unk_fa8450_set(const Unk_fa8450* self, Unk_fa8450_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8460_arg1, field_0, 0x0);

struct Unk_fa8460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8460, field_0, 0x0);

// 0x7100fa8460
void Unk_fa8460_set(const Unk_fa8460* self, Unk_fa8460_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fa8470_0 {
    u8 _0[0x340];
    Unk_e807f0* field_340;
};
PKMN_OFFSET_ASSERT(Unk_fa8470_0, field_340, 0x340);

struct Unk_fa8470 {
    Unk_fa8470_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8470, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fa8470
void Unk_fa8470_call(const Unk_fa8470* self) {
    Unk_e807f0_call(self->field_0->field_340, false);
}

// 0x7100fa8480
void Unk_fa8480_update() {}

struct Unk_fa8490_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8490_arg1, field_0, 0x0);

struct Unk_fa8490 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8490, field_0, 0x0);

// 0x7100fa8490
void Unk_fa8490_set(const Unk_fa8490* self, Unk_fa8490_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa84a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa84a0_arg1, field_0, 0x0);

struct Unk_fa84a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa84a0, field_0, 0x0);

// 0x7100fa84a0
void Unk_fa84a0_set(const Unk_fa84a0* self, Unk_fa84a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fa84d0
void Unk_fa84d0_update() {}

struct Unk_fa84e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa84e0_arg1, field_0, 0x0);

struct Unk_fa84e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa84e0, field_0, 0x0);

// 0x7100fa84e0
void Unk_fa84e0_set(const Unk_fa84e0* self, Unk_fa84e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa84f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa84f0_arg1, field_0, 0x0);

struct Unk_fa84f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa84f0, field_0, 0x0);

// 0x7100fa84f0
void Unk_fa84f0_set(const Unk_fa84f0* self, Unk_fa84f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fa8500_0 {
    u8 _0[0x340];
    Unk_e807f0* field_340;
};
PKMN_OFFSET_ASSERT(Unk_fa8500_0, field_340, 0x340);

struct Unk_fa8500 {
    Unk_fa8500_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8500, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fa8500
void Unk_fa8500_call(const Unk_fa8500* self) {
    Unk_e807f0_call(self->field_0->field_340, false);
}

// 0x7100fa8510
void Unk_fa8510_update() {}

struct Unk_fa8520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8520_arg1, field_0, 0x0);

struct Unk_fa8520 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8520, field_0, 0x0);

// 0x7100fa8520
void Unk_fa8520_set(const Unk_fa8520* self, Unk_fa8520_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8530_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8530_arg1, field_0, 0x0);

struct Unk_fa8530 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8530, field_0, 0x0);

// 0x7100fa8530
void Unk_fa8530_set(const Unk_fa8530* self, Unk_fa8530_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fa8560
void Unk_fa8560_update() {}

struct Unk_fa8570_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8570_arg1, field_0, 0x0);

struct Unk_fa8570 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8570, field_0, 0x0);

// 0x7100fa8570
void Unk_fa8570_set(const Unk_fa8570* self, Unk_fa8570_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8580_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8580_arg1, field_0, 0x0);

struct Unk_fa8580 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8580, field_0, 0x0);

// 0x7100fa8580
void Unk_fa8580_set(const Unk_fa8580* self, Unk_fa8580_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fa8590_0 {
    u8 _0[0x340];
    Unk_e807f0* field_340;
};
PKMN_OFFSET_ASSERT(Unk_fa8590_0, field_340, 0x340);

struct Unk_fa8590 {
    Unk_fa8590_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8590, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fa8590
void Unk_fa8590_call(const Unk_fa8590* self) {
    Unk_e807f0_call(self->field_0->field_340, false);
}

// 0x7100fa85a0
void Unk_fa85a0_update() {}

struct Unk_fa85b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa85b0_arg1, field_0, 0x0);

struct Unk_fa85b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa85b0, field_0, 0x0);

// 0x7100fa85b0
void Unk_fa85b0_set(const Unk_fa85b0* self, Unk_fa85b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa85c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa85c0_arg1, field_0, 0x0);

struct Unk_fa85c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa85c0, field_0, 0x0);

// 0x7100fa85c0
void Unk_fa85c0_set(const Unk_fa85c0* self, Unk_fa85c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8600 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa8600, field_8, 0x8);

// 0x7100fa8600
void Unk_fa8600_call(Unk_fa8600* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_fa8640_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa8640_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fa8640_arg1, field_8, 0x8);

struct Unk_fa8640 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa8640, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fa8640, field_8, 0x8);

// 0x7100fa8640
void Unk_fa8640_call(const Unk_fa8640* self, Unk_fa8640_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fa8670_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa8670_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fa8670_arg1, field_8, 0x8);

struct Unk_fa8670 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa8670, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fa8670, field_8, 0x8);

// 0x7100fa8670
void Unk_fa8670_call(const Unk_fa8670* self, Unk_fa8670_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fa8740 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa8740, field_8, 0x8);

// 0x7100fa8740
void Unk_fa8740_call(Unk_fa8740* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_fa8780_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa8780_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fa8780_arg1, field_8, 0x8);

struct Unk_fa8780 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa8780, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fa8780, field_8, 0x8);

// 0x7100fa8780
void Unk_fa8780_call(const Unk_fa8780* self, Unk_fa8780_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_fa87b0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa87b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fa87b0_arg1, field_8, 0x8);

struct Unk_fa87b0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_fa87b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fa87b0, field_8, 0x8);

// 0x7100fa87b0
void Unk_fa87b0_call(const Unk_fa87b0* self, Unk_fa87b0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x7100fa8800
void Unk_fa8800_update() {}

struct Unk_fa8810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8810_arg1, field_0, 0x0);

struct Unk_fa8810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8810, field_0, 0x0);

// 0x7100fa8810
void Unk_fa8810_set(const Unk_fa8810* self, Unk_fa8810_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8820_arg1, field_0, 0x0);

struct Unk_fa8820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8820, field_0, 0x0);

// 0x7100fa8820
void Unk_fa8820_set(const Unk_fa8820* self, Unk_fa8820_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fa8830
void Unk_fa8830_update() {}

// 0x7100fa8840
void Unk_fa8840_update() {}

// 0x7100fa8850
void Unk_fa8850_update() {}

// 0x7100fa8860
void Unk_fa8860_update() {}

// 0x7100fa8890
void Unk_fa8890_update() {}

struct Unk_fa88a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa88a0_arg1, field_0, 0x0);

struct Unk_fa88a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa88a0, field_0, 0x0);

// 0x7100fa88a0
void Unk_fa88a0_set(const Unk_fa88a0* self, Unk_fa88a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa88b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa88b0_arg1, field_0, 0x0);

struct Unk_fa88b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa88b0, field_0, 0x0);

// 0x7100fa88b0
void Unk_fa88b0_set(const Unk_fa88b0* self, Unk_fa88b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fa8900
void Unk_fa8900_update() {}

struct Unk_fa8910_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8910_arg1, field_0, 0x0);

struct Unk_fa8910 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8910, field_0, 0x0);

// 0x7100fa8910
void Unk_fa8910_set(const Unk_fa8910* self, Unk_fa8910_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8920_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8920_arg1, field_0, 0x0);

struct Unk_fa8920 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8920, field_0, 0x0);

// 0x7100fa8920
void Unk_fa8920_set(const Unk_fa8920* self, Unk_fa8920_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e807f0;
struct Unk_fa8930_0 {
    u8 _0[0x340];
    Unk_e807f0* field_340;
};
PKMN_OFFSET_ASSERT(Unk_fa8930_0, field_340, 0x340);

struct Unk_fa8930 {
    Unk_fa8930_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8930, field_0, 0x0);

void Unk_e807f0_call(Unk_e807f0*, bool);

// 0x7100fa8930
void Unk_fa8930_call(const Unk_fa8930* self) {
    Unk_e807f0_call(self->field_0->field_340, false);
}

// 0x7100fa8940
void Unk_fa8940_update() {}

struct Unk_fa8950_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8950_arg1, field_0, 0x0);

struct Unk_fa8950 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8950, field_0, 0x0);

// 0x7100fa8950
void Unk_fa8950_set(const Unk_fa8950* self, Unk_fa8950_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8960_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8960_arg1, field_0, 0x0);

struct Unk_fa8960 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8960, field_0, 0x0);

// 0x7100fa8960
void Unk_fa8960_set(const Unk_fa8960* self, Unk_fa8960_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fa8970
void Unk_fa8970_update() {}

// 0x7100fa8980
void Unk_fa8980_update() {}

// 0x7100fa8990
void Unk_fa8990_update() {}

// 0x7100fa89a0
void Unk_fa89a0_update() {}

// 0x7100fa89b0
void Unk_fa89b0_update() {}

// 0x7100fa89c0
void Unk_fa89c0_update() {}

// 0x7100fa89d0
void Unk_fa89d0_update() {}

// 0x7100fa89e0
void Unk_fa89e0_update() {}

// 0x7100fa8a10
void Unk_fa8a10_update() {}

struct Unk_fa8a20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8a20_arg1, field_0, 0x0);

struct Unk_fa8a20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8a20, field_0, 0x0);

// 0x7100fa8a20
void Unk_fa8a20_set(const Unk_fa8a20* self, Unk_fa8a20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8a30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8a30_arg1, field_0, 0x0);

struct Unk_fa8a30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8a30, field_0, 0x0);

// 0x7100fa8a30
void Unk_fa8a30_set(const Unk_fa8a30* self, Unk_fa8a30_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fa8a40
void Unk_fa8a40_update() {}

// 0x7100fa8a50
void Unk_fa8a50_update() {}

// 0x7100fa8a60
void Unk_fa8a60_update() {}

// 0x7100fa8a70
void Unk_fa8a70_update() {}

// 0x7100fa8b10
void Unk_fa8b10_update() {}

struct Unk_fa8b20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8b20_arg1, field_0, 0x0);

struct Unk_fa8b20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8b20, field_0, 0x0);

// 0x7100fa8b20
void Unk_fa8b20_set(const Unk_fa8b20* self, Unk_fa8b20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fa8b30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8b30_arg1, field_0, 0x0);

struct Unk_fa8b30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa8b30, field_0, 0x0);

// 0x7100fa8b30
void Unk_fa8b30_set(const Unk_fa8b30* self, Unk_fa8b30_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fa8b40
void Unk_fa8b40_update() {}

// 0x7100fa8b50
void Unk_fa8b50_update() {}

// 0x7100fa8b60
void Unk_fa8b60_update() {}

// 0x7100fa8b70
void Unk_fa8b70_update() {}
