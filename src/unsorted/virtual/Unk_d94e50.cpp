// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ee328 {
public:
    virtual ~Unk_23ee328();
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

// 0x7100d94e50
u32 Unk_23ee328::vf7() {
    return 1;
}

// 0x7100d94e60
void Unk_23ee328::vf8() {}

// 0x7100d95100
void Unk_23ee328::vf10() {}

class Unk_23ee3f8 {
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

// 0x7100d95470
u32 Unk_23ee3f8::vf7() {
    return 1;
}

// 0x7100d95480
void Unk_23ee3f8::vf8() {}

// 0x7100d96140
void Unk_23ee3f8::vf10() {}
