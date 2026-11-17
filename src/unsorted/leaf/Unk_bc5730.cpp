// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_bc5730 {
    u8 _0[0x2c0];
    u32 field_2c0;
    u32 field_2c4;
    u8 _2c8[0x58];
    u32 field_320;
};
PKMN_OFFSET_ASSERT(Unk_bc5730, field_2c0, 0x2c0);
PKMN_OFFSET_ASSERT(Unk_bc5730, field_2c4, 0x2c4);
PKMN_OFFSET_ASSERT(Unk_bc5730, field_320, 0x320);

// 0x7100bc5730
void Unk_bc5730_set(Unk_bc5730* self) {
    self->field_2c0 = 5;
    self->field_2c4 = self->field_320 == 2;
}

struct Unk_bc64e0 {
    u8 _0[0x2b8];
    u64 field_2b8;
};
PKMN_OFFSET_ASSERT(Unk_bc64e0, field_2b8, 0x2b8);

void Unk_c182b0(u64);

// 0x7100bc64e0
void Unk_bc64e0_call(const Unk_bc64e0* self) {
    Unk_c182b0(self->field_2b8);
}

struct Unk_c18050 {
    u8 _0[0x780];
    u64 field_780;
};
PKMN_OFFSET_ASSERT(Unk_c18050, field_780, 0x780);

void Unk_c5ac90(u64);

// 0x7100c18050
void Unk_c18050_call(const Unk_c18050* self) {
    Unk_c5ac90(self->field_780);
}

void Unk_c1e8f0(void*, u64, u64, u32);

// 0x7100c1eef0
void Unk_c1eef0_call(void* self, u64 value, u64 /*unused*/, u64 arg3) {
    Unk_c1e8f0(self, value, arg3, 1);
}
