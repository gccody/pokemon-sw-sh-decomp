// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2413e48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010c84a0
void Unk_2413e48::vf0() {}

// 0x71010c84b0
void Unk_2413e48::vf1() {}

// 0x71010c84c0
void Unk_2413e48::vf2() {}

class Unk_24140d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010c9f80
void Unk_24140d0::vf0() {}

// 0x71010c9f90
void Unk_24140d0::vf1() {}

// 0x71010c9fa0
void Unk_24140d0::vf2() {}
