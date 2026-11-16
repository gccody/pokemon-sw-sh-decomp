// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_620820 {
    f32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_620820, field_0, 0x0);

// 0x7100620820
void Unk_620820_setField0(Unk_620820* self, f32 value) {
    self->field_0 = value;
}

struct Unk_64d770 {
    u8 _0[0x270];
    f32 field_270;
};
PKMN_OFFSET_ASSERT(Unk_64d770, field_270, 0x270);

// 0x710064d770
void Unk_64d770_setField270(Unk_64d770* self, f32 value) {
    self->field_270 = value;
}

struct Unk_658df0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_658df0, field_60, 0x60);

// 0x7100658df0
u32 Unk_658df0_getField60(const Unk_658df0* self) {
    return self->field_60;
}
