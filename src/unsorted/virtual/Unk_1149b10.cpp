// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_241a360 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7101149b10
void Unk_241a360::vf0() {}

// 0x7101149b20
void Unk_241a360::vf1() {}

// 0x7101149b30
void Unk_241a360::vf2() {}

// 0x7101149b40
void Unk_241a360::vf3() {}
