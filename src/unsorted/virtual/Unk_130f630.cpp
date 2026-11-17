// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_131b690(void* self);
void Unk_131f690(void* self);

class Unk_242f710 {
public:
    virtual ~Unk_242f710();
    virtual void vf2();
    virtual void vf3();
};

// 0x710130f630
void Unk_242f710::vf2() {}

class Unk_242f740 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710130f6b0
void Unk_242f740::vf0() {}

class Unk_242f760 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710130f730
u32 Unk_242f760::vf0() {
    return 2;
}

class Unk_242f978 {
public:
    virtual ~Unk_242f978();
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

// 0x710131a3d0
void Unk_242f978::vf22() {}

class Unk_242f8c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710131ad50
void Unk_242f8c8::vf6() {
    Unk_131b690(this);
}

class Unk_242f910 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710131ae40
void Unk_242f910::vf5() {
    Unk_131b690(this);
}

class Unk_242f950 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710131ae50
void Unk_242f950::vf0() {
    Unk_131b690(this);
}

class Unk_242fb00 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710131b300
u32 Unk_242fb00::vf0() {
    return 1;
}

class Unk_242fb30 {
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

// 0x710131f320
void Unk_242fb30::vf6() {
    Unk_131f690(this);
}

// 0x710131d2e0
void Unk_242fb30::vf10() {}

class Unk_242fbc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710131f4d0
void Unk_242fbc8::vf5() {
    Unk_131f690(this);
}

class Unk_242fc08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710131f4e0
void Unk_242fc08::vf0() {
    Unk_131f690(this);
}
