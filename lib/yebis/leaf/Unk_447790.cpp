// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_447790 {
    u8 _0[0x18];
    u64 field_18;
    u8 _20[0x58];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_447790, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_447790, field_78, 0x78);

void Unk_43fa90(u64, u32);

// 0x7100447790
void Unk_447790_call(const Unk_447790* self) {
    Unk_43fa90(self->field_18, self->field_78);
}

// 0x71004486a0
u64 Unk_4486a0_get(u64 /*unused*/, u32 /*unused*/, u32 /*unused*/, u32 /*unused*/, u32 /*unused*/, u32 /*unused*/, u32 /*unused*/, u32 /*unused*/) {
    return 0;
}
