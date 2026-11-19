// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_106e130_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_106e130_arg1, field_0, 0x0);

struct Unk_106e130 {
    u16 field_0;
    u8 _2[0x2];
    u32 field_4;
    u32 field_8;
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_106e130, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_106e130, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_106e130, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_106e130, field_c, 0xc);

// 0x710106e130
void Unk_106e130_set(Unk_106e130* self,
                     const Unk_106e130_arg1* value,
                     u16 arg2,
                     u32 arg3,
                     u16 arg4) {
    self->field_0 = arg2;
    self->field_4 = value->field_0;
    self->field_8 = arg3;
    self->field_c = arg4;
}

struct Unk_106e210_arg1 {
    u16 field_0;
    u8 _2[0x2];
    u32 field_4;
    u32 field_8;
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_106e210_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_106e210_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_106e210_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_106e210_arg1, field_c, 0xc);
struct Unk_106e210 {
    u16 field_0;
    u8 _2[0x2];
    u32 field_4;
    u32 field_8;
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_106e210, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_106e210, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_106e210, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_106e210, field_c, 0xc);

// 0x710106e210
bool Unk_106e210_check(const Unk_106e210* self, const Unk_106e210_arg1* value) {
    if (self->field_0 == value->field_0) {
        if (self->field_4 == value->field_4) {
            if (self->field_8 == value->field_8) {
                return self->field_c == value->field_c;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

struct Unk_106e270_arg1 {
    u16 field_0;
    u8 _2[0x2];
    u32 field_4;
    u32 field_8;
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_106e270_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_106e270_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_106e270_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_106e270_arg1, field_c, 0xc);
struct Unk_106e270 {
    u16 field_0;
    u8 _2[0x2];
    u32 field_4;
    u32 field_8;
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_106e270, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_106e270, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_106e270, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_106e270, field_c, 0xc);

// 0x710106e270
bool Unk_106e270_check(const Unk_106e270* self, const Unk_106e270_arg1* value) {
    if (self->field_0 == value->field_0) {
        if (self->field_4 == value->field_4) {
            if (self->field_8 == value->field_8) {
                return self->field_c != value->field_c;
            }
            return 1;
        }
        return 1;
    }
    return 1;
}

struct Unk_106e2d0 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_106e2d0, field_4, 0x4);

// 0x710106e2d0
u8* Unk_106e2d0_getField4Ptr(Unk_106e2d0* self) {
    return &self->field_4;
}

// 0x710106e2e0
void Unk_106e2e0() {}

struct Unk_106e2f0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_106e2f0, field_8, 0x8);

// 0x710106e2f0
u8* Unk_106e2f0_getField8Ptr(Unk_106e2f0* self) {
    return &self->field_8;
}

struct Unk_106e300 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_106e300, field_c, 0xc);

// 0x710106e300
u8* Unk_106e300_getFieldcPtr(Unk_106e300* self) {
    return &self->field_c;
}
