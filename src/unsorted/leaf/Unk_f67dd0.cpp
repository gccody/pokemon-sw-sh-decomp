// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f67dd0 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_f67dd0, field_80, 0x80);

void Unk_f68f00(u64);

// 0x7100f67dd0
void Unk_f67dd0_call(const Unk_f67dd0* self) {
    Unk_f68f00(self->field_80);
}

struct Unk_f67de0 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_f67de0, field_80, 0x80);

void Unk_f68e00(u64);

// 0x7100f67de0
void Unk_f67de0_call(const Unk_f67de0* self) {
    Unk_f68e00(self->field_80);
}

struct Unk_f6c9c0 {
    u64 field_0;
    u8 field_8;
    u8 _9[0x7];
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u64 field_50;
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_f6c9c0, field_88, 0x88);

// 0x7100f6c9c0
void Unk_f6c9c0_set(Unk_f6c9c0* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_80 = 0;
    self->field_88 = 0;
    self->field_70 = 0;
    self->field_78 = 0;
    self->field_60 = 0;
    self->field_68 = 0;
    self->field_50 = 0;
    self->field_58 = 0;
    self->field_40 = 0;
    self->field_48 = 0;
    self->field_30 = 0;
    self->field_38 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
}

struct Unk_f6cc70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f6cc70, field_0, 0x0);

void Unk_eb8a30(u64, u32);

// 0x7100f6cc70
void Unk_f6cc70_call(const Unk_f6cc70* self) {
    Unk_eb8a30(self->field_0, 1);
}

struct Unk_f6cdc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f6cdc0, field_0, 0x0);

void Unk_eb8e80(u64);

// 0x7100f6cdc0
void Unk_f6cdc0_call(const Unk_f6cdc0* self) {
    Unk_eb8e80(self->field_0);
}

void Unk_f6c850(void*, u32, u32);

// 0x7100f74240
void Unk_f74240_call(void* self, bool value) {
    Unk_f6c850(self, 4, value);
}

void Unk_f6c850(void*, u32, u32);

// 0x7100f74250
void Unk_f74250_call(void* self, bool value) {
    Unk_f6c850(self, 3, value);
}
