// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d0a100 {
    u8 _0[0x4dc];
    f32 field_4dc;
};
PKMN_OFFSET_ASSERT(Unk_d0a100, field_4dc, 0x4dc);

// 0x7100d0a100
f32 Unk_d0a100_getField4dc(const Unk_d0a100* self) {
    return self->field_4dc;
}

struct Unk_d0a110 {
    u8 _0[0x514];
    f32 field_514;
};
PKMN_OFFSET_ASSERT(Unk_d0a110, field_514, 0x514);

// 0x7100d0a110
f32 Unk_d0a110_getField514(const Unk_d0a110* self) {
    return self->field_514;
}

struct Unk_d0b220 {
    u8 _0[0xb30];
    u8 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_d0b220, field_b30, 0xb30);

void Unk_d09bb0(void*, void*);

// 0x7100d0b220
void Unk_d0b220_call(Unk_d0b220* self) {
    Unk_d09bb0(self, &self->field_b30);
}

struct Unk_d0b570 {
    u8 _0[0x2a8];
    u64 field_2a8;
};
PKMN_OFFSET_ASSERT(Unk_d0b570, field_2a8, 0x2a8);

void Unk_5c89c0(u64);

// 0x7100d0b570
void Unk_d0b570_call(const Unk_d0b570* self) {
    Unk_5c89c0(self->field_2a8);
}
