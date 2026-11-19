// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24ba120;
struct Unk_5ec9d0_0_2a0 {
    u8 _0[0x168];
    u64 field_168;
    u8 _170[0x2080];
    u8 field_21f0;
};
PKMN_OFFSET_ASSERT(Unk_5ec9d0_0_2a0, field_168, 0x168);
PKMN_OFFSET_ASSERT(Unk_5ec9d0_0_2a0, field_21f0, 0x21f0);

struct Unk_5ec9d0_0 {
    u8 _0[0x2a0];
    Unk_5ec9d0_0_2a0* field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_5ec9d0_0, field_2a0, 0x2a0);

struct Unk_5ec9d0 {
    Unk_5ec9d0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_5ec9d0, field_0, 0x0);

void Unk_5f21d0(u64, void*);
void Unk_5f7930(u64);

// 0x71005ec9d0
void Unk_5ec9d0_call(const Unk_5ec9d0* self) {
    Unk_5f21d0(self->field_0->field_2a0->field_168, &self->field_0->field_2a0->field_21f0);
    Unk_5f7930(Unk_24ba120);
}

// 0x71005eca10
void Unk_5eca10_update() {}

struct Unk_5eca20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5eca20_arg1, field_0, 0x0);

struct Unk_5eca20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5eca20, field_0, 0x0);

// 0x71005eca20
void Unk_5eca20_set(const Unk_5eca20* self, Unk_5eca20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_5eca30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5eca30_arg1, field_0, 0x0);

struct Unk_5eca30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5eca30, field_0, 0x0);

// 0x71005eca30
void Unk_5eca30_set(const Unk_5eca30* self, Unk_5eca30_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71005ee0c0
void Unk_5ee0c0_update() {}

struct Unk_5ee0d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5ee0d0_arg1, field_0, 0x0);

struct Unk_5ee0d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5ee0d0, field_0, 0x0);

// 0x71005ee0d0
void Unk_5ee0d0_set(const Unk_5ee0d0* self, Unk_5ee0d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_5ee0e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5ee0e0_arg1, field_0, 0x0);

struct Unk_5ee0e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5ee0e0, field_0, 0x0);

// 0x71005ee0e0
void Unk_5ee0e0_set(const Unk_5ee0e0* self, Unk_5ee0e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_5f1b00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5f1b00, field_0, 0x0);

void Unk_5efcd0(u64);

// 0x71005f1b00
void Unk_5f1b00_call(const Unk_5f1b00* self) {
    Unk_5efcd0(self->field_0);
}

// 0x71005f1b10
void Unk_5f1b10_update() {}

struct Unk_5f1b20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5f1b20_arg1, field_0, 0x0);

struct Unk_5f1b20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5f1b20, field_0, 0x0);

// 0x71005f1b20
void Unk_5f1b20_set(const Unk_5f1b20* self, Unk_5f1b20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_5f1b30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5f1b30_arg1, field_0, 0x0);

struct Unk_5f1b30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5f1b30, field_0, 0x0);

// 0x71005f1b30
void Unk_5f1b30_set(const Unk_5f1b30* self, Unk_5f1b30_arg1* value) {
    value->field_0 = self->field_0;
}
