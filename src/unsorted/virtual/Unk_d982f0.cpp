// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ee5c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7100d982f0
void Unk_23ee5c8::vf0() {}

// 0x7100d98310
void Unk_23ee5c8::vf1() {}

class Unk_23ee600 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100d98300
void Unk_23ee600::vf0() {}

// 0x7100d98320
void Unk_23ee600::vf1() {}
