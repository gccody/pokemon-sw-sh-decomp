// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_da57d0(void* self);

class Unk_23eed68 {
public:
    virtual ~Unk_23eed68();
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

// 0x7100da57a0
void Unk_23eed68::vf6() {
    Unk_da57d0(this);
}

// 0x7100da5000
u32 Unk_23eed68::vf7() {
    return 1;
}

class Unk_23eedd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100da57b0
void Unk_23eedd0::vf5() {
    Unk_da57d0(this);
}

class Unk_23eee10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100da57c0
void Unk_23eee10::vf0() {
    Unk_da57d0(this);
}
