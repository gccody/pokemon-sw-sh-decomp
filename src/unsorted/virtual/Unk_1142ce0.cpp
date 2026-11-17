// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_241a068 {
public:
    virtual ~Unk_241a068();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x7101142ce0
void Unk_241a068::vf7() {}

class Unk_241a128 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7101142cf0
void Unk_241a128::vf0() {}
