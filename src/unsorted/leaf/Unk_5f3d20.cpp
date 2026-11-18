// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5f3d20 {
    u8 _0[0xe0];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_5f3d20, field_e0, 0xe0);

void Unk_5f3e90(u64);

// 0x71005f3d20
void Unk_5f3d20_call(const Unk_5f3d20* self) {
    Unk_5f3e90(self->field_e0);
}

struct Unk_5f3d30 {
    u8 _0[0xe0];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_5f3d30, field_e0, 0xe0);

void Unk_5f4030(u64);

// 0x71005f3d30
void Unk_5f3d30_call(const Unk_5f3d30* self) {
    Unk_5f4030(self->field_e0);
}

struct Unk_5f5760 {
    u8 _0[0xd8];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_5f5760, field_d8, 0xd8);

// 0x71005f5760
u64 Unk_5f5760_getFieldd8(const Unk_5f5760* self) {
    return self->field_d8;
}

void Unk_1787c60();

// 0x71005f7100
void Unk_5f7100_call() {
    Unk_1787c60();
}

void Unk_1787bf0();

// 0x71005f7110
void Unk_5f7110_call() {
    Unk_1787bf0();
}

void Unk_1787c10();

// 0x71005f7120
void Unk_5f7120_call() {
    Unk_1787c10();
}
