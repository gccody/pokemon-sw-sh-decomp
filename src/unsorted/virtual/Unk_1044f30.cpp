// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240aa50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void* vf9();
    virtual void* vf10();
    virtual u32 vf11();
    virtual void vf12();
};

// 0x7101044f30
u32 Unk_240aa50::vf8() {
    return 0;
}

// 0x7101044f40
void* Unk_240aa50::vf9() {
    return nullptr;
}

// 0x7101044f50
void* Unk_240aa50::vf10() {
    return nullptr;
}

class Unk_240ab30 {
public:
    virtual ~Unk_240ab30();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual u32 vf11();
    virtual void vf12();
};

// 0x7101044f60
u32 Unk_240ab30::vf11() {
    return 0;
}
