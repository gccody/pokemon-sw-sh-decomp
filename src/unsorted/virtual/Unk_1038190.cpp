// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2409f30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7101038190
void Unk_2409f30::vf0() {}

// 0x71010381a0
void Unk_2409f30::vf4() {}

class Unk_2409f68 {
public:
    virtual void vf0();
};

// 0x71010381b0
void Unk_2409f68::vf0() {}
