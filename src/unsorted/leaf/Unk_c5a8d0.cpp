// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c5a8d0 {
    u8 _0[0x85];
    bool field_85;
};
PKMN_OFFSET_ASSERT(Unk_c5a8d0, field_85, 0x85);

// 0x7100c5a8d0
void Unk_c5a8d0_set(Unk_c5a8d0* self, bool value) {
    self->field_85 = value;
}

struct Unk_c5ac00 {
    u8 _0[0x82];
    u8 field_82;
    u8 _83[0xa1bd];
    u8 field_a240;
};
PKMN_OFFSET_ASSERT(Unk_c5ac00, field_82, 0x82);
PKMN_OFFSET_ASSERT(Unk_c5ac00, field_a240, 0xa240);

extern "C" void* memcpy(void*, const void*, unsigned long);

// 0x7100c5ac00
void Unk_c5ac00_call(Unk_c5ac00* self, void* value) {
    memcpy(&self->field_a240, value, 0xa20);
    self->field_82 = 1;
}

struct Unk_c627e0 {
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
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27(u32);
    u8 _8[0x230];
    bool field_238;
    u8 _239[0x2];
    u8 field_23b;
};
PKMN_OFFSET_ASSERT(Unk_c627e0, field_238, 0x238);
PKMN_OFFSET_ASSERT(Unk_c627e0, field_23b, 0x23b);

// 0x7100c627e0
void Unk_c627e0_call(Unk_c627e0* self, bool value) {
    self->field_238 = value;
    if (value != 0) {
        if (self->field_23b == 0) {
            self->field_23b = 1;
            self->vf27(1);
            return;
        }
        return;
    }
    if (self->field_23b != 0) {
        self->field_23b = 0;
        self->vf27(0);
        return;
    }
}

struct Unk_c63670_2c0 {
    u8 _0[0x84];
    bool field_84;
};
PKMN_OFFSET_ASSERT(Unk_c63670_2c0, field_84, 0x84);

struct Unk_c63670 {
    u8 _0[0x2c0];
    Unk_c63670_2c0* field_2c0;
};
PKMN_OFFSET_ASSERT(Unk_c63670, field_2c0, 0x2c0);

// 0x7100c63670
void Unk_c63670_set(const Unk_c63670* self, bool value) {
    if (self->field_2c0 != nullptr) {
        self->field_2c0->field_84 = value;
    }
}

struct Unk_c63690_2c0 {
    u8 _0[0x84];
    u8 field_84;
};
PKMN_OFFSET_ASSERT(Unk_c63690_2c0, field_84, 0x84);

struct Unk_c63690 {
    u8 _0[0x2c0];
    Unk_c63690_2c0* field_2c0;
};
PKMN_OFFSET_ASSERT(Unk_c63690, field_2c0, 0x2c0);

// 0x7100c63690
bool Unk_c63690_check(const Unk_c63690* self) {
    if (self->field_2c0 == nullptr) {
        return false;
    }
    return self->field_2c0->field_84 != 0;
}

extern bool Unk_23dc938;

// 0x7100c64770
void Unk_c64770_set(bool self) {
    Unk_23dc938 = self;
}

extern f32 Unk_23dc93c;

// 0x7100c64790
void Unk_c64790_set(f32 fvalue) {
    Unk_23dc93c = fvalue;
}

extern u32 Unk_27d9b88;

// 0x7100c647b0
u32 Unk_c647b0_get() {
    return Unk_27d9b88;
}

// 0x7100c65100
void Unk_c65100_update() {}

struct Unk_c65110_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65110_arg1, field_0, 0x0);

struct Unk_c65110 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65110, field_0, 0x0);

// 0x7100c65110
void Unk_c65110_set(const Unk_c65110* self, Unk_c65110_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c65120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65120_arg1, field_0, 0x0);

struct Unk_c65120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65120, field_0, 0x0);

// 0x7100c65120
void Unk_c65120_set(const Unk_c65120* self, Unk_c65120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c65520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65520_arg1, field_0, 0x0);

struct Unk_c65520_0 {
    u8 _0[0x370];
    u32 field_370;
};
PKMN_OFFSET_ASSERT(Unk_c65520_0, field_370, 0x370);

struct Unk_c65520 {
    Unk_c65520_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65520, field_0, 0x0);

void Unk_618d40(u64, u32);

// 0x7100c65520
void Unk_c65520_call(const Unk_c65520* self, const Unk_c65520_arg1* value) {
    Unk_618d40(value->field_0, self->field_0->field_370);
}

// 0x7100c65540
void Unk_c65540_update() {}

struct Unk_c65550_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65550_arg1, field_0, 0x0);

struct Unk_c65550 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65550, field_0, 0x0);

// 0x7100c65550
void Unk_c65550_set(const Unk_c65550* self, Unk_c65550_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c65560_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65560_arg1, field_0, 0x0);

struct Unk_c65560 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c65560, field_0, 0x0);

// 0x7100c65560
void Unk_c65560_set(const Unk_c65560* self, Unk_c65560_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100c660f0
void Unk_c660f0_update() {}

struct Unk_c66100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c66100_arg1, field_0, 0x0);

struct Unk_c66100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c66100, field_0, 0x0);

// 0x7100c66100
void Unk_c66100_set(const Unk_c66100* self, Unk_c66100_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c66110_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c66110_arg1, field_0, 0x0);

struct Unk_c66110 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c66110, field_0, 0x0);

// 0x7100c66110
void Unk_c66110_set(const Unk_c66110* self, Unk_c66110_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c68570 {
    u8 _0[0xe0];
    u64 field_e0;
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_c68570, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_c68570, field_e8, 0xe8);

// 0x7100c68570
void Unk_c68570_set(Unk_c68570* self) {
    self->field_e8 = self->field_e0;
}
