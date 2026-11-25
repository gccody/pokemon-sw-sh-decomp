// Scope: common
#include "types.h"

// Per-kind slot counts: the highest valid slot index of each kind.
extern const u16 Unk_1f34714[] __attribute__((visibility("hidden")));

struct Unk_1394530_T {
    u8 field_0[0x128];
    u8* field_128[1];
};
PKMN_OFFSET_ASSERT(Unk_1394530_T, field_128, 0x128);

// 0x7101394530
void Unk_1394530(Unk_1394530_T* self, s32 kind, u16 slot, bool value) {
    if (slot <= Unk_1f34714[kind]) {
        self->field_128[static_cast<u16>(kind)][slot] = value;
    }
}

// 0x7101394560
bool Unk_1394560(const Unk_1394530_T* self, s32 kind, u16 slot) {
    if (slot > Unk_1f34714[kind]) {
        return false;
    }
    return self->field_128[kind][slot] == 1;
}
