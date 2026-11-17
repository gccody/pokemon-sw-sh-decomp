// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24087b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7101021950
void Unk_24087b8::vf0() {}

// 0x7101021960
void Unk_24087b8::vf4() {}

class Unk_24087f0 {
public:
    virtual void vf0();
};

// 0x7101021970
void Unk_24087f0::vf0() {}
