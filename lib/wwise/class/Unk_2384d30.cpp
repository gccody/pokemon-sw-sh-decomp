// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3dce80_arg1 {
    u8 _0[0x10];
    u16 field_10;
    u8 _12[0x1e];
    u32 field_30;
};
PKMN_OFFSET_ASSERT(Unk_3dce80_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3dce80_arg1, field_30, 0x30);
struct Unk_3dce80 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15(void*);
    u8 _8[0x80];
    u8 field_88;
    u8 _89[0x17];
    u16 field_a0;
    u8 _a2[0x18];
    u16 field_ba;
};
PKMN_OFFSET_ASSERT(Unk_3dce80, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_3dce80, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_3dce80, field_ba, 0xba);

struct Unk_3dd7a0 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_3dd7a0, field_98, 0x98);

struct Unk_3dd740 {
    u8 _0[0xe8];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_3dd740, field_e8, 0xe8);

class Unk_2384d30 {
public:
    void vf14(Unk_3dce80_arg1* value);
    u64 vf16();
    u32 vf17();
};

// 0x71003dce80
void Unk_2384d30::vf14(Unk_3dce80_arg1* value) {
    Unk_3dce80* self = reinterpret_cast<Unk_3dce80*>(this);
    self->field_a0 = value->field_10;
    if (self->field_88 != 0) {
        value->field_30 = 0x11;
        self->vf15(value);
        return;
    }
    if (self->field_ba != 0) {
        self->vf15(value);
        return;
    }
}

// 0x71003dd740
u32 Unk_2384d30::vf17() {
    const Unk_3dd740* self = reinterpret_cast<const Unk_3dd740*>(this);
    return self->field_e8;
}

// 0x71003dd7a0
u64 Unk_2384d30::vf16() {
    const Unk_3dd7a0* self = reinterpret_cast<const Unk_3dd7a0*>(this);
    return self->field_98;
}
