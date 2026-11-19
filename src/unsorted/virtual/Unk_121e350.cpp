// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24240b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710121e350
void Unk_24240b8::vf1() {}

// 0x710121e360
void Unk_24240b8::vf2() {}

// 0x710121e370
void Unk_24240b8::vf3() {}

// 0x710121e380
void Unk_24240b8::vf5() {}
