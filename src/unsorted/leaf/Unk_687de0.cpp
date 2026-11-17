// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_687de0_198 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_687de0_198, field_80, 0x80);

struct Unk_687de0 {
    u8 _0[0x198];
    Unk_687de0_198* field_198;
};
PKMN_OFFSET_ASSERT(Unk_687de0, field_198, 0x198);

// 0x7100687de0
u8* Unk_687de0_get(const Unk_687de0* self) {
    return &self->field_198->field_80;
}

struct Unk_68d900 {
    u8 _0[0x260];
    u8 field_260;
};
PKMN_OFFSET_ASSERT(Unk_68d900, field_260, 0x260);

// 0x710068d900
u8* Unk_68d900_getField260Ptr(Unk_68d900* self) {
    return &self->field_260;
}

struct Unk_68d910_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_68d910_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_68d910_arg1, field_8, 0x8);

struct Unk_68d910 {
    u8 _0[0x260];
    u64 field_260;
    u64 field_268;
};
PKMN_OFFSET_ASSERT(Unk_68d910, field_260, 0x260);
PKMN_OFFSET_ASSERT(Unk_68d910, field_268, 0x268);

// 0x710068d910
void Unk_68d910_set(Unk_68d910* self, const Unk_68d910_arg1* value) {
    self->field_268 = value->field_8;
    self->field_260 = value->field_0;
}

struct Unk_68d930 {
    u8 _0[0x27a];
    u8 field_27a;
};
PKMN_OFFSET_ASSERT(Unk_68d930, field_27a, 0x27a);

// 0x710068d930
void Unk_68d930_set(Unk_68d930* self) {
    self->field_27a = 1;
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

struct Unk_692920_198 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_692920_198, field_80, 0x80);

struct Unk_692920 {
    u8 _0[0x198];
    Unk_692920_198* field_198;
};
PKMN_OFFSET_ASSERT(Unk_692920, field_198, 0x198);

// 0x7100692920
u32 Unk_692920_get(const Unk_692920* self) {
    return self->field_198->field_80;
}

// 0x7100694510
void Unk_694510() {}

// 0x71006955b0
void Unk_6955b0() {}
