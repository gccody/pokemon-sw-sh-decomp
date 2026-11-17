// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_124a100(void* self);
void Unk_124af10(void* self);
void Unk_1250f00(void* self);

class Unk_24269d8 {
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

// 0x7101249f90
void Unk_24269d8::vf6() {
    Unk_124a100(this);
}

class Unk_2426a70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710124a040
void Unk_2426a70::vf5() {
    Unk_124a100(this);
}

class Unk_2426ab0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710124a050
void Unk_2426ab0::vf0() {
    Unk_124a100(this);
}

class Unk_2426be8 {
public:
    virtual ~Unk_2426be8();
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

// 0x710124aea0
void Unk_2426be8::vf6() {
    Unk_124af10(this);
}

class Unk_2426c80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710124aed0
void Unk_2426c80::vf5() {
    Unk_124af10(this);
}

class Unk_2426cc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710124aee0
void Unk_2426cc0::vf0() {
    Unk_124af10(this);
}

class Unk_2426db8 {
public:
    virtual ~Unk_2426db8();
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

// 0x7101250e90
void Unk_2426db8::vf6() {
    Unk_1250f00(this);
}

// 0x710124d540
void Unk_2426db8::vf9() {}

class Unk_2426e20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101250ec0
void Unk_2426e20::vf5() {
    Unk_1250f00(this);
}

class Unk_2426e60 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101250ed0
void Unk_2426e60::vf0() {
    Unk_1250f00(this);
}
