// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2416538 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010e7980
void Unk_2416538::vf0() {}

// 0x71010e7990
void Unk_2416538::vf1() {}

// 0x71010e79a0
void Unk_2416538::vf2() {}

class Unk_24167c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010e90e0
void Unk_24167c0::vf0() {}

// 0x71010e90f0
void Unk_24167c0::vf1() {}

// 0x71010e9100
void Unk_24167c0::vf2() {}
