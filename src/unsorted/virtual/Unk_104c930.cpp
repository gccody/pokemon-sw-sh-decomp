// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240b1d8 {
public:
    virtual ~Unk_240b1d8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
};

// 0x710104c930
u32 Unk_240b1d8::vf7() {
    return 1;
}

// 0x710104c9d0
u32 Unk_240b1d8::vf9() {
    return 0;
}

// 0x710104c9e0
void Unk_240b1d8::vf10() {}

class Unk_240b2e8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710104d330
u32 Unk_240b2e8::vf0() {
    return 1;
}
