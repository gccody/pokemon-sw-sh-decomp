// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5474b0 {
    u8 _0[0x184];
    u8 field_184;
};
PKMN_OFFSET_ASSERT(Unk_5474b0, field_184, 0x184);
void Unk_547500(void*, u32, u64);

// 0x71005474b0
u32 Unk_5474b0_get(Unk_5474b0* self) {
    if (self->field_184 != 0) {
        Unk_547500(self, 1, 0);
        self->field_184 = 0;
        return 1;
    }
    return 0;
}
