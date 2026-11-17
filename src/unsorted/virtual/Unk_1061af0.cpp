// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240c9d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101061af0
void Unk_240c9d8::vf2() {}

class Unk_240ca08 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7101061b70
void Unk_240ca08::vf0() {}
