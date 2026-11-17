// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_11bd380(void* self);

class Unk_241fb28 {
public:
    virtual ~Unk_241fb28();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

// 0x71011bd8d0
void Unk_241fb28::vf8() {
    Unk_11bd380(this);
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

// 0x71011bdac0
void Unk_23ce100::vf2() {}

// 0x71011bdae0
void Unk_23ce100::vf5() {}

class Unk_23d3800 {
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
};

// 0x71011bdad0
void Unk_23d3800::vf4() {}

class Unk_23cda40 {
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
    u8 _8[0x14];
    u8 field_1c;
    u8 _1d[0x3];
    u32 field_20;
    u8 _24[0x1];
    u8 field_25;
    u8 _26[0x1a2];
    u8 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_23cda40, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_23cda40, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23cda40, field_25, 0x25);
PKMN_OFFSET_ASSERT(Unk_23cda40, field_1c8, 0x1c8);

// 0x71011bdaf0
void Unk_23cda40::vf6() {}

// 0x71011bdb00
void Unk_23cda40::vf9() {}
