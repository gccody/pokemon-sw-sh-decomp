// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_239a840 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005eb520
u32 Unk_239a840::vf0() {
    return 2;
}

class Unk_239a870 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005eb690
u32 Unk_239a870::vf0() {
    return 2;
}

class Unk_239a8c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005ec250
void Unk_239a8c0::vf2() {}

class Unk_239a8f0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005ec2d0
void Unk_239a8f0::vf0() {}

class Unk_239a2f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71005ece00
void Unk_239a2f0::vf5() {}
