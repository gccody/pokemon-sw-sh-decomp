// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240bfb8 {
public:
    virtual ~Unk_240bfb8();
    virtual void vf2();
    virtual void vf3();
};

// 0x710105c3e0
void Unk_240bfb8::vf2() {}

class Unk_240bfe8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710105c460
void Unk_240bfe8::vf0() {}

class Unk_240c5a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x710105e1b0
void Unk_240c5a8::vf0() {}

// 0x710105e1d0
void Unk_240c5a8::vf2() {}

// 0x710105e220
void Unk_240c5a8::vf4() {}

class Unk_240c5e0 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710105e230
u32 Unk_240c5e0::vf0() {
    return 1;
}

class Unk_240c610 {
public:
    virtual ~Unk_240c610();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710105e280, 0x710105e290
Unk_240c610::~Unk_240c610() {}

// 0x710105e310
u32 Unk_240c610::vf4() {
    return 0xffff;
}

class Unk_240c658 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710105e430
void Unk_240c658::vf1() {}

// 0x710105e440
void Unk_240c658::vf2() {}

class Unk_240c688 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710105e4c0
void Unk_240c688::vf0() {}
