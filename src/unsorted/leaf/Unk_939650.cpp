// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_939650 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_939650, field_38, 0x38);

// 0x7100939650
void Unk_939650_setField38(Unk_939650* self, u64 value) {
    self->field_38 = value;
}

struct Unk_93cc90_78 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_93cc90_78, field_58, 0x58);

struct Unk_93cc90 {
    u8 _0[0x78];
    Unk_93cc90_78* field_78;
    u8 _80[0x10];
    bool field_90;
};
PKMN_OFFSET_ASSERT(Unk_93cc90, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_93cc90, field_90, 0x90);

// 0x710093cc90
void Unk_93cc90_set(Unk_93cc90* self, bool value, bool arg2) {
    self->field_90 = value;
    self->field_78->field_58 = (self->field_78->field_58 & 0xfffffffe) | (arg2);
}

struct Unk_95abd0 {
    u8 _0[0xa0];
    u32 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_95abd0, field_a0, 0xa0);

// 0x710095abd0
bool Unk_95abd0_check(const Unk_95abd0* self) {
    return self->field_a0 == 0;
}
