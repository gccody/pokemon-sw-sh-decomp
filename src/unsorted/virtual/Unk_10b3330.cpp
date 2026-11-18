// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2411eb0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010b3330
void Unk_2411eb0::vf0() {}

// 0x71010b3340
void Unk_2411eb0::vf1() {}

// 0x71010b3350
void Unk_2411eb0::vf2() {}

class Unk_24120d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010b4960
void Unk_24120d8::vf0() {}

// 0x71010b4970
void Unk_24120d8::vf1() {}

// 0x71010b4980
void Unk_24120d8::vf2() {}

class Unk_2412200 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010b5690
void Unk_2412200::vf0() {}

// 0x71010b56a0
void Unk_2412200::vf1() {}

// 0x71010b56b0
void Unk_2412200::vf2() {}
