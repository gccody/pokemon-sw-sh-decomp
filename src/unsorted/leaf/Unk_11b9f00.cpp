// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11b9f00 {
    u8 _0[0x60];
    u64 field_60;
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_11b9f00, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_11b9f00, field_68, 0x68);

// 0x71011b9f00
void Unk_11b9f00_set(Unk_11b9f00* self, u64 value, u32 arg2) {
    self->field_60 = value;
    self->field_68 = arg2;
}

struct Unk_11ba0a0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_11ba0a0, field_6c, 0x6c);

// 0x71011ba0a0
void Unk_11ba0a0_setField6c(Unk_11ba0a0* self, u32 value) {
    self->field_6c = value;
}

// 0x71011ba150
void Unk_11ba150_update() {}

struct Unk_11ba160_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ba160_arg1, field_0, 0x0);

struct Unk_11ba160 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ba160, field_0, 0x0);

// 0x71011ba160
void Unk_11ba160_set(const Unk_11ba160* self, Unk_11ba160_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11ba170_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ba170_arg1, field_0, 0x0);

struct Unk_11ba170 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11ba170, field_0, 0x0);

// 0x71011ba170
void Unk_11ba170_set(const Unk_11ba170* self, Unk_11ba170_arg1* value) {
    value->field_0 = self->field_0;
}
