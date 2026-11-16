// Scope: common
#include <types.h>

struct Unk_a6d3c0 {
    u8 _0[0x21d0];
    u64 field_21d0;
    u8 _21d8[0x21f8 - 0x21d8];
    u64 field_21f8;
};
PKMN_OFFSET_ASSERT(Unk_a6d3c0, field_21d0, 0x21d0);
PKMN_OFFSET_ASSERT(Unk_a6d3c0, field_21f8, 0x21f8);

// 0x7100a6d3c0
// -O3 only: the `add; ldr; ret` tail of both cases is duplicated (-O2/-Os
// share it).
u64 Unk_a6d3c0_get(const Unk_a6d3c0* self, s32 kind) {
    switch (kind) {
        case 0:
            return self->field_21d0;
        case 1:
            return self->field_21f8;
        default:
            return 0;
    }
}
