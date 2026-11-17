// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_239b130 {
public:
    virtual ~Unk_239b130();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
};

// 0x71005f71b0, 0x71005f8cf0
Unk_239b130::~Unk_239b130() {}

class Unk_239b0e0 {
public:
    virtual ~Unk_239b0e0();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005f8310
void Unk_239b0e0::vf2() {}

class Unk_239b110 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005f8320
void Unk_239b110::vf0() {}
