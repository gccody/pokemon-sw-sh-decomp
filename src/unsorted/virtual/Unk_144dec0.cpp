// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_243c740 {
public:
    virtual ~Unk_243c740();
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

// 0x710144dec0
void Unk_243c740::vf9() {}

class Unk_243c828 {
public:
    virtual ~Unk_243c828();
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

// 0x710144efb0
void Unk_243c828::vf9() {}

class Unk_243c8f8 {
public:
    virtual ~Unk_243c8f8();
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

// 0x710144f650
u32 Unk_243c8f8::vf7() {
    return 1;
}

// 0x7101451c30
void Unk_243c8f8::vf10() {}
