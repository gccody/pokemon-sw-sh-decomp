// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1295840(void* self);

class Unk_242b360 {
public:
    virtual ~Unk_242b360();
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

// 0x71012957d0
void Unk_242b360::vf6() {
    Unk_1295840(this);
}

class Unk_242b3c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101295800
void Unk_242b3c8::vf5() {
    Unk_1295840(this);
}

class Unk_242b408 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101295810
void Unk_242b408::vf0() {
    Unk_1295840(this);
}
