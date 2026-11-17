// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a25e0 {
public:
    virtual ~Unk_23a25e0();
    virtual void vf2();
    virtual void vf3();
};

// 0x71006a50e0
void Unk_23a25e0::vf2() {}

class Unk_23a2610 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71006a5160
void Unk_23a2610::vf0() {}

class Unk_23a2650 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71006a5650
u32 Unk_23a2650::vf0() {
    return 1;
}
