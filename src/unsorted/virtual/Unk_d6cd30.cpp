// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ed2a0 {
public:
    virtual ~Unk_23ed2a0();
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

// 0x7100d6cd30
u32 Unk_23ed2a0::vf7() {
    return 1;
}

// 0x7100d6cd40
void Unk_23ed2a0::vf8() {}

// 0x7100d6d0d0
void Unk_23ed2a0::vf10() {}
