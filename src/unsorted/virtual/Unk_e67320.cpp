// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23f2df0 {
public:
    virtual ~Unk_23f2df0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13() = 0;
    virtual void vf14();
    virtual void vf15();
    virtual void vf16() = 0;
};

// 0x7100e67320
u32 Unk_23f2df0::vf9() {
    return 1;
}

// 0x7100e674a0
void Unk_23f2df0::vf10() {}

// 0x7100e674b0
void Unk_23f2df0::vf11() {}

// 0x7100e674c0
void Unk_23f2df0::vf14() {}

// 0x7100e674d0
void Unk_23f2df0::vf15() {}
