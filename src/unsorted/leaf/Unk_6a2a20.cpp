// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6a2a20 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_6a2a20, field_50, 0x50);

// 0x71006a2a20
void Unk_6a2a20_setField50(Unk_6a2a20* self, u64 value) {
    self->field_50 = value;
}

struct Unk_6a2a30 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_6a2a30, field_50, 0x50);

// 0x71006a2a30
void Unk_6a2a30_clearField50(Unk_6a2a30* self) {
    self->field_50 = 0;
}

struct Unk_6a2b60 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_6a2b60, field_88, 0x88);

// 0x71006a2b60
u8 Unk_6a2b60_getField88(const Unk_6a2b60* self) {
    return self->field_88;
}

struct Unk_6a3240 {
    u8 _0[0x98];
    u8 field_98;
};
PKMN_OFFSET_ASSERT(Unk_6a3240, field_98, 0x98);

// 0x71006a3240
u8* Unk_6a3240_getField98Ptr(Unk_6a3240* self) {
    return &self->field_98;
}

struct Unk_6a3250 {
    u8 _0[0xc98];
    u64 field_c98;
};
PKMN_OFFSET_ASSERT(Unk_6a3250, field_c98, 0xc98);

// 0x71006a3250
u64 Unk_6a3250_getFieldc98(const Unk_6a3250* self) {
    return self->field_c98;
}
