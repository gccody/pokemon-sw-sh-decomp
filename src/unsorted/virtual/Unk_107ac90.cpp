// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_15b6e10(void* self);

class Unk_240cfd8 {
public:
    virtual ~Unk_240cfd8();
    virtual void vf2();
    virtual u32 vf3();
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
};

// 0x710107ac90
u32 Unk_240cfd8::vf3() {
    return 1;
}

class Unk_240d058 {
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
};

// 0x710107b120
void Unk_240d058::vf1() {}

// 0x710107b130
void Unk_240d058::vf2() {}

// 0x710107b140
void Unk_240d058::vf3() {}

// 0x710107b150
void Unk_240d058::vf4() {}

// 0x710107b160
void Unk_240d058::vf5() {}

// 0x710107b170
void Unk_240d058::vf6() {}

// 0x710107b180
void Unk_240d058::vf7() {}

// 0x710107b190
void Unk_240d058::vf8() {}

// 0x710107b1a0
void Unk_240d058::vf9() {}

// 0x710107b1b0
void Unk_240d058::vf10() {}

// 0x710107b1c0
void Unk_240d058::vf11() {}

// 0x710107b1d0
void Unk_240d058::vf13() {}

class Unk_240d118 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710107b420
void Unk_240d118::vf0() {}

// 0x710107b430
void Unk_240d118::vf1() {
    Unk_15b6e10(this);
}

class Unk_240d138 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710107b440
void Unk_240d138::vf1() {
    Unk_15b6e10(this);
}

class Unk_240d158 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710107b450
void Unk_240d158::vf1() {
    Unk_15b6e10(this);
}

class Unk_240d178 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710107b460
void Unk_240d178::vf1() {
    Unk_15b6e10(this);
}

class Unk_240d1d8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710107bbb0
void Unk_240d1d8::vf1() {
    Unk_15b6e10(this);
}
