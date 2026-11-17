// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6a1ee0(u64);

class Unk_2412c88 {
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
PKMN_OFFSET_ASSERT(Unk_2412c88, field_78, 0x78);

// 0x71010bd130
void Unk_2412c88::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2412d88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010bd9e0
void Unk_2412d88::vf0() {}

// 0x71010bd9f0
void Unk_2412d88::vf1() {}

// 0x71010bda00
void Unk_2412d88::vf2() {}

class Unk_2412f10 {
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
PKMN_OFFSET_ASSERT(Unk_2412f10, field_78, 0x78);

// 0x71010bea50
void Unk_2412f10::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2413010 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010bf300
void Unk_2413010::vf0() {}

// 0x71010bf310
void Unk_2413010::vf1() {}

// 0x71010bf320
void Unk_2413010::vf2() {}

class Unk_2413198 {
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
PKMN_OFFSET_ASSERT(Unk_2413198, field_78, 0x78);

// 0x71010c0150
void Unk_2413198::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2413298 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010c0a10
void Unk_2413298::vf0() {}

// 0x71010c0a20
void Unk_2413298::vf1() {}

// 0x71010c0a30
void Unk_2413298::vf2() {}

class Unk_2413370 {
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
PKMN_OFFSET_ASSERT(Unk_2413370, field_78, 0x78);

// 0x71010c1410
void Unk_2413370::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2413470 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010c1cc0
void Unk_2413470::vf0() {}

// 0x71010c1cd0
void Unk_2413470::vf1() {}

// 0x71010c1ce0
void Unk_2413470::vf2() {}
