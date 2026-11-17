// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bac00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71008c1e70
void Unk_23bac00::vf0() {}

// 0x71008c1e90
void Unk_23bac00::vf1() {}

class Unk_23bac38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71008c1e80
void Unk_23bac38::vf0() {}

// 0x71008c1ea0
void Unk_23bac38::vf1() {}
