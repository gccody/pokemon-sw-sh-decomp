// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_126c7a0(void* self);

class Unk_24283e8 {
public:
    virtual ~Unk_24283e8();
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

// 0x710126bc90
void Unk_24283e8::vf6() {
    Unk_126c7a0(this);
}

// 0x7101269800
void Unk_24283e8::vf9() {}

class Unk_24284d0 {
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

// 0x710126ad40
void Unk_24284d0::vf10() {}

class Unk_2428468 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710126bcc0
void Unk_2428468::vf5() {
    Unk_126c7a0(this);
}

class Unk_24284a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710126bcd0
void Unk_24284a8::vf0() {
    Unk_126c7a0(this);
}
