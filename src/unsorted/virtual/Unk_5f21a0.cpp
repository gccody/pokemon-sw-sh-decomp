// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_239aed8 {
public:
    virtual ~Unk_239aed8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual u32 vf9();
};

// 0x71005f21a0
u32 Unk_239aed8::vf8() {
    return 1;
}

// 0x71005f21b0
u32 Unk_239aed8::vf9() {
    return 1;
}
