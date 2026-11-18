// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_eadbd0 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_eadbd0, field_64, 0x64);

// 0x7100eadbd0
void Unk_eadbd0_set(Unk_eadbd0* self) {
    self->field_64 = 1;
}

struct Unk_eadbe0 {
    u8 _0[0x64];
    u32 field_64;
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_eadbe0, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_eadbe0, field_68, 0x68);

// 0x7100eadbe0
u64 Unk_eadbe0_update(Unk_eadbe0* self) {
    self->field_64 = 1;
    return self->field_68;
}

struct Unk_eadbf0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_eadbf0, field_68, 0x68);

// 0x7100eadbf0
void Unk_eadbf0_setField68(Unk_eadbf0* self, u64 value) {
    self->field_68 = value;
}

struct Unk_eadc00 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_eadc00, field_64, 0x64);

// 0x7100eadc00
void Unk_eadc00_clearField64(Unk_eadc00* self) {
    self->field_64 = 0;
}

struct Unk_eadcf0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_eadcf0, field_50, 0x50);

// 0x7100eadcf0
u64 Unk_eadcf0_getField50(const Unk_eadcf0* self) {
    return self->field_50;
}

void Unk_eae960();

// 0x7100eae950
void Unk_eae950_call() {
    Unk_eae960();
}

// 0x7100eaf460
void Unk_eaf460_update() {}

struct Unk_eaf470_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eaf470_arg1, field_0, 0x0);

struct Unk_eaf470 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eaf470, field_0, 0x0);

// 0x7100eaf470
void Unk_eaf470_set(const Unk_eaf470* self, Unk_eaf470_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_eaf480_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eaf480_arg1, field_0, 0x0);

struct Unk_eaf480 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eaf480, field_0, 0x0);

// 0x7100eaf480
void Unk_eaf480_set(const Unk_eaf480* self, Unk_eaf480_arg1* value) {
    value->field_0 = self->field_0;
}
