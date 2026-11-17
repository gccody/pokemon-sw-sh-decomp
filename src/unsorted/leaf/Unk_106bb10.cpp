// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710106bb10
void Unk_106bb10() {}

struct Unk_106bb20 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_106bb20, field_60, 0x60);

// 0x710106bb20
u8* Unk_106bb20_getField60Ptr(Unk_106bb20* self) {
    return &self->field_60;
}

struct Unk_106bb30 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_106bb30, field_c0, 0xc0);

// 0x710106bb30
u8* Unk_106bb30_getFieldc0Ptr(Unk_106bb30* self) {
    return &self->field_c0;
}

struct Unk_106bb40 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_106bb40, field_120, 0x120);

// 0x710106bb40
u8* Unk_106bb40_getField120Ptr(Unk_106bb40* self) {
    return &self->field_120;
}

struct Unk_106bb50 {
    u8 _0[0x180];
    u8 field_180;
};
PKMN_OFFSET_ASSERT(Unk_106bb50, field_180, 0x180);

// 0x710106bb50
u8* Unk_106bb50_getField180Ptr(Unk_106bb50* self) {
    return &self->field_180;
}

struct Unk_106c0e0 {
    u8 _0[0x48];
    u64 field_48;
    u8 _50[0x58];
    u64 field_a8;
    u8 _b0[0x58];
    u64 field_108;
    u8 _110[0x58];
    u64 field_168;
    u8 _170[0x58];
    u64 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_106c0e0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_106c0e0, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_106c0e0, field_108, 0x108);
PKMN_OFFSET_ASSERT(Unk_106c0e0, field_168, 0x168);
PKMN_OFFSET_ASSERT(Unk_106c0e0, field_1c8, 0x1c8);

// 0x710106c0e0
void Unk_106c0e0_set(Unk_106c0e0* self) {
    self->field_48 = 0;
    self->field_a8 = 0;
    self->field_108 = 0;
    self->field_168 = 0;
    self->field_1c8 = 0;
}
