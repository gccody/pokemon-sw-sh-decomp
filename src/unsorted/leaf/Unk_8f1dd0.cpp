// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8f1dd0_158 {
    u8 _0[0xf0];
    u32 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_8f1dd0_158, field_f0, 0xf0);

struct Unk_8f1dd0 {
    u8 _0[0x158];
    Unk_8f1dd0_158* field_158;
};
PKMN_OFFSET_ASSERT(Unk_8f1dd0, field_158, 0x158);

// 0x71008f1dd0
u32 Unk_8f1dd0_get(const Unk_8f1dd0* self) {
    return self->field_158->field_f0;
}

struct Unk_8f2890 {
    u8 _0[0x120];
    bool field_120;
};
PKMN_OFFSET_ASSERT(Unk_8f2890, field_120, 0x120);

// 0x71008f2890
void Unk_8f2890_set(Unk_8f2890* self, bool value) {
    self->field_120 = value;
}
