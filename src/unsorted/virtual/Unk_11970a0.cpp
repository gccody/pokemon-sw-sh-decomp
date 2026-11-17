// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1197830(void* self);
void Unk_1198110(void* self);

class Unk_241d190 {
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
    virtual u32 vf11();
    virtual void vf12();
    virtual void vf13();
};

// 0x71011970a0
u32 Unk_241d190::vf11() {
    return 1;
}

class Unk_241df40 {
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
    virtual u32 vf12();
    virtual void vf13();
};

// 0x71011970b0
u32 Unk_241df40::vf12() {
    return 1;
}

// 0x71011970c0
void Unk_241df40::vf13() {}

class Unk_241dad0 {
public:
    virtual ~Unk_241dad0();
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
};

// 0x71011977c0
void Unk_241dad0::vf6() {
    Unk_1197830(this);
}

class Unk_241dba0 {
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

// 0x71011977f0
void Unk_241dba0::vf5() {
    Unk_1197830(this);
}

class Unk_241dc10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101197800
void Unk_241dc10::vf0() {
    Unk_1197830(this);
}

class Unk_241dc38 {
public:
    virtual ~Unk_241dc38();
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
};

// 0x71011980a0
void Unk_241dc38::vf6() {
    Unk_1198110(this);
}

class Unk_241dd08 {
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

// 0x71011980d0
void Unk_241dd08::vf5() {
    Unk_1198110(this);
}

class Unk_241dd78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71011980e0
void Unk_241dd78::vf0() {
    Unk_1198110(this);
}

class Unk_241dda0 {
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
};

// 0x7101198450
void Unk_241dda0::vf10() {}
