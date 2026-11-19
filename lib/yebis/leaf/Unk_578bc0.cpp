// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_578bc0 {
    u8 _0[0xb0];
    void* field_b0;
};
PKMN_OFFSET_ASSERT(Unk_578bc0, field_b0, 0xb0);

void Unk_56ca20(void*, void*);

// 0x7100578bc0
void Unk_578bc0_call(Unk_578bc0* self) {
    if (self->field_b0 != nullptr) {
        Unk_56ca20(self->field_b0, self);
    }
}
