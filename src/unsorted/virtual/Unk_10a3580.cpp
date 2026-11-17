// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24108f0 {
public:
    virtual ~Unk_24108f0();
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

// 0x71010a3580
u32 Unk_24108f0::vf3() {
    return 1;
}

class Unk_24108a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71010a3a00
void Unk_24108a8::vf0() {}

// 0x71010a3a10
void Unk_24108a8::vf2() {}

// 0x71010a3a20
void Unk_24108a8::vf3() {}

// 0x71010a3a30
void Unk_24108a8::vf4() {}

// 0x71010a3a40
void Unk_24108a8::vf6() {}
