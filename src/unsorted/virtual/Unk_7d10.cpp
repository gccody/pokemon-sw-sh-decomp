// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_236d378 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710000a8d0
void Unk_236d378::vf0() {}

// 0x7100007d10
void Unk_236d378::vf1() {}

class Unk_2399470 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x710000d500
void Unk_2399470::vf0() {}
