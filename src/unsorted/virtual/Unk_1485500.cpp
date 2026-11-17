// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_243fd20 {
public:
    virtual ~Unk_243fd20();
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

// 0x7101485500
void Unk_243fd20::vf9() {}

class Unk_243fdf0 {
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

// 0x7101485a90
u32 Unk_243fdf0::vf7() {
    return 1;
}

// 0x7101485aa0
void Unk_243fdf0::vf8() {}

// 0x7101485c40
void Unk_243fdf0::vf10() {}

class Unk_243ff00 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014866e0
u32 Unk_243ff00::vf0() {
    return 1;
}
