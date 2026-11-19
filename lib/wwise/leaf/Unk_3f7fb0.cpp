// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24df330;

// 0x71003f7fb0
u64 Unk_3f7fb0_get() {
    return Unk_24df330;
}

void Unk_3f7fe0(void*, void*, u64);

// 0x71003f7fd0
void Unk_3f7fd0_call(void* self, u64 value) {
    Unk_3f7fe0(self, self, value);
}

extern const u8 Unk_24df358[] __attribute__((visibility("hidden")));

// 0x71003f83b0
const u8* Unk_3f83b0_get() {
    return Unk_24df358;
}

struct Unk_3ffdb0 {
    u8 _0[0x210];
    u8 field_210;
};
PKMN_OFFSET_ASSERT(Unk_3ffdb0, field_210, 0x210);

// 0x71003ffdb0
void Unk_3ffdb0_set(Unk_3ffdb0* self) {
    self->field_210 = 1;
}
