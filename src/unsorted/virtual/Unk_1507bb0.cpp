// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1508500(void* self);
void Unk_150c500(void* self);
void Unk_150cd80(void* self);

class Unk_2446808 {
public:
    virtual ~Unk_2446808();
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
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
};

// 0x7101507bb0
void Unk_2446808::vf22() {}

class Unk_2446950 {
public:
    virtual ~Unk_2446950();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101508490
void Unk_2446950::vf6() {
    Unk_1508500(this);
}

class Unk_2446998 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71015084c0
void Unk_2446998::vf5() {
    Unk_1508500(this);
}

class Unk_24469d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71015084d0
void Unk_24469d8::vf0() {
    Unk_1508500(this);
}

class Unk_2446c08 {
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

// 0x710150c1c0
void Unk_2446c08::vf6() {
    Unk_150c500(this);
}

class Unk_2446ca0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710150c380
void Unk_2446ca0::vf5() {
    Unk_150c500(this);
}

class Unk_2446ce0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710150c390
void Unk_2446ce0::vf0() {
    Unk_150c500(this);
}

class Unk_2446d08 {
public:
    virtual ~Unk_2446d08();
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

// 0x710150ccc0
void Unk_2446d08::vf6() {
    Unk_150cd80(this);
}

class Unk_2446da0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710150cd40
void Unk_2446da0::vf5() {
    Unk_150cd80(this);
}

class Unk_2446de0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710150cd50
void Unk_2446de0::vf0() {
    Unk_150cd80(this);
}
