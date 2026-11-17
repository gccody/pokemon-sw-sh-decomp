// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24149b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010d2b00
void Unk_24149b8::vf0() {}

// 0x71010d2b10
void Unk_24149b8::vf1() {}

// 0x71010d2b20
void Unk_24149b8::vf2() {}
