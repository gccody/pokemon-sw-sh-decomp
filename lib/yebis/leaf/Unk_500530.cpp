// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_500530 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_500530, field_18, 0x18);

// 0x7100500530
void Unk_500530_set(Unk_500530* self, u64 value) {
    self->field_18 = value;
}

struct Unk_500540 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_500540, field_18, 0x18);

// 0x7100500540
u64 Unk_500540_get(const Unk_500540* self) {
    return self->field_18;
}
