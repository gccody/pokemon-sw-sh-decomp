// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23b9ab8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71008abf40
void Unk_23b9ab8::vf0() {}

// 0x71008abf60
void Unk_23b9ab8::vf1() {}

class Unk_23b9af0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71008abf50
void Unk_23b9af0::vf0() {}

// 0x71008abf70
void Unk_23b9af0::vf1() {}

class Unk_23b9b20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71008ac690
void Unk_23b9b20::vf0() {}

// 0x71008ac6b0
void Unk_23b9b20::vf1() {}

class Unk_23b9b58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71008ac6a0
void Unk_23b9b58::vf0() {}

// 0x71008ac6c0
void Unk_23b9b58::vf1() {}
