// Scope: common
#include <types.h>

struct Unk_f4ac50 {
    u8 _0[0x5cc];
    s32 field_5cc;
    bool field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_f4ac50, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_f4ac50, field_5d0, 0x5d0);

// 0x7100f4ac50 (Shield 0x7100f4ac80)
// -O3 only: the shared `str; strb; ret` tail is duplicated into all three
// paths. As a switch, all three versions fold into one csel sequence instead.
void Unk_f4ac50_setMode(Unk_f4ac50* self, s32 kind) {
    if (kind == 0)
        self->field_5cc = 4;
    else if (kind == 1)
        self->field_5cc = 5;
    else
        self->field_5cc = 6;
    self->field_5d0 = false;
}
