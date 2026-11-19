// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8c6810 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_8c6810, field_64, 0x64);

// 0x71008c6810
u8 Unk_8c6810_getField64(const Unk_8c6810* self) {
    return self->field_64;
}

struct Unk_8c6820 {
    u8 _0[0x5c];
    u32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_8c6820, field_5c, 0x5c);

// 0x71008c6820
u32 Unk_8c6820_getField5c(const Unk_8c6820* self) {
    return self->field_5c;
}

struct Unk_8c2630;
struct Unk_8c82b0 {
    u8 _0[0xb8];
    Unk_8c2630* field_b8;
};
PKMN_OFFSET_ASSERT(Unk_8c82b0, field_b8, 0xb8);

u8 Unk_8c2630_getField288(const Unk_8c2630*);

// 0x71008c82b0
void Unk_8c82b0_call(const Unk_8c82b0* self) {
    Unk_8c2630_getField288(self->field_b8);
}

struct Unk_8c82c0 {
    u8 _0[0x1a1];
    u8 field_1a1;
};
PKMN_OFFSET_ASSERT(Unk_8c82c0, field_1a1, 0x1a1);

// 0x71008c82c0
u8 Unk_8c82c0_getField1a1(const Unk_8c82c0* self) {
    return self->field_1a1;
}

struct Unk_8c82d0 {
    u8 _0[0x198];
    u32 field_198;
};
PKMN_OFFSET_ASSERT(Unk_8c82d0, field_198, 0x198);

// 0x71008c82d0
u32 Unk_8c82d0_getField198(const Unk_8c82d0* self) {
    return self->field_198;
}

struct Unk_8c82e0_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c82e0_arg1, field_0, 0x0);

struct Unk_8c82e0_arg2 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c82e0_arg2, field_0, 0x0);

struct Unk_8c82e0 {
    u8 _0[0x19c];
    u8 field_19c;
    u8 field_19d;
    u8 _19e[0x3];
    u8 field_1a1;
};
PKMN_OFFSET_ASSERT(Unk_8c82e0, field_19c, 0x19c);
PKMN_OFFSET_ASSERT(Unk_8c82e0, field_19d, 0x19d);
PKMN_OFFSET_ASSERT(Unk_8c82e0, field_1a1, 0x1a1);

// 0x71008c82e0
void Unk_8c82e0_set(const Unk_8c82e0* self, Unk_8c82e0_arg1* value, Unk_8c82e0_arg2* arg2) {
    if (self->field_1a1 != 0) {
        value->field_0 = self->field_19c;
        arg2->field_0 = self->field_19d;
    }
}
