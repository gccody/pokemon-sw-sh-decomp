// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240a570 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x710103f700
void Unk_240a570::vf1() {}

// 0x710103f710
void Unk_240a570::vf2() {}

// 0x710103f720
void Unk_240a570::vf3() {}

// 0x710103f730
void Unk_240a570::vf5() {}

// 0x710103f740
void Unk_240a570::vf6() {}

// 0x710103f750
void Unk_240a570::vf7() {}
