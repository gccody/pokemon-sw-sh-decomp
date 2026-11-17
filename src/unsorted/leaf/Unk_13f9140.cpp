// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_13f9140 {
    u8 _0[0x380];
    u64 field_380;
};
PKMN_OFFSET_ASSERT(Unk_13f9140, field_380, 0x380);

// 0x71013f9140
bool Unk_13f9140_check(const Unk_13f9140* self) {
    return self->field_380 == 0;
}

struct Unk_13faad0_460 {
    u8 _0[0x6c];
    u8 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_13faad0_460, field_6c, 0x6c);

struct Unk_13faad0 {
    u8 _0[0x460];
    Unk_13faad0_460* field_460;
};
PKMN_OFFSET_ASSERT(Unk_13faad0, field_460, 0x460);

// 0x71013faad0
void Unk_13faad0_set(const Unk_13faad0* self) {
    self->field_460->field_6c = 1;
}
