// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// Lifted through their own placeholder structs (cast_member).
struct Unk_c65b60 {
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
    u8 _8[0x58];
    u32 field_60;
    u32 field_64;
    u8 _68[0x2];
    u8 field_6a;
};
PKMN_OFFSET_ASSERT(Unk_c65b60, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_c65b60, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_c65b60, field_6a, 0x6a);

struct Unk_c65bc0 {
    u8 _0[0x60];
    u32 field_60;
    u8 _64[0x6];
    u8 field_6a;
};
PKMN_OFFSET_ASSERT(Unk_c65bc0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_c65bc0, field_6a, 0x6a);

// A class on Unk_239a418 whose type getter (0x7100c657d0) is out of line.
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type between Unk_239a418 and Unk_23dcb30 (its class isn't known yet).
struct Unk_27f0240 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

class Unk_23dcb30 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0240::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
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
    u8 _60[0x8];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_23dcb30, field_68, 0x68);

// 0x7100c65a20
const Unk_239a418_Type* Unk_23dcb30::vf_type() {
    return Unk_GetType();
}

// 0x7100c65b20
void Unk_23dcb30::vf9() {}

// 0x7100c65b30
void Unk_23dcb30::vf10() {}

// 0x7100c65b40
void Unk_23dcb30::vf11() {
    field_68 = 0;
}

// 0x7100c65b50
void Unk_23dcb30::vf12() {
    field_68 = 1;
}

// 0x7100c65b60
void Unk_23dcb30::vf13() {
    Unk_c65b60* self = reinterpret_cast<Unk_c65b60*>(this);
    self->vf14();
    if (self->field_60 == self->field_64) {
        if (self->field_6a != 0) {
            self->field_6a = 0;
            self->vf15();
            self->vf16();
            return;
        }
        self->vf16();
        return;
    }
    self->field_6a = 0;
    self->vf15();
    self->vf16();
}

// 0x7100c65bc0
void Unk_23dcb30::vf14() {
    Unk_c65bc0* self = reinterpret_cast<Unk_c65bc0*>(this);
    if (self->field_60 != 0) {
        return;
    }
    self->field_60 = 1;
    self->field_6a = 0;
}

// 0x7100c65be0
void Unk_23dcb30::vf15() {}

// 0x7100c65bf0
void Unk_23dcb30::vf16() {}
