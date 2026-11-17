// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8acbe0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8acbe0, field_30, 0x30);

// 0x71008acbe0
u8 Unk_8acbe0_getField30(const Unk_8acbe0* self) {
    return self->field_30;
}

struct Unk_8acbf0_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_20, 0x20);

struct Unk_8acbf0 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u8 field_28;
    u8 _29[0x3];
    u32 field_2c;
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_30, 0x30);

// 0x71008acbf0
void Unk_8acbf0_set(Unk_8acbf0* self, const Unk_8acbf0_arg1* value) {
    self->field_8 = value->field_8;
    self->field_10 = value->field_10;
    self->field_18 = value->field_0;
    self->field_20 = value->field_18;
    self->field_28 = value->field_20;
    self->field_2c = 0;
    self->field_30 = 0;
}
