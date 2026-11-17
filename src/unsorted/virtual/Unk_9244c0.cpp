// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bec40 {
public:
    virtual ~Unk_23bec40();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x71009244c0
u32 Unk_23bec40::vf8() {
    return 0;
}

// 0x71009244d0
void Unk_23bec40::vf9() {}
