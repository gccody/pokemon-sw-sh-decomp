// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23edc60 {
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

// 0x7100d7f810
u32 Unk_23edc60::vf7() {
    return 1;
}

// 0x7100d81c20
void Unk_23edc60::vf10() {}

class Unk_23ede30 {
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

// 0x7100d83f40
u32 Unk_23ede30::vf7() {
    return 1;
}

class Unk_23edf00 {
public:
    virtual ~Unk_23edf00();
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

// 0x7100d84440
u32 Unk_23edf00::vf7() {
    return 1;
}

// 0x7100d84450
void Unk_23edf00::vf8() {}

// 0x7100d848e0
void Unk_23edf00::vf10() {}
