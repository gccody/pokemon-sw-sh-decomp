// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710106fcf0
void Unk_106fcf0() {}

struct Unk_106fd00 {
    u8 _0[0x1c];
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_106fd00, field_1c, 0x1c);

// 0x710106fd00
u32 Unk_106fd00_getField1c(const Unk_106fd00* self) {
    return self->field_1c;
}

struct Unk_106fd30 {
    u8 _0[0x24];
    u8 field_24;
};
PKMN_OFFSET_ASSERT(Unk_106fd30, field_24, 0x24);

// 0x710106fd30
u8 Unk_106fd30_getField24(const Unk_106fd30* self) {
    return self->field_24;
}

struct Unk_106fd40 {
    u8 _0[0x25];
    u8 field_25;
};
PKMN_OFFSET_ASSERT(Unk_106fd40, field_25, 0x25);

// 0x710106fd40
u8 Unk_106fd40_getField25(const Unk_106fd40* self) {
    return self->field_25;
}
