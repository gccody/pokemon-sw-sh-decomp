// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23f7578 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ed0890
void* Unk_23f7578::vf3() {
    return nullptr;
}

class Unk_23f75a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ed08d0
void* Unk_23f75a8::vf3() {
    return nullptr;
}

class Unk_23f75d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ed0910
void* Unk_23f75d8::vf3() {
    return nullptr;
}

class Unk_23f7608 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ed0950
void* Unk_23f7608::vf3() {
    return nullptr;
}
