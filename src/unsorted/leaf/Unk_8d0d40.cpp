// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8d0d40_60 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_8d0d40_60, field_78, 0x78);

struct Unk_8d0d40 {
    u8 _0[0x60];
    Unk_8d0d40_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_8d0d40, field_60, 0x60);

u32 Unk_14db6e0(u64);

// 0x71008d0d40
bool Unk_8d0d40_call(const Unk_8d0d40* self) {
    if (self->field_60->field_78 == 0) {
        return false;
    }
    u32 r0 = Unk_14db6e0(self->field_60->field_78);
    return r0 == 0;
}

struct Unk_8d7c80 {
    u8 _0[0x6b4];
    u32 field_6b4;
};
PKMN_OFFSET_ASSERT(Unk_8d7c80, field_6b4, 0x6b4);

// 0x71008d7c80
u32 Unk_8d7c80_getField6b4(const Unk_8d7c80* self) {
    return self->field_6b4;
}

struct Unk_8d86e0_0 {
    u8 _0[0x5e0];
    u64 field_5e0;
    u8 _5e8[0xc8];
    u32 field_6b0;
};
PKMN_OFFSET_ASSERT(Unk_8d86e0_0, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_8d86e0_0, field_6b0, 0x6b0);

struct Unk_8d86e0 {
    Unk_8d86e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d86e0, field_0, 0x0);

void Unk_14e1a30(u64, u32);

// 0x71008d86e0
void Unk_8d86e0_call(const Unk_8d86e0* self) {
    Unk_8d86e0_0* p0 = self->field_0;
    p0->field_6b0 = 1;
    Unk_14e1a30(p0->field_5e0, 0);
}

// 0x71008d8700
void Unk_8d8700_update() {}

struct Unk_8d8710_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8710_arg1, field_0, 0x0);

struct Unk_8d8710 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8710, field_0, 0x0);

// 0x71008d8710
void Unk_8d8710_set(const Unk_8d8710* self, Unk_8d8710_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8d8720_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8720_arg1, field_0, 0x0);

struct Unk_8d8720 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8720, field_0, 0x0);

// 0x71008d8720
void Unk_8d8720_set(const Unk_8d8720* self, Unk_8d8720_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8d8730_0 {
    u8 _0[0x5e0];
    u64 field_5e0;
    u8 _5e8[0xc8];
    u32 field_6b0;
};
PKMN_OFFSET_ASSERT(Unk_8d8730_0, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_8d8730_0, field_6b0, 0x6b0);

struct Unk_8d8730 {
    Unk_8d8730_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8730, field_0, 0x0);

void Unk_14e1a30(u64, u32);

// 0x71008d8730
void Unk_8d8730_call(const Unk_8d8730* self) {
    Unk_8d8730_0* p0 = self->field_0;
    p0->field_6b0 = 3;
    Unk_14e1a30(p0->field_5e0, 0);
}

// 0x71008d8750
void Unk_8d8750_update() {}

struct Unk_8d8760_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8760_arg1, field_0, 0x0);

struct Unk_8d8760 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8760, field_0, 0x0);

// 0x71008d8760
void Unk_8d8760_set(const Unk_8d8760* self, Unk_8d8760_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8d8770_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8770_arg1, field_0, 0x0);

struct Unk_8d8770 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8770, field_0, 0x0);

// 0x71008d8770
void Unk_8d8770_set(const Unk_8d8770* self, Unk_8d8770_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71008d8800
void Unk_8d8800_update() {}

struct Unk_8d8810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8810_arg1, field_0, 0x0);

struct Unk_8d8810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8810, field_0, 0x0);

// 0x71008d8810
void Unk_8d8810_set(const Unk_8d8810* self, Unk_8d8810_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8d8820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8820_arg1, field_0, 0x0);

struct Unk_8d8820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8d8820, field_0, 0x0);

// 0x71008d8820
void Unk_8d8820_set(const Unk_8d8820* self, Unk_8d8820_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8da650_0 {
    u8 _0[0xa68];
    u8 field_a68;
};
PKMN_OFFSET_ASSERT(Unk_8da650_0, field_a68, 0xa68);

struct Unk_8da650 {
    Unk_8da650_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8da650, field_0, 0x0);

// 0x71008da650
void Unk_8da650_set(const Unk_8da650* self) {
    self->field_0->field_a68 = 1;
}

// 0x71008da660
void Unk_8da660_update() {}

struct Unk_8da670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8da670_arg1, field_0, 0x0);

struct Unk_8da670 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8da670, field_0, 0x0);

// 0x71008da670
void Unk_8da670_set(const Unk_8da670* self, Unk_8da670_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8da680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8da680_arg1, field_0, 0x0);

struct Unk_8da680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8da680, field_0, 0x0);

// 0x71008da680
void Unk_8da680_set(const Unk_8da680* self, Unk_8da680_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8e04b0 {
    u8 _0[0x188];
    u64 field_188;
};
PKMN_OFFSET_ASSERT(Unk_8e04b0, field_188, 0x188);

// 0x71008e04b0
bool Unk_8e04b0_check(const Unk_8e04b0* self) {
    return self->field_188 != 0;
}

struct Unk_8e0710_188 {
    u8 _0[0x5a1];
    u8 field_5a1;
};
PKMN_OFFSET_ASSERT(Unk_8e0710_188, field_5a1, 0x5a1);

struct Unk_8e0710 {
    u8 _0[0x188];
    Unk_8e0710_188* field_188;
};
PKMN_OFFSET_ASSERT(Unk_8e0710, field_188, 0x188);

// 0x71008e0710
u8 Unk_8e0710_get(const Unk_8e0710* self) {
    if (self->field_188 == nullptr) {
        return 0;
    }
    return self->field_188->field_5a1;
}

struct Unk_8e1430_180 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8e1430_180, field_60, 0x60);

struct Unk_8e1430 {
    u8 _0[0x180];
    Unk_8e1430_180* field_180;
};
PKMN_OFFSET_ASSERT(Unk_8e1430, field_180, 0x180);

u32 Unk_65c7c0(void*, u32);

// 0x71008e1430
u32 Unk_8e1430_call(const Unk_8e1430* self) {
    if (self->field_180 == nullptr) {
        return 0;
    }
    u32 r0 = Unk_65c7c0(&self->field_180->field_60, 0x22fc);
    return r0 & 0xffff;
}

struct Unk_8e1460_188 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8e1460_188, field_60, 0x60);

struct Unk_8e1460 {
    u8 _0[0x188];
    Unk_8e1460_188* field_188;
};
PKMN_OFFSET_ASSERT(Unk_8e1460, field_188, 0x188);

u32 Unk_65c7c0(void*, u32);

// 0x71008e1460
u32 Unk_8e1460_call(const Unk_8e1460* self) {
    if (self->field_188 == nullptr) {
        return 0;
    }
    u32 r0 = Unk_65c7c0(&self->field_188->field_60, 0x640);
    return r0 & 0xffff;
}

// 0x71008e16c0
void Unk_8e16c0_update() {}

struct Unk_8e16d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e16d0_arg1, field_0, 0x0);

struct Unk_8e16d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e16d0, field_0, 0x0);

// 0x71008e16d0
void Unk_8e16d0_set(const Unk_8e16d0* self, Unk_8e16d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8e16e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e16e0_arg1, field_0, 0x0);

struct Unk_8e16e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e16e0, field_0, 0x0);

// 0x71008e16e0
void Unk_8e16e0_set(const Unk_8e16e0* self, Unk_8e16e0_arg1* value) {
    value->field_0 = self->field_0;
}
