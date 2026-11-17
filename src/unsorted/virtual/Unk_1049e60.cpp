// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240b028 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101049e60
void Unk_240b028::vf2() {}

class Unk_240b058 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7101049ee0
void Unk_240b058::vf0() {}
