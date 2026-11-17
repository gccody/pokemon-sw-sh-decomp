// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24311b8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710133e710
u32 Unk_24311b8::vf0() {
    return 1;
}

class Unk_2431298 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x710133fc10
void Unk_2431298::vf9() {}

class Unk_2431368 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7101340690
void Unk_2431368::vf9() {}

class Unk_2431778 {
public:
    virtual ~Unk_2431778();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7101344540
u32 Unk_2431778::vf7() {
    return 1;
}

// 0x71013445d0
void Unk_2431778::vf10() {}

class Unk_2431910 {
public:
    virtual ~Unk_2431910();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101346250, 0x7101346260
Unk_2431910::~Unk_2431910() {}

class Unk_2431940 {
public:
    virtual ~Unk_2431940();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101346290, 0x71013462a0
Unk_2431940::~Unk_2431940() {}

class Unk_24319a8 {
public:
    virtual ~Unk_24319a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101346750, 0x7101346760
Unk_24319a8::~Unk_24319a8() {}

class Unk_24319f0 {
public:
    virtual ~Unk_24319f0();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101347ab0, 0x7101347ac0
Unk_24319f0::~Unk_24319f0() {}
