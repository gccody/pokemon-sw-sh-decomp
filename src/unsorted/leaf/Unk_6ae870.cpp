// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6ae870 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_6ae870, field_58, 0x58);

void Unk_6b14b0(u64);

// 0x71006ae870
void Unk_6ae870_call(const Unk_6ae870* self) {
    if (self->field_58 != 0) {
        Unk_6b14b0(self->field_58);
    }
}

struct Unk_6ae880 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_6ae880, field_58, 0x58);

void Unk_6b2b10(u64);

// 0x71006ae880
void Unk_6ae880_call(const Unk_6ae880* self) {
    if (self->field_58 != 0) {
        Unk_6b2b10(self->field_58);
    }
}

struct Unk_6aea30 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_6aea30, field_58, 0x58);

void Unk_6b1530(u64);

// 0x71006aea30
void Unk_6aea30_call(const Unk_6aea30* self) {
    if (self->field_58 != 0) {
        Unk_6b1530(self->field_58);
    }
}

struct Unk_6aecf0 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_6aecf0, field_58, 0x58);

void Unk_6b2bd0(u64);

// 0x71006aecf0
void Unk_6aecf0_call(const Unk_6aecf0* self) {
    if (self->field_58 != 0) {
        Unk_6b2bd0(self->field_58);
    }
}

struct Unk_6aedb0 {
    u8 _0[0x1c0];
    u64 field_1c0;
};
PKMN_OFFSET_ASSERT(Unk_6aedb0, field_1c0, 0x1c0);

void Unk_6b7670(u64);

// 0x71006aedb0
void Unk_6aedb0_call(const Unk_6aedb0* self) {
    if (self->field_1c0 != 0) {
        Unk_6b7670(self->field_1c0);
    }
}

struct Unk_6aedc0 {
    u8 _0[0x1c0];
    u64 field_1c0;
};
PKMN_OFFSET_ASSERT(Unk_6aedc0, field_1c0, 0x1c0);

void Unk_6b77f0(u64);

// 0x71006aedc0
void Unk_6aedc0_call(const Unk_6aedc0* self) {
    if (self->field_1c0 != 0) {
        Unk_6b77f0(self->field_1c0);
    }
}

struct Unk_6aedd0 {
    u8 _0[0x219];
    bool field_219;
};
PKMN_OFFSET_ASSERT(Unk_6aedd0, field_219, 0x219);

// 0x71006aedd0
void Unk_6aedd0_set(Unk_6aedd0* self, bool value) {
    self->field_219 = value;
}

struct Unk_6aede0 {
    u8 _0[0x219];
    u8 field_219;
};
PKMN_OFFSET_ASSERT(Unk_6aede0, field_219, 0x219);

// 0x71006aede0
u8 Unk_6aede0_getField219(const Unk_6aede0* self) {
    return self->field_219;
}

struct Unk_6aee00 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_6aee00, field_58, 0x58);

void Unk_6b2c30(u64);

// 0x71006aee00
void Unk_6aee00_call(const Unk_6aee00* self) {
    if (self->field_58 != 0) {
        Unk_6b2c30(self->field_58);
    }
}
