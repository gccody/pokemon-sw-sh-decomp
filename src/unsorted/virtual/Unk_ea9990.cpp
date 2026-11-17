// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23f5b58 {
public:
    virtual ~Unk_23f5b58();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7100ea9990, 0x7100ea99a0
Unk_23f5b58::~Unk_23f5b58() {}

class Unk_23f5bf8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100eaa6e0
void Unk_23f5bf8::vf2() {}

class Unk_23f5c28 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100eaa760
void Unk_23f5c28::vf0() {}

class Unk_23f5cb0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100eacd80
void Unk_23f5cb0::vf2() {}

class Unk_23f5ce0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100eace00
void Unk_23f5ce0::vf0() {}
