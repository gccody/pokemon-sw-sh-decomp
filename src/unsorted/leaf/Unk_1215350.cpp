// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1215350 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1215350, field_60, 0x60);

// 0x7101215350
u32 Unk_1215350_getField60(const Unk_1215350* self) {
    return self->field_60;
}

struct Unk_1215d60 {
    u8 _0[0xa0];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1215d60, field_a0, 0xa0);

// 0x7101215d60
u8 Unk_1215d60_getFielda0(const Unk_1215d60* self) {
    return self->field_a0;
}

struct Unk_1216490 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1216490, field_68, 0x68);

// 0x7101216490
u64 Unk_1216490_getField68(const Unk_1216490* self) {
    return self->field_68;
}

struct Unk_12165b0_68 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_12165b0_68, field_98, 0x98);

struct Unk_12165b0 {
    u8 _0[0x68];
    Unk_12165b0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_12165b0, field_68, 0x68);

// 0x71012165b0
u64 Unk_12165b0_get(const Unk_12165b0* self) {
    return self->field_68->field_98;
}
