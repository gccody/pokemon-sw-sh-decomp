// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a1f18 {
public:
    virtual ~Unk_23a1f18();
};

// 0x7100694160, 0x7100696610
Unk_23a1f18::~Unk_23a1f18() {}

class Unk_23a1ee8 {
public:
    virtual ~Unk_23a1ee8();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100696600, 0x71006965c0
Unk_23a1ee8::~Unk_23a1ee8() {}

class Unk_23a20c8 {
public:
    virtual ~Unk_23a20c8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x710069a2a0
void Unk_23a20c8::vf15() {}
