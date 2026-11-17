// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12e8820(void* self);

class Unk_242e368 {
public:
    virtual ~Unk_242e368();
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

// 0x71012e8550
void Unk_242e368::vf6() {
    Unk_12e8820(this);
}

// 0x71012e8150
void Unk_242e368::vf9() {}

class Unk_242e3d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012e8580
void Unk_242e3d0::vf5() {
    Unk_12e8820(this);
}

class Unk_242e410 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012e8590
void Unk_242e410::vf0() {
    Unk_12e8820(this);
}
