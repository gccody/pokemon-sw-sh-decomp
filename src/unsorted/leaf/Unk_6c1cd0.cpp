// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6c1cd0 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6c1cd0, field_0, 0x0);

// 0x71006c1cd0
u32 Unk_6c1cd0_get(const Unk_6c1cd0* self) {
    return (self->field_0 >> 4) & 0xf;
}

struct Unk_6c1f30 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6c1f30, field_0, 0x0);

// 0x71006c1f30
u8 Unk_6c1f30_getField0(const Unk_6c1f30* self) {
    return self->field_0;
}

// 0x71006c1ff0
void Unk_6c1ff0() {}

struct Unk_6c2000 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_6c2000, field_2, 0x2);

// 0x71006c2000
u8* Unk_6c2000_getField2Ptr(Unk_6c2000* self) {
    return &self->field_2;
}

struct Unk_6c2010 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_6c2010, field_4, 0x4);

// 0x71006c2010
u8* Unk_6c2010_getField4Ptr(Unk_6c2010* self) {
    return &self->field_4;
}

struct Unk_6c2070 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6c2070, field_0, 0x0);

// 0x71006c2070
u32 Unk_6c2070_getField0(const Unk_6c2070* self) {
    return self->field_0;
}

struct Unk_6c2080 {
    u8 _0[0x4];
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_6c2080, field_4, 0x4);

// 0x71006c2080
u16 Unk_6c2080_getField4(const Unk_6c2080* self) {
    return self->field_4;
}
