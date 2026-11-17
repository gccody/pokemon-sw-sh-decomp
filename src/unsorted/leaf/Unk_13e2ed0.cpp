// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_13e2ed0 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13e2ed0, field_60, 0x60);

// 0x71013e2ed0
u8* Unk_13e2ed0_getField60Ptr(Unk_13e2ed0* self) {
    return &self->field_60;
}

void Unk_13e32b0();

// 0x71013e35c0
void Unk_13e35c0_call() {
    Unk_13e32b0();
}

void Unk_13e3450();

// 0x71013e35d0
void Unk_13e35d0_call() {
    Unk_13e3450();
}
