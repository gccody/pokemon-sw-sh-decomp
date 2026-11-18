// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a7e740(void* self);
void Unk_a91120(void* self);

class Unk_23c7ed0 {
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
};

// 0x7100a90df0
void Unk_23c7ed0::vf6() {
    Unk_a91120(this);
}

// 0x7100a8bfa0
void Unk_23c7ed0::vf10() {}

class Unk_23c7f68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a90f80
void Unk_23c7f68::vf5() {
    Unk_a91120(this);
}

class Unk_23c7fa8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a90f90
void Unk_23c7fa8::vf0() {
    Unk_a91120(this);
}

class Unk_23c8000 {
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
    virtual u32 vf10();
    u8 _8[0xe0];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_23c8000, field_e8, 0xe8);

// 0x7100a91970
u32 Unk_23c8000::vf10() {
    return field_e8;
}

class Unk_23c80d0 {
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
    virtual u32 vf10();
    u8 _8[0xe0];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_23c80d0, field_e8, 0xe8);

// 0x7100a92580
u32 Unk_23c80d0::vf10() {
    return field_e8;
}

class Unk_23c81e8 {
public:
    virtual ~Unk_23c81e8();
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
};

// 0x7100aaba90
void Unk_23c81e8::vf6() {
    Unk_a7e740(this);
}

// 0x7100a95a60
void Unk_23c81e8::vf8() {}

class Unk_23c8280 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100aabac0
void Unk_23c8280::vf5() {
    Unk_a7e740(this);
}

class Unk_23c82c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100aabad0
void Unk_23c82c0::vf0() {
    Unk_a7e740(this);
}
