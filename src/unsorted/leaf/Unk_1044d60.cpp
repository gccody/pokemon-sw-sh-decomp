// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1044d60 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1044d60, field_60, 0x60);

// 0x7101044d60
bool Unk_1044d60_check(const Unk_1044d60* self) {
    return self->field_60 == 3;
}

struct Unk_1044d70 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1044d70, field_60, 0x60);

// 0x7101044d70
void Unk_1044d70_set(Unk_1044d70* self) {
    self->field_60 = 4;
}

struct Unk_1044d80 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1044d80, field_60, 0x60);

// 0x7101044d80
bool Unk_1044d80_check(const Unk_1044d80* self) {
    return self->field_60 == 5;
}

struct Unk_1044e60 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_1044e60, field_64, 0x64);

// 0x7101044e60
bool Unk_1044e60_check(const Unk_1044e60* self) {
    return self->field_64 == 2;
}

struct Unk_10457c0 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_10457c0, field_68, 0x68);

// 0x71010457c0
u32 Unk_10457c0_get(const Unk_10457c0* self) {
    return (self->field_68 == 0) | (self->field_68 == 3);
}

struct Unk_10457e0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_10457e0, field_6c, 0x6c);

// 0x71010457e0
u32 Unk_10457e0_getField6c(const Unk_10457e0* self) {
    return self->field_6c;
}
