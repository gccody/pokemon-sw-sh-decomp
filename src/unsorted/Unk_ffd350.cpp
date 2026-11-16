// Scope: common
#include <types.h>

struct Unk_ffd350 {
    u8 _0[0xa8];
    void* field_a8;
    u8 _b0[0xc0 - 0xb0];
    void* field_c0[8];
    u8 field_100;
};
PKMN_OFFSET_ASSERT(Unk_ffd350, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_ffd350, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_ffd350, field_100, 0x100);

// 0x7100ffd350 (Shield 0x7100ffd380)
// -O3 only: the 4-instruction `ldr; cmp; cset; ret` tail is duplicated.
bool Unk_ffd350_isCurrent(const Unk_ffd350* self, u8 index) {
    void* entry = self->field_100 != 0 ? self->field_c0[index % self->field_100] : nullptr;
    return entry == self->field_a8;
}
