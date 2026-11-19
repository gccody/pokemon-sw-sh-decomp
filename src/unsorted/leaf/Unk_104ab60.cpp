// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_104ab60 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_104ab60, field_0, 0x0);

// 0x710104ab60
u32 Unk_104ab60_getField0(const Unk_104ab60* self) {
    return self->field_0;
}

struct Unk_104ab70 {
    u8 _0[0x4];
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_104ab70, field_4, 0x4);

// 0x710104ab70
u16 Unk_104ab70_getField4(const Unk_104ab70* self) {
    return self->field_4;
}

struct Unk_104ab80 {
    u8 _0[0x6];
    u8 field_6;
};
PKMN_OFFSET_ASSERT(Unk_104ab80, field_6, 0x6);

// 0x710104ab80
u8 Unk_104ab80_getField6(const Unk_104ab80* self) {
    return self->field_6;
}

struct Unk_104ab90 {
    u8 _0[0x7];
    u8 field_7;
};
PKMN_OFFSET_ASSERT(Unk_104ab90, field_7, 0x7);

// 0x710104ab90
u8 Unk_104ab90_getField7(const Unk_104ab90* self) {
    return self->field_7;
}

struct Unk_104aba0 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_104aba0, field_8, 0x8);

// 0x710104aba0
u16 Unk_104aba0_getField8(const Unk_104aba0* self) {
    return self->field_8;
}

struct Unk_104ad80 {
    virtual void vf0();
    virtual void vf1();
    virtual u64 vf2();
};

// 0x710104ad80
u64 Unk_104ad80_call(Unk_104ad80* self) {
    u64 r0 = self->vf2();
    return r0 == 0 ? 0 : (r0 + 0xa);
}
