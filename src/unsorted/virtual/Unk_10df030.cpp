// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6a1ee0(u64);

class Unk_2415868 {
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
PKMN_OFFSET_ASSERT(Unk_2415868, field_78, 0x78);

// 0x71010df030
void Unk_2415868::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2415968 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010df870
void Unk_2415968::vf0() {}

// 0x71010df880
void Unk_2415968::vf1() {}

// 0x71010df890
void Unk_2415968::vf2() {}

class Unk_2415a40 {
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
PKMN_OFFSET_ASSERT(Unk_2415a40, field_78, 0x78);

// 0x71010e0250
void Unk_2415a40::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2415b40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010e0a90
void Unk_2415b40::vf0() {}

// 0x71010e0aa0
void Unk_2415b40::vf1() {}

// 0x71010e0ab0
void Unk_2415b40::vf2() {}

class Unk_2415b68 {
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
PKMN_OFFSET_ASSERT(Unk_2415b68, field_78, 0x78);

// 0x71010e1060
void Unk_2415b68::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2415c68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010e17f0
void Unk_2415c68::vf0() {}

// 0x71010e1800
void Unk_2415c68::vf1() {}

// 0x71010e1810
void Unk_2415c68::vf2() {}

class Unk_2415df0 {
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
PKMN_OFFSET_ASSERT(Unk_2415df0, field_78, 0x78);

// 0x71010e2620
void Unk_2415df0::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2415ef0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010e2e70
void Unk_2415ef0::vf0() {}

// 0x71010e2e80
void Unk_2415ef0::vf1() {}

// 0x71010e2e90
void Unk_2415ef0::vf2() {}
