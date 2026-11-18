// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710143bd70
void Unk_143bd70_update() {}

struct Unk_143bd80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143bd80_arg1, field_0, 0x0);

struct Unk_143bd80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143bd80, field_0, 0x0);

// 0x710143bd80
void Unk_143bd80_set(const Unk_143bd80* self, Unk_143bd80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_143bd90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143bd90_arg1, field_0, 0x0);

struct Unk_143bd90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143bd90, field_0, 0x0);

// 0x710143bd90
void Unk_143bd90_set(const Unk_143bd90* self, Unk_143bd90_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710143d040
void Unk_143d040_update() {}

struct Unk_143d050 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_143d050, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_143d050, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_143d050, field_10, 0x10);

// 0x710143d050
void Unk_143d050_set(const Unk_143d050* self, Unk_143d050* value) {
    *value = *self;
}

struct Unk_143d070 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_143d070, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_143d070, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_143d070, field_10, 0x10);

// 0x710143d070
void Unk_143d070_set(const Unk_143d070* self, Unk_143d070* value) {
    *value = *self;
}

struct Unk_143d480_0 {
    u8 _0[0x5cc];
    u8 field_5cc;
    u8 _5cd[0x3];
    u32 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_143d480_0, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_143d480_0, field_5d0, 0x5d0);

struct Unk_143d480 {
    Unk_143d480_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_143d480, field_0, 0x0);

// 0x710143d480
void Unk_143d480_set(const Unk_143d480* self) {
    Unk_143d480_0* p0 = self->field_0;
    p0->field_5d0 = 0;
    p0->field_5cc = 1;
}

// 0x710143d4a0
void Unk_143d4a0_update() {}

struct Unk_143d4b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143d4b0_arg1, field_0, 0x0);

struct Unk_143d4b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143d4b0, field_0, 0x0);

// 0x710143d4b0
void Unk_143d4b0_set(const Unk_143d4b0* self, Unk_143d4b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_143d4c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143d4c0_arg1, field_0, 0x0);

struct Unk_143d4c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143d4c0, field_0, 0x0);

// 0x710143d4c0
void Unk_143d4c0_set(const Unk_143d4c0* self, Unk_143d4c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_143fce0 {
    u8 _0[0x700];
    u64 field_700;
};
PKMN_OFFSET_ASSERT(Unk_143fce0, field_700, 0x700);

// 0x710143fce0
void Unk_143fce0_setField700(Unk_143fce0* self, u64 value) {
    self->field_700 = value;
}

void Unk_eb6230(void*, u32);

// 0x7101442c40
void Unk_1442c40_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_1443160 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u32 field_20;
    u8 _24[0x4];
    u64 field_28;
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_1443160, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1443160, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1443160, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1443160, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1443160, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1443160, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_1443160, field_30, 0x30);

// 0x7101443160
void Unk_1443160_set(Unk_1443160* self) {
    self->field_20 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_28 = 0;
    self->field_30 = 0;
}

struct Unk_1443df0 {
    u8 _0[0x20];
    u8 field_20;
    u8 _21[0x1];
    u16 field_22;
};
PKMN_OFFSET_ASSERT(Unk_1443df0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1443df0, field_22, 0x22);

// 0x7101443df0
u16 Unk_1443df0_get(const Unk_1443df0* self) {
    if (self->field_20 == 0) {
        return 0xffff;
    }
    return self->field_22;
}

struct Unk_1448b60 {
    u8 _0[0x3198];
    u64 field_3198;
};
PKMN_OFFSET_ASSERT(Unk_1448b60, field_3198, 0x3198);

void Unk_14bacd0(u64);

// 0x7101448b60
void Unk_1448b60_call(const Unk_1448b60* self) {
    Unk_14bacd0(self->field_3198);
}

// 0x71014499e0
void Unk_14499e0_update() {}

struct Unk_14499f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14499f0_arg1, field_0, 0x0);

struct Unk_14499f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14499f0, field_0, 0x0);

// 0x71014499f0
void Unk_14499f0_set(const Unk_14499f0* self, Unk_14499f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1449a00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1449a00_arg1, field_0, 0x0);

struct Unk_1449a00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1449a00, field_0, 0x0);

// 0x7101449a00
void Unk_1449a00_set(const Unk_1449a00* self, Unk_1449a00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101449b30
void Unk_1449b30_update() {}

struct Unk_1449b40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1449b40_arg1, field_0, 0x0);

struct Unk_1449b40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1449b40, field_0, 0x0);

// 0x7101449b40
void Unk_1449b40_set(const Unk_1449b40* self, Unk_1449b40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1449b50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1449b50_arg1, field_0, 0x0);

struct Unk_1449b50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1449b50, field_0, 0x0);

// 0x7101449b50
void Unk_1449b50_set(const Unk_1449b50* self, Unk_1449b50_arg1* value) {
    value->field_0 = self->field_0;
}
