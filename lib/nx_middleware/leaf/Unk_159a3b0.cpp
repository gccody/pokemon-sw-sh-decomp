// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_159a3b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_159a3b0_arg1, field_0, 0x0);

void Unk_159b040(u64, void*);

// 0x710159a3b0
void Unk_159a3b0_call(void* self, const Unk_159a3b0_arg1* value) {
    Unk_159b040(value->field_0, self);
}

struct Unk_15a37e0_arg1 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x3];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_15a37e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_15a37e0_arg1, field_c, 0xc);

struct Unk_15a37e0 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x3];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_15a37e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_15a37e0, field_c, 0xc);

// 0x71015a37e0
void Unk_15a37e0_set(Unk_15a37e0* self, const Unk_15a37e0_arg1* value) {
    self->field_8 = value->field_8;
    self->field_c = value->field_c;
}

// 0x71015a3a70
void Unk_15a3a70_update() {
}

// 0x71015a3a80
void Unk_15a3a80_update() {
}

// 0x71015a3a90
void Unk_15a3a90_update() {
}

// 0x71015a3aa0
void Unk_15a3aa0_update() {
}

// 0x71015a3ab0
void Unk_15a3ab0_update() {
}

// 0x71015a3b60
void Unk_15a3b60_update() {
}

// 0x71015a3b70
void Unk_15a3b70_update() {
}

// 0x71015a3df0
void Unk_15a3df0_update() {
}

// 0x71015a3e90
void Unk_15a3e90_update() {
}

// 0x71015a4320
void Unk_15a4320_update() {
}

struct Unk_15a5840 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_15a5840, field_64, 0x64);

// 0x71015a5840
void Unk_15a5840_set(Unk_15a5840* self, u32 value) {
    self->field_64 = value;
}

struct Unk_15a5880 {
    u8 _0[0x80];
    bool field_80;
};
PKMN_OFFSET_ASSERT(Unk_15a5880, field_80, 0x80);

// 0x71015a5880
void Unk_15a5880_set(Unk_15a5880* self, bool value) {
    self->field_80 = value;
}

struct Unk_15a6a60 {
    u8 _0[0xc9];
    bool field_c9;
};
PKMN_OFFSET_ASSERT(Unk_15a6a60, field_c9, 0xc9);

// 0x71015a6a60
void Unk_15a6a60_set(Unk_15a6a60* self, bool value) {
    self->field_c9 = value;
}

struct Unk_15a6a70 {
    u8 _0[0xc8];
    bool field_c8;
    u8 _c9[0x7];
    u16 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_15a6a70, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_15a6a70, field_d0, 0xd0);

// 0x71015a6a70
void Unk_15a6a70_set(Unk_15a6a70* self, bool value) {
    self->field_c8 = value;
    self->field_d0 = 1;
}

struct Unk_15a6a90 {
    u8 _0[0xca];
    bool field_ca;
};
PKMN_OFFSET_ASSERT(Unk_15a6a90, field_ca, 0xca);

// 0x71015a6a90
void Unk_15a6a90_set(Unk_15a6a90* self, bool value) {
    self->field_ca = value;
}

struct Unk_15a6aa0 {
    u8 _0[0x100];
    bool field_100;
};
PKMN_OFFSET_ASSERT(Unk_15a6aa0, field_100, 0x100);

// 0x71015a6aa0
void Unk_15a6aa0_set(Unk_15a6aa0* self, bool value) {
    self->field_100 = value;
}

struct Unk_15a6ab0 {
    u8 _0[0xcc];
    u32 field_cc;
};
PKMN_OFFSET_ASSERT(Unk_15a6ab0, field_cc, 0xcc);

// 0x71015a6ab0
void Unk_15a6ab0_set(Unk_15a6ab0* self, u32 value) {
    self->field_cc = value;
}

struct Unk_15a73b0 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_15a73b0, field_64, 0x64);

// 0x71015a73b0
void Unk_15a73b0_set(Unk_15a73b0* self, u32 value) {
    self->field_64 = value;
}

struct Unk_15a73c0 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_15a73c0, field_64, 0x64);

// 0x71015a73c0
u32 Unk_15a73c0_get(const Unk_15a73c0* self) {
    return self->field_64;
}
