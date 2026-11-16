// Scope: common
#include <types.h>

struct Unk_ea5d80 {
    u8 _0[0xc];
    s32 field_c;
    s32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ea5d80, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_ea5d80, field_10, 0x10);

// 0x7100ea5d80 (Shield 0x7100ea5db0)
// -O3 only: the shared `sub; str; ret` tail is duplicated into both paths (the
// -O3 tail-duplication threshold is 4 instructions, -O2/-Os use 2).
void Unk_ea5d80_countDown(Unk_ea5d80* self) {
    if (self->field_10 == 0)
        self->field_10 = self->field_c;
    self->field_10--;
}
