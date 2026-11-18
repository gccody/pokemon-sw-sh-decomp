// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100f8fea0
void Unk_f8fea0_update() {}

// 0x7100f8feb0
void Unk_f8feb0_update() {}

// 0x7100f8fec0
void Unk_f8fec0_update() {}

// 0x7100f8fed0
void Unk_f8fed0_update() {}

// 0x7100f8ff20
void Unk_f8ff20_update() {}

struct Unk_f8ff30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ff30_arg1, field_0, 0x0);

struct Unk_f8ff30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ff30, field_0, 0x0);

// 0x7100f8ff30
void Unk_f8ff30_set(const Unk_f8ff30* self, Unk_f8ff30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f8ff40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ff40_arg1, field_0, 0x0);

struct Unk_f8ff40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f8ff40, field_0, 0x0);

// 0x7100f8ff40
void Unk_f8ff40_set(const Unk_f8ff40* self, Unk_f8ff40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f90080
void Unk_f90080_update() {}

struct Unk_f90090_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90090_arg1, field_0, 0x0);

struct Unk_f90090 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90090, field_0, 0x0);

// 0x7100f90090
void Unk_f90090_set(const Unk_f90090* self, Unk_f90090_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f900a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f900a0_arg1, field_0, 0x0);

struct Unk_f900a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f900a0, field_0, 0x0);

// 0x7100f900a0
void Unk_f900a0_set(const Unk_f900a0* self, Unk_f900a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f900b0_0 {
    u8 _0[0x1f8];
    u8 field_1f8;
    u8 _1f9[0x3];
    u32 field_1fc;
};
PKMN_OFFSET_ASSERT(Unk_f900b0_0, field_1f8, 0x1f8);
PKMN_OFFSET_ASSERT(Unk_f900b0_0, field_1fc, 0x1fc);

struct Unk_f900b0 {
    Unk_f900b0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f900b0, field_0, 0x0);

// 0x7100f900b0
void Unk_f900b0_set(const Unk_f900b0* self) {
    Unk_f900b0_0* p0 = self->field_0;
    p0->field_1fc = 3;
    p0->field_1f8 = 1;
}

// 0x7100f900d0
void Unk_f900d0_update() {}

struct Unk_f900e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f900e0_arg1, field_0, 0x0);

struct Unk_f900e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f900e0, field_0, 0x0);

// 0x7100f900e0
void Unk_f900e0_set(const Unk_f900e0* self, Unk_f900e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f900f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f900f0_arg1, field_0, 0x0);

struct Unk_f900f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f900f0, field_0, 0x0);

// 0x7100f900f0
void Unk_f900f0_set(const Unk_f900f0* self, Unk_f900f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f90100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90100, field_0, 0x0);

void Unk_f89de0(u64, u32);

// 0x7100f90100
void Unk_f90100_call(const Unk_f90100* self) {
    Unk_f89de0(self->field_0, 0);
}

// 0x7100f90110
void Unk_f90110_update() {}

struct Unk_f90120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90120_arg1, field_0, 0x0);

struct Unk_f90120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90120, field_0, 0x0);

// 0x7100f90120
void Unk_f90120_set(const Unk_f90120* self, Unk_f90120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f90130_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90130_arg1, field_0, 0x0);

struct Unk_f90130 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90130, field_0, 0x0);

// 0x7100f90130
void Unk_f90130_set(const Unk_f90130* self, Unk_f90130_arg1* value) {
    value->field_0 = self->field_0;
}
