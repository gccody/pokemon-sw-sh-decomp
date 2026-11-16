// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8139c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8139c0, field_0, 0x0);

// 0x71008139c0
void Unk_8139c0_clearField0(Unk_8139c0* self) {
    self->field_0 = 0;
}

struct Unk_8139d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8139d0, field_0, 0x0);

// 0x71008139d0
void Unk_8139d0_clearField0(Unk_8139d0* self) {
    self->field_0 = 0;
}

struct Unk_813a20 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_813a20, field_8, 0x8);

// 0x7100813a20
u8* Unk_813a20_getField8Ptr(Unk_813a20* self) {
    return &self->field_8;
}

struct Unk_813a30 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_813a30, field_0, 0x0);

// 0x7100813a30
u32 Unk_813a30_getField0(const Unk_813a30* self) {
    return self->field_0;
}

struct Unk_813b20 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_813b20, field_4, 0x4);

// 0x7100813b20
u32 Unk_813b20_getField4(const Unk_813b20* self) {
    return self->field_4;
}

struct Unk_813d50 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_813d50, field_4, 0x4);

// 0x7100813d50
void Unk_813d50_setField4(Unk_813d50* self, u32 value) {
    self->field_4 = value;
}
