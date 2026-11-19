// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3dca40_98 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Unk_3dca40_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

struct Unk_3dca40 {
    u8 _0[0x8];
    Unk_3dca40_8* field_8;
    u8 _10[0x78];
    u8 field_88;
    u8 _89[0xf];
    Unk_3dca40_98* field_98;
};
PKMN_OFFSET_ASSERT(Unk_3dca40, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3dca40, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_3dca40, field_98, 0x98);

struct Unk_3dc8c0_arg1 {
    u8 _0[0x30];
    u32 field_30;
};
PKMN_OFFSET_ASSERT(Unk_3dc8c0_arg1, field_30, 0x30);

struct Unk_3dc8c0 {
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
};
PKMN_OFFSET_ASSERT(Unk_3dc8c0, field_88, 0x88);

struct Unk_3dccd0 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_3dccd0, field_98, 0x98);

struct Unk_3dcc30 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_3dcc30, field_a8, 0xa8);

class Unk_2384bf0 {
public:
    void vf2();
    void vf7();
    u32 vf13();
    void vf14(Unk_3dc8c0_arg1* value);
    u64 vf16();
    u32 vf17();
};

// 0x71003dc8c0
void Unk_2384bf0::vf14(Unk_3dc8c0_arg1* value) {
    Unk_3dc8c0* self = reinterpret_cast<Unk_3dc8c0*>(this);
    if (self->field_88 != 0) {
        value->field_30 = 0x11;
        self->vf15(value);
    }
}

// 0x71003dca40
void Unk_2384bf0::vf7() {
    Unk_3dca40* self = reinterpret_cast<Unk_3dca40*>(this);
    self->field_98->vf3();
    self->field_88 = 0;
    self->field_8->vf7();
}

// 0x71003dcc30
u32 Unk_2384bf0::vf17() {
    const Unk_3dcc30* self = reinterpret_cast<const Unk_3dcc30*>(this);
    return self->field_a8;
}

// 0x71003dccc0
u32 Unk_2384bf0::vf13() {
    return 0;
}

// 0x71003dccd0
u64 Unk_2384bf0::vf16() {
    const Unk_3dccd0* self = reinterpret_cast<const Unk_3dccd0*>(this);
    return self->field_98;
}

// 0x7100404530
void Unk_2384bf0::vf2() {
}
