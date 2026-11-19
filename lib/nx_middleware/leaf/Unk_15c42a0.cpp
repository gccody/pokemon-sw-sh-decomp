// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_15c42a0 {
    u8 _0[0x10];
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_15c42a0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15c42a0, field_18, 0x18);

// 0x71015c42a0
u64 Unk_15c42a0_get(const Unk_15c42a0* self) {
    return self->field_10 == self->field_18 ? 0 : self->field_10;
}

struct Unk_15c42b0 {
    u8 _0[0x10];
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_15c42b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15c42b0, field_18, 0x18);

// 0x71015c42b0
u64 Unk_15c42b0_get(const Unk_15c42b0* self) {
    return self->field_18 - self->field_10;
}

struct Unk_15c7560_10 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_15c7560_10, field_18, 0x18);

struct Unk_15c7560 {
    u8 _0[0x10];
    Unk_15c7560_10* field_10;
    u8 _18[0x10];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_15c7560, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15c7560, field_28, 0x28);

// 0x71015c7560
void Unk_15c7560_set(Unk_15c7560* self) {
    self->field_28 = self->field_10->field_18 << 3;
}

extern u64 Unk_244f8e0 __attribute__((visibility("hidden")));

// 0x71015c7dc0
u64 Unk_15c7dc0_get() {
    return Unk_244f8e0;
}

struct Unk_15c8420_arg1 {
    u8 _0[0x10];
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u8 field_30;
    u8 field_31;
    u8 field_32;
};
PKMN_OFFSET_ASSERT(Unk_15c8420_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15c8420_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_15c8420_arg1, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_15c8420_arg1, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_15c8420_arg1, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_15c8420_arg1, field_31, 0x31);
PKMN_OFFSET_ASSERT(Unk_15c8420_arg1, field_32, 0x32);

struct Unk_15c8420 {
    u8 _0[0x10];
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u8 field_30;
    u8 field_31;
    u8 field_32;
};
PKMN_OFFSET_ASSERT(Unk_15c8420, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15c8420, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_15c8420, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_15c8420, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_15c8420, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_15c8420, field_31, 0x31);
PKMN_OFFSET_ASSERT(Unk_15c8420, field_32, 0x32);

// 0x71015c8420
void Unk_15c8420_set(Unk_15c8420* self, Unk_15c8420_arg1* value) {
    u64 v0 = self->field_10;
    self->field_10 = value->field_10;
    value->field_10 = v0;
    u64 v1 = self->field_18;
    self->field_18 = value->field_18;
    value->field_18 = v1;
    u64 v2 = self->field_20;
    self->field_20 = value->field_20;
    value->field_20 = v2;
    u64 v3 = self->field_28;
    self->field_28 = value->field_28;
    value->field_28 = v3;
    u8 v4 = self->field_30;
    self->field_30 = value->field_30;
    value->field_30 = v4;
    u8 v5 = self->field_31;
    self->field_31 = value->field_31;
    value->field_31 = v5;
    u8 v6 = self->field_32;
    self->field_32 = value->field_32;
    value->field_32 = v6;
}

struct Unk_15c85c0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_15c85c0, field_18, 0x18);

// 0x71015c85c0
void Unk_15c85c0_set(Unk_15c85c0* self) {
    self->field_18 = self->field_18 - 1;
}

struct Unk_15c9350 {
    u8 _0[0x70];
    u64 field_70;
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_15c9350, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_15c9350, field_78, 0x78);

// 0x71015c9350
void Unk_15c9350_set(Unk_15c9350* self, u64 value, u32 arg2) {
    self->field_70 = value;
    self->field_78 = arg2;
}

void Unk_15ca5c0();

// 0x71015ca5b0
void Unk_15ca5b0_call() {
    Unk_15ca5c0();
}

struct Unk_15caa30 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_15caa30, field_10, 0x10);

// 0x71015caa30
void Unk_15caa30_set(Unk_15caa30* self, u32 value) {
    self->field_10 = self->field_10 | value;
}

void Unk_15cb150();

// 0x71015cb140
void Unk_15cb140_call() {
    Unk_15cb150();
}

struct Unk_15cc220 {
    u8 _0[0x20];
    u64 field_20;
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_15cc220, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_15cc220, field_28, 0x28);

// 0x71015cc220
void Unk_15cc220_set(Unk_15cc220* self) {
    self->field_28 = 2;
    self->field_20 = 0;
}

void Unk_15ce010();

// 0x71015ce000
void Unk_15ce000_call() {
    Unk_15ce010();
}

struct Unk_15ce600 {
    u8 _0[0x10];
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_15ce600, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15ce600, field_18, 0x18);

// 0x71015ce600
u64 Unk_15ce600_get(const Unk_15ce600* self) {
    return self->field_10 == self->field_18 ? 0 : self->field_10;
}

struct Unk_15ce860_20 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_15ce860_20, field_10, 0x10);

struct Unk_15ce860 {
    u8 _0[0x20];
    Unk_15ce860_20* field_20;
    u8 _28[0x8];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_15ce860, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_15ce860, field_30, 0x30);

// 0x71015ce860
u64 Unk_15ce860_get(const Unk_15ce860* self) {
    if (self->field_30 == 0) {
        return 0;
    }
    return self->field_20->field_10;
}

struct Unk_15d2cd0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_15d2cd0, field_18, 0x18);

// 0x71015d2cd0
void Unk_15d2cd0_set(Unk_15d2cd0* self, u32 value) {
    self->field_18 = value;
}
