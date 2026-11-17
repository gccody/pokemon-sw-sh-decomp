// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_db1070(void* self);
void Unk_db5380(void* self);

class Unk_23ef6a8 {
public:
    virtual ~Unk_23ef6a8();
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
};

// 0x7100db0f80
void Unk_23ef6a8::vf9() {}

// 0x7100db30d0
void Unk_23ef6a8::vf11() {
    Unk_db1070(this);
}

class Unk_23ef798 {
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

// 0x7100db5170
void Unk_23ef798::vf6() {
    Unk_db5380(this);
}

// 0x7100db4360
u32 Unk_23ef798::vf7() {
    return 1;
}

// 0x7100db4370
void Unk_23ef798::vf8() {}

// 0x7100db5080
void Unk_23ef798::vf10() {}

class Unk_23ef800 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100db5280
void Unk_23ef800::vf5() {
    Unk_db5380(this);
}

class Unk_23ef840 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100db5290
void Unk_23ef840::vf0() {
    Unk_db5380(this);
}
