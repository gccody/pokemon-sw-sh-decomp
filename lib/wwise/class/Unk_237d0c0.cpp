// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_312460_98_8 {
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
    virtual void vf18(u64, u64, u64, u64, u64, u32);
};

struct Unk_312460_98 {
    u8 _0[0x8];
    Unk_312460_98_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_312460_98, field_8, 0x8);

struct Unk_312460 {
    u8 _0[0x98];
    Unk_312460_98* field_98;
};
PKMN_OFFSET_ASSERT(Unk_312460, field_98, 0x98);

struct Unk_312a40 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_312a40, field_78, 0x78);

class Unk_237d0c0 {
public:
    void vf18(u64 value, u64 arg2, u64 arg3, u64 arg4, u64 arg5, bool arg6);
    u64 vf22();
};

// 0x7100312460
void Unk_237d0c0::vf18(u64 value, u64 arg2, u64 arg3, u64 arg4, u64 arg5, bool arg6) {
    const Unk_312460* self = reinterpret_cast<const Unk_312460*>(this);
    self->field_98->field_8->vf18(value, arg2, arg3, arg4, arg5, arg6);
}

// 0x7100312a40
u64 Unk_237d0c0::vf22() {
    const Unk_312a40* self = reinterpret_cast<const Unk_312a40*>(this);
    return self->field_78;
}
