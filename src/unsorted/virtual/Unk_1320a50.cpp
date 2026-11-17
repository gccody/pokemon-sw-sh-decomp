// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1320ae0(void* self);
void Unk_1320fd0(void* self);
void Unk_1321580(void* self);
void Unk_1323280(void* self);

class Unk_242fd30 {
public:
    virtual ~Unk_242fd30();
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

// 0x7101320a70
void Unk_242fd30::vf6() {
    Unk_1320ae0(this);
}

// 0x7101320a50
void Unk_242fd30::vf9() {}

class Unk_242fd98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101320aa0
void Unk_242fd98::vf5() {
    Unk_1320ae0(this);
}

class Unk_242fdd8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101320ab0
void Unk_242fdd8::vf0() {
    Unk_1320ae0(this);
}

class Unk_242fe00 {
public:
    virtual ~Unk_242fe00();
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

// 0x7101320f60
void Unk_242fe00::vf6() {
    Unk_1320fd0(this);
}

// 0x7101320f40
void Unk_242fe00::vf9() {}

class Unk_242fe68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101320f90
void Unk_242fe68::vf5() {
    Unk_1320fd0(this);
}

class Unk_242fea8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101320fa0
void Unk_242fea8::vf0() {
    Unk_1320fd0(this);
}

class Unk_242fed0 {
public:
    virtual ~Unk_242fed0();
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

// 0x7101321510
void Unk_242fed0::vf6() {
    Unk_1321580(this);
}

// 0x7101321210
void Unk_242fed0::vf8() {}

// 0x7101321220
void Unk_242fed0::vf10() {}

// 0x7101321230
u32 Unk_242fed0::vf16() {
    return 0;
}

class Unk_242ff68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101321540
void Unk_242ff68::vf5() {
    Unk_1321580(this);
}

class Unk_242ffa8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101321550
void Unk_242ffa8::vf0() {
    Unk_1321580(this);
}

class Unk_242ffd0 {
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

// 0x7101322e50
void Unk_242ffd0::vf6() {
    Unk_1323280(this);
}

// 0x7101322a90
void Unk_242ffd0::vf9() {}

class Unk_2430038 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101323060
void Unk_2430038::vf5() {
    Unk_1323280(this);
}

class Unk_2430078 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101323070
void Unk_2430078::vf0() {
    Unk_1323280(this);
}
