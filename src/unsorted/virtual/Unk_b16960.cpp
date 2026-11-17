// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ce028 {
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
    u8 _8[0x88];
    u32 field_90;
    u8 _94[0x44];
    u8 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_23ce028, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23ce028, field_d8, 0xd8);

// 0x7100b16c80
void Unk_23ce028::vf9() {}

// 0x7100b16960
void Unk_23ce028::vf11() {
    field_90 = field_d8 == 0 ? 0xd : 0xf;
}

class Unk_23ce100 {
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
    u32 field_8;
    u8 _c[0x44];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_23ce100, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23ce100, field_50, 0x50);

// 0x7100b16980
void Unk_23ce100::vf4() {
    field_8 = field_50 == 0 ? 0xd : 0xf;
}
