// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23e0e60 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ca95e0
void Unk_23e0e60::vf1() {}

// 0x7100cac9e0
void Unk_23e0e60::vf2() {
    ::operator delete(this);
}

class Unk_23e0e88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100cacae0
void Unk_23e0e88::vf2() {
    ::operator delete(this);
}

class Unk_23e0eb0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100cacbe0
void Unk_23e0eb0::vf2() {
    ::operator delete(this);
}
