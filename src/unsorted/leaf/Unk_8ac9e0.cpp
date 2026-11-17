// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ac9e0 {
    u8 _0[0x20];
    u32 field_20;
    u8 field_24;
    u8 field_25;
    u8 _26[0x2];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_8ac9e0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ac9e0, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_8ac9e0, field_25, 0x25);
PKMN_OFFSET_ASSERT(Unk_8ac9e0, field_28, 0x28);

// 0x71008ac9e0
void Unk_8ac9e0_set(Unk_8ac9e0* self, u8 value, u32 arg2) {
    self->field_20 = 0;
    self->field_24 = 0;
    self->field_25 = value;
    self->field_28 = arg2;
}

struct Unk_8acb50 {
    u8 _0[0x24];
    u8 field_24;
};
PKMN_OFFSET_ASSERT(Unk_8acb50, field_24, 0x24);

// 0x71008acb50
u8 Unk_8acb50_getField24(const Unk_8acb50* self) {
    return self->field_24;
}
