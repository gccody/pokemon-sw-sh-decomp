// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1400490 {
    u8 _0[0x1f8];
    u64 field_1f8;
    u8 _200[0x8];
    u32 field_208;
    u32 field_20c;
    u32 field_210;
    u32 field_214;
};
PKMN_OFFSET_ASSERT(Unk_1400490, field_1f8, 0x1f8);
PKMN_OFFSET_ASSERT(Unk_1400490, field_208, 0x208);
PKMN_OFFSET_ASSERT(Unk_1400490, field_20c, 0x20c);
PKMN_OFFSET_ASSERT(Unk_1400490, field_210, 0x210);
PKMN_OFFSET_ASSERT(Unk_1400490, field_214, 0x214);

// 0x7101400490
void Unk_1400490_set(Unk_1400490* self, u64 value, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    self->field_1f8 = value;
    self->field_208 = arg2;
    self->field_20c = arg3;
    self->field_210 = arg4;
    self->field_214 = arg5;
}

struct Unk_1400540 {
    u8 _0[0x200];
    u64 field_200;
    u8 _208[0x10];
    u32 field_218;
    u32 field_21c;
    u32 field_220;
    u32 field_224;
};
PKMN_OFFSET_ASSERT(Unk_1400540, field_200, 0x200);
PKMN_OFFSET_ASSERT(Unk_1400540, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_1400540, field_21c, 0x21c);
PKMN_OFFSET_ASSERT(Unk_1400540, field_220, 0x220);
PKMN_OFFSET_ASSERT(Unk_1400540, field_224, 0x224);

// 0x7101400540
void Unk_1400540_set(Unk_1400540* self, u64 value, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    self->field_200 = value;
    self->field_218 = arg2;
    self->field_21c = arg3;
    self->field_220 = arg4;
    self->field_224 = arg5;
}
