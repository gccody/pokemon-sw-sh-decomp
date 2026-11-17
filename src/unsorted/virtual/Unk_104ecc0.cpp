// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240b368 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x710104ecc0
void Unk_240b368::vf4() {}

class Unk_240b3a0 {
public:
    virtual void vf0();
};

// 0x710104ecd0
void Unk_240b3a0::vf0() {}
