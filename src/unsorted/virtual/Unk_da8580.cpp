// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ef248 {
public:
    virtual ~Unk_23ef248();
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

// 0x7100da8580
u32 Unk_23ef248::vf7() {
    return 1;
}

// 0x7100da8590
void Unk_23ef248::vf8() {}

// 0x7100da8720
void Unk_23ef248::vf10() {}

class Unk_23ef318 {
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

// 0x7100da8b40
u32 Unk_23ef318::vf7() {
    return 1;
}

// 0x7100da8b50
void Unk_23ef318::vf8() {}

// 0x7100da8df0
void Unk_23ef318::vf10() {}
