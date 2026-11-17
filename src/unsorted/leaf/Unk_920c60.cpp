// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x7100920c60
void Unk_920c60_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100920c70
void Unk_920c70_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_921040 {
    u8 _0[0x798];
    u64 field_798;
};
PKMN_OFFSET_ASSERT(Unk_921040, field_798, 0x798);

void Unk_14e1a00(u64, u32);

// 0x7100921040
void Unk_921040_call(const Unk_921040* self, bool value) {
    Unk_14e1a00(self->field_798, value);
}
