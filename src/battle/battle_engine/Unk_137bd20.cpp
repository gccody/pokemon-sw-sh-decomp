// Scope: common
// The flags at +0x19c of the object of src/battle/battle_engine/Unk_137bba0.cpp,
// and the constructor of Unk_2432c78.
#include "battle/battle_engine/Unk_137c470.h"

struct Unk_137bd20 {
    u8 _0[0x19c];
    u32 field_19c;
};
PKMN_OFFSET_ASSERT(Unk_137bd20, field_19c, 0x19c);

// 0x710137bd20: a bit of field_19c.
bool Unk_137bd20_check(const Unk_137bd20* self, u32 bit) {
    if (bit < 32)
        return (self->field_19c & (1u << bit)) != 0;
    return false;
}

struct Unk_137bd50 {
    u8 _0[0x19c];
    u32 field_19c;
};
PKMN_OFFSET_ASSERT(Unk_137bd50, field_19c, 0x19c);

// 0x710137bd50
void Unk_137bd50_set(Unk_137bd50* self, u32 bit, bool value) {
    if (bit >= 32)
        return;
    if (value)
        self->field_19c |= 1u << bit;
    else
        self->field_19c &= ~(1u << bit);
}

// 0x710137c400
Unk_2432c78::Unk_2432c78() : field_60(nullptr) {
    field_68.Unk_Reset();
}
