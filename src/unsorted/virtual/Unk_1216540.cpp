// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1217300(void* self);

class Unk_2423ec8 {
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
    virtual void vf17();
};

// 0x7101216540
void Unk_2423ec8::vf10() {}

// 0x7101216ff0
void Unk_2423ec8::vf11() {}

// 0x7101217000
void Unk_2423ec8::vf12() {}

// 0x7101217010
void Unk_2423ec8::vf13() {}

// 0x7101217020
void Unk_2423ec8::vf14() {}

// 0x7101217030
void Unk_2423ec8::vf15() {}

// 0x7101217040
void Unk_2423ec8::vf16() {}

// 0x7101217050
void Unk_2423ec8::vf17() {}

class Unk_2423d30 {
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
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
};

// 0x7101216b70
void Unk_2423d30::vf6() {
    Unk_1217300(this);
}

// 0x7101216a50
void Unk_2423d30::vf20() {}

class Unk_2423eb0 {
public:
    virtual void vf0();
};

// 0x7101216a60
void Unk_2423eb0::vf0() {}

class Unk_2423de8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101216c80
void Unk_2423de8::vf5() {
    Unk_1217300(this);
}

class Unk_2423e28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101216c90
void Unk_2423e28::vf0() {
    Unk_1217300(this);
}
