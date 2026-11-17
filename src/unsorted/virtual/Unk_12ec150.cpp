// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12ec1e0(void* self);

class Unk_242e650 {
public:
    virtual ~Unk_242e650();
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

// 0x71012ec170
void Unk_242e650::vf6() {
    Unk_12ec1e0(this);
}

// 0x71012ec150
void Unk_242e650::vf9() {}

class Unk_242e6b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012ec1a0
void Unk_242e6b8::vf5() {
    Unk_12ec1e0(this);
}

class Unk_242e6f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012ec1b0
void Unk_242e6f8::vf0() {
    Unk_12ec1e0(this);
}
