// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a2c48 {
public:
    virtual ~Unk_23a2c48();
    virtual void vf2();
    virtual void vf3();
};

// 0x71006af550
void Unk_23a2c48::vf2() {}

class Unk_23a2c78 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71006af5d0
void Unk_23a2c78::vf0() {}

class Unk_23a2c98 {
public:
    virtual ~Unk_23a2c98();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71006af690, 0x71006af6a0
Unk_23a2c98::~Unk_23a2c98() {}
