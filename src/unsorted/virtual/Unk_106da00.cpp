// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240cad8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710106da50
void Unk_240cad8::vf0() {}

// 0x710106da00
void Unk_240cad8::vf1() {}

class Unk_240cb20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710106da10
void Unk_240cb20::vf0() {}

// 0x710106da20
void Unk_240cb20::vf1() {}

class Unk_240cb50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710106da30
void Unk_240cb50::vf1() {}

// 0x710106da40
void Unk_240cb50::vf2() {}
