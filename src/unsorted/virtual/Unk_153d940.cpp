// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_153dd60(void* self);

class Unk_2449478 {
public:
    virtual ~Unk_2449478();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710153d940
void Unk_2449478::vf6() {
    Unk_153dd60(this);
}

class Unk_24494c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710153d950
void Unk_24494c0::vf5() {
    Unk_153dd60(this);
}

class Unk_2449500 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710153d960
void Unk_2449500::vf0() {
    Unk_153dd60(this);
}
