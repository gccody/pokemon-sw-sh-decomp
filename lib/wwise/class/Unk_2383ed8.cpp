// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3ca1e0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3ca1e0, field_20, 0x20);

struct Unk_3ca1d0_20 {
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
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18(u64);
};

struct Unk_3ca1d0 {
    u8 _0[0x20];
    Unk_3ca1d0_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_3ca1d0, field_20, 0x20);

extern u32 Unk_2382e78;

class Unk_2383ed8 {
public:
    u64 vf3();
    u32 vf7();
    u32 vf8();
    u32 vf9();
    void vf11(u64 value);
    u64 vf13();
    u32 vf17();
};

// 0x71003ca020
u32 Unk_2383ed8::vf7() {
    return 2;
}

// 0x71003ca030
u32 Unk_2383ed8::vf8() {
    return 0;
}

// 0x71003ca040
u32 Unk_2383ed8::vf9() {
    return 2;
}

// 0x71003ca1d0
void Unk_2383ed8::vf11(u64 value) {
    const Unk_3ca1d0* self = reinterpret_cast<const Unk_3ca1d0*>(this);
    self->field_20->vf18(value);
}

// 0x71003ca1e0
u64 Unk_2383ed8::vf3() {
    const Unk_3ca1e0* self = reinterpret_cast<const Unk_3ca1e0*>(this);
    return self->field_20;
}

// 0x71003ca220
u64 Unk_2383ed8::vf13() {
    return 0;
}

// 0x71003ca230
u32 Unk_2383ed8::vf17() {
    return Unk_2382e78;
}
