// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2414e00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010d6890
void Unk_2414e00::vf0() {}

// 0x71010d68a0
void Unk_2414e00::vf1() {}

// 0x71010d68b0
void Unk_2414e00::vf2() {}

class Unk_2415200 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010d8b80
void Unk_2415200::vf0() {}

// 0x71010d8b90
void Unk_2415200::vf1() {}

// 0x71010d8ba0
void Unk_2415200::vf2() {}
