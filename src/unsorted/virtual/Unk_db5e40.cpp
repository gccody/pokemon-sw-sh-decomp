// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ef868 {
public:
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
    u8 _64[0x4];
    u8 field_68;
    u8 _69[0x1];
    u8 field_6a;
};
PKMN_OFFSET_ASSERT(Unk_23ef868, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_23ef868, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_23ef868, field_6a, 0x6a);

// 0x7100db5e40
void Unk_23ef868::vf12() {
    field_68 = 1;
    field_60 = 0;
    field_6a = 0;
}

// 0x7100db6030
void Unk_23ef868::vf15() {}

class Unk_23ef968 {
public:
    virtual ~Unk_23ef968();
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
};

// 0x7100db7e10
void Unk_23ef968::vf9() {}
