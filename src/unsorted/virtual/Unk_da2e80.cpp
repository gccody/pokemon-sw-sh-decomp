// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23eeaf0 {
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

// 0x7100da2e80
u32 Unk_23eeaf0::vf7() {
    return 1;
}

// 0x7100da2e90
void Unk_23eeaf0::vf8() {}

// 0x7100da30d0
void Unk_23eeaf0::vf10() {}

class Unk_23eebc0 {
public:
    virtual ~Unk_23eebc0();
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

// 0x7100da3240
u32 Unk_23eebc0::vf7() {
    return 1;
}

// 0x7100da34a0
void Unk_23eebc0::vf10() {}
