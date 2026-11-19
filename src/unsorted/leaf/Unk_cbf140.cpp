// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_27e06a0;
void Unk_c50830(u64, u32);

// 0x7100cbf140
void Unk_cbf140_call() {
    Unk_c50830(Unk_27e06a0, 9);
}

extern u64 Unk_27e06a0;
void Unk_c50830(u64, u32);

// 0x7100cbf990
void Unk_cbf990_call() {
    Unk_c50830(Unk_27e06a0, 0xa);
}

struct Unk_cc1260_e8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

struct Unk_cc1260 {
    u8 _0[0xe8];
    Unk_cc1260_e8* field_e8;
};
PKMN_OFFSET_ASSERT(Unk_cc1260, field_e8, 0xe8);

// 0x7100cc1260
void Unk_cc1260_call(const Unk_cc1260* self) {
    self->field_e8->vf9();
}

struct Unk_cc65c0_e8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u32);
};

struct Unk_cc65c0 {
    u8 _0[0xe8];
    Unk_cc65c0_e8* field_e8;
};
PKMN_OFFSET_ASSERT(Unk_cc65c0, field_e8, 0xe8);

// 0x7100cc65c0
void Unk_cc65c0_call(const Unk_cc65c0* self, bool value) {
    self->field_e8->vf7(value);
}

struct Unk_ccb550_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_ccb550 {
    Unk_ccb550_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccb550, field_0, 0x0);

// 0x7100ccb550
void Unk_ccb550_call(const Unk_ccb550* self) {
    self->field_0->vf13();
}

// 0x7100ccb560
void Unk_ccb560_update() {}

struct Unk_ccb570_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccb570_arg1, field_0, 0x0);

struct Unk_ccb570 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccb570, field_0, 0x0);

// 0x7100ccb570
void Unk_ccb570_set(const Unk_ccb570* self, Unk_ccb570_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccb580_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccb580_arg1, field_0, 0x0);

struct Unk_ccb580 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccb580, field_0, 0x0);

// 0x7100ccb580
void Unk_ccb580_set(const Unk_ccb580* self, Unk_ccb580_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccc2c0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_ccc2c0 {
    Unk_ccc2c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccc2c0, field_0, 0x0);

// 0x7100ccc2c0
void Unk_ccc2c0_call(const Unk_ccc2c0* self) {
    self->field_0->vf13();
}

// 0x7100ccc2d0
void Unk_ccc2d0_update() {}

struct Unk_ccc2e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccc2e0_arg1, field_0, 0x0);

struct Unk_ccc2e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccc2e0, field_0, 0x0);

// 0x7100ccc2e0
void Unk_ccc2e0_set(const Unk_ccc2e0* self, Unk_ccc2e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccc2f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccc2f0_arg1, field_0, 0x0);

struct Unk_ccc2f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccc2f0, field_0, 0x0);

// 0x7100ccc2f0
void Unk_ccc2f0_set(const Unk_ccc2f0* self, Unk_ccc2f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccc9e0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_ccc9e0 {
    Unk_ccc9e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccc9e0, field_0, 0x0);

// 0x7100ccc9e0
void Unk_ccc9e0_call(const Unk_ccc9e0* self) {
    self->field_0->vf13();
}

// 0x7100ccc9f0
void Unk_ccc9f0_update() {}

struct Unk_ccca00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccca00_arg1, field_0, 0x0);

struct Unk_ccca00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccca00, field_0, 0x0);

// 0x7100ccca00
void Unk_ccca00_set(const Unk_ccca00* self, Unk_ccca00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccca10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccca10_arg1, field_0, 0x0);

struct Unk_ccca10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccca10, field_0, 0x0);

// 0x7100ccca10
void Unk_ccca10_set(const Unk_ccca10* self, Unk_ccca10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccd100_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_ccd100 {
    Unk_ccd100_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccd100, field_0, 0x0);

// 0x7100ccd100
void Unk_ccd100_call(const Unk_ccd100* self) {
    self->field_0->vf13();
}

// 0x7100ccd110
void Unk_ccd110_update() {}

struct Unk_ccd120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccd120_arg1, field_0, 0x0);

struct Unk_ccd120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccd120, field_0, 0x0);

// 0x7100ccd120
void Unk_ccd120_set(const Unk_ccd120* self, Unk_ccd120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccd130_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccd130_arg1, field_0, 0x0);

struct Unk_ccd130 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccd130, field_0, 0x0);

// 0x7100ccd130
void Unk_ccd130_set(const Unk_ccd130* self, Unk_ccd130_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccda90_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_ccda90 {
    Unk_ccda90_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccda90, field_0, 0x0);

// 0x7100ccda90
void Unk_ccda90_call(const Unk_ccda90* self) {
    self->field_0->vf13();
}

// 0x7100ccdaa0
void Unk_ccdaa0_update() {}

struct Unk_ccdab0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccdab0_arg1, field_0, 0x0);

struct Unk_ccdab0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccdab0, field_0, 0x0);

// 0x7100ccdab0
void Unk_ccdab0_set(const Unk_ccdab0* self, Unk_ccdab0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccdac0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccdac0_arg1, field_0, 0x0);

struct Unk_ccdac0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccdac0, field_0, 0x0);

// 0x7100ccdac0
void Unk_ccdac0_set(const Unk_ccdac0* self, Unk_ccdac0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cce1a0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cce1a0 {
    Unk_cce1a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce1a0, field_0, 0x0);

// 0x7100cce1a0
void Unk_cce1a0_call(const Unk_cce1a0* self) {
    self->field_0->vf13();
}

// 0x7100cce1b0
void Unk_cce1b0_update() {}

struct Unk_cce1c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce1c0_arg1, field_0, 0x0);

struct Unk_cce1c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce1c0, field_0, 0x0);

// 0x7100cce1c0
void Unk_cce1c0_set(const Unk_cce1c0* self, Unk_cce1c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cce1d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce1d0_arg1, field_0, 0x0);

struct Unk_cce1d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce1d0, field_0, 0x0);

// 0x7100cce1d0
void Unk_cce1d0_set(const Unk_cce1d0* self, Unk_cce1d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cce8b0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cce8b0 {
    Unk_cce8b0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce8b0, field_0, 0x0);

// 0x7100cce8b0
void Unk_cce8b0_call(const Unk_cce8b0* self) {
    self->field_0->vf13();
}

// 0x7100cce8c0
void Unk_cce8c0_update() {}

struct Unk_cce8d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce8d0_arg1, field_0, 0x0);

struct Unk_cce8d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce8d0, field_0, 0x0);

// 0x7100cce8d0
void Unk_cce8d0_set(const Unk_cce8d0* self, Unk_cce8d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cce8e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce8e0_arg1, field_0, 0x0);

struct Unk_cce8e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cce8e0, field_0, 0x0);

// 0x7100cce8e0
void Unk_cce8e0_set(const Unk_cce8e0* self, Unk_cce8e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccefc0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_ccefc0 {
    Unk_ccefc0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccefc0, field_0, 0x0);

// 0x7100ccefc0
void Unk_ccefc0_call(const Unk_ccefc0* self) {
    self->field_0->vf13();
}

// 0x7100ccefd0
void Unk_ccefd0_update() {}

struct Unk_ccefe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccefe0_arg1, field_0, 0x0);

struct Unk_ccefe0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccefe0, field_0, 0x0);

// 0x7100ccefe0
void Unk_ccefe0_set(const Unk_ccefe0* self, Unk_ccefe0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cceff0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cceff0_arg1, field_0, 0x0);

struct Unk_cceff0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cceff0, field_0, 0x0);

// 0x7100cceff0
void Unk_cceff0_set(const Unk_cceff0* self, Unk_cceff0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ccf630
void Unk_ccf630_update() {}

struct Unk_ccf640_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccf640_arg1, field_0, 0x0);

struct Unk_ccf640 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccf640, field_0, 0x0);

// 0x7100ccf640
void Unk_ccf640_set(const Unk_ccf640* self, Unk_ccf640_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccf650_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccf650_arg1, field_0, 0x0);

struct Unk_ccf650 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccf650, field_0, 0x0);

// 0x7100ccf650
void Unk_ccf650_set(const Unk_ccf650* self, Unk_ccf650_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccf870_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_ccf870 {
    Unk_ccf870_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccf870, field_0, 0x0);

// 0x7100ccf870
void Unk_ccf870_call(const Unk_ccf870* self) {
    self->field_0->vf13();
}

// 0x7100ccf880
void Unk_ccf880_update() {}

struct Unk_ccf890_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccf890_arg1, field_0, 0x0);

struct Unk_ccf890 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccf890, field_0, 0x0);

// 0x7100ccf890
void Unk_ccf890_set(const Unk_ccf890* self, Unk_ccf890_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccf8a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccf8a0_arg1, field_0, 0x0);

struct Unk_ccf8a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccf8a0, field_0, 0x0);

// 0x7100ccf8a0
void Unk_ccf8a0_set(const Unk_ccf8a0* self, Unk_ccf8a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccff80_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_ccff80 {
    Unk_ccff80_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccff80, field_0, 0x0);

// 0x7100ccff80
void Unk_ccff80_call(const Unk_ccff80* self) {
    self->field_0->vf13();
}

// 0x7100ccff90
void Unk_ccff90_update() {}

struct Unk_ccffa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccffa0_arg1, field_0, 0x0);

struct Unk_ccffa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccffa0, field_0, 0x0);

// 0x7100ccffa0
void Unk_ccffa0_set(const Unk_ccffa0* self, Unk_ccffa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ccffb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccffb0_arg1, field_0, 0x0);

struct Unk_ccffb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ccffb0, field_0, 0x0);

// 0x7100ccffb0
void Unk_ccffb0_set(const Unk_ccffb0* self, Unk_ccffb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd0690_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd0690 {
    Unk_cd0690_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd0690, field_0, 0x0);

// 0x7100cd0690
void Unk_cd0690_call(const Unk_cd0690* self) {
    self->field_0->vf13();
}

// 0x7100cd06a0
void Unk_cd06a0_update() {}

struct Unk_cd06b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd06b0_arg1, field_0, 0x0);

struct Unk_cd06b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd06b0, field_0, 0x0);

// 0x7100cd06b0
void Unk_cd06b0_set(const Unk_cd06b0* self, Unk_cd06b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd06c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd06c0_arg1, field_0, 0x0);

struct Unk_cd06c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd06c0, field_0, 0x0);

// 0x7100cd06c0
void Unk_cd06c0_set(const Unk_cd06c0* self, Unk_cd06c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd0da0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd0da0 {
    Unk_cd0da0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd0da0, field_0, 0x0);

// 0x7100cd0da0
void Unk_cd0da0_call(const Unk_cd0da0* self) {
    self->field_0->vf13();
}

// 0x7100cd0db0
void Unk_cd0db0_update() {}

struct Unk_cd0dc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd0dc0_arg1, field_0, 0x0);

struct Unk_cd0dc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd0dc0, field_0, 0x0);

// 0x7100cd0dc0
void Unk_cd0dc0_set(const Unk_cd0dc0* self, Unk_cd0dc0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd0dd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd0dd0_arg1, field_0, 0x0);

struct Unk_cd0dd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd0dd0, field_0, 0x0);

// 0x7100cd0dd0
void Unk_cd0dd0_set(const Unk_cd0dd0* self, Unk_cd0dd0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd14b0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd14b0 {
    Unk_cd14b0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd14b0, field_0, 0x0);

// 0x7100cd14b0
void Unk_cd14b0_call(const Unk_cd14b0* self) {
    self->field_0->vf13();
}

// 0x7100cd14c0
void Unk_cd14c0_update() {}

struct Unk_cd14d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd14d0_arg1, field_0, 0x0);

struct Unk_cd14d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd14d0, field_0, 0x0);

// 0x7100cd14d0
void Unk_cd14d0_set(const Unk_cd14d0* self, Unk_cd14d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd14e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd14e0_arg1, field_0, 0x0);

struct Unk_cd14e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd14e0, field_0, 0x0);

// 0x7100cd14e0
void Unk_cd14e0_set(const Unk_cd14e0* self, Unk_cd14e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd1bd0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd1bd0 {
    Unk_cd1bd0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd1bd0, field_0, 0x0);

// 0x7100cd1bd0
void Unk_cd1bd0_call(const Unk_cd1bd0* self) {
    self->field_0->vf13();
}

// 0x7100cd1be0
void Unk_cd1be0_update() {}

struct Unk_cd1bf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd1bf0_arg1, field_0, 0x0);

struct Unk_cd1bf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd1bf0, field_0, 0x0);

// 0x7100cd1bf0
void Unk_cd1bf0_set(const Unk_cd1bf0* self, Unk_cd1bf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd1c00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd1c00_arg1, field_0, 0x0);

struct Unk_cd1c00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd1c00, field_0, 0x0);

// 0x7100cd1c00
void Unk_cd1c00_set(const Unk_cd1c00* self, Unk_cd1c00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd22e0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd22e0 {
    Unk_cd22e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd22e0, field_0, 0x0);

// 0x7100cd22e0
void Unk_cd22e0_call(const Unk_cd22e0* self) {
    self->field_0->vf13();
}

// 0x7100cd22f0
void Unk_cd22f0_update() {}

struct Unk_cd2300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd2300_arg1, field_0, 0x0);

struct Unk_cd2300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd2300, field_0, 0x0);

// 0x7100cd2300
void Unk_cd2300_set(const Unk_cd2300* self, Unk_cd2300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd2310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd2310_arg1, field_0, 0x0);

struct Unk_cd2310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd2310, field_0, 0x0);

// 0x7100cd2310
void Unk_cd2310_set(const Unk_cd2310* self, Unk_cd2310_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd29f0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd29f0 {
    Unk_cd29f0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd29f0, field_0, 0x0);

// 0x7100cd29f0
void Unk_cd29f0_call(const Unk_cd29f0* self) {
    self->field_0->vf13();
}

// 0x7100cd2a00
void Unk_cd2a00_update() {}

struct Unk_cd2a10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd2a10_arg1, field_0, 0x0);

struct Unk_cd2a10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd2a10, field_0, 0x0);

// 0x7100cd2a10
void Unk_cd2a10_set(const Unk_cd2a10* self, Unk_cd2a10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd2a20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd2a20_arg1, field_0, 0x0);

struct Unk_cd2a20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd2a20, field_0, 0x0);

// 0x7100cd2a20
void Unk_cd2a20_set(const Unk_cd2a20* self, Unk_cd2a20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd3100_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd3100 {
    Unk_cd3100_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3100, field_0, 0x0);

// 0x7100cd3100
void Unk_cd3100_call(const Unk_cd3100* self) {
    self->field_0->vf13();
}

// 0x7100cd3110
void Unk_cd3110_update() {}

struct Unk_cd3120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3120_arg1, field_0, 0x0);

struct Unk_cd3120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3120, field_0, 0x0);

// 0x7100cd3120
void Unk_cd3120_set(const Unk_cd3120* self, Unk_cd3120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd3130_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3130_arg1, field_0, 0x0);

struct Unk_cd3130 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3130, field_0, 0x0);

// 0x7100cd3130
void Unk_cd3130_set(const Unk_cd3130* self, Unk_cd3130_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd3810_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd3810 {
    Unk_cd3810_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3810, field_0, 0x0);

// 0x7100cd3810
void Unk_cd3810_call(const Unk_cd3810* self) {
    self->field_0->vf13();
}

// 0x7100cd3820
void Unk_cd3820_update() {}

struct Unk_cd3830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3830_arg1, field_0, 0x0);

struct Unk_cd3830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3830, field_0, 0x0);

// 0x7100cd3830
void Unk_cd3830_set(const Unk_cd3830* self, Unk_cd3830_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd3840_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3840_arg1, field_0, 0x0);

struct Unk_cd3840 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3840, field_0, 0x0);

// 0x7100cd3840
void Unk_cd3840_set(const Unk_cd3840* self, Unk_cd3840_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd3f20_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd3f20 {
    Unk_cd3f20_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3f20, field_0, 0x0);

// 0x7100cd3f20
void Unk_cd3f20_call(const Unk_cd3f20* self) {
    self->field_0->vf13();
}

// 0x7100cd3f30
void Unk_cd3f30_update() {}

struct Unk_cd3f40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3f40_arg1, field_0, 0x0);

struct Unk_cd3f40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3f40, field_0, 0x0);

// 0x7100cd3f40
void Unk_cd3f40_set(const Unk_cd3f40* self, Unk_cd3f40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd3f50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3f50_arg1, field_0, 0x0);

struct Unk_cd3f50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd3f50, field_0, 0x0);

// 0x7100cd3f50
void Unk_cd3f50_set(const Unk_cd3f50* self, Unk_cd3f50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd4630_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd4630 {
    Unk_cd4630_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4630, field_0, 0x0);

// 0x7100cd4630
void Unk_cd4630_call(const Unk_cd4630* self) {
    self->field_0->vf13();
}

// 0x7100cd4640
void Unk_cd4640_update() {}

struct Unk_cd4650_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4650_arg1, field_0, 0x0);

struct Unk_cd4650 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4650, field_0, 0x0);

// 0x7100cd4650
void Unk_cd4650_set(const Unk_cd4650* self, Unk_cd4650_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd4660_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4660_arg1, field_0, 0x0);

struct Unk_cd4660 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4660, field_0, 0x0);

// 0x7100cd4660
void Unk_cd4660_set(const Unk_cd4660* self, Unk_cd4660_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd4d40_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd4d40 {
    Unk_cd4d40_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4d40, field_0, 0x0);

// 0x7100cd4d40
void Unk_cd4d40_call(const Unk_cd4d40* self) {
    self->field_0->vf13();
}

// 0x7100cd4d50
void Unk_cd4d50_update() {}

struct Unk_cd4d60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4d60_arg1, field_0, 0x0);

struct Unk_cd4d60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4d60, field_0, 0x0);

// 0x7100cd4d60
void Unk_cd4d60_set(const Unk_cd4d60* self, Unk_cd4d60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd4d70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4d70_arg1, field_0, 0x0);

struct Unk_cd4d70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd4d70, field_0, 0x0);

// 0x7100cd4d70
void Unk_cd4d70_set(const Unk_cd4d70* self, Unk_cd4d70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd5460_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd5460 {
    Unk_cd5460_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5460, field_0, 0x0);

// 0x7100cd5460
void Unk_cd5460_call(const Unk_cd5460* self) {
    self->field_0->vf13();
}

// 0x7100cd5470
void Unk_cd5470_update() {}

struct Unk_cd5480_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5480_arg1, field_0, 0x0);

struct Unk_cd5480 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5480, field_0, 0x0);

// 0x7100cd5480
void Unk_cd5480_set(const Unk_cd5480* self, Unk_cd5480_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd5490_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5490_arg1, field_0, 0x0);

struct Unk_cd5490 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5490, field_0, 0x0);

// 0x7100cd5490
void Unk_cd5490_set(const Unk_cd5490* self, Unk_cd5490_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd5b70_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd5b70 {
    Unk_cd5b70_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5b70, field_0, 0x0);

// 0x7100cd5b70
void Unk_cd5b70_call(const Unk_cd5b70* self) {
    self->field_0->vf13();
}

// 0x7100cd5b80
void Unk_cd5b80_update() {}

struct Unk_cd5b90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5b90_arg1, field_0, 0x0);

struct Unk_cd5b90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5b90, field_0, 0x0);

// 0x7100cd5b90
void Unk_cd5b90_set(const Unk_cd5b90* self, Unk_cd5b90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd5ba0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5ba0_arg1, field_0, 0x0);

struct Unk_cd5ba0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd5ba0, field_0, 0x0);

// 0x7100cd5ba0
void Unk_cd5ba0_set(const Unk_cd5ba0* self, Unk_cd5ba0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd6280_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd6280 {
    Unk_cd6280_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd6280, field_0, 0x0);

// 0x7100cd6280
void Unk_cd6280_call(const Unk_cd6280* self) {
    self->field_0->vf13();
}

// 0x7100cd6290
void Unk_cd6290_update() {}

struct Unk_cd62a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd62a0_arg1, field_0, 0x0);

struct Unk_cd62a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd62a0, field_0, 0x0);

// 0x7100cd62a0
void Unk_cd62a0_set(const Unk_cd62a0* self, Unk_cd62a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd62b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd62b0_arg1, field_0, 0x0);

struct Unk_cd62b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd62b0, field_0, 0x0);

// 0x7100cd62b0
void Unk_cd62b0_set(const Unk_cd62b0* self, Unk_cd62b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd6990_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd6990 {
    Unk_cd6990_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd6990, field_0, 0x0);

// 0x7100cd6990
void Unk_cd6990_call(const Unk_cd6990* self) {
    self->field_0->vf13();
}

// 0x7100cd69a0
void Unk_cd69a0_update() {}

struct Unk_cd69b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd69b0_arg1, field_0, 0x0);

struct Unk_cd69b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd69b0, field_0, 0x0);

// 0x7100cd69b0
void Unk_cd69b0_set(const Unk_cd69b0* self, Unk_cd69b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd69c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd69c0_arg1, field_0, 0x0);

struct Unk_cd69c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd69c0, field_0, 0x0);

// 0x7100cd69c0
void Unk_cd69c0_set(const Unk_cd69c0* self, Unk_cd69c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd70a0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd70a0 {
    Unk_cd70a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd70a0, field_0, 0x0);

// 0x7100cd70a0
void Unk_cd70a0_call(const Unk_cd70a0* self) {
    self->field_0->vf13();
}

// 0x7100cd70b0
void Unk_cd70b0_update() {}

struct Unk_cd70c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd70c0_arg1, field_0, 0x0);

struct Unk_cd70c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd70c0, field_0, 0x0);

// 0x7100cd70c0
void Unk_cd70c0_set(const Unk_cd70c0* self, Unk_cd70c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd70d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd70d0_arg1, field_0, 0x0);

struct Unk_cd70d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd70d0, field_0, 0x0);

// 0x7100cd70d0
void Unk_cd70d0_set(const Unk_cd70d0* self, Unk_cd70d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd77b0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd77b0 {
    Unk_cd77b0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd77b0, field_0, 0x0);

// 0x7100cd77b0
void Unk_cd77b0_call(const Unk_cd77b0* self) {
    self->field_0->vf13();
}

// 0x7100cd77c0
void Unk_cd77c0_update() {}

struct Unk_cd77d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd77d0_arg1, field_0, 0x0);

struct Unk_cd77d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd77d0, field_0, 0x0);

// 0x7100cd77d0
void Unk_cd77d0_set(const Unk_cd77d0* self, Unk_cd77d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd77e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd77e0_arg1, field_0, 0x0);

struct Unk_cd77e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd77e0, field_0, 0x0);

// 0x7100cd77e0
void Unk_cd77e0_set(const Unk_cd77e0* self, Unk_cd77e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd7ec0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd7ec0 {
    Unk_cd7ec0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd7ec0, field_0, 0x0);

// 0x7100cd7ec0
void Unk_cd7ec0_call(const Unk_cd7ec0* self) {
    self->field_0->vf13();
}

// 0x7100cd7ed0
void Unk_cd7ed0_update() {}

struct Unk_cd7ee0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd7ee0_arg1, field_0, 0x0);

struct Unk_cd7ee0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd7ee0, field_0, 0x0);

// 0x7100cd7ee0
void Unk_cd7ee0_set(const Unk_cd7ee0* self, Unk_cd7ee0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd7ef0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd7ef0_arg1, field_0, 0x0);

struct Unk_cd7ef0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd7ef0, field_0, 0x0);

// 0x7100cd7ef0
void Unk_cd7ef0_set(const Unk_cd7ef0* self, Unk_cd7ef0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd85d0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd85d0 {
    Unk_cd85d0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd85d0, field_0, 0x0);

// 0x7100cd85d0
void Unk_cd85d0_call(const Unk_cd85d0* self) {
    self->field_0->vf13();
}

// 0x7100cd85e0
void Unk_cd85e0_update() {}

struct Unk_cd85f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd85f0_arg1, field_0, 0x0);

struct Unk_cd85f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd85f0, field_0, 0x0);

// 0x7100cd85f0
void Unk_cd85f0_set(const Unk_cd85f0* self, Unk_cd85f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd8600_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd8600_arg1, field_0, 0x0);

struct Unk_cd8600 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd8600, field_0, 0x0);

// 0x7100cd8600
void Unk_cd8600_set(const Unk_cd8600* self, Unk_cd8600_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd8ce0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd8ce0 {
    Unk_cd8ce0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd8ce0, field_0, 0x0);

// 0x7100cd8ce0
void Unk_cd8ce0_call(const Unk_cd8ce0* self) {
    self->field_0->vf13();
}

// 0x7100cd8cf0
void Unk_cd8cf0_update() {}

struct Unk_cd8d00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd8d00_arg1, field_0, 0x0);

struct Unk_cd8d00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd8d00, field_0, 0x0);

// 0x7100cd8d00
void Unk_cd8d00_set(const Unk_cd8d00* self, Unk_cd8d00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd8d10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd8d10_arg1, field_0, 0x0);

struct Unk_cd8d10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd8d10, field_0, 0x0);

// 0x7100cd8d10
void Unk_cd8d10_set(const Unk_cd8d10* self, Unk_cd8d10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd93f0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd93f0 {
    Unk_cd93f0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd93f0, field_0, 0x0);

// 0x7100cd93f0
void Unk_cd93f0_call(const Unk_cd93f0* self) {
    self->field_0->vf13();
}

// 0x7100cd9400
void Unk_cd9400_update() {}

struct Unk_cd9410_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd9410_arg1, field_0, 0x0);

struct Unk_cd9410 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd9410, field_0, 0x0);

// 0x7100cd9410
void Unk_cd9410_set(const Unk_cd9410* self, Unk_cd9410_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd9420_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd9420_arg1, field_0, 0x0);

struct Unk_cd9420 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd9420, field_0, 0x0);

// 0x7100cd9420
void Unk_cd9420_set(const Unk_cd9420* self, Unk_cd9420_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd9b00_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cd9b00 {
    Unk_cd9b00_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd9b00, field_0, 0x0);

// 0x7100cd9b00
void Unk_cd9b00_call(const Unk_cd9b00* self) {
    self->field_0->vf13();
}

// 0x7100cd9b10
void Unk_cd9b10_update() {}

struct Unk_cd9b20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd9b20_arg1, field_0, 0x0);

struct Unk_cd9b20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd9b20, field_0, 0x0);

// 0x7100cd9b20
void Unk_cd9b20_set(const Unk_cd9b20* self, Unk_cd9b20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cd9b30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd9b30_arg1, field_0, 0x0);

struct Unk_cd9b30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cd9b30, field_0, 0x0);

// 0x7100cd9b30
void Unk_cd9b30_set(const Unk_cd9b30* self, Unk_cd9b30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cda210_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cda210 {
    Unk_cda210_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda210, field_0, 0x0);

// 0x7100cda210
void Unk_cda210_call(const Unk_cda210* self) {
    self->field_0->vf13();
}

// 0x7100cda220
void Unk_cda220_update() {}

struct Unk_cda230_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda230_arg1, field_0, 0x0);

struct Unk_cda230 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda230, field_0, 0x0);

// 0x7100cda230
void Unk_cda230_set(const Unk_cda230* self, Unk_cda230_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cda240_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda240_arg1, field_0, 0x0);

struct Unk_cda240 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda240, field_0, 0x0);

// 0x7100cda240
void Unk_cda240_set(const Unk_cda240* self, Unk_cda240_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cda930_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

struct Unk_cda930 {
    Unk_cda930_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda930, field_0, 0x0);

// 0x7100cda930
void Unk_cda930_call(const Unk_cda930* self) {
    self->field_0->vf13();
}

// 0x7100cda940
void Unk_cda940_update() {}

struct Unk_cda950_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda950_arg1, field_0, 0x0);

struct Unk_cda950 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda950, field_0, 0x0);

// 0x7100cda950
void Unk_cda950_set(const Unk_cda950* self, Unk_cda950_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cda960_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda960_arg1, field_0, 0x0);

struct Unk_cda960 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cda960, field_0, 0x0);

// 0x7100cda960
void Unk_cda960_set(const Unk_cda960* self, Unk_cda960_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100cdae90
void Unk_cdae90_update() {}

// 0x7100cdaea0
void Unk_cdaea0_update() {}

// 0x7100cdaeb0
void Unk_cdaeb0_update() {}

struct Unk_cdbce0_arg1_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u64 vf9();
};

struct Unk_cdbce0_arg1 {
    Unk_cdbce0_arg1_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdbce0_arg1, field_0, 0x0);

struct Unk_cdbce0_0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdbce0_0, field_0, 0x0);

struct Unk_cdbce0 {
    Unk_cdbce0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdbce0, field_0, 0x0);

// 0x7100cdbce0
bool Unk_cdbce0_call(const Unk_cdbce0* self, const Unk_cdbce0_arg1* value) {
    u64 r0 = value->field_0->vf9();
    return r0 == self->field_0->field_0;
}

// 0x7100cdbd20
void Unk_cdbd20_update() {}

struct Unk_cdbd30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdbd30_arg1, field_0, 0x0);

struct Unk_cdbd30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdbd30, field_0, 0x0);

// 0x7100cdbd30
void Unk_cdbd30_set(const Unk_cdbd30* self, Unk_cdbd30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cdbd40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdbd40_arg1, field_0, 0x0);

struct Unk_cdbd40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdbd40, field_0, 0x0);

// 0x7100cdbd40
void Unk_cdbd40_set(const Unk_cdbd40* self, Unk_cdbd40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100cdbe70
void Unk_cdbe70_update() {}

struct Unk_cdbe80 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_cdbe80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_cdbe80, field_8, 0x8);

// 0x7100cdbe80
void Unk_cdbe80_set(const Unk_cdbe80* self, Unk_cdbe80* value) {
    *value = *self;
}

struct Unk_cdbe90 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_cdbe90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_cdbe90, field_8, 0x8);

// 0x7100cdbe90
void Unk_cdbe90_set(const Unk_cdbe90* self, Unk_cdbe90* value) {
    *value = *self;
}

struct Unk_cdc030_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc030_arg1, field_0, 0x0);

struct Unk_cdc030_0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc030_0, field_0, 0x0);

struct Unk_cdc030 {
    Unk_cdc030_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc030, field_0, 0x0);

void Unk_eec870(u64, u64, u32);

// 0x7100cdc030
void Unk_cdc030_call(const Unk_cdc030* self, const Unk_cdc030_arg1* value) {
    Unk_eec870(value->field_0, self->field_0->field_0, 0);
}

// 0x7100cdc050
void Unk_cdc050_update() {}

struct Unk_cdc060_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc060_arg1, field_0, 0x0);

struct Unk_cdc060 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc060, field_0, 0x0);

// 0x7100cdc060
void Unk_cdc060_set(const Unk_cdc060* self, Unk_cdc060_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cdc070_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc070_arg1, field_0, 0x0);

struct Unk_cdc070 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc070, field_0, 0x0);

// 0x7100cdc070
void Unk_cdc070_set(const Unk_cdc070* self, Unk_cdc070_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cdc080_arg2 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc080_arg2, field_0, 0x0);

struct Unk_cdc080_0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc080_0, field_0, 0x0);

struct Unk_cdc080 {
    Unk_cdc080_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc080, field_0, 0x0);

void Unk_eec870(u64, u64, u32);

// 0x7100cdc080
void Unk_cdc080_call(const Unk_cdc080* self, u64 /*unused*/, const Unk_cdc080_arg2* arg2) {
    Unk_eec870(arg2->field_0, self->field_0->field_0, 0);
}

// 0x7100cdc0a0
void Unk_cdc0a0_update() {}

struct Unk_cdc0b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc0b0_arg1, field_0, 0x0);

struct Unk_cdc0b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc0b0, field_0, 0x0);

// 0x7100cdc0b0
void Unk_cdc0b0_set(const Unk_cdc0b0* self, Unk_cdc0b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cdc0c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc0c0_arg1, field_0, 0x0);

struct Unk_cdc0c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdc0c0, field_0, 0x0);

// 0x7100cdc0c0
void Unk_cdc0c0_set(const Unk_cdc0c0* self, Unk_cdc0c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100cdc7a0
void Unk_cdc7a0_update() {}

struct Unk_cdc7b0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_cdc7b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_cdc7b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_cdc7b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_cdc7b0, field_18, 0x18);

// 0x7100cdc7b0
void Unk_cdc7b0_set(const Unk_cdc7b0* self, Unk_cdc7b0* value) {
    *value = *self;
}

struct Unk_cdc7d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_cdc7d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_cdc7d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_cdc7d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_cdc7d0, field_18, 0x18);

// 0x7100cdc7d0
void Unk_cdc7d0_set(const Unk_cdc7d0* self, Unk_cdc7d0* value) {
    *value = *self;
}

struct Unk_cdcab0_arg2_0 {
    u8 _0[0x390];
    u64 field_390;
    u8 _398[0x10];
    u8 field_3a8;
};
PKMN_OFFSET_ASSERT(Unk_cdcab0_arg2_0, field_390, 0x390);
PKMN_OFFSET_ASSERT(Unk_cdcab0_arg2_0, field_3a8, 0x3a8);

struct Unk_cdcab0_arg2 {
    Unk_cdcab0_arg2_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdcab0_arg2, field_0, 0x0);

struct Unk_cdcab0_0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdcab0_0, field_0, 0x0);

struct Unk_cdcab0 {
    Unk_cdcab0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdcab0, field_0, 0x0);

// 0x7100cdcab0
bool Unk_cdcab0_check(const Unk_cdcab0* self, u32 /*unused*/, const Unk_cdcab0_arg2* arg2) {
    if (arg2->field_0->field_390 != self->field_0->field_0) {
        return false;
    }
    return arg2->field_0->field_3a8 != 0;
}

// 0x7100cdcae0
void Unk_cdcae0_update() {}

struct Unk_cdcaf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdcaf0_arg1, field_0, 0x0);

struct Unk_cdcaf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdcaf0, field_0, 0x0);

// 0x7100cdcaf0
void Unk_cdcaf0_set(const Unk_cdcaf0* self, Unk_cdcaf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cdcb00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdcb00_arg1, field_0, 0x0);

struct Unk_cdcb00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdcb00, field_0, 0x0);

// 0x7100cdcb00
void Unk_cdcb00_set(const Unk_cdcb00* self, Unk_cdcb00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100cdcda0
void Unk_cdcda0_update() {}

struct Unk_cdcdb0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_cdcdb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_cdcdb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_cdcdb0, field_10, 0x10);

// 0x7100cdcdb0
void Unk_cdcdb0_set(const Unk_cdcdb0* self, Unk_cdcdb0* value) {
    *value = *self;
}

struct Unk_cdcdd0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_cdcdd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_cdcdd0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_cdcdd0, field_10, 0x10);

// 0x7100cdcdd0
void Unk_cdcdd0_set(const Unk_cdcdd0* self, Unk_cdcdd0* value) {
    *value = *self;
}

// 0x7100cdce60
void Unk_cdce60_update() {}

struct Unk_cdce70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdce70_arg1, field_0, 0x0);

struct Unk_cdce70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdce70, field_0, 0x0);

// 0x7100cdce70
void Unk_cdce70_set(const Unk_cdce70* self, Unk_cdce70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cdce80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdce80_arg1, field_0, 0x0);

struct Unk_cdce80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cdce80, field_0, 0x0);

// 0x7100cdce80
void Unk_cdce80_set(const Unk_cdce80* self, Unk_cdce80_arg1* value) {
    value->field_0 = self->field_0;
}
