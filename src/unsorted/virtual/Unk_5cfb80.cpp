// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2399470 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71005cfe80
void Unk_2399470::vf1() {}

// 0x71005cfb80
void Unk_2399470::vf2() {}

class Unk_23994a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005cfee0
void Unk_23994a8::vf0() {}

// 0x71005cfef0
void Unk_23994a8::vf1() {}
