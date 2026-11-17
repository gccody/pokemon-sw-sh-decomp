// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_11c0350(void* self);

class Unk_241fe30 {
public:
    virtual ~Unk_241fe30();
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

// 0x71011c02e0
void Unk_241fe30::vf6() {
    Unk_11c0350(this);
}

class Unk_241fe98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71011c0310
void Unk_241fe98::vf5() {
    Unk_11c0350(this);
}

class Unk_241fed8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71011c0320
void Unk_241fed8::vf0() {
    Unk_11c0350(this);
}
