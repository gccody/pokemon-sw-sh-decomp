// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_117a610_68 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_117a610_68, field_170, 0x170);

struct Unk_117a610 {
    u8 _0[0x68];
    Unk_117a610_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_117a610, field_68, 0x68);

// 0x710117a610
bool Unk_117a610_check(const Unk_117a610* self) {
    if (self->field_68 == nullptr) {
        return false;
    }
    return self->field_68->field_170 != 0;
}

struct Unk_117b380 {
    u8 _0[0x154];
    u32 field_154;
};
PKMN_OFFSET_ASSERT(Unk_117b380, field_154, 0x154);

// 0x710117b380
void Unk_117b380_setField154(Unk_117b380* self, u32 value) {
    self->field_154 = value;
}
