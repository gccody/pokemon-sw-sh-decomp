// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240ca28 {
public:
    virtual ~Unk_240ca28();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101062330
void Unk_240ca28::vf2() {}

class Unk_240ca58 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7101062340
void Unk_240ca58::vf0() {}
