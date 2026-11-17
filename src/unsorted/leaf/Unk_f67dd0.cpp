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
