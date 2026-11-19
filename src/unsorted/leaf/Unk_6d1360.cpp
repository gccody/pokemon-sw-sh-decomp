// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_27fc0a8;
struct Unk_6d1360 {
    u8 _0[0x110];
    u64 field_110;
};
PKMN_OFFSET_ASSERT(Unk_6d1360, field_110, 0x110);

u32 Unk_172bd80(u64);
void Unk_6d4140(u64);

// 0x71006d1360
void Unk_6d1360_call(const Unk_6d1360* self) {
    u32 r0 = Unk_172bd80(Unk_27fc0a8);
    if ((r0 & 1) != 0) {
        if (self->field_110 == 0)
            return;
        Unk_6d4140(self->field_110);
    }
}

struct Unk_6d1530 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_6d1530, field_a0, 0xa0);

// 0x71006d1530
void Unk_6d1530_setFielda0(Unk_6d1530* self, u64 value) {
    self->field_a0 = value;
}
