// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6a1ee0(u64);

class Unk_2414d00 {
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
PKMN_OFFSET_ASSERT(Unk_2414d00, field_78, 0x78);

// 0x71010d5fe0
void Unk_2414d00::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2414e00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010d6890
void Unk_2414e00::vf0() {}

// 0x71010d68a0
void Unk_2414e00::vf1() {}

// 0x71010d68b0
void Unk_2414e00::vf2() {}

class Unk_2415100 {
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
PKMN_OFFSET_ASSERT(Unk_2415100, field_78, 0x78);

// 0x71010d8350
void Unk_2415100::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2415200 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010d8b80
void Unk_2415200::vf0() {}

// 0x71010d8b90
void Unk_2415200::vf1() {}

// 0x71010d8ba0
void Unk_2415200::vf2() {}

class Unk_2415228 {
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
PKMN_OFFSET_ASSERT(Unk_2415228, field_78, 0x78);

// 0x71010d8f00
void Unk_2415228::vf8() {
    Unk_6a1ee0(field_78);
}
