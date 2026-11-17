// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6a1ee0(u64);

class Unk_2416cc8 {
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
PKMN_OFFSET_ASSERT(Unk_2416cc8, field_78, 0x78);

// 0x71010ecd20
void Unk_2416cc8::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2416dc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010ed540
void Unk_2416dc8::vf0() {}

// 0x71010ed550
void Unk_2416dc8::vf1() {}

// 0x71010ed560
void Unk_2416dc8::vf2() {}

class Unk_24170c8 {
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
PKMN_OFFSET_ASSERT(Unk_24170c8, field_78, 0x78);

// 0x71010eef90
void Unk_24170c8::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_24171c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010ef7c0
void Unk_24171c8::vf0() {}

// 0x71010ef7d0
void Unk_24171c8::vf1() {}

// 0x71010ef7e0
void Unk_24171c8::vf2() {}

class Unk_24171f0 {
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
PKMN_OFFSET_ASSERT(Unk_24171f0, field_78, 0x78);

// 0x71010efb40
void Unk_24171f0::vf8() {
    Unk_6a1ee0(field_78);
}
