// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1148c40 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1148c40, field_60, 0x60);

// 0x7101148c40
u32 Unk_1148c40_getField60(const Unk_1148c40* self) {
    return self->field_60;
}

// 0x7101148fe0
void Unk_1148fe0_update() {}

struct Unk_1148ff0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1148ff0_arg1, field_0, 0x0);

struct Unk_1148ff0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1148ff0, field_0, 0x0);

// 0x7101148ff0
void Unk_1148ff0_set(const Unk_1148ff0* self, Unk_1148ff0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1149000_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1149000_arg1, field_0, 0x0);

struct Unk_1149000 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1149000, field_0, 0x0);

// 0x7101149000
void Unk_1149000_set(const Unk_1149000* self, Unk_1149000_arg1* value) {
    value->field_0 = self->field_0;
}
