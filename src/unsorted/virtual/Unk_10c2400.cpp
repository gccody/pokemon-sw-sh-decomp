// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2413590 {
public:
    virtual ~Unk_2413590();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x71010c2400
u32 Unk_2413590::vf3() {
    return 1;
}

class Unk_2413558 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71010c2880
void Unk_2413558::vf0() {}

// 0x71010c2890
void Unk_2413558::vf2() {}

// 0x71010c28a0
void Unk_2413558::vf4() {}

class Unk_2413600 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71010c2a50
void Unk_2413600::vf1() {}

// 0x71010c2a60
void Unk_2413600::vf3() {}
