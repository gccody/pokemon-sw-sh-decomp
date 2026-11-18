// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2416dc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010ed540
void Unk_2416dc8::vf0() {}

// 0x71010ed550
void Unk_2416dc8::vf1() {}

// 0x71010ed560
void Unk_2416dc8::vf2() {}

class Unk_24171c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010ef7c0
void Unk_24171c8::vf0() {}

// 0x71010ef7d0
void Unk_24171c8::vf1() {}

// 0x71010ef7e0
void Unk_24171c8::vf2() {}
