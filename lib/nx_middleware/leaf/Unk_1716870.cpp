// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_1716880(void*, u64, u64, u64, u32);

// 0x7101716870
void Unk_1716870_call(void* self, u64 value, u64 arg2, u64 arg3, bool arg4) {
    Unk_1716880(self, value, arg2, arg3, arg4);
}

struct Unk_171aea0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_171aea0, field_0, 0x0);

// 0x710171aea0
void Unk_171aea0_set(Unk_171aea0* self) {
    self->field_0 = 0;
}
