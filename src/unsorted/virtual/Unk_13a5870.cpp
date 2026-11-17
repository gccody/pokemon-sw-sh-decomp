// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2433de0 {
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

// 0x71013a5870
u32 Unk_2433de0::vf7() {
    return 1;
}

// 0x71013a5940
void Unk_2433de0::vf10() {}

class Unk_2433eb0 {
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

// 0x71013a60c0
u32 Unk_2433eb0::vf7() {
    return 1;
}

// 0x71013a60d0
void Unk_2433eb0::vf8() {}

// 0x71013a6210
void Unk_2433eb0::vf10() {}

class Unk_2433f80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71013a6b20
void Unk_2433f80::vf1() {}

class Unk_2433fb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71013a6b30
void Unk_2433fb8::vf0() {}

// 0x71013a6b40
void Unk_2433fb8::vf1() {}
