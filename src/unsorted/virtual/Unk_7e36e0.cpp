// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ac1a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71007e36e0
void Unk_23ac1a8::vf1() {}

class Unk_23ac1e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71007e36f0
void Unk_23ac1e0::vf0() {}

// 0x71007e3700
void Unk_23ac1e0::vf1() {}

class Unk_23ac210 {
public:
    virtual ~Unk_23ac210();
};

// 0x71007e3710, 0x71007e3720
Unk_23ac210::~Unk_23ac210() {}
