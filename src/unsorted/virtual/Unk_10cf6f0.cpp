// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6a1ee0(u64);

class Unk_2414508 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2414508, field_78, 0x78);

// 0x71010cf6f0
void Unk_2414508::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2414608 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2414608, field_78, 0x78);

// 0x71010d0610
void Unk_2414608::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_24147b8 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_24147b8, field_78, 0x78);

// 0x71010d16e0
void Unk_24147b8::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_24148b8 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_24148b8, field_78, 0x78);

// 0x71010d2250
void Unk_24148b8::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_24149b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010d2b00
void Unk_24149b8::vf0() {}

// 0x71010d2b10
void Unk_24149b8::vf1() {}

// 0x71010d2b20
void Unk_24149b8::vf2() {}
