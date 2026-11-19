// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1180260 {
    u8 _0[0x400];
    u64 field_400;
    u64 field_408;
};
PKMN_OFFSET_ASSERT(Unk_1180260, field_400, 0x400);
PKMN_OFFSET_ASSERT(Unk_1180260, field_408, 0x408);

u32 Unk_eb9750(u64);

// 0x7101180260
u32 Unk_1180260_call(const Unk_1180260* self) {
    u32 r0 = Unk_eb9750(self->field_400);
    u32 r1 = Unk_eb9750(self->field_408);
    return (r0 & r1) & 1;
}

struct Unk_11802d0 {
    u8 _0[0x410];
    u8 field_410;
};
PKMN_OFFSET_ASSERT(Unk_11802d0, field_410, 0x410);

// 0x71011802d0
u8 Unk_11802d0_getField410(const Unk_11802d0* self) {
    return self->field_410;
}

struct Unk_11802e0 {
    u8 _0[0x7c];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_11802e0, field_7c, 0x7c);

// 0x71011802e0
bool Unk_11802e0_check(const Unk_11802e0* self) {
    return self->field_7c >= 4 && self->field_7c <= 9;
}
