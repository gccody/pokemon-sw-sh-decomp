// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23f5d70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100eadd00
void Unk_23f5d70::vf1() {}

// 0x7100eadd10
void Unk_23f5d70::vf2() {}

class Unk_23f5da0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100eadd90
void Unk_23f5da0::vf0() {}

class Unk_23f5dc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100eaf260
void Unk_23f5dc0::vf2() {}

class Unk_23f5df0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100eaf2e0
void Unk_23f5df0::vf0() {}
