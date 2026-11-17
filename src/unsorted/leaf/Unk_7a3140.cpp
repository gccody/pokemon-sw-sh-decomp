// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71007a3140
bool Unk_7a3140_check(void* /*unused*/, u32 value) {
    return value >= 0x4ff && value <= 0x62a;
}

struct Unk_7a7e60 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_7a7e60, field_120, 0x120);

// 0x71007a7e60
u32 Unk_7a7e60_getField120(const Unk_7a7e60* self) {
    return self->field_120;
}

struct Unk_7a7e70 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_7a7e70, field_120, 0x120);

// 0x71007a7e70
void Unk_7a7e70_setField120(Unk_7a7e70* self, u32 value) {
    self->field_120 = value;
}
