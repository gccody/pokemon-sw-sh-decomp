// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x7100934e50
void Unk_934e50_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100934e60
void Unk_934e60_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_934e70 {
    u8 _0[0x618];
    u32 field_618;
    u8 _61c[0x16c];
    u8 field_788;
};
PKMN_OFFSET_ASSERT(Unk_934e70, field_618, 0x618);
PKMN_OFFSET_ASSERT(Unk_934e70, field_788, 0x788);

void Unk_934e90(void*, u32);

// 0x7100934e70
void Unk_934e70_call(Unk_934e70* self, u32 value) {
    self->field_788 = 0;
    self->field_618 = value == 0xff ? 0 : value;
    Unk_934e90(self, value == 0xff ? 0 : value);
}
