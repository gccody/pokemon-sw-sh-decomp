// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2446e08 {
public:
    virtual ~Unk_2446e08();
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

// 0x710150d900
void Unk_2446e08::vf9() {}

class Unk_2446ed8 {
public:
    virtual ~Unk_2446ed8();
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

// 0x710150e600
void Unk_2446ed8::vf9() {}

class Unk_2446fa8 {
public:
    virtual ~Unk_2446fa8();
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

// 0x710150f2a0
void Unk_2446fa8::vf9() {}

class Unk_2447078 {
public:
    virtual void vf0();
    virtual void vf1();
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

// 0x710150f8f0
u32 Unk_2447078::vf7() {
    return 1;
}

// 0x710150f910
void Unk_2447078::vf10() {}

class Unk_2447188 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101510520
u32 Unk_2447188::vf0() {
    return 1;
}
