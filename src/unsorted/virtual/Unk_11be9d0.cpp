// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_241fc68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71011be9d0
void Unk_241fc68::vf0() {}

// 0x71011be9e0
void Unk_241fc68::vf4() {}

class Unk_241fca0 {
public:
    virtual void vf0();
};

// 0x71011be9f0
void Unk_241fca0::vf0() {}
