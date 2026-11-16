// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_aad500 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_aad500, field_80, 0x80);

// 0x7100aad500
u32 Unk_aad500_getField80(const Unk_aad500* self) {
    return self->field_80;
}

struct Unk_aad510 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_aad510, field_80, 0x80);

// 0x7100aad510
void Unk_aad510_clearField80(Unk_aad510* self) {
    self->field_80 = 0;
}

struct Unk_aafbb0 {
    u8 _0[0x690];
    u8 field_690;
};
PKMN_OFFSET_ASSERT(Unk_aafbb0, field_690, 0x690);

// 0x7100aafbb0
u8* Unk_aafbb0_getField690Ptr(Unk_aafbb0* self) {
    return &self->field_690;
}

struct Unk_ab3af0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_ab3af0, field_5cc, 0x5cc);

// 0x7100ab3af0
u32 Unk_ab3af0_getField5cc(const Unk_ab3af0* self) {
    return self->field_5cc;
}

struct Unk_ab3b00 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_ab3b00, field_5cc, 0x5cc);

// 0x7100ab3b00
void Unk_ab3b00_clearField5cc(Unk_ab3b00* self) {
    self->field_5cc = 0;
}

struct Unk_ab4260 {
    u8 _0[0x5d0];
    u32 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_ab4260, field_5d0, 0x5d0);

// 0x7100ab4260
u32 Unk_ab4260_getField5d0(const Unk_ab4260* self) {
    return self->field_5d0;
}
