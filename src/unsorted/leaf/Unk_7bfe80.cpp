// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7bfe80 {
    u8 _0[0xa8];
    u8 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_7bfe80, field_a8, 0xa8);

// 0x71007bfe80
u8* Unk_7bfe80_getFielda8Ptr(Unk_7bfe80* self) {
    return &self->field_a8;
}

void Unk_76a5d0();
void Unk_7c2280();

// 0x71007c1af0
void Unk_7c1af0_call() {
    Unk_7c2280();
    Unk_76a5d0();
}

struct Unk_7c22a0 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_7c22a0, field_50, 0x50);

// 0x71007c22a0
u8 Unk_7c22a0_getField50(const Unk_7c22a0* self) {
    return self->field_50;
}
