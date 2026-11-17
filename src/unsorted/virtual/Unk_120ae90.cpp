// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2423168 {
public:
    virtual ~Unk_2423168();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual u32 vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
};

// 0x710120b0f0
u32 Unk_2423168::vf13() {
    return 0x46;
}

// 0x710120ae90
void Unk_2423168::vf17() {}

class Unk_2423348 {
public:
    virtual void vf0();
};

// 0x710120aea0
void Unk_2423348::vf0() {}

class Unk_2423270 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual u32 vf14();
};

// 0x710120b160
void Unk_2423270::vf1() {}

// 0x710120b170
void Unk_2423270::vf3() {}

// 0x710120b180
void Unk_2423270::vf4() {}

// 0x710120b190
void Unk_2423270::vf5() {}

// 0x710120b1a0
void Unk_2423270::vf6() {}

// 0x710120b1b0
void Unk_2423270::vf7() {}

// 0x710120b540
u32 Unk_2423270::vf14() {
    return 0x46;
}

class Unk_2423360 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13() = 0;
    virtual void vf14() = 0;
};

// 0x710120b550
void Unk_2423360::vf0() {}

// 0x710120b560
void Unk_2423360::vf2() {}
