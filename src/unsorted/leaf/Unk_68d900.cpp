// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_68d900 {
    u8 _0[0x260];
    u8 field_260;
};
PKMN_OFFSET_ASSERT(Unk_68d900, field_260, 0x260);

// 0x710068d900
u8* Unk_68d900_getField260Ptr(Unk_68d900* self) {
    return &self->field_260;
}

struct Unk_68d940 {
    u8 _0[0x27a];
    u8 field_27a;
};
PKMN_OFFSET_ASSERT(Unk_68d940, field_27a, 0x27a);

// 0x710068d940
void Unk_68d940_clearField27a(Unk_68d940* self) {
    self->field_27a = 0;
}

struct Unk_68f160 {
    u8 _0[0x68];
    f32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_68f160, field_68, 0x68);

// 0x710068f160
void Unk_68f160_setField68(Unk_68f160* self, f32 value) {
    self->field_68 = value;
}

// 0x7100694510
void Unk_694510() {}

// 0x71006955b0
void Unk_6955b0() {}
