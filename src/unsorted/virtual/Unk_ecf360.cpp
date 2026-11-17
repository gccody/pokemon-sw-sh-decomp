// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23f7268 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ecf360
void* Unk_23f7268::vf3() {
    return nullptr;
}

class Unk_23f7388 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ecfe50
void* Unk_23f7388::vf3() {
    return nullptr;
}

class Unk_23f73b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ecfe90
void* Unk_23f73b8::vf3() {
    return nullptr;
}
