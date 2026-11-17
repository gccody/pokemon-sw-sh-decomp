// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6a1ee0(u64);

class Unk_2416438 {
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
PKMN_OFFSET_ASSERT(Unk_2416438, field_78, 0x78);

// 0x71010e7140
void Unk_2416438::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2416538 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010e7980
void Unk_2416538::vf0() {}

// 0x71010e7990
void Unk_2416538::vf1() {}

// 0x71010e79a0
void Unk_2416538::vf2() {}

class Unk_24166c0 {
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
PKMN_OFFSET_ASSERT(Unk_24166c0, field_78, 0x78);

// 0x71010e88a0
void Unk_24166c0::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_24167c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010e90e0
void Unk_24167c0::vf0() {}

// 0x71010e90f0
void Unk_24167c0::vf1() {}

// 0x71010e9100
void Unk_24167c0::vf2() {}

class Unk_24167e8 {
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
PKMN_OFFSET_ASSERT(Unk_24167e8, field_78, 0x78);

// 0x71010e96b0
void Unk_24167e8::vf8() {
    Unk_6a1ee0(field_78);
}
