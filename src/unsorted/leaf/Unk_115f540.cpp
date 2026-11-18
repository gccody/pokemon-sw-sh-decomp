// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u32 Unk_241b370;
extern u32 Unk_241b374;
extern u32 Unk_27ea7d0;
struct Unk_115f540 {
    u8 field_0;
    u8 _1[0x3];
    f32 field_4;
    u32 field_8;
    u32 field_c;
    f32 field_10;
    u32 field_14;
    u32 field_18;
    f32 field_1c;
    f32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_115f540, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_115f540, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_115f540, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_115f540, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_115f540, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_115f540, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_115f540, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_115f540, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_115f540, field_20, 0x20);

// 0x710115f540
void Unk_115f540_set(Unk_115f540* self, f32 fvalue, f32 farg1, f32 farg2, f32 farg3) {
    self->field_0 = 1;
    self->field_14 = Unk_27ea7d0;
    self->field_c = Unk_241b374;
    u32 v0 = Unk_241b370;
    self->field_18 = 0;
    self->field_10 = farg1;
    self->field_8 = v0;
    self->field_4 = fvalue;
    self->field_20 = farg3;
    self->field_1c = farg2;
}

struct Unk_115f590 {
    u8 _0[0x18];
    f32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_115f590, field_18, 0x18);

// 0x710115f590
f32 Unk_115f590_getField18(const Unk_115f590* self) {
    return self->field_18;
}
