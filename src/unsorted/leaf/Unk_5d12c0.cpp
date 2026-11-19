// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_2773638 __attribute__((visibility("hidden")));

// 0x71005d12c0
u64 Unk_5d12c0_get() {
    return Unk_2773638;
}

struct Unk_5d1b50 {
    u8 _0[0x130];
    u64 field_130;
};
PKMN_OFFSET_ASSERT(Unk_5d1b50, field_130, 0x130);

// 0x71005d1b50
void Unk_5d1b50_set(Unk_5d1b50* self) {
    self->field_130 = self->field_130 | 0x10;
}

extern u64 Unk_2773640;

// 0x71005d42e0
u64 Unk_5d42e0_get() {
    return Unk_2773640;
}
