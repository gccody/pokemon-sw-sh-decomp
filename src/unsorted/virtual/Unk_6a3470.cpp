// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a2590 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71006a3470
void Unk_23a2590::vf2() {}

class Unk_23a25c0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71006a34f0
void Unk_23a25c0::vf0() {}
