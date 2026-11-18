// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_15d65c0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15d65c0, field_8, 0x8);

// 0x71015d65c0
const u8* Unk_15d65c0_get(const Unk_15d65c0* self) {
    return &self->field_8;
}

struct Unk_15d65d0 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_15d65d0, field_80, 0x80);

// 0x71015d65d0
const u8* Unk_15d65d0_get(const Unk_15d65d0* self) {
    return &self->field_80;
}

struct Unk_15d65e0 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_15d65e0, field_a8, 0xa8);

// 0x71015d65e0
u32 Unk_15d65e0_get(const Unk_15d65e0* self) {
    return self->field_a8;
}

struct Unk_15d7280 {
    u8 _0[0x48];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_15d7280, field_48, 0x48);

// 0x71015d7280
bool Unk_15d7280_check(const Unk_15d7280* self) {
    return self->field_48 == 0x40;
}

struct Unk_15d7310_arg2 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15d7310_arg2, field_0, 0x0);

struct Unk_15d7310 {
    u8 _0[0xe8];
    u64 field_e8;
    u64 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_15d7310, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_15d7310, field_f0, 0xf0);

// 0x71015d7310
void Unk_15d7310_set(Unk_15d7310* self, u64 value, const Unk_15d7310_arg2* arg2) {
    self->field_e8 = value;
    self->field_f0 = arg2->field_0;
}

struct Unk_15d8df0 {
    u8 _0[0x24];
    f32 field_24;
};
PKMN_OFFSET_ASSERT(Unk_15d8df0, field_24, 0x24);

// 0x71015d8df0
void Unk_15d8df0_set(Unk_15d8df0* self, f32 fvalue) {
    self->field_24 = fvalue;
}

struct Unk_15da8f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15da8f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_15da8f0, field_8, 0x8);

void Unk_15b9390(u64);

// 0x71015da8f0
void Unk_15da8f0_call(Unk_15da8f0* self) {
    if (self->field_0 != 0) {
        self->field_8 = self->field_0;
        Unk_15b9390(self->field_0);
    }
}

struct Unk_15de3f0_arg1_10 {
    u8 _0[0x10];
    u64 field_10;
    u64 field_18;
    u8 _20[0x8];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_15de3f0_arg1_10, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15de3f0_arg1_10, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_15de3f0_arg1_10, field_28, 0x28);

struct Unk_15de3f0_arg1 {
    u8 _0[0x10];
    Unk_15de3f0_arg1_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_15de3f0_arg1, field_10, 0x10);

void Unk_15c8ad0(void*, u64, u64);

// 0x71015de3f0
void Unk_15de3f0_call(void* self, const Unk_15de3f0_arg1* value) {
    Unk_15c8ad0(self, (value->field_10->field_10 + value->field_10->field_28) + 4, value->field_10->field_18 - 4);
}

// 0x71015df270
void Unk_15df270_update() {
}

struct Unk_15e6fc0 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_15e6fc0, field_80, 0x80);

// 0x71015e6fc0
const u8* Unk_15e6fc0_get(const Unk_15e6fc0* self) {
    return &self->field_80;
}

struct Unk_15e8d50 {
    u8 _0[0x1d1];
    bool field_1d1;
};
PKMN_OFFSET_ASSERT(Unk_15e8d50, field_1d1, 0x1d1);

// 0x71015e8d50
void Unk_15e8d50_set(Unk_15e8d50* self, bool value) {
    self->field_1d1 = value;
}

// 0x71015eaa80
u32 Unk_15eaa80_get() {
    return 3;
}
