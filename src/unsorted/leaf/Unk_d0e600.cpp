// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d0e600_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_d0e600_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d0e600_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_d0e600_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_d0e600_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_d0e600_arg1, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_d0e600_arg1, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_d0e600_arg1, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_d0e600_arg1, field_38, 0x38);

struct Unk_d0e600 {
    u8 _0[0x3a0];
    u64 field_3a0;
    u64 field_3a8;
    u64 field_3b0;
    u64 field_3b8;
    u64 field_3c0;
    u64 field_3c8;
    u32 field_3d0;
    u8 _3d4[0xc];
    u64 field_3e0;
    u64 field_3e8;
    u64 field_3f0;
    u64 field_3f8;
    u64 field_400;
    u64 field_408;
    u32 field_410;
    u8 _414[0xc];
    u64 field_420;
    u64 field_428;
    u64 field_430;
    u64 field_438;
    u64 field_440;
    u64 field_448;
    u64 field_450;
    u64 field_458;
    u32 field_460;
};
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3a0, 0x3a0);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3a8, 0x3a8);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3b0, 0x3b0);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3b8, 0x3b8);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3c8, 0x3c8);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3e0, 0x3e0);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3e8, 0x3e8);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_3f8, 0x3f8);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_400, 0x400);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_408, 0x408);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_410, 0x410);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_420, 0x420);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_428, 0x428);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_430, 0x430);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_438, 0x438);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_448, 0x448);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_450, 0x450);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_458, 0x458);
PKMN_OFFSET_ASSERT(Unk_d0e600, field_460, 0x460);

// 0x7100d0e600
void Unk_d0e600_set(Unk_d0e600* self, const Unk_d0e600_arg1* value) {
    self->field_3f0 = self->field_3b0;
    self->field_3e0 = self->field_3a0;
    self->field_410 = self->field_3d0;
    self->field_400 = self->field_3c0;
    self->field_3e8 = self->field_3a8;
    self->field_408 = self->field_3c8;
    self->field_3f8 = self->field_3b8;
    u64 v0 = value->field_0;
    u64 v1 = value->field_10;
    u64 v2 = value->field_8;
    self->field_438 = value->field_18;
    self->field_430 = v1;
    self->field_428 = v2;
    self->field_420 = v0;
    u64 v3 = value->field_20;
    u64 v4 = value->field_28;
    u64 v5 = value->field_30;
    self->field_458 = value->field_38;
    self->field_450 = v5;
    self->field_448 = v4;
    self->field_440 = v3;
    self->field_460 = 0;
}
