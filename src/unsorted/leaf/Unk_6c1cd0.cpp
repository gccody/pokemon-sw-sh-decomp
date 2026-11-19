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

extern u64 Unk_24ba170;
u64 Unk_6aed90(u64);

// 0x71006c1f00
u64 Unk_6c1f00_call() {
    if (Unk_24ba170 == 0) {
        return 0;
    }
    u64 r0 = Unk_6aed90(Unk_24ba170);
    return r0 & 1;
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

struct Unk_6c2020_arg1 {
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
};

struct Unk_6c2020 {
    u32 field_0;
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_6c2020, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6c2020, field_4, 0x4);

// 0x71006c2020
void Unk_6c2020_call(Unk_6c2020* self, Unk_6c2020_arg1* value) {
    u32 r0 = value->vf3();
    self->field_0 = r0;
    u32 r1 = value->vf2();
    self->field_4 = r1;
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

struct Unk_6c2430 {
    virtual void vf0();
    virtual void vf1();
    virtual u64 vf2();
};

// 0x71006c2430
u64 Unk_6c2430_call(Unk_6c2430* self) {
    u64 r0 = self->vf2();
    return r0 + 5;
}
