// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_35b310 {
    u64 field_0;
    u64 field_8;
    u16 field_10;
    u8 field_12;
    u8 _13[0x5];
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_35b310, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_35b310, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_35b310, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_35b310, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_35b310, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_35b310, field_20, 0x20);

// 0x710035b310
void Unk_35b310_set(Unk_35b310* self) {
    self->field_10 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_12 = self->field_12 & 0xfc;
    self->field_18 = 0;
    self->field_20 = 0;
}

struct Unk_35b5c0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_35b5c0, field_10, 0x10);

// 0x710035b5c0
void Unk_35b5c0_set(Unk_35b5c0* self) {
    self->field_10 = self->field_10 + 1;
}

struct Unk_35b620 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
    u16 field_10;
    u8 field_12;
};
PKMN_OFFSET_ASSERT(Unk_35b620, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_35b620, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_35b620, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_35b620, field_12, 0x12);

// 0x710035b620
void Unk_35b620_set(Unk_35b620* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_10 = 0x64;
    self->field_12 = 0;
}

struct Unk_35c6f0 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u32 field_18;
    u8 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_35c6f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_35c6f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_35c6f0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_35c6f0, field_1c, 0x1c);

// 0x710035c6f0
u32 Unk_35c6f0_update(Unk_35c6f0* self, u64 value) {
    self->field_18 = 0;
    self->field_8 = value;
    self->field_10 = 0;
    self->field_1c = 0;
    return 1;
}

struct Unk_35d290 {
    u8 _0[0x20];
    u32 field_20;
    u8 _24[0x24];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_35d290, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_35d290, field_48, 0x48);
void Unk_35c9f0(void*, u32, u32);

// 0x710035d290
void Unk_35d290_call(Unk_35d290* self) {
    if (self->field_48 == 2) {
        if (self->field_20 != 0) {
            Unk_35c9f0(self, 0, 4);
            return;
        }
        return;
    }
}

struct Unk_35f2c0 {
    u32 field_0;
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_35f2c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_35f2c0, field_4, 0x4);

// 0x710035f2c0
u32 Unk_35f2c0_update(Unk_35f2c0* self) {
    self->field_4 = 0;
    self->field_0 = 0;
    return 1;
}

extern u8 Unk_24bcb78;
void Unk_3683a0();
void Unk_3681e0();

// 0x71003681b0
void Unk_3681b0_call() {
    if (Unk_24bcb78 != 0) {
        Unk_3681e0();
    }
    Unk_3683a0();
}

// 0x71003689d0
void Unk_3689d0_update() {
}

// 0x71003689e0
void Unk_3689e0_update() {
}

struct Unk_368b00 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_368b00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_368b00, field_8, 0x8);

// 0x7100368b00
void Unk_368b00_set(Unk_368b00* self) {
    self->field_0 = 0;
    self->field_8 = 0;
}

struct Unk_369090 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_369090, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_369090, field_8, 0x8);

// 0x7100369090
void Unk_369090_set(Unk_369090* self) {
    self->field_8 = 0;
    self->field_0 = 0;
}

// 0x71003690a0
void Unk_3690a0_update() {
}

struct Unk_369910_50 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_369910_50, field_90, 0x90);

struct Unk_369910 {
    u8 _0[0x50];
    Unk_369910_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_369910, field_50, 0x50);

// 0x7100369910
u32 Unk_369910_get(const Unk_369910* self) {
    return self->field_50->field_90;
}

struct Unk_369920_50 {
    u8 _0[0x70];
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_369920_50, field_70, 0x70);

struct Unk_369920 {
    u8 _0[0x50];
    Unk_369920_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_369920, field_50, 0x50);

// 0x7100369920
u8* Unk_369920_get(const Unk_369920* self) {
    return &self->field_50->field_70;
}

struct Unk_369930 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_369930, field_50, 0x50);

// 0x7100369930
u64 Unk_369930_get(const Unk_369930* self) {
    return self->field_50;
}
