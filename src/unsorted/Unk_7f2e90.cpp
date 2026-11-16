// Scope: common
#include <types.h>

struct Unk_7f2e90 {
    u8 _0[0x456];
    u16 field_456;
};
PKMN_OFFSET_ASSERT(Unk_7f2e90, field_456, 0x456);

// 0x71007f2e90
// Subtracts *amount from field_456. When that would reach zero or below, it
// clamps, stores the part actually taken in *amount and returns true.
// -O3 only: the `strh; mov; ret` tail is duplicated (-O2/-Os branch to it).
bool Unk_7f2e90_take(Unk_7f2e90* self, u16* amount) {
    if (self->field_456 > *amount) {
        self->field_456 -= *amount;
        return false;
    }
    *amount = self->field_456;
    self->field_456 = 0;
    return true;
}
