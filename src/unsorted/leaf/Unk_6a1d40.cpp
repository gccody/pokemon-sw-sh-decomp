// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6a1d40 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_6a1d40, field_58, 0x58);

void Unk_6a1bd0();

// 0x71006a1d40
void Unk_6a1d40_call(Unk_6a1d40* self, u64 value) {
    Unk_6a1bd0();
    self->field_58 = value;
}

struct Unk_6a1f70 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_6a1f70, field_58, 0x58);

// 0x71006a1f70
u64 Unk_6a1f70_getField58(const Unk_6a1f70* self) {
    return self->field_58;
}
