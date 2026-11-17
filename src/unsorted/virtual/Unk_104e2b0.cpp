// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240b318 {
public:
    virtual ~Unk_240b318();
    virtual void vf2();
    virtual void vf3();
};

// 0x710104e2b0
void Unk_240b318::vf2() {}

class Unk_240b348 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710104e330
void Unk_240b348::vf0() {}
