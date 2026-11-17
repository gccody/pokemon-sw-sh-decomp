// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_59b970(void* self);
void Unk_5d8db0(void* self);
void Unk_5eca40(void* self);
void Unk_619640(void* self);

class Unk_2399708 {
public:
    virtual ~Unk_2399708();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8() = 0;
};

// 0x71005d5870
void Unk_2399708::vf6() {
    Unk_5eca40(this);
}

class Unk_2399760 {
public:
    virtual ~Unk_2399760();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71005d58f0
void Unk_2399760::vf5() {
    Unk_5eca40(this);
}

class Unk_23997a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005d5900
void Unk_23997a0::vf0() {
    Unk_5eca40(this);
}

class Unk_2399a38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005d8510
void Unk_2399a38::vf2() {}

class Unk_2399a68 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005d8590
void Unk_2399a68::vf0() {}

class Unk_2399a88 {
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

// 0x71005d8a50
void Unk_2399a88::vf5() {
    Unk_5d8db0(this);
}

class Unk_2399b18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005d8c00
void Unk_2399b18::vf0() {
    Unk_5d8db0(this);
}

class Unk_2399bf0 {
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

// 0x71005db430
void Unk_2399bf0::vf12() {}

// 0x71005db450
void Unk_2399bf0::vf13() {}

class Unk_2399c70 {
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
};

// 0x71005db440
void Unk_2399c70::vf10() {}

// 0x71005db460
void Unk_2399c70::vf11() {}

class Unk_2399d08 {
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
    virtual u32 vf16();
};

// 0x71005db9e0
void Unk_2399d08::vf6() {
    Unk_619640(this);
}

// 0x71005dba40
void Unk_2399d08::vf15() {
    Unk_59b970(this);
}

// 0x71005dba50
u32 Unk_2399d08::vf16() {
    return 0;
}

class Unk_2399da0 {
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
};

// 0x71005dbb80
void Unk_2399da0::vf5() {
    Unk_619640(this);
}

class Unk_2399e10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005dbb90
void Unk_2399e10::vf0() {
    Unk_619640(this);
}
