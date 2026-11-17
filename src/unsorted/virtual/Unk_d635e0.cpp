// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d64290(void* self);
void Unk_13eb080(void* self);

class Unk_23ec918 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100d63950
void Unk_23ec918::vf6() {
    Unk_13eb080(this);
}

// 0x7100d635e0
u32 Unk_23ec918::vf7() {
    return 1;
}

// 0x7100d635f0
void Unk_23ec918::vf8() {}

// 0x7100d63820
void Unk_23ec918::vf10() {}

class Unk_23ec980 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d63a80
void Unk_23ec980::vf5() {
    Unk_13eb080(this);
}

class Unk_23ec9c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d63a90
void Unk_23ec9c0::vf0() {
    Unk_13eb080(this);
}

class Unk_23ec9e8 {
public:
    virtual ~Unk_23ec9e8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    u8 _8[0x8c];
    u32 field_94;
};
PKMN_OFFSET_ASSERT(Unk_23ec9e8, field_94, 0x94);

// 0x7100d64220
void Unk_23ec9e8::vf6() {
    Unk_d64290(this);
}

// 0x7100d63ce0
u32 Unk_23ec9e8::vf7() {
    return 1;
}

// 0x7100d63cf0
void Unk_23ec9e8::vf8() {
    field_94 = 1;
}

// 0x7100d64200
void Unk_23ec9e8::vf10() {}

class Unk_23eca50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d64250
void Unk_23eca50::vf5() {
    Unk_d64290(this);
}

class Unk_23eca90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d64260
void Unk_23eca90::vf0() {
    Unk_d64290(this);
}

class Unk_23ecab8 {
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
    u8 _8[0x60];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_23ecab8, field_68, 0x68);

// 0x7100d64730
void Unk_23ecab8::vf11() {
    field_68 = 0;
}

// 0x7100d64740
void Unk_23ecab8::vf12() {
    field_68 = 1;
}
