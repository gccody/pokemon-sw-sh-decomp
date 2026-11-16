// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101310140
void Unk_1310140() {}

struct Unk_1310150 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1310150, field_60, 0x60);

// 0x7101310150
u8* Unk_1310150_getField60Ptr(Unk_1310150* self) {
    return &self->field_60;
}

struct Unk_13193c0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13193c0, field_60, 0x60);

// 0x71013193c0
u64 Unk_13193c0_getField60(const Unk_13193c0* self) {
    return self->field_60;
}

struct Unk_13193d0 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_13193d0, field_70, 0x70);

// 0x71013193d0
u32 Unk_13193d0_getField70(const Unk_13193d0* self) {
    return self->field_70;
}

struct Unk_13193e0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_13193e0, field_6c, 0x6c);

// 0x71013193e0
void Unk_13193e0_setField6c(Unk_13193e0* self, u32 value) {
    self->field_6c = value;
}

struct Unk_131dbe0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_131dbe0, field_5cc, 0x5cc);

// 0x710131dbe0
void Unk_131dbe0_clearField5cc(Unk_131dbe0* self) {
    self->field_5cc = 0;
}

struct Unk_131dbf0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_131dbf0, field_5cc, 0x5cc);

// 0x710131dbf0
u32 Unk_131dbf0_getField5cc(const Unk_131dbf0* self) {
    return self->field_5cc;
}
